#pragma once
#include <string>

class Student
{
public:
	Student() {
		name = "unknown";
		age = 0;
	}

	Student(std::string name_, int age_) {
		name = name_;
		age = age_;
		
	}

	void Write();
	void Read();

public:
	std::string name;
	int age;

	//private:
	float gpa;
	float height;
};