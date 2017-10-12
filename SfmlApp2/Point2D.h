#pragma once
template<class T> class Point2D
{
public:
	T x, y;


	Point2D() {}

	Point2D(T x, T y)
	{
		this->x = x;
		this->y = y;
	}
	~Point2D() {}
};

typedef Point2D<int> Point2Di;
typedef Point2D<float> Point2Df;
typedef Point2D<unsigned int> Point2Du;