#ifndef IS_TRAPEZOID_H
#define IS_TRAPEZOID_H
#include "Is.h"
#include "../core/Expression.h"
using namespace core;
namespace fuzzy {
	template <class T>
	class IsTrapezoid : public Is<T>
	{
	public:
		IsTrapezoid();
		IsTrapezoid(const T & min, const T & mid1, const T & _mid2, const T & _max);
		virtual ~IsTrapezoid();

		virtual T evaluate(Expression<T> * o) const;
	private:
		T min, mid1, mid2, max;
	};

	template<class T>
	IsTrapezoid<T>::IsTrapezoid()
	{
	}

	template<class T>
	IsTrapezoid<T>::IsTrapezoid(const T & _min, const T & _mid1, const T & _mid2, const T & _max) :
		min(_min), mid1(_mid1), mid2(_mid2), max(_max)
	{
	}

	template<class T>
	IsTrapezoid<T>::~IsTrapezoid()
	{
	}

	template<class T>
	T IsTrapezoid<T>::evaluate(Expression<T>* o) const
	{
		T v = o->evaluate();
		if (v >= min && v <= max)
		{
			if (v <= mid1)
				return (v - min) / (mid1 - min);
			if (v >= mid2)
				return (max - v) / (max - mid2);
			return 1;
		}
		return 0;
	}
}
#endif