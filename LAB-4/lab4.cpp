#include <SFML/Graphics.hpp>
#include <iostream>
#include "Classes.hpp"

using namespace sf;
using namespace std;

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
		rotation = rotation + 0.05;
	}

	return 0;
}