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
	private:

	};

	template<class T>
	AndMin<T>::AndMin() {

	}

	template<class T>
	AndMin<T>::~AndMin() {

	}

	template<class T>
	T AndMin<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
		return (l->evaluate() < r->evaluate()) ? l->evaluate() : r->evaluate();
	}
}



#endif // ANDMIN_H
