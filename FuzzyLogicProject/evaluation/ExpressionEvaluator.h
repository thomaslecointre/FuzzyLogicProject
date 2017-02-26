#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include "../core/Expression.h"
#include "Evaluator.h"

using namespace core;
using namespace fuzzy;

namespace evaluation {
	template <class T>
	class ExpressionEvaluator : public Evaluator<T>::EvalFunc
	{
	public:
		ExpressionEvaluator(Expression<T> *);
		virtual ~ExpressionEvaluator();

		T operator () (const T&) const;
	private:
		ExpressionEvaluator<T> * e;
	};

	template <class T>
	ExpressionEvaluator<T>::ExpressionEvaluator(Expression<T> * _e) :
		e(_e)
	{

	}

	template <class T>
	ExpressionEvaluator<T>::~ExpressionEvaluator()
	{
		delete e;
	}

	template <class T>
	T ExpressionEvaluator<T>::operator () (const T& v) const
	{
		return e->evaluate(&ValueModel(v));
	}
}
#endif