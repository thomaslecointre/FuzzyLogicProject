// FuzzyLogicProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "core/ValueModel.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/IsTrapezoidLeft.h"
#include <iostream>

using namespace core;
using namespace fuzzy;

int main()
{
	ValueModel<float> * vm = new ValueModel<float>(5);
	
	/*
	ValueModel<int> vm(5);
	std::cout << vm.evaluate();
	std::cout << vm2->evaluate();
	*/
	
	/*
	IsTriangle<float> * it = new IsTriangle<float>(2, 4, 6);
	std::cout << it->evaluate(vm);
	*/

	IsTrapezoidLeft<float> trap(3, 4);
	std::cout << trap.evaluate(vm);

	return 0;
}

