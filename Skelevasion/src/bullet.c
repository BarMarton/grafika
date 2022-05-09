#include "bullet.h"

#include <GL/gl.h>

#include <math.h>

void init_bullet(Bullet* bullet, float pos_x, float pos_y, float pos_z, float rot_x, float rot_y, float rot_z)
{
    double speed_modifier = 5;
    double angle;
    double side_angle;
    angle = degree_to_radian(rot_z);
    bullet->speed.x = cos(angle) * speed_modifier;
    bullet->speed.y = sin(angle) * speed_modifier;
    bullet->speed.z = 0;//rot_z * speed_modifier;
    bullet->position.x = pos_x + (bullet->speed.x * 0.2);
    bullet->position.y = pos_y + (bullet->speed.y * 0.2);
    bullet->position.z = pos_z;
    bullet->bounces = 0;
    bullet->is_dead = false;

    //printf("INIT BULLET");
}

void update_bullet(Bullet* bullet, double time)
{
    if(bullet->is_dead){
        bullet->position.x = -50;
        bullet->position.y = -50;
        bullet->position.z = -50;
    }
    else {
        bullet->position.x += bullet->speed.x * time;
        bullet->position.y += bullet->speed.y * time;
        bullet->position.z += bullet->speed.z * time;
        //Bounces
        if (bullet->position.x >= 10.0 || bullet->position.x <= -10.0) {
            bullet->speed.x = -1.0 * bullet->speed.x;
            bullet->bounces++;
        }
        if (bullet->position.y >= 10.0 || bullet->position.y <= -10.0) {
            bullet->speed.y = -1.0 * bullet->speed.y;
            bullet->bounces++;
        }
        if (bullet->position.z >= 20.0 || bullet->position.z <= 0.0) {
            bullet->speed.z = -1.0 * bullet->speed.z;
            bullet->bounces++;
        }
        if (bullet->bounces >= 3) {
            bullet->is_dead = true;
        }
    }
    //printf("BULLET: X: %f Y: %f Z: %f\n", bullet->position.x, bullet->position.y, bullet->position.z);
}

/*void set_view(const Camera* camera)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-(camera->rotation.x + 90), 1.0, 0, 0);
    glRotatef(-(camera->rotation.z - 90), 0, 0, 1.0);
    glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);
}


void set_camera_speed(Camera* camera, double speed)
{
    camera->speed.y = speed;
}

void set_camera_side_speed(Camera* camera, double speed)
{
    camera->speed.x = speed;
}
*/

