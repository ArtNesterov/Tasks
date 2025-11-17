#include<stdio.h>
#include<math.h>
#include <float.h>
#include <stdbool.h>
#include<stdlib.h>
/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @param x значение параметра x
 * @return рассчитанное значение коэффициента
 */
double getRecurent(const int i, const double x);

/**
 * @brief рассчитывает сумму членов последовательности с точностью e
 * @param e заданная точность
 * @param x значение параметра x
 * @return рассчитанное значение
 */
double getSumE(const double e, const double x);

/**
 * @brief Проверяет, что начальное значение меньше конечного
 * @param start начальное значение промежутка
 * @param end конечное значение промежутка
 */
void checkDiapason(const double start, const double end);

/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Проверяет, что шаг функции больше нуля.
 * @param step значение шага функции
 */
void checkStep(const double step);

/**
 * @brief Вычисление значения функции
 * @param x значение параметра x
 * @return рассчитанное значение
 */
double getFunction(const double x);

/**
 * @brief считывает вещественное значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
double getValue();


int main(void) {
	printf("Введите значение х: ");
	double x = getValue();

	printf("Введите начальное значение диапазона: ");
	double start = getValue();

	printf("Введите конечное значение диапазона: ");
	double end = getValue();

	printf("Введите шаг: ");
	double step = getValue();
	checkStep(step);

	printf("Введите точность: ");
	double e = getValue();
	checkPositive(step);

	printf("Значение функции в точке х равно: %.4lf\n", getFunction(x));

	for (double x = start; x < end + step; x += step) {
		printf("x = %.4lf, значение S = %.4lf\n", x, getSumE(e, x));
	}

	return 0;

}
double getValue() {
	double value = 0;
	if (!scanf_s("%lf", &value)) {
		printf("Error\n");
		abort();
	}
	return value;
}

void checkPositive(const double value)
{
	if (!value > 0)
	{
		printf("Error\n");
		exit(1);
	}
}

double getFunction(const double x) {
	return (exp(x) + exp(-x)) / 2;
}

void checkStep(const double step)
{
	if (step <= DBL_EPSILON)
	{
		printf("Ошибка, шаг должен быть положительным\n");
		abort();
	}
}

void checkDiapason(const double start, const double end) {
	if (start > end || fabs(start - end) <= DBL_EPSILON) {
		printf("Error");
		exit(1);
	}
}

double getRecurent(const int i, const double x)
{
	return (x * x) / ((2.0 * i + 2.0) * (2 * i + 1));
}

double getSumE(const double e, const double x)
{
	double current = 1;
	double result = current;
	for (int i = 1; fabs(current) > e; i++)
	{
		current *= getRecurent(i, x);
		result += current;
	}
	return result;
}