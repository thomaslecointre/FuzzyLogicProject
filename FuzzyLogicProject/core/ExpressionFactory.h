#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H
#include "Expression.h"
#include "UnaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"
using namespace std;

namespace core {
	template <class T>
	class 
	{
	public:
		ExpressionFactory();
		virtual ~ExpressionFactory() {};

		Expression<T> hold(Expression<T>);
		Expression<T> newUnary(UnaryExpression<T>, Expression<T>);
		Expression<T> newBinary(BinaryExpression<T>, Expression<T>, Expression<T>);
	};

	template <class T>
	ExpressionFactory<T>::ExpressionFactory() :
	{

	}

	template <class T>
	Expression<T> ExpressionFactory<T>::hold(Expression<T> o)
	{
		//return;
	}

	template <class T>
	Expression<T> ExpressionFactory<T>::newUnary(UnaryExpression<T> ope, Expression<T> o)
	{
		return new UnaryExpressionModel(ope, e);
	}

	template <class T>
	 Expression<T> ExpressionFactory<T>::newUnary(BinaryExpression<T> ope, Expression<T> l, Expression<T> r)
	{
		 return new BinaryExpressionModel(ope, l, r);
	}
}


#endif