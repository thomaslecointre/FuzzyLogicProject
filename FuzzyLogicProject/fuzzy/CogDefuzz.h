#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H
#include "../core/BinaryExpression.h"
#include "MamdaniDefuzz.h"

using namespace core;
namespace fuzzy {
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T>
	{
	public:
		CogDefuzz();
		~CogDefuzz();
		T evaluate(Expression<T> *l, Expression<T> *r);
	};

	template<class T>
	CogDefuzz<T>::CogDefuzz() {

	}

	template<class T>
	CogDefuzz<T>::~CogDefuzz() {

	}

	template<class T>
	T CogDefuzz<T>::evaluate(Expression<T> *l, Expression<T> *r) {
		return;
	}
}



#endif // COGDEFUZZ_H
