#include<stdio.h>
#include<stdlib.h>

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
 * @brief Вычисляет сумму элементов массива
 * @param arr массив
 * @param size размер массива
 */
int sumArray(int* arr, const size_t size);

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
 * @brief Заменяет минимальный элемент массива на среднее
 * @param arr массив
 * @param Copyarr копия массива
 * @param size размер массива
 */
void replaceMinElement(int* copyArr, int* arr, const size_t size);

/**
 * @brief Возвращается индекс элементов, которые больше предыдущих
 * @param Copyarr копия массива
 * @param size размер массива
 */
int OutputIndex(int* copyArr, const size_t size);

/**
 * @brief Находит одинаковые по знаку пары элементов
 * @param Copyarr копия массива
 * @param size размер массива
 */
int FindPair(int* copyArr, const size_t size);

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
        break;

    }


    printArray(arr, size);
    int* copyArr = copyArray(arr, size);

    replaceMinElement(copyArr, arr, size);
    printArray(copyArr, size);

    OutputIndex(copyArr, size);
    FindPair(copyArr, size);

    free(copyArr);
    free(arr);

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
        printf("ERROR");
        abort();
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

int sumArray(int* arr, const size_t size)
{
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        result += arr[i];
    }
    return result;
}


void fillRandom(int* arr, const size_t size)
{
    printf("начальное значение диапазона: ");
    int start = Value();
    printf("конечноее значение диапазона: ");
    int end = Value();
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}


int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int) * size);
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}


void replaceMinElement(int* copyArr, int* arr, const size_t size)
{
    int minElement = copyArr[0];
    size_t minIndex = 0;
    int mid = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (copyArr[i] < minElement) {
            minElement = copyArr[i];
            minIndex = i;
        }
    }

    if (size % 2 != 0 && size >= 3) {
        printf("Замена произведена: ");
        mid = sumArray(arr, size) / size;
        copyArr[minIndex] = mid;
    }

    else {
        printf("Замена на медианное невозможно, так как размер массива должен быть нечетным и больше 3: ");
    }
}

int OutputIndex(int* copyArr, const size_t size) {
    int saveIndex = 0;
    for (size_t i = 1; i < size; i++) {
        if (copyArr[i] > copyArr[i - 1]) {
            saveIndex = i;
            printf("Индекс элемента, значения которого больше значения предыдущего элемента: %d \n", saveIndex);
        }
    }
    printf("\n");
}

int FindPair(int* copyArr, const size_t size) {
    int PairFound = 0;

    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (copyArr[i] == copyArr[j]) {
                printf("Пара найдена: %d и %d (индексы %d и %d)\n",
                    copyArr[i], copyArr[j], i, j);
                PairFound = 1;
            }
        }
    }

    if (!PairFound) {
        printf("Пары одинаковых чисел не найдены\n");
    }

    return PairFound;
}