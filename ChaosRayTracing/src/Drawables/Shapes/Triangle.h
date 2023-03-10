#ifndef TRIANGLE_H

#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(Point edges[3]);
	Triangle(Point edge1, Point edge2, Point edge3);

	Triangle(Point edges[3], Color color);
	Triangle(Point edge1, Point edge2, Point edge3, Color color);

	virtual bool isHit(Point point) const override;
	virtual Drawable* clone() override;

private:
	Point m_Edges[3];

	Point getCenter() const;
};

#endif // !TRIANGLE_H