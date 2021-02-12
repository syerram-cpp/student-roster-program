//
//  degree.hpp
//  C++Project
//
//  Created by crazywidow on 4/11/20.
//  Copyright © 2020 crazywidow. All rights reserved.
//

#pragma once

#ifndef DEGREE_H
#define DEGREE_H

#include <stdio.h>
#include <string>
#include <map>

enum DegreeProgram
{
    SECURITY=0, NETWORK, SOFTWARE
};

inline std::string DegreeProgramToString (DegreeProgram degreeProgram)
{
    switch(degreeProgram)
    {
        case 0: return "Security"; break;
        case 1: return "Network"; break;
        case 2: return "Software"; break;
    }
    throw "Not a valid degreeProgram";
}

inline DegreeProgram StringToDegreeProgram (std::string degreeProgram)
{
    if(degreeProgram == "SECURITY")
    {
        return SECURITY;
    }
    else if (degreeProgram == "NETWORK")
    {
        return NETWORK;
    }
    else
    {
        return SOFTWARE;
    }
}

#endif
