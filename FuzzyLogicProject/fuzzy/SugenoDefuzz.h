#ifndef SUGENO_DEFUZZ_H
#define SUGENO_DEFUZZ_H

#include <set>
#include "../core/CoreIncludes.h"

using namespace std;
using namespace core;

namespace fuzzy {
	template <class T>
	class SugenoDefuzz : public NaryExpression<T>
	{
	public:
		T evaluate(set<Expression<T>*> * operands) const;
	};

	template<class T>
	T SugenoDefuzz<T>::evaluate(set<Expression<T>*> * operands) const
	{
		return T();
	}
}
#endif