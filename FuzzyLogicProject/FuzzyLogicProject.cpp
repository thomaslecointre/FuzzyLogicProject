// FuzzyLogicProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "core/ValueModel.h"
#include <iostream>
using namespace core;

int main()
{
	ValueModel<int> vm(5);
	std::cout << vm.evaluate();
	return 0;
}

