#include <SFML/Graphics.hpp>
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
	void set_x(int x) {
		x_coordinate = x;
	}
	void set_y(int y) {
		y_coordinate = y;
	}
	int get_x() {
		return x_coordinate;
	}
	int get_y() {
		return y_coordinate;
	}
	void set_color_red(int red) {
		color_red = red;
	}
	void set_color_green(int grn) {
		color_green = grn;
	}
	void set_color_blue(int blue) {
		color_blue = blue;
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

int main() {
	int user_choose;
	cout << "What do you want to see: linear move or rotation? (1/2): ";
	cin >> user_choose;
	if (user_choose != 1 && user_choose != 2) {
		cout << "Invalid number\n";
		return 1;
	}
	
	srand(time(NULL));
	
	cout << "Constructors:\n";

	tPoint tpoint(1, 1, (rand() % 1910), (rand() % 1070), (rand() % 255), (rand() % 255), (rand() % 255)); 
	Line myLine((60 + rand() % 41), (3 + rand() % 3), (rand() % 21)); // [60; 100], [3; 5], [0; 20]
	Circle myCircle(30 + rand() % 31); // [30; 60]
	Rectangle myRectangle((30 + rand() % 71), (30 + rand() % 71)); // [30; 100]
	Triangle myTriangle((15 + rand() % 36), 3); // [15; 50]
	Ellipse myEllipse((30 + rand() % 31), (15 + rand() % 36)); // [30; 60], [15; 50]
	int side_of_rhombus = 30 + rand() % 31; // [30; 100]
	Rhombus myRhombus(side_of_rhombus, side_of_rhombus); 
	

	RenderWindow window(VideoMode(1920, 1080), "LAB-4");


	float rotation = 0;
	// Main loop of app. Performed while window is open.
	while (window.isOpen()) {
		// Processing the event queue in a loop
		Event event;
		while (window.pollEvent(event)) {
			// User wants to close the window?
			if (event.type == Event::Closed) {
				cout << "\nDestructors:\n";
				// then close it
				window.close();
			}
		}
		// The color of window
		window.clear(Color(0, 0, 0, 0));

		CircleShape point(10.f);
		point.setPosition(tpoint.get_x(), tpoint.get_y());
		point.setFillColor(Color(tpoint.get_color_red(), tpoint.get_color_green(), tpoint.get_color_blue()));
		
		RectangleShape line(Vector2f(myLine.get_thickness_1(), myLine.get_thickness_2()));
		line.setPosition(myLine.get_x(), myLine.get_y());
		line.setFillColor(Color(myLine.get_color_red(), myLine.get_color_green(), myLine.get_color_blue()));
		line.rotate(myLine.get_rotation_degree());
		
		CircleShape circle(myCircle.get_radius());
		circle.setPosition(myCircle.get_x(), myCircle.get_y());
		circle.setFillColor(Color(myCircle.get_color_red(), myCircle.get_color_green(), myCircle.get_color_blue()));
		
		RectangleShape rectangle(Vector2f(myRectangle.get_length(), myRectangle.get_height()));
		rectangle.setPosition(myRectangle.get_x(), myRectangle.get_y());
		rectangle.setFillColor(Color(myRectangle.get_color_red(), myRectangle.get_color_green(), myRectangle.get_color_blue()));
		
		CircleShape triangle(myTriangle.get_space(), myTriangle.get_num_of_angles());
		triangle.setPosition(myTriangle.get_x(), myTriangle.get_y());
		triangle.setFillColor(Color(myTriangle.get_color_red(), myTriangle.get_color_green(), myTriangle.get_color_blue()));
		
		EllipseShape ellipse(Vector2f(myEllipse.get_radius(), myEllipse.get_convexity()));
		ellipse.setPosition(myEllipse.get_x(), myEllipse.get_y());
		ellipse.setFillColor(Color(myEllipse.get_color_red(), myEllipse.get_color_green(), myEllipse.get_color_blue()));
		
		RectangleShape rhombus(Vector2f(myRhombus.get_length(), myRhombus.get_height()));
		rhombus.setPosition(myRhombus.get_x(), myRhombus.get_y());
		rhombus.setFillColor(Color(myRhombus.get_color_red(), myRhombus.get_color_green(), myRhombus.get_color_blue()));
		rhombus.rotate(45);
		

		switch (user_choose) {
		case 1: 
			tpoint.linearmove_x();
			tpoint.linearmove_y();
			window.draw(point);

			myLine.linearmove_x();
			myLine.linearmove_y();
			window.draw(line);

			myCircle.linearmove_x();
			myCircle.linearmove_y();
			window.draw(circle);

			myRectangle.linearmove_x();
			myRectangle.linearmove_y();
			window.draw(rectangle);

			myTriangle.linearmove_x();
			myTriangle.linearmove_y();
			window.draw(triangle);

			myEllipse.linearmove_x();
			myEllipse.linearmove_y();
			window.draw(ellipse);

			myRhombus.linearmove_x();
			myRhombus.linearmove_y();
			window.draw(rhombus);
			
			break;

		case 2:
			point.rotate(rotation);
			window.draw(point);

			line.rotate(rotation);
			window.draw(line);

			circle.rotate(rotation);
			window.draw(circle);

			rectangle.rotate(rotation);
			window.draw(rectangle);

			triangle.rotate(rotation);
			window.draw(triangle);

			ellipse.rotate(rotation);
			window.draw(ellipse);

			rhombus.rotate(rotation);
			window.draw(rhombus);

			break;
		}

		// Display the window
		window.display();
		rotation = rotation + 0.01;
	}

	return 0;
}