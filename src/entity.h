#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <stdio.h>

// see https://stackoverflow.com/a/44748651 && Day 3
typedef struct vec2d {
	float x;
	float y;
} vec2d;

typedef struct Entity {
	vec2d location;
	vec2d screen;
	float yaw;
	float acceleration_speed;
	float turn_speed;
	float velocity;
	float thickness;
	bool alive;
	ALLEGRO_COLOR color;
	ALLEGRO_TRANSFORM transform;
} Entity;

void destroy_entity(Entity *e);
void update_entity(Entity *e, const char* name);

Entity* new_ship(int screen_w, int screen_h);
void draw_ship(Entity *ship);

Entity* new_asteroid(int screen_w, int screen_h);
void draw_asteroid(Entity *asteroid);
