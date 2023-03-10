#ifndef POINT_H

#define POINT_H

class Point
{
public:
	Point();
	Point(int x, int y);

	int x() const;
	int y() const;

	int& x();
	int& y();

	Point operator-() const;

	Point& operator+=(Point p);
	Point& operator-=(Point p);
	Point& operator*=(int scalar);
	Point& operator/=(int scalar);

private:
	int m_X;
	int m_Y;
};

Point operator+(Point p1, Point p2);
Point operator-(Point p1, Point p2);
Point operator*(Point p, int scalar);
Point operator*(int scalar, Point p);
Point operator/(Point p, int scalar);
Point operator/(int scalar, Point p);

bool operator==(Point p1, Point p2);
bool operator!=(Point p1, Point p2);

int dotProduct(Point p1, Point p2);

#endif // !POINT_H
