#include "array.h"
#include "vector.h"
#include "list.h"
#include <iostream>
#include <array>
#include <vector>
using namespace std;

//void function();

//void DisplayVector(const nc::vector<int>& v) {
//    for (size_t i = 0; i < v.size(); i++) {
//        cout << v[i] << " ";
//    }
//    cout << endl;
//}

//
//class A
//{
//public:
//    A() { cout << "default constructor\n"; }
//    A(int data) : data{ data } { cout << "constructor\n"; }
//    A(const A& other) { cout << "copy constructor\n"; }
//    ~A() { cout << "destructor\n"; }
//
//    A& operator = (const A& other) { cout << "assignment operator\n"; }
//
//    int GetData() { return data; }
//
//protected:
//    int data{ 0 };
//    float fdata{};
//};
//
//void functionA(A& o)
//{
//    //
//}
//
//void functionA(A* o)
//{
//    //
//}

    void DisplayArray(const nc::array<int, 5>& a) {
        for (size_t i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    void DisplayVector(const nc::vector<int>& v)
    {
        for (size_t i = 0; i < v.size(); i++) { cout << v[i] << " "; }
        cout << endl;
    }


int main()
{

    /* ARRAY */
    //cout << "array\n";
    //nc::array<int, 5> numbers{ 7,10, 65, 23, 14 };
    //numbers[0] = 23;
    //DisplayArray(numbers);

    //cout << "copy\n";
    //nc::array<int, 5> copy{ numbers };
    //copy[0] = 56;
    //copy[4] = 8;
    //DisplayArray(copy);

    //cout << "swap\n";
    //numbers.swap(copy);
    //DisplayArray(numbers);
    //DisplayArray(copy);

    //cout << "fill\n";
    //copy.fill(21);
    //DisplayArray(copy);

    //cout << "front: " << numbers.front() << endl;
    //cout << "back: " << numbers.back() << endl;
    //cout << "size: " << numbers.size() << endl;
    //cout << "data: " << numbers.data() << endl;
    

    /* Vector */
    /*cout << "vector\n";
    nc::vector<int> numbers{ 43, 23, 56, 7, 16 };
    numbers[0] = 84;
    numbers.push_back(99);
    DisplayVector(numbers);

    cout << "copy\n";
    nc::vector<int> copy;
    copy = numbers;
    copy.pop_back();
    copy.pop_back();
    DisplayVector(copy);

    cout << "swap\n";
    numbers.swap(copy);
    DisplayVector(numbers);
    DisplayVector(copy);

    cout << "clear\n";
    copy.clear();
    DisplayVector(copy);

    cout << "resize\n";
    numbers.resize(10, 5);
    numbers.reserve(20);
    DisplayVector(numbers);

    cout << "front: " << numbers.front() << endl;
    cout << "back: " << numbers.back() << endl;
    cout << "size: " << numbers.size() << endl;
    cout << "max size: " << numbers.max_size() << endl;
    cout << "capacity: " << numbers.capacity() << endl;
    cout << "empty: " << numbers.empty() << endl;
    cout << "data: " << numbers.data() << endl;*/

    /* LIST */
    nc::list<int> numbers{ 12, 78, 12, 34, 9 };
    numbers.push_back(10);
    numbers.push_front(8);
    numbers.write(cout);

    nc::list<int> copy;
    copy = numbers;
    copy.pop_front();
    copy.pop_back();
    copy.pop_back();
    copy.write(cout);

    copy.remove(12);
    copy.write(cout);

    copy.resize(10, 99);
    copy.write(cout);

    numbers.reverse();
    numbers.write(cout);

    cout << "front: " << numbers.front() << endl;
    cout << "back: " << numbers.back() << endl;
    cout << "size: " << numbers.size() << endl;
    cout << "empty: " << numbers.empty() << endl;



    /* IN CLASS TESTING */
    //int i = 1234;
    //char c{ static_cast<char>(i) };

    ////A a{ 3 };
    ////A b{ a };
    ////cout << "functionA" << endl;
    ////functionA(&a);

    //nc::vector<int> vnumbers{ 5, 8 };
    //vnumbers.push_back(10);
    //vnumbers.push_back(43);
    //vnumbers[0] = 3;
    ///*vnumbers.pop_back();*/
    //DisplayVector(vnumbers);

    //nc::vector<int> vcopy{ vnumbers };
    //vcopy = vnumbers;
    ////vcopy = vnumbers2;


    //for (size_t i = 0; i < vnumbers.size(); i++)
    //{
    //    cout << vnumbers[i] << " ";
    //}
    //cout << endl;
    ////nc::vector<int> cnumbers{ vnumbers };

    //nc::array<int, 5> numbers{ 23, 54, 12, 7, 12 };
    //for (int i = 0; i < 5; i++) { cout << numbers[i] << " "; }
    //cout << endl;

    //nc::array<int, 5> copy{ numbers };
    //for (int i = 0; i < 5; i++) { cout << copy[i] << " "; }
    //cout << endl;
    

    /*nc::list<int> numbers;
    numbers.push_front(5);
    numbers.push_front(8);
    numbers.write(cout);*/
    

}


