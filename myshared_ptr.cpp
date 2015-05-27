//
//  test_type_func.cpp
//  cppprogram
//
//  Created by thomas on 15/5/7.
//  Copyright (c) 2015年 thomas. All rights reserved.
//

#include <iostream>
//#include <numeric>
#include <string>
#include <cstdio>
//#include <vector>
#include <algorithm>
#include <iomanip>
#include <list>
using namespace std;

template<typename T>
class tShared_ptr
{
    T* value;
    size_t *count;
public:
    tShared_ptr():value(nullptr),count(nullptr){};
    tShared_ptr(int i):value(new T(i)),count(new size_t(1)){}
    tShared_ptr(const tShared_ptr& p):value(p.value),count(p.count)
    {
        (*count)++;
    };
    tShared_ptr operator=(const tShared_ptr& p)const
    {
        (*count)++;
        return tShared_ptr(p);
    }
    T& operator*()
    {
        return *value;
    }
    const size_t getCount(){return *count;}
    ~tShared_ptr()
    {
        (*count)--;
        if(count==0)
        {
            delete count;
            delete value;
        }
    }
};

void printHex(unsigned int i,unsigned int bitWidth)
{
    if(bitWidth==0)return;
    printHex(i/10, bitWidth-1);
    printf("%x",i%16);
}

int main()
{
//    tShared_ptr<char> p(1);
//    {
//        auto q=p;
//        cout<<p.getCount()<<endl;
//    }
//    cout<<p.getCount()<<endl;
//    *p=45;
//    cout<<*p;
    printHex(123456, 8);
}