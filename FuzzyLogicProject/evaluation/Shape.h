#ifndef SHAPE_H
#define SHAPE_H

namespace evaluation {
	template <class T>
	class Shape
	{
	public:
		Shape(vector<T>, vector<T>);
	private:
		pair<vector<T>, vector<T>> _pair;
	};
}

#endif // !SHAPE_H
