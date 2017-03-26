#ifndef AND_H
#define AND_H

#include "../core/BinaryExpression.h"

using namespace core;

namespace fuzzy {
	template <class T>
	class And : public BinaryExpression<T> {};
}

#endif // AND_H
