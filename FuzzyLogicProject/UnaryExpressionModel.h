#ifndef UNARY_EXPRESSION_MODEL_H
#define UNARY_EXPRESSION_MODEL_H
#include "UnaryExpression.h"
#include "Expression.h"

template <class T>
class UnaryExpressionModel : public UnaryExpression, public Expression
{
public:
	UnaryExpressionModel();
	~UnaryExpressionModel();

	T evaluate();
	T evaluate(const Expression& o);

private:
	UnaryExpression operator;
	Expression operand;
};

template<class T>
UnaryExpressionModel<T>::UnaryExpressionModel()
{
}

template<class T>
UnaryExpressionModel<T>::~UnaryExpressionModel()
{
}

template<class T>
T UnaryExpressionModel<T>::evaluate()
{
	if (operand != null)
		return evaluate(operand);
}

template<class T>
T UnaryExpressionModel<T>::evaluate(const Expression & o)
{
	if (operator != null)
		return operator.evaluate(o);
}

#endif 


