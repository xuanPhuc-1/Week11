#include<iostream>
using namespace std;
class Fraction
{
public:
		const int numerator;
		const int denominator;
		
        int convert(int a, int b) {
        
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

		void print(int a)
		{
            cout << this->numerator / a << "/" << this->denominator / a;
		}
};

int main() {
	Fraction fraction1 = { 6, 8 };
	fraction1.print(fraction1.convert(fraction1.numerator, fraction1.denominator));
	return 0;
}