all:
	g++ -o main main.cc objects/Object.cpp objects/Drawable.cpp objects/Animation.cpp -lallegro -lallegro_primitives -lallegro_audio -lallegro_acodec -lallegro_font -lallegro_ttf -lallegro_main -lallegro_image
