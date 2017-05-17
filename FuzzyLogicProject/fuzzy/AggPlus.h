#ifndef AGGPLUS_H
#define AGGPLUS_H
#include "../core/BinaryExpression.h"
#include "Agg.h"

using namespace core;
namespace fuzzy {
	template <class T>
	class AggPlus : public Agg<T>
	{
	public:
		AggPlus();
		~AggPlus();
		virtual T evaluate(Expression<T> *l, Expression<T> *r) const;
	};

	template<class T>
	AggPlus<T>::AggPlus() {

	}

	template<class T>
	AggPlus<T>::~AggPlus() {

	}

	template<class T>
	T AggPlus<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
		T l2 = l->evaluate();
		T r2 = r->evaluate();
		return (l2 + r2);
	}
}



#endif // AGGPLUS_H
