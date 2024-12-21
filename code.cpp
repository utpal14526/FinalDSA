
#include <bits/stdc++.h>
using namespace std;

class Complex
{

public:
    int a, b;

    Complex(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    Complex() : a(0), b(0)
    {
    }

    Complex operator+(Complex &b)
    {
        Complex t;
        t.a = this->a + b.a;
        t.b = this->b + b.b;

        return t;
    }
};

int main(void)
{

    Complex c1(2, 3);
    Complex c2(3, 4);

    Complex c3;

    c3 = c1 + c2;

    cout << c3.a << " " << c3.b << endl;
}
