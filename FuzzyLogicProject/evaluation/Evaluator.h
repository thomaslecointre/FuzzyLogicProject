#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include "../core/Expression.h"
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
		static Shape<T> * buildShape(const T& min, const T& max, const T& step, Expression<T> * e);
		static ostream& printShape(ostream&, Shape<T> & s);
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
	Shape<T> * Evaluator<T>::buildShape(const T & min, const T & max, const T & step, Expression<T> * e)
	{
		vector<T> x, y;
		for (T i = min; i <= max; i += step)
		{
			// y.push_back(e->evaluate(&ValueModel(i), &ValueModel(i)); ?
			x.push_back(i);
		}
		return new Shape<T>(x, y);
	}

	template <class T>
	ostream& Evaluator<T>::printShape(ostream& os, Shape<T> & s)
	{
		os << '[';
		vector<T>::const_iterator it = s.fBegin();
		for (; it != s.fEnd(); ++it)
			os << *it << ' ';
		os << ']';
		os << endl;
		os << '[';
		it = s.sBegin();
		for (; it != s.sEnd(); ++it)
			os << *it << ' ';
		os << ']';
		os << std::endl;
		return os;
	}
}
#endif // !EVALUATOR_H
