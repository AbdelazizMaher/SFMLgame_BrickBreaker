#include "entitesInteraction.h"

bool isInteracting(const gameEntity& e1, const gameEntity& e2)
{
	auto entity1 = e1.getBoundingBox();
	auto entity2 = e2.getBoundingBox();

	return entity1.intersects(entity2);
}

void handleCollision(ball& ball, const paddle& paddle)
{
	if (isInteracting(ball, paddle))
	{
		// Make the ball bounce upwards
		ball.moveUp();

		// Make the new direction depend on where the collision occurs on the paddle
		// If the collision is on the left of the paddle, make the ball bounce to the left
		if (ball.Xpos() < paddle.Xpos())
			ball.moveLeft();
		else if (ball.Xpos() > paddle.Xpos())
			ball.moveRight();
		else
			ball.stopMoving();
	}
}

void handleCollision(ball& ball, brick& brick)
{
    if (isInteracting(ball, brick)) {
        // Update the brick's strength
        brick.weaken();

        // The brick is destroyed
        if (brick.isTooWeak())
            brick.destroyEntity();   

        // Make the new direction depend on where the collision occurs on the brick
        // If the ball collides on the side of the brick, make the ball bounce to the left/right
        // If the ball collides on the top/bottom of the brick, make the ball bounce upwards/downwards

        // First we find the amount of overlap in each direction
        // The smaller the left overlap, the closer the ball is to the left side of the brick
        // And similarly for the other sides of the brick
        float leftOverlap = ball.rightBound() - brick.leftBound();
        float rightOverlap = brick.rightBound() - ball.leftBound();
        float topOverlap = ball.bottomBound() - brick.topBound();
        float bottomOverlap = brick.bottomBound() - ball.topBound();

        // If the left overlap is smaller than the right overlap, the ball hit the left side
        bool fromLeft = std::abs(leftOverlap) < std::abs(rightOverlap);
        bool fromTop = std::abs(topOverlap) < std::abs(bottomOverlap);

        // Use the right or left overlap as appropriate
        float minXoverlap = fromLeft ? leftOverlap : rightOverlap;
        float minYoverlap = fromTop ? topOverlap : bottomOverlap;

        // If the ball hit the left or right side of the brick, change its horizontal direction
        // If the ball hit the top or bottom of the brick, change its vertical direction
        if (std::abs(minXoverlap) < std::abs(minYoverlap)) {
            if (fromLeft)
                ball.moveLeft();
            else
                ball.moveRight();
        }
        else {
            if (fromTop)
                ball.moveUp();
            else
                ball.moveDown();
        }
    }
}
