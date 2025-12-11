#include <stdio.h>
#include <stdlib.h>

/**
 * @return Ввод данных типа int
 * @return Введенное значение
 */
int Value();

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество его элементов)
 */
size_t getSize(char* message);

/**
 * @brief Считывает значения элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Выводит массив (его элементы)
 * @param arr массив
 * @param size размер массива
 */
void printArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Создание двумерного массива
 * @param rows строки
 * @param columns столбцы
 */
int** getArray(const size_t rows, const size_t columns);

/**
 * @brief Освобождение памяти
 * @param arr массив
 * @param rows строки
 */
int** freeArray(int** arr, const size_t rows);

/**
 * @brief Проверка, что начальное значение меньше конечного
 * @param start начальное значение
 * @param end конечное значение
 */
void checkRange(const int start, const int end);

/**
 * @brief Замена максимального элемента в каждом столбце на 0
 * @param rows строки
 * @param columns столбцы
 * @param arr массив
 * @param NewArray новый массив
 */
void ReplaceMax(const size_t rows, const size_t columns, int** arr, int** NewArray);

/**
 * @brief Подсчет количества строк с максимальным значением элемента по модулю
 * @param arr массив
 * @param rows строки
 * @param columns столбцы
 */
size_t getCountRowsWithMax(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Добавление первой строки после каждой строки с максимальным элементом
 * @param rows строки
 * @param columns столбцы
 * @param arr массив
 * @param NewArray новый второй массив
 */
void AddFirstRow(const size_t rows, const size_t columns, int** arr, int** NewArray2);

/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum { RANDOM = 1, MANUAL };

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int main(void)
{

    size_t rows = getSize("Введите количество строк массива:  ");
    size_t columns = getSize("Введите количество стобцов массива:  ");
    int** arr = getArray(rows, columns);
    printf("Выберите способ заполнения массива:\n"
        "%d - случайными числами или %d - вручную ", RANDOM, MANUAL);

    int choice = Value();
    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, rows, columns);
        break;
    case MANUAL:
        fillArray(arr, rows, columns);
        break;
    default:
        printf("error");
        free(arr);
        break;
    }


    printArray(arr, rows, columns);
    int** NewArray = getArray(rows, columns);

    ReplaceMax(rows, columns, arr, NewArray);
    printArray(NewArray, rows, columns);


    size_t addRows = getCountRowsWithMax(arr, rows, columns);
    size_t newRows = rows + addRows;
    int** NewArray2 = getArray(newRows, columns);

    AddFirstRow(rows, columns, arr, NewArray2);
    printArray(NewArray2, newRows, columns);


    freeArray(arr, rows);
    freeArray(NewArray, rows);
    freeArray(NewArray2, newRows);
    return 0;
}




int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("ERROR\n");
        abort();
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        fprintf(stderr, "Error");
        abort();
    }
    return (size_t)value;
}

void fillArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Введите число[%d,%d] = ", i, j);
            arr[i][j] = Value();
        }
    }
}

void printArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fillRandom(int** arr, const size_t rows, const size_t columns)
{
    printf("Введите начало диапазона случайных чисел: ");
    const int start = Value();
    printf("Введите конец диапазона случайных чисел: ");
    const int end = Value();
    checkRange(start, end);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = (rand() % (end - start + 1)) + start;
        }
    }
}

int** getArray(const size_t rows, const size_t columns)
{
    int** arr = malloc(rows * sizeof(int*));
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = malloc(columns * sizeof(int));
    }
    if (arr == NULL)
    {
        fprintf(stderr, "Error");
        exit(1);
    }
    return arr;
}

int** freeArray(int** arr, const size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
}


void checkRange(const int start, const int end)
{
    if (start > end)
    {
        fprintf(stderr, "Error\n");
        exit(1);
    }
}



void ReplaceMax(const size_t rows, const size_t columns, int** arr, int** NewArray)
{
    for (size_t j = 0; j < columns; ++j) {
        int max = arr[0][j];         

        for (size_t i = 1; i < rows; ++i) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }

        for (size_t i = 0; i < rows; ++i) {
            if (arr[i][j] == max) {
                NewArray[i][j] = 0;
            }
            else {
                NewArray[i][j] = arr[i][j];
            }
        }
    }
    printf("Замена выполнена: \n");
}


void AddFirstRow(const size_t rows, const size_t columns, int** arr, int** NewArray2) { 
    int maxAbs = abs(arr[0][0]);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            int Max = abs(arr[i][j]);
            if (Max > maxAbs) {
                maxAbs = Max;
            }
        }
    }

    size_t k = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            NewArray2[k][j] = arr[i][j];
        }
        k++;

        int MaxFound = 0;
        for (size_t j = 0; j < columns; ++j) {
            if (abs(arr[i][j]) == maxAbs) {
                MaxFound = 1;
                break;
            }
        }

        if (MaxFound) {
            for (size_t j = 0; j < columns; ++j) {
                NewArray2[k][j] = arr[0][j];
            }
            k++;
        }
    }
    printf("Массив с добавленными строками: \n");
}


size_t getCountRowsWithMax(int** arr, const size_t rows, const size_t columns)
{
    int maxAbs = abs(arr[0][0]);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            int Max = abs(arr[i][j]);
            if (Max > maxAbs) {
                maxAbs = Max;
            }
        }
    }

    size_t counter = 0;
    for (size_t i = 0; i < rows; i++) {
        int RowFound = 0;
        for (size_t j = 0; j < columns; j++) {
            if (abs(arr[i][j]) == maxAbs) {
                RowFound = 1;
                break;
            }
        }
        if (RowFound) {
            counter++;
        }
    }

    return counter;
}
