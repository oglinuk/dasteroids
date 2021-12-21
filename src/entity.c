#include "entity.h"

void draw_entity(Entity *e)
{
	al_identity_transform(&e->transform);
	al_rotate_transform(&e->transform, e->yaw);
	al_translate_transform(&e->transform,
		e->location.x, e->location.y);
	al_use_transform(&e->transform);

	int j = 1;
	for (int i = 0; i < sizeof(e->shape); i++) {
		printf("shape[%d]: %f %f | shape[%d]: %f %f\n",
			i, e->shape[i].x, e->shape[i].y,
			j, e->shape[j].x, e->shape[j].y);

		al_draw_line(e->shape[i].x, e->shape[i].y,
			e->shape[j].x, e->shape[j].y,
			e->color, e->thickness);

		i++;
		j+=2;
	}
	update_entity(e);
}

void update_entity(Entity *e)
{
	e->location.x -= sin(-e->yaw) * e->velocity;
	e->location.y -= cos(-e->yaw) * e->velocity;

	// bound entity to the screen resolution
	e->location.x = fmod(e->location.x + e->screen.x, e->screen.x);
	e->location.y = fmod(e->location.y + e->screen.y, e->screen.y);

	printf("%s velocity: %f | yaw: %f | location (x,y): %f, %f\n",
		e->name, e->velocity, e->yaw, e->location.x, e->location.y);
}

void destroy_entity(Entity *e)
{
	free(e);
}
