#ifndef THENMIN_H
#define THENMIN_H
#include "../core/BinaryExpression.h"
#include "Then.h"

using namespace core;
namespace fuzzy {
	template <class T>
	class ThenMin : public Then<T>
	{
	public:
		ThenMin();
		~ThenMin();
		T evaluate(Expression<T> *l, Expression<T> *r) const;
	};

	template<class T>
	ThenMin<T>::ThenMin() {

	}

	template<class T>
	ThenMin<T>::~ThenMin() {

	}

	template<class T>
	T ThenMin<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
		return (l->evaluate() < r->evaluate()) ? l->evaluate() : r->evaluate();
	}
}



#endif // THENMIN_H
