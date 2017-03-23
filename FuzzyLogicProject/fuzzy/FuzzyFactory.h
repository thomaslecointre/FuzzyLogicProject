#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "../core/CoreIncludes.h"
#include "FuzzyIncludes.h"
#include "GenericOperatorIncludes.h"

using namespace std;
using namespace core;

namespace fuzzy {
	template <class T>
	class FuzzyFactory : public ExpressionFactory<T>
	{
	public:
		FuzzyFactory();
		FuzzyFactory(Not<T> * opNot, And<T> * opAnd, Or<T> * opOr, Then<T> * opThen, MamdaniDefuzz<T> * opDefuzz, Agg<T> * opAgg, Is<T> * opIs);
		virtual ~FuzzyFactory() {};

		Expression<T> * newAnd(Expression<T> * l, Expression<T> * r);
		Expression<T> * newOr(Expression<T> * l, Expression<T> * r);
		Expression<T> * newThen(Expression<T> * l, Expression<T> * r);
		Expression<T> * newDefuzz(Expression<T> * l, Expression<T> * r);
		Expression<T> * newAgg(Expression<T> * l, Expression<T> * r);
		Expression<T> * newNot(Expression<T> * l, Expression<T> * r);
		Expression<T> * newIs(Expression<T> * l, Expression<T> * r);
		void changeAnd(And<T> *);
		void changeOr(Or<T> *);
		void changeThen(Then<T> *);
		void changeDefuzz(MamdaniDefuzz<T> *);
		void changeAgg(Agg<T> *);
		void changeNot(Not<T> *);
		void changeIs(Is<T> *);

	private:
		UnaryShadowExpression<T> * not;
		UnaryShadowExpression<T> * is
		BinaryShadowExpression<T> * and;
		BinaryShadowExpression<T> * or;
		BinaryShadowExpression<T> * then;
		BinaryShadowExpression<T> * defuzz;
		BinaryShadowExpression<T> * agg;
	};

	template <class T>
	FuzzyFactory<T>::FuzzyFactory()
	{

	}

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(Not<T> * opNot, And<T> * opAnd, Or<T> * opOr, Then<T> * opThen, MamdaniDefuzz<T> * opDefuzz, Agg<T> * opAgg, Is<T> * opIs) :
		not(new UnaryShadowExpression<T>(opNot)), 
		and(new BinaryShadowExpression<T>(opAnd)), 
		or(new BinaryShadowExpression<T>(opOr)), 
		then(new BinaryShadowExpression<T>(opThen)), 
		defuzz(new BinaryShadowExpression<T>(opDefuzz)), 
		agg(new BinaryShadowExpression<T>(opAgg)), 
		is(new UnaryShadowExpression<T>(opIs))
	{

	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r)
	{/*
		BinaryExpressionModel bem(opAnd, l, r);
		BinaryShadowExpression<T> bse(bem);
		return &bse;*/
		return new BinaryShadowExpression(BinaryExpressionModel bem(opAnd, l, r));
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

	template<class T>
	void FuzzyFactory<T>::changeAnd(And<T>*)
	{
	}

	template<class T>
	void FuzzyFactory<T>::changeOr(Or<T>*)
	{
	}

	template<class T>
	void FuzzyFactory<T>::changeThen(Then<T>*)
	{
	}

	template<class T>
	void FuzzyFactory<T>::changeDefuzz(MamdaniDefuzz<T>*)
	{
	}

	template<class T>
	void FuzzyFactory<T>::changeAgg(Agg<T>*)
	{
	}

	template<class T>
	void FuzzyFactory<T>::changeNot(Not<T>*)
	{
	}

	template<class T>
	void FuzzyFactory<T>::changeIs(Is<T>*)
	{
	}


}
#endif