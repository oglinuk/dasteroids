#include "entity.h"

int main()
{
	int difficulty = 10;
	int sw = 1280; // screen width
	int sh = 720; // screen height
	Entity *ship = new_ship(sw, sh);
	Entity *asteroids[difficulty];

	int i;
	for (i = 0; i < difficulty; i++)
		asteroids[i] = new_asteroid(sw, sh);

	al_init();
	al_install_keyboard();
	if (!al_init_primitives_addon()) {
		printf("al_init_primitives_addon failed: %d", al_get_errno());
		exit(1);
	}

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	ALLEGRO_DISPLAY* display = al_create_display(sw, sh);

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
			case ALLEGRO_KEY_UP:
				if (ship->velocity < 9.899494936611665)
					ship->velocity += ship->acceleration_speed;
				break;
			case ALLEGRO_KEY_A:
			case ALLEGRO_KEY_LEFT:
				ship->yaw -= ship->turn_speed;
				break;
			case ALLEGRO_KEY_S:
			case ALLEGRO_KEY_DOWN:
				if (ship->velocity > -4.242640687119286)
					ship->velocity -= ship->acceleration_speed;
				break;
			case ALLEGRO_KEY_D:
			case ALLEGRO_KEY_RIGHT:
				ship->yaw += ship->turn_speed;
				break;
			case ALLEGRO_KEY_ESCAPE:
				running = false;
				break;
			}
		}


		if (redraw && al_is_event_queue_empty(queue)) {
			al_clear_to_color(al_map_rgb(0, 0, 0));
			draw_entity(ship);
			for (i = 0; i < difficulty; i++)
				draw_entity(asteroids[i]);
			al_flip_display();
			redraw = false;
		}
	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	destroy_entity(ship);
	for (i = 0; i < difficulty; i++)
		destroy_entity(asteroids[i]);

	return 0;
}
