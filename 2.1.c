#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/**
    @brief считывает значение, введенное с клавиатуры с проверкой кода
    @return считанное значение
**/


double getValue();

/**
    @brief проверяет, что переменная находится в нужном диапазоне
    @param значение проверяемой переменной
**/
void checkValueWeek(const double Value);

/**
    @brief проверяет, что переменная находится в нужном диапазоне
    @param значение проверяемой переменной
**/
void checkValueMonth(const double Value);

enum { week, month };

/**
    @brief точка входа в программу
    @return 0 если программа выполнена успешно
**/
int main(void) {
    setlocale(LC_ALL, "Russian");

    printf("Введите номер дня недели\n");
    double Week = getValue();
    checkValueWeek(Week);

    printf("Введите номер месяца\n");
    double Month = getValue();
    checkValueMonth(Month);

    printf("Выберите нужный расчет: %d-название дня недели, %d-название месяца\n", week, month);
    int choice = (int)getValue();

    char days[7][30] = { "Понедельник", "Вторник", "Среда", "Четверг",
    "Пятница", "Суббота", "Воскресенье" };
    char months[12][30] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь"," Ноябрь", "Декабрь" };

    switch (choice)
    {
    case week:
        printf("День недели: %s ", days[(int)(Week)-1]);
        break;
    case month:
        printf("Название месяца: %s", months[(int)(Month)-1]);
        break;
    default:
        printf("Неправильный выбор");
    }
    return 0;
}

double getValue() {
    double Value = 0;
    if (!scanf_s("%lf", &Value)) {
        printf("Error\n");
        abort();
    }
    return Value;
}

void checkValueWeek(const double Value) {
    if (Value <= 0 || Value >= 8) {
        printf("Значение должно быть равно числу от 1 до 7\n");
        abort();
    }
}
void checkValueMonth(const double Value) {
    if (Value <= 0 || Value >= 13) {
        printf("Значение должно быть равно числу от 1 до 12\n");
        abort();
    }
}