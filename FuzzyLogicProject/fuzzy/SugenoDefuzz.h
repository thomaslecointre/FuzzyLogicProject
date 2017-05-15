#ifndef SUGENO_DEFUZZ_H
#define SUGENO_DEFUZZ_H
#include "../core/CoreIncludes.h"
namespace fuzzy {
	template <class T>
	class SugenoDefuzz : public NaryExpression<T>
	{
	public:
		virtual T evaluate(Expression<T>[] * o) const;
	};
}
#endif