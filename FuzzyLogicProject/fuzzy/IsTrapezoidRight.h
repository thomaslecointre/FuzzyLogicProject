#ifndef IS_TRAPEZOID_RIGHT_H
#define IS_TRAPEZOID_RIGHT_H
#include "../core/Expression.h"
#include "Is.h"
using namespace core;
namespace fuzzy {
	template <class T>
	class IsTrapezoidRight : public Is<T>
	{
	public:
		IsTrapezoidRight();
		IsTrapezoidRight(const T& _mid2, const T& _max);
		virtual ~IsTrapezoidRight();

		virtual T evaluate(Expression<T> * o) const;
	private:
		T min, mid1, max;
	};

	template<class T>
	IsTrapezoidRight<T>::IsTrapezoidRight()
	{
	}

	template<class T>
	IsTrapezoidRight<T>::IsTrapezoidRight(const T & _min, const T & _mid1) :
		mid1(_mid1), max(100), min(_min) // ?
	{
	}

	template<class T>
	IsTrapezoidRight<T>::~IsTrapezoidRight()
	{
	}

	template<class T>
	T IsTrapezoidRight<T>::evaluate(Expression<T>* o) const
	{
		T v = o->evaluate();
		if (v >= min && v <= max)
		{
			if (v <= mid1)
				return (v - min) / (mid1 - min);
			return 1;
		}
		return 0;
	}
}
#endif