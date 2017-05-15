#ifndef NARY_EXPRESSION_MODEL
#define NARY_EXPRESSION_MODEL

#include "CoreIncludes.h"

namespace core {
	template<class T>
	class NaryExpressionModel : public Expression<T>, public NaryExpression<T>
	{
	public:
		NaryExpressionModel();
		NaryExpressionModel(NaryExpression<T> * __operator, *Expression<T>[] _operands);
		~NaryExpressionModel();

		T evaluate() const;
		T evaluate(*Expression<T>[] operands) const;
	private:
		NaryExpression<T> * _operator;
		*Expression<T>[] operands;
	};

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel()
	{
	}

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* __operator, *Expression<T>[] _operands):
		_operator(__operator), operands(_operands)
	{
	}

	template<class T>
	NaryExpressionModel<T>::~NaryExpressionModel()
	{
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate() const
	{
		if (_operands != NULL)
			return evaluate(_operands);
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate(*Expression<T>[] operands) const
	{
		if (_operator != NULL)
			return _operator->evaluate(operands);
	}
}
#endif // !NARY_EXPRESSION_MODEL
