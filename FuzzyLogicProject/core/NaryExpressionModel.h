#ifndef NARY_EXPRESSION_MODEL
#define NARY_EXPRESSION_MODEL

#include <set>
#include "Expression.h"
#include "NaryExpression.h"

using namespace std;

namespace core {
	template<class T>
	class NaryExpressionModel : public Expression<T>, public NaryExpression<T>
	{
	public:
		NaryExpressionModel();
		NaryExpressionModel(NaryExpression<T> * __operator, set<Expression<T>*> _operands);
		~NaryExpressionModel();

		T evaluate() const;
		T evaluate(set<Expression<T>*> operands) const;
	private:
		NaryExpression<T> * _operator;
		set<Expression<T>*> operands;
	};

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel()
	{
	}

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* __operator, set<Expression<T>*> _operands):
		_operator(__operator), operands(_operands)
	{
	}

	template<class T>
	NaryExpressionModel<T>::~NaryExpressionModel()
	{
		delete _operator;
		for (typename set<Expression<T> *>::iterator it = operands.begin(); it != operands.end(); ++it)
		{
			delete *it;
		}
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate() const
	{
		if (_operands != NULL)
			return evaluate(_operands);
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate(set<Expression<T>*> operands) const
	{
		if (_operator != NULL)
			return _operator->evaluate(operands);
	}
}
#endif // !NARY_EXPRESSION_MODEL
