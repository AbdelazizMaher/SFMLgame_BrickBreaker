# Brick Breaker Game

## Overview
The **Brick Breaker Game** is a classic arcade-style game where the player controls a paddle to bounce a ball and break bricks. The game is built using C++ and the Simple and Fast Multimedia Library **`(**SFML**)`**, providing an engaging visual and interactive experience.

## Features
- **`Responsive Paddle Movement`**: The player controls the `paddle using the keyboard`.
- **`Dynamic Ball Physics`**: The ball bounces off the paddle, walls, and bricks, following realistic physics.
- **`Brick Interaction`**: Bricks can be weakened and destroyed upon collision with the ball.bricks require multiple hits to break.
- **`Game States`**: The game supports multiple states, including `PAUSED`, `RUNNING`, `GAME_OVER`, and `PLAYER_WINS`.
- **`On-screen Display`**: The game displays the current state and the number of lives remaining.

## SFML Features & APIs Used

- **`sf::RenderWindow`**: Manages the main window where the game is rendered.
- **`sf::Texture`**: Handles the images used for the game’s background, ball, bricks, and paddle.
- **`sf::Sprite`**: Represents 2D images (textures) and allows for easy manipulation like scaling, rotation, and movement.
- **`sf::Event`**: Handles input events like keyboard presses to control the paddle.
- **`sf::Clock & sf::Time`**: Manages the game’s timing, ensuring consistent movement across different systems.
- **`sf::Vector2f`**: Handles 2D positions and velocities in the game.

  ## Files Overview

### Main Files
- **main.cpp**: The entry point of the application, responsible for setting up the game loop, initializing objects, and managing the game flow.

### Background Module
- **`background.h`**: Declares the `Background` class, which manages the game’s background.
- **`background.cpp`**: Implements the `Background` class, handling the loading and rendering of the background texture.

### Ball Module
- **`ball.h`**: Declares the `Ball` class, which manages the ball's properties and behavior.
- **`ball.cpp`**: Implements the `Ball` class, handling movement, collision detection, and rendering.

### Brick Module
- **`brick.h`**: Declares the `Brick` class, representing individual bricks in the game.
- **`brick.cpp`**: Implements the `Brick` class, managing the state and rendering of bricks.

### Entity Module
- **`entityManager.h`**: Declares the `EntityManager` class, responsible for managing game entities.
- **`entityManager.cpp`**: Implements the `EntityManager` class, handling entity updates and interactions.

### Game Module
- **`game.h`**: Declares the `Game` class, which encapsulates the game logic and states.
- **`game.cpp`**: Implements the `Game` class, managing the game loop, state transitions, and rendering.

### Paddle Module
- **`paddle.h`**: Declares the `Paddle` class, which controls the player's paddle.
- **`paddle.cpp`**: Implements the `Paddle` class, handling input and paddle movement.

### Interaction Module
- **`entitesInteraction.h`**: Declares functions that handle interactions between various game entities, such as collisions.
- **`entitesInteraction.cpp`**: Implements interaction logic, ensuring proper responses when entities collide.

### Resource Files
- **`background.jpg`**: The background image used in the game.
- **`ball.png`**: The image representing the ball.
- **`brick01.png`**: The image representing a single brick.
- **`paddle.png`**: The image representing the paddle.

## How to Build
To build this project, use CMake to generate the necessary build files and compile the code.

```bash
mkdir build
cd build
cmake ..
make
```
