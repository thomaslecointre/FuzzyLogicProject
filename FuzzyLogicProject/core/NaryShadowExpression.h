#ifndef NARY_SHADOW_EXPRESSION
#define NARY_SHADOW_EXPRESSION

#include "CoreIncludes.h"

namespace core {
	template<class T>
	class NaryShadowExpression : public NaryExpression<T>
	{
	public:
		NaryShadowExpression();
		NaryShadowExpression(NaryExpression<T> * _target);
		~NaryShadowExpression();

		T evaluate(Expression<T>*[] operands) const;
		NaryExpression<T> * getTarget();
	private:
		NaryExpression<T> * target;
	};

	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression()
	{
	}

	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T> * _target):
		target(_target)
	{}

	template<class T>
	NaryShadowExpression<T>::~NaryShadowExpression()
	{
	}

	template<class T>
	inline T NaryShadowExpression<T>::evaluate(Expression<T>*[]operands) const
	{
		if (target != NULL)
			retrun target->evaluate(operands);
	}

	template<class T>
	inline NaryExpression<T>* NaryShadowExpression<T>::getTarget()
	{
		return target;
	}
}
#endif // !NARY_SHADOW_EXPRESSION
