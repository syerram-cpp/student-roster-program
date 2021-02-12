//
//  student.hpp
//  C++Project
//
//  Created by crazywidow on 4/11/20.
//  Copyright © 2020 crazywidow. All rights reserved.
//

#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string>

#include "degree.hpp"

const static int numOfCourses = 3;

std::string getStudentID();
void setStudentID(std::string StudentID);

std::string getFirstName();
void setFirstName(std::string FirstName);

std::string getLastName();
void setLastName(std::string LastName);

std::string getEmail();
void setEmail(std::string Email);

int getAge();
void setAge(int Age);

int* getDaysInCourses();
void setDaysInCourses(int* DaysInCourses);

DegreeProgram getDegreeProgram();
void setDegreeProgram(DegreeProgram degreeProgram);

void printDaysInCourses(int* p);

void print();


#endif

