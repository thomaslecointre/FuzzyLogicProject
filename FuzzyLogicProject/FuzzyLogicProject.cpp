// FuzzyLogicProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "core/CoreIncludes.h"
#include "evaluation/EvaluationIncludes.h"
#include "fuzzy/FuzzyIncludes.h"

#include <iostream>

using namespace core;
using namespace fuzzy;
using namespace evaluation;

int main()
{
	/*
	ValueModel<float> * vm = new ValueModel<float>(100);
	*/

	/*
	ValueModel<int> vm(5);
	std::cout << vm.evaluate() << std::endl;
	std::cout << vm2->evaluate() << std::endl;
	*/
	
	/*
	IsTriangle<float> * it = new IsTriangle<float>(2, 4, 6);
	std::cout << it->evaluate(vm) << std::endl;
	*/
	
	/*
	IsTrapezoidLeft<float> trap(10, 30);
	std::cout << trap.evaluate(new ValueModel<float>(5)) << std::endl;
	std::cout << trap.evaluate(new ValueModel<float>(15)) << std::endl;
	std::cout << trap.evaluate(new ValueModel<float>(60)) << std::endl;
	*/
	
	/*
	IsTrapezoidRight<float> trap(75, 90);
	std::cout << trap.evaluate(new ValueModel<float>(100)) << std::endl;
	std::cout << trap.evaluate(new ValueModel<float>(80)) << std::endl;
	std::cout << trap.evaluate(new ValueModel<float>(60)) << std::endl;
	*/

	/*
	IsTrapezoid<float> trap(10, 20, 30, 40);
	std::cout << trap.evaluate(new ValueModel<float>(100)) << std::endl;
	std::cout << trap.evaluate(new ValueModel<float>(35)) << std::endl;
	std::cout << trap.evaluate(new ValueModel<float>(25)) << std::endl;
	std::cout << trap.evaluate(new ValueModel<float>(15)) << std::endl;
	std::cout << trap.evaluate(new ValueModel<float>(5)) << std::endl;
	*/

	/*
	AggMax<float> * am = new AggMax<float>();
	std::cout << am->evaluate(new ValueModel<float>(5), new ValueModel<float>(7)) << std::endl;
	*/

	/*
	AggPlus<float> * ap = new AggPlus<float>();
	std::cout << ap->evaluate(new ValueModel<float>(5), new ValueModel<float>(7)) << std::endl;
	*/
	
	/*
	AndMin<float> * am = new AndMin<float>();
	std::cout << am->evaluate(new ValueModel<float>(5), new ValueModel<float>(7)) << std::endl;
	*/

	/*
	AndMult<float> * am = new AndMult<float>();
	std::cout << am->evaluate(new ValueModel<float>(5), new ValueModel<float>(7)) << std::endl;
	*/

	/*
	OrMax<float> * om = new OrMax<float>();
	std::cout << om->evaluate(new ValueModel<float>(5), new ValueModel<float>(7)) << std::endl;
	*/

	/*
	OrPlus<float> * op = new OrPlus<float>();
	std::cout << op->evaluate(new ValueModel<float>(5), new ValueModel<float>(7)) << std::endl;
	*/

	/*
	ThenMin<float> * tm = new ThenMin<float>();
	std::cout << tm->evaluate(new ValueModel<float>(5), new ValueModel<float>(7)) << std::endl;
	*/

	/*
	ThenMult<float> * tm = new ThenMult<float>();
	std::cout << tm->evaluate(new ValueModel<float>(5), new ValueModel<float>(7)) << std::endl;
	*/

	/*
	NotMinus1<float> * nm1 = new NotMinus1<float>();
	std::cout << nm1->evaluate(new ValueModel<float>(1)) << std::endl;
	*/

	/*
	IsGaussian<float> * ig = new IsGaussian<float>(1, 0);
	std::cout << ig->evaluate(new ValueModel<float>(0)) << std::endl;
	*/

	ValueModel<float> v(6);
	IsBell<float> ib(2, 4, 6);
	// std::cout << ib.evaluate(&v) << std::endl;
	BellEvaluator<float> be(ib);
	return 0;
}

