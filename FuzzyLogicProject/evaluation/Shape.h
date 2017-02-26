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
		virtual ~Shape() {};

		typename vector<T>::const_iterator xBegin() const;
		typename vector<T>::const_iterator xEnd() const;
		typename vector<T>::const_iterator yBegin() const;
		typename vector<T>::const_iterator yEnd() const;

		const size_t size() const;

	private:
		const vector<T> x;
		const vector<T> y;
	};

	template <class T>
	Shape<T>::Shape(const vector<T> & _x, const vector<T> & _y) :
		x(_x), y(_y)
	{

	}

	template <class T>
	typename vector<T>::const_iterator Shape<T>::xBegin() const
	{
		return x.begin();
	}

	template <class T>
	typename vector<T>::const_iterator Shape<T>::xEnd() const
	{
		return x.end();
	}

	template <class T>
	typename vector<T>::const_iterator Shape<T>::yBegin() const
	{
		return y.begin();
	}

	template <class T>
	typename vector<T>::const_iterator Shape<T>::yEnd() const
	{
		return y.end();
	}

	template <class T>
	const size_t Shape<T>::size() const
	{
		return x.size();
	}
}

#endif // !SHAPE_H
