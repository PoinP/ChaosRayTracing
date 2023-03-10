#ifndef CIRCLE_H

#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(Point center, unsigned radius);
	Circle(Point center, unsigned radius, Color color);

	bool isHit(Point coord) const override;
	Circle* clone() const override;

private:
	unsigned m_Radius;
};

#endif // !CIRCLE_H