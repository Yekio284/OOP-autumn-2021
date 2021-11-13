#include <SFML/Graphics.hpp>
#include <iostream>

int rand_num = rand();
#define SIDE_OF_RHOMBUS (30 + rand_num % 31)

using namespace sf;
using namespace std;

class Figures {
protected:
	int x_speed, y_speed;
	int x_coordinate, y_coordinate, color_red, color_green, color_blue;
	int thickness_1, thickness_2, rotation_degree;
	int radius;
	int length, height;
	int space, num_of_angles;
	int convexity;

public:
	Figures() : x_speed(1), y_speed(1), x_coordinate(rand() % 1910), y_coordinate(rand() % 1070), color_red(rand() % 255), color_green(rand() % 255),
	color_blue(rand() % 255), thickness_1(60 + rand() % 41), thickness_2(3 + rand() % 3), rotation_degree(rand() % 21), radius(30 + rand() % 31),
	length(30 + rand() % 71), height(30 + rand() % 71), space(15 + rand() % 36), num_of_angles(3), convexity(15 + rand() % 36)
	{
		cout << "Constructor Figures\n";
	}
	virtual int get_x() {
		return x_coordinate;
	}
	virtual int get_y() {
		return y_coordinate;
	}
	virtual int get_color_red() {
		return color_red;
	}
	virtual int get_color_green() {
		return color_green;
	}
	virtual int get_color_blue() {
		return color_blue;
	}
	virtual int get_thickness_1() {
		return thickness_1;
	}
	virtual int get_thickness_2() {
		return thickness_2;
	}
	virtual int get_rotation_degree() {
		return rotation_degree;
	}
	virtual int get_radius() {
		return radius;
	}
	virtual int get_length() {
		return length;
	}
	virtual int get_height() {
		return height;
	}
	virtual int get_space() {
		return space;
	}
	virtual int get_num_of_angles() {
		return num_of_angles;
	}
	virtual int get_convexity() {
		return convexity;
	}
	virtual void linearmove_x() {
		x_coordinate = x_coordinate + x_speed;
		if (x_coordinate < 0 || x_coordinate > 1910)
			x_speed = x_speed * -1;
	}
	virtual void linearmove_y() {
		y_coordinate = y_coordinate + y_speed;
		if (y_coordinate < 0 || y_coordinate > 1070)
			y_speed = y_speed * -1;
	}
	virtual void randommove_x() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (x_coordinate < 0)
			x_coordinate = x_coordinate + x_speed * 2;
		else if (x_coordinate > 1910)
			x_coordinate = x_coordinate - x_speed * 2;
		else {
			if (variant_to_go == 1)
				x_coordinate = x_coordinate + x_speed * 2;
			else
				x_coordinate = x_coordinate + x_speed * -2;
		}
	}
	virtual void randommove_y() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (y_coordinate < 0)
			y_coordinate = y_coordinate + y_speed * 2;
		else if (y_coordinate > 1070)
			y_coordinate = y_coordinate - y_speed * 2;
		else {
			if (variant_to_go == 1)
				y_coordinate = y_coordinate + y_speed * 2;
			else
				y_coordinate = y_coordinate + y_speed * -2;
		}
	}
	~Figures() {
		cout << "Destructor Figures\n";
	}
};


