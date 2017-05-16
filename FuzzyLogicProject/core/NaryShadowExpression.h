#ifndef NARY_SHADOW_EXPRESSION
#define NARY_SHADOW_EXPRESSION

#include <vector>
#include "NaryExpression.h"
#include "Expression.h"

using namespace std;

namespace core {
	template<class T>
	class NaryShadowExpression : public NaryExpression<T>
	{
	public:
		NaryShadowExpression();
		NaryShadowExpression(NaryExpression<T> * _target);
		~NaryShadowExpression();

		T evaluate(typename vector<Expression<T>*> * operands) const;
		void setTarget(NaryExpression<T> * _target);
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
	T NaryShadowExpression<T>::evaluate(typename vector<Expression<T>*> * operands) const
	{
		if (target != NULL)
			return target->evaluate(operands);
		else
			return 0;
	}

	template<class T>
	void NaryShadowExpression<T>::setTarget(NaryExpression<T> * _target)
	{
		target = _target;
	}

	template<class T>
	NaryExpression<T>* NaryShadowExpression<T>::getTarget()
	{
		return target;
	}
}
#endif // !NARY_SHADOW_EXPRESSION
