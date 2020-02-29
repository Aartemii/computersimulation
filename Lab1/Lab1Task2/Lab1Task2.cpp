#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "rus");
	using namespace std;
	double v, L, a, t, x = 0, y = 0;
	const double g = 9.98;
	const double translation = 3.14 / 180;

	std::cout << "Задайте начальную скорость:\n";
	std::cin >> v;
	std::cout << "Задайте угол (в градусах):\n";
	std::cin >> a;
	std::cout << "Задайте шаг моделирования\n";
	std::cin >> t;
	std::cout << "Расстояние, которое преодолеет материальная точка:\n";

	unsigned int start = clock();

	a *= translation;
	double vx = v * cos(a);
	double vy = v * sin(a);
	for ( ; ; )
	{
		if (y < 0) break;
		x += vx * t;
		vy -= g * t;
		y += vy * t;
	}

	L = x + ((vx * y) / (vy));
	unsigned int end = clock();

	std::cout << L;
	std::cout << "\nВремя выполнения программы: ";
	std::cout << end - start;
	std::cout << " мс\n\n\n\n\n";
}