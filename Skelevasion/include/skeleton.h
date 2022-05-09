#ifndef SKELETON_H
#define SKELETON_H

#include "utils.h"
#include "camera.h"
#include "bullet.h"
#include <stdbool.h>
/**
 * Skeleton, as a moving point with direction
 */
typedef struct Skeleton
{
    vec3 position;
    vec3 rotation;
    vec3 speed;
    float speed_modifier;
    bool is_dead;
} Skeleton;

/**
 * Initialize the skeleton
 *to the start position.
 */
void init_skeleton(Skeleton* skeleton);

/**
 * Update the position of the skeleton
 *.
 */
void update_skeleton(Skeleton* skeleton, Camera* camera, double time);

/**
 * Apply the skeleton
 *settings to the view transformation.
 */

/**
 * Set the horizontal and vertical rotation of the view angle.
 */
void rotate_skeleton(Skeleton* skeleton, double horizontal, double vertical);

/**
 * Set the speed of forward and backward motion.
 */
void set_skeleton_speed(Skeleton* skeleton, double speed);

/**
 * Set the speed of left and right side steps.
 */
void set_skeleton_side_speed(Skeleton* skeleton, double speed);

float get_skeleton_position_x(Skeleton* skeleton);

float get_skeleton_position_y(Skeleton* skeleton);

float get_skeleton_position_z(Skeleton* skeleton);

float get_skeleton_rotation_x(Skeleton* skeleton);

float get_skeleton_rotation_y(Skeleton* skeleton);

float get_skeleton_rotation_z(Skeleton* skeleton);
#endif /* CAMERA_H */
