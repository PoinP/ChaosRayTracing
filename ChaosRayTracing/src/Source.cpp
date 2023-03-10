#include <iostream>
#include <fstream>
#include <string>

#include "Utility.h"
#include "Core/Color.h"
#include "Core/Image.h"
#include "Drawables/Shapes/AllShapes.h"

// The random color grid
void taskOne();

// The object drawing task
void taskTwo();

// A drawing of a truck
void taskTwoTruck();

bool isSameAsANeighbour(Color** colors, int row, int column);
void generateRandomColors(Color** colors, int size);

int main()
{
	taskOne();
	taskTwo();
	taskTwoTruck();
}

void taskOne()
{
	std::ofstream outputStream("out\\color-grid.ppm");

	if (!outputStream || !outputStream.is_open())
	{
		std::cerr << "Error opening the image file! Maybe it's being used!" << std::endl;
		return;
	}

	// The amount of rectangles on each row and column
	const unsigned SPLITS = 7;

	const int WIDTH = 1920;
	const int HEIGHT = 1080;
	const int W_SPLIT = ceil((double)WIDTH / SPLITS);
	const int H_SPLIT = ceil((double)HEIGHT / SPLITS);

	outputStream << 
		"P3\n" <<
		WIDTH << " " << HEIGHT << "\n" <<
		"255\n";

	srand(time(0));

	Color* colorGrid[SPLITS]{};
	for (int i = 0; i < SPLITS; i++)
		colorGrid[i] = new Color[SPLITS];

	generateRandomColors(colorGrid, SPLITS);

	int rowColor = -1;
	int colColor = -1;

	std::string buffer;
	buffer.reserve(2048);

	const int diff = 2048 - 3 * 6;

	for (int i = 0; i < HEIGHT; i++)
	{
		if (i % H_SPLIT == 0)
			rowColor++;

		for (int j = 0; j < WIDTH; j++)
		{
			if (j % W_SPLIT == 0)
				colColor++;

			using Utility::generateRandomNumber;

			buffer.append(std::to_string(generateRandomNumber(0, colorGrid[rowColor][colColor].getRed())) + " ");
			buffer.append(std::to_string(generateRandomNumber(0, colorGrid[rowColor][colColor].getGreen())) + " ");
			buffer.append(std::to_string(generateRandomNumber(0, colorGrid[rowColor][colColor].getBlue())) + "\n");

			if (buffer.size() >= diff || (i + 1 >= HEIGHT && j + 1 >= WIDTH))
			{
				outputStream << buffer;
				buffer.clear();
			}
		}

		colColor = -1;
	}

	outputStream.close();

	for (int i = 0; i < SPLITS; i++)
		delete[] colorGrid[i];

	std::cout << "Color grid successfully generated!" << std::endl;
}

void taskTwo()
{
	const Color background = Color(255, 0, 0);
	const Color fontColor = Color(255, 255, 255);

	Image myImage(1200, 1200, background);

	Drawable* letterC[] = { new Triangle(Point(223, 607), Point(299, 573), Point(272 , 542), background),
							new Triangle(Point(208, 564), Point(223, 607), Point(299 , 522), background),
							new Circle(Point(185, 600), 50, background), new Circle(Point(185, 600), 100, fontColor) };

	Drawable* letterH[] = { new Circle(Point(400, 600), 50, background), new Rectangle(Point(400, 700), 100, 200, background),
							new Rectangle(Point(325, 555), 50, 285, fontColor), new Rectangle(Point(474, 645), 50, 105, fontColor),
							new Circle(Point(400, 600), 100, fontColor) };

	Drawable* letterA[] = { new Circle(Point(615, 600), 50, background), new Circle(Point(615, 600), 100, fontColor),
							new Rectangle(Point(689, 650), 50, 90, fontColor) };

	Drawable* letterO[] = { new Circle(Point(835, 600), 50, background), new Circle(Point(835, 600), 100, fontColor) };

	// I just couldn't draw a good S with my current primitives :(
	Drawable* sadFace[] = { new Circle(Point(1002, 563), 36, fontColor), new Circle(Point(1127, 563), 36, fontColor),
							new Circle(Point(1064, 680), 55, background), new Circle(Point(1064, 670), 55, fontColor) };

	myImage.addObjects(letterC, sizeof(letterC) / sizeof(Drawable*));
	myImage.addObjects(letterH, sizeof(letterH) / sizeof(Drawable*));
	myImage.addObjects(letterA, sizeof(letterA) / sizeof(Drawable*));
	myImage.addObjects(letterO, sizeof(letterO) / sizeof(Drawable*));
	myImage.addObjects(sadFace, sizeof(sadFace) / sizeof(Drawable*));

	// It draws the objects sequentially. It draws the first hit object
	// in the scene. The objects are checked from the first added object
	// to the last one.

	try
	{
		myImage.draw("out\\chaos-logo.ppm");
	}
	catch (const std::invalid_argument& ex)
	{
		std::cerr << "Error: " << ex.what() << std::endl;
		return;
	}

	std::cout << "Logo successfully generated!" << std::endl;
}

