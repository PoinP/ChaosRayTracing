#ifndef SHAPE_H

#define SHAPE_H

#include "../Drawable.h"

class Shape : public Drawable
{
public:
	Shape(Point center)
		: m_Center(center) {}
	Shape(Point center, Color color)
		: m_Center(center), Drawable(color) {}
	virtual ~Shape() {}

protected:
	Point m_Center;
};

#endif // !SHAPE_H