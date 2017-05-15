#ifndef NARY_EXPRESSION_H
#define NARY_EXPRESSION_H

#include <set>
#include "Expression.h"

using namespace std;

namespace core {
	template <class T>
	class NaryExpression
	{
	public:
		virtual T evaluate(set<Expression<T>*> * operands) const = 0;
	};
}
#endif