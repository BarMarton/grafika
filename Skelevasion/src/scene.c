#include "scene.h"

#include "load.h"
#include "draw.h"

void init_scene(Scene* scene)
{
    //Load models and textures
    load_model(&(scene->models[0]), "ASSETS/Models/MAP.obj");
    scene->texture_id[0] = load_texture("ASSETS/Textures/MAP.jpg");
    load_model(&(scene->models[1]), "ASSETS/Models/USP.obj");
    scene->texture_id[1] = load_texture("ASSETS/Textures/AWP.png");
    load_model(&(scene->models[2]), "ASSETS/Models/SKELETON.obj");
    scene->texture_id[2] = load_texture("ASSETS/Textures/SKELETON.png");
    load_model(&(scene->models[3]), "ASSETS/Models/BULLET.obj");
    scene->texture_id[3] = load_texture("ASSETS/Textures/BULLET.png");
    scene->texture_id[4] = load_texture("ASSETS/Textures/HELP.jpg");
    scene->texture_id[5] = load_texture("ASSETS/Textures/VICTORY.jpg");
    scene->texture_id[6] = load_texture("ASSETS/Textures/DEFEAT.png");
    load_model(&(scene->models[4]), "ASSETS/Models/FLASHLIGHT.obj");
    scene->texture_id[7] = load_texture("ASSETS/Textures/FLASHLIGHT.jpg");


    //init weapon
    scene->angle_weapon = 1;
    scene->angle_weapon_speed = 0;
    scene->flashlight = false;
    scene->flashlight_power = 3;

    //init bullet
    for(int i = 0; i < 100; i++){
        scene->bullet_x[i] = -200;
        scene->bullet_y[i]= -200;
    }
    //init skeleton
    for(int i = 0; i < 25; i++){
        scene->skeleton_x[i] =  200;
        scene->skeleton_y[i] =  200;
        scene->skeleton_rotation[i] =  0;
    }
    scene->is_win = false;
    scene->kill_count = 0;

    scene->material.ambient.red = 0.0;
    scene->material.ambient.green = 0.0;
    scene->material.ambient.blue = 0.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;
}

void set_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void check_win(Scene* scene, Skeleton* skeleton){
    if(skeleton->is_dead){
        scene->is_win = true;
    }
}
void update_skeletons_scene(Scene* scene, Skeleton* skeleton, int i){
    scene->skeleton_x[i] = skeleton->position.x;
    scene->skeleton_y[i] = skeleton->position.y;
    scene->skeleton_rotation[i] = skeleton->rotation.z;

}
void update_bullets_scene(Scene* scene, Bullet* bullet, int i){
    scene->bullet_x[i] = bullet->position.x;
    scene->bullet_y[i] = bullet->position.y;
}

void update_scene(Scene* scene)
{
    if (scene->angle_weapon > 360)
        scene->angle_weapon  = 0.1;
    else
        scene->angle_weapon  = scene->angle_weapon  + scene->angle_weapon_speed*2;
    if (scene->kill_count > 4){
        scene->is_win = true;
    }
}

void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
    //draw_origin();

    //Map
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->texture_id[0]);
    glRotatef(90, 90, 0, 0);
    glTranslatef(0, 0, 0);
    glScalef(2, 2, 2);
    draw_model(&(scene->models[0]));
    glPopMatrix();

    //Weapon
    glBindTexture(GL_TEXTURE_2D, scene->texture_id[1]);
    glPushMatrix();
    glLoadIdentity();
    glRotatef(0,0,0,0);
    glScalef(0.1,0.1,0.1);
    glTranslatef(5, -5,-10);
    glRotatef(-scene->angle_weapon,1,0,0);
    draw_model(&(scene->models[1]));
    glPopMatrix();

    //Skeleton
    for(int i = 0; i < 25; i++){
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->texture_id[2]);
        glTranslatef(scene->skeleton_x[i], scene->skeleton_y[i] , 0.2);
        glRotatef(90, 1, 0, 0);
        glRotatef(scene->skeleton_rotation[i], 0 , scene->skeleton_y[i], 0);
        glScalef(1, 1, 1);
        draw_model(&(scene->models[2]));
        glPopMatrix();
    }


    //Bullet
    for(int i = 0; i < 100; i++){
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->texture_id[3]);
        glRotatef(0, 0, 0, 0);
        glTranslatef(scene->bullet_x[i], scene->bullet_y[i], 1);
        glScalef(0.1, 0.1, 0.1);
        draw_model(&(scene->models[3]));
        glPopMatrix();
    }

    if(scene->flashlight){
        glEnable(GL_LIGHT1);
        GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 0.0 };
        GLfloat light_diffuse[] = { scene->flashlight_power, scene->flashlight_power, scene->flashlight_power, 1.0 };
        GLfloat light_specular[] = { 0.0, 0.0, 0.0, 0.0 };
        GLfloat light_position[] = { 0.0, 0.0, 1.0, 0.0 };
        GLfloat spot_direction[] = { 0.0, 0.0, -1.0 };
        glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
        glPushMatrix();
        glLoadIdentity();
        glLightfv(GL_LIGHT1, GL_POSITION, light_position);
        glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 35);
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
        glPopMatrix();

        glBindTexture(GL_TEXTURE_2D, scene->texture_id[7]);
        glPushMatrix();
        glLoadIdentity();
        glScalef(0.1,0.1,0.1);
        glTranslatef(-5,-5,-10);
        glRotatef(90,0,0,1);
        glRotatef(90,0,1,0);
        draw_model(&(scene->models[4]));
        glPopMatrix();
    } else {
        glDisable(GL_LIGHT1);
    }
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
void show_picture(GLuint picture) {
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, picture);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3d(-2, 1.5, -2.5);
    glTexCoord2f(1, 0);
    glVertex3d(2, 1.5, -2.5);
    glTexCoord2f(1, 1);
    glVertex3d(2, -1.5, -2.5);
    glTexCoord2f(0, 1);
    glVertex3d(-2, -1.5, -2.5);
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

}
void check_skeleton_bullet_collision(Scene* scene, Skeleton* skeleton, Bullet* bullet){
    if(pow(skeleton->position.x - bullet->position.x, 2) + pow(skeleton->position.y - bullet->position.y, 2) < 1){
        skeleton->is_dead = true;
        bullet->is_dead = true;
        scene->kill_count++;
    }
}
