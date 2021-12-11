#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

typedef struct Spaceship {
	float screen_x;
	float screen_y;
	float direction;
	float speed;
	float thickness;
	bool alive;
	ALLEGRO_COLOR color;
} Spaceship;

Spaceship* new_ship(int screen_w, int screen_h);
void destroy_ship(Spaceship *ship);
void draw_ship(Spaceship *ship);
