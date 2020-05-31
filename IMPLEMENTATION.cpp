#include <iostream>
#include "rational.hpp"

// Default (zero-argument) constructor
Rational::Rational()
{
    numer = denom = 0;
}

// Two argument constructor
Rational::Rational(int num, int den)
{
   denom= den;
   numer= num;
}

void Rational::setNumerator(int num)
{
    numer = num;
}

int Rational::getNumerator()
{
    return numer;
}

void Rational::setDenominator(int den)
{
    denom=den;
}

int Rational::getDenominator()
{
    return denom;
}

void Rational::print()
{
   std::cout << (numer/denom);
}


Rational Rational::add(Rational rhs)
{
    Rational result;
    if(rhs.denom%denom==0){
        int kat=rhs.denom/denom;
        result.numer= kat*numer+rhs.numer;
        result.denom=rhs.denom;
        
    }
    else if(denom%rhs.denom==0){
        int kat=denom/rhs.denom;
        result.numer= kat*rhs.numer+numer;
        result.denom=denom;
        
    }
    else{
       result.numer= denom*rhs.numer+rhs.denom*numer;
       result.denom=denom*rhs.denom;
    }
   
   result.simplify();
   return result;
}


Rational Rational::multiply(Rational rhs)
{
   Rational result;
   result.numer=rhs.numer*numer;
   result.denom=denom*rhs.denom;
   return result;
}

void Rational::simplify()
{
    for(int i=1; i<=denom; i++){
        if(numer%i==0 && denom%i==0){
            numer/=i;
            denom/=i;
        }
    }
    
}

int Rational::gcd(int a, int b)
{
    int c;

    if(a<0)
        a = a * -1;
    if(b<0)
        b = b * -1;
  while (a != 0)
    {
        c = a;
        a = b % a;
        b = c;
    }

    return b;
}
