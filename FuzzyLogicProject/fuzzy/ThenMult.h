#ifndef THENMULT_H
#define THENMULT_H
#include "../core/BinaryExpression.h"
#include "Then.h"

using namespace core;
namespace fuzzy {
	template <class T>
	class ThenMult : public Then<T>
	{
	public:
		ThenMult();
		~ThenMult();
		T evaluate(Expression<T> *l, Expression<T> *r) const;
	};

	template<class T>
	ThenMult<T>::ThenMult() {

	}

	template<class T>
	ThenMult<T>::~ThenMult() {

	}

	template<class T>
	T ThenMult<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
		return (l->evaluate() * r->evaluate());
	}
}



#endif // THENMULT_H
