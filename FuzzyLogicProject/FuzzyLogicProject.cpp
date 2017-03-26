// FuzzyLogicProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "core/CoreIncludes.h"
#include "evaluation/EvaluationIncludes.h"
#include "fuzzy/FuzzyIncludes.h"
#include "fuzzy\FuzzyFactory.h"

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

	/*
	ValueModel<float> v(6);

	IsBell<float> ib(2, 4, 6);
	BellEvaluator<float> be(ib);

	IsGaussian<float> ig(1, 0);
	GaussianEvaluator<float> ge(ig);

	IsTrapezoid<float> trap(10, 20, 30, 40);
	TrapezoidEvaluator<float> te(trap);

	IsTrapezoidLeft<float> trapL(10, 30);
	TrapezoidLeftEvaluator<float> tle(trapL);

	IsTrapezoidRight<float> trapR(75, 90);
	TrapezoidRightEvaluator<float> tre(trapR);

	IsTriangle<float> it(2, 4, 6);
	TriangleEvaluator<float> trie(it);
	
	std::cout << "Bell" << std::endl;
	Evaluator<float>::PrintShape(std::cout, Evaluator<float>::BuildShape(0, 100, 1, be));
	std::cout << "Gaussian curve" << std::endl;
	Evaluator<float>::PrintShape(std::cout, Evaluator<float>::BuildShape(0, 100, 1, ge));
	std::cout << "Trapezoid" << std::endl;
	Evaluator<float>::PrintShape(std::cout, Evaluator<float>::BuildShape(0, 100, 1, te));
	std::cout << "Trapezoid Left" << std::endl;
	Evaluator<float>::PrintShape(std::cout, Evaluator<float>::BuildShape(0, 100, 1, tle));
	std::cout << "Trapezoid Right" << std::endl;
	Evaluator<float>::PrintShape(std::cout, Evaluator<float>::BuildShape(0, 100, 1, tre));
	std::cout << "Triangle" << std::endl;
	Evaluator<float>::PrintShape(std::cout, Evaluator<float>::BuildShape(0, 100, 1, trie));
	*/
	
	// operators 
	NotMinus1<float> opNot;
	AndMin<float> opAnd;
	OrMax<float> opOr;
	ThenMin<float> opThen;
	CogDefuzz<float> opDefuzz;
	AggMax<float> opAgg;
	IsTriangle<float> opIs;

	// fuzzy expression factory
	FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opDefuzz, &opAgg, &opIs);

	
	return 0;
}

