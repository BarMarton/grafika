all:
	gcc -Iinclude/ src/app.c src/camera.c src/main.c src/scene.c src/texture.c src/utils.c  src/draw.c src/info.c src/load.c src/model.c src/transform.c src/bullet.c src/skeleton.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lobj -lopengl32 -lm -o cube.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/app.c src/camera.c src/main.c src/scene.c src/texture.c src/utils.c  src/draw.c src/info.c src/load.c src/model.c src/transform.c src/bullet.c src/skeleton.c -L obj/libobj.a -lSDL2 -lSDL2_image -lSDL2_gfx -lGL -lm -o skelevasion -Wall -Wextra -Wpedantic