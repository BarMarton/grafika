#include <stdio.h>
#include <stdlib.h>

struct Brick {
    int a;
    int b;
    int c;
};

struct Brick set_size(){
    struct Brick CUBE;
    CUBE.a = 0;
    CUBE.b = 0;
    CUBE.c = 0;
    scanf("%i", &CUBE.a);
    scanf("%i", &CUBE.b);
    scanf("%i", &CUBE.c);
    return CUBE;
}

int calc_volume(struct Brick CUBE){
    return CUBE.a * CUBE.b * CUBE.c;
}

int calc_surface(struct Brick CUBE){
    return 2*(CUBE.a * CUBE.b + CUBE.a * CUBE.c + CUBE.b * CUBE.c);
}

int check_square(struct Brick CUBE){
    if(CUBE.a == CUBE.b || CUBE.b == CUBE.c || CUBE.a == CUBE.c) return 1;
    else return 0;
}
int main()
{
    struct Brick CUBE = set_size();
    int vol = calc_volume(CUBE);
    printf("%d\n", vol);
    int sur = calc_surface(CUBE);
    printf("%d\n", sur);
    int isSquare = check_square(CUBE);
    printf("%d\n", isSquare);
    return 0;
}
