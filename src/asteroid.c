#include "entity.h"

Entity* new_asteroid(int screen_w, int screen_h)
{
	Entity *asteroid = malloc(sizeof(Entity));

	asteroid->location.x = rand() % screen_w;
	asteroid->location.y = rand() % screen_h;
	asteroid->screen.x = screen_w;
	asteroid->screen.y = screen_h;
	asteroid->yaw = (rand() / (float)RAND_MAX) * 10;
	asteroid->velocity = (rand() / (float)RAND_MAX) * 10;
	asteroid->thickness = 2.0;
	asteroid->alive = true;
	asteroid->color = al_map_rgba_f(1, 1, 1, 1);

	return asteroid;
}

void draw_asteroid(Entity *asteroid)
{
	al_identity_transform(&asteroid->transform);
	al_rotate_transform(&asteroid->transform, asteroid->yaw);
	al_translate_transform(&asteroid->transform,
		asteroid->location.x, asteroid->location.y);
	al_use_transform(&asteroid->transform);

	al_draw_line(-8.0, 9.0, 0.0, -11.0, asteroid->color, asteroid->thickness);	
	al_draw_line(0.0, -11.0, 8.0, 9.0, asteroid->color, asteroid->thickness);	
	al_draw_line(-6.0, 4.0, -1.0, 4.0, asteroid->color, asteroid->thickness);	
	al_draw_line(6.0, 4.0, 1.0, 4.0, asteroid->color, asteroid->thickness);	

	update_entity(asteroid, "asteroid");
}
