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
		virtual ~AndMult();
		virtual T evaluate(Expression<T> *l, Expression<T> *r) const;
	};

	template<class T>
	AndMult<T>::AndMult() {

	}

	template<class T>
	AndMult<T>::~AndMult() {

	}

	template<class T>
	T AndMult<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		T l2 = l->evaluate();
		T r2 = r->evaluate();
		return (l2 * r2);
	}
}



#endif // ANDMULT_H
