#include "pch.h"

#include <iostream>
#include <vector>
using namespace std;

#include "student.h"

//demostrating default constructor, though not needed
Student::Student() {
    studentId = "A0";
    firstName = "";
    lastName = "";
    email = "";
    age = 0;
    daysInCourses = {0,0,0};
    DegreeProgram degree = NONE;
}

//overloaded constructor with all parameters
Student::Student(string studentId, string firstName, string lastName, string email, int age, vector<int> daysInCourses, DegreeProgram degree) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->daysInCourses = daysInCourses;
    this->degree = degree;
}

void Student::setStudentId(string studentId) { this->studentId = studentId; }

void Student::setFirstName(string firstName) { this->firstName = firstName; }

void Student::setLastName(string lastName) { this->lastName = lastName; }

void Student::setEmail(string email) { this->email = email; }

void Student::setAge(int age) { this->age = age; }

void Student::setDaysInCourses(vector<int> daysInCourses) { this->daysInCourses = daysInCourses; }

void Student::setDegree(DegreeProgram degree) { this->degree = degree; }

void Student::print() {
    cout << "Student ID: " << getStudentId() << "\t";
    cout << "First Name: " << getFirstName() << "\t";
    cout << "Last Name: " << getLastName() << "\t";
    cout << "Email: " << getEmail() << "\t";
    cout << "Age: " << getAge() << "\t";
    cout << "Days in Course: {";
    for (size_t i = 0; i < getDaysInCourses().size(); ++i) {
        cout << daysInCourses[i];
        if (i != daysInCourses.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}\t";
    
    switch (degree) {
    case DegreeProgram::SECURITY:
        cout << "Degree Program: SECURITY" << std::endl;
        break;
    case DegreeProgram::NETWORK:
        cout << "Degree Program: NETWORK" << std::endl;
        break;
    case DegreeProgram::SOFTWARE:
        cout << "Degree Program: SOFTWARE" << std::endl;
        break;
    default:
        cout << "Degree Program: NONE" << std::endl;
    }
}



