#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "../core/CoreIncludes.h"
#include "../core/ExpressionFactory.h"
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
		FuzzyFactory(Not<T> * opNot, And<T> * opAnd, Or<T> * opOr, Then<T> * opThen, MamdaniDefuzz<T> * opDefuzz, Agg<T> * opAgg);

		Expression<T> * newAnd(Expression<T> * l, Expression<T> * r);
		Expression<T> * newOr(Expression<T> * l, Expression<T> * r);
		Expression<T> * newThen(Expression<T> * l, Expression<T> * r);
		Expression<T> * newDefuzz(Expression<T> *l, Expression<T> * r);
		Expression<T> * newDefuzz(Expression<T> * l, Expression<T> * r, const T & min, const T & max, const T & step);
		Expression<T> * newAgg(Expression<T> * l, Expression<T> * r);
		Expression<T> * newNot(Expression<T> * e);
		Expression<T> * newIs(Expression<T> * e, Is<T> * is);

		void changeAnd(And<T> * e);
		void changeOr(Or<T> * e);
		void changeThen(Then<T> * e);
		void changeDefuzz(MamdaniDefuzz<T> * e);
		void changeAgg(Agg<T> * e);
		void changeNot(Not<T> * e);

	private:
		UnaryShadowExpression<T> & not;
		BinaryShadowExpression<T> & and;
		BinaryShadowExpression<T> & or;
		BinaryShadowExpression<T> & then;
		BinaryShadowExpression<T> & defuzz;
		BinaryShadowExpression<T> & agg;
	};

	template <class T>
	FuzzyFactory<T>::FuzzyFactory()
	{

	}

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(Not<T> * opNot, And<T> * opAnd, Or<T> * opOr, Then<T> * opThen, MamdaniDefuzz<T> * opDefuzz, Agg<T> * opAgg) :
		not(UnaryShadowExpression<T>(opNot)),
		and(BinaryShadowExpression<T>(opAnd)),
		or(BinaryShadowExpression<T>(opOr)),
		then(BinaryShadowExpression<T>(opThen)),
		defuzz(BinaryShadowExpression<T>(opDefuzz)),
		agg(BinaryShadowExpression<T>(opAgg))
	{

	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r)
	{
		return newBinary(&and, l, r);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r)
	{
		return newBinary(&or , l, r);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T> * l, Expression<T>* r)
	{
		return newBinary(&then, l, r);
	}

	// l = ValueModel, r = Agg
	template<class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r)
	{
		return newBinary(&defuzz, l, r);
	}

	// l = ValueModel, r = Agg
	template<class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T> * l, Expression<T> * r, const T & min, const T & max, const T & step)
	{
		((MamdaniDefuzz<T>*) defuzz.getTarget())->setMin(min);
		((MamdaniDefuzz<T>*) defuzz.getTarget())->setMax(max);
		((MamdaniDefuzz<T>*) defuzz.getTarget())->setStep(step);
		return newBinary(&defuzz, l, r);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r)
	{
		return newBinary(&agg, l, r);
	}


	template<class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T> * e)
	{
		return newUnary(&not, e);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newIs(Expression<T> * e, Is<T> * is)
	{
		return newUnary(is, e);
	}

	template<class T>
	void FuzzyFactory<T>::changeAnd(And<T> * e)
	{
		and.setTarget(e);
	}

	template<class T>
	void FuzzyFactory<T>::changeOr(Or<T>* e)
	{
		or.setTarget(e);
	}

	template<class T>
	void FuzzyFactory<T>::changeThen(Then<T>* e)
	{
		then.setTarget(e);
	}

	template<class T>
	void FuzzyFactory<T>::changeDefuzz(MamdaniDefuzz<T>* e)
	{
		defuzz.setTarget(e);
	}

	template<class T>
	void FuzzyFactory<T>::changeAgg(Agg<T>* e)
	{
		agg.setTarget(e);
	}

	template<class T>
	void FuzzyFactory<T>::changeNot(Not<T>* e)
	{
		not.setTarget(e);
	}
}
#endif