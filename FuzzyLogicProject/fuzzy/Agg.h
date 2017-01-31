#ifndef AGG_H
#define AGG_H
#include "../core/BinaryExpression.h"

using namespace core;
namespace fuzzy {
	template <class T>
	class Agg : public BinaryExpression<T> {};
}

#endif // AGG_H
