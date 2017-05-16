#ifndef SUGENO_CONCLUSION_H
#define SUGENO_CONCLUSION_H

#include <vector>
#include "../core/CoreIncludes.h"

using namespace std;
using namespace core;

namespace fuzzy {
	template <class T>
	class SugenoConclusion : public NaryExpression<T>
	{
	public:
		SugenoConclusion();
		SugenoConclusion(typename vector<T> & _coeff);
		~SugenoConclusion();

		T evaluate(typename vector<Expression<T>*> * operands) const;
	private: 
		typename vector<T> coeff;
	};
	
	template<class T>
	SugenoConclusion<T>::SugenoConclusion()
	{
	}

	template<class T>
	SugenoConclusion<T>::SugenoConclusion(typename vector<T> & _coeff):
		coeff(_coeff)
	{}

	template<class T>
	SugenoConclusion<T>::~SugenoConclusion()
	{
	}

	template<class T>
	T SugenoConclusion<T>::evaluate(typename vector<Expression<T>*> * operands) const
	{
		typename vector<T>::const_iterator itCoeff = coeff.begin();
		typename vector<Expression<T>*>::const_iterator itExp = operands->begin();
		T result = 0;

		for (; itExp != operands->end() && itCoeff != coeff.end(); itExp++, itCoeff++) {
			T evaluation = (*itExp)->evaluate();
			result += *itCoeff * evaluation;
		}

		return result;
	}
}
#endif
