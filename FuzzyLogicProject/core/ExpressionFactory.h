#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include <set>
#include "Expression.h"
#include "UnaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"

using namespace std;

namespace core {
	template <class T>
	class ExpressionFactory
	{
	public:
		ExpressionFactory();
		~ExpressionFactory();

		Expression<T> * hold(Expression<T> * e);
		Expression<T> * newUnary(UnaryExpression<T> * ope, Expression<T> * o);
		Expression<T> * newBinary(BinaryExpression<T> * ope, Expression<T> * l, Expression<T> * r);
	
	private:
		set<Expression<T> *> expressions;
	};

	template<class T>
	ExpressionFactory<T>::ExpressionFactory()
	{
	}

	template<class T>
	ExpressionFactory<T>::~ExpressionFactory()
	{
		for (typename set<Expression<T> *>::iterator it = expressions.begin(); it != expressions.end(); ++it)
		{
			delete *it;
		}
	}

	template <class T>
	Expression<T> * ExpressionFactory<T>::hold(Expression<T> * e)
	{
		expressions.insert(e);
		return e;
	}

	template <class T>
	Expression<T> * ExpressionFactory<T>::newUnary(UnaryExpression<T> * ope, Expression<T> * o)
	{
		return hold(UnaryExpressionModel(ope, o));
	}

	template <class T>
	Expression<T> * ExpressionFactory<T>::newBinary(BinaryExpression<T> * ope, Expression<T> * l, Expression<T> * r)
	{
		 return hold(BinaryExpressionModel(ope, l, r));
	}

}

#endif