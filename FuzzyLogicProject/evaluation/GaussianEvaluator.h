#ifndef GAUSSIAN_EVALUATOR_FUNC_H
#define GAUSSIAN_EVALUATOR_FUNC_H

#include "../fuzzy/IsGaussian.h"
#include "../core/ValueModel.h"
#include "Evaluator.h"

using namespace core;
using namespace fuzzy;

namespace evaluation {
	template <class T>
	class GaussianEvaluator : public Evaluator<T>
	{
	public:
		GaussianEvaluator(IsGaussian &);
		virtual ~GaussianEvaluator() {};

		T EvalFunc<T>::operator () (const T&) const;
	private:
		IsGaussian & gauss;
	};

	template <class T>
	GaussianEvaluator<T>::GaussianEvaluator(IsGaussian & _gauss):
		gauss(_gauss)
	{
	}

	template <class T>
	T GaussianEvaluator<T>::EvalFunc<T>::operator () (const T& v) const
	{
		return gauss.evaluate(ValueModel<T>(v));
	}
}

#endif