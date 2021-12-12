#include "spaceship.h"

const vec2d default_ship[] = {
	{ 0.0, -5.0 },
	{ -10.0, 25.0 },
	{ 10.0, 25.0 },
};

Spaceship* new_ship(int screen_w, int screen_h)
{
	Spaceship *ship = malloc(sizeof(Spaceship));

	ship->vertices = sizeof(default_ship) / sizeof(default_ship[0]);
	ship->shape = default_ship;

	ship->vertex = malloc(ship->vertices * sizeof(ship->vertex[0]));
	if (!ship->vertex) {
		printf("Ran out of memory ...\n");
		exit(1);
	}

	ship->location.x = screen_w / 2;
	ship->location.y = screen_h / 2;
	ship->yaw = 0.0;
	ship->acceleration_speed = 10.0;
	ship->turn_speed = M_E / 10;
	ship->thickness = 1.0;
	ship->alive = true;
	ship->color = al_map_rgba_f(0.5, 0, 0.5, 1);

	update_ship(ship);

	return ship;
}

void destroy_ship(Spaceship *ship)
{
	free(ship);
}

void draw_ship(Spaceship* ship)
{
	update_ship(ship);

	for (int i = 1; i < ship->vertices; i++) {
		al_draw_line(ship->location.x, ship->location.y,
			ship->vertex[i].x, ship->vertex[i].y,
			ship->color, ship->thickness);
	}
}

void update_ship(Spaceship* ship)
{
	const float c = cos(ship->yaw);
	const float s = sin(ship->yaw);
	int i;

	for (i = 0; i < ship->vertices; i++) {
		ship->vertex[i].x = ship->location.x +
			c*ship->shape[i].x - s*ship->shape[i].y;

		ship->vertex[i].y = ship->location.y +
			s*ship->shape[i].x + c*ship->shape[i].y;
	}
}
