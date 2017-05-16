#ifndef NARY_EXPRESSION_H
#define NARY_EXPRESSION_H

#include <vector>
#include "Expression.h"

using namespace std;

namespace core {
	template <class T>
	class NaryExpression
	{
	public:
		virtual T evaluate(typename vector<Expression<T>*> * operands) const = 0;
	};
}
#endif