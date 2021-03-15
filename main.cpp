#include "Rational.h"

int main() {
    std::cout << "Data :" << std::endl;
    Rational x; // 1/1
    std::cout << "x = ";
    x.print(std::cout);
    Rational y(14, 5); // 14/5
    std::cout << "y = ";
    y.print(std::cout);
    Rational z(7);
    std::cout << "z = ";
    z.print(std::cout);

    std::cout << std::endl << "Operation:" << std::endl;

    std::cout << "x + y = ";
    (x + y).print(std::cout);
    std::cout << "z - y = ";
    (z - y).print(std::cout);
    std::cout << "y * z = ";
    (y * z).print(std::cout);
    std::cout << "y : z = ";
    (y / z).print(std::cout);

    std::cout << std::endl << "Compare: " << std::endl;

    bool eq = x == y;
    std::cout << "x == y ? " << eq << std::endl;
    bool neq = x != y;
    std::cout << "x != y ? " << neq << std::endl;
    bool l = x < y;
    std::cout << "x < y ? " << l << std::endl;
    bool leq = x <= y;
    std::cout << "x <= y ? " << leq << std::endl;
    bool g = x > y;
    std::cout << "x > y ? " << g << std::endl;
    bool geq = x >= y;
    std::cout << "x >= y ? " << geq << std::endl;


    Rational n(10, 5);
    std::cout << "10/5 =  ";
    Rational b = n.reduce();
    b.print(std::cout);
    
}