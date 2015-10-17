#include <iostream>
using namespace std;

template <int n1,int n2>
struct ADD
{
    enum{value=n1+n2};
};
template <int n1,int n2>
struct SUB
{
    enum{value=n1-n2};
};
template <int n1,int n2>
struct MUL
{
    enum{value=n1*n2};
};
template <int n1,int n2>
struct DIV
{
    enum{value=n1/n2};
};
template <int n1,int n2>
struct MOD
{
    enum{value=n1%n2};
};
template <int n1,int n2>
struct POWER
{
    enum{value=n1*POWER<n1,n2-1>::value};
};
template <int n1>
struct POWER<n1,0>
{
    enum{value=1};
};
template <int n1>
struct FACT
{
    enum{value=n1*FACT<n1-1>::value};
};
template <>
struct FACT<0>
{
    enum{value=1};
};
template <int n,int n1,int n2>
struct squareroot
{
    enum{
        value=((n1+n2)*(n1+n2)>=4*n)?
                    squareroot<n,n1,(n1+n2)/2>::value
                    :squareroot<n,(n1+n2)/2+1,n2>::value
    };
};
template <int n,int n1>
struct squareroot<n,n1,n1>
{
    enum{value=n1};
};
template <int n>
struct SQUAREROOT
{
    enum{value=squareroot<n, 0, n>::value};
};

struct Nil;

template <int n,typename L>
struct LIST
{
    enum{value=n};
    typedef LIST<n, L> THISNODE;
    typedef L NEXTNODE;
};

template <typename L>
struct lenghOfLIST
{
    enum{value=1+lenghOfLIST<typename L::NEXTNODE>::value};
};

template <>
struct lenghOfLIST<Nil>
{
    enum{value=0};
};

template <typename L,int n>
struct nthValue
{
    enum{value=nthValue<typename L::NEXTNODE,n-1>::value};
};

template <typename L>
struct nthValue<L,0>
{
    enum{value=L::value};
};

template <typename L>
struct maxOfLIST
{
    enum
    {
        value=(L::value>=maxOfLIST<typename L::NEXTNODE>::value)?
        L::value:maxOfLIST<typename L::NEXTNODE>::value
    };
};
template <int n>
struct maxOfLIST<LIST<n,Nil>>
{
    enum{value=n};
};

template <typename L>
struct minOfLIST
{
    enum
    {
        value=(L::value<=minOfLIST<typename L::NEXTNODE>::value)?
        L::value:minOfLIST<typename L::NEXTNODE>::value
    };
};
template <int n>
struct minOfLIST<LIST<n,Nil>>
{
    enum{value=n};
};

template <typename L>
struct accumulaterForList
{
    enum{value=L::value+accumulaterForList<typename L::NEXTNODE>::value};
};
template <int n>
struct accumulaterForList<LIST<n,Nil>>
{
    enum{value=n};
};

template <typename L1,typename L2>
struct mergeLIST
{
    typedef LIST<L1::value,typename mergeLIST<typename L1::NEXTNODE, L2>::type> type;
};

template <typename L>
struct mergeLIST<Nil,L>
{
    typedef L type;
};

template <typename L>
struct lastValue
{
    enum{value=lastValue<typename L::NEXTNODE>::value};
};
template <int n>
struct lastValue<LIST<n,Nil>>
{
    enum{value=n};
};

template <typename L>
struct deleteBack
{
    typedef LIST<L::value,typename deleteBack<typename L::NEXTNODE>::type> type;
};
template <int n>
struct deleteBack<LIST<n, Nil>>
{
    typedef Nil type;
};

template <typename L>
struct reverseLIST
{
    typedef LIST<lastValue<L>::value, typename reverseLIST<typename deleteBack<L>::type>::type> type;
};
template <>
struct reverseLIST<Nil>
{
    typedef Nil type;
};

template <typename L>
void printLIST()
{
        std::cout<<L::value<<" ";
        printLIST<typename L::NEXTNODE>();
}
template <>
void printLIST<Nil>()
{
    std::cout<<std::endl;
}

int main()
{
    std::cout<<FACT<5>::value<<std::endl;
    std::cout<<SQUAREROOT<POWER<100, 2>::value>::value<<std::endl;
    
    typedef LIST<1,LIST<5,LIST<5, LIST<3, LIST<6, Nil>>>>> l1;
    typedef LIST<1,LIST<3,LIST<5, LIST<3, LIST<9, Nil>>>>> l2;
    
    typedef mergeLIST<l1, l2>::type l3;
    printLIST<l3>();
    
    typedef reverseLIST<l1>::type rl1;
    printLIST<rl1>();
    
    return 0;
}
