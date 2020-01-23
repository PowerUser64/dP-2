/*
#include <string.h>
class String
{
public:
    String(const char * str_);
    ~String();
private:
    char *string_;
};
//-------------------------------------
String::String(const char *str_)
{
    int length = strlen(str_);
    string_ = new char[length + 1];
    strcpy(string_, str_);
}
String::~String() { delete[] string_; }
String::String(String& that)
{
    
}

String String::operator=(String& that)
{

}
//-------------------------------------
    int main(void)
{
    String str1("Hello");
    String str2(str1);
    String str3("World");
    str3 = str2;
    return 0;
}
*/
/*
class Fun
{
private:
    int i_;
    double d_;
public:
    Fun operator-(const Fun &a) const;                 // ✅
    double operator%(const double &a) const;           // ✅
    Fun operator*(const Fun &a, const Fun &b) const ;  // ✅
    friend Fun operator%(const Fun &a);                // ❌
    double operator*(double a);                        // ✅
    friend Fun operator-(const Fun &a) const;          // ❌
    friend Fun operator*(double a, int b);             // ❌
    Fun operator-(void) const;                         // ❌
    Fun operator/(const Fun &a) const;                 // ✅
    friend Fun operator-(const Fun &a, int b);         // ❌
};
*/
/*
int main(void)
{
    const float cf = 10.0f;
    int x = 2;
    float f = 5.0f;
    float &r1 = f;          // ✅
    float &r2 = r1;         // ✅
    float &r3 = cf;         // ✅
    float &r4 = (float &)x; // ❌
    float &r5 = 5.0f;       // ❌
    float &r6 = x;          // ❌
    float &r7 = (float)x;   // ✅
    float &r8 = &f;         // ❌
    const float &r9 = f;    // ✅
} *//*
#include <iostream>
namespace Foo
{
float f = 11.0f;
}
void Function1(void)
{
    std::cout << f << std::endl;      // ❌
    std::cout << Foo::f << std::endl; // ✅
    std::cout << ::f << std::endl;    // ❌
}
namespace Bar
{
float f = 12.0f;
}
void Function2(void)
{
    using namespace Foo;
    std::cout << f << std::endl;      // ✅
    std::cout << Foo::f << std::endl; // ✅
    std::cout << ::f << std::endl;    // ❌
    std::cout << Bar::f << std::endl; // ✅
}
float f = 10.0f;
int main(void)
{
    Function1();
    Function2();
    float f = 13.0f;
    std::cout << f << std::endl;      // ✅
    std::cout << Foo::f << std::endl; // ✅
    std::cout << ::f << std::endl;    // ✅
    std::cout << Bar::f << std::endl; // ✅
    return 0;
}
*/
// Output:
/* ❌
 * 11
 * ❌
 * --
 * 11
 * 12
 * ❌
 * 12
 * --
 * 13
 * 11
 * 10
 * 12
 */