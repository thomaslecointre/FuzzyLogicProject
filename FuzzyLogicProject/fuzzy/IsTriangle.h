#ifndef IS_TRIANGLE_H
#define IS_TRIANGLE_H
#include "../core/Expression.h"
namespace fuzzy {
	template <class T>
	class IsTriangle : public Is<T>
	{
	public:
		IsTriangle();
		~IsTriangle();

		T evaluate(Expression * o) const;
	private:
		T min, mid, max;
	};

	template<class T>
	IsTriangle<T>::IsTriangle()
	{
	}

	template<class T>
	IsTriangle<T>::~IsTriangle()
	{
	}

	template<class T>
	T IsTriangle<T>::evaluate(Expression * o) const
	{
		T v = o->evaluate();
		if(v )
	}
}
#endif // !IS_TRIANGLE_H
