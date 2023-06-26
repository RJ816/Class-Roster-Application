#include "pch.h"

#include <iostream>
using namespace std;

#include "roster.h"

// Constructor
Roster::Roster() {
    classRosterArray = vector<Student*>();
}

// Destructor
Roster::~Roster() {
    for (auto student : classRosterArray) {
        delete student;
    }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, vector<int> daysInCourses, DegreeProgram degreeProgram) {
    Student* student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourses, degreeProgram);
    classRosterArray.push_back(student);
}

void Roster::remove(std::string studentID) {
    bool found = false;
    for (auto student = classRosterArray.begin(); student != classRosterArray.end(); ++student) {
        if ((*student)->getStudentId() == studentID) {
            classRosterArray.erase(student);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Student with ID " << studentID << " was not found." << std::endl;
    }
}

void Roster::printAll() {
    for (const auto& student : classRosterArray) {
        student->print();
    }
}

void Roster::printAverageDaysInCourses(string studentId) {
    for (const auto& student : classRosterArray) {
        if (student->getStudentId() == studentId) {
            std::vector<int> daysInCourse = student->getDaysInCourses();
            int sum = 0;
            for (int days : daysInCourse) {
                sum += days;
            }
            double average = static_cast<double>(sum) / daysInCourse.size();
            std::cout << "Average number of days in course for student " << studentId << ": " << average << std::endl;
            return;
        }
    }
    std::cout << "Student with ID " << studentId << " was not found." << std::endl;
}

void Roster::printInvalidEmails() {
    for (const auto& student : classRosterArray) {
        std::string email = student->getEmail();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            std::cout << "Invalid email: " << email << std::endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degree) {
    for (const auto& student : classRosterArray) {
        if (student->getDegree() == degree) {
            student->print();
        }
    }
}


const std::vector<Student*>& Roster::getClassRosterArray() const {
    return classRosterArray;
}
