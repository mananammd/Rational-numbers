#include <iostream>
// Дробь x/y


class Rational {
private:
    
    bool nan; //деление на 0
    int numerator; //числитель
    int denumerator; //знаменатель
    

    Rational sum(Rational);
    Rational sub(Rational);
    Rational mul(Rational);
    Rational div(Rational);

    bool eq(Rational);   // ==
    bool neq(Rational);  // !=
    bool l(Rational);    // < less than
    bool leq(Rational);  // <= less or equal than
    bool g(Rational);    // > greater than
    bool geq(Rational);  // >= greater or equal than

public:
    
    Rational();
    Rational(int, int);
    Rational(int);
    
    Rational reduce();   // Сокращение

    Rational neg();      // *-1
    Rational inv();      // ^-1


    // Вывести на экран
    void print(std::ostream& out);
    // Считать с клавиатуры
    void scan(std::istream& in);


    Rational operator+(Rational a);
    Rational operator-(Rational a);
    Rational operator*(Rational a);
    Rational operator/(Rational a);


    bool operator==(Rational a);
    bool operator!=(Rational a);
    bool operator<(Rational a);
    bool operator<=(Rational a);
    bool operator>(Rational a);
    bool operator>=(Rational a);
    
    friend std::ostream& operator<<(std::ostream& out, Rational& n);
    friend std::istream& operator>>(std::istream& in, Rational& n);

};