#include <iostream>

#define ADD(FIRST, SECOND) \
  Operation<'+', Integer<FIRST >, Integer<SECOND > >


#define SUB(FIRST, SECOND) \
  Operation<'-', Integer<FIRST >, Integer<SECOND > >

#define MUL(FIRST, SECOND) \
  Operation<'*', Integer<FIRST >, Integer<SECOND > >

#define DIV(FIRST, SECOND) \
  Operation<'/', Integer<FIRST >, Integer<SECOND > >

#define INT(FIRST) \
  FIRST//  Operation<0, Integer<0>, Integer<FIRST> >

#define FACT(FIRST) \
  fact<Integer<FIRST >::value>

#define FIBO(FIRST) \
  fibo<Integer<FIRST >::value>

#define VAL(FIRST) \
  FIRST::value

#define GET0(val) val::value
#define GET1(val) GET0(val::next)
#define GET2(val) GET1(val::next)
#define GET3(val) GET2(val::next)
#define GET4(val) GET3(val::next)
#define GET5(val) GET4(val::next)

#define CREATE1(val) IntList<Integer<val>, Integer<0> >
#define CREATE2(val1, val2) IntList<Integer<val1>, CREATE1(val2) >
#define CREATE3(val1, val2, val3) IntList<Integer<val1>, CREATE2(val2, val3) >
#define CREATE4(val1, val2, val3, val4) IntList<Integer<val1>, CREATE3(val2, val3, val4) >




template <bool i, int a, int b>
struct static_if
{
    static const int value = a;
};

template <int a, int b>
struct static_if<false, a, b>
{
    static const int value = b;
};



template<int x, int n>
struct pow
{
    static const int value = x * pow<x, n-1>::value;
};


// template<int x, int n>
// struct fast_pow
// {
//     static const int value =

template<int x>
struct pow<x, 1>
{
    static const int value = x;
};


template <int n>
struct fact
{
    static const int value = n * fact<n-1>::value;
};

template <>
struct fact<0>
{
    static const int value = 1;
};

template <int n>
struct fibo
{
    static const int value = fibo<n -1>::value + fibo<n - 2>::value;
};


template <>
struct fibo<1>
{
    static const int value = 1;
};
template <>
struct fibo<0>
{
    static const int value = 1;
};


template <char op, typename x, typename y>
struct Operation
{
    static const int value = 0;
};


template <typename x, typename y>
struct Operation<'+', x, y>
{
    static const int value = x::value + y::value;
};


template <typename x, typename y>
struct Operation<'^', x, y>
{
    static const int value = pow<x::value, y::value>::value;
};


template <typename x, typename y>
struct Operation<'-', x, y>
{
    static const int value = x::value - y::value;
};


template <typename x, typename y>
struct Operation<'*', x, y>
{
    static const int value = x::value * y::value;
};


template <typename x, typename y>
struct Operation<'/', x, y>
{
    static const int value = x::value / y::value;
};



template<int v>
struct Integer
{
    static const int value = v;

    template<int n>
    const Integer<n + v> operator+(Integer<n> i)
    {
      return Integer<v + n>();
    }

    template<int n>
    const Integer<n * v> operator*(Integer<n> i)
    {
      return Integer<v * n>();
    }

    template<int n>
    const Integer<v - n> operator-(Integer<n> i)
    {
      return Integer<v - n>();
    }

    template<int n>
    const Integer<v / n> operator/(Integer<n> i)
    {
      return Integer<v / n>();
    }

    template<int n>
    const Integer<Operation<'^', Integer<v>, Integer<n> >::value >
    operator^ (Integer<n> i)
    {
      return Integer<Operation<'^', Integer<v>, Integer<n> >::value>();
    }

    template<int n>
    const Integer<v % n> operator%(Integer<n> i)
    {
      return Integer<v % n>();
    }

    template <int n>
    bool
    operator== (Integer<n> i)
    {
      return n == v;
    }

    template <int n>
    bool
    operator< (Integer<n> i)
    {
      return v < n;
    }

    template <int n>
    bool
    operator> (Integer<n> i)
    {
      return v > n;
    }

    template <int n>
    bool
    operator<= (Integer<n> i)
    {
      return v <= n;
    }

    template <int n>
    bool
    operator>= (Integer<n> i)
    {
      return v >= n;
    }

    Integer<v + 1>
    operator++ ()
    {
      return Integer<v + 1>();
    }


    operator
    int ()
    {
      return v;
    }

    operator
    double ()
    {
      return v;
    }

    operator
    float ()
    {
      return v;
    }


};


template <typename a, typename T>
struct IntList
{
    static const int value = a::value;
    typedef T next;
};

struct OUT_OF_RANGE
{
};

template <typename x>
struct IntList<x, Integer<0> >
{
    static const int value = x::value;
    typedef OUT_OF_RANGE next;
};


template <typename x>
struct Operation<0, Integer<0>, x>
{
    static const int value = x::value;
};




template<int n>
std::ostream& operator<< (std::ostream& s, Integer<n> i)
    {
      s << n;
      return s;
    }


// template <char op, int z, int y>
// struct Operation
// {
//     static const int value = Operation<op, Integer<x>, Integer<y> >;
// };

#include <typeinfo>
int main()
{
//  std::cout << Operation<'+', Operation<0, Integer<0>, Integer<10> >, Operation<0, Integer<0>, Integer<32> > >::value << std::endl;
//  std::cout << VAL(FIBO(INT(1))) << std::endl;
  Integer<2> i;
  Integer<2> j;
  auto t = j ^ i;
  std::cout << t << std::endl;
  std::cout << static_if<2 == 1, 42, 73>::value << std::endl;

//  typedef IntList<Integer<42>, IntList<Integer<73>, IntList<Integer<51>, Integer<0> > > > intlist;
  typedef CREATE4(1, 2, 3, 4) intlist;

  int foo = GET3(intlist);

  std::cout << foo << std::endl;
}
