#ifndef SUGENO_THEN
#define SUGENO_THEN

#include "GenericOperatorIncludes.h"
#include "../core/CoreIncludes.h"

using namespace core;

namespace fuzzy {
	template<class T>
	class SugenoThen : public Then<T>
	{
	public:
		SugenoThen();
		SugenoThen(And<T> * _andFunction);
		~SugenoThen();

		T evaluate(Expression<T> * l, Expression<T> * r) const;

		void setAnd(And<T> * _andFunction);

		T PremiseValue();
	private:
		And<T> * andFunction;
		mutable T premiseValue;
	};
	
	template<class T>
	SugenoThen<T>::SugenoThen()
	{
	}

	template<class T>
	SugenoThen<T>::SugenoThen(And<T> * _andFunction):
		andFunction(_andFunction)
	{}

	template<class T>
	SugenoThen<T>::~SugenoThen()
	{
	}

	template<class T>
	T SugenoThen<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		premiseValue = l->evaluate();
		return premiseValue * r->evaluate();
	}

	template<class T>
	void SugenoThen<T>::setAnd(And<T> * _andFunction)
	{
		andFunction = _andFunction;
	}

	template<class T>
	T SugenoThen<T>::PremiseValue()
	{
		return premiseValue;
	}

}

#endif