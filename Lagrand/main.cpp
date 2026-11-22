#include <iostream>
#include <Windows.h>


using namespace std;

void calculate_coeffs(const double X[], const double Y[], double a[], int n) 
{
    double div_diff[100];
    for (int i = 0; i < n; ++i) 
    {
        div_diff[i] = Y[i];
    }

    a[0] = div_diff[0];
    cout << "Коэффициент a0: " << a[0] << endl;

    for (int k = 1; k < n; ++k) 
    {
        for (int i = 0; i < n - k; ++i) 
        {
            div_diff[i] = (div_diff[i + 1] - div_diff[i]) / (X[i + k] - X[i]);
        }
        a[k] = div_diff[0];
        cout << "Коэффициент a" << k << ": " << a[k] << endl;
    }
}

double newton_interpolate(const double X[], const double Y[], int n, double x_to_find) {
    double a[100];
    calculate_coeffs(X, Y, a, n);

    double result = 0.0;
    double multiplier = 1.0;

    for (int i = 0; i < n; ++i) {
        result += a[i] * multiplier;
        multiplier *= (x_to_find - X[i]);
    }
    return result;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    const int n = 4;
    double X[n] = { -2, 0, 1, 3 };
    double Y[n] = { -1, -1, 2, 14 };
    double x = 2.0;

    double result = newton_interpolate(X, Y, n, x);
    cout << "Значение в точке x = " << x << ": " << result << endl;

    return 0;
}
