/*
Лабораторная Работа "Калькулятор"
*/


#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


class IntelliCalc {
    public:

    string BracketCrusher(string);
    long double MathWhiz(long double, char, long double);
    long double Counter(string);

    IntelliCalc();
    ~IntelliCalc();

    private:
    string math_extract;
};

// ищем скобки
string IntelliCalc::BracketCrusher(string math_extract) {

    // magic

    return "";
}

// считаем
long double IntelliCalc::MathWhiz(long double first_num, char action, long double second_num) {

    // magic

    return 0;
}

// выставляем приоритеты
long double IntelliCalc::Counter(string simple_math) {

    // magic

    return 0;
}

IntelliCalc::IntelliCalc() {}

IntelliCalc::~IntelliCalc() {}


int main() {

    string math_extract;

    cout << "[пример] : ";
    cin >> math_extract;

    return 0;
}
