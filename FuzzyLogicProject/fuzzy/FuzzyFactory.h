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
		FuzzyFactory(
			Not<T> * opNot, 
			And<T> * opAnd, 
			Or<T> * opOr, 
			Then<T> * opThen,
			MamdaniDefuzz<T> * opDefuzz, 
			Agg<T> * opAgg, 
			SugenoDefuzz<T> * opSugeno, 
			SugenoConclusion<T> * opConclusion,
			SugenoThen<T> * opSugenoThen
			);
		virtual ~FuzzyFactory();

		Expression<T> * newNot(Expression<T> * e);
		Expression<T> * newIs(Expression<T> * e, Is<T> * is);

		Expression<T> * newAnd(Expression<T> * l, Expression<T> * r);
		Expression<T> * newOr(Expression<T> * l, Expression<T> * r);
		Expression<T> * newThen(Expression<T> * l, Expression<T> * r);
		Expression<T> * newDefuzz(Expression<T> *l, Expression<T> * r);
		Expression<T> * newDefuzz(Expression<T> * l, Expression<T> * r, const T & min, const T & max, const T & step);
		Expression<T> * newAgg(Expression<T> * l, Expression<T> * r);
		Expression<T> * newSugenoThen(Expression<T> * l, Expression<T> * r);
		
		Expression<T> * newSugeno(typename vector<Expression<T>*> * operands);
		Expression<T> * newConclusion(typename vector<Expression<T>*> * operands);
		
		void changeNot(Not<T> & e);

		void changeAnd(And<T> & e);
		void changeOr(Or<T> & e);
		void changeThen(Then<T> & e);
		void changeDefuzz(MamdaniDefuzz<T> & e);
		void changeAgg(Agg<T> & e);
		
		void changeSugenoConclusion(SugenoConclusion<T> & e);

	private:
		UnaryShadowExpression<T> * not;
		BinaryShadowExpression<T> * and;
		BinaryShadowExpression<T> * or;
		BinaryShadowExpression<T> * then;
		BinaryShadowExpression<T> * defuzz;
		BinaryShadowExpression<T> * agg;
		BinaryShadowExpression<T> * sugenoThen;
		NaryShadowExpression<T> * sugeno;
		NaryShadowExpression<T> * conclusion;
	};

	template <class T>
	FuzzyFactory<T>::FuzzyFactory()
	{

	}

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(Not<T> * opNot, And<T> * opAnd, Or<T> * opOr, Then<T> * opThen, MamdaniDefuzz<T> * opDefuzz, Agg<T> * opAgg, SugenoDefuzz<T> * opSugeno, SugenoConclusion<T> * opConclusion, SugenoThen<T> * opSugenoThen) :
		not(new UnaryShadowExpression<T>(opNot)),
		and(new BinaryShadowExpression<T>(opAnd)),
		or(new BinaryShadowExpression<T>(opOr)),
		then(new BinaryShadowExpression<T>(opThen)),
		defuzz(new BinaryShadowExpression<T>(opDefuzz)),
		agg(new BinaryShadowExpression<T>(opAgg)),
		sugenoThen(new BinaryShadowExpression<T>(opSugenoThen)),
		sugeno(new NaryShadowExpression<T>(opSugeno)),
		conclusion(new NaryShadowExpression<T>(opConclusion))
	{

	}

	template <class T>
	FuzzyFactory<T>::~FuzzyFactory()
	{
		ExpressionFactory<T>::~ExpressionFactory();
		delete not;
		delete and;
		delete or;
		delete then;
		delete defuzz;
		delete agg;
		delete sugenoThen;
		delete sugeno;
		delete conclusion;
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r)
	{
		return newBinary(and, l, r);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r)
	{
		return newBinary(or , l, r);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T> * l, Expression<T>* r)
	{
		return newBinary(then, l, r);
	}

	// l = ValueModel, r = Agg
	template<class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r)
	{
		return newBinary(defuzz, l, r);
	}

	// l = ValueModel, r = Agg
	template<class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T> * l, Expression<T> * r, const T & min, const T & max, const T & step)
	{
		MamdaniDefuzz<T> * temp = (MamdaniDefuzz<T> *) (defuzz->getTarget());
		temp->setMin(min);
		temp->setMax(max);
		temp->setStep(step);
		return newBinary(defuzz, l, r);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r)
	{
		return newBinary(agg, l, r);
	}


	template<class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T> * e)
	{
		return newUnary(not, e);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newIs(Expression<T> * e, Is<T> * is)
	{
		return newUnary(is, e);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newSugeno(typename vector<Expression<T>*> * operands)
	{
		return newNary(sugeno, operands);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newConclusion(typename vector<Expression<T>*> * operands)
	{
		return newNary(conclusion, operands);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newSugenoThen(Expression<T> * l, Expression<T> * r)
	{
		return newBinary(sugenoThen, l, r);
	}

	template<class T>
	void FuzzyFactory<T>::changeAnd(And<T> & e)
	{
		and->setTarget(&e);
	}

	template<class T>
	void FuzzyFactory<T>::changeOr(Or<T> & e)
	{
		or->setTarget(&e);
	}

	template<class T>
	void FuzzyFactory<T>::changeThen(Then<T> & e)
	{
		then->setTarget(&e);
	}

	template<class T>
	void FuzzyFactory<T>::changeDefuzz(MamdaniDefuzz<T> & e)
	{
		defuzz->setTarget(& e);
	}

	template<class T>
	void FuzzyFactory<T>::changeAgg(Agg<T> & e)
	{
		agg->setTarget(&e);
	}

	template<class T>
	void FuzzyFactory<T>::changeNot(Not<T> & e)
	{
		not->setTarget(&e);
	}

	template<class T>
	void FuzzyFactory<T>::changeSugenoConclusion(SugenoConclusion<T> & e)
	{
		conclusion->setTarget(&e);
	}
}
#endif