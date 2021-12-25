#include "entity.h"

const vec2d default_asteroid[] = {
	{0.0, 0.0}, {8.0, -6.0},
	{8.0, -6.0}, {25.0, -8.0},
	{25.0, -8.0}, {33.0, 13.0},
	{33.0, 13.0}, {15.0, 24.0},
	{15.0, 24.0}, {0.0, 12.0},
	{0.0, 12.0}, {0.0, 0.0}
};

Entity* new_asteroid(int screen_w, int screen_h)
{
	Entity *asteroid = malloc(sizeof(Entity));

	asteroid->name = "asteroid";
	asteroid->location.x = rand() % screen_w;
	asteroid->location.y = rand() % screen_h;
	asteroid->screen.x = screen_w;
	asteroid->screen.y = screen_h;
	asteroid->shape = default_asteroid;
	printf("Asteroid: %ld | Asteroid[0]: %ld\n",
		sizeof(default_asteroid), sizeof(default_asteroid[0]));
	asteroid->shape_size = ARRAYSIZE(default_asteroid);
	asteroid->yaw = (rand() / (float)RAND_MAX) * 10;
	asteroid->velocity = (rand() / (float)RAND_MAX) * 10;
	asteroid->thickness = 2.0;
	asteroid->alive = true;
	asteroid->color = al_map_rgba_f(1, 1, 1, 1);

	return asteroid;
}
