# Welcome to tetris!

## how to run
```bash
mingw32-make run
```

## how does it work
I use two buffers to make the Tetris game. The first buffer is the dynamic buffer. This buffer is where the block falling animation occurs and it gets cleared every game step. The second buffer is the baked buffer. Whenever a block is placed, it is transferred to the baked buffer where it is placed ‘permanently’. The buffers consist of a grid of numbers. These numbers correspond to the type of pixel. For example; the number ‘0’ corresponds to two spaces or the padding. ‘1’ is a white pixel, ‘2’ is red, etc. The Console class then takes both of these buffers and merges them into one. This buffer is then translated to characters and color codes and then sent to the console. Where the image is then displayed.

Collision detection happens in the TetrisBlock class where it queries the Graphics class if there is a block at a certain position inits buffer. If there is for example a block right unter the TetrisBlock, it knows not to move down anymore.

I chose to use the block character “██” as pixels. They look like “██” in the console. I put two of them together to make a rough square. This makes the game a little more visually pleasing.  The colors come from special color characters used in the console. You can find them in Console.h



## General

- The whole app/game should be object oriented. No global stuff. Main should also be clean.
- Code should be your own. You can research techniques and such but no code copy pasting. If teacher finds out (and he/she does 9 out of 10 times), the other guy/girl gets the grades and not you.
- Decent GIT history so teacher can track your progress through time. This means committing often and committing small. This is also part of proving your code is your own.
- Provide a decent README explaining your project, how it is structured, what fancy techniques you used, how someone can build your app and how to run it. Also add a couple of screenshots in your README off how your app looks.
- A makefile so the user only needs to use `make` to build your app.
- Check if your application runs on other systems (Windows vs Linux). If not, no problem, but make sure to document this inside your README.
