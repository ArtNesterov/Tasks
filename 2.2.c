#include<stdio.h>
#include<math.h>
#include<locale.h>

/**
    @brief считывает значение, введенное с клавиатуры с проверкой кода
    @return считанное значение
**/
double getValue();

/**
    @brief  функция рассчитывающая значение 
    @param  x - переменная вводимая пользователем
    @param  a - константа 
    @return рассчитанное значение
**/
double getFunction(const double x, const double a);

/**
    @brief  точка входа в программу
    @retval 0 если программа выполнена корректно 
**/
int main(void) {
    setlocale(LC_ALL, "Russian");
    printf("Введите значение х: ");
    double x = getValue();
    const double a = 20.3;
    printf("Значение функции равно %.2lf", getFunction(x,a));
    return 0;
}

double getValue()
{
    double value = 0;
    if (!scanf_s("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

double getFunction(const double x, const double a) {
    if (x > 1) return log10(x + 1);
    if (x<= 1) return sin(2) * sqrt(abs(a * x));
}