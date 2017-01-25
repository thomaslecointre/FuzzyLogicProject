#ifndef UNARY_EXPRESSION_H
#define UNARY_EXPRESSION_H
#include "Expression.h"
 
template <class T>
class UnaryExpression
{
public:
	virtual T evaluate(const Expression& o) = 0;
};

#endif