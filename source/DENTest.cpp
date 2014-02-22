//
//  DENTest.cpp
//  DenverTest
//
//  Created by PARAMJIT SINGH on 2/8/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#include <math.h>
#include "DENTest.h"
#include "DENVector.h"

//
//
//
void testDENVectorEq(const std::string& str, const DENVector& v,
                     const DENReal& x, const DENReal& y, const DENReal& z)
{
    if (v.x() == x && v.y() == y && v.z() == z) {
        std::cout << str << "->Passed\n";
    }
    else {
        std::cout << str << "->**FAILED**\n";
    }
}

//
//
//
void testDENVectorEq(const std::string& str, const DENVector& actualValue, const DENVector& expected)
{
    if (actualValue.x() == expected.x()
        && actualValue.y() == expected.y()
        && actualValue.z() == expected.z()) {
        std::cout << str << "->Passed\n";
    }
    else {
        std::cout << str << "->**FAILED**\n";
    }
}

//
//
//
void testDENEq(const std::string& str, const DENReal& actualValue, const DENReal& expected)
{
    if (DENRealEqual(actualValue,expected)) {
        std::cout << str << "->Passed\n";
    }
    else {
        std::cout << str << "\n\tExpected:" << expected << " Actual:" << actualValue << " ->**FAILED**\n";
    }
}
