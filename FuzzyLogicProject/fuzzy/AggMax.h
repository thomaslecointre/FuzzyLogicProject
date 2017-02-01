#ifndef AGGMAX_H
#define AGGMAX_H
#include "../core/BinaryExpression.h"
#include "Agg.h"

using namespace core;
namespace fuzzy {
	template <class T>
	class AggMax : public Agg<T>
	{
	public:
		AggMax();
		~AggMax();
		T evaluate(Expression<T> *l, Expression<T> *r) const;
	};

	template<class T>
	AggMax<T>::AggMax() {

	}

	template<class T>
	AggMax<T>::~AggMax() {

	}

	template<class T>
	T AggMax<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
		T l2 = l->evaluate();
		T r2 = r->evaluate();
		return (l2 > r2) ? l2 : r2;
	}
}



#endif // AGGMAX_H
