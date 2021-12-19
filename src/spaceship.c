#include "spaceship.h"

Spaceship* new_ship(int screen_w, int screen_h)
{
	Spaceship *ship = malloc(sizeof(Spaceship));

	ship->location.x = screen_w / 2;
	ship->location.y = screen_h / 2;
	ship->sw = screen_w;
	ship->sh = screen_h;
	ship->yaw = 0.0;
	ship->acceleration_speed = M_SQRT2;
	ship->turn_speed = M_PI / 6;
	ship->velocity= 0.0;
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
	al_identity_transform(&ship->transform);
	al_rotate_transform(&ship->transform, ship->yaw);
	al_translate_transform(&ship->transform,
		ship->location.x, ship->location.y);
	al_use_transform(&ship->transform);

	al_draw_line(-8.0, 9.0, 0.0, -11.0, ship->color, ship->thickness);	
	al_draw_line(0.0, -11.0, 8.0, 9.0, ship->color, ship->thickness);	
	al_draw_line(-6.0, 4.0, -1.0, 4.0, ship->color, ship->thickness);	
	al_draw_line(6.0, 4.0, 1.0, 4.0, ship->color, ship->thickness);	

	update_ship(ship);
}

void update_ship(Spaceship *ship)
{
	ship->location.x -= sin(-ship->yaw) * ship->velocity;
	ship->location.y -= cos(-ship->yaw) * ship->velocity;

	ship->location.x = fmod(ship->location.x + ship->sw, ship->sw);
	ship->location.y = fmod(ship->location.y + ship->sh, ship->sh);

	printf("ship->yaw: %f | ship->location.x: %f | ship->location.y: %f\n",
		ship->yaw, ship->location.x, ship->location.y);
}
