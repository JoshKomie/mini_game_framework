# cpp_files := $(wildcard *.cpp)
cpp_files := $(wildcard *.cpp)
h_files   := $(wildcard *.h)	
obj_files := $(cpp_files:%.cpp=%.obj)

sdl_include := E:\Libraries\SDL2-2.0.16\include\ 
sdl_image_include := E:\Libraries\SDL2_image-2.0.5\include\ 
sdl_ttf_include := E:\Libraries\SDL2_ttf-2.0.15\include\ 

sdllibpath := "E:\Libraries\SDL2-2.0.16\lib\x64"
sdlimagelibpath := "E:\Libraries\SDL2_image-2.0.5\lib\x64"
sdlttflibpath := "E:\Libraries\SDL2_ttf-2.0.15\lib\x64"
libs := shell32.lib SDL2.lib SDL2main.lib SDL2_image.lib SDL2_ttf.lib
libs_no_main := shell32.lib SDL2.lib SDL2_image.lib SDL2_ttf.lib

includes := /I $(sdl_include) /I $(sdl_image_include) /I $(sdl_ttf_include)


mgf.lib: game.obj sdl_helper.obj input.obj texture.obj
	mkdir -p "build/mgf-1.0.0/lib/x64"
	mkdir -p "build/mgf-1.0.0/include"
	lib $(libpaths)  /OUT:build/mgf-1.0.0/lib/x64/$@ $^ 
	cp game.h build/mgf-1.0.0/include/game.h
	cp input.h build/mgf-1.0.0/include/input.h
	cp sdl_helper.h build/mgf-1.0.0/include/sdl_helper.h
	cp texture.h build/mgf-1.0.0/include/texture.h
	cp mgf.h build/mgf-1.0.0/include/mgf.h

#compile
%.obj: %.cpp
	cl -Zi /EHsc $(includes) /c $< 


.PHONY: clean
clean:
	rm -rf ./build/
