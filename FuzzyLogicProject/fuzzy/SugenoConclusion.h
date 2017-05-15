#ifndef SUGENO_CONCLUSION_H
#define SUGENO_CONCLUSION_H

#include <set>
#include "../core/CoreIncludes.h"

using namespace std;
using namespace core;

namespace fuzzy {
	template <class T>
	class SugenoConclusion : public NaryExpression<T>
	{
	public:
		SugenoConclusion();
		SugenoConclusion(set<T> _coeff);
		~SugenoConclusion();

		T evaluate(set<Expression<T>*> * operands) const;
	private: 
		set<T> coeff;
	};
	
	template<class T>
	SugenoConclusion<T>::SugenoConclusion()
	{
	}

	template<class T>
	SugenoConclusion<T>::SugenoConclusion(set<T> _coeff):
		coeff(_coeff)
	{}

	template<class T>
	SugenoConclusion<T>::~SugenoConclusion()
	{
	}

	template<class T>
	T SugenoConclusion<T>::evaluate(set<Expression<T>*> * operands) const
	{
		return T();
	}
}
#endif
