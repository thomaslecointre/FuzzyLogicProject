#ifndef TRIANGLE_EVALUATOR_FUNC_H
#define TRIANGLE_EVALUATOR_FUNC_H

#include "../core/ValueModel.h"
#include "../fuzzy/IsTriangle.h"
#include "Evaluator.h"

using namespace core;
using namespace fuzzy;

namespace evaluation {
	template <class T>
	class TriangleEvaluator : public Evaluator<T>
	{
	public:
		TriangleEvaluator(IsTriangle &);
		virtual ~TriangleEvaluator() {};

		T EvalFunc<T>::operator () (const T&) const;
	private:
		IsTriangle & tri;
	};

	template <class T>
	TriangleEvaluator<T>::TriangleEvaluator(IsTriangle & _tri) :
		tri(_tri)
	{
	}

	template <class T>
	T TriangleEvaluator<T>::EvalFunc<T>::operator() (const T& v) const
	{
		return tri.evaluate(ValueModel<T>(v));
	}
}
#endif