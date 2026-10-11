#include <iostream>

using namespace std;

void Home1(int N) {
    for (int i = 1; i <= N; i += 2) {
        int d = i % 10;
        if (d!=0 && i % d == 0)
            cout << i * i << " ";
    }
    cout << endl;
}

int lab1() {
    int x;
    int count = 0;
    int prevSign = 0;

    while (true) {
        cin >> x;

        if (!cin) break;
        if (x == 0) break;

        int sign;
        if (x > 0) {
            sign = 1;
        }
        else {
            sign = -1;
        }

        if (prevSign != 0 && sign != prevSign)
            count++;

        prevSign = sign;
    }
    return count;
}

int main() {
/*
    int N;
    cin >> N;
    Home1(N);
*/
    cout << lab1() << endl;
}