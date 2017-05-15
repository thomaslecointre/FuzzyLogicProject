#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

using namespace std;

namespace evaluation {
	template <class T>
	class Shape
	{
	public:
		Shape(const vector<T> &, const vector<T> &);
		Shape(const Shape<T> &);
		virtual ~Shape() {};

		typename vector<T>::const_iterator fBegin() const;
		typename vector<T>::const_iterator fEnd() const;
		typename vector<T>::const_iterator sBegin() const;
		typename vector<T>::const_iterator sEnd() const;

		const size_t size() const;

		ostream& PrintOn(ostream&) const;

	private:
		const vector<T> first;
		const vector<T> second;
	};

	template <class T>
	Shape<T>::Shape(const vector<T> & _first, const vector<T> & _second) :
		first(_first), second(_second)
	{

	}

	template <class T>
	Shape<T>::Shape(const Shape<T> & shape):
		first(shape.first), second(shape.second)
	{
	}

	template <class T>
	typename vector<T>::const_iterator Shape<T>::fBegin() const
	{
		return first.begin();
	}

	template <class T>
	typename vector<T>::const_iterator Shape<T>::fEnd() const
	{
		return first.end();
	}

	template <class T>
	typename vector<T>::const_iterator Shape<T>::sBegin() const
	{
		return second.begin();
	}

	template <class T>
	typename vector<T>::const_iterator Shape<T>::sEnd() const
	{
		return second.end();
	}

	template <class T>
	const size_t Shape<T>::size() const
	{
		return first.size();
	}

	template<class T>
	ostream& Shape<T>::PrintOn(ostream& os) const
	{
		/*
		os << '[';
		
		for (typename vector<T>::const_iterator itF = fBegin(); itF != fEnd(); itF++)
		{
			os << ' ' << *itF;
		}

		os << " ]" << endl;
		*/
		os << '[';
			
		for (typename vector<T>::const_iterator itS = sBegin(); itS != sEnd(); itS++)
		{
			os << ' ' << *itS;
		}

		os << " ]" << endl;

		return os;
	}
}

#endif // !SHAPE_H
