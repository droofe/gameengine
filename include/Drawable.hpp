#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Object.hpp"
#include "Animation.hpp"
#include <map>
#include <string>

class Drawable : public Object {
	public:
		Drawable(uint px, uint py);
		Drawable(uint px, uint py, Animation *panimation);
		void draw();
		uint x, y;
		Animation *currentAnimation;
		std::map<std::string, Animation*> animations;
};

#endif