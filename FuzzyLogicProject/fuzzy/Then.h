#ifndef THEN_H
#define THEN_H
#include "../core/BinaryExpression.h"

using namespace core;
namespace fuzzy {
	template <class T>
	class Then : public BinaryExpression<T> {};
}

#endif // THEN_H
