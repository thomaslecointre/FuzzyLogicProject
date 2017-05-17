#ifndef IS_GAUSSIAN_H
#define IS_GAUSSIAN_H
#include "Is.h"
#include "../core/UnaryExpression.h"
#include <math.h>
using namespace core;
namespace fuzzy {
	template <class T>
	class IsGaussian : public Is<T>
	{
	public:
		IsGaussian();
		IsGaussian(const T & sdev, const T & expectedVal);
		virtual ~IsGaussian();

		virtual T evaluate(Expression<T> * o) const;
	private:
		T sdev, expectedVal;
	};

	template<class T>
	IsGaussian<T>::IsGaussian()
	{
	}

	template<class T>
	IsGaussian<T>::IsGaussian(const T & _sdev, const T & _expectedVal) :
		sdev(_sdev), expectedVal(_expectedVal)
	{
	}

	template<class T>
	IsGaussian<T>::~IsGaussian()
	{
	}

	template<class T>
	T IsGaussian<T>::evaluate(Expression<T>* o) const
	{
		T x = o->evaluate();
		return exp((-pow((x - expectedVal), 2.0)) / (2 * (pow(sdev, 2))));
	}
}
#endif
