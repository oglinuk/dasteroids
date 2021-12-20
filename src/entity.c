#include "entity.h"


void update_entity(Entity *e, const char* name)
{
	e->location.x -= sin(-e->yaw) * e->velocity;
	e->location.y -= cos(-e->yaw) * e->velocity;

	// bound entity to the screen resolution
	e->location.x = fmod(e->location.x + e->screen.x, e->screen.x);
	e->location.y = fmod(e->location.y + e->screen.y, e->screen.y);

	printf("%s->yaw: %f | %s->location.x: %f | %s->location.y: %f\n",
		name, e->yaw, name, e->location.x, name, e->location.y);
}

void destroy_entity(Entity *e)
{
	free(e);
}
