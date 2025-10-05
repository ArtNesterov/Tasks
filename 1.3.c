#include<stdio.h>
#include<math.h>
#include<locale.h>
/**
 * @brief - рассчет силы по заданной формуле
 * @param Sila - переменная со значением силы тяги
 * @param Rabota - переменная со значением работы
 * return рассчитанное значение пути
 */
double getS(const double Sila, const double Rabota);

/**
 * @brief точка входа в программу
 * return 0 если программа выполнена корректно 
 */
int main() {
	setlocale(LC_ALL, "Russian");
	double Sila;
	double Rabota;
	printf("Введите работу в МДж: ");
	scanf_s("%lf", &Rabota);
	printf("Введите силу тяги в кН: ");
	scanf_s("%lf", &Sila);


	printf("Путь, пройденный автомобилем равен: %.2lf", getS(Sila, Rabota));
	return 0;
}
double getS(const double Sila, const double Rabota) {
	return (Rabota * 1000000) / (Sila * 1000);
}
