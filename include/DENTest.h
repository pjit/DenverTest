//
//  DENTest.h
//  DenverTest
//
//  Created by PARAMJIT SINGH on 2/8/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#ifndef DenverTest_DENTest_h
#define DenverTest_DENTest_h

#include <string>
#include "DENUtils.h"

class DENVector;

//
//
//
void testDENVectorEq(const std::string&, const DENVector&,
                     const DENReal&, const DENReal&, const DENReal&);
void testDENVectorEq(const std::string&, const DENVector&, const DENVector&);
void testDENEq(const std::string&, const DENReal&, const DENReal&);

//
// DENVector test
//
void testDENVector();
//
// DENParticle Tests
//
void testDENParticle();
//
//
//
void testDENParticleForceGravity();

#endif
