#ifndef IS_TRAPEZOID_LEFT_H
#define IS_TRAPEZOID_LEFT_H
#include "../core/Expression.h"
#include "Is.h"
using namespace core;
namespace fuzzy {
	template <class T>
	class IsTrapezoidLeft : public Is<T>
	{
	public:
		IsTrapezoidLeft();
		IsTrapezoidLeft(const T& _mid2, const T& _max);
		~IsTrapezoidLeft();

		T evaluate(Expression<T> * o) const;
	private:
		T min, mid2, max;
	};

	template<class T>
	IsTrapezoidLeft<T>::IsTrapezoidLeft()
	{
	}

	template<class T>
	IsTrapezoidLeft<T>::IsTrapezoidLeft(const T & _mid2, const T & _max):
		mid2(_mid2), max(_max), min(0)
	{
	}

	template<class T>
	IsTrapezoidLeft<T>::~IsTrapezoidLeft()
	{
	}

	template<class T>
	T IsTrapezoidLeft<T>::evaluate(Expression<T>* o) const
	{
		T v = o->evaluate();
		if(v >= mid2 && v <= max)
		{
			if (v >= mid2)
				return (max - v) / (max - mid2);
			return 1;
		}
		return 0;
	}
}
#endif