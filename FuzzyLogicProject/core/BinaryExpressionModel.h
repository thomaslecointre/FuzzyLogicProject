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
		BinaryExpressionModel(BinaryExpression<T> * __operator, Expression<T> * _left, Expression<T> * _right);
		BinaryExpressionModel(BinaryExpression<T> * __operator);
		virtual ~BinaryExpressionModel();

		virtual T evaluate() const;
		virtual T evaluate(Expression<T> * l, Expression<T> * r) const;

		BinaryExpression<T> * getOperator();
		Expression<T> * getLeft();
		Expression<T> * getRight();
	
	private:
		BinaryExpression<T> * _operator;
		Expression<T> * left;
		Expression<T> * right;
	};

	template<class T>
	BinaryExpressionModel<T>::BinaryExpressionModel()
	{
	}

	template<class T>
	BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* __operator, Expression<T>* _left, Expression<T>* _right) :
		_operator(__operator), left(_left), right(_right)
	{
	}

	template<class T>
	BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T> * __operator):
		_operator(__operator)
	{}

	template<class T>
	BinaryExpressionModel<T>::~BinaryExpressionModel()
	{
		delete _operator;
		delete left;
		delete right;
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate() const
	{
		if (left != NULL && right != NULL)
			return evaluate(left, right);
		else
			throw std::exception();
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T> * l, Expression<T> * r) const
	{
		if (_operator != NULL)
			return _operator->evaluate(l, r);
		else
			throw std::exception();
	}

	template<class T>
	BinaryExpression<T> * BinaryExpressionModel<T>::getOperator()
	{
		return _operator;
	}

	template<class T>
	Expression<T> * BinaryExpressionModel<T>::getLeft()
	{
		return left;
	}

	template<class T>
	Expression<T> * BinaryExpressionModel<T>::getRight()
	{
		return right;
	}
}
#endif


