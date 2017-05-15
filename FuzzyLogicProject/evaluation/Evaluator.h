#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include "../core/BinaryExpressionModel.h"
#include "../core/UnaryExpressionModel.h"
#include "Shape.h"

using namespace std;
using namespace core;

namespace evaluation {

	template <class T>
	class Evaluator
	{
	public:
		class EvalFunc
		{
		public:
			virtual T operator () (const T&) const = 0;
		};

		static Shape<T> * buildShape(const T& min, const T& max, const T& step, EvalFunc & f);
		static Shape<T> * buildShape(const T& min, const T& max, const T& step, Expression<T> * tips, BinaryExpressionModel<T> * r);
	};

	template <class T>
	Shape<T> * Evaluator<T>::buildShape(const T & min, const T & max, const T & step, EvalFunc & f)
	{
		vector<T> x, y;
		for (T i = min; i <= max; i += step)
		{
			y.push_back(f(i));
			x.push_back(i);
		}
		return new Shape<T>(x, y);
	}

	template<class T>
	Shape<T> * Evaluator<T>::buildShape(const T & min, const T & max, const T & step, Expression<T> * tips, BinaryExpressionModel<T> * r)
	{
		vector<T> x, y;
		for (T i = min; i <= max; i += step)
		{
			ValueModel<T> * temp = (ValueModel<T> *)(tips);
			temp->setValue(i);
			y.push_back(r->evaluate());
			x.push_back(i);
		}
		return new Shape<T>(x, y);
	}
}
#endif // !EVALUATOR_H
