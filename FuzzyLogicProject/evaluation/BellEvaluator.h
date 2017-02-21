#ifndef BELL_EVALUATOR_FUNC_H
#define BELL_EVALUATOR_FUNC_H

#include "../fuzzy/IsBell.h"
#include "../core/ValueModel.h"
#include "Evaluator.h"

using namespace core;
using namespace fuzzy;

namespace evaluation {
	template <class T>
	class BellEvaluator : public Evaluator<T>
	{
	public:
		BellEvaluator(IsBell<T> &);
		virtual ~BellEvaluator() {};

		T BellEvaluator<T>::EvalFunc<T>::operator () (const T&) const;
	private:
		IsBell<T> & bell;
	};

	template <class T>
	BellEvaluator<T>::BellEvaluator(IsBell<T> & _bell) :
		bell(_bell)
	{
	}

	template <class T>
	T BellEvaluator<T>::EvalFunc<T>::operator() (const T& v) const
	{
		return bell.evaluate(ValueModel<T>(v));
	}
}

#endif 