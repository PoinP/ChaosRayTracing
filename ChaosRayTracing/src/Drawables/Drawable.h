#ifndef DRAWABLE_H

#define DRAWABLE_H

#include "../Core/Color.h"
#include "../Core/Point.h"

class Drawable
{
public:
	Drawable() {}
	Drawable(const Color& color)
		: m_Color(color) {}
	virtual ~Drawable() {}

	Color getColor() const { return m_Color; }
	void setColor(Color color) { m_Color = color; }

	virtual bool isHit(Point point) const = 0;
	virtual Drawable* clone() const = 0;

private:
	Color m_Color;
};

#endif // !DRAWABLE_H