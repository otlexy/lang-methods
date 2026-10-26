#include <iostream>
#include <iomanip>
using namespace std;

void homework_task() {
    setlocale(LC_ALL, "Russian");

    int N, M;
    cout << "Введите количество слагаемых (N): ";
    cin >> N;
    cout << "Введите количество знаков после запятой (M): ";
    cin >> M;

    double S = 0.0;
    long long fact = 1;

    long long a_prev2 = 13;
    long long a_prev1 = 15;
    long long a_cur = 13;

    for (int i = 1; i <= N; i++) {
        fact *= i;

 
        if (i == 1) {
            a_cur = 13;
        }
        else if (i == 2) {
            a_cur = 15;
        }
        else {
            a_cur = a_prev1 + a_prev2;
            a_prev2 = a_prev1;
            a_prev1 = a_cur;
        }


        double term = (double)fact / a_cur;


        if (i % 2 == 1) {
            S += term;
        }
        else {
            S -= term;
        }
    }

    cout << fixed << setprecision(M);
    cout << "Сумма S = " << S << endl;

    // Возвращаем cout в обычный режим (чтобы не влиять на другие функции)
    cout.unsetf(ios::fixed);
    cout << setprecision(6);
}