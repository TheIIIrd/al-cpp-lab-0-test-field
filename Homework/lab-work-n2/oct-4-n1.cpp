/*
Лабораторная Работа 2
*/

#include <cmath>
#include <iostream>
#include <math.h>
#include <utility>

using namespace std;

/*
С клавиатуры вводятся числа X, Y, Z. Необходимо записать условие, которое
является истинным, когда:

- каждое из чисел X и Y нечетное;
- только одно из чисел X и Y меньше 20;
- хотя бы одно из чисел X и Y равно нулю;
- каждое из чисел X, Y, Z отрицательное;
- только одно из чисел X, Y и Z кратно пяти;
- хотя бы одно из чисел X, Y, Z больше 100.

В случае, если условие выполняется вывести на экран - condition is true, иначе
condition is false
*/
void num_1() {

  int X, Y, Z;
  bool flag;

  cout << "Введите три числа >>> ";
  cin >> X >> Y >> Z;

  if ((X % 2 != 0) && (Y % 2 != 0)) {

    cout << "[+] condition is true" << endl;

  } else
    cout << "[-] condition is false" << endl;

  if (((X < 20) && (Y > 20)) || ((X > 20) && (Y < 20))) {

    cout << "[+] condition is true" << endl;

  } else
    cout << "[-] condition is false" << endl;

  if (X == 0 || Y == 0) {

    cout << "[+] condition is true" << endl;

  } else
    cout << "[-] condition is false" << endl;

  if (X < 0 && Y < 0 && Z < 0) {

    cout << "[+] condition is true" << endl;
  }
  cout << "[-] condition is false" << endl;

  if ((X % 5 == 0 && (Y * Z) % 5 != 0) || (Y % 5 == 0 && (X * Z) % 5 != 0) ||
      (Z % 5 == 0 && (Y * X) % 5 != 0)) {

    cout << "[+] condition is true" << endl;
  }
  cout << "[-] condition is false" << endl;

  if (X > 100 || Y > 100 || Z > 100) {

    cout << "[+] condition is true" << endl;
  }
  cout << "[-] condition is false" << endl;

  return;
}

/*
Клетка на шахматной доски определяется парой натуральных чисел, каждое из
которых не превосходит 8: первое число — номер вертикали (при счете слева
направо), второе — номер горизонтали (при счете снизу вверх). Для пары удобно
использовать тип std::pair, чтобы обратиться к первому элементу пары, нужно
указать к переменной приписать .first, чтобы обратиться ко второму элементу -
.second.

Пример

Продемонстрируем как считать с клавиатуры данные и записать их в пару:

   using byte = unsigned char;
   std::pair<byte, byte> position;
   std::cin >> position.first >> position.second;

Продемонстрируем, как задать значения пары при инициализации и выведем их на
экран.

   using byte = unsigned char;
   std::pair<byte, byte> position(0, 4);
                              std::cout << position.first << " " <<
position.second;

Даны две координаты шахматных фигур positionA(a, b) и positionB(c, d). Числа a,
b, c, d не превосходят 8. Требуется:

- На поле positionA(a, b) расположена ладья. Записать условие, при котором она
угрожает полю positionB(c, d).
- На поле positionA(a, b) расположен слон. Записать условие, при котором он
угрожает полю positionB(c, d).
- На поле positionA(a, b) расположен король. Записать условие, при котором он
может одним ходом попасть на поле positionB(c, d).
- На поле positionA(a, b) расположен ферзь. Записать условие, при котором он
угрожает полю positionB(c, d).
- На поле positionA(a, b) расположена белая пешка. Записать условие, при котором
она может одним ходом попасть на поле positionB(c, d): при обычном ходе; когда
она "бьет" фигуру или пешку соперника.
*/
void num_2() {

  pair<int, int> positionA;
  pair<int, int> positionB;

  cout << "Введите координаты 2-х клеток >>> ";
  cin >> positionA.first >> positionA.second >> positionB.first >>
      positionB.second;

  if ((positionA.first != positionB.first ||
       positionA.second != positionB.second) &&
      (positionA.first > 0 && positionA.first < 9 && positionA.second > 0 &&
       positionA.second < 9 &&
       (positionB.first > 0 && positionB.first < 9 && positionB.second > 0 &&
        positionB.second < 9))) {

    // На поле positionA(a, b) расположена ладья. Записать условие, при котором
    // она угрожает полю positionB(c, d).
    if (positionA.first == positionB.first ||
        positionA.second == positionB.second) {

      cout << "[+] Ладья (" << positionA.first << ", " << positionA.second
           << ") ";
      cout << "угрожает полю [" << positionB.first << " ," << positionB.second
           << "]" << endl;

    }

    else {

      cout << "[-] Ладья (" << positionA.first << ", " << positionA.second
           << ") ";
      cout << "не угрожает полю [" << positionB.first << " ,"
           << positionB.second << "]" << endl;
    }

    // На поле positionA(a, b) расположен слон. Записать условие, при котором он
    // угрожает полю positionB(c, d).
    if (abs(positionA.first - positionB.first) ==
        abs(positionA.second - positionB.second)) {

      cout << "[+] Слон (" << positionA.first << ", " << positionA.second
           << ") ";
      cout << "угрожает полю [" << positionB.first << " ," << positionB.second
           << "]" << endl;

    }

    else {

      cout << "[-] Слон (" << positionA.first << ", " << positionA.second
           << ") ";
      cout << "не угрожает полю [" << positionB.first << " ,"
           << positionB.second << "]" << endl;
    }

    // На поле positionA(a, b) расположен король. Записать условие, при котором
    // он может одним ходом попасть на поле positionB(c, d).
    if (abs(positionA.first - positionB.first) <= 1 &&
        abs(positionA.second - positionB.second) <= 1 &&
        (positionA.first != positionB.first &&
         positionA.second != positionB.second)) {

      cout << "[+] Король (" << positionA.first << ", " << positionA.second
           << ") ";
      cout << "может переместиться на [" << positionB.first << " ,"
           << positionB.second << "]" << endl;

    }

    else {

      cout << "[-] Король (" << positionA.first << ", " << positionA.second
           << ") ";
      cout << "не может переместиться на [" << positionB.first << " ,"
           << positionB.second << "]" << endl;
    }

    // На поле positionA(a, b) расположен ферзь. Записать условие, при котором
    // он угрожает полю positionB(c, d).
    if ((positionA.first == positionB.first ||
         positionA.second == positionB.second) ||
        (abs(positionA.first - positionB.first) ==
         abs(positionA.second - positionB.second))) {

      cout << "[+] Ферзь (" << positionA.first << ", " << positionA.second
           << ") ";
      cout << "угрожает полю [" << positionB.first << " ," << positionB.second
           << "]" << endl;

    }

    else {

      cout << "[-] Ферзь (" << positionA.first << ", " << positionA.second
           << ") ";
      cout << "не угрожает полю [" << positionB.first << " ,"
           << positionB.second << "]" << endl;
    }

    /*
    На поле positionA(a, b) расположена белая пешка. Записать условие,
    при котором она может одним ходом попасть на поле positionB(c, d):

    - при обычном ходе;
    - когда она "бьет" фигуру или пешку соперника.
    */
    if ((positionA.second == 2 && (positionB.second == positionA.second + 2) &&
         positionA.first == positionB.first) ||
        ((positionB.first == positionA.first + 1) &&
         positionA.second == positionB.second)) {

      cout << "[+] Пешка (" << positionA.first << ", " << positionA.second
           << ") ";
      cout << "может переместиться на [" << positionB.first << " ,"
           << positionB.second << "]" << endl;

    }

    else if ((abs(positionA.first - positionB.first) == 1) &&
             (abs(positionB.second - positionA.second) == 1)) {

      cout << "[+] Пешка (" << positionA.first << ", " << positionA.second
           << ") ";
      cout << "может переместиться на [" << positionB.first << " ,"
           << positionB.second << "] если тут будет вражеская фигура" << endl;

    }

    else {

      cout << "[-] Пешка (" << positionA.first << ", " << positionA.second
           << ") ";
      cout << "не может переместиться на [" << positionB.first << " ,"
           << positionB.second << "]" << endl;
    }

  }

  else {

    cout << "[*] Фигура (" << positionA.first << ", " << positionA.second
         << ") ";
    cout << "уже на позиции [" << positionB.first << " ," << positionB.second
         << "] ";
    cout << "или координаты выходят за границы шахматной доски" << endl;
  }

  return;
}

