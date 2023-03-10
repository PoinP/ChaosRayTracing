#include "Color.h"
#include "../Utility.h"

Color::Color()
	: m_Red(0), m_Green(0), m_Blue(0)
{
}

Color::Color(unsigned char red, unsigned char green, unsigned char blue)
	: m_Red(red), m_Green(green), m_Blue(blue)
{
}

short Color::getRed() const
{
	return m_Red;
}

short Color::getGreen() const
{
	return m_Green;
}

short Color::getBlue() const
{
	return m_Blue;
}

std::string Color::toString() const
{
	using std::to_string;

	std::string colorString;
	colorString.reserve(3 * 3 + 2); // 3 digits per color * 3 colors + 2 spaces

	return to_string(m_Red) + " " + to_string(m_Green) + " " + to_string(m_Blue);
}

Color Color::generateRandomColor(unsigned char threshold)
{
	using Utility::generateRandomNumber;
	
	return Color(
		generateRandomNumber(0, threshold),
		generateRandomNumber(0, threshold),
		generateRandomNumber(0, threshold)
	);
}

Color Color::generateRandomBasicColor()
{
	using Utility::generateRandomNumber;

	const char RED = 0x1;
	const char GREEN = 0x2;
	const char BLUE = 0x4;

	char colorIndex = generateRandomNumber(1, 6); // 0 is black and 7 is white so they are excluded

	Color randomColor;
	if (colorIndex & RED)
		randomColor.m_Red = 255;
	if (colorIndex & GREEN)
		randomColor.m_Green = 255;
	if (colorIndex & BLUE)
		randomColor.m_Blue = 255;

	return randomColor;
}

bool Color::operator==(Color c)
{
	return m_Red == c.m_Red && m_Green == c.m_Green && m_Blue == c.m_Blue;
}

bool Color::operator!=(Color c)
{
	return !(*this == c);
}

std::ostream& operator<<(std::ostream& stream, Color color)
{
	stream << color.getRed() << " " << color.getGreen() << " " << color.getBlue();
	return stream;
}
