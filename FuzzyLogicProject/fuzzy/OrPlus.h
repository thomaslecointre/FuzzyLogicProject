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
		return (l->evaluate() + r->evaluate());
	}
}



#endif // ORPLUS_H
