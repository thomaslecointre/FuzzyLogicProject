#ifndef IS_TRIANGLE_H
#define IS_TRIANGLE_H

#include "../core/Expression.h"
#include "Is.h"

using namespace core;

namespace fuzzy {
	template <class T>
	class IsTriangle : public Is<T>
	{
	public:
		IsTriangle();
		IsTriangle(const T& _min, const T& _mid, const T& _max);
		~IsTriangle();

		T evaluate(Expression<T> * o) const;
	private:
		T min, mid, max;
	};

	template<class T>
	IsTriangle<T>::IsTriangle()
	{
	}

	template<class T>
	IsTriangle<T>::IsTriangle(const T & _min, const T & _mid, const T & _max) :
		min(_min), mid(_mid), max(_max)
	{
	}

	template<class T>
	IsTriangle<T>::~IsTriangle()
	{
	}

	template<class T>
	T IsTriangle<T>::evaluate(Expression<T> * o) const
	{
		T v = o->evaluate();
		if(v >= min && v <= max) 
		{
			if(v > mid)
			{
				return (max - v) / (max - mid);
			}
			return (v - min) / (mid - min);
		}
		return 0;
	}
}
#endif // !IS_TRIANGLE_H
