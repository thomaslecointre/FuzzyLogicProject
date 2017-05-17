#ifndef NOT_MINUS_1_H
#define NOT_MINUS_1_H

#include "../core/Expression.h"
#include "Not.h"

using namespace core;

namespace fuzzy {
	template <class T>
	class NotMinus1 : public Not<T>
	{
	public:
		NotMinus1();
		virtual ~NotMinus1();
		
		virtual T evaluate(Expression<T> * o) const;
	};

	template<class T>
	NotMinus1<T>::NotMinus1()
	{
	}

	template<class T>
	NotMinus1<T>::~NotMinus1()
	{
	}

	template<class T>
	T NotMinus1<T>::evaluate(Expression<T> * o) const
	{
		return 1 - o->evaluate();
	}
}
#endif // !NOT_MINUS_1_H
