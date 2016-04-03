#include "fraction.h"
#include "algebra.h"

chipmunk::Fraction::Fraction(int num, int denom)
{
    numerator = num;
    denominator = denom;
}

chipmunk::Fraction chipmunk::Fraction::add(chipmunk::Fraction other)
{
    int common = lcm(denominator, other.getDenom());
    int f1 = common / denominator;
    numerator *= f1;
    denominator *= f1;
    int f2 = common / other.getDenom();
    other.numerator *= f2;
    other.denominator *= f2;
    int n = numerator + other.getNum();
    simplify();
    other.simplify();
    chipmunk::Fraction frac(n, denominator);
    frac.simplify();
    return frac;
}

chipmunk::Fraction chipmunk::Fraction::sub(chipmunk::Fraction other)
{
    int common = lcm(denominator, other.getDenom());
    int f1 = common / denominator;
    numerator *= f1;
    denominator *= f1;
    int f2 = common / other.getDenom();
    other.numerator *= f2;
    other.denominator *= f2;
    int n = numerator - other.getNum();
    simplify();
    other.simplify();
    chipmunk::Fraction frac(n, denominator);
    frac.simplify();
    return frac;
}

chipmunk::Fraction chipmunk::Fraction::mult(chipmunk::Fraction other)
{
    int n = numerator * other.numerator;
    int d = denominator * other.denominator;
    chipmunk::Fraction frac(n, d);
    frac.simplify();
    return frac;
}

chipmunk::Fraction chipmunk::Fraction::div(chipmunk::Fraction other)
{
    int n = numerator * other.denominator;
    int d = denominator * other.numerator;
    chipmunk::Fraction frac(n, d);
    frac.simplify();
    return frac;
}

void chipmunk::Fraction::simplify()
{
    int common = chipmunk::gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;
}

double chipmunk::Fraction::getValue()
{
    double val = numerator / denominator;
    return val;
}

int chipmunk::Fraction::getNum()
{
return numerator;
}

int chipmunk::Fraction::getDenom()
{
return denominator;
}
