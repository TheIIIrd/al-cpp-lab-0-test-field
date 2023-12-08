#include <cmath>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

const double Pie = acos(-1); // число Пи
const double E = exp(1);     // число E

// Обработка выражений с унарными минусами после скобок
string UnaryMinus(string line) {
  int pos = 0, len = line.length() - 1;

  string zero = "0";
  string bracket_minus = "(-";

  for (int i = 0; i < len; ++i) {
    pos = i + 1;

    if (line[i] == bracket_minus[0] && line[pos] == bracket_minus[1]) {
      line.insert(pos, zero);
    }
  }

  return line;
}

struct Price {
  // тип данных num, +, -, *, /, ^
  char type;
  // само число или 0.0 если действие
  long double value;
};

bool Math(stack<Price> &stack_num, stack<Price> &stack_action, Price &item) {
  // num_one присваивается значение верхнего числа из стека с числами
  double num_one, num_two;
  num_one = stack_num.top().value;

  stack_num.pop(); // Удаляется верхнее число из стека с числами

  switch (stack_action.top().type) {

  case '+': {
    num_two = stack_num.top().value;
    stack_num.pop();

    item.type = '0';
    item.value = num_one + num_two;
    stack_num.push(item); // Результат операции кладется в стек с числами
    stack_action.pop();

    break;
  }

  case '-': {
    num_two = stack_num.top().value;
    stack_num.pop();

    item.type = '0';
    item.value = num_two - num_one;
    stack_num.push(item);
    stack_action.pop();

    break;
  }

  case '^': {
    num_two = stack_num.top().value;
    stack_num.pop();

    item.type = '0';
    item.value = pow(num_two, num_one);
    stack_num.push(item);
    stack_action.pop();

    break;
  }

  case '*': {
    num_two = stack_num.top().value;
    stack_num.pop();

    item.type = '0';
    item.value = num_one * num_two;
    stack_num.push(item);
    stack_action.pop();

    break;
  }

  case '/': {
    num_two = stack_num.top().value;
    if (num_one == 0) {
      cerr << "[-] err" << endl;

      return false;

    } else {
      stack_num.pop();

      item.type = '0';
      item.value = num_two / num_one;
      stack_num.push(item);
      stack_action.pop();

      break;
    }
  }

  default: {
    cerr << endl << "[-] err" << endl;

    return false;
    break;
  }
  }

  return true;
}

int getRang(char element) { // Приоритет операции
  if (element == '+' || element == '-')
    return 1;
  if (element == '*' || element == '/')
    return 2;
  if (element == '^')
    return 3;
  else
    return 0;
}

int main() {
  while (true) {

    cout << "[*] math : ";

    string str;
    getline(cin, str);
    str = UnaryMinus(str);
    stringstream expression{str};

    char element; // текущий символ
    double value;
    bool minus = true; // унарный минус в начале строки

    stack<Price> stack_num;    // Стек с числами
    stack<Price> stack_action; // Стек с операциями

    Price item;

    while (true) {
      element = expression.peek();
      if (element == '\377')
        break; // Восьмеричная Escape последовательность  - конец строки

      if (element == ' ') { // Игнорирование пробелов
        expression.ignore();

        continue;
      }

      if (element == 'p') { // число Пи
        item.type = '0';
        item.value = Pie;
        stack_num.push(item); // Число кладется в стек с числами
        minus = 0;
        expression.ignore();

        continue;
      }

      if (element == 'e') { // число E
        item.type = '0';
        item.value = E;
        stack_num.push(item);
        minus = 0;
        expression.ignore();

        continue;
      }

      if (element >= '0' && element <= '9' ||
          element == '-' && minus == 1) { // Прочитано число
        expression >> value;
        item.type = '0';
        item.value = value;
        stack_num.push(item);
        minus = 0;

        continue;
      }

      // Прочитана операция
      if (element == '+' || element == '-' && minus == 0 || element == '*' ||
          element == '/' || element == '^') {
        if (stack_action.size() == 0) { // Если стек с операциями пуст
          item.type = element;
          item.value = 0;
          stack_action.push(item); // Операция кладется в стек с операциями
          expression.ignore();

          continue;
        }

        // Если стек с операциями НЕ пуст, но приоритет текущей операции выше
        // верхней в стеке с операциями
        if (stack_action.size() != 0 &&
            getRang(element) > getRang(stack_action.top().type)) {
          item.type = element;
          item.value = 0;
          stack_action.push(item);
          expression.ignore();

          continue;
        }

        // Если стек с операциями НЕ пуст, и приоритет текущей операции ниже или
        // равен верхней в стеке с операциями
        if (stack_action.size() != 0 &&
            getRang(element) <= getRang(stack_action.top().type)) {
          if (Math(stack_num, stack_action, item) == false) {

            return 0;
          }
          continue;
        }
      }

      if (element == '(') { // Открывающаяся скобка
        item.type = element;
        item.value = 0;
        stack_action.push(item);
        expression.ignore();
        continue;
      }

      if (element == ')') { // закрывающаяся скобка
        while (stack_action.top().type != '(') {
          if (Math(stack_num, stack_action, item) == false) {

            return 0;
          } else
            continue;
        }
        stack_action.pop();
        expression.ignore();
        continue;
      } else { // введен посторонний символ
        cout << endl << "[-] wrong math" << endl;

        return 0;
      }
    }

    while (stack_action.size() != 0) {
      if (Math(stack_num, stack_action, item) == false) {

        return 0;
      } else
        continue;
    }

    std::cout << "[+] ans : " << stack_num.top().value << endl;
  }

  return 0;
}