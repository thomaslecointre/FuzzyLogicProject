#ifndef UNARY_SHADOW_EXPRESSION_H
#define UNARY_SHADOW_EXPRESSION_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core {
	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T>
	{
	public:
		UnaryShadowExpression();
		UnaryShadowExpression(UnaryExpression<T> * _target);
		virtual ~UnaryShadowExpression();

		virtual T evaluate(Expression<T> * o) const;

		UnaryExpression<T> * getTarget();
		void setTarget(UnaryExpression<T> * _target);

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
	UnaryShadowExpression<T>::~UnaryShadowExpression()
	{
		delete target;
	}

	template <class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T> * o) const
	{
		if (target != NULL)
			return target->evaluate(o);
		else
			throw std::exception();
	}

	template <class T>
	void UnaryShadowExpression<T>::setTarget(UnaryExpression<T> * _target)
	{
		target = _target;
	}

	template <class T>
	UnaryExpression<T> * UnaryShadowExpression<T>::getTarget()
	{
		return target;
	}
}

#endif