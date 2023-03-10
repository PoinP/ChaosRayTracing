#ifndef IMAGE_H

#define IMAGE_H

#include <vector>
#include "../Drawables/Drawable.h"

class Image
{
public:
	Image(unsigned width, unsigned height);
	Image(unsigned width, unsigned height, Color background);
	Image(const Image& image);
	Image(Image&& image) noexcept;
	~Image();

	Image& operator= (const Image& image);
	Image& operator= (Image&& image) noexcept;

	void draw(const char* imagePath) const;

	void addObject(Drawable* object);
	void addObjects(Drawable** objects, int size);

private:
	unsigned m_Width;
	unsigned m_Height;
	Color m_Background;
	std::vector<Drawable*> m_Objects;
};

#endif // !IMAGE_H