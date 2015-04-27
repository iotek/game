#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include "animation.h"

#define ENTITY_TYPE_DEFAULT 0
#define ENTITY_TYPE_MAIN_CHARACTER 1
#define ENTITY_TYPE_PET 2

typedef struct {
    // pos
    float x, y;
    // body size
    float w,h;
    float x_vel, y_vel;
    float velocity;
    int type;
    // animation
    animationCollection animations;
    animation* anim;
} entity;

entity* CreateEntity(int x, int y, int w, int h,animationCollection animations);

void rendererEntity(SDL_Renderer *ren, entity *e);
void updateEntity(entity *e, float deltaTimeS);
void eventEntity(entity * e, SDL_Event event, float deltaTimeS);

// Use these functions to move the entity
void entity_move_left(entity*, float);
void entity_move_right(entity*, float);
void entity_move_up(entity*, float);
void entity_move_down(entity*, float);

void entity_move(entity*, float, float);
#endif  // ENTITY_H
