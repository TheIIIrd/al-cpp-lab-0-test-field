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
