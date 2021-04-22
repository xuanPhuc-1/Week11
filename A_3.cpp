#include<iostream>
using namespace std;
class Fraction
{
public:
    int numerator;
    int denominator;


    int rut_gon(int a, int b) {

        if (a == 0 || b == 0) {
            return a + b;
        }
        while (a != b) {
            if (a > b) {
                a -= b;
            }
            else {
                b -= a;
            }
        }
        return a;
    }
    
	int quy_dong(int a, int b)
    {
        return ((a * b) / rut_gon(a, b));
    }
    
	void print(int a)
    {
        cout << this->numerator / a << "/" << this->denominator / a << endl;
    }
    
	// tu1 = a, tu2 = b, mau1 = c, mau2 = d
    void multiplication(int a, int b, int c, int d)
    {
        cout << (a * b) / rut_gon(a * b, c * d) << "/" << (c * d) / rut_gon(a * b, c * d);
    }
    
	void divine(int a, int b, int c, int d)
    {
        cout << (a * d) / rut_gon(a * d, b * c) << "/" << (b * c) / rut_gon(a * d, b * c);
    }
    
	void subtract(int a, int b, int c, int d) 
    {
        cout << a * quy_dong(c, d) / c - b * quy_dong( c, d) / d << "/" << quy_dong(c, d);  
    }
    
	void plus(int a, int b, int c, int d) 
    {
        cout << a * quy_dong(c, d) / c + b * quy_dong(c, d) / d << "/" << quy_dong(c, d);   
    }
};

int main() {
    char c;
    Fraction fraction1 = { 3, 2 };
    Fraction fraction2 = { 5, 9 };
    if (fraction1.denominator == 0)
    {
        cout << "Gia tri khoi tao khong dung" << endl;
        return 0;
    }
    if (fraction2.denominator == 0)
    {
        cout << "Gia tri khoi tao khong dung" << endl;
        return 0;
    }
    fraction1.print(fraction1.rut_gon(fraction1.numerator, fraction1.denominator));
    fraction2.print(fraction2.rut_gon(fraction2.numerator, fraction2.denominator));
    int tu1, tu2, mau1, mau2;
    tu1 = fraction1.numerator / fraction1.rut_gon(fraction1.numerator, fraction1.denominator);
    tu2 = fraction2.numerator / fraction2.rut_gon(fraction2.numerator, fraction2.denominator);
    mau1 = fraction1.denominator / fraction1.rut_gon(fraction1.numerator, fraction1.denominator);
    mau2 = fraction2.denominator / fraction2.rut_gon(fraction2.numerator, fraction2.denominator);
    cout << "Nhap dau phep tinh: ";
    cin >> c;
    switch (c)
    {
    case '*':
        cout << "Ket qua la: ";
        fraction1.multiplication(fraction1.numerator, fraction2.numerator, fraction1.denominator, fraction2.denominator);
        break;
    case '/':
        cout << "Ket qua la: ";
        fraction1.divine(fraction1.numerator, fraction2.numerator, fraction1.denominator, fraction2.denominator);
        break;
    case '+':
        cout << "Ket qua la: ";
        fraction1.plus(tu1, tu2, mau1, mau2);
        break;
    case '-':
        cout << "Ket qua la: ";
        fraction1.subtract(tu1, tu2, mau1, mau2);
        break;
    default:
        cout << "Phep tinh khong hop le vui long nhap lai!";
        break;
    }
    return 0;
}