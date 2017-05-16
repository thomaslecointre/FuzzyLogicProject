// FuzzyLogicProject.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#define NUMERIC double
#include "fuzzy.h"

#include "core\CoreIncludes.h"
#include "evaluation\EvaluationIncludes.h"
#include "fuzzy\FuzzyIncludes.h"
#include <iostream>

void mamdaniFuzzyInference(_FuzzyFactory_ & f)
{
	// membership function
	_IsTriangle_ poor(-5, 0, 5);
	_IsTriangle_ good(0, 5, 10);
	_IsTriangle_ excellent(5, 10, 15);

	_IsTriangle_ cheap(0, 5, 10);
	_IsTriangle_ average(10, 15, 20);
	_IsTriangle_ generous(20, 25, 30);

	// values
	_ValueModel_ service(8);
	_ValueModel_ food(3);
	_ValueModel_ tips(0);

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

	_Expression_ * system = f.newDefuzz(&tips, r, 0, 25, 1);


	// apply input
	float s;
	while (true)
	{
		cout << "service: ";
		cin >> s;
		service.setValue(s);
		cout << "tips ->" << system->evaluate() << endl;
	}
}

void sugenoFuzzyInference(_FuzzyFactory_ & f)
{
	// Inputs
	_ValueModel_ service(0);
	_ValueModel_ food(0);
	_ValueModel_ tips(0);

	// Tips
	_ValueModel_ cheap(5);
	_ValueModel_ average(15);
	_ValueModel_ generous(25);

	// Quality
	_IsTrapezoid_ poor(0, 3, 6, 9);
	_IsTrapezoid_ good(6, 10, 14, 18);
	_IsTrapezoid_ excellent(15, 19, 23, 27);
	_IsTriangle_ rancid(-5, 0, 5);
	_IsTriangle_ delicious(5, 10, 15);

	// Defuzz
	_SugenoDefuzz_ opSugeno;
	_vector_ coef;
	coef.push_back(1);
	coef.push_back(1);
	_SugenoConclusion_ opConclusion(coef);

	// Conclusion
	_vectorExpression_ serviceFood;
	serviceFood.push_back(&service);
	serviceFood.push_back(&food);

	_vectorExpression_ vService;
	vService.push_back(&service);

	// Rules
	_vectorExpression_ rules;
	rules.push_back(
		f.newThen(
			f.newOr(
				f.newIs(&service, &poor),
				f.newIs(&food, &rancid)
			),
			f.newConclusion(&serviceFood)
		)
	);

	rules.push_back(
		f.newThen(
			f.newIs(&service, &good),
			f.newConclusion(&vService)
		)
	);

	rules.push_back(
		f.newThen(
			f.newOr(
				f.newIs(&service, &excellent),
				f.newIs(&food, &delicious)
			),
			f.newConclusion(&serviceFood)
		)
	);


	// Defuzzification
	_Expression_ *system = f.newSugeno(&rules);


	float s = 0;

	while (s != -1)
	{
		cout << "service : "; 
		cin >> s;
		service.setValue(s);
		cout << "food : "; 
		cin >> s;
		food.setValue(s);
		cout << "tips -> " << system->evaluate() << endl;
	}

}

int main()
{
	// operators 
	_NotMinus1_ opNot;
	_AndMin_ opAnd;
	_OrMax_ opOr;
	_ThenMin_ opThen;
	_CogDefuzz_ opDefuzz;
	_AggMax_ opAgg;
	_SugenoDefuzz_ opSugenoDefuzz;
	_SugenoConclusion_ opConclusion;

	// fuzzy expression factory
	_FuzzyFactory_ f(&opNot, &opAnd, &opOr, &opThen, &opDefuzz, &opAgg, &opSugenoDefuzz, &opConclusion);

	// mamdaniFuzzyInference(f);

	sugenoFuzzyInference(f);

	return 0;
}
