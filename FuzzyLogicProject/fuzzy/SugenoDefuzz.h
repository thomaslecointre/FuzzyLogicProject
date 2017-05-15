#ifndef SUGENO_DEFUZZ_H
#define SUGENO_DEFUZZ_H
#include "../core/CoreIncludes.h"
namespace fuzzy {
	template <class T>
	class SugenoDefuzz : public NaryExpression<T>
	{
	public:
		T evaluate(Expression<T>*[] o) const;
	};

	template<class T>
	T SugenoDefuzz<T>::evaluate(Expression<T>*[] o) const
	{

		return T();
	}
}
#endif