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
		T evaluate(Expression<T> *l, Expression<T> *r) const;
	};

	template<class T>
	AggPlus<T>::AggPlus() {

	}

	template<class T>
	AggPlus<T>::~AggPlus() {

	}

	template<class T>
	T AggPlus<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
		return (l->evaluate() + r->evaluate());
	}
}



#endif // AGGPLUS_H
