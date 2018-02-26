#include <iostream>
#include <sstream>
using namespace std;

struct complex_t {
	
	complex_t() { real = 0.0f; imag = 0.0f;}

	complex_t add(complex_t other) const {
		complex_t res;
		res.real = real + other.real;
		res.imag = imag + other.imag;
		return res;
	}
	
	complex_t sub(complex_t other) const {
		complex_t res;
		res.real = real - other.real;
		res.imag = imag - other.imag;
		return res;
	}
	complex_t mul(complex_t other) const {
		complex_t res;
		res.real = real*other.real - imag*other.imag;
		res.imag = real*other.imag + other.real*imag;
		return res;
	}
	complex_t div(complex_t other) const {
		complex_t res;
		res.real = (real*other.real + imag*other.imag) / (other.real*other.real + other.imag*other.imag);
		res.imag = (imag*other.real - real*other.imag) / (other.real*other.real + other.imag*other.imag);
		return res;
	}

	istream & read(istream & stream) {
		char op1, op2, op3;
		float real, imag;
		if (stream >> op1 && op1 == '(' && stream >> real && stream >> op2 && op2 == ',' 
		    && stream >> imag && stream >> op3 && op3 == ')') {
			this->real = real;
			this->imag = imag;
		}
		else {
			stream.setstate(std::ios::failbit);
		}
		return stream;
	}
	ostream & write(ostream & stream) {
		return stream << '(' << real << ',' << imag << ')' << endl;
	}

	float real;
	float imag;
};


int main() {

	complex_t a,b,res;
	char op;

	if (a.read(cin) && (cin >> op) && b.read(cin)) {

		switch (op) {
		case '+':
			res  = a.add(b);
			res.write(cout);
			break;
		case '-':
			res = a.sub(b);
			res.write(cout);
			break;
		case '*':
			res =  a.mul(b);
			res.write(cout);
			break;
		case '/':
			res = a.div(b);
			res.write(cout);
			break;
		default:
			cout << '\n' << "An error has occured while reading input data";
			break;
		}
	}
	else {
		cout << endl << "An error has occured while reading input data";
	}

	return 0;
}
