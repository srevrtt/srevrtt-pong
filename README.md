# Srevertt's Pong Remake v1.0
## About
 A remake of Pong using C++ and SDL2. The game is currently in its first
 release, so expect some bugs. Linux/MacOS support will come soon.

 ## Running
 To run this program, you must go to https://github.com/srevrtt/srevrtt-pong/releases and download the .zip file on there. You can follow the directions on the release. **You also need MinGW**. You can install it by going to https://www.mingw-w64.org/downloads, or you can install a package manager to install mingw32. 
 
 **I recommend a package manager, as it is easier to install everything that you need.** I would recommend Chocolatey. To install Chocolatey, go to https://chocolatey.org/install. After that, open Powershell as an administrator (right click and click "Open As Administrator"). Then type in `$ choco install mingw`. Finally, you can run the program.

 ## Building (only Windows support currently)
 ### Windows
To build on windows, you need to install mingw32. Use these commmands to install. You must have Git installed. You can use Powershell to use these commands. **Do not** run as administrator.

- `$ git clone --recursive https://github.com/srevrtt/srevrtt-pong.git`
- `$ cd srevrtt-pong`
- `$ make`
- `$ ./bin/game.exe`
