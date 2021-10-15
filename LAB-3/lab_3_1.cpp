#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class tPoint {
private:
	int x_speed = 1, y_speed = 1;
	int x_coordinate, y_coordinate, color_red, color_green, color_blue;

public:
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
};

int main() {
	srand(time(NULL));
	
	int user_choose, i;
	cout << "What do you want to see: linear move or random move? (1/2): ";
	cin >> user_choose;

	tPoint arr_of_points[100];

	for (i = 0; i < 100; i++) {
		arr_of_points[i].set_x(rand() % 1910);
		arr_of_points[i].set_y(rand() % 1070);
		arr_of_points[i].set_color_red(rand() % 255);
		arr_of_points[i].set_color_green(rand() % 255);
		arr_of_points[i].set_color_blue(rand() % 255);
	}

	RenderWindow window(VideoMode(1920, 1080), "LAB-3");

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen()) {
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event)) {
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		// Цвет окна
		window.clear(Color(0, 0, 0, 0));

		for (i = 0; i < 100; i++) {
			CircleShape circle(10.f);
			circle.setPosition(arr_of_points[i].get_x(), arr_of_points[i].get_y());
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
				cout << "Incorrect input.";
				return 1;
			}

			window.draw(circle);
		}


		// Отрисовка окна
		window.display();
	}

	return 0;
}