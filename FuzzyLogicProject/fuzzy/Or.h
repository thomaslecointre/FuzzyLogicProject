#ifndef OR_H
#define OR_H
#include "../core/BinaryExpression.h"

using namespace core;
namespace fuzzy {
	template <class T>
	class Or : public BinaryExpression<T> {};
}

#endif // OR_H
