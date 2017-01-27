#ifndef NOT_MINUS_1_H
#define NOT_MINUS_1_H
namespace fuzzy {
	template <class T>
	class NotMinus1 : public Not<T>
	{
	public:
		NotMinus1();
		~NotMinus1();
		
		T evaluate(Expression * o) const;
	};

	template<class T>
	NotMinus1<T>::NotMinus1()
	{
	}

	template<class T>
	NotMinus1<T>::~NotMinus1()
	{
	}

	template<class T>
	T NotMinus1<T>::evaluate(Expression * o) const
	{
		// TODO
		return T(); // false
	}
}
#endif // !NOT_MINUS_1_H
