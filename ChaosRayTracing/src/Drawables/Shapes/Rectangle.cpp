#include "Rectangle.h"

Rectangle::Rectangle(Point center, unsigned width, unsigned height)
    : Shape(center, Color(255, 255, 255)), m_SideX(width), m_SideY(height)
{
}

Rectangle::Rectangle(Point center, unsigned width, unsigned height, Color color)
    : Shape(center, color), m_SideX(width), m_SideY(height)
{
}

bool Rectangle::isHit(Point point) const
{
    int xDiff = abs(int(point.x() - m_Center.x()));
    int yDiff = abs(int(point.y() - m_Center.y()));

    return xDiff * 2 <= m_SideX && yDiff * 2 <= m_SideY;
}

Drawable* Rectangle::clone() const
{
    return new Rectangle(*this);
}
