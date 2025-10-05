#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>
#include<locale.h>

/**
 * @brief - рассчитывает объем по заданной формуле
 * @param radius - переменная со значением радиуса
 * @param angle - переменная со значением угла
 * @return рассчитанное значение объема
 */
double getVolume(const double radius, const double angle);

/**
 * @brief - рассчитывает площадь поверхности по заданной формуле
 * @param radius - переменная со значением радиуса
 * @param angle - переменная со значением угла
 * @return рассчитанное значение площади
 */
double getArea(double radius, double angle);

/**
 * @brief - точка входа
 * @return 0 если программа выполнена корректно 
 */
int main() {
	setlocale(LC_ALL, "Russian");
	double radius;
	double angle;
	printf("Введите радиус шара ");
	scanf_s("%lf", &radius);
	printf("Введите угол конуса при вершине ");
	scanf_s("%lf", &angle);

	printf("Объем конуса равен: %.2lf\n", getVolume(radius, angle));
	printf("Площадь поверхности конуса равна: %.2lf", getArea(radius, angle));

	return 0;
}

double getVolume(const double radius, const double angle) {
	double rad = angle * M_PI / 180; // перевод в радианы 
	return (M_PI * pow(radius, 3) * pow(sin(rad), 2)*(1 + cos(rad))) / 3;
}

double getArea(const double radius,const double angle) {
	double rad = angle * M_PI / 180;
	return M_PI * pow(radius, 2) * pow(sin(rad), 2) + M_PI * (radius * sin(rad)) * (2 * radius * cos(rad / 2));
}
