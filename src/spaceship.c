#include "entity.h"

Entity* new_ship(int screen_w, int screen_h)
{
	Entity *ship = malloc(sizeof(Entity));

	ship->location.x = screen_w / 2;
	ship->location.y = screen_h / 2;
	ship->screen.x = screen_w;
	ship->screen.y = screen_h;
	ship->yaw = 0.0;
	ship->acceleration_speed = M_SQRT2;
	ship->turn_speed = M_PI / 6;
	ship->velocity= 0.0;
	ship->thickness = 1.0;
	ship->alive = true;
	ship->color = al_map_rgba_f(0.0, 1.0, 0.0, 1);

	return ship;
}

void draw_ship(Entity *ship)
{
	al_identity_transform(&ship->transform);
	al_rotate_transform(&ship->transform, ship->yaw);
	al_translate_transform(&ship->transform,
		ship->location.x, ship->location.y);
	al_use_transform(&ship->transform);

	al_draw_line(-8.0, 9.0, 0.0, -11.0, ship->color, ship->thickness);	
	al_draw_line(0.0, -11.0, 8.0, 9.0, ship->color, ship->thickness);	
	al_draw_line(-6.0, 4.0, -1.0, 4.0, ship->color, ship->thickness);	
	al_draw_line(6.0, 4.0, 1.0, 4.0, ship->color, ship->thickness);	

	update_entity(ship, "ship");
}


