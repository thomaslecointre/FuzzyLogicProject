#ifndef TRAPEZOID_RIGHT_EVALUATOR_FUNC_H
#define TRAPEZOID_RIGHT_EVALUATOR_FUNC_H

#include "../core/ValueModel.h"
#include "../fuzzy/IsTrapezoidRight.h"
#include "Evaluator.h"

using namespace core;
using namespace fuzzy;

namespace evaluation {
	template <class T>
	class TrapezoidRightEvaluator : public Evaluator<T>
	{
	public:
		TrapezoidRightEvaluator(IsTrapezoidRight &);
		virtual ~TrapezoidRightEvaluator() {};

		T EvalFunc<T>::operator () (const T&) const;
	private:
		IsTrapezoidRight & trapR;
	};

	template <class T>
	TrapezoidRightEvaluator<T>::TrapezoidRightEvaluator(IsTrapezoidRight & _trapR) :
		trapR(_trapR)
	{

	}

	template <class T>
	T TrapezoidRightEvaluator<T>::EvalFunc<T>::operator() (const T& v) const
	{
		return trapR.evaluate(ValueModel<T>(v));
	}
}
#endif