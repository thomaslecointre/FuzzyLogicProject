#ifndef TRAPEZOID_LEFT_EVALUATOR_FUNC_H
#define TRAPEZOID_LEFT_EVALUATOR_FUNC_H

#include "../core/ValueModel.h"
#include "../fuzzy/IsTrapezoidLeft.h"
#include "Evaluator.h"

using namespace core;
using namespace fuzzy;

namespace evaluation {
	template <class T>
	class TrapezoidLeftEvaluator : public Evaluator<T>
	{
	public:
		TrapezoidLeftEvaluator(IsTrapezoidLeft &);
		virtual ~TrapezoidLeftEvaluator() {};

		T EvalFunc<T>::operator () (const T&) const;
	private:
		IsTrapezoidLeft & trapL;
	};

	template <class T>
	TrapezoidLeftEvaluator<T>::TrapezoidLeftEvaluator(IsTrapezoidLeft & _trapL) :
		trapL(_trapL)
	{

	}

	template <class T>
	T TrapezoidLeftEvaluator<T>::EvalFunc<T>::operator() (const T& v) const
	{
		return trapL.evaluate(ValueModel<T>(v));
	}
}
#endif