/*
Лабораторная Работа 3
*/


#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


// Получить случайное число в диапозоне от min до max
int GetRandomNumber(int min, int max) {

    int num = min + rand() % (max - min + 1);
    return num;
}

/*
Дан массив. Все его элементы:

    увеличить в 2 раза;
    уменьшить на число a;
    разделить на первый элемент.

Определить:

    сумму всех элементов массива;
    сумму квадратов всех элементов массива;
    сумму шести первых элементов массива;
    сумму элементов массива с k1-го по k2й;
    среднее арифметическое всех элементов массива;
    среднее арифметическое элементов массива с s1-го по s2-й.
*/
void num_1() {

    string ans;
    cout << "Создать массив при помощи рандома ? [Y/n] : ";

    cin.ignore();
    getline(cin, ans);

    int len;
    vector<long double> vect_num;

    if ((ans == "") || (ans[0] == 'y') || (ans[0] == 'Y') || (ans == "Yes") || (ans == "yes")) {

        srand(time(NULL));
        len = GetRandomNumber(10, 30);

        cout << "Массив длиной " << len << " заполнен : " << endl;

        for (int i = 0; i <= len; ++i) {

            vect_num.push_back(GetRandomNumber(-100, 100));
            cout << vect_num[i] << ' ';

        }

        cout << endl;
    }

    else if ((ans[0] == 'n') || (ans[0] == 'n') || (ans == "no") || (ans == "No")) {

        cout << "Введите длину массива : ";
        cin >> len;

        long double num;

        for (int i = 0; i<= len; ++i) {

            cout << i << "-й элемент будет равен : ";
            cin >> num;

            vect_num.push_back(num);

        }
    }
    
    else {

        cout << "Ответ введен некорректно" << endl;
        return;

    }

    // увеличить в 2 раза
    cout << "[+] Массив увеличен в 2 раза :" << endl;
    for (int i = 0; i <= len; ++i) {

        vect_num[i] = vect_num[i] * 2;
        cout << vect_num[i] << ' ';

    }

    // уменьшить на число a
    long double a;
    cout << endl << "Введите число a : ";
    cin >> a;

    cout << "[+] Массив уменьшен на " << a << " :" << endl;
    for (int i = 0; i <= len; ++i) {

        vect_num[i] = vect_num[i] - a;
        cout << vect_num[i] << ' ';

    }

    // разделить на первый элемент
    if (vect_num[0] != 0) {

        cout << endl << "[+] Массив поделен на " << vect_num[0] << " :" << endl;
        long double first_vect_num = vect_num[0];

        for (int i = 0; i <= len; ++i) {

        vect_num[i] = vect_num[i] / first_vect_num;
        cout << vect_num[i] << ' ';

        }

        cout << endl;
    }

    else {

        cout << endl << "[-] Первый элемент массива равен " << vect_num[0] << ". ";
        cout << "На это число делить нельзя" << endl;

    }

    // сумма всех элементов массива
    long double vect_sum;

    for (int i = 0; i <= len; ++i) vect_sum += vect_num[i];
    
    cout << "Сумма всех элементов массива равна " << vect_sum << endl;

    return;
}


void num_2() {}


// Выбор номера
int main () {

    int task_num;

    cout << "Введите номер задачи : ";
    cin >> task_num;

    switch (task_num) {

        case 1: num_1(); return 0;

        case 2: num_2(); return 0;

        default: 
            cout << "Задачи, под номером " << task_num << " не существует" << endl;
            return 0;

    }

    return 0;
}