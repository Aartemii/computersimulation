#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "rus");
	using namespace std;
	double v, L, a;
	const double g = 9.98;
	const double translation = 3.14 / 180;

	std::cout << "Задайте начальную скорость:\n";
	std::cin >> v;
	std::cout << "Задайте угол (в градусах):\n";
	std::cin >> a;
	std::cout << "Расстояние, которое преодолеет материальная точка:\n";

	unsigned int start = clock();

	a *= translation;
	L = (v * v * sin(2 * a)) / g;
	unsigned int end = clock();

	std::cout << L;
	std::cout << "\nВремя выполнения программы: ";
	std::cout << end - start;
	std::cout << " мс\n\n\n\n\n";
}