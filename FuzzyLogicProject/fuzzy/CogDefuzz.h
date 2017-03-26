#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H
#include "../core/BinaryExpression.h"
#include "MamdaniDefuzz.h"

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

	// l = ValueModel, r = Agg
	template <class T>
	T CogDefuzz<T>::evaluate(Expression<T> *l, Expression<T> *r) const
	{
		Shape<T> * shape = buildShape(min, max, step, l, r);

		// Determine how much area there is within the shape

		T area = 0;
		T leftSide;
		T rightSide;
		vector<T>::const_iterator itS = shape->sBegin();
		vector<T>::const_iterator itF = shape->fBegin();

		for (;itF != shape->fEnd(); itF++)
		{
			leftSide = *itS;
			rightSide = *(++itS);
			area += (1.0f / 2.0f) * (leftSide + rightSide);
		}

		// Find x coordinate of COG

		T halfway = area / 2.0f;
		area = 0;
		T fCoord;
		itS = shape->sBegin();

		for (itF = shape->fBegin(); itF != shape->fEnd(); itF++)
		{
			if (area > halfway)
			{
				fCoord = *itF;
				break;
			}
			leftSide = *itS;
			rightSide = *(++itS);
			area += (1.0f / 2.0f) * (leftSide + rightSide);
		}
		
		return fCoord;
	}
}



#endif // COGDEFUZZ_H
