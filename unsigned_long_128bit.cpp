//
//  test_type_func.cpp
//  cppprogram
//
//  Created by thomas on 15/5/7.
//  Copyright (c) 2015年 thomas. All rights reserved.
//

#include <iostream>
//#include <numeric>
//#include <string>
//#include <cstdio>
//#include <vector>
//#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

/*
template <int DIM,typename T >
class DotProduct
{
public:
    static T result(T *a,T *b)
    {
        return *a * *b +DotProduct<DIM-1,T>::result(a+1,b+1);
    }
};

template <typename T>
class DotProduct<1,T> {
public:
    static T result(T *a,T *b)
    {
        return *a * *b;
    }
};

template <int DIM,typename T>
inline T dotProduct(T *a,T *b) {
    return DotProduct<DIM, T>::result(a,b);
}
*/


class unsigned_long_128
{
private:
    unsigned long long lower;
    unsigned long long higher;
public:
    unsigned_long_128():lower(0),higher(0){};
    unsigned_long_128(unsigned long long l):lower(l),higher(0){}
    unsigned_long_128(unsigned long long h,unsigned long long l):lower(l),higher(h){}
    unsigned_long_128(const unsigned_long_128& u):lower(u.lower),higher(u.higher){}
    friend const unsigned_long_128 operator+(const unsigned_long_128& l1,const unsigned_long_128& l2);
    friend void print(unsigned_long_128);
    inline unsigned long long mod(int n){return (higher*6+lower)%n;}
    inline bool isZero(){return higher==0&&lower==0;}
    inline bool overlap(){
        if((higher*6)%10+lower%10>=10)return true;
        else return false;}
    unsigned_long_128 div(int n);
};

//static unsigned int counting;

unsigned_long_128 unsigned_long_128::div(int n)
{
    if(higher==0)
    {//  cout<<++counting<<" "<<lower/10<<endl;
       return unsigned_long_128(lower/n);
    }
    if (overlap()) {
     //   cout<<++counting<<" "<<higher/10<<" "<<lower/10+((((higher%10)<<60)/10))<<endl;
        return unsigned_long_128(higher/n,lower/n+((((higher%n)<<60)/n)*16)+(((higher%n)<<60)%n*16/n));
    }
    else
    {
      //  cout<<++counting<<" "<<higher/10<<" "<<lower/10+((((higher%10)<<4)/10)<<60+1)<<endl;
        return unsigned_long_128(higher/n,lower/n+((((higher%n)<<60)/n)*16)+(((higher%n)<<60)%n*16/n)+1);
    }
}

inline
const unsigned_long_128 operator+(const unsigned_long_128& l1,
                                const unsigned_long_128& l2)
{
    if(l1.lower+l2.lower>l2.lower)
    {
        return unsigned_long_128(l1.higher+l2.higher,l1.lower+l2.lower);
    }
    else
    {
        return unsigned_long_128(l1.higher+l2.higher+1,l1.lower+l2.lower);
    }
}


void print(unsigned_long_128 u)
{
    
    if(u.isZero())return;
    print(u.div(10));
    cout<<u.mod(10);
}

int main()
{
    unsigned long long int l=0;
    unsigned long long int last=1;
    int N;
    cin>>N;
    for(int i=0;i<N&&i<18;i++)
    {
        l+=last;
        last=last*10+1;
    }
    cout<<l;
        

}

