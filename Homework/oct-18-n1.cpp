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

vector<long int> VectGen() {

    string ans;
    cout << "Создать массив при помощи рандома ? [Y/n] : ";

    cin.ignore();
    getline(cin, ans);

    int len;
    vector<long int> vect_num;

    if ((ans == "") || (ans[0] == 'y') || (ans[0] == 'Y') || (ans == "Yes") || (ans == "yes")) {

        srand(time(NULL));
        len = GetRandomNumber(20, 30);

        cout << "Массив длиной " << len << " заполнен : " << endl;

        for (int i = 0; i < len; ++i) {

            vect_num.push_back(GetRandomNumber(-100, 100));
            cout << vect_num[i] << ' ';

        }

        cout << endl;
    }

    else if ((ans[0] == 'n') || (ans[0] == 'N') || (ans == "no") || (ans == "No")) {

        cout << "Введите длину массива : ";
        cin >> len;

        long double num;

        for (int i = 0; i < len; ++i) {

            cout << i << "-й элемент будет равен : ";
            cin >> num;

            vect_num.push_back(num);

        }
    }
    
    else {

        cout << "Ответ введен некорректно" << endl;
        return vect_num;

    }

    return vect_num;
}


/*
Дан массив. Все его элементы:

    - увеличить в 2 раза;
    - уменьшить на число a;
    - разделить на первый элемент.

Определить:

    - сумму всех элементов массива;
    - сумму квадратов всех элементов массива;
    - сумму шести первых элементов массива;
    - сумму элементов массива с k1-го по k2й;
    - среднее арифметическое всех элементов массива;
    - среднее арифметическое элементов массива с s1-го по s2-й.
*/
void num_1() {

    vector<long int> vect_num;
    vect_num = VectGen();

    size_t len = vect_num.size();

    // Увеличить в 2 раза
    cout << "[+] Массив увеличен в 2 раза :" << endl;
    for (size_t i = 0; i <= len; ++i) {

        vect_num[i] = vect_num[i] * 2;
        cout << vect_num[i] << ' ';

    }

    // Уменьшить на число a
    long double a;
    cout << endl << "Введите число a : ";
    cin >> a;

    cout << "[+] Массив уменьшен на " << a << " :" << endl;
    for (size_t i = 0; i <= len; ++i) {

        vect_num[i] = vect_num[i] - a;
        cout << vect_num[i] << ' ';

    }

    // Разделить на первый элемент
    if (vect_num[0] != 0) {

        cout << endl << "[+] Массив поделен на " << vect_num[0] << " :" << endl;
        long double first_vect_num = vect_num[0];

        for (size_t i = 0; i <= len; ++i) {

        vect_num[i] = vect_num[i] / first_vect_num;
        cout << vect_num[i] << ' ';

        }

        cout << endl;
    }

    else {

        cout << endl << "[-] Первый элемент массива равен " << vect_num[0] << ". ";
        cout << "На это число делить нельзя" << endl;

    }

    long double vect_sum = 0, vect_sq = 0, vect_six = 0, vect_ksix = 0, vect_saver = 0;

    // Сумма всех элементов массива и квадратов всех элементов массива
    for (size_t i = 0; i <= len; ++i) {
        vect_sum += vect_num[i];
        vect_sq += (vect_num[i] * vect_num[i]);

    }
    
    cout << "[+] Сумма всех элементов массива : " << vect_sum << endl;
    cout << "[+] Сумма квадратов всех элементов массива : " << vect_sq << endl;

    // Сумма шести первых элементов массива
    if (len >= 6) {
        for (size_t i = 0; i <= 6; ++i) {
            vect_six += vect_num[i];
        }
        cout << "[+] Сумма шести первых элементов массива : " << vect_six << endl;
    }

    else cout << "[-] Длина массива меньше 6-ти" << endl;

    // Сумма элементов массива с k1-го по k2й
    int k1, k2;
    cout << "Введите k1 и k2 (границы подсчета суммы элементов) : ";
    cin >> k1 >> k2;

    if ((k1 > k2) && (k1 <= len) && (k2 <= len) && (k1 >= 0) && (k2 >= 0)) {
        for (int i = k2; i <= k1; ++i) {

            vect_ksix += vect_num[i];

        }
        cout << "[+] Сумма элементов массива от " << k2 << " до " << k1 << " : " << vect_ksix << endl;
    }

    else if ((k1 <= len) && (k2 <= len) && (k1 >= 0) && (k2 >= 0)) {
        for (int i = k1; i <= k2; ++i) {

            vect_ksix += vect_num[i];

        }
        cout << "[+] Сумма элементов массива от " << k1 << " до " << k2 << " : " << vect_ksix << endl;
    }

    else cout << "[-] Длина массива не попадает в диапазон" << endl;

    // Среднее арифметическое всех элементов массива
    cout << "[+] Среднее арифметическое всех элементов массива : " << vect_sum / len << endl;

    // Среднее арифметическое элементов массива с s1-го по s2-й
    int s1, s2;
    cout << "Введите s1 и s2 (границы подсчета суммы элементов) : ";
    cin >> s1 >> s2;

    if ((s1 > s2) && (s1 <= len) && (s2 <= len) && (s1 >= 0) && (s2 >= 0)) {
        for (int i = s2; i <= s1; ++i) {

            vect_saver += vect_num[i];

        }
        cout << "[+] Среднее арифметическое элементов массива от " << s2 << " до " << s1 << " : ";
        cout << vect_saver / (s1 - s2 + 1) << endl;
    }

    else if ((s1 <= len) && (s2 <= len) && (s1 >= 0) && (s2 >= 0)) {
        for (int i = s1; i <= s2; ++i) {

            vect_saver += vect_num[i];

        }
        cout << "[+] Среднее арифметическое элементов массива от " << s1 << " до " << s2 << " : ";
        cout << vect_saver / (s1 - s1 + 1) << endl;
    }

    else cout << "[-] Длина массива не попадает в диапазон" << endl;

    return;
}


