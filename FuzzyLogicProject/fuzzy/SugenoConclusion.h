#ifndef SUGENO_CONCLUSION_H
#define SUGENO_CONCLUSION_H
#include "../core/CoreIncludes.h"
namespace fuzzy {
	template <class T>
	class SugenoConclusion : public NaryExpression<T>
	{
	public:
		virtual T evaluate(Expression<T>[] * o) const;

	private: 
		T[] coeff;
	};
}
#endif
