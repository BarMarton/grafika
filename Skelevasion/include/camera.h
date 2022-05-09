#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"

#include <stdbool.h>
#include "bullet.h"

/**
 * Camera, as a moving point with direction
 */
typedef struct Camera
{
    vec3 position;
    vec3 rotation;
    vec3 speed;
    bool is_help, is_dead;
} Camera;

/**
 * Initialize the camera to the start position.
 */
void init_camera(Camera* camera);

/**
 * Update the position of the camera.
 */
void update_camera(Camera* camera, double time);

/**
 * Apply the camera settings to the view transformation.
 */
void set_view(const Camera* camera);

/**
 * Set the horizontal and vertical rotation of the view angle.
 */
void rotate_camera(Camera* camera, double horizontal, double vertical);

/**
 * Set the speed of forward and backward motion.
 */
void set_camera_speed(Camera* camera, double speed);

/**
 * Set the speed of left and right side steps.
 */
void set_camera_side_speed(Camera* camera, double speed);

//Simple getter functions
float get_camera_position_x(Camera* camera);

float get_camera_position_y(Camera* camera);

float get_camera_position_z(Camera* camera);

float get_camera_rotation_x(Camera* camera);

float get_camera_rotation_y(Camera* camera);

float get_camera_rotation_z(Camera* camera);

void check_camera_bullet_collision(Camera* camera, Bullet* bullet);
//void check_bullet_count(Camera* camera, Bullet* bullet);

#endif /* CAMERA_H */
