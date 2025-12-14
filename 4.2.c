#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>
#include<stdbool.h>

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
void fillArray(int* arr, const size_t size);

/**
 * @brief Выводит массив (его элементы)
 * @param arr массив
 * @param size размер массива
 */
void printArray(int* arr, const size_t size);


/**
 * @brief Заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Создаёт копию массива
 * @param arr массив
 * @param size размер массива
 * @return полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Заменяет минимальный положительный элемент массива последним элементом
 * @param arr массив
 * @param Copyarr копия массива
 * @param size размер массива
 */
void replaceMinElement(int* copyArr, const size_t size);


/**
 * @brief Заменяет исходные массив на массив с заменой элементов на 0
 * @param Copyarr копия массива
 * @param size размер массива
 */
int* replaceArray(int* copyArr, const size_t size);



/**
 * @brief Формирует новый массив А на основе элементов старого массива С.
 * @param Copyarr копия массива
 * @param size размер массива
 */
void NewArrayA(int* copyArr, const size_t size);



/**
 * @brief Удаляет элементы, в которых последняя цифра нечетная, а само число кратно 3
 * @param Copyarr копия массива
 * @param size размер массива
 */
void DeleteOdd(int* copyArr, const size_t size);

/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum { RANDOM = 1, MANUAL };


/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int main()
{
    size_t size = getSize("Введите размер массива:  ");
    int* arr = malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("error");
        exit(1);
    }

    printf("Выберите способ заполнения массива:\n""%d-случайными числами %d-вручную ", RANDOM, MANUAL);
    int choice = Value();

    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, size);
        break;
    case MANUAL:
        fillArray(arr, size);
        break;
    default:
        printf("error");
        free(arr);
        exit(1);
    }


    printArray(arr, size);
    int* copyArr = copyArray(arr, size);

    replaceMinElement(copyArr, size);
    printArray(copyArr, size);

    DeleteOdd(copyArr, size);

    NewArrayA(copyArr, size);


    free(copyArr);
    free(arr);

    return 0;
}


int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        fprintf(stderr, "Error\n");
        exit(1);
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
        exit(1);
    }
    return (size_t)value;
}



void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите A = ");
        arr[i] = Value();
    }
}



void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



void fillRandom(int* arr, const size_t size)
{
    printf("начальное значение диапазона: ");
    const int start = Value();
    printf("конечное значение диапазона: ");
    const int end = Value();
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}


int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int) * size);

    if (copyArr == NULL)
    {
        fprintf(stderr, "Error");
        exit(1);
    }

    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}


void replaceMinElement(int* copyArr, const size_t size)
{
    int minElement = INT_MAX;
    size_t minIndex = 0;
    int MinLast = 0;
    bool FindPositive = false;

    for (size_t i = 0; i < size; i++)
    {
        if ((copyArr[i] < minElement) && (copyArr[i] > 0)) {
            minElement = copyArr[i];
            FindPositive = true;
            minIndex = i;
        }
    }
    if (FindPositive != true) {
        printf("Положительных элементов не найдено \n");
    }

    else {
        printf("Замена произведена: ");
        MinLast = copyArr[size - 1];
        copyArr[minIndex] = MinLast;
    }
}

int* replaceArray(int* copyArr, const size_t size) {
    int notZero = 0;
    for (size_t i = 0; i < size; i++) {
        if (copyArr[i] != 0) {
            copyArr[notZero] = copyArr[i];
            notZero++;
        }
    }
    for (size_t j = notZero; j < size; j++) {
        copyArr[j] = 0;
    }
    return copyArr;
}

void DeleteOdd(int* copyArr, const size_t size) {
    int counter = 0;
    for (size_t i = 0; i < size; i++) {
        if ((((copyArr[i] % 10) % 2) != 0) && (copyArr[i] % 3 == 0)) {
            counter++;
            copyArr[i] = 0;
        }
    }
    if (counter == 0) {
        printf("Нужных элементов не обнаружено \n");
    }
    else 
    {
        replaceArray(copyArr, size);
        printf("Массив с удаленными элементами:");
        for (size_t j = 0; j < size; j++) {
            if (copyArr[j] != 0) {
                printf("%d ", copyArr[j]);
            }
        }
        printf("\n");
    }
}

void NewArrayA(int* copyArr, const size_t size) {
    if (size == 0) {
        printf("Массив С пуст, нельзя сформировать новый массив!\n");
        abort();
    }

    int* A = malloc(size * sizeof(int));
    if (A == NULL) {
        fprintf(stderr, "Error");
        exit(1);
    }

    for (size_t i = 0; i < size; i++) {
        if (copyArr[i] % 2 == 0) {
            A[i] = copyArr[i] + (int)i;
        }
        else {
            A[i] = copyArr[i] - (int)i;
        }
    }

    printf("Массив А: ");
    printArray(A, size);
    free(A);
}
