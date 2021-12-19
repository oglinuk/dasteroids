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
	vec2d location;
	int sw;
	int sh;
	float yaw;
	float acceleration_speed;
	float turn_speed;
	float velocity;
	float thickness;
	bool alive;
	ALLEGRO_COLOR color;
	ALLEGRO_TRANSFORM transform;
} Spaceship;

Spaceship* new_ship(int screen_w, int screen_h);
void destroy_ship(Spaceship *ship);
void draw_ship(Spaceship *ship);
void update_ship(Spaceship *ship);
