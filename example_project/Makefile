cpp_files := $(wildcard src/*.cpp)
obj_files := $(cpp_files:%.cpp=%.obj)

sdl_include := E:\Libraries\SDL2-2.0.16\include\ 
sdl_image_include := E:\Libraries\SDL2_image-2.0.5\include\ 
sdl_ttf_include := E:\Libraries\SDL2_ttf-2.0.15\include\ 

sdllibpath := "E:\Libraries\SDL2-2.0.16\lib\x64"
sdlimagelibpath := "E:\Libraries\SDL2_image-2.0.5\lib\x64"
sdlttflibpath := "E:\Libraries\SDL2_ttf-2.0.15\lib\x64"
mgflibpath := "E:\Libraries\mgf-1.0.0\lib\x64"
libs := shell32.lib SDL2.lib SDL2main.lib SDL2_image.lib SDL2_ttf.lib mgf.lib

includes := /I $(sdl_include) /I $(sdl_image_include) /I $(sdl_ttf_include) /I E:\Libraries\mgf-1.0.0\include\ 
libpaths := /LIBPATH:$(sdllibpath) /LIBPATH:$(sdlimagelibpath) /LIBPATH:$(sdlttflibpath) /LIBPATH:$(mgflibpath)

#link main
main.exe: $(obj_files)
	link /SUBSYSTEM:CONSOLE $(libpaths) /DEBUG:FULL /OUT:$@ $^ $(libs)

#compile
%.obj: %.cpp
	cl -Zi /EHsc $(includes) /Fo./src/ /c  $< 


.PHONY: clean
clean:
	rm -f main.exe
	rm -f $(wildcard *.obj)
