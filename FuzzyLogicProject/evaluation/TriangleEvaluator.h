#ifndef TRIANGLE_EVALUATOR_FUNC_H
#define TRIANGLE_EVALUATOR_FUNC_H

#include "../core/ValueModel.h"
#include "../fuzzy/IsTriangle.h"
#include "Evaluator.h"

using namespace core;
using namespace fuzzy;

namespace evaluation {
	template <class T>
	class TriangleEvaluator : public Evaluator<T>::EvalFunc
	{
	public:
		TriangleEvaluator(IsTriangle<T> &);
		virtual ~TriangleEvaluator() {};

		T operator () (const T&) const;
	private:
		IsTriangle<T> & tri;
	};

	template <class T>
	TriangleEvaluator<T>::TriangleEvaluator(IsTriangle<T> & _tri) :
		tri(_tri)
	{
	}

	template <class T>
	T TriangleEvaluator<T>::operator() (const T& v) const
	{
		return tri.evaluate(&ValueModel<T>(v));
	}
}
#endif