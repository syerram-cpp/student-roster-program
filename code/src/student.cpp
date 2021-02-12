//
//  student.cpp
//  C++Project
//
//  Created by crazywidow on 4/11/20.
//  Copyright © 2020 crazywidow. All rights reserved.
//

#include "student.hpp"
#include <string>
#include <iostream>

using namespace std;

class Student
{

private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourses[numOfCourses];
    DegreeProgram degreeProgram;

public:

    const static int numOfCourses = 3;

    virtual ~Student()
    {
    };

    Student(string StudentID, string FirstName, string LastName, string Email, int Age, int DaysInCourses[], DegreeProgram DegreeProgram):
        studentID(StudentID),
        firstName(FirstName),
        lastName(LastName),
        email(Email),
        age(Age),
        degreeProgram(DegreeProgram)
    {
        for(int i=0; i<numOfCourses; i++)
        {
            int days = DaysInCourses[i];
            daysInCourses[i] = days;
        }
    }

    string getStudentID()
    {
        return studentID;
    }

    void setStudentID(string StudentID)
    {
        studentID = StudentID;
    }

    string getFirstName()
    {
        return firstName;
    }

    void setFirstName(string FirstName)
    {
        firstName = FirstName;
    }

    string getLastName()
    {
        return lastName;
    }

    void setLastName(string LastName)
    {
        lastName = LastName;
    }

    string getEmail()
    {
        return email;
    }

    void setEmail(string Email)
    {
        email = Email;
    }

    int getAge()
    {
        return age;
    }

    void setAge(int Age)
    {
        age = Age;
    }

    int* getDaysInCourses()
    {
        return daysInCourses;
    }

    void setDaysInCourses(int* DaysInCourses)
    {
        for(int i=0; i<numOfCourses; i++)
        {
            daysInCourses[i] = DaysInCourses[i];
        }
    }

     DegreeProgram getDegreeProgram()
    {
        return degreeProgram;
    }

    void setDegreeProgram(DegreeProgram DegreeProgram)
    {
        degreeProgram = DegreeProgram;
    }

    void printDaysInCourses(int* p)
    {
        for (int i=0; i<numOfCourses; i++)
        {
            cout << *p << '\t';
            p++;
        }
    }

    void print()
    {
        cout << getStudentID() << '\t'
             << "First Name: " << getFirstName() << '\t'
             << "Last Name: " << getLastName() << '\t'
             << "Age: " << getAge() << '\t'
             << "daysInCourse: {";
        int i=0;
        for(; i<numOfCourses-1; i++)
        {
            cout << getDaysInCourses()[i] << ", ";
        }
        cout << daysInCourses[numOfCourses-1] << "}\t"
             << "Degree Program: " << DegreeProgramToString(getDegreeProgram()) << endl;
    }

};
