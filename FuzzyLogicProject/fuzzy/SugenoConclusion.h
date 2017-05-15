#ifndef SUGENO_CONCLUSION_H
#define SUGENO_CONCLUSION_H

#include "../core/CoreIncludes.h"

namespace fuzzy {
	template <class T>
	class SugenoConclusion : public NaryExpression<T>
	{
	public:
		SugenoConclusion();
		~SugenoConclusion();

		T evaluate(Expression<T>*[] o) const;
	private: 
		T[] coeff;
	};
	
	template<class T>
	SugenoConclusion<T>::SugenoConclusion()
	{
	}

	template<class T>
	SugenoConclusion<T>::~SugenoConclusion()
	{
	}

	template<class T>
	T SugenoConclusion<T>::evaluate(Expression<T>*[]o) const
	{
		return T();
	}
}
#endif
