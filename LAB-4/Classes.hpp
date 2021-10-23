#include <iostream>

using namespace sf;
using namespace std;

class tPoint {
protected:
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
	int get_color_red() {
		return color_red;
	}
	int get_color_green() {
		return color_green;
	}
	int get_color_blue() {
		return color_blue;
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

class Line : public tPoint {
private:
	int thickness_1, thickness_2, rotation_degree;

public:
	Line(int Thickness1, int Thickness2, int RotationDegree) : thickness_1(Thickness1), thickness_2(Thickness2), rotation_degree(RotationDegree) {
		cout << "Constructor Line\n";
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
	~Line() {
		cout << "Destructor Line\n";
	}
};

class Circle : public tPoint {
private:
	int radius;

public:
	Circle(int Radius) : radius(Radius) {
		cout << "Constructor Circle\n";
	}
	int get_radius() {
		return radius;
	}
	~Circle() {
		cout << "Destructor Circle\n";
	}
};

class Rectangle : public tPoint {
private:
	int length, height;

public:
	Rectangle(int Length, int Height) : length(Length), height(Height) {
		cout << "Constructor Rectangle\n";
	}
	int get_length() {
		return length;
	}
	int get_height() {
		return height;
	}
	~Rectangle() {
		cout << "Destructor Rectangle\n";
	}
};

class Triangle : public tPoint {
private:
	int space, num_of_angles;

public:
	Triangle(int Space, int NumOfAngles) : space(Space), num_of_angles(NumOfAngles) {
		cout << "Constructor Triangle\n";
	}
	int get_space() {
		return space;
	}
	int get_num_of_angles() {
		return num_of_angles;
	}
	~Triangle() {
		cout << "Destructor Triangle\n";
	}
};

class Ellipse : public tPoint {
private:
	int radius, convexity;

public:
	Ellipse(int Radius, int Convexity) : radius(Radius), convexity(Convexity) {
		cout << "Constructor Ellipse\n";
	}
	int get_radius() {
		return radius;
	}
	int get_convexity() {
		return convexity;
	}
	~Ellipse() {
		cout << "Destructor Ellipse\n";
	}
};

class Rhombus : public tPoint {
private:
	int length, height;

public:
	Rhombus(int Length, int Height) : length(Length), height(Height) {
		cout << "Constructor Rhombus\n";
	}
	int get_length() {
		return length;
	}
	int get_height() {
		return height;
	}
	~Rhombus() {
		cout << "Destructor Rhombus\n";
	}
};