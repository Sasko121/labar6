#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <locale.h>

#define EPSILON 0.0001

// Визначаємо M_PI, якщо він не оголошений
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Функція для обчислення значення рівняння
double equation(double x) {
    return sqrt(x) - 2 * cos(M_PI / 2 * x) - x;
}

// Метод бісекції
double bisection(double a, double b) {
    double c;
    while (fabs(b - a) > EPSILON) {
        c = (a + b) / 2;
        if (equation(a) * equation(c) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }
    return c;
}

// Метод простих ітерацій
double simpleIteration(double x0) {
    double x1;
    do {
        x1 = sqrt(2 * cos(M_PI / 2 * x0) + x0);
        x0 = x1;
    } while (fabs(equation(x1)) > EPSILON);
    return x1;
}

// Метод хорд
double chord(double a, double b) {
    double x1;
    do {
        x1 = a - equation(a) * (b - a) / (equation(b) - equation(a));
        a = b;
        b = x1;
    } while (fabs(equation(x1)) > EPSILON);
    return x1;
}

// Метод дотичних (Ньютона)
double tangent(double x0) {
    double x1;
    do {
        x1 = x0 - equation(x0) / (1 / (2 * sqrt(x0)) + M_PI / 2 * sin(M_PI / 2 * x0) - 1);
        x0 = x1;
    } while (fabs(equation(x1)) > EPSILON);
    return x1;
}

int main() {
    setlocale(LC_ALL, "RU");

    // Визначаємо початкові інтервали для методів
    double a = 0;
    double b = 2; // Обираємо інтервал для пошуку кореня

    printf("Метод бисекции: %lf\n", bisection(a, b));
    printf("Метод простых итераций: %lf\n", simpleIteration(1.0));
    printf("Метод хорд: %lf\n", chord(a, b));
    printf("Метод касательных: %lf\n", tangent(1.0));

    return 0;
}

