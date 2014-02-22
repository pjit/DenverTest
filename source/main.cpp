//
//  main.cpp
//  DenverTest
//
//  Created by PARAMJIT SINGH on 2/4/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#include <iostream>
#include "DENTest.h"

int main(int argc, const char * argv[])
{
	// DENVector test
	testDENVector();
	// DENParticle test
	testDENParticle();
	// Gravity force test
	testDENParticleForceGravity();
	
	return 0;
}

