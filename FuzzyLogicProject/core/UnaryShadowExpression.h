#ifndef UNARY_SHADOW_EXPRESSION_H
#define UNARY_SHADOW_EXPRESSION_H
#include "UnaryExpression.h"

namespace core {
	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T>
	{
	public:
		UnaryShadowExpression();
		UnaryShadowExpression(UnaryExpression<T> * _target);
		virtual ~UnaryShadowExpression() {};

		T evaluate(Expression<T> * o);

	private:
		UnaryExpression<T> * target;
	};
	
	template<class T>
	UnaryShadowExpression<T>::UnaryShadowExpression()
	{
	}
	
	template<class T>
	UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T> * _target):
		target(_target)
	{
	}

	template <class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T> * o)
	{
		if (target != null)
			return target->evaluate(o);
		return null;
	}
}

#endif