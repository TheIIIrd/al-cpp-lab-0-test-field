/*
Лабораторная Работа "Калькулятор"
*/


#include <cstddef>
#include <iostream>
#include <stack>

using namespace std;


class IntelliCalc {
    public:
    
        long double CounIt();

        IntelliCalc();
        ~IntelliCalc();

    private:
        struct Price {
            // тип данных num, +, -, *, /, ^
            char type;
            // само число или 0.0 если действие
            long double value;
        };

        stack<Price> stack_num;
        stack<Price> stack_action;
        Price item;

        int PriorityProtocol(char);
        bool MathWhiz();
};


// получение приоритета
int IntelliCalc::PriorityProtocol(char action) {

    if (action == '+' || action == '-') return 0;
    else if (action == '*' || action == '/') return 1;

    return -1;
}


// основная функция для подсчета значений
bool IntelliCalc::MathWhiz() {

    // определяем пару чисел
    long double num_one, num_two;
    Price item;

    // получение 1-го числа
    num_one = stack_num.top().value;
    stack_num.pop();

    // выбор операции
    switch (stack_action.top().type) {

        case '+' : {

            // получение 2-го числа
            num_two = stack_num.top().value;

            item.type = 'n';
            item.value = num_one + num_two;

            // замена чисел операции на ответ
            stack_num.pop();
            stack_num.push(item);

            stack_action.pop();
            break;
        }

        case '-' : {

            // получение 2-го числа
            num_two = stack_num.top().value;

            item.type = 'n';
            item.value = num_two - num_one;

            // замена чисел операции на ответ
            stack_num.pop();
            stack_num.push(item);

            stack_action.pop();
            break;
        }

        case '*' : {

            // получение 2-го числа
            num_two = stack_num.top().value;

            item.type = 'n';
            item.value = num_one * num_two;

            // замена чисел операции на ответ
            stack_num.pop();
            stack_num.push(item);

            stack_action.pop();
            break;
        }

        case '/' : {

            // получение 2-го числа
            num_two = stack_num.top().value;

            item.type = 'n';
            item.value = num_two / num_one;

            // замена чисел операции на ответ
            stack_num.pop();
            stack_num.push(item);

            stack_action.pop();
            break;
        }

        // вывод ошибки, если ничего не подходит
        default: return false;
    }

    return true;
}


// обработка строки
long double IntelliCalc::CounIt() {
    // переменная для анализа введенной строки
    char commod;

    do {

        // просматриваем первый элемент введенной строки
        commod = cin.peek();

        // если цифра
        if (commod >= '0' && commod <= '9') {

            // забираем число целиком
            cin >> item.value;
            // n - num
            item.type = 'n';

            // складываем в стек с числами
            stack_num.push(item);
            
            continue;
        }

        // если операция
        else if (commod == '+' || commod == '-' || commod == '*' || commod == '/') {

            if (stack_action.size() == 0) {
                
                // забираем тип операции
                item.type = commod;
                // 0.0 т.к. это не число
                item.value = 0.0;
                
                // складываем в стек с операциями
                stack_action.push(item);
                cin.ignore();

            }

            else {

                if (PriorityProtocol(commod) > PriorityProtocol(stack_action.top().type)) {
                    
                    // забираем тип операции
                    item.type = commod;
                    // 0.0 т.к. это не число
                    item.value = 0.0;
                    
                    // складываем в стек с операциями
                    stack_action.push(item);
                    cin.ignore();

                }
                
                else if (MathWhiz() == false) {

                    cerr << endl << "Err" << endl;
                    return 0;

                }
                
                continue;
            }

            continue;
        }
    }

    // пока не получим в строке Enter
    while (commod != '\n');

    while (stack_action.size() != 0) {

        // если основная функция для подсчета значений отработала без ошибок
        if (MathWhiz()) continue;

        // если произошла ошибка
        else {

            cerr << endl << "Err" << endl;
            return 0;

        }
    }

    return stack_num.top().value;
}


IntelliCalc::IntelliCalc() {}

IntelliCalc::~IntelliCalc() {}


int main() {

    // magic
    cout << IntelliCalc().CounIt() << endl;

    return 0;
}
