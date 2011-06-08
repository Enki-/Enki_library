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
    static const int value = 73;
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
  Integer<42> i;
  Integer<1> j;
  auto t = i / j;
  bool o = typeid(t) == typeid(42);
  std::cout << o << std::endl;
}
