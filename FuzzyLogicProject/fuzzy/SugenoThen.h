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
		virtual ~SugenoThen();

		virtual T evaluate(Expression<T> * l, Expression<T> * r) const;

		void updatePremiseValue(Expression<T> * l);

		T PremiseValue();
	private:
		T premiseValue;
	};
	
	template<class T>
	SugenoThen<T>::SugenoThen()
	{
	}

	template<class T>
	SugenoThen<T>::~SugenoThen()
	{
	}

	template<class T>
	T SugenoThen<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		return l->evaluate() * r->evaluate();
	}

	template<class T>
	void SugenoThen<T>::updatePremiseValue(Expression<T> * l)
	{
		premiseValue = l->evaluate();
	}

	template<class T>
	T SugenoThen<T>::PremiseValue()
	{
		return premiseValue;
	}

}

#endif