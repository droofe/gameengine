#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "include/Drawable.hpp"

int main(int argc, char **argv) {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *eventQueue;

	bool quit = false;

	if (!al_init() || !al_init_image_addon()) {
		fprintf(stderr, "Failed to init!\n");
		return -1;
	}

	display = al_create_display(640, 480);
	if (!display) {
		fprintf(stderr, "Failed to create display!\n");
		return -1;
	}

	ALLEGRO_BITMAP *sheet = al_load_bitmap("resources/mega.png");
	
	if (!sheet) {
		fprintf(stderr, "Couldn't load spritesheet\n");
		return -1;
	}

	eventQueue = al_create_event_queue();
	al_register_event_source(eventQueue, al_get_display_event_source(display));

	std::list<Animation*> animations;

	Animation run(sheet);
	run.addFrame(8, 13, 21, 24);
	run.addFrame(58, 13, 21, 24);

	animations.push_back(&run);

	std::list<Drawable*> drawableObjects;

	Drawable player1(100, 200, &run);
	drawableObjects.push_back(&player1);
	Drawable player2(200, 200, &run);
	drawableObjects.push_back(&player2);

	while (!quit) {
		ALLEGRO_EVENT event;
		ALLEGRO_TIMEOUT timeout;

		al_set_target_bitmap(al_get_backbuffer(display));
		al_init_timeout(&timeout, 0.10);
		bool get_event = al_wait_for_event_until(eventQueue, &event, &timeout);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			quit = true;
		}

		al_clear_to_color(al_map_rgb(0,0,100));

		std::list<Drawable*>::iterator dit;
		for (dit = drawableObjects.begin(); dit != drawableObjects.end(); ++dit) {
			ALLEGRO_BITMAP *image = (*dit)->currentAnimation->getBitmap();
			al_draw_bitmap(image, (*dit)->x, (*dit)->y, 1);
		}

		std::list<Animation*>::iterator ait;
		for (ait = animations.begin(); ait != animations.end(); ++ait) {
			(*ait)->updateFrame();
		}

		al_flip_display();
	}


	al_destroy_display(display);
}