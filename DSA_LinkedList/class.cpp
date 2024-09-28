#include <iostream>
using namespace std;

class Student {
    int rollno;
    string name;

    public:
    void print () {
        cout << "rollno = " << rollno << "\t" << "name = " << name << endl;
    }

    Student (int rollno, string name) {
        (*this).rollno = rollno;
        this -> name = name;
    }

    ~Student () {
        cout << "default constructor called for rollno = " << this -> rollno << endl;
    }
};

int main() {
    //statically
    Student s1(1,"sania");

    //dynamically
    Student * s2 = new Student(2,"ritik");   // will have to manually call its descructor

    s1.print();
    s2 -> print();   // or (*s2).print();

    delete s2;
}
