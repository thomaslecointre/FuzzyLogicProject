#ifndef BINARY_EXPRESSION_MODEL_H
#define	BINARY_EXPRESSION_MODEL_H
#include "BinaryExpression.h"
#include "Expression.h"
namespace core {
	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T>
	{
	public:
		BinaryExpressionModel();
		~BinaryExpressionModel();

		T evaluate() const;
		T evaluate(Expression<T> * l, Expression<T> * r) const;
	private:
		BinaryExpression * operator;
		Expression * left;
		Expression * right;
	};

	template<class T>
	BinaryExpressionModel<T>::BinaryExpressionModel()
	{
	}

	template<class T>
	BinaryExpressionModel<T>::~BinaryExpressionModel()
	{
		delete operator;
		delete left;
		delete right;
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate() const
	{
		if (left != null && right != null)
			return evaluate(left, right);
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T> * l, Expression<T> * r) const
	{
		if (operator != null)
			return operator.evaluate(l, r);
	}
}
#endif


