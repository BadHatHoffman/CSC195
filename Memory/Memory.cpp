// Memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void function(int& i) {
    i = 23;

    cout << i << endl;
    cout << &i << endl;
}

void swap(int& i1, int& i2) {
    int temp = i1;
    i1 = i2;
    i2 = temp;

}

void print(vector<int>& numbers) {

}


int main()
{
    int i = 5;
    int j = 8;

    int& r = i;

    swap(i, j);

    cout << i << endl;
    cout << &i << endl;

    cout << j << endl;
    cout << &j << endl;

    vector<int> numbers(1000);
    print(numbers);
}
