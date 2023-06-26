#pragma once
#include "pch.h"

#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include "student.h"

class Roster {
public:
    //Rule of three for C++
    Roster();
    ~Roster();
    //Roster(const Roster& objectToCopy);
    //Roster& operator=(const Roster& objectToCopy);

    void add(string studentID, string firstName, string lastName, string emailAddress, int age, vector<int> daysInCourses, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourses(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    const vector<Student*>& getClassRosterArray() const;
private:
    vector<Student*> classRosterArray;

};

#endif