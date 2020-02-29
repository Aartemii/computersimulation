#include <iostream>
#include <math.h>
#include <stdio.h>
#include <ctime>

int main()
{
    setlocale(LC_ALL, "rus");
    double R = 8, height = 8, width = 26;
    const double Pi = 3.14;
    const double translation = 180 / 3.14;
    double a, S;

    std::cout << "Задайте ширину прямоугольника: ";
    std::cin >> width;
    std::cout << "\nЗадайте высоту прямоугольника: ";
    std::cin >> height;
    std::cout << "\nЗадайте радиус круга: ";
    std::cin >> R;

    a = cos(sqrt((R * R) - (height / 2 * height / 2)) / R) * translation;

    if ((R * R >= (width * width + height * height) / 4))
    {
        unsigned int start = clock();
        S = width * height;
        unsigned int end = clock();
        std::cout << "\nПлощадь фигуры: " << S << "\n";
        std::cout << end - start;
        std::cout << " мс\n\n\n\n\n";
        return 0;
    }
    else if (R <= width / 2 && R <= height / 2)
    {
        unsigned int start = clock();
        S = Pi * R * R;
        unsigned int end = clock();
        std::cout << "\nПлощадь фигуры: " << S << "\n";
        std::cout << end - start;
        std::cout << " мс\n\n\n\n\n";
        return 0;
    }
    else if (height > width)
    {
        unsigned int start = clock();
        double BO = width / 2;
        double AO = R;
        double AB = sqrt(AO * AO - BO * BO);
        double S_abo = (AB * BO) / 2;

        double degree = atan(BO / AB) * translation;
        double S_aoc = (Pi * R * R * degree) / 360;

        S = 4 * (S_abo + S_aoc);
        unsigned int end = clock();
        std::cout << "\nПлощадь фигуры: " << S << "\n";
        std::cout << end - start;
        std::cout << " мс\n\n\n\n\n";
    }
    else
    {
        unsigned int start = clock();
        double BO = height / 2;
        double AO = R;
        double AB = sqrt(AO * AO - BO * BO);
        double S_abo = (AB * BO) / 2;

        double degree = atan(BO / AB) * translation;
        double S_aoc = (Pi * R * R * degree) / 360;

        S = 4 * (S_abo + S_aoc);
        unsigned int end = clock();
        std::cout << "\nПлощадь фигуры: " << S << "\n";
        std::cout << end - start;
        std::cout << " мс\n\n\n\n\n";
    }
}