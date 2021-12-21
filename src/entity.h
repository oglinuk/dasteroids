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
	const char* name;
	vec2d location;
	vec2d screen;
	const vec2d *shape;
	float yaw;
	float acceleration_speed;
	float turn_speed;
	float velocity;
	float thickness;
	bool alive;
	ALLEGRO_COLOR color;
	ALLEGRO_TRANSFORM transform;
} Entity;

void draw_entity(Entity *e);
void update_entity(Entity *e);
void destroy_entity(Entity *e);

Entity* new_ship(int screen_w, int screen_h);
Entity* new_asteroid(int screen_w, int screen_h);
