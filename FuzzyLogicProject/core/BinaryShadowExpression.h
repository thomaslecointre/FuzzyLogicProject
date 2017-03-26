#ifndef BINARY_SHADOW_EXPRESSION_H
#define BINARY_SHADOW_EXPRESSION_H

#include "Expression.h"
#include "BinaryExpression.h"

namespace core {
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T>
	{
	public:
		BinaryShadowExpression();
		BinaryShadowExpression(BinaryExpression<T> * _target);
		virtual ~BinaryShadowExpression();

		virtual T evaluate(Expression<T> * l, Expression<T> * r) const;

		void setTarget(Expression<T> * _target);
		BinaryExpression<T> * getTarget();

	private:
		BinaryExpression<T> * target;
	};

	template <class T>
	BinaryShadowExpression<T>::BinaryShadowExpression()
	{
	}

	template <class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T> * _target) :
		target(_target)
	{
	}

	template <class T>
	BinaryShadowExpression<T>::~BinaryShadowExpression()
	{
		delete target;
	}

	template <class T>
	T BinaryShadowExpression<T>::evaluate(Expression<T> * l, Expression<T> * r) const
	{
		if (target != NULL)
			return target->evaluate(l, r);
		return NULL;
	}

	template <class T>
	void BinaryShadowExpression<T>::setTarget(Expression<T> * _target)
	{
		target = _target;
	}

	template<class T>
	BinaryExpression<T> * BinaryShadowExpression<T>::getTarget()
	{
		return target;
	}
}

#endif