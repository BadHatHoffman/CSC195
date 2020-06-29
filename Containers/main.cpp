// Containers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

typedef float currency;
//using currency = double;

void print(int* n, size_t count) {
    for (int i = 0; i < count; i++) {
        cout << n[i] << " ";
    }
    cout << endl;
}

void print(const array<int, 4>& na) {

    for (int i = 0; i < na.size(); i++) {
        cout << na[i] << " ";
    }
    cout << endl;
}
    class Runner {
    public:
        Runner() {}
        Runner(string name, float time) : name(name), time(time) {}

        string getName() const { return name; }
        friend bool operator == (const Runner& runner, string name) {
            return (runner.name == name);
        }
        friend bool operator < (const Runner& runner1, const Runner& runner2) {
            return (runner1.time < runner2.time);
        }
        friend ostream& operator << (ostream& stream, const Runner& runner) {
            stream << runner.name << " " << runner.time << endl;
            return stream;
        }

    protected:
        string name;
        float time;
    };




int main()
{
    auto i = 5;
    currency dollars = 4.65f;

    int n[] = { 1,2,3,4,5,6, 7};
    cout << n[1] << endl;
    print(n, 7);

    array<int, 4> na = { 32,52,12,67 };
    cout << na.size() << endl;
    cout << na.front() << endl;
    na.fill(0);
    print(na);
    cout << na.at(0) << endl;

    list<string> strings = {"hi " , "my " , "name ", "is ", "Ethan "};
    strings.push_back("Hoffman ");
    auto iter = strings.begin();
    iter = strings.erase(iter);
    iter++;
    cout << *iter << endl;

    strings.remove("name");
    //strings.reverse();
    //strings.sort();


    for (string str : strings) {
        cout << str << "";
    }
    cout << endl;

    vector<int> numbers { 1,7,3,8,4 };
    vector<int>::iterator niter = find(numbers.begin(), numbers.end(), 3); 
    cout << *niter << endl;
    numbers.erase(niter);
    sort(numbers.begin(), numbers.end(), greater<int>());

    for (int i : numbers) {
        cout << i << " ";
    }
    cout << endl;


    for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;


    vector<Runner> runners = { { "felix", 5.2f} ,{"bolt", 4.5} ,{"johnson", 4.8} };
    auto riter =find(runners.begin(), runners.end(), "bolt");
    cout << (*riter).getName() << endl;
    sort(runners.begin(), runners.end());

    for (Runner runner : runners) {
        cout << runner;
    }
    
}



