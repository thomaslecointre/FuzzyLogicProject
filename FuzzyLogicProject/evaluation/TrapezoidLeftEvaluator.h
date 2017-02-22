#ifndef TRAPEZOID_LEFT_EVALUATOR_FUNC_H
#define TRAPEZOID_LEFT_EVALUATOR_FUNC_H

#include "../core/ValueModel.h"
#include "../fuzzy/IsTrapezoidLeft.h"
#include "Evaluator.h"

using namespace core;
using namespace fuzzy;

namespace evaluation {
	template <class T>
	class TrapezoidLeftEvaluator : public Evaluator<T>::EvalFunc
	{
	public:
		TrapezoidLeftEvaluator(IsTrapezoidLeft<T> &);
		virtual ~TrapezoidLeftEvaluator() {};

		T operator () (const T&) const;
	private:
		IsTrapezoidLeft<T> & trapL;
	};

	template <class T>
	TrapezoidLeftEvaluator<T>::TrapezoidLeftEvaluator(IsTrapezoidLeft<T> & _trapL) :
		trapL(_trapL)
	{

	}

	template <class T>
	T TrapezoidLeftEvaluator<T>::operator() (const T& v) const
	{
		return trapL.evaluate(&ValueModel<T>(v));
	}
}
#endif