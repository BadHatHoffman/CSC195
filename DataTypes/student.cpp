#include "student.h"
#include <iostream>

using namespace std;

void Student::Write() {
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}

void Student::Read(){
	cout << "Name: ";
	cin >> name;
	cout << "Age: ";
	cin >> age;
}
