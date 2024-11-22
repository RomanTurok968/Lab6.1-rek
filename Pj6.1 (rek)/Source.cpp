#include <iostream>
#include <ctime>  
#include <iomanip> 
using namespace std;

// ��������� ������
void COUT(int mas[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << mas[i] << " ";
    COUT(mas, size, i + 1);
}

// ϳ�������� ������� ��'����� ������ ��������
int PlusEl(int mas[], int size, int i = 0) {
    if (i == size) return 0;
    return ((mas[i] < 0 && mas[i] % 2 == 0) ? 1 : 0) + PlusEl(mas, size, i + 1);
}

// ���������� ���� ��'����� ������ ��������
int SUM(int mas[], int size, int i = 0) {
    if (i == size) return 0;
    return ((mas[i] < 0 && mas[i] % 2 == 0) ? mas[i] : 0) + SUM(mas, size, i + 1);
}

// ������� ��'��� ���� �������� �� ���
void Nulls(int mas[], int size, int i = 0) {
    if (i == size) return;
    if (mas[i] < 0 && mas[i] % 2 == 0) {
        mas[i] = 0;
    }
    Nulls(mas, size, i + 1);
}

int main() {
    srand((unsigned)time(0)); // ��������� ���������� �����
    setlocale(LC_CTYPE, "ukr");

    const int SIZE = 20; // ����� �� 20 ��������
    int a[SIZE];

    // ������� ����� � ���������� ������� � ������� �� -20 �� 34
    for (int i = 0; i < SIZE; i++) {
        a[i] = rand() % 55 - 20;  // ��������� ������� �� -20 �� 34
    }

    // ��������� ����������� ������
    cout << "���������� �����: " << endl;
    COUT(a, SIZE);

    // ϳ�������� ������� ��'����� ������ ��������
    int count = PlusEl(a, SIZE);

    // ���������� ���� ��'����� ������ ��������
    int sum = SUM(a, SIZE);

    // ��������� ����������
    cout << "ʳ������ ��'����� ������ ��������: " << count << endl;
    cout << "���� ��'����� ������ ��������: " << sum << endl;

    // ����� ��'����� ������ �������� �� ���
    Nulls(a, SIZE);

    // ��������� �������������� ������
    cout << "������������� �����: " << endl;
    COUT(a, SIZE);

    return 0;
}
