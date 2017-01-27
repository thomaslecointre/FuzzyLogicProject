#ifndef VALUE_MODEL_H
#define VALUE_MODEL_H
#include "Expression.h"
namespace core {
	template <class T>
	class ValueModel : public Expression<T>
	{
	public:
		ValueModel();
		ValueModel(T v);
		~ValueModel();
		T evaluate() const;
		void setValue(const T& v);
	private:
		T value;
	};

	template<class T>
	ValueModel<T>::ValueModel()
	{
	}

	template<class T>
	ValueModel<T>::ValueModel(T v) :
		value(v)
	{
	}

	template<class T>
	ValueModel<T>::~ValueModel()
	{
	}

	template<class T>
	T ValueModel<T>::evaluate() const
	{
		return value;
	}

	template<class T>
	void ValueModel<T>::setValue(const T& v)
	{
		value = v;
	}
}
#endif