class tPoint : public Figures {
private:
	int x_speed, y_speed;
	int x_coordinate, y_coordinate, color_red, color_green, color_blue;

public:
	tPoint() : x_speed(1), y_speed(1), x_coordinate(rand() % 1910), y_coordinate(rand() % 1070), color_red(rand() % 255), color_green(rand() % 255),
		color_blue(rand() % 255)
	{
		cout << "Constructor tPoint\n";
	}
	tPoint(int xSpeed, int ySpeed, int xCoordinate, int yCoordinate, int colorRed, int colorGreen, int colorBlue) : x_speed(xSpeed), y_speed(ySpeed),
		x_coordinate(xCoordinate), y_coordinate(yCoordinate), color_red(colorRed), color_green(colorGreen), color_blue(colorBlue) {
		cout << "Constructor with params tPoint\n";
	}
	int get_x() {
		return x_coordinate;
	}
	int get_y() {
		return y_coordinate;
	}
	void linearmove_x() {
		x_coordinate = x_coordinate + x_speed;
		if (x_coordinate < 0 || x_coordinate > 1910)
			x_speed = x_speed * -1;
	}
	void linearmove_y() {
		y_coordinate = y_coordinate + y_speed;
		if (y_coordinate < 0 || y_coordinate > 1070)
			y_speed = y_speed * -1;
	}
	void randommove_x() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (x_coordinate < 0)
			x_coordinate = x_coordinate + x_speed * 2;
		else if (x_coordinate > 1910)
			x_coordinate = x_coordinate - x_speed * 2;
		else {
			if (variant_to_go == 1)
				x_coordinate = x_coordinate + x_speed * 2;
			else
				x_coordinate = x_coordinate + x_speed * -2;
		}
	}
	void randommove_y() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (y_coordinate < 0)
			y_coordinate = y_coordinate + y_speed * 2;
		else if (y_coordinate > 1070)
			y_coordinate = y_coordinate - y_speed * 2;
		else {
			if (variant_to_go == 1)
				y_coordinate = y_coordinate + y_speed * 2;
			else
				y_coordinate = y_coordinate + y_speed * -2;
		}
	}
	~tPoint() {
		cout << "Destructor tPoint\n";
	}
};

class EllipseShape : public Shape {
private:
	Vector2f m_radius;

public:
	explicit EllipseShape(const Vector2f& radius = Vector2f(0, 0)) : m_radius(radius) {
		update();
	}
	void setRadius(const Vector2f& radius) {
		m_radius = radius;
		update();
	}
	const Vector2f& getRadius() const {
		return m_radius;
	}
	virtual unsigned int getPointCount() const {
		return 30; // fixed, but could be an attribute of the class if needed
	}
	virtual Vector2f getPoint(unsigned int index) const {
		static const float pi = 3.141592654f;

		float angle = index * 2 * pi / getPointCount() - pi / 2;
		float x = std::cos(angle) * m_radius.x;
		float y = std::sin(angle) * m_radius.y;

		return Vector2f(m_radius.x + x, m_radius.y + y);
	}
};

class Line : public Figures {
private:
	int thickness_1, thickness_2, rotation_degree;

public:
	Line() : thickness_1(60 + rand() % 41), thickness_2(3 + rand() % 3), rotation_degree(rand() % 21) {
		cout << "Constructor Line\n";
	}
	int get_x() {
		return x_coordinate;
	}
	int get_y() {
		return y_coordinate;
	}
	int get_thickness_1() {
		return thickness_1; // roughly speaking, this is length
	}
	int get_thickness_2() {
		return thickness_2; // and this is height
	}
	int get_rotation_degree() {
		return rotation_degree;
	}
	void linearmove_x() {
		x_coordinate = x_coordinate + x_speed;
		if (x_coordinate < 0 || x_coordinate > 1910)
			x_speed = x_speed * -1;
	}
	void linearmove_y() {
		y_coordinate = y_coordinate + y_speed;
		if (y_coordinate < 0 || y_coordinate > 1070)
			y_speed = y_speed * -1;
	}
	void randommove_x() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (x_coordinate < 0)
			x_coordinate = x_coordinate + x_speed * 2;
		else if (x_coordinate > 1910)
			x_coordinate = x_coordinate - x_speed * 2;
		else {
			if (variant_to_go == 1)
				x_coordinate = x_coordinate + x_speed * 2;
			else
				x_coordinate = x_coordinate + x_speed * -2;
		}
	}
	void randommove_y() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (y_coordinate < 0)
			y_coordinate = y_coordinate + y_speed * 2;
		else if (y_coordinate > 1070)
			y_coordinate = y_coordinate - y_speed * 2;
		else {
			if (variant_to_go == 1)
				y_coordinate = y_coordinate + y_speed * 2;
			else
				y_coordinate = y_coordinate + y_speed * -2;
		}
	}
	~Line() {
		cout << "Destructor Line\n";
	}
};

