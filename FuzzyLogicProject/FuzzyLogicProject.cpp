// FuzzyLogicProject.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#define NUMERIC float
#include "fuzzy.h"

#include "core\CoreIncludes.h"
#include "evaluation\EvaluationIncludes.h"
#include "fuzzy\FuzzyIncludes.h"
#include <iostream>

int main()
{
	// operators 
	_NotMinus1_ opNot;
	_AndMin_ opAnd;
	_OrMax_ opOr;
	_ThenMin_ opThen;
	_CogDefuzz_ opDefuzz;
	_AggMax_ opAgg;
	_IsTriangle_ opIs;

	// fuzzy expression factory
	_FuzzyFactory_ f(&opNot, &opAnd, &opOr, &opThen, &opDefuzz, &opAgg, &opIs);

	// membership function
	_IsTriangle_ poor(-5, 0, 5);
	_IsTriangle_ good(0, 5, 10);
	_IsTriangle_ excellent(5, 10, 15);
	
	_IsTriangle_ cheap(0, 5, 10);
	_IsTriangle_ average(10, 15, 20);
	_IsTriangle_ generous(20, 25, 30);
	
	// values
	_ValueModel_ service(0);
	_ValueModel_ food(0);
	_ValueModel_ tips(0);
	/*
	_Expression_ *r =
		f.newAgg(
			f.newAgg(
				f.newThen(
					f.newIs(&service, &poor),
					f.newIs(&tips, &cheap)
					),
				f.newThen(
					f.newIs(&service, &good),
					f.newIs(&tips, &average)
					)
				),
			f.newThen(
				f.newIs(&service, &excellent),
				f.newIs(&tips, &generous)
				)
			);

	_Expression_ *system = f.newDefuzz(&tips, r, 0, 25, 1);
	

	// apply input
	float s;
	while (true)
	{
		cout << "service: ";
		cin >> s;
		
	}
	*/
	return 0;
}

