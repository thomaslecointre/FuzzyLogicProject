#ifndef MAMDANI_DEFUZZ_H
#define MAMDANI_DEFUZZ_H

#include "../core/BinaryExpression.h"
#include "../core/Expression.h"
#include "../evaluation/Evaluator.h"
#include "../evaluation/ExpressionEvaluator.h"
#include "../evaluation/Shape.h"
#include "../fuzzy/ThenMin.h"

using namespace core;
using namespace evaluation;

namespace fuzzy {
	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T>
	{
	public:
		MamdaniDefuzz();
		virtual ~MamdaniDefuzz() {};

		virtual T evaluate(Expression<T> * l, Expression<T> * r) const;
		virtual Shape<T> buildShape(const T& min, const T& max, const T& step, Expression<T> * l, Expression<T> * r) const;
		virtual T conclude() const = 0;
	};

	template <class T>
	MamdaniDefuzz<T>::MamdaniDefuzz()
	{

	}

	template <class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T> * l, Expression<T> * r) const
	{
		return ThenMin().evaluate(l, r);
	}

	template <class T>
	Shape<T> MamdaniDefuzz<T>::buildShape(const T& min, const T& max, const T& step, Expression<T> * l, Expression<T> * r) const
	{
		ExpressionEvaluator<T> le(l);
		ExpresssionEvaluator<T> re(r);

		Shape<T> leftShape(Evaluator<T>::BuildShape(min, max, step, le));
		Shape<T> rightShape(E)
		
	}
}

#endif // !MAMDANI_DEFUZZ_H