class Circle : public Figures {
private:
	int radius;

public:
	Circle() : radius(30 + rand() % 31) {
		cout << "Constructor Circle\n";
	}
	int get_x() {
		return x_coordinate;
	}
	int get_y() {
		return y_coordinate;
	}
	int get_radius() {
		return radius;
	}
	void linearmove_x() {
		x_coordinate = x_coordinate + x_speed;
		if (x_coordinate < 0 || x_coordinate > 1910)
			x_speed = x_speed * -1;
	}
	void linearmove_y() {
		y_coordinate = y_coordinate + y_speed;
		if (y_coordinate < 0 || y_coordinate > 1070)
			y_speed = y_speed * -1;
	}
	void randommove_x() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (x_coordinate < 0)
			x_coordinate = x_coordinate + x_speed * 2;
		else if (x_coordinate > 1910)
			x_coordinate = x_coordinate - x_speed * 2;
		else {
			if (variant_to_go == 1)
				x_coordinate = x_coordinate + x_speed * 2;
			else
				x_coordinate = x_coordinate + x_speed * -2;
		}
	}
	void randommove_y() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (y_coordinate < 0)
			y_coordinate = y_coordinate + y_speed * 2;
		else if (y_coordinate > 1070)
			y_coordinate = y_coordinate - y_speed * 2;
		else {
			if (variant_to_go == 1)
				y_coordinate = y_coordinate + y_speed * 2;
			else
				y_coordinate = y_coordinate + y_speed * -2;
		}
	}
	~Circle() {
		cout << "Destructor Circle\n";
	}
};

class Rectangle : public Figures {
private:
	int length, height;

public:
	Rectangle() : length(30 + rand() % 71), height(30 + rand() % 71) {
		cout << "Constructor Rectangle\n";
	}
	int get_x() {
		return x_coordinate;
	}
	int get_y() {
		return y_coordinate;
	}
	int get_length() {
		return length;
	}
	int get_height() {
		return height;
	}
	void linearmove_x() {
		x_coordinate = x_coordinate + x_speed;
		if (x_coordinate < 0 || x_coordinate > 1910)
			x_speed = x_speed * -1;
	}
	void linearmove_y() {
		y_coordinate = y_coordinate + y_speed;
		if (y_coordinate < 0 || y_coordinate > 1070)
			y_speed = y_speed * -1;
	}
	void randommove_x() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (x_coordinate < 0)
			x_coordinate = x_coordinate + x_speed * 2;
		else if (x_coordinate > 1910)
			x_coordinate = x_coordinate - x_speed * 2;
		else {
			if (variant_to_go == 1)
				x_coordinate = x_coordinate + x_speed * 2;
			else
				x_coordinate = x_coordinate + x_speed * -2;
		}
	}
	void randommove_y() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (y_coordinate < 0)
			y_coordinate = y_coordinate + y_speed * 2;
		else if (y_coordinate > 1070)
			y_coordinate = y_coordinate - y_speed * 2;
		else {
			if (variant_to_go == 1)
				y_coordinate = y_coordinate + y_speed * 2;
			else
				y_coordinate = y_coordinate + y_speed * -2;
		}
	}
	~Rectangle() {
		cout << "Destructor Rectangle\n";
	}
};

class Triangle : public Figures {
private:
	int space, num_of_angles;

public:
	Triangle() : space(15 + rand() % 36), num_of_angles(3) {
		cout << "Constructor Triangle\n";
	}
	int get_x() {
		return x_coordinate;
	}
	int get_y() {
		return y_coordinate;
	}
	int get_space() {
		return space;
	}
	int get_num_of_angles() {
		return num_of_angles;
	}
	void linearmove_x() {
		x_coordinate = x_coordinate + x_speed;
		if (x_coordinate < 0 || x_coordinate > 1910)
			x_speed = x_speed * -1;
	}
	void linearmove_y() {
		y_coordinate = y_coordinate + y_speed;
		if (y_coordinate < 0 || y_coordinate > 1070)
			y_speed = y_speed * -1;
	}
	void randommove_x() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (x_coordinate < 0)
			x_coordinate = x_coordinate + x_speed * 2;
		else if (x_coordinate > 1910)
			x_coordinate = x_coordinate - x_speed * 2;
		else {
			if (variant_to_go == 1)
				x_coordinate = x_coordinate + x_speed * 2;
			else
				x_coordinate = x_coordinate + x_speed * -2;
		}
	}
	void randommove_y() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (y_coordinate < 0)
			y_coordinate = y_coordinate + y_speed * 2;
		else if (y_coordinate > 1070)
			y_coordinate = y_coordinate - y_speed * 2;
		else {
			if (variant_to_go == 1)
				y_coordinate = y_coordinate + y_speed * 2;
			else
				y_coordinate = y_coordinate + y_speed * -2;
		}
	}
	~Triangle() {
		cout << "Destructor Triangle\n";
	}
};

