#include <SFML/Graphics.hpp>
#include <iostream>
#include "Figures.hpp"

using namespace sf;
using namespace std;

int main() {
	int user_choose;
	cout << "What do you want to see: linear move or rotation? (1/2): ";
	cin >> user_choose;
	if (user_choose != 1 && user_choose != 2) {
		cout << "Invalid number/symbol\n";
		return 1;
	}

	srand(time(NULL));

	cout << "Constructors:\n";
	
	Figures *array_of_figures[7];
	array_of_figures[0] = new tPoint;
	array_of_figures[1] = new Line;
	array_of_figures[2] = new Circle;
	array_of_figures[3] = new Rectangle;
	array_of_figures[4] = new Triangle;
	array_of_figures[5] = new Ellipse;
	array_of_figures[6] = new Rhombus;


	RenderWindow window(VideoMode(1920, 1080), "LAB-5");


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
		point.setPosition(array_of_figures[0]->get_x(), array_of_figures[0]->get_y());
		point.setFillColor(Color(array_of_figures[0]->get_color_red(), array_of_figures[0]->get_color_green(), array_of_figures[0]->get_color_blue()));

		RectangleShape line(Vector2f(array_of_figures[1]->get_thickness_1(), array_of_figures[1]->get_thickness_2()));
		line.setPosition(array_of_figures[1]->get_x(), array_of_figures[1]->get_y());
		line.setFillColor(Color(array_of_figures[1]->get_color_red(), array_of_figures[1]->get_color_green(), array_of_figures[1]->get_color_blue()));
		line.rotate(array_of_figures[1]->get_rotation_degree());

		CircleShape circle(array_of_figures[2]->get_radius());
		circle.setPosition(array_of_figures[2]->get_x(), array_of_figures[2]->get_y());
		circle.setFillColor(Color(array_of_figures[2]->get_color_red(), array_of_figures[2]->get_color_green(), array_of_figures[2]->get_color_blue()));

		RectangleShape rectangle(Vector2f(array_of_figures[3]->get_length(), array_of_figures[3]->get_height()));
		rectangle.setPosition(array_of_figures[3]->get_x(), array_of_figures[3]->get_y());
		rectangle.setFillColor(Color(array_of_figures[3]->get_color_red(), array_of_figures[3]->get_color_green(), array_of_figures[3]->get_color_blue()));

		CircleShape triangle(array_of_figures[4]->get_space(), array_of_figures[4]->get_num_of_angles());
		triangle.setPosition(array_of_figures[4]->get_x(), array_of_figures[4]->get_y());
		triangle.setFillColor(Color(array_of_figures[4]->get_color_red(), array_of_figures[4]->get_color_green(), array_of_figures[4]->get_color_blue()));

		EllipseShape ellipse(Vector2f(array_of_figures[5]->get_radius(), array_of_figures[5]->get_convexity()));
		ellipse.setPosition(array_of_figures[5]->get_x(), array_of_figures[5]->get_y());
		ellipse.setFillColor(Color(array_of_figures[5]->get_color_red(), array_of_figures[5]->get_color_green(), array_of_figures[5]->get_color_blue()));

		RectangleShape rhombus(Vector2f(array_of_figures[6]->get_length(), array_of_figures[6]->get_height()));
		rhombus.setPosition(array_of_figures[6]->get_x(), array_of_figures[6]->get_y());
		rhombus.setFillColor(Color(array_of_figures[6]->get_color_red(), array_of_figures[6]->get_color_green(), array_of_figures[6]->get_color_blue()));
		rhombus.rotate(45);

		switch (user_choose) {
		case 1:
			array_of_figures[0]->linearmove_x();
			array_of_figures[0]->linearmove_y();
			window.draw(point);

			array_of_figures[1]->linearmove_x();
			array_of_figures[1]->linearmove_y();
			window.draw(line);

			array_of_figures[2]->linearmove_x();
			array_of_figures[2]->linearmove_y();
			window.draw(circle);

			array_of_figures[3]->linearmove_x();
			array_of_figures[3]->linearmove_y();
			window.draw(rectangle);

			array_of_figures[4]->linearmove_x();
			array_of_figures[4]->linearmove_y();
			window.draw(triangle);

			array_of_figures[5]->linearmove_x();
			array_of_figures[5]->linearmove_y();
			window.draw(ellipse);

			array_of_figures[6]->linearmove_x();
			array_of_figures[6]->linearmove_y();
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

	for (int i = 0; i < 7; i++)
		delete array_of_figures[i];

	return 0;
}
