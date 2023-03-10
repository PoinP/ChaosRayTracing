#include "Image.h"
#include <fstream>
#include <stdexcept>
#include <string>

Image::Image(unsigned width, unsigned height)
    : m_Width(width), m_Height(height), m_Background(Color(255, 255, 255))
{
}

Image::Image(unsigned width, unsigned height, Color background)
    : m_Width(width), m_Height(height), m_Background(background)
{
}

Image::Image(const Image& image)
{
    m_Width = image.m_Width;
    m_Height = image.m_Height;

    m_Objects.reserve(image.m_Objects.capacity());

    for (Drawable* drawable : image.m_Objects)
        m_Objects.emplace_back(drawable->clone());
}

Image::Image(Image&& image) noexcept
{
    std::swap(m_Width, image.m_Width);
    std::swap(m_Height, image.m_Height);
    std::swap(m_Objects, image.m_Objects);
}

Image::~Image()
{
    for (Drawable* drawable : m_Objects)
        delete drawable;

    m_Objects.clear();
}

Image& Image::operator=(const Image& image)
{
    if (this != &image)
    {
        m_Width = image.m_Width;
        m_Height = image.m_Height;

        m_Objects.reserve(image.m_Objects.capacity());

        for (Drawable* drawable : image.m_Objects)
            m_Objects.emplace_back(drawable->clone());
    }

    return *this;
}

Image& Image::operator=(Image&& image) noexcept
{
    std::swap(m_Width, image.m_Width);
    std::swap(m_Height, image.m_Height);
    std::swap(m_Objects, image.m_Objects);

    return *this;
}

void Image::draw(const char* imagePath) const
{
    std::ofstream outputStream(imagePath);

    if (!outputStream || !outputStream.is_open())
        throw std::invalid_argument("Can not open file! Maybe it's being used!");

    outputStream << 
        "P3\n" <<
        m_Width << " " << m_Height << "\n" <<
        "255\n";

    bool isHit = false;

    const int BUFFER_SIZE = 2048;
    const int BUFFER_LIMIT = BUFFER_SIZE - (3 * 3 + 2); // 3 digits by 3 color channels and 2 spaces
    
    std::string buffer;
    buffer.reserve(BUFFER_SIZE);

    for (unsigned y = 0; y < m_Height; y++)
    {
        for (unsigned x = 0; x < m_Width; x++)
        {
            for (Drawable* drawable : m_Objects)
            {
                isHit = drawable->isHit(Point(x, y));

                if (isHit)
                {
                    buffer += drawable->getColor().toString() + "\n";
                    break;
                }
            }

            if (!isHit)
                buffer += m_Background.toString() + "\n";

            isHit = false;

            if (buffer.size() >= BUFFER_LIMIT || (x + 1 >= m_Width && y + 1 >= m_Height))
            {
                outputStream << buffer;
                buffer.clear();
            }
        }
    }

    outputStream.close();
}

void Image::addObject(Drawable* object)
{
    m_Objects.push_back(object);
}

void Image::addObjects(Drawable** objects, int size)
{
    for (int i = 0; i < size; i++)
        m_Objects.push_back(objects[i]);
}
