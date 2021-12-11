#include <stdio.h>
#include "spaceship.h"

struct Spaceship* new_ship(int screen_w, int screen_h)
{
	Spaceship *ship = malloc(sizeof(Spaceship));

	ship->screen_x = screen_w / 2;
	ship->screen_y = screen_h / 2;
	ship->direction = 1.0;
	ship->speed = 10.0;
	ship->thickness = 1.0;
	ship->alive = true;
	ship->color = al_map_rgba_f(0.5, 0, 0.5, 1);

	return ship;
}

void destroy_ship(Spaceship *ship)
{
	free(ship);
}

void draw_ship(Spaceship* ship)
{
	al_draw_triangle(ship->screen_x, ship->screen_y,
		ship->screen_x+10, ship->screen_y+23,
		ship->screen_x-10, ship->screen_y+23,
		ship->color, ship->thickness);
}
