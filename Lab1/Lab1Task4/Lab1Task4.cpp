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
    double S, Dx, Dy;
    int N = 1000, K;

    std::cout << "Задайте ширину прямоугольника: ";
    std::cin >> width;
    std::cout << "\nЗадайте высоту прямоугольника: ";
    std::cin >> height;
    std::cout << "\nЗадайте радиус круга: ";
    std::cin >> R;

    if (R * R >= (width * width + height * height) / 4) // Круг описан
    {
        unsigned int start = clock();
        K = 0;
        for (int i = 0; i < N; i++)
        {
            double ax = -1 * width / 2, bx = width / 2;
            double ay = -1 * height / 2, by = height / 2;
            
            Dx = (double)rand() / (double)RAND_MAX * (bx - ax) + ax;
            Dy = (double)rand() / (double)RAND_MAX * (by - ay) + ay;
            K++;
        }

        S = (width * height * K) / N;
        unsigned int end = clock();
        std::cout << "\nПлощадь фигуры: " << S << "\n";
        std::cout << "\nОбщее количество точек: " << N << "\n";
        std::cout << "\nКоличество попаданий: " << K << "\n";
        std::cout << "\nВремя выполнения: ";
        std::cout << end - start;
        std::cout << " мс\n\n\n\n\n";
        return 0;
    }
    else if (width >= R * 2 && height >= R * 2) // Круг вписан
    {
        unsigned int start = clock();
        K = 0;
        for (int i = 0; i < N; i++)
        {
            double a = -1 * R, b = R;

            Dx = (double)rand() / (double)RAND_MAX * (b - a) + a;
            Dy = (double)rand() / (double)RAND_MAX * (b - a) + a;

            std::cout << "\n Точка по х: " << Dx << " Точка по y: " << Dy;
            if (Dx * Dx + Dy * Dy < R * R)
            {
                K++;
                std::cout << "     [+]";
            }
            else
            {
                std::cout << "     (-)";
            }
        }
        S = (4 * R * R * K) / N;
        unsigned int end = clock();
        std::cout << "\nПлощадь фигуры: " << S << "\n";
        std::cout << "\nОбщее количество точек: " << N << "\n";
        std::cout << "\nКоличество попаданий: " << K << "\n";
        std::cout << "\nВремя выполнения: ";
        std::cout << end - start;
        std::cout << " мс\n\n\n\n\n";
        return 0;
    }
    else if (height > width) // Если треугольники меняются местами
    {
        unsigned int start = clock();
        K = 0;
        for (int i = 0; i < N; i++)
        {
            double ax = -1 * width / 2, bx = width / 2;
            double ay = -1 * R, by = R;

            Dx = (double)rand() / (double)RAND_MAX * (bx - ax) + ax;
            Dy = (double)rand() / (double)RAND_MAX * (by - ay) + ay;

            std::cout << "\n Точка по х: " << Dx << " Точка по y: " << Dy;
            if (Dx * Dx + Dy * Dy < R * R)
            {
                K++;
                std::cout << "     [+]";
            }
            else
            {
                std::cout << "     (-)";
            }
        }
        S = (2 * R * width * K) / N;
        unsigned int end = clock();
        std::cout << "\nПлощадь фигуры: " << S << "\n";
        std::cout << "\nОбщее количество точек: " << N << "\n";
        std::cout << "\nКоличество попаданий: " << K << "\n";
        std::cout << "\nВремя выполнения: ";
        std::cout << end - start;
        std::cout << " мс\n\n\n\n\n";
    }
    else // Третий вариант
    {
        unsigned int start = clock();
        K = 0;
        for (int i = 0; i < N; i++)
        {
            double ax = -1 * R, bx = R;
            double ay = -1 * height / 2, by = height / 2;

            Dx = (double)rand() / (double)RAND_MAX * (bx - ax) + ax;
            Dy = (double)rand() / (double)RAND_MAX * (by - ay) + ay;

            std::cout << "\n Точка по х: " << Dx << " Точка по y: " << Dy;
            if (Dx * Dx + Dy * Dy < R * R)
            {
                K++;
                std::cout << "     [+]";
            }
            else
            {
                std::cout << "     (-)";
            }
        }
        S = (2 * R * height * K) / N;
        unsigned int end = clock();
        std::cout << "\nПлощадь фигуры: " << S << "\n";
        std::cout << "\nОбщее количество точек: " << N << "\n";
        std::cout << "\nКоличество попаданий: " << K << "\n";
        std::cout << "\nВремя выполнения: ";
        std::cout << end - start;
        std::cout << " мс\n\n\n\n\n";
    }
}