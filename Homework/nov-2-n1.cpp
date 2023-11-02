/*
Лабораторная Работа "Калькулятор"
*/


#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class IntelliCalc {
    public:

    long double Counter(string);

    IntelliCalc();
    ~IntelliCalc();

    private:
    string math_extract;
};

long double IntelliCalc::Counter(string simple_math){

    size_t len = simple_math.length();
    vector<string> actions_math;

    // разбираем пример на числа "0123456789" и действия "+-*/^!"
    for (size_t i = 0; i < len; ++i) {
        
    }

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
