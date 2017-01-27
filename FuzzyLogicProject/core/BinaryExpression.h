#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H
#include "Expression.h"
namespace core {
	template <class T>
	class BinaryExpression
	{
	public:
		virtual T evaluate(Expression * l, Expression * r) const = 0;
	};
}
#endif