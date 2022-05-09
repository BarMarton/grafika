#ifndef BULLET_H
#define BULLET_H

#include "utils.h"

#include <stdbool.h>

/**
 * Camera, as a moving point with direction
 */
typedef struct Bullet
{
    vec3 position;
    vec3 speed;
    int bounces;
    bool is_dead;
} Bullet;


void init_bullet(Bullet* bullet, float pos_x, float pos_y, float pos_z, float rot_x, float rot_y, float rot_z);

void update_bullet(Bullet* bullet, double time);

void set_bullet_speed(Bullet* bullet, double speed);

void set_bullet_side_speed(Bullet* bullet, double speed);
#endif
