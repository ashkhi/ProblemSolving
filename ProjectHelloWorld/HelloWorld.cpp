#include <iostream>

using namespace std;

class Test
{
    public:
        void myPrint();
};

void Test::myPrint()
{
    cout << "Hello World \n\n";
}

int main()
{
    Test* t1 = new Test();
    t1->myPrint();

    //system("pause");
    return 0;
}