#ifndef TRAPEZOID_EVALUATOR_FUNC_H
#define TRAPEZOID_EVALUATOR_FUNC_H

#include "../fuzzy/IsTrapezoid.h"
#include "../core/ValueModel.h"
#include "Evaluator.h"

using namespace core;
using namespace fuzzy;

namespace evaluation {
	template <class T>
	class TrapezoidEvaluator : public Evaluator<T>::EvalFunc
	{
	public:
		TrapezoidEvaluator(IsTrapezoid<T> &);
		virtual ~TrapezoidEvaluator() {};

		T operator () (const T&) const;
	private:
		IsTrapezoid<T> & trap;
	};

	template <class T>
	TrapezoidEvaluator<T>::TrapezoidEvaluator(IsTrapezoid<T> & _trap) :
		trap(_trap)
	{

	}

	template <class T>
	T TrapezoidEvaluator<T>::operator () (const T& v) const
	{
		return trap.evaluate(&ValueModel<T>(v));
	}
}
#endif