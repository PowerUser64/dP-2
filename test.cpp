#include <iostream>
class BaseClass
{
public:
  int iPublicField;
  void Display(void)
  {
    std::cout << iPublicField << std::endl; // a        V
    std::cout << iPrivateField << std::endl; // b       V
    std::cout << iProtectedField << std::endl; // c     V
  }
private:
  int iPrivateField;
protected:
  int iProtectedField;
};

class SubClass : public BaseClass
{
public:
  void Display(void)
  {
    std::cout << iPublicField << std::endl; // d        V
    std::cout << iPrivateField << std::endl; // e       NV
    std::cout << iProtectedField << std::endl; // f     V
  }
};

int main(void)
{
   BaseClass var1;
   std::cout << var1.iPublicField << std::endl; // g    V 
   std::cout << var1.iPrivateField << std::endl; // h   NV
   std::cout << var1.iProtectedField << std::endl; // i NV
   var1.Display(); // j                                 V
   
   SubClass var2;
   std::cout << var2.iPublicField << std::endl; // k    V
   std::cout << var2.iPrivateField << std::endl; // l   NV
   std::cout << var2.iProtectedField << std::endl; // m NV
   var2.Display(); // n                                 V
   
   return 0;
}