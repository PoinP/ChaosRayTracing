#ifndef RECTANGLE_H

#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(Point center, unsigned width, unsigned height);
	Rectangle(Point center, unsigned width, unsigned height, Color color);

	virtual bool isHit(Point point) const override;
	virtual Drawable* clone() override;

private:
	int m_SideX;
	int m_SideY;
};

#endif // !RECTANGLE_H