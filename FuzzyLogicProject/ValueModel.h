#ifndef VALUE_MODEL_H
#define VALUE_MODEL_H
#include "Expression.h"

template <class T>
class ValueModel: public Expression
{
public:
	ValueModel();
	ValueModel(T v);
	~ValueModel();
	T evaluate();
	void setValue(T v);
private:
	T value;
};

template<class T>
ValueModel<T>::ValueModel()
{
}

template<class T>
ValueModel<T>::ValueModel(T v):
	value(v)
{
}

template<class T>
ValueModel<T>::~ValueModel()
{
}

template<class T>
T ValueModel<T>::evaluate()
{
	return value;
}

template<class T>
void ValueModel<T>::setValue(T v)
{
	value = v;
}

#endif


