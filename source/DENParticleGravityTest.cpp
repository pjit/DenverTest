//
//  DENParticleGravityTest.cpp
//  DenverTest
//
//  Created by PARAMJIT SINGH on 2/22/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#include "DENTest.h"
#include "DENParticleGravity.h"
#include "DENParticle.h"
#include "DENVector.h"

//
//
//
void testDENParticleForceGravity()
{
	DENParticle p;
	DENVector position(1, 2, 3);
	
	p.setPosition(position);
	p.setMass(5);
	
	DENParticleForce *gravityForce = new DENParticleGravity();
	
	gravityForce->updateForce(p, 1);
	
	DENVector accumulatedForce = p.getForce();
	
	p.setMass(2);
}