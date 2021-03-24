# My World

I did this project during my first year of studies.
The goal was to make a world-building tool allowing us to edit terrain height.

I decided, unlike examples, to split terrain into many vertices, and therefore have it more detailed.

there are two tools available :
- shaping represented by the curve
- flatten represented by the rectangle

To allow the user to transform their world efficiently, I created a soft brush for the shaping tool.

Τhe flatten tool brush is round, and nearly as tall as the shaping one.
It will set the height around your cursor to the level of the point you started on.

I had to use CSFML (SFML's C binding)

# Usage

command-line arguments
--------------------------

-h: print this file's content into the standard output

-l: load an existing file  
example: "./my_world -l myfile"

-n: the application will save the world to the specified file path.  
example: "./my_world -n mynewfile"

in-app hotkeys
---------------------------
Inside the application, you can use W and S keys to zoom in and out.
You can also slightly rotate the world with A and D.
And save the world with F.

# Main problems

While trying to transform the world around a hill, the change can happen on the ground behind the hill.  
I had an idea about how to fix it, but I lacked time.

Height is represented by luminosity.  
Adding textures to the ground instead might imrpove clarity.

Tools lacks settings.  
Menu to configure brush size and hardness or prevent the flatten tool from raising or lowering the level.  
Are probably mandatory features to make this a reliable world editor

Lack of clarity.  
No message on saving and only command-line arguments allow setting save path or load an existing file.  
It could interfere with comfortable use.

Terrible memory mangement on the rendering part.

I could fix it all if I decide to work on it again.