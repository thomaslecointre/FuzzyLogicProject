#ifndef BINARY_SHADOW_EXPRESSION_H
#define BINARY_SHADOW_EXPRESSION_H
#include "BinaryExpression.h"

namespace core {
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T>
	{
	public:
		BinaryShadowExpression();
		BinaryShadowExpression(BinaryExpression<T> * _target);
		virtual ~BinaryShadowExpression() {};

		T evaluate(Expression<T> * o);

	private:
		BinaryExpression<T> * target;
	};

	template<class T>
	BinaryShadowExpression<T>::BinaryShadowExpression()
	{
	}

	template<class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T> * _target) :
		target(_target)
	{
	}

	template <class T>
	T BinaryShadowExpression<T>::evaluate(Expression<T> * o)
	{
		if (target != null)
			return target->evaluate(o);
		return null;
	}
}

#endif