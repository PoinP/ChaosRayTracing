#ifndef COLOR_H

#define COLOR_H

#include <iostream>
#include <string>

class Color
{
public:
	Color();
	Color(unsigned char red, unsigned char green, unsigned char blue);

	short getRed() const;
	short getGreen() const;
	short getBlue() const;
	std::string toString() const;

	static Color generateRandomColor(unsigned char threshold = 255);
	static Color generateRandomBasicColor();

	bool operator== (Color c);
	bool operator!= (Color c);

private:
	unsigned char m_Red;
	unsigned char m_Green;
	unsigned char m_Blue;
};

std::ostream& operator<<(std::ostream& stream, Color color);

#endif // !COLOR_H