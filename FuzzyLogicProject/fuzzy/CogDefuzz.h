#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "../core/BinaryExpression.h"
#include "MamdaniDefuzz.h"

#include <numeric>

using namespace core;
using namespace evaluation;

namespace fuzzy {
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T>
	{
	public:
		CogDefuzz();
		virtual ~CogDefuzz() {};

		virtual T evaluate(Expression<T> * l, Expression<T> * r) const;
	};

	template <class T>
	CogDefuzz<T>::CogDefuzz() 
	{

	}

	// l = tips, r = agg (BinaryExpressionModel)
	template <class T>
	T CogDefuzz<T>::evaluate(Expression<T> * l, Expression<T> * r) const
	{
		Shape<T> * shape = Evaluator<T>::buildShape(min, max, step, l, (BinaryExpressionModel<T>*)r);

		// Determine how much area there is within the shape

		double area = 0;
		
		double leftSide;
		double rightSide;
		vector<T>::const_iterator itS = shape->sBegin();
		vector<T>::const_iterator itF = shape->fBegin();
		
		for (;itF != shape->fEnd(); itF++)
		{
			if (++itF != shape->fEnd()) 
			{
				leftSide = *itS;
				rightSide = *(++itS);
				itF--;
			}
			else 
			{
				break;
			}
			
			area += (1.0 / 2.0) * (leftSide + rightSide) * step;
		}
		
		// Find x coordinate of COG

		
		double halfway = area / 2.0;
		
		area = 0.0;
		T fCoord = 0;
		itS = shape->sBegin();

		for (itF = shape->fBegin(); itF != shape->fEnd(); itF++)
		{
			if (area > halfway)
			{
				fCoord = *itF;
				break;
			}
			if (++itF != shape->fEnd())
			{
				leftSide = *itS;
				rightSide = *(++itS);
				itF--;
				area += (1.0 / 2.0) * (leftSide + rightSide) * step;
			}
			else
			{
				break;
			}
		}
		
		return fCoord;
	}
}



#endif // COGDEFUZZ_H
