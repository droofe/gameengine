#include <iostream>
#include "../include/Animation.hpp"

Animation::Animation(ALLEGRO_BITMAP *pparent){
	this->parent = pparent;
}

void Animation::addFrame(int x, int y, int w, int h) {
	this->frames.push_back(al_create_sub_bitmap(this->parent,x,y,w,h));
	this->currentFrame = this->frames.begin();
}

ALLEGRO_BITMAP *Animation::getBitmap() {
	return *(this->currentFrame);
}

void Animation::updateFrame() {
	printf("Updating frame %p\n", *this->currentFrame);
	if (this->currentFrame == this->frames.end()) {
		printf("Wrap\n");
		this->currentFrame = this->frames.begin();
	} else {
		printf("++\n");
		this->currentFrame++;
	}
}