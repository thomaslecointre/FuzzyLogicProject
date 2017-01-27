#ifndef NOT_H
#define NOT_H
#include "../core/UnaryExpression.h"
namespace fuzzy {
	template <class T>
	class Not : public UnaryExpression<T> {};
}
#endif // !NOT_H
