#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "bullet.h"
#include "skeleton.h"
#include "model.h"

typedef struct Scene
{
    Model models[10];
    Material material, skybox;
    GLuint texture_id[10];
    double angle_weapon, angle_weapon_speed, bullet_x[100], bullet_y[100], skeleton_x[25], skeleton_y[25], skeleton_rotation[25], flashlight_power;
    bool weapon_fire, help_menu, flashlight, is_win;
    int kill_count;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene);
void update_bullets_scene(Scene* scene, Bullet* bullet, int i);//Update bullet specific information in the scene
void update_skeletons_scene(Scene* scene, Skeleton* skeleton, int i);//Update skeleton specific information in the scene
void check_win(Scene* scene, Skeleton* skeleton);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();
void show_picture(GLuint picture);
void check_skeleton_bullet_collision(Scene* scene, Skeleton* skeleton, Bullet* bullet);

#endif /* SCENE_H */
