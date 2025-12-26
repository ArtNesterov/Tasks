#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

/**
* @breif - Рассчитывает функцию A по заданной формуле
* @param x - переменная со значением x 
* @param y - переменная со значением y 
* @param z - переменная со значением z 
* @return рассчитанное значение
*/
double getA(const double x, const double y, const double z);
/**
* @breif - Рассчитывает функцию B по заданной формуле
* @param x - переменная со значением x  
* @param y - переменная со значением y  
* @param z - переменная со значением z
* @return рассчитанное значение
*/
double getB(const double x, const double y, const double z);

/**
 * @breif Точка входа
 * @return 0, если ошибок нет
 */
int main()
{
	const double x = 0.5;
	const double y = 0.05;
	const double z = 0.7;
	printf("A = %lf\n", getA(x, y, z));
	printf("B = %lf\n", getB(x, y, z));
	return 0;
}

double getA(const double x, const double y, const double z)
{
	return (pow(x, 2) * (x + 1)) / (y - pow(sin(x + z), 2));
}

double getB(const double x, const double y, const double z)
{
	return sqrt((x * y) / z) + pow(cos(pow(x + y, 2)), 2);
}
