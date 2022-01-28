# Srevertt's Pong Remake v1.0.1
## About
 A remake of Pong using C++ and SDL2. The game is currently in its first
 release, so expect some bugs. Linux/MacOS support will come soon.

 ## Running
 To run this program, you must go to https://github.com/srevrtt/srevrtt-pong/releases and download the .zip file on there. **Everything you need to compile is in there.**

 ## Building (only Windows support currently)
 ### Windows
To build on windows, you need to install mingw32. Use these commmands to install. You must have Git installed. You can use Powershell to use these commands. **Do not** run as administrator.

- `$ git clone --recursive https://github.com/srevrtt/srevrtt-pong.git`
- `$ cd srevrtt-pong`
- `$ make`
- `$ ./bin/game.exe`

## Controls
- W key: move first paddle up
- S key: move first paddle down
- Up arrow key: move second paddle up
- Down arrow key: move second paddle down
- Q key: start game
- Escape key: pause
- Space key: unpause

## Release v1.0.1
Added more DLLs in the binary so the user does not have to install mingw.

## TODOs:
- Add AI
- Add start screen
- Revamp ball physics
- Add a play again button when a player wins
- Add Linux/MacOS support
