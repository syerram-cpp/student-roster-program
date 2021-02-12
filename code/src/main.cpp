//
//  main.cpp
//  C++Project
//
//  Created by crazywidow on 4/11/20.
//  Copyright © 2020 crazywidow. All rights reserved.
//
#include "roster.cpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Scripting & Programming Applications\n"
         << "C++\n"
         << "001359531\n"
         << "Sravani Yerramaneni\n"
         << endl;

    Roster* classRoster = new Roster();
    const string studentData[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Sravani,Yerramaneni,syerram@wgu.edu,18, 16, 5, 3,SOFTWARE"};
    classRoster->pars(studentData, sizeof(studentData));  // pars() FUNCTION CALLS add()
    classRoster->printAll();
    classRoster->printInvalidEmails();
    classRoster->loopThroughAverageDaysInCourse();
    classRoster->printByDegreeProgram(SOFTWARE);
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");
    classRoster->~Roster();
    cout << '\n' << endl;

}
