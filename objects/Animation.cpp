#include "../include/Animation.hpp"

Animation::Animation(ALLEGRO_BITMAP *pparent){
	this->parent = pparent;
}

void Animation::addFrame(int x, int y, int w, int h) {
	this->frames.push_back(al_create_sub_bitmap(this->parent,x,y,w,h));
	this->currentFrame = this->frames.begin();
}

ALLEGRO_BITMAP *Animation::getBitmap() {
	if (this->currentFrame == this->frames.end()) {
		this->currentFrame = this->frames.begin();
	}
	
	return *(this->currentFrame++);
}