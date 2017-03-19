#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_HFu
#include "../core/ExpressionFactory.h"
#include "../core/Expression.h"
#include "FuzzyIncludes.h"

using namespace std;

namespace fuzzy {
	template <class T>
	class FuzzyFactory : public ExpressionFactory<T>
	{
	public:
		FuzzyFactory();
		FuzzyFactory(NotMinus1<T> * _opNot, AndMin<T> * _opAnd, OrMax<T> * _opOr, ThenMin<T> * _opThen, CogDefuzz<T> * _opDefuzz);
		virtual ~FuzzyFactory() {};

		Expression<T> * newAnd(Expression<T> * l, Expression<T> * r);
		Expression<T> * newOr(Expression<T> * l, Expression<T> * r);
		Expression<T> * newThen(Expression<T> * l, Expression<T> * r);
		Expression<T> * newAgg(Expression<T> * l, Expression<T> * r);
		Expression<T> * newDefuzz(Expression<T> * l, Expression<T> * r);
		Expression<T> * newNot(Expression<T> * l, Expression<T> * r);
		Expression<T> * newIs(Expression<T> * l, Expression<T> * r);

	private:
		NotMinus1<T> * opNot;
		AndMin<T> * opAnd;
		OrMax<T> * opOr; 
		ThenMin<T> * opThen;
		CogDefuzz<T> * opDefuzz;
	};

	template <class T>
	FuzzyFactory<T>::FuzzyFactory()
	{

	}

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(NotMinus1<T> * _opNot, AndMin<T> * _opAnd, OrMax<T> * _opOr, ThenMin<T> * _opThen, CogDefuzz<T> * _opDefuzz) :
		opNot(_opNot), opAnd(_opAnd), opOr(_opOr), opThen(_opThen), opDefuzz(_opDefuzz)
	{

	}

	template <class T>
	Expression<T> * newAnd(Expression<T> * l, Expression<T> * r)
	{
		return opAnd->evaluate(l, r);
	}

}
#endif