/*
Напечатать таблицу умножения на 7:

     1 х 7 = 7
     2 х 7 = 14
     ...
     9 х 7 = 63

Напечатать таблицу умножения на N, которое вводится с клавиатуры:

     1 х N = 1*N
     2 х N = 2*N
     ...
     9 х N = 9*N
*/
void num_3() {

  for (int i = 0; i < 10; ++i) {

    cout << i << " x 7 = " << i * 7 << endl;
  }

  long double N;

  cout << "Введите ваше число >>> ";
  cin >> N;

  for (int i = 0; i < 10; ++i) {

    cout << i << " x " << N << " = " << i * N << endl;
  }

  return;
}

/*
Найти и вывести на экран:

-	произведение всех целых чисел от 8 до 15;
-	произведение всех целых чисел от a до 20 (значение a вводится с
клавиатуры; 1 < a < 20); -	произведение всех целых чисел от 1 до b
(значение b вводится с клавиатуры; 1 < b < 20); -	произведение всех целых
чисел от a до b (значения a и b вводятся с клавиатуры; b >= a).
*/
void num_4() {
  // произведение всех целых чисел от 8 до 15
  long long int summ;
  summ = 1;

  cout << "[+] Произведение всех целых чисел от 8 до 15 : " << endl;

  for (int i = 8; i < 16; ++i) {
    summ *= i;
  }

  cout << summ << endl;

  // произведение всех целых чисел от a до 20
  long int a;
  summ = 1;

  cout << endl << "Введите число a >>> ";
  cin >> a;

  for (int i = a; i < 21; ++i) {
    summ *= i;
  }

  cout << summ << endl;

  // произведение всех целых чисел от 1 до b
  long int b;
  summ = 1;

  cout << endl << "Введите число b >>> ";
  cin >> b;

  for (int i = 1; i <= b; ++i) {
    summ *= i;
  }

  cout << summ << endl;

  // произведение всех целых чисел от a до b
  cout << endl << "Введите число a и b >>> ";
  cin >> a >> b;
  summ = 1;

  for (int i = a; i <= b; ++i) {
    summ *= i;
  }

  cout << summ << endl;

  return;
}

int main() {

  int task_num;

  cout << "Введите номер задачи : ";
  cin >> task_num;

  switch (task_num) {

  case 1:
    num_1();
    return 0;

  case 2:
    num_2();
    return 0;

  case 3:
    num_3();
    return 0;

  case 4:
    num_4();
    return 0;

  default:
    cout << "Задачи, под номером " << task_num << " не существует" << endl;
    return 0;
  }

  return 0;
}
