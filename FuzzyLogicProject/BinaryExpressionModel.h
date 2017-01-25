#ifndef BINARY_EXPRESSION_MODEL_H
#define	BINARY_EXPRESSION_MODEL_H
#include "BinaryExpression.h"
#include "Expression.h"

template <class T>
class BinaryExpressionModel: public BinaryExpression, public Expression
{
public:
	BinaryExpressionModel();
	~BinaryExpressionModel();
	T evaluate();
	T evaluate(const Expression& l, const Expression& r);
private:
	BinaryExpression operator;
	Expression left;
	Expression right;
};

template<class T>
BinaryExpressionModel<T>::BinaryExpressionModel()
{
}

template<class T>
BinaryExpressionModel<T>::~BinaryExpressionModel()
{
}

template<class T>
T BinaryExpressionModel<T>::evaluate()
{
	if (left != null && right != null)
		return evaluate(left, right);
}

template<class T>
T BinaryExpressionModel<T>::evaluate(const Expression & l, const Expression & r)
{
	if (operator != null)
		return operator.evaluate(l, r);
}

#endif


