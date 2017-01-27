#ifndef IS_H
#define IS_H
#include "../core/UnaryExpression.h"
using namespace core;
namespace fuzzy {
	template <class T>
	class Is : public UnaryExpression<T> {};
}
#endif // !IS_H
