#ifndef TRAPEZOID_EVALUATOR_FUNC_H
#define TRAPEZOID_EVALUATOR_FUNC_H

#include "../fuzzy/IsTrapezoid.h"
#include "../core/ValueModel.h"
#include "Evaluator.h"

using namespace core;
using namespace fuzzy;

namespace evaluation {
	template <class T>
	class TrapezoidEvaluator : public Evaluator<T>
	{
	public:
		TrapezoidEvaluator(IsTrapezoid &);
		virtual ~TrapezoidEvaluator() {};

		T EvalFunc<T>::operator () (const T&) const;
	private:
		IsTrapezoid & trap;
	};

	template <class T>
	TrapezoidEvaluator<T>::TrapezoidEvaluator<T>(IsTrapezoid & _trap) :
		trap(_trap)
	{

	}

	template <class T>
	T TrapezoidEvaluator<T>::EvalFunc<T>::operator () (const T& v) const
	{
		return trap.evaluate(ValueModel<T>(v));
	}
}
#endif