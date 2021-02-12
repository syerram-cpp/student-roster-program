//
//  roster.hpp
//  C++Project
//
//  Created by crazywidow on 4/11/20.
//  Copyright © 2020 crazywidow. All rights reserved.
//

#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include "student.cpp"

#include <stdio.h>
#include<string>


/* roster_hpp */

void pars(const std::string studentList[], int size);

void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

void remove(std::string studentID);

void printAll();

void printAverageDaysInCourse(std::string studentID);

void loopThroughAverageDaysInCourse();

void printInvalidEmails();

void printByDegreeProgram(DegreeProgram degreeProgram);

#endif

