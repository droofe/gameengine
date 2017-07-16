#include "../include/Drawable.hpp"

Drawable::Drawable(uint px, uint py){
	this->x = px;
	this->y = py;
}

Drawable::Drawable(uint px, uint py, Animation *panimation){
	this->x = px;
	this->y = py;
	this->currentAnimation = panimation;
	this->animations["start"] = this->currentAnimation;
}

