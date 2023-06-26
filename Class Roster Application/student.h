#pragma once
#include "pch.h"

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <vector>
#include "degree.h"
using namespace std;

class Student {
public:
    //constructors
    Student();
    Student(string studentId, string firstName, string lastName, string email, int age, vector<int> daysInCourses, DegreeProgram degree);

    //mutators
    void setStudentId(string studentId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysInCourses(vector<int> daysInCourses);
    void setDegree(DegreeProgram degree);

    //accessors
    //Demostrate inline for getter functions
    //const generates compiler error if function trys to modify the data field
    string getStudentId() const { return studentId; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getEmail() const { return email; }
    int getAge() const { return age; }
    vector<int> getDaysInCourses() const { return daysInCourses; }
    DegreeProgram getDegree() const { return degree; }

    void print();

private:
    string studentId = "A0";
    string firstName = "";
    string lastName = "";
    string email = "";
    int age = 0;
    vector<int> daysInCourses ={0,0,0};
    DegreeProgram degree = NONE;
};

#endif