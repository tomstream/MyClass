#include <vector>
#include <iostream>
using namespace std;


class tstring

{	// varying size array of bits
public:
    typedef size_t size_type;
    
    tstring() = default;
    tstring(const tstring&) = default;
    ~tstring() = default;
    tstring(const char* _c)
    {
        auto p = c;
        while (*_c != '\0')
        {
            *(p++) = *(_c++);
        }
        *p = '\0';
    }
    
    typedef char const_reference;
    typedef char value_type;
    
    typedef const char* const_iterator;
    typedef char* iterator;
    
    typedef iterator pointer;
    typedef const_iterator const_pointer;
    
    iterator begin()
    {
        return c;
    }
    iterator end()
    {
        auto iter = c;
        while (*(iter++) != '\0'){}
        return iter;
    }
    const_iterator cbegin()
    {
        return const_cast<const_iterator>(c);
    }
    const_iterator cend()
    {
        auto iter = c;
        while (*(iter++) != '\0'){}
        return const_cast<const_iterator>(iter);
    }
    
private:
    char c[200];
};

int main()
{
    tstring ts("123qwerty");
    for (auto& i:ts)
    {
        cout << i << endl;
    }
    getchar();
}

