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

		T evaluate() const;
		T evaluate(Expression<T> * o) const;

	private:
		UnaryExpression * _operator;
		Expression * operand;
	};

	template<class T>
	UnaryExpressionModel<T>::UnaryExpressionModel()
	{
	}

	template<class T>
	UnaryExpressionModel<T>::~UnaryExpressionModel()
	{
		delete _operator;
		delete operand;
	}

	template<class T>
	T UnaryExpressionModel<T>::evaluate() const
	{
		if (operand != null)
			return evaluate(operand);
	}

	template<class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T> * o) const
	{
		if (_operator != null)
			return _operator.evaluate(o);
	}
}
#endif 


