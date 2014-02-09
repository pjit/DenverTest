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
        std::cout << str << "->**FAILED**\n";
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
    
    DENVector v2(1, -2, 3);
    
    testDENEq("squaremagnitude", v2.squareMagnitude(), 14);
    
    testDENEq("magnitude", v2.magnitude(), sqrt(14));
    
    DENVector v3(3,1,2);
    
    v3.normalize();

    testDENVectorEq("normalize", v3, 0.8017837257372732, 0.2672612419124244, 0.5345224838248488);
    
    DENVector v4(4,5,6);
    
    DENVector v5;
    
    v5 = v4;
    
    testDENVectorEq("assignment", v5, 4,5,6);
    
    DENVector v6(v5);
    
    testDENVectorEq("copy-constructed", v6, 4,5,6);
    
    v4 = v5 + v6;
    
    testDENVectorEq("add vectors + op", v4, 8, 10, 12);
    
    DENVector v7(1,2,3);
    DENVector v8(4,5,6);
    
    DENVector addedVector = DENVector::add(v7, v8);
    
    testDENVectorEq("add vectors", addedVector, 5, 7, 9);
    testDENVectorEq("add vectors - original (left operand) unchanged", v7, 1, 2, 3);
    testDENVectorEq("add vectors - original (right operand) unchanged", v8, 4, 5, 6);
    
    DENVector v9(2,-3,7);
    DENVector v10(-4,2,-4);
    
    DENReal scalarProduct = DENVector::scalarProduct(v9, v10);
    
    testDENEq("scalar product", scalarProduct, -42);
    
    DENVector v11(1,2,3);
    DENVector v12(4,5,6);
    
    DENVector vectorProduct = DENVector::vectorProduct(v11, v12);
    
    testDENVectorEq("vector product", vectorProduct, -3, 6, -3);
    
    DENVector v13(2,4,0);
    
    DENVector normalVector = DENVector::normal(v13);
    
    testDENVectorEq("normal to a given vector", normalVector, 1/sqrt(5), 2/sqrt(5), 0);
    
    testDENEq("normal vector should have magnitude 1", normalVector.magnitude(), 1);
}