class Ellipse : public Figures {
private:
	int radius, convexity;

public:
	Ellipse() : radius(30 + rand() % 31), convexity(15 + rand() % 36) {
		cout << "Constructor Ellipse\n";
	}
	int get_x() {
		return x_coordinate;
	}
	int get_y() {
		return y_coordinate;
	}
	int get_radius() {
		return radius;
	}
	int get_convexity() {
		return convexity;
	}
	void linearmove_x() {
		x_coordinate = x_coordinate + x_speed;
		if (x_coordinate < 0 || x_coordinate > 1910)
			x_speed = x_speed * -1;
	}
	void linearmove_y() {
		y_coordinate = y_coordinate + y_speed;
		if (y_coordinate < 0 || y_coordinate > 1070)
			y_speed = y_speed * -1;
	}
	void randommove_x() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (x_coordinate < 0)
			x_coordinate = x_coordinate + x_speed * 2;
		else if (x_coordinate > 1910)
			x_coordinate = x_coordinate - x_speed * 2;
		else {
			if (variant_to_go == 1)
				x_coordinate = x_coordinate + x_speed * 2;
			else
				x_coordinate = x_coordinate + x_speed * -2;
		}
	}
	void randommove_y() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (y_coordinate < 0)
			y_coordinate = y_coordinate + y_speed * 2;
		else if (y_coordinate > 1070)
			y_coordinate = y_coordinate - y_speed * 2;
		else {
			if (variant_to_go == 1)
				y_coordinate = y_coordinate + y_speed * 2;
			else
				y_coordinate = y_coordinate + y_speed * -2;
		}
	}
	~Ellipse() {
		cout << "Destructor Ellipse\n";
	}
};

class Rhombus : public Figures {
private:
	int length, height;

public:
	Rhombus() : length(SIDE_OF_RHOMBUS), height(SIDE_OF_RHOMBUS) {
		cout << "Constructor Rhombus\n";
	}
	int get_x() {
		return x_coordinate;
	}
	int get_y() {
		return y_coordinate;
	}
	int get_length() {
		return length;
	}
	int get_height() {
		return height;
	}
	void linearmove_x() {
		x_coordinate = x_coordinate + x_speed;
		if (x_coordinate < 0 || x_coordinate > 1910)
			x_speed = x_speed * -1;
	}
	void linearmove_y() {
		y_coordinate = y_coordinate + y_speed;
		if (y_coordinate < 0 || y_coordinate > 1070)
			y_speed = y_speed * -1;
	}
	void randommove_x() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (x_coordinate < 0)
			x_coordinate = x_coordinate + x_speed * 2;
		else if (x_coordinate > 1910)
			x_coordinate = x_coordinate - x_speed * 2;
		else {
			if (variant_to_go == 1)
				x_coordinate = x_coordinate + x_speed * 2;
			else
				x_coordinate = x_coordinate + x_speed * -2;
		}
	}
	void randommove_y() {
		int variant_to_go = 1 + rand() % 2; // [1;2]

		if (y_coordinate < 0)
			y_coordinate = y_coordinate + y_speed * 2;
		else if (y_coordinate > 1070)
			y_coordinate = y_coordinate - y_speed * 2;
		else {
			if (variant_to_go == 1)
				y_coordinate = y_coordinate + y_speed * 2;
			else
				y_coordinate = y_coordinate + y_speed * -2;
		}
	}
	~Rhombus() {
		cout << "Destructor Rhombus\n";
	}
};