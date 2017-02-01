#ifndef ORPLUS_H
#define ORPLUS_H
#include "../core/BinaryExpression.h"
#include "Or.h"

using namespace core;
namespace fuzzy {
	template <class T>
	class OrPlus : public Or<T>
	{
	public:
		OrPlus();
		~OrPlus();
		T evaluate(Expression<T> *l, Expression<T> *r) const;
	};

	template<class T>
	OrPlus<T>::OrPlus() {

	}

	template<class T>
	OrPlus<T>::~OrPlus() {

	}

	template<class T>
	T OrPlus<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
		T l2 = l->evaluate();
		T r2 = r->evaluate();
		return (l2 + r2);
	}
}



#endif // ORPLUS_H
