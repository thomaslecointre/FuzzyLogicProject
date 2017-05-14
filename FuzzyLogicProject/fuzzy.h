#ifndef FUZZY_H
#define FUZZY_H

#ifndef NUMERIC
#define NUMERIC double
#endif // !NUMERIC

#include "core\CoreIncludes.h"
#include "evaluation\EvaluationIncludes.h"
#include "fuzzy\FuzzyIncludes.h"

#include "fuzzy\FuzzyFactory.h"

typedef fuzzy::AggMax<NUMERIC> _AggMax_;
typedef fuzzy::AggPlus<NUMERIC> _AggPlus_;
typedef fuzzy::AndMin<NUMERIC> _AndMin_;
typedef fuzzy::AndMult<NUMERIC> _AndMult_;
typedef fuzzy::CogDefuzz<NUMERIC> _CogDefuzz_;
typedef fuzzy::IsBell<NUMERIC> _IsBell_;
typedef fuzzy::IsGaussian<NUMERIC> _IsGaussian_;
typedef fuzzy::IsTrapezoid<NUMERIC> _IsTrapezoid_;
typedef fuzzy::IsTrapezoidLeft<NUMERIC> _IsTrapezoidLeft_;
typedef fuzzy::IsTrapezoidRight<NUMERIC> _IsTrapezoidRight_;
typedef fuzzy::IsTriangle<NUMERIC> _IsTriangle_;
typedef fuzzy::NotMinus1<NUMERIC> _NotMinus1_;
typedef fuzzy::OrMax<NUMERIC> _OrMax_;
typedef fuzzy::OrPlus<NUMERIC> _OrPlus_;
typedef fuzzy::ThenMin<NUMERIC> _ThenMin_;
typedef fuzzy::ThenMult<NUMERIC> _ThenMult_;

typedef fuzzy::FuzzyFactory<NUMERIC> _FuzzyFactory_;
typedef core::Expression<NUMERIC> _Expression_;
typedef core::ValueModel<NUMERIC> _ValueModel_;

#endif