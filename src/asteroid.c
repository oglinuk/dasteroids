#include "entity.h"

const vec2d default_asteroid[] = {
	{-8.0, 9.0}, {0.0, -11.0},
	{0.0, -11.0}, {8.0, 9.0},
	{-6.0, 4.0}, {-1.0, 4.0},
	{6.0, 4.0}, {1.0, 4.0}
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
	asteroid->yaw = (rand() / (float)RAND_MAX) * 10;
	asteroid->velocity = (rand() / (float)RAND_MAX) * 10;
	asteroid->thickness = 2.0;
	asteroid->alive = true;
	asteroid->color = al_map_rgba_f(1, 1, 1, 1);

	return asteroid;
}
