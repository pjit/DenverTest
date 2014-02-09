//
//  DENTest.cpp
//  DenverTest
//
//  Created by PARAMJIT SINGH on 2/8/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#include "DENTest.h"
#include "DenVector.h"
#include <math.h>

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
void testDENEq(const std::string& str, const DENReal& actualValue, const DENReal& expected)
{
    if (DENRealEqual(actualValue,expected)) {
        std::cout << str << "->Passed\n";
    }
    else {
        std::cout << str << "\n\tExpected:" << expected << " Actual:" << actualValue << " ->**FAILED**\n";
    }
}

void testDENVector()
{
    DENVector v(1,2,3);
    
    testDENVectorEq("constructed", v, 1, 2, 3);
    
    v.invert();

    testDENVectorEq("invert", v, -1, -2, -3);
    
    v.scale(3);
    
    testDENVectorEq("scale", v, -3, -6, -9);
    
    v.reset();
    
    testDENVectorEq("reset", v, 0, 0, 0);
    
    v.reset(9, 10, 11);
    
    testDENVectorEq("reset to non-zero", v, 9, 10, 11);
    
    DENVector v2(1, -2, 3);
    
    testDENEq("squaremagnitude", v2.squareMagnitude(), 14);
    
    testDENEq("magnitude", v2.magnitude(), sqrt(14));
    
    v2.reset(3,1,2);
    
    v2.normalize();

    testDENVectorEq("normalize", v2, 0.8017837257372732, 0.2672612419124244, 0.5345224838248488);
    
    v2.reset(4,5,6);
    
    DENVector v3;
    
    v3 = v2;
    
    testDENVectorEq("assignment", v3, 4,5,6);
    
    DENVector v4(v3);
    
    testDENVectorEq("copy-constructed", v4, 4,5,6);
    
    v4 = v3 + v4;
    
    testDENVectorEq("add vectors + op", v4, 8, 10, 12);
    
    v.reset(1,2,3);
    v2.reset(4,5,6);
    
    DENVector addedVector = DENVector::add(v, v2);
    
    testDENVectorEq("add vectors", addedVector, 5, 7, 9);
    testDENVectorEq("add vectors - original (left operand) unchanged", v, 1, 2, 3);
    testDENVectorEq("add vectors - original (right operand) unchanged", v2, 4, 5, 6);
    
    v.reset(2,-3,7);
    v2.reset(-4,2,-4);
    
    DENReal scalarProduct = DENVector::scalarProduct(v, v2);
    
    testDENEq("scalar product", scalarProduct, -42);
    
    v.reset(1,2,3);
    v2.reset(4,5,6);
    
    DENVector vectorProduct = DENVector::vectorProduct(v, v2);
    
    testDENVectorEq("vector product", vectorProduct, -3, 6, -3);
    
    v.reset(2,4,0);
    
    DENVector normalVector = DENVector::normal(v);
    
    testDENVectorEq("normal to a given vector", normalVector, 1.0/sqrt(5), 2.0/sqrt(5), 0);
    
    testDENEq("normal vector should have magnitude 1", normalVector.magnitude(), 1);
}