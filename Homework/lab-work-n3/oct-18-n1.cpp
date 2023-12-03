/*
Лабораторная Работа 3
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Получить случайное число в диапозоне от min до max
int GetRandomNumber(int min, int max) {
  int num = min + rand() % (max - min + 1);
  return num;
}

// Генерация массива
vector<long int> VectGen() {

  string ans;
  cout << "Создать массив при помощи рандома ? [Y/n] : ";

  cin.ignore();
  getline(cin, ans);

  size_t len;
  vector<long int> vect_num;

  if ((ans == "") || (ans[0] == 'y') || (ans[0] == 'Y') || (ans == "Yes") ||
      (ans == "yes")) {

    srand(time(NULL));
    len = GetRandomNumber(20, 30);

    cout << "Массив длиной " << len << " заполнен : " << endl;

    for (int i = 0; i < len; ++i) {

      vect_num.push_back(GetRandomNumber(-100, 100));
      cout << vect_num.at(i) << ' ';
    }

    cout << endl;
  }

  else if ((ans[0] == 'n') || (ans[0] == 'N') || (ans == "no") ||
           (ans == "No")) {

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
  for (size_t i = 0; i < len; ++i) {

    vect_num.at(i) = vect_num.at(i) * 2;
    cout << vect_num.at(i) << ' ';
  }

  // Уменьшить на число a
  long double a;
  cout << endl << "Введите число a : ";
  cin >> a;

  cout << "[+] Массив уменьшен на " << a << " :" << endl;
  for (size_t i = 0; i < len; ++i) {

    vect_num.at(i) = vect_num.at(i) - a;
    cout << vect_num.at(i) << ' ';
  }

  // Разделить на первый элемент
  if (vect_num[0] != 0) {

    cout << endl << "[+] Массив поделен на " << vect_num[0] << " :" << endl;
    long double first_vect_num = vect_num[0];

    for (size_t i = 0; i < len; ++i) {

      vect_num.at(i) = vect_num.at(i) / first_vect_num;
      cout << vect_num.at(i) << ' ';
    }

    cout << endl;
  }

  else {

    cout << endl << "[-] Первый элемент массива равен " << vect_num[0] << ". ";
    cout << "На это число делить нельзя" << endl;
  }

  long double vect_sum = 0, vect_sq = 0, vect_six = 0, vect_ksix = 0,
              vect_saver = 0;

  // Сумма всех элементов массива и квадратов всех элементов массива
  for (size_t i = 0; i < len; ++i) {
    vect_sum += vect_num.at(i);
    vect_sq += (vect_num.at(i) * vect_num.at(i));
  }

  cout << "[+] Сумма всех элементов массива : " << vect_sum << endl;
  cout << "[+] Сумма квадратов всех элементов массива : " << vect_sq << endl;

  // Сумма шести первых элементов массива
  if (len >= 6) {
    for (size_t i = 0; i <= 6; ++i) {
      vect_six += vect_num.at(i);
    }
    cout << "[+] Сумма шести первых элементов массива : " << vect_six << endl;
  }

  else
    cout << "[-] Длина массива меньше 6-ти" << endl;

  // Сумма элементов массива с k1-го по k2й
  int k1, k2;
  cout << "Введите k1 и k2 (границы подсчета суммы элементов) : ";
  cin >> k1 >> k2;

  if ((k1 > k2) && (k1 <= len) && (k2 <= len) && (k1 >= 0) && (k2 >= 0)) {
    for (int i = k2; i <= k1; ++i) {

      vect_ksix += vect_num.at(i);
    }
    cout << "[+] Сумма элементов массива от " << k2 << " до " << k1 << " : "
         << vect_ksix << endl;
  }

  else if ((k1 <= len) && (k2 <= len) && (k1 >= 0) && (k2 >= 0)) {
    for (int i = k1; i <= k2; ++i) {

      vect_ksix += vect_num.at(i);
    }
    cout << "[+] Сумма элементов массива от " << k1 << " до " << k2 << " : "
         << vect_ksix << endl;
  }

  else
    cout << "[-] Длина массива не попадает в диапазон" << endl;

  // Среднее арифметическое всех элементов массива
  cout << "[+] Среднее арифметическое всех элементов массива : "
       << vect_sum / len << endl;

  // Среднее арифметическое элементов массива с s1-го по s2-й
  int s1, s2;
  cout << "Введите s1 и s2 (границы подсчета суммы элементов) : ";
  cin >> s1 >> s2;

  if ((s1 > s2) && (s1 <= len) && (s2 <= len) && (s1 >= 0) && (s2 >= 0)) {
    for (int i = s2; i <= s1; ++i) {

      vect_saver += vect_num.at(i);
    }
    cout << "[+] Среднее арифметическое элементов массива от " << s2 << " до "
         << s1 << " : ";
    cout << vect_saver / (s1 - s2 + 1) << endl;
  }

  else if ((s1 <= len) && (s2 <= len) && (s1 >= 0) && (s2 >= 0)) {
    for (int i = s1; i <= s2; ++i) {

      vect_saver += vect_num.at(i);
    }
    cout << "[+] Среднее арифметическое элементов массива от " << s1 << " до "
         << s2 << " : ";
    cout << vect_saver / (s1 - s1 + 1) << endl;
  }

  else
    cout << "[-] Длина массива не попадает в диапазон" << endl;

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

    vnum = vect_num.at(i);
    vect_num.at(i) = vect_num[len - 3 + i];
    vect_num[len - 3 + i] = vnum;
  }

  cout << "Масиив с переставленными элементами равен : " << endl;

  for (size_t i = 0; i < len; ++i) {
    cout << vect_num.at(i) << " ";
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

    if (vect_num.at(i) % 2 == 0)
      even_num = i;

    else if ((vect_num.at(i) < 0) && (neg_num == -1))
      neg_num = i;
  }

  if (even_num != -1) {
    vect_num.erase(vect_num.begin() + even_num);

    if (neg_num > even_num)
      neg_num -= 1;
  }

  if (neg_num != -1) {
    vect_num.erase(vect_num.begin() + neg_num);
  }

  cout << "После обработки масиив равен : " << endl;

  len = vect_num.size();
  for (size_t i = 0; i < len; ++i) {
    cout << vect_num.at(i) << " ";
  }

  cout << endl;

  return;
}

// Дано название города. Определить, четно или нет количество символов в нем.
void num_4() {

  string city;

  cout << "Введите название города : ";
  cin >> city;

  size_t len = city.length();

  if (len % 2 == 0)
    cout << "В названии города четное кол-во символов : " << len;
  else
    cout << "В названии города нечетное кол-во символов : " << len;

  cout << endl;

  return;
}

// Даны две фамилии. Верните true, если первая длинее.
void num_5() {

  string sn_igor, sn_ksy;

  cout << "Введите фамилию Игоря : ";
  cin >> sn_igor;

  cout << "Введите фамилию Ксюши : ";
  cin >> sn_ksy;

  if (sn_igor.length() > sn_ksy.length())
    cout << "[+] Ответ : true" << endl;
  else
    cout << "[-] Ответ : false" << endl;

  return;
}

// Даны названия трех городов. Запишите в the_longest самое длинное, а самое
// короткое название в the_shortest.
void num_6() {

  string mas_sity[3];
  string word;

  cout << "Введите название 3-х городов через пробел : ";
  cin >> mas_sity[0] >> mas_sity[1] >> mas_sity[2];

  string the_longest = mas_sity[0], the_shortest = mas_sity[0];

  for (size_t i = 1; i < 3; ++i) {

    if (the_longest.length() < mas_sity[i].length()) {
      the_longest = mas_sity[i];

    }

    else if (the_shortest.length() > mas_sity[i].length()) {
      the_shortest = mas_sity[i];
    }
  }

  cout << "[+] Самое длинное название : " << the_longest << endl;
  cout << "[+] Самое короткое название : " << the_shortest << endl;

  return;
}

// Дано слово. Добавить к нему в начале и конце столько звездочек, сколько букв
// в этом слове.
void num_7() {

  string word;

  cout << "Введите слово : ";
  cin >> word;

  size_t len = word.length();

  for (size_t i = 0; i < len; ++i)
    word = "*" + word + "*";

  cout << "Слово, длиной " << len << " преобразовано : " << word << endl;

  return;
}

// Дано предложение. Определить долю (в %) букв 'a' в нем.
void num_8() {

  string sentence;
  long double count_a = 0, count_space = 0;

  cout << "Введите предложение : ";

  cin.ignore();
  getline(cin, sentence);

  long double len = sentence.length();

  for (size_t i = 0; i < len; ++i) {
    if (sentence[i] == 'a' || sentence[i] == 'A')
      count_a += 1;
    else if (sentence[i] == ' ')
      count_space += 1;
  }

  cout << "[+] Доля букв a в нем (с учетом пробелов): " << (count_a / len) * 100
       << " %" << endl;
  cout << "[+] Доля букв a в нем (без учета пробелов): "
       << (count_a / (len - count_space)) * 100 << " %" << endl;

  return;
}

// Дано предложение "Can you can a can as a canner can can a can?". Заменить все
// слова can на слово new_word.s
void num_9() {

  string sentence = "Can you can a can as a canner can can a can?";
  string new_word, letters, str_none = "";

  string words_can[] = {"Can", "can"};
  char symbols[] = {',', '.', ':', ';', '!', '?', ' '};

  cout << "Введите слово : ";
  cin >> new_word;

  bool flag = true;

  for (size_t i = 0; i < sentence.length() - 3; ++i) {

    letters = str_none + sentence[i] + sentence[i + 1] + sentence[i + 2] +
              sentence[i + 3];

    if (flag == true) {
      for (size_t j = 0; j < 2; ++j) {
        for (size_t k = 0; k < 7; ++k) {
          if (letters == (str_none + words_can[j] + symbols[k])) {
            cout << letters << " " << words_can[j] + symbols[k] << endl;

            flag = false;
            break;
          }
        }
        if (flag == false)
          break;
      }
    }

    flag = true;
  }

  return;
}

// Выбор номера
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

  case 5:
    num_5();
    return 0;

  case 6:
    num_6();
    return 0;

  case 7:
    num_7();
    return 0;

  case 8:
    num_8();
    return 0;

  case 9:
    num_9();
    return 0;

  default:
    cout << "Задачи, под номером " << task_num << " не существует" << endl;
    return 0;
  }

  return 0;
}
