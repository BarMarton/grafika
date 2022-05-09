#include "skeleton.h"

#include <GL/gl.h>

#include <math.h>
#include <time.h>
void init_skeleton(Skeleton* skeleton)
{
    srand(time(0));
    skeleton->speed_modifier = 0.02;
    skeleton->position.x = rand() % (19) - 9;
    skeleton->position.y = 0.2;
    skeleton->position.z = rand() % (19) - 9;
    skeleton->rotation.x = 90.0;
    skeleton->rotation.y = 0.0;
    skeleton->rotation.z = 0.0;
    skeleton->speed.x = 0;
    skeleton->speed.y = 0;
    skeleton->speed.z = 0.0;
    skeleton->is_dead = false;
}

void update_skeleton(Skeleton* skeleton, Camera* camera, double time)
{
        //movement
        if(skeleton->is_dead){
            skeleton->rotation.z = 0;
            skeleton->position.x = 50;
            skeleton->position.y = 50;
        }
        else{
            skeleton->rotation.z += 360 * time;
            skeleton->speed.x = -(skeleton->position.x - camera->position.x);
            skeleton->speed.y = -(skeleton->position.y - camera->position.y);
            skeleton->position.x += skeleton->speed.x * skeleton->speed_modifier;
            skeleton->position.y += skeleton->speed.y * skeleton->speed_modifier;
        }
        //Player death
        if(pow(skeleton->position.x - camera->position.x, 2) + pow(skeleton->position.y - camera->position.y, 2) < 1){
            camera->is_dead = true;
        }

}


void rotate_skeleton(Skeleton* skeleton, double horizontal, double vertical)
{
    skeleton->rotation.z += horizontal;

    if (skeleton->rotation.z < 0) {
        skeleton->rotation.z += 360.0;
    }

    if (skeleton->rotation.z > 360.0) {
        skeleton->rotation.z -= 360.0;
    }

    if (skeleton->rotation.x < 0) {
        skeleton->rotation.x += 360.0;
    }

    if (skeleton->rotation.x > 360.0) {
        skeleton->rotation.x -= 360.0;
    }
}

float get_skeleton_position_x(Skeleton* skeleton){
    return skeleton->position.x;
}
float get_skeleton_position_y(Skeleton* skeleton){
    return skeleton->position.y;
}
float get_skeleton_position_z(Skeleton* skeleton){
    return skeleton->position.z;
}
float get_skeleton_rotation_x(Skeleton* skeleton){
    return skeleton->rotation.x;
}
float get_skeleton_rotation_y(Skeleton* skeleton){
    return skeleton->rotation.y;
}
float get_skeleton_rotation_z(Skeleton* skeleton){
    return skeleton->rotation.z;
}
void set_skeleton_speed(Skeleton* skeleton, double speed)
{
    skeleton->speed.y = speed;
}

void set_skeleton_side_speed(Skeleton* skeleton, double speed)
{
    skeleton->speed.x = speed;
}

