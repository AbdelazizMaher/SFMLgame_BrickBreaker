#pragma once

#include "ball.h"
#include "paddle.h"
#include "brick.h"

// Determine whether two entities overlap
bool isInteracting(const gameEntity& e1, const gameEntity& e2);

// Resolve potential collision between the ball and the paddle
void handleCollision(ball& ball, const paddle& paddle);

// Resolve potential collision between the ball and a brick
void handleCollision(ball& ball, brick& brick);