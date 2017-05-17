#ifndef UNARY_EXPRESSION_MODEL_H
#define UNARY_EXPRESSION_MODEL_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core {
	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T>
	{
	public:
		UnaryExpressionModel();
		~UnaryExpressionModel();
		UnaryExpressionModel(UnaryExpression<T> * __operator, Expression<T> * _operand);

		T evaluate() const;
		T evaluate(Expression<T> * o) const;

		UnaryExpression<T> * getOperator();
		Expression<T> * getOperand();

	private:
		UnaryExpression<T> * _operator;
		Expression<T> * operand;
	};

	template<class T>
	UnaryExpressionModel<T>::UnaryExpressionModel()
	{
	}

	template<class T>
	UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T> * __operator, Expression<T> * _operand) :
		_operator(__operator), operand(_operand)
	{}

	template<class T>
	UnaryExpressionModel<T>::~UnaryExpressionModel()
	{
		delete _operator;
		delete operand;
	}

	template<class T>
	T UnaryExpressionModel<T>::evaluate() const
	{
		if (operand != nullptr)
			return evaluate(operand);
		else
			throw std::exception();
	}

	template<class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T> * o) const
	{
		if (_operator != nullptr)
			return _operator->evaluate(o);
		else
			throw std::exception();
	}

	template<class T>
	UnaryExpression<T> * UnaryExpressionModel<T>::getOperator()
	{
		return _operator;
	}
	
	template<class T>
	Expression<T> * UnaryExpressionModel<T>::getOperand()
	{
		return operand;
	}
}
#endif 


