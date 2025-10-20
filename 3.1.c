#include<stdlib.h>
#include<float.h>
#include<math.h>
#include<stdbool.h>
#include<stdio.h>


/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param step значение проверяемой переменной
 */
void checkStep(const double step);

/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение
 * @return
 */
double getY(const double x);

/**
 * @brief проверяет, принадлежит ли значение аргумента функции
 * её области определения
 * @param x - аргумент функции
 * @return true, если аргумент принадлежит ООФ, иначе false
 */
bool defineOOF(const double x);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Введите начальное значение: ");
	double start = getValue();
	printf("Введите конечное значение: ");
	double end = getValue();
	printf("Введите шаг: ");
	double step = getValue();
	checkStep(step);

	for (double x = start; x < end + DBL_EPSILON; x = x + step)
	{
		if (defineOOF(x))
		{
			printf("x = %.2lf, y = %.4lf\n", x, getY(x));
		}
		else
		{
			printf("x = %.2lf, не принадлежит ООФ\n", x);
		}
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

void checkStep(const double step) {
	if (step <= DBL_EPSILON) {
		printf("Шаг должен быть положительным");
		abort();
	}
}

double getY(const double x) {
	return tan(x) - (1 / 3) * (pow(tan(x), 3)) + (1 / 5) * (pow(tan(x), 5)) - 1 / 3;
}

bool defineOOF(const double x)
{
	double rad = x * M_PI/180;
	return rad != M_PI / 2 && rad!= 3 * M_PI / 2;

}
