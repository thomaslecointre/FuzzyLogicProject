#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H
#include "Expression.h"

template <class T>
class BinaryExpression
{
public:
	virtual T evaluate(const Expression& l, const Expression& r) = 0;
};
#endif