#include <iostream>
#include <ctime>  
#include <iomanip> 
using namespace std;

// Виведення масиву
void COUT(int mas[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << mas[i] << " ";
    COUT(mas, size, i + 1);
}

// Підрахунок кількості від'ємних парних елементів
int PlusEl(int mas[], int size, int i = 0) {
    if (i == size) return 0;
    return ((mas[i] < 0 && mas[i] % 2 == 0) ? 1 : 0) + PlusEl(mas, size, i + 1);
}

// Обчислення суми від'ємних парних елементів
int SUM(int mas[], int size, int i = 0) {
    if (i == size) return 0;
    return ((mas[i] < 0 && mas[i] % 2 == 0) ? mas[i] : 0) + SUM(mas, size, i + 1);
}

// Замінити від'ємні парні елементи на нулі
void Nulls(int mas[], int size, int i = 0) {
    if (i == size) return;
    if (mas[i] < 0 && mas[i] % 2 == 0) {
        mas[i] = 0;
    }
    Nulls(mas, size, i + 1);
}

int main() {
    srand((unsigned)time(0)); // генератор випадкових чисел
    setlocale(LC_CTYPE, "ukr");

    const int SIZE = 20; // Масив має 20 елементів
    int a[SIZE];

    // Формуємо масив з випадкових значень в діапазоні від -20 до 34
    for (int i = 0; i < SIZE; i++) {
        a[i] = rand() % 55 - 20;  // Генерація значень від -20 до 34
    }

    // Виведення початкового масиву
    cout << "Початковий масив: " << endl;
    COUT(a, SIZE);

    // Підрахунок кількості від'ємних парних елементів
    int count = PlusEl(a, SIZE);

    // Обчислення суми від'ємних парних елементів
    int sum = SUM(a, SIZE);

    // Виведення результатів
    cout << "Кількість від'ємних парних елементів: " << count << endl;
    cout << "Сума від'ємних парних елементів: " << sum << endl;

    // Заміна від'ємних парних елементів на нулі
    Nulls(a, SIZE);

    // Виведення модифікованого масиву
    cout << "Модифікований масив: " << endl;
    COUT(a, SIZE);

    return 0;
}
