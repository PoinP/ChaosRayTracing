#include "Triangle.h"

Triangle::Triangle(Point edges[3])
    : Triangle(edges[0], edges[1], edges[2])
{
}

Triangle::Triangle(Point edge1, Point edge2, Point edge3)
    : Shape(Point(), Color(255, 255, 255)), m_Edges {edge1, edge2, edge3}
{
    m_Center = getCenter();
}

Triangle::Triangle(Point edges[3], Color color)
    : Triangle(edges[0], edges[1], edges[2], color)
{ }

Triangle::Triangle(Point edge0, Point edge1, Point edge2, Color color)
    : Shape(Point(), color), m_Edges{edge0, edge1, edge2}
{
    m_Center = getCenter();
}

bool Triangle::isHit(Point p) const
{
    Point p0 = m_Edges[0];
    Point p1 = m_Edges[1];
    Point p2 = m_Edges[2];
    
    Point v0 = p2 - p0;
    Point v1 = p1 - p0;
    Point pv = p  - p0;

    long long dotV00 = dotProduct(v0, v0);
    long long dotV01 = dotProduct(v0, v1);
    long long dotV11 = dotProduct(v1, v1);
    long long dotPV0 = dotProduct(pv, v0);
    long long dotPV1 = dotProduct(pv, v1);

    double invervse = 1.0 / (dotV00 * dotV11 - dotV01 * dotV01);

    double u = (dotV11 * dotPV0 - dotV01 * dotPV1) * invervse;
    double v = (dotV00 * dotPV1 - dotV01 * dotPV0) * invervse;

    return u > 0 && v > 0 && (u + v) <= 1;
}

Drawable* Triangle::clone()
{
    return new Triangle(*this);
}

Point Triangle::getCenter() const
{
    int centerX = (m_Edges[0].x() + m_Edges[1].x() + m_Edges[2].x()) / 3;
    int centerY = (m_Edges[0].y() + m_Edges[1].y() + m_Edges[2].y()) / 3;

    return Point(centerX, centerY);
}
