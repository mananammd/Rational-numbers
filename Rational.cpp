#include "Rational.h"

namespace {
    //нок
    int gcd(int a, int b){
        return b ? gcd(b, a % b) : a;
    }
}

Rational::Rational() {
    numerator = 1;
    denumerator = 1;
    nan = false;
}

Rational::Rational(int x, int y) {
    if (y == 0) {
        nan = true;
    }
    else {
        nan = false;
    }
    numerator = x;
    denumerator = y;
    reduce();
}

Rational::Rational(int x) {
    numerator = x;
    denumerator = 1;
    nan = false;
}

Rational Rational::reduce() {
    int nod = gcd(std::abs(numerator), denumerator);
    if (nod != 0) {
        numerator /= nod;
        denumerator /= nod;
    }
    return *this;
}


Rational Rational::neg() {
     return Rational(-1 * numerator, denumerator);
}

Rational Rational:: inv() {
    return Rational(denumerator, numerator);
}


Rational Rational::sum(Rational r) {
    int newNumerator = ((numerator * r.denumerator) + 
         (r.numerator * denumerator));

    int newDenumerator = denumerator * r.denumerator;

    return Rational(newNumerator, newDenumerator);
}

Rational Rational::sub(Rational r) {
    int newNumerator = ((numerator * r.denumerator) - 
         (r.numerator * denumerator));

    int newDenumerator = denumerator * r.denumerator;

    return Rational(newNumerator, newDenumerator);
}

Rational Rational::mul(Rational r) {
    return Rational (
        numerator * r.numerator,
        denumerator * r.denumerator
    );
}

Rational Rational::div(Rational r) {
    return Rational (
        numerator * r.denumerator,
        denumerator * r.numerator
    );
}

bool Rational::eq(Rational r) {
    r.reduce();
    reduce();
    return ( 
        (numerator == r.numerator)
        &&
        (denumerator == r.denumerator));
}

bool Rational::neq(Rational r) {
    return !eq(r);
}

bool Rational::l(Rational r) {
    return (
        (numerator * r.denumerator) 
        <
        (denumerator * r.numerator)
    );
}

bool Rational::leq(Rational r) {
    return (l(r)) || (eq(r));
}

bool Rational::g(Rational r) {
    return !(l(r)) && (neq(r));
}

bool Rational::geq(Rational r) {
    return !(l(r));
}

void Rational::print(std::ostream& out) {
    reduce();
    if (nan == false) {
        out 
        << numerator
        << "/"
        << denumerator
        << std::endl;  
    } 
    else {
        out
        << nan
        << std::endl;
    }
}

void Rational::scan(std::istream& in) {
    std::cin
        >> numerator
        >> denumerator;
        
}

Rational Rational::operator+(Rational a) {
    return sum(a);
}

Rational Rational::operator-(Rational a) {
    return sub(a);
}

Rational Rational::operator*(Rational a) {
    return mul(a);
}

Rational Rational::operator/(Rational a) {
    return div(a);
}


bool Rational::operator==(Rational a) {
    return eq(a);
}

bool Rational::operator!=(Rational a) {
    return !eq(a);
}

bool Rational::operator<(Rational a) {
    return l(a);
}

bool Rational::operator<=(Rational a) {
    return leq(a);
}

bool Rational::operator>(Rational a) {
    return g(a);
}

bool Rational::operator>=(Rational a) {
    return geq(a);
}


std::ostream& operator<<(std::ostream& out, Rational& n) {
    n.reduce();
    n.print(out);
    return out;
}

std::istream& operator>> (std::istream& in, Rational& n) {
    n.scan(in);
    return in;
}

