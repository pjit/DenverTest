//
//  DENParticleTest.cpp
//  DenverTest
//
//  Created by PARAMJIT SINGH on 2/22/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#include <math.h>
#include "DENTest.h"
#include "DENParticle.h"

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