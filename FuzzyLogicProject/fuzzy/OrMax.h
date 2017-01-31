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
		~OrMax();
		T evaluate(Expression<T> *l, Expression<T> *r) const;
	};

	template<class T>
	OrMax<T>::OrMax() {

	}

	template<class T>
	OrMax<T>::~OrMax() {

	}

	template<class T>
	T OrMax<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
		return (l->evaluate() > r->evaluate()) ? l->evaluate() : r->evaluate();
	}
}



#endif // ORMAX_H
