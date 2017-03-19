#ifndef UNARY_SHADOW_EXPRESSION_H
#define UNARY_SHADOW_EXPRESSION_H
#include "UnaryExpression.h"

namespace core {
	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T>
	{
	public:
		UnaryShadowExpression();
		UnaryShadowExpression(UnaryExpression<T> _target);
		virtual ~UnaryShadowExpression();

		T evaluate(Expression<T> * o);

	private:
		UnaryExpression<T> target;
	};
}

#endif