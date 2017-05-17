#ifndef ORMAX_H
#define ORMAX_H

#include "../core/BinaryExpression.h"
#include "Or.h"

using namespace core;

namespace fuzzy {
	template <class T>
	class OrMax : public Or<T>
	{
	public:
		OrMax();
		virtual ~OrMax();
		
		virtual T evaluate(Expression<T> *l, Expression<T> *r) const;
	};

	template<class T>
	OrMax<T>::OrMax() {

	}

	template<class T>
	OrMax<T>::~OrMax() {

	}

	template<class T>
	T OrMax<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
		T l2 = l->evaluate();
		T r2 = r->evaluate();
		return (l2 > r2) ? l2 : r2;
	}
}



#endif // ORMAX_H
