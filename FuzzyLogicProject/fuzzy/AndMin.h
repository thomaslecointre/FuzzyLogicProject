#ifndef ANDMIN_H
#define ANDMIN_H

#include "../core/BinaryExpression.h"
#include "And.h"

using namespace core;

namespace fuzzy {
	template <class T>
	class AndMin : public And<T> 
	{
	public: 
		AndMin();
		~AndMin();
		T evaluate(Expression<T> *l, Expression<T> *r) const;
	};

	template<class T>
	AndMin<T>::AndMin() {

	}

	template<class T>
	AndMin<T>::~AndMin() {

	}

	template<class T>
	T AndMin<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
		T l2 = l->evaluate();
		T r2 = r->evaluate();
		return (l2 <= r2) ? l2 : r2;
	}
}



#endif // ANDMIN_H
