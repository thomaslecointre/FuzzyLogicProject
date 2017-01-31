#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H
#include "../core/BinaryExpression.h"

using namespace core;
namespace fuzzy {
	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> {
	public:
		MamdaniDefuzz();
		~MamdaniDefuzz();
		T evaluate(Expression<T> *l, Expression<T> *r);
	private:
	
	};

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz() {

	}

	template<class T>
	MamdaniDefuzz<T>::~MamdaniDefuzz() {

	}

	template<class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T> *l, Expression<T> *r) {
		return;
	}
}

#endif // MAMDANIDEFUZZ_H
