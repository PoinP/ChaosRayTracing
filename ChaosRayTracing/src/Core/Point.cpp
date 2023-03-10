#include "Point.h"

Point::Point()
    : m_X(0), m_Y(0)
{
}

Point::Point(int x, int y)
    : m_X(x), m_Y(y)
{
}

int Point::x() const
{
    return m_X;
}

int Point::y() const
{
    return m_Y;
}

int& Point::x()
{
    return m_X;
}

int& Point::y()
{
    return m_Y;
}

Point Point::operator-() const
{
    return Point(-m_X, -m_Y);
}

Point& Point::operator+=(Point p)
{
    m_X += p.m_X;
    m_Y += p.m_Y;

    return *this;
}

Point& Point::operator-=(Point p)
{
    *this += -p;

    return *this;
}

Point& Point::operator*=(int scalar)
{
    m_X *= scalar;
    m_Y *= scalar;

    return *this;
}

Point& Point::operator/=(int scalar)
{
    *this *= (1 / scalar);

    return *this;
}

Point operator+(Point p1, Point p2)
{
    return Point(p1.x() + p2.x(), p1.y() + p2.y());
}

Point operator-(Point p1, Point p2)
{
    return p1 + (-p2);
}

Point operator*(Point p, int scalar)
{
    return Point(p.x() * scalar, p.y() * scalar);
}

Point operator*(int scalar, Point p)
{
    return p * scalar;
}

Point operator/(Point p, int scalar)
{
    return p * (1 / scalar);
}

Point operator/(int scalar, Point p)
{
    return p / scalar;
}

bool operator==(Point p1, Point p2)
{
    return p1.x() == p2.x() && p1.y() == p2.y();
}

bool operator!=(Point p1, Point p2)
{
    return !(p1 == p2);
}

int dotProduct(Point p1, Point p2)
{
    return p1.x() * p2.x() + p1.y() * p2.y();
}

