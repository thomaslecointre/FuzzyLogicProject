#ifndef NARY_EXPRESSION_H
#define NARY_EXPRESSION_H
#include "Expression.h"
namespace core {
	template <class T>
	class NaryExpression
	{
	public:
		virtual T evaluate(Expression<T>[] * l) const = 0;
	};
}
#endif