/*
Дан одномерный массив из 20 элементов. 
Переставить первые три и последние три элемента, сохранив порядок их следования.
*/
void num_2() {

    vector<long int> vect_num;
    vect_num = VectGen();

    size_t len = vect_num.size();

    long double vnum;
    
    for (size_t i = 0; i < 3; ++i) {

        vnum = vect_num[i];
        vect_num[i] = vect_num[len - 3 + i];
        vect_num[len - 3 + i] = vnum;

    }

    cout << "Масиив с переставленными элементами равен : " << endl;

    for (size_t i = 0; i < len; ++i) {
        cout << vect_num[i] << " ";
    }

    cout << endl;

    return;
}


/*
Удалить из массива:

    - первый отрицательный элемент (если отрицательные элементы в массиве есть)
    - последний четный элемент (если четные элементы в массиве есть)
*/
void num_3() {

    vector<long int> vect_num;
    vect_num = VectGen();

    size_t len = vect_num.size();
    long int neg_num = -1, even_num = -1;

    for (size_t i = 0; i < len; ++i) {

        if (vect_num[i] % 2 == 0) even_num = i;

        else if ((vect_num[i] < 0) && (neg_num == -1)) neg_num = i;
    }

    if (even_num != -1) {
        vect_num.erase(vect_num.begin() + even_num);

        if (neg_num > even_num) neg_num -= 1;
    }

    if (neg_num != -1) {
        vect_num.erase(vect_num.begin() + neg_num);
    }

    cout << "После обработки масиив равен : " << endl;

    len = vect_num.size();
    for (size_t i = 0; i < len; ++i) {
        cout << vect_num[i] << " ";
    }

    cout << endl;

    return;
}


// Дано название города. Определить, четно или нет количество символов в нем.
void num_4() {

    cout << "Введите название города : ";
    string city;
    cin >> city;

    size_t len = city.length();

    if (len % 2 == 0) cout << "В названии города четное кол-во символов : " << len;
    else cout << "В названии города нечетное кол-во символов : " << len;

    cout << endl;

    return;
}


// Даны две фамилии. Верните true, если первая длинее.
void num_5() {

    cout << "Введите фамилию Игоря : ";
    string sn_igor;
    cin >> sn_igor;

    cout << "Введите фамилию Ксюши : ";
    string sn_ksy;
    cin >> sn_ksy;

    if (sn_igor.length() > sn_ksy.length()) cout << "[+] Ответ : true" << endl;
    else cout << "[-] Ответ : false" << endl;

    return;
}


// Даны названия трех городов. Запишите в the_longest самое длинное, а самое короткое название в the_shortest.
void num_6() {
    return;
}


// Выбор номера
int main () {

    int task_num;

    cout << "Введите номер задачи : ";
    cin >> task_num;

    switch (task_num) {

        case 1: num_1(); return 0;

        case 2: num_2(); return 0;

        case 3: num_3(); return 0;

        case 4: num_4(); return 0;

        case 5: num_5(); return 0;

        case 6: num_6(); return 0;

        default: 
            cout << "Задачи, под номером " << task_num << " не существует" << endl;
            return 0;

    }

    return 0;
}
