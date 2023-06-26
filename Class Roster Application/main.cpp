#include "pch.h"
using namespace winrt;
using namespace Windows::Foundation;

#include <iostream>
#include "roster.h"
using namespace std;

int main()
{
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 010760041" << endl;
    cout << "Name: Samurai Jack" << endl;

    Roster classRoster = Roster();

    classRoster.add("A1", "John", "Smith", "John1989@gm ail.com", 20, { 30, 35, 40 }, DegreeProgram::SECURITY);
    classRoster.add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, { 50, 30, 40 }, DegreeProgram::NETWORK);
    classRoster.add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, { 20, 40, 33 }, DegreeProgram::SOFTWARE);
    classRoster.add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, { 50, 58, 40 }, DegreeProgram::SECURITY);
    classRoster.add("A5", "Samurai", "Jack", "backtothepast@aol.com", 33, { 34, 35, 36 }, DegreeProgram::NONE);

    classRoster.printAll();
    classRoster.printInvalidEmails();

    // Loop through classRosterArray and print average days in course for each student
    for (const auto& student : classRoster.getClassRosterArray()) {
        classRoster.printAverageDaysInCourses(student->getStudentId());
    }

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    classRoster.remove("A3");
    classRoster.printAll();

    classRoster.remove("A3"); // Should print an error message

    return 0;
}