#include <iostream>

class tPoint {
private:
	int x_speed = 1, y_speed = 1;
	int x_coordinate, y_coordinate, color_red, color_green, color_blue;
public:
	void set_x_coordinate(int x) {
		x_coordinate = x;
	}
	void set_y_coordinate(int y) {
		y_coordinate = y;
	}
	int get_x_coordinate() {
		return x_coordinate;
	}
	int get_y_coordinate() {
		return y_coordinate;
	}
	void set_color_red(int red) {
		color_red = red;
	}
	void set_color_green(int green) {
		color_green = green;
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