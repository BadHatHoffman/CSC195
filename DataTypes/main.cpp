// DataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//the default level of a stuct is public
//the default level of a class is private

#include "math.h"
#include "student.h"
#include <iostream>

using namespace std;


enum class eDegree {

	CS,
	SE,

};

eDegree degree = eDegree::SE; //0 = CS, 1 = SE

string GetDegreeName(eDegree degree) {
	switch (degree)
	{
	case eDegree::CS:
		cout << "Computer Science" << endl;
		break;
	case eDegree::SE:
		cout << "Software Engineer" << endl;
		break;
	default:
		break;
	}
	return "";
}

int main(){


	cout << GetDegreeName(degree) << endl;

	Student greg("Greg", 20);
	//greg.name = "Greg";
	//greg.age = 19;
	//cout << greg.name << endl;

	greg.Read();
	greg.Write();

	cout << sqr(8) << endl;
	cout << sqr(5.5f) << endl;
}


