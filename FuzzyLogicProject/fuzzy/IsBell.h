#ifndef IS_BELL_H
#define IS_BELL_H
#include "Is.h"
#include "../core/UnaryExpression.h"
#include <math.h>
using namespace core;
namespace fuzzy {
	template <class T>
	class IsBell : public Is<T>
	{
	public:
		IsBell();
		IsBell(const T & a, const T & b, const T & c);
		~IsBell();

		T evaluate(Expression<T> * o) const;
	private:
		T a, b, c;
	};

	template<class T>
	IsBell<T>::IsBell()
	{
	}

	template<class T>
	IsBell<T>::IsBell(const T & _a, const T & _b, const T & _c) :
		a(_a), b(_b), c(_c)
	{
	}

	template<class T>
	IsBell<T>::~IsBell()
	{
	}

	template<class T>
	T IsBell<T>::evaluate(Expression<T>* o) const
	{
		T x = o->evaluate();
		return 1 / (1 + pow(abs((x - c) / a), 2 * b));
	}
}
#endif
