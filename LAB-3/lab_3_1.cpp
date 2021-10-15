#include <SFML/Graphics.hpp>
#include <iostream>
#include "tPoint.hpp"

using namespace sf;
using namespace std;

int main() {
	srand(time(NULL));
	
	tPoint arr_of_points[100];
	int i;

	for (i = 0; i < 100; i++) {
		arr_of_points[i].set_x_coordinate(rand() % 1910);
		arr_of_points[i].set_y_coordinate(rand() % 1070);
		arr_of_points[i].set_color_red(rand() % 255);
		arr_of_points[i].set_color_green(rand() % 255);
		arr_of_points[i].set_color_blue(rand() % 255);
	}

	int user_choose;
	cout << "What do you want to see: linear move or random move? (1/2): ";
	cin >> user_choose;
	
	RenderWindow window(VideoMode(1920, 1080), "LAB-3");
	
	// Main loop of app. Performed while window is open.
	while (window.isOpen()) {
		// Processing the event queue in a loop
		Event event;
		while (window.pollEvent(event)) {
			// User wants to close the window?
			if (event.type == Event::Closed)
				// then close it
				window.close();
		}
		// The color of window
		window.clear(Color(0, 0, 0, 0));

		for (i = 0; i < 100; i++) {
			CircleShape circle(10.f);
			circle.setPosition(arr_of_points[i].get_x_coordinate(), arr_of_points[i].get_y_coordinate());
			circle.setFillColor(Color(arr_of_points[i].get_color_red(), arr_of_points[i].get_color_green(), arr_of_points[i].get_color_blue()));

			switch (user_choose) {
			case 1:
				arr_of_points[i].linearmove_x();
				arr_of_points[i].linearmove_y();
				break;
			case 2:
				arr_of_points[i].randommove_x();
				arr_of_points[i].randommove_y();
				break;
			default:
				cout << "Incorrect input.\n";
				return 1;
			}
			// Drawing our point
			window.draw(circle);
		}
		// Display the window
		window.display();
	}
	return 0;
}