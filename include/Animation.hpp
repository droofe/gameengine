#ifndef ANIMATION_H
#define ANIMATION_H

#include <list>
#include <allegro5/allegro.h>

class Animation {
	public:
		Animation(ALLEGRO_BITMAP *pparent);
		void addFrame(int x, int y, int w, int h);
		ALLEGRO_BITMAP *getBitmap();
	protected:
		std::list<ALLEGRO_BITMAP*> frames;
		std::list<ALLEGRO_BITMAP*>::iterator currentFrame;
		ALLEGRO_BITMAP *parent;
};

#endif