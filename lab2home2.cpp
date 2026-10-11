#include <iostream>
#include <string>
using namespace std;

void home2() {
    string s;
    cin >> s;

    bool b = true;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c == '-') continue;

        if ((c - '0') % 2 != 0) {
            b = false;
            break;
        }
    }

    if (b)
        cout << "Число состоит только из чётных цифр" << endl;
    else
        cout << "Число состоит не только из чётных цифр" << endl;
}


void reverse(double X[], double Y[], int n) {
    for (int i = 0; i < n; i++) {
        Y[i] = X[n - 1 - i];
    }
}

void percents(double Y[], int n) {
    int chet = 0, neChet = 0, zero = 0;

    for (int i = 0; i < n; i++) {
        int intPart = (int)Y[i];

        if (Y[i] == 0.0)
            zero++;
        else if (intPart % 2 == 0)
            chet++;
        else
            neChet++;
    }

    cout << "Чётных: " << (double)chet / n * 100 << "%" << endl;
    cout << "Нечётных: " << (double)neChet / n * 100 << "%" << endl;
    cout << "Нулевых: " << (double)zero / n * 100 << "%" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    //home2();
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    double X[100], Y[100];

    cout << "Введите " << n << " чисел:" << endl;
    for (int i = 0; i < n; i++)
        cin >> X[i];

    reverse(X, Y, n);
    percents(Y, n);
}