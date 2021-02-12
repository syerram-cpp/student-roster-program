//
//  roster.cpp
//  C++Project
//
//  Created by crazywidow on 4/11/20.
//  Copyright © 2020 crazywidow. All rights reserved.
//

#include "roster.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Roster
{
private:
    int index = -1;
    const static int capacity = 40;
    Student* classRosterArray[capacity];

public:
    virtual ~Roster()
    {
        cout << "DELETING ROSTER... " << endl;
        for(int i=0; i<index+1; i++)
        {
            (*classRosterArray[i]).~Student();
        }
        cout << "ROSTER DELETED." << endl;
    };

    void pars(const string studentList[], int size)
    {
        try
        {
            int noOfStudents = size/sizeof(studentList[0]);
            for (int i=0; i<noOfStudents; i++)
            {
                string student[9];
                stringstream studentStream(studentList[i]);
                int j=0;
                while(studentStream.good())
                {
                    string substring;
                    getline(studentStream, substring, ',');
                    student[j] = substring;
                    j++;
                }
                string Age = student[4], DaysInCourse1 = student[5], DaysInCourse2 = student[6], DaysInCourse3 = student[7];
                int age = stoi(Age), daysInCourse1 = stoi(DaysInCourse1), daysInCourse2 = stoi(DaysInCourse2), daysInCourse3 = stoi(DaysInCourse3);
                DegreeProgram degreeProgram = StringToDegreeProgram(student[8]);
                add(student[0], student[1], student[2], student[3], age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
            }
        }
        catch(...)
        {
            cout << "Failed to create student(s)" << endl;
        }
    }

    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
    {
        int DaysInCourses[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
        Student* s = new Student(studentID, firstName, lastName, emailAddress, age, DaysInCourses, degreeProgram);
        index++;
        if (index == capacity)
        {
            throw "Max capacity of ClassRosterArray reached";
        }
        classRosterArray[index] = s;
    }

    void remove(string studentID)
    {
        cout << "REMOVING STUDENT '" << studentID << "'..." << endl;
        bool studentNotFound = 1;
        for(int i=0; i<index+1; i++)
        {
            Student s = *classRosterArray[i];
            if (s.getStudentID()==studentID)
            {
                studentNotFound = 0;
                int j=i;
                delete classRosterArray[j];
                for(; j<index; j++)
                {
                    Student* s = classRosterArray[j+1];
                    classRosterArray[j] = s;
                }
                delete classRosterArray[j];
                classRosterArray[j] = nullptr;
                index--;
                cout << "STUDENT '" << studentID << "' REMOVED.\n" << endl;
                return;
            }
        }
            if(studentNotFound)
            {
                cout << "Student with ID:'" << studentID << "' not found\n" << endl;;
            }
    }

    void printAll()
    {
        cout << "PRINTING ALL STUDENTS: " << endl;
        for(int i=0; i<index+1; i++)
        {
            Student s = *(classRosterArray[i]);
            s.print();
        }
        cout << endl;
    }

    void printAverageDaysInCourse(string studentID)
    {
        for(int i=0; i<index+1; i++)
        {
            Student s = *(classRosterArray[i]);
            if (s.getStudentID()==studentID)
            {
                int* p = s.getDaysInCourses();
                int average = 0;
                for (int i=0; i<Student::numOfCourses; i++)
                {
                    average+= p[i];
                }
                average /= Student::numOfCourses;
                cout << studentID << ": " << average << endl;
                return;
            }
        }
    }

    void loopThroughAverageDaysInCourse()
    {
        cout << "AVERAGE DAYS IN COURSE: " << endl;
        for(int i=0; i<index+1; i++)
        {
            Student s = *(classRosterArray[i]);
            printAverageDaysInCourse(s.getStudentID());
        }
        cout << endl;
    }

    void printInvalidEmails()
    {
        cout << "INVALID EMAILS: " << endl;
        for(int i=0; i<index+1; i++)
        {
            Student s = *(classRosterArray[i]);
            string email = s.getEmail();
            if (email.find(' ') != string::npos)
            {
                cout << email << endl;
                continue;
            }
            if ((email.find('@') != string::npos) && (email.find('.') != string::npos))
            {
                continue;
            }
            cout << email << endl;
        }
        cout << endl;
    }

    void printByDegreeProgram(DegreeProgram degreeProgram)
    {
        cout << "PRINT BY DEGREE PROGRAM [" << DegreeProgramToString(degreeProgram) << "]: " << endl;
        for(int i=0; i<index+1; i++)
        {
            Student s = *(classRosterArray[i]);
            if (s.getDegreeProgram()==degreeProgram)
            {
                s.print();
            }
        }
        cout << endl;
    }

};
