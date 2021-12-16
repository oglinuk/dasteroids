#include "spaceship.h"

const vec2d default_ship[] = {
	{ -10.0, 25.0 },
	{ 10.0, 25.0 },
};

Spaceship* new_ship(int screen_w, int screen_h)
{
	Spaceship *ship = malloc(sizeof(Spaceship));

	printf("Sizeof(default_ship): %ld | Sizeof(default_ship[0]): %ld == %ld\n",
		sizeof(default_ship), sizeof(default_ship[0]),
		(sizeof(default_ship) / sizeof(default_ship[0])));

	ship->vertices = sizeof(default_ship) / sizeof(default_ship[0]);
	ship->shape = default_ship;

	printf("ship->vertices: %d | sizeof(ship->vertex[0]): %ld\n",
		ship->vertices, sizeof(ship->vertex[0]));

	ship->vertex = malloc(ship->vertices * sizeof(ship->vertex[0]));
	if (!ship->vertex) {
		printf("Ran out of memory ...\n");
		exit(1);
	}

	ship->location.x = screen_w / 2;
	ship->location.y = screen_h / 2;
	ship->yaw = 0.0;
	ship->acceleration_speed = M_SQRT2;
	ship->turn_speed = M_PI / 6;
	ship->velocity= 0.0;
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
	ALLEGRO_COLOR colors[] = {
		al_map_rgba_f(0, 0, 1, 1),
		al_map_rgba_f(0, 1, 0, 1),
	};

	update_ship(ship);

	for (int i = 0; i < ship->vertices; i++) {
		al_draw_line(ship->location.x, ship->location.y,
			ship->vertex[i].x, ship->vertex[i].y,
			colors[i], ship->thickness);
			//ship->color, ship->thickness);
	}

}

void update_ship(Spaceship* ship)
{
	const float c = cosf(ship->yaw);
	const float s = sinf(ship->yaw);
	int i;

	// 2D rotation
	for (i = 0; i < ship->vertices; i++) {
		ship->vertex[i].x = ship->location.x +
			(c*ship->shape[i].x) - (s*ship->shape[i].y);

		ship->vertex[i].y = ship->location.y +
			(s*ship->shape[i].x) + (c*ship->shape[i].y);

		printf("ship->vertex[%d].x: %f | ship->vertex[%d].y: %f\n",
			i, ship->vertex[i].x, i, ship->vertex[i].y);
	}
}
