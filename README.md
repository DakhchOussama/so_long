# So Long Project

Welcome to the So Long project! 🕹️ This project involves creating a game using the MiniLibX graphics library. The player's goal is to collect every collectible on the map and then escape, choosing the shortest possible route.

## Project Overview

- **Libraries:** You must use the MiniLibX graphics library. You can either use the version available on the school machines or install it using its sources. 🖼️
- **Makefile:** Provide a Makefile to compile your source files. It must not relink. 🛠️
- **Map Description:** Your program must take a map description file as a parameter, ending with the .ber extension. 🗺️
- **Gameplay:**
  - The player uses the W, A, S, and D keys (or ZQSD or arrow keys) to move in four directions: up, down, left, and right. 🎮
  - The player cannot move into walls.
  - Display the current number of movements in the shell after every move. 🔄
  - The game does not have to be real-time.

## Graphic Management

- **Display:** Your program must display the game image in a window. 🪟
- **Window Management:** The window management must remain smooth, including changing to another window, minimizing, etc. 🔄
- **Exiting the Program:**
  - Pressing ESC must close the window and quit the program cleanly. 🚪
  - Clicking on the cross on the window's frame must also close the window and quit the program in a clean way.

## Map

- **Components:**
  - Walls (1)
  - Collectibles (C)
  - Free space (0)
  - Player's starting position (P)
  - Exit (E)
- **Valid Map:**
  - The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
  - No duplicate characters (exit/start) allowed.
  - The map must be rectangular and surrounded by walls.
  - There must be a valid path in the map.
- **Example Maps:**
  ```plaintext
  1111111111111
  10010000000C1
  1000011111001
  1P0011E000001
  1111111111111
  ```
## Bonus Part

While there are more interesting graphic projects later, you can earn extra points by implementing the following bonus features:

- Make the player lose when they touch an enemy patrol. ⚔️
- Add sprite animation. 🚶
- Display the movement count directly on the screen instead of writing it in the shell. 🔄

## How to Use 🚀

1. Clone the repository to your local machine.
2. Navigate to the project folder.
3. Build the project using the provided Makefile.
   ```
   $ make
   ```
Run the program with a valid .ber map file:
  ```
    $ ./so_long [map.ber]
  ```

Good luck with your game development! 🎮
