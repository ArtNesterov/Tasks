#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();


/**
@brief Triangle - формула для треугольника
@brief Square - формула для квадрата
@brief Rhombus - формула для ромба
@brief Rectangle - формула для прямоугольника
*/
enum { Triangle, Square, Rhombus, Rectangle };

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    setlocale(LC_ALL, "Russian");
    printf("Выберите желаемый номер фигуры: %d-треугольник, %d-квадрат, %d-ромб, %d-прямоугольник\n", Triangle, Square, Rhombus, Rectangle);
    int choice = (int)getValue();
    switch (choice)
    {
    case Square:
        printf("Формула площади равна: a*a " );
        break;
    case Triangle:
        printf("Формула площади равна: a*h*0.5, где h - высота треугольника" );
        break;
    case Rhombus:
        printf("Формула площади равна: (d1*d2)*0,5 , где d1 и d2 - диагонали ромба" );
        break;
    case Rectangle:
        printf("Формула площади равна: a*b" );
        break;
    default:
        printf("Неправильный выбор");
        abort();
    }

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
