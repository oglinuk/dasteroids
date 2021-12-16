#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <stdio.h>

// see https://stackoverflow.com/a/44748651 && Day 3
typedef struct vec2d {
	float x;
	float y;
} vec2d;

typedef struct Spaceship {
	const vec2d *shape;
	vec2d *vertex;
	int vertices;
	vec2d location;
	float yaw;
	float acceleration_speed;
	float turn_speed;
	float velocity;
	float thickness;
	bool alive;
	ALLEGRO_COLOR color;
} Spaceship;

Spaceship* new_ship(int screen_w, int screen_h);
void destroy_ship(Spaceship *ship);
void draw_ship(Spaceship *ship);
void update_ship(Spaceship *ship);