void taskTwoTruck()
{
	Color grass(37, 135, 18);
	Color paint(0, 42, 255);
	Color glass(215, 216, 216);
	Color road(120, 99, 72);
	Color cargo(126, 126, 126);
	Color tyre(0, 0, 0);
	Color sideStrip(99, 66, 0);
	Color background(0, 185, 255);
	Color light(255, 234, 0);

	Image truckImage(1920, 1080, background);

	truckImage.addObject(new Triangle(Point(150, 460), Point(70, 425), Point(70, 500), light)); // Headlight

	truckImage.addObject(new Circle(Point(200, 680), 35, cargo));  // Inner tyre
	truckImage.addObject(new Circle(Point(200, 680), 90, tyre));   // First tyre

	truckImage.addObject(new Circle(Point(670, 680), 35, cargo));  // Inner tyre
	truckImage.addObject(new Circle(Point(670, 680), 90, tyre));   // Second tyre

	truckImage.addObject(new Circle(Point(880, 680), 35, cargo));  // Inner tyre
	truckImage.addObject(new Circle(Point(880, 680), 90, tyre));   // Third tyre

	truckImage.addObject(new Circle(Point(1380, 680), 35, cargo)); // Inner tyre
	truckImage.addObject(new Circle(Point(1380, 680), 90, tyre));  // Fourth tyre

	truckImage.addObject(new Circle(Point(1590, 680), 35, cargo)); // Inner tyre
	truckImage.addObject(new Circle(Point(1590, 680), 90, tyre));  // Fifth tyre

	truckImage.addObject(new Rectangle(Point(1145, 405), 1080, 445, cargo)); // Cargo (trailer)
	truckImage.addObject(new Rectangle(Point(510, 640), 880, 85, paint));    // Lower long part of truck
	truckImage.addObject(new Rectangle(Point(318, 485), 435, 235, paint));	 // Main part of truck
	truckImage.addObject(new Rectangle(Point(420, 285), 230, 170, paint));	 // Upper part of truck
	truckImage.addObject(new Triangle(Point(310, 195), Point(310, 370), Point(155, 370), glass));  // Windshield

	truckImage.addObject(new Rectangle(Point(960, 765), 1920, 330, road));      // Dirt road
	truckImage.addObject(new Rectangle(Point(960, 765), 1920, 400, sideStrip)); // Side strip
	truckImage.addObject(new Rectangle(Point(960, 780), 1920, 670, grass));	    // Grass
	
	try
	{
		truckImage.draw("out\\truck.ppm");
	}
	catch (const std::invalid_argument& ex)
	{
		std::cerr << "Error: " << ex.what() << std::endl;
		return;
	}

	std::cout << "Truck successfully generated!" << std::endl;
}

bool isSameAsANeighbour(Color** colors, int row, int column)
{																   // Neighbor Position
	return colors[row][column] == colors[row - 1][column - 1] ||   // up-right
		colors[row][column] == colors[row - 1][column] ||   // up
		colors[row][column] == colors[row - 1][column + 1] ||   // up-left
		colors[row][column] == colors[row][column + 1] ||   // right
		colors[row][column] == colors[row + 1][column + 1] ||   // down-right
		colors[row][column] == colors[row + 1][column] ||   // down
		colors[row][column] == colors[row + 1][column - 1] ||   // down-left
		colors[row][column] == colors[row][column - 1];		   // right
}

// Generates a square matrix of random colors while making
// sure that colors next to each other are different colors
void generateRandomColors(Color** colors, int size)
{
	// A new matrix that adds a padding to the main matrix
	// 
	/*
		Example: (Let's say that the colors are numbers)

		Main matrix:
		1 9
		2 3

		With padding:
		0 0 0 0
		0 1 9 0
		0 2 3 0
		0 0 0 0
	*/
	//
	// This helps out when checking if there are
	// any neighboring elements with the same value!
	// 
	// In this example we make an empty matrix and
	// fill it up while adding the filled colors inside
	// the main matrix.

	unsigned helperSize = size + 2; // + 2 for the padding

	Color** helperMatrix = new Color * [helperSize];
	for (int i = 0; i < helperSize; i++)
		helperMatrix[i] = new Color[helperSize]{};

	for (int row = 1; row < helperSize - 1; row++)
	{
		for (int col = 1; col < helperSize - 1; col++)
		{
			do
			{
				helperMatrix[row][col] = Color::generateRandomBasicColor();
			} while (isSameAsANeighbour(helperMatrix, row, col));

			colors[row - 1][col - 1] = helperMatrix[row][col];
		}
	}

	for (int i = 0; i < helperSize; i++)
	{
		delete[] helperMatrix[i];
	}
	delete[] helperMatrix;
}
