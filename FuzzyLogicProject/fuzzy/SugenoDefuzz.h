#ifndef SUGENO_DEFUZZ_H
#define SUGENO_DEFUZZ_H

#include <vector>
#include "../core/CoreIncludes.h"

using namespace std;
using namespace core;

namespace fuzzy {
	template <class T>
	class SugenoDefuzz : public NaryExpression<T>
	{
	public:
		T evaluate(typename vector<Expression<T>*> * operands) const;
	};

	template<class T>
	T SugenoDefuzz<T>::evaluate(typename vector<Expression<T>*> * operands) const
	{
		typename vector<Expression<T>*>::const_iterator it = operands->begin();
		T numerator = 0;
		T denominator = 0;

		for (it = operands->begin(); it != operands->end(); it++) {
			numerator += (*it)->evaluate();
		}

		for (it = operands->begin(); it != operands->end(); it++) {
			BinaryExpressionModel<T> * model = (BinaryExpressionModel<T>*) (*it);
			SugenoThen<T> * sugeno = (SugenoThen<T>*) model->getOperator();
			sugeno->updatePremiseValue(model->getLeft());
			denominator += sugeno->PremiseValue();
		}

		cout << "numerator : " << numerator << endl;
		cout << "denominator : " << denominator << endl;

		if (denominator != 0)
			return numerator / denominator;
		else
			return 0;

	}
}
#endif