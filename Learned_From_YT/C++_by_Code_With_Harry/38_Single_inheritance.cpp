#include <iostream>
using namespace std;

class Base      // This is base class
{
    int data1;
    public:
        int data2;
        void setData();
        int getData1();
        int getData2();
};

void Base :: setData(void)
{
    data1 = 11;
    data2 = 22;
}

int Base :: getData1()
{
    return data1;
}

int Base :: getData2()
{
    return data2;
}

class Derived : public Base     // This is derived class
{
    int data3;
    public:
        void process();
        void display();
};

void Derived :: process()
{
    data3 = data2 * getData1();
}

void Derived :: display()
{
    cout<< "Data 1 : " << getData1() << endl;
    cout<< "Data 2 : " << data2 << endl;
    cout<< "Data 3 : " << data3 << endl;
}

int main()
{
    Derived der;
    der.setData();
    der.process();
    der.display();
    return 0;
}