#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include "Shape.h"

using namespace std;

namespace evaluation {
	template <class T>
	class Evaluator
	{
	public:
		
		template <class T>
		class EvalFunc
		{
		public:
			virtual T operator () (const T&) const = 0;
		};

		static Shape BuildShape(const T& min, const T& max, const T& step);
		static ostream& PrintShape(ostream&)
	
	private:
		Shape & s;
		EvalFunc & f;
	};

	template <class T>
	Shape Evaluator<T>::BuildShape(const T& min, const T& max, const T& step)
	{
		vector<T> x, y;
		for (T i = min; i <= max; i += step)
		{
			y.push_back(f(i));
			x.push_back(i);
		}
		return Shape(x, y);
	}

	template <class T>
	ostream& Evaluator<T>::PrintShape(ostream& os)
	{
		os << '[';
		typename vector<T>::const_iterator it = s.first.begin();
		for (; it != s.first.end(); ++it)
			os << *it << ' ';
		os << ']';
		os << endl;
		os << '[';
		it = s.second.begin();
		for (; it != s.second.end(); ++it)
			os << *it << ' ';
		os << ']';
		return os;
	}
}
#endif // !EVALUATOR_H
