#include "Circle.h"

Circle::Circle(Point center, unsigned radius)
	: Shape(center, Color(255, 255, 255)), m_Radius(radius)
{
}

Circle::Circle(Point center, unsigned radius, Color color)
	: Shape(center, color), m_Radius(radius)
{
}

bool Circle::isHit(Point coord) const
{
	Point distance = coord - m_Center;
	int distanceSquared = dotProduct(distance, distance);

	return distanceSquared <= ((long long)m_Radius * m_Radius);
}

Circle* Circle::clone()
{
	return new Circle(*this);
}
