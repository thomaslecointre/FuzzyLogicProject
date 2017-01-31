#ifndef ANDMULT_H
#define ANDMULT_H
#include "../core/BinaryExpression.h"
#include "And.h"

using namespace core;
namespace fuzzy {
	template <class T>
	class AndMult : public And<T>
	{
	public:
		AndMult();
		~AndMult();
		T evaluate(Expression<T> *l, Expression<T> *r) const;
	};

	template<class T>
	AndMult<T>::AndMult() {

	}

	template<class T>
	AndMult<T>::~AndMult() {

	}

	template<class T>
	T AndMult<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		return (l->evaluate() * r->evaluate());
	}
}



#endif // ANDMULT_H
