#include <iostream>
#include <sstream>

using namespace std;

struct complex_t {
    float real;
    float imag;
};

complex_t add(complex_t lhs, complex_t rhs) {
    complex_t res;
    res.real = lhs.real + rhs.real;
    res.imag = lhs.imag + rhs.imag;
    return res;
}

complex_t sub(complex_t lhs, complex_t rhs) {
    complex_t res;
    res.real = lhs.real - rhs.real;
    res.imag = lhs.imag - rhs.imag;
    return res;
}

complex_t mul(complex_t lhs, complex_t rhs) {
    complex_t res;
    //res= ((lhs.real * rhs.real) - (lhs.imag * rhs.imag)+(lhs.imag * rhs.real) + (lhs.real * rhs.imag));
    res.real = ((lhs.real * rhs.real) - (lhs.imag * rhs.imag));
    res.imag = ((lhs.imag * rhs.real) + (lhs.real * rhs.imag));
    return res;
}

complex_t div(complex_t lhs, complex_t rhs) {
    complex_t res;
    res.real = ((lhs.real * rhs.real) + (lhs.imag * rhs.imag)) / ((rhs.real * rhs.real) + (rhs.imag * rhs.imag));
    res.imag = ((lhs.imag * rhs.real) - (lhs.real * rhs.imag)) / ((rhs.real * rhs.real) + (rhs.imag * rhs.imag));
    return res;
}

istream & read( istream & stream, complex_t & complex ) {

    char symbol;
    float real, imag;

    if (stream >> symbol && symbol == '(' &&
        stream >> real &&
        stream >> symbol && symbol == ',' &&
        stream >> imag &&
        stream >> symbol && symbol == ')') {

        complex.real = real;
        complex.imag = imag;

    }
    else {
        stream.setstate(std::ios::failbit);
        if(_S_failbit){
            cout<< "error";
        }
    }
}

ostream & write( ostream & stream, complex_t complex ) {

    cout << "(" << complex.real << "," << " " << complex.imag << ")";
}

int main() {
    complex_t a, b;
    string s;
    char op;

    getline(cin, s);
    istringstream stream(s);
    read(stream, a);
    stream >> op;
    read(stream, b);
    switch (op) {
            case '+':
                write(cout,add(a,b));
            case '-':
                write(cout,sub(a,b));
            case '*':
                write(cout,mul(a,b));
            case '/':
                write(cout,div(a,b));
        }


    return 0;
}
