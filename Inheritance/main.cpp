// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Parent {
public:
    Parent() { 
        cout << "Parent Constructor"<<endl;
        count++;
    }

    virtual string getName() { return "Parent"; }
    static string getClassName() { return "ParentClass"; }
    static int getCount() { return count; }

protected:
    static int count;
    int data1;
};

int Parent::count = 0;

class Child : public Parent{
public:
    Child() {
        cout << "Child Constructor"<<endl;
    }

    string getName() override { return "Child"; }
    static string getClassName() { return "ChildClass"; }

protected:
    int data2;
};

int main()
{
    cout << Child::getClassName() << endl;
    
    Parent parent;
    Child child;

    cout << Parent::getCount() << endl;

    Parent* pParent = &parent;
    Parent* pChild = &child;

    cout << sizeof(parent) << endl;
    cout << sizeof(child) << endl;

    cout << pParent->getName() << endl;
    cout << pChild->getName() << endl;
}
