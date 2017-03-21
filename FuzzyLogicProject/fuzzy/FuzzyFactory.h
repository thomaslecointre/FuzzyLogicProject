#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_HFu
#include "../core/ExpressionFactory.h"
#include "../core/Expression.h"
#include "../core/BinaryShadowExpression.h"
#include "FuzzyIncludes.h"

using namespace std;

namespace fuzzy {
	template <class T>
	class FuzzyFactory : public ExpressionFactory<T>
	{
	public:
		FuzzyFactory();
		FuzzyFactory(Not<T> * _opNot, And<T> * _opAnd, Or<T> * _opOr, Then<T> * _opThen, MamdaniDefuzz<T> * _opDefuzz, Agg<T> * _opAgg, Is<T> * _opIs);
		virtual ~FuzzyFactory() {};

		Expression<T> * newAnd(Expression<T> * l, Expression<T> * r);
		Expression<T> * newOr(Expression<T> * l, Expression<T> * r);
		Expression<T> * newThen(Expression<T> * l, Expression<T> * r);
		Expression<T> * newDefuzz(Expression<T> * l, Expression<T> * r);
		Expression<T> * newAgg(Expression<T> * l, Expression<T> * r);
		Expression<T> * newNot(Expression<T> * l, Expression<T> * r);
		Expression<T> * newIs(Expression<T> * l, Expression<T> * r);

	private:
		Not<T> * opNot;
		And<T> * opAnd;
		Or<T> * opOr; 
		Then<T> * opThen;
		MamdaniDefuzz<T> * opDefuzz;
		Agg<T> * opAgg;
		Is<T> * opIs
		
	};

	template <class T>
	FuzzyFactory<T>::FuzzyFactory()
	{

	}

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(Not<T> * _opNot, And<T> * _opAnd, Or<T> * _opOr, Then<T> * _opThen, MamdaniDefuzz<T> * _opDefuzz, Agg<T> * _opAgg, Is<T> * _opIs) :
		opNot(_opNot), opAnd(_opAnd), opOr(_opOr), opThen(_opThen), opDefuzz(_opDefuzz), opAgg(_opAgg), opIs(_opIs)
	{

	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r)
	{
		BinaryExpressionModel bem(opAnd, l, r);
		BinaryShadowExpression<T> bse(bem);
		return &bse;
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r)
	{
		BinaryExpressionModel bem(opOr, l, r);
		BinaryShadowExpression<T> bse(bem);
		return &bse;
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r)
	{
		BinaryExpressionModel bem(opThen, l, r);
		BinaryShadowExpression<T> bse(bem);
		return &bse;
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r)
	{
		BinaryExpressionModel bem(opDefuzz, l, r);
		BinaryShadowExpression<T> bse(bem);
		return &bse;
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r)
	{
		BinaryExpressionModel bem(opAgg, l, r);
		BinaryShadowExpression<T> bse(bem);
		return &bse;
	}


	template<class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* l, Expression<T>* r)
	{
		BinaryExpressionModel bem(opNot, l, r);
		BinaryShadowExpression<T> bse(bem);
		return &bse;
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newIs(Expression<T>* l, Expression<T>* r)
	{
		BinaryExpressionModel bem(opIs, l, r);
		BinaryShadowExpression<T> bse(bem);
		return &bse;
	}


}
#endif