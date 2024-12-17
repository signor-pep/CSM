#ifndef _PVECTOR_
#define _PVECTOR_
 
#include<initializer_list> // inizializzazione vettori
#include<iostream> // input/output
#include<cmath>
#include<string> // strings
#include "./randnumgen.hpp"

// wrap class to avoid narrowing errors of C++ when using curly brace initialization
template <typename dstntype>
class wrapt 
{
  dstntype wt;
public:

  template <typename srcntype>
  wrapt(const srcntype t)
    {
      wt = dstntype(t);
    }

  operator dstntype() const
    {
      return wt;
    }
};
 
template <typename ntype, int NT>
class pvector
{
  ntype v[NT]; // private member
public:
  pvector() // void constructor
    {
      int i;
      for(i=0; i < NT; i++)
        {
          v[i]=0;
        }
    }

  // overloading of constructor for handling curly brace initialization
  // NOTE: wrapt avoids narrowing errors, i.e. without "wrapping" if you declare a pvector<double>
  // and you initialize it as follows:
  // int a=2;
  // pvector<double,3> V={a,a,a};
  // you will get errors since you can not narrow the value of a int variable to a double.
  // By "wrapping" the elements with wrapt class, integral types will be automatically casted to ntype 
  pvector(std::initializer_list<wrapt<ntype>> list)  // overloading constructor
    {
      int c=0;
      for (ntype el: list) {
          if (c < NT){
              v[c] = el;
            }
          c++;
        }
      for (;c < NT; c++){
          v[c]=0.0;
        }
    }


  ~pvector() // destructor
    {
    }

  // Note this method does not change data of object hence it is declared "const"
  void show(std::string s="") const // argomento di default 
    {
      std::cout << s << "(";
      for (int i=0; i < NT; i++)
        {
          std::cout << v[i];
          if (i < NT-1) 
            std::cout << ",";
        }
      std::cout << ")\n";
    }

  // get
  // Note this method does not change data of object hence it is declared "const"
  ntype get(int i) const
    {
      return v[i];
    }

  // set
  ntype set(int i, ntype val) 
    {
      return v[i]=val;
      // equivalently: 
      // return (*this).v[i]=val;
    }

  // since assign operator returns pvector objects by reference:
  // (A=B).set(0,2.3); it set element 0 o A to 2.3
  // Note this method changes data of object hence it is *not* declared "const"
  pvector& operator=(const pvector& v2)
    {
      for (int i=0; i < NT; i++)
        {
          (*this).v[i] = v2.v[i];
        }
      return(*this);
    }

  // operator+: (*this)+v2
  // Note this method does not change data of object hence it is declared "const"
  pvector operator+(const pvector& v2) const
    {
      pvector vs;
      for (int i=0; i < NT; i++)
        {
          vs.v[i] = v[i] + v2.v[i];          
        }
      return vs;
    } 

  // sum based on overloaded + operator (example of usage of (*this)) 
  // A.sum(B) questo è equivalente a scrivere A+B
  // Note this method does not change data of object hence it is declared "const"
  pvector sum(const pvector& v2) const
    {
      return (*this)+v2;
    }

  pvector& operator+=(const pvector& v2)
    {
      for (int i=0; i < NT; i++)
        {
          v[i] += v2.v[i];
        }
      return (*this);
    }


  // operator-
  // Note this method does not change data of object hence it is declared "const"
  pvector operator-(const pvector& v2) const
    {
      pvector vs;
      for (int i=0; i < NT; i++)
        {
          vs.v[i] = v[i] - v2.v[i];
        }
      return vs;
    } 
  
  pvector& operator-=(const pvector& v2)
    {
      for (int i=0; i < NT; i++)
        {
          v[i] -= v2.v[i];
        }
      return (*this);
    }


  // This is needed to access elements of const vector objects
  // this is like having following arguments: operator()(const pvector *this, int i) 
  // where (implicit) first argument is the "calling" object
  ntype operator()(int idx) const
    {
      return v[idx]; 
    }
  // this is like having following arguments: operator()(pvector *this, int i) 
  // where first (implicit) argument is the "calling" object
  // pvector A;
  // double val;
  // A(1)=val;
  ntype& operator()(int idx)
    {
      return v[idx]; 
    }

  // prodotto scalare
  ntype operator*(const pvector& vec) const
    {
      ntype sp=0;
      for (int i=0; i < NT; i++)
        sp += v[i]*vec.v[i];
      return sp;
    }

  // is_integral() restituisce "true" se il tipo forniti come argomento è un tipo intero (i.e. int, long int, char, ecc),
  // mentre conditional restituisce il primo tipo se la condizione è vera, altrimenti il secondo.
  // In questo modo se ho un pvector di interi norm() restituisce un double
  // (vedi anche materiale classroom "Metaprogramming: norm() per vettori di interi")
  typename std::conditional<std::is_integral<ntype>::value==true, double, ntype>::type
  norm(void) const
    {
      return sqrt((*this)*(*this));
    }
    
  // vector times scalar 
  pvector operator*(ntype s) const
    {
      pvector vt;  // note that inside the class is possible to use private member of objects belonging to the class (such as vt in this case)
      for (int i=0; i < NT; i++)
        vt.v[i] = v[i]*s;
      return vt;
    }

