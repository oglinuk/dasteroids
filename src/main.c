#include <stdbool.h>
#include "spaceship.h"

int main()
{
	int sw = 1280; // screen width
	int sh = 720; // screen height
	Spaceship *ship = new_ship(sw, sh);

	al_init();
	al_install_keyboard();
	if (!al_init_primitives_addon()) {
		printf("al_init_primitives_addon failed: %d", al_get_errno());
		exit(1);
	}

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	ALLEGRO_DISPLAY* display = al_create_display(sw, sh);
	ALLEGRO_FONT* font = al_create_builtin_font();

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	bool running = true;
	bool redraw = true;
	ALLEGRO_EVENT event;

	al_start_timer(timer);
	while (running) {
		al_wait_for_event(queue, &event);

		if (event.type == ALLEGRO_EVENT_TIMER)
			redraw = true;

		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_W:
				ship->location.y -= ship->acceleration_speed;
				break;
			case ALLEGRO_KEY_A:
				ship->yaw -= ship->turn_speed;
				break;
			case ALLEGRO_KEY_S:
				ship->location.y += ship->acceleration_speed;
				break;
			case ALLEGRO_KEY_D:
				ship->yaw += ship->turn_speed;
				break;
			case ALLEGRO_KEY_ESCAPE:
				running = false;
				break;
			}
		}

		// this bounds the player to the screen (man fmod)
		ship->location.x = fmod(ship->location.x + sw, sw);
		ship->location.y = fmod(ship->location.y + sh, sh);

		if (redraw && al_is_event_queue_empty(queue)) {
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_text(font, al_map_rgb(255, 255, 255),
				0, 0, 0, "Hello world from Allegro! Esc to quit.");
			draw_ship(ship);
			al_flip_display();

			redraw = false;
		}
	}

	al_destroy_font(font);
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	destroy_ship(ship);

	return 0;
}
