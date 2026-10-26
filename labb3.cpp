#include <iostream>
#include <iomanip>
using namespace std;


int findMinIndex(double* arr, int n) {
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIdx]) minIdx = i;
    }
    return minIdx;
}


int findMaxIndex(double* arr, int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }
    return maxIdx;
}

// Функция сортировки (пузырек). 
// isAscending = true -> по возрастанию, false -> по убыванию
void sortPart(double* arr, int start, int end, bool vozrast) {
    for (int i = start; i < end; i++) {
        for (int j = start; j < end - (i - start); j++) {
            if (vozrast) {
                if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
            }
            else {
                if (arr[j] < arr[j + 1]) swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void lab6_task() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    // Динамический массив
    double* arr = new double[n];

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n > 1) {
        int minIdx = findMinIndex(arr, n);
        int maxIdx = findMaxIndex(arr, n);

        // Сортируем элементы ДО минимального по возрастанию
        if (minIdx > 1) {
            sortPart(arr, 0, minIdx - 1, true);
        }

        // Сортируем элементы ПОСЛЕ максимального по убыванию
        if (maxIdx < n - 2) {
            sortPart(arr, maxIdx + 1, n - 1, false);
        }
    }

    cout << "Результат: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
}