  // scalar time vector 
  friend pvector operator*(ntype s, const pvector& vec)
    {
      pvector vt;
      for (int i=0; i < NT; i++)
        {
          vt.v[i] = s*vec.v[i];
        }
      return vt;
    }

  // vector divided by scalar 
  pvector operator/(ntype s) const
    {
      pvector vt;
      for (int i=0; i < NT; i++)
        vt.v[i] = v[i]/s;
      return vt;
    }

  // multiply by scalar and assign result to vector
  pvector& operator *=(ntype s)
    {
      for (int i=0; i < NT; i++)
        v[i] *= s;
      return (*this);
    }

  // divide by scalar and assign result to vector
  pvector& operator /=(ntype s)
    {
      for (int i=0; i < NT; i++)
        v[i] /= s;
      return (*this);
    }
  // operatore confronto
  bool operator==(pvector vec)
    {
      for (int i=0; i < NT; i++)
        {
          if (v[i] != vec.v[i])
            return 0;
        }
      return 1;
    }

 //operatore prodotto vettoriale
  pvector operator^(const pvector& vec) const
    {
      if (NT==3)
        {
          pvector vt;
          vt.v[0] = v[1]*vec.v[2]-v[2]*vec.v[1];
          vt.v[1] = v[2]*vec.v[0]-v[0]*vec.v[2];
          vt.v[2] = v[0]*vec.v[1]-v[1]*vec.v[0];
          return vt;
        }
      else
        {
          std::cout << "Cross product not defined\n";
          exit(1);
        }
    }

  

  // rint() method
  // pvector<double,3> A, B={1.1,2.2,3.3};
  // A = rint(B);
  pvector rint()
    {
      pvector vt;
      for (auto i=0; i < NT; i++)
        {
          vt.v[i] = rint(v[i]);
        }
      return vt;
    }
  
//Stampa su terminale usando la sintassi std:: cout << .... 

#if 1
  friend std::ostream& operator<<(std::ostream& os, const pvector& vec)
    {
      os << "(";
      for (int i=0; i < NT; i++)
        {
          os << vec.v[i];
          if (i < NT-1)
           os << ","; 
        }
      os << ")";
      return os;
    }
#endif

  // component-wise multiplication of two vectors
  // pvector A, B, C; 
  // C = A.mulcw(B); 
  // is equivalent to
  // C(i) = A(i)*B(i) i=0....NT-1
  pvector mulcw(const pvector& vec)
    {
      pvector vt;
      for (int i=0; i < NT; i++)
        {
          vt(i) = v[i]*vec(i);
        }
      return vt;
    }
 
  // component-wise division of two vectors
  // pvector A, B, C; 
  // C = A.divcw(B);
  // is equivalent to
  // C(i) = A(i)/B(i) i=0....NT-1
  pvector divcw(const pvector& vec)
    {
      pvector vt;
      for (int i=0; i < NT; i++)
        {
          vt(i) = v[i]/vec(i);
        }
      return vt;
    }

  // random(L) genera un vettore con componenti comprese tra [-L/2 , L/2]
  pvector& random(const ntype& L)
    {
      for (int i=0; i < NT; i++)
        {
          v[i] = (rng.ranf()-0.5)*L; // assign a random value in [-L/2,L/2]
        }
      return (*this);
    }
//NON UTILE PER IL PROGETTO
  void random_orient(void)
    {
      ntype rS, S, V1, V2;
      if (NT==3)
        {
          do
            {
              V1 = 2.0*rng.ranf()-1.0;
              V2 = 2.0*rng.ranf()-1.0;
              S = V1*V1+V2*V2;
            }
          while (S >= 1.0);
          rS = sqrt(1.0-S);
#if 0
          v[0] = 2.0*rS*V1;
          v[1] = 2.0*rS*V2;
          v[2] = 1.0-2.0*S;
#else
          (*this) = {2.0*rS*V1, 2.0*rS*V2, 1.0-2.0*S};
#endif

        }
      else
        {
          std::cout << "[random_orient] Only 3D vectors are supported\n";
        }
    }


};

// since pvector is a generic class (class template), 
// we make rint() also generic (function template)
// pvector v1, v2:
// v1 = rint(v2); <---
template<typename ntype, int NT>
pvector<ntype,NT> rint(const pvector<ntype,NT>& vec)
{
  pvector<ntype,NT> vt;

  for (int i=0; i < NT; i++)
    {
      vt(i) = rint(vec(i));
    }
  return vt;
}
#if 0
template<typename ntype, int NT>
std::ostream& operator<<(std::ostream& os, const pvector<ntype,NT>& vec)
    {
      os << "(";
      for (int i=0; i < NT; i++)
        {
          os << vec(i);
          if (i < NT-1)
           os << ","; 
        }
      os << ")";
      return os;
    }
 
#endif
#if 0
// non friend implementation of scalar time vector
// scalar time vector 
template<typename ntype, int NT>
pvector<ntype,NT> operator*(ntype s, const pvector<ntype, NT>& vec)
{
  pvector<ntype,NT> vt;
  for (int i=0; i < NT; i++)
    {
      vt(i) = s*vec(i);
    }
  return vt;
}
#endif

// predefined 3d vector of doubles
using pvec3d=pvector<double,3>;
#endif
