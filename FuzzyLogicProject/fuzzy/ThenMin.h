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
		T l2 = l->evaluate();
		T r2 = r->evaluate();
		return (l2 <= r2) ? l2 : r2;
	}
}



#endif // THENMIN_H
