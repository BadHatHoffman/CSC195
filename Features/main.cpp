// Features.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<list>
using namespace std;

 template<typename T>
 T sqr(T v) {
     return v * v;
 }

 template<>
 int sqr<int>(int v) {
     cout << "int version\n";
     return v * v;
 }

 template<typename T>
 class Numbers {
 public:
     void setNumber(T number) { this->number = number;}
     T getNumber() { return number; }



 protected:
     T number;
 };


 struct Point {
     Point(){}
     Point(int x, int y) : x(x), y(y) {}

     Point add(Point p) {
         Point point;
         point.x = x + p.x;
         point.y = y + p.y;

         return point;
     }
    // + * - / ^ +=
    friend Point operator + (Point point1, Point point2) {
        Point point;
        point.x = point1.x + point2.x;
        point.y = point1.y + point2.y;

        return point;
    }  

     int x;
     int y;
 };

 ostream& operator << (ostream& stream, Point p) {
     cout << p.x << " " << p.y << endl;

     return stream;
 }


int main(){


    Point point1(3, 5);
    Point point2(5, 7);
    Point point3 = point1 + point2;
    //cout << point3.x << " " << point3.y << endl;
    cout << point3 << endl;


    vector<int> numbers = { 5,6,8 };

    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;


    //remove element from vector
    for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++){
        if (*iter == 6) {
            numbers.erase(iter);
            break;
        }
    }
    cout << endl;

    for (int n : numbers) {
        cout << n << " ";
    }

    Numbers<int> in;
    in.setNumber(5);

    Numbers<float> fn;
    fn.setNumber(6.5f);


}


