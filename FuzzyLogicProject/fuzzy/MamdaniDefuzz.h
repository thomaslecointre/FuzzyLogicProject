#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "../core/CoreIncludes.h"
#include "../evaluation/EvaluationIncludes.h"
#include "../fuzzy/ThenMin.h"

using namespace core;
using namespace evaluation;

namespace fuzzy {
	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> 
	{
	public:
		MamdaniDefuzz();
		MamdaniDefuzz(const T & _min, const T & _max, const T & _step);
		virtual ~MamdaniDefuzz() {};
		
		virtual T evaluate(Expression<T> * l, Expression<T> * r) const = 0;

		virtual Shape<T> * buildShape(const T & _min, const T & _max, const T & _step, Expression<T> * l, Expression<T> * r) const;

		virtual void setMin(const T & _min);
		virtual void setMax(const T & _max);
		virtual void setStep(const T & _step);
	
	protected:
		T min, max, step;
	};

	template <class T>
	MamdaniDefuzz<T>::MamdaniDefuzz() 
	{

	}

	template <class T>
	MamdaniDefuzz<T>::MamdaniDefuzz(const T & _min, const T & _max, const T & _step) :
		min(_min), max(_max), step(_step) 
	{

	}

	// l = ValueModel, r = IsTriangle (?)
	template <class T>
	Shape<T> * MamdaniDefuzz<T>::buildShape(const T & _min, const T & _max, const T & _step, Expression<T> * l, Expression<T> * r) const
	{
		BinaryExpressionModel<T> bem(&ThenMin<T>(), l, r);
		return Evaluator<T>::buildShape(_min, _max, _step, &bem);
	}
	
	template <class T>
	void MamdaniDefuzz<T>::setMin(const T & _min)
	{
		min = _min;
	}

	template <class T>
	void MamdaniDefuzz<T>::setMax(const T & _max)
	{
		max = _max;
	}

	template <class T>
	void MamdaniDefuzz<T>::setStep(const T & _step)
	{
		step = _step;
	}
}

#endif // MAMDANIDEFUZZ_H
