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
		virtual ~ThenMult();
		virtual T evaluate(Expression<T> *l, Expression<T> *r) const;
	};

	template<class T>
	ThenMult<T>::ThenMult() {

	}

	template<class T>
	ThenMult<T>::~ThenMult() {

	}

	template<class T>
	T ThenMult<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
		T l2 = l->evaluate();
		T r2 = r->evaluate();
		return (l2 * r2);
	}
}



#endif // THENMULT_H
