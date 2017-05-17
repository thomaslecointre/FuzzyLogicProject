#ifndef NARY_EXPRESSION_MODEL
#define NARY_EXPRESSION_MODEL

#include <vector>
#include "Expression.h"
#include "NaryExpression.h"

using namespace std;

namespace core {
	template<class T>
	class NaryExpressionModel : public Expression<T>, public NaryExpression<T>
	{
	public:
		NaryExpressionModel();
		NaryExpressionModel(NaryExpression<T> * __operator, typename vector<Expression<T>*> * _operands);
		~NaryExpressionModel();

		T evaluate() const;
		T evaluate(typename vector<Expression<T>*> * operands) const;
	private:
		NaryExpression<T> * _operator;
		typename vector<Expression<T>*> * operands;
	};

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel()
	{
	}

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* __operator, typename vector<Expression<T>*> * _operands):
		_operator(__operator), operands(_operands)
	{
	}

	template<class T>
	NaryExpressionModel<T>::~NaryExpressionModel()
	{
		delete _operator;
		for (vector<Expression<T> *>::iterator it = operands->begin(); it != operands->end(); ++it)
		{
			delete *it;
		}
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate() const
	{
		if (operands != NULL)
			return evaluate(operands);
		else
			throw std::exception();
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate(typename vector<Expression<T>*> * operands) const
	{
		if (_operator != NULL)
			return _operator->evaluate(operands);
		else
			throw std::exception();
	}
}
#endif // !NARY_EXPRESSION_MODEL
