//
//  DENTest.cpp
//  DenverTest
//
//  Created by PARAMJIT SINGH on 2/8/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#include <math.h>
#include "DENTest.h"
#include "DenVector.h"
#include "DENParticle.h"

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
    
    testDENVectorEq("add vectors '+' op", v4, 8, 10, 12);
    
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

//
//
//
void testDENParticle()
{
    DENParticle p1;
    
    testDENVectorEq("Init Position", p1.getPosition(), 0,0,0);
    testDENVectorEq("Init Velocity", p1.getVelocity(), 0,0,0);
    testDENVectorEq("Init Acceleration", p1.getAcceleration(), 0,0,0);
    testDENEq("Init Damping", p1.getDamping(), 0);
    
    DENVector v(1,2,3);
    
    p1.setPosition(v);
    
    testDENVectorEq("Position", p1.getPosition(), 1,2,3);
    
    v.reset(5,6,7);
    
    p1.setVelocity(v);
    
    testDENVectorEq("Velocity", p1.getVelocity(), 5,6,7);
    
    p1.setDamping(5);
    
    testDENEq("Damping", p1.getDamping(), 5);
    
    v.reset(0,-10,0);
    
    p1.setAcceleration(v);

    testDENVectorEq("Acceleration", p1.getAcceleration(), 0, -10, 0);
    
    DENReal mass = 1.5;
    
    p1.setMass(mass);
    
    testDENEq("Mass", p1.getMass(), 1.5);
    
    p1.setVelocity(DENVector(1,2,3));
    p1.setPosition(DENVector(4,5,6));
    
    DENParticle p2;
    
    p2 = p1;

    testDENVectorEq("assignment:position", p2.getPosition(), p1.getPosition());
    testDENVectorEq("assignment:velocity", p2.getVelocity(), p1.getVelocity());
    testDENVectorEq("assignment:acceleration", p2.getAcceleration(), p1.getAcceleration());
    testDENEq("assignment:mass", p2.getMass(), p1.getMass());
}