#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H
#include "../core/BinaryExpression.h"
#include "../core/BinaryExpressionModel.h"
#include "../evaluation/Evaluator.h"
#include "../fuzzy/ThenMin.h"

using namespace core;
namespace fuzzy {
	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> {
	public:
		MamdaniDefuzz();
		MamdaniDefuzz(T _min, T _max, T _step);
		~MamdaniDefuzz();
		
		T evaluate(Expression<T> *l, Expression<T> *r);
		
		Shape<T> buildShape(T _min, T _max, T _step, Expression<T> * l, Expression<T> * r);

		void setMin(T _min);
		void setMax(T _max);
		void setStep(T _step);
		
		virtual Defuzz() = 0;
	
	private:
		T min, max, step;
	};

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz() 
	{

	}

	template <class T>
	MamdaniDefuzz<T>::MamdaniDefuzz(T _min, T _max, T _step) :
		min(_min), max(_max), step(_step) 
	{

	}

	template<class T>
	MamdaniDefuzz<T>::~MamdaniDefuzz() 
	{

	}

	template<class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T> *l, Expression<T> *r) 
	{
		return;
	}

	// l = ValueModel, r = IsTriangle (?)
	template <class T>
	Shape<T> MamdaniDefuzz<T>::buildShape(T _min, T _max, T _step, Expression<T> * l, Expression<T> * r)
	{
		BinaryShadowExpression<T> bem(&ThenMin<T>(), l, r);
		return Evaluator<T>::BuildShape(_min, _max, _step, bem);
	}
	
	template <class T>
	void MamdaniDefuzz<T>::setMin(T _min)
	{
		min = _min;
	}

	template <class T>
	void MamdaniDefuzz<T>::setMax(T _max)
	{
		max = _max;
	}

	template <class T>
	void MamdaniDefuzz<T>::setStep(T _step)
	{
		step = _step;
	}
}

#endif // MAMDANIDEFUZZ_H
