## What I'm confused on
1.  Part one
2.  Part Six
3.  
----------------------
CS230 Lab 4: Graphics
=====================

### Suggested Steps:

#### Part 1: Getting Started

1.  Download and unzip the lab. 
2.  Copy the following files from your previous lab (CS230 Lab 3 - Level Management):
    *   Level.cpp
    *   Level1.cpp
    *   Level2.cpp
    *   Space.cpp
3.  Remove any print statements (std::cout) from the following functions:
    *   Space::Update
    *   Level1::Update
    *   Level2::Update
4.  Compile and run the program to make sure it works on your machine.
5.  Take a look at the provided interfaces (.h files) for the classes you will be implementing:
    *   MeshHelper.h
    *   Sprite.h
    *   SpriteSource.h
    *   Animator.h
    *   Animation.h
6.  Also note the additional variables that have been added to the following files:
    *   Level1.h
    *   Level2.h

After reading through the function documentation for each class, you should have a basic idea of what each function is supposed to be doing (apart from the additions to Level 1 and Level 2, which we'll cover later in the directions).

#### Part 2: Mesh Creation Functions

Each of the functions below will utilize functions in the _MeshFactory_ module to create meshes three vertices at a time (i.e., using _AddTriangle_). A few notes:

*   Each vertex passed in to the _AddTriangle _function is an instance of the _Vertex _struct.
*   The _Vertex_ struct has several constructors which you can find in Vertex.h; make sure you're using the right one based on the information you're given via the function parameters!
*   Keep the vertices of your mesh within 0.5 units of the origin (0, 0). This is to ensure that scaling works in a predictable way for all objects.

The following functions will need to be implemented in a new MeshHelper.cpp file:

1.  CreateTriangleMesh
    *   Create a mesh consisting of a single triangle, with each vertex using the corresponding color provided in the function parameters.
    *   The triangle should be pointing right, just as it looks in the picture near the top of this assignment page. In other words, two of your vertices will be to the left of the origin, and the third will be in the middle on the right.
2.  CreateQuadMesh
    *   Note that you won't need this function until you're in a position to test Level2. You can implement it now or wait until then.
    *   Create a square mesh consisting of two triangles. Since the triangles share a side, they will share two of their vertices, so you may want to create the vertices as separate variables, then pass those in to the calls to the _AddTriangle_ function.
    *   Keep in mind that texture (UV) coordinates work differently than normal Cartesian coordinates. The point (0, 0) is at the top left of the texture, and (1,1) is at the bottom right, no matter the size of the texture!
    *   _\[NOTE: Some enterprising students may notice there is already a function for this in MeshFactory. It may be tempting to simply call this function here. Don't do that, or I will dock you points for this assignment. The purpose of this part of the assignment is to prove you can create a textured quad using triangles on your own.\]_

We'll test these functions later in Level1 and Level2 respectively.

#### Part 3: Sprite Class

The **Sprite** class is responsible for drawing a mesh, either with or without a texture, at a specific place on the screen with an appropriate scale and rotation. It does not store the texture itself or any information about it; that is the responsibility of the **SpriteSource** class, which you will implement later in this project. For now, you will need to implement the following functions in a new Sprite.cpp file:

1.  Sprite (constructor)  
    *   Initialize  class variables using the given parameters or, in the absence of matching parameters, using sane default values (such as 0, false, nullptr, etc.).
2.  Draw
    *   If this sprite has no mesh, simply return. Can't draw without a mesh!
    *   Get the sprite shader from the GraphicsEngine module and call its _Use_ function to activate it.
    *   If this sprite has a sprite source
        *   Call the _UseTexture_ function on the sprite source, passing it the appropriate information using this sprite's class variables.
    *   Otherwise
        *   Get the default texture from the GraphicsEngine module (a 1x1 white texture) and call its _Use_ function to set it as the current texture_._
    *   Set the location and scale of the object being drawn using the _SetTransform _function on Graphics. Eventually we'll have a transform component to get these values from, but for now just use _Vector2D(0, 0)_ as the position,  _Vector2D(1, 1)_ as the scale, and 0 as the rotation.
    *   Last but not least, tell the mesh to draw itself!
3.  SetAlpha
    *   Set the alpha on the sprite's _color_ variable to the provided value.
4.  GetAlpha
    *   Return the alpha on the sprite's _color_ variable.
5.  SetFrame  
    *   Print out "Sprite::SetFrame" to the console.
    *   If the provided frame index is less than the sprite source's frame count, set the _frameIndex _to the provided value.
6.  SetMesh, Set/GetSpriteSource, Set/GetColor, SetFlipX/Y
    *   Simple accessors/mutators. Implement them.

Verify that the code you've written compiles. You may get linker errors for calls to SpriteSource functions. If you want to test without implementing SpriteSource, simply comment out the offending lines in Sprite for now and remind yourself to uncomment them later. We won't actually need sprite sources until Level 2.

#### Part 4: Level1 Class

We're going to use Level 1 to test drawing a sprite without a texture/sprite source. The following changes need to be made to the Level1.cpp file (taken from CS230 Lab 3):

1.  In the **constructor**, initialize any new class variables to sane values. Change the value of _lives_ from 3 to 256.
2.  In the **Load** function, add code to create a triangle mesh (using three distinct colors such as red, green, and blue) and store it in the mesh pointer (you wrote a function for this earlier in _Part 2_ of this assignment).
3.  In the **Initialize** function, create a new Sprite, store it in the appropriate variable, and make sure it's using the mesh you created in Load.
4.  The **Shutdown** and **Unload** functions should be deleting what you created in _Initialize_ and _Load, _respectively.
5.  In the **Update** function, draw the sprite.

Once you've written this code, test to see if Level 1 is correctly drawing the colored triangle as shown in the picture at the top of this page.

#### Part 5: SpriteSource Class

The sprite source class stores a texture and figures out what the UV coordinates for a specific frame should be based on the number of rows and columns in the sprite sheet. You will need to implement the following functions in a new SpriteSource.cpp file:

1.  SpriteSource (constructor)
    *   Simple constructor, just make sure everything gets initialized properly using the provided parameters/sane default values.
2.  UseTexture
    *   Calculate the UV offset using _GetUV_ and store it in a variable.
    *   Call the texure's _Use _function, passing 1 and 1 for the rows and columns, using the appropriate class variables for the other parameters. You can leave the last param (the shader) blank; it will default to the last used shader.
    *   _\[NOTE:_ _Yes, we do have actual variables for the rows and columns of the sprite source that we could pass in here, in which case the shader would take care of drawing the correct portion of the texture for us, which is ideal. However, I want you_ _to do the work of calculating which portion of the texture to display when you create the quad mesh in MeshHelper.cpp. This is just to prove you can get the math correct. If you pass in the columns and rows here instead of doing the UV calculations in the mesh creation, I will dock you points for this assignment. In the future, however, I suggest passing in the column/row info here, as this will allow you to use the same mesh for nearly every 2D sprite.\]_
3.   GetFrameCount
    *   Return the total frame count (calculated based off of _numRows _and _numCols_).
4.  GetUV
    *   The only non-trivial function. First calculate the portion of the texture that each column and row take up (sometimes called U-size and V-size). Remember that texture coordinates go from 0.0 to 1.0 on both axes.
    *   Next, calculate the column and row that correspond to the given frame. (HINT: You'll need to use some form of division, along with the frame and the number of columns.)
    *   Once you have the U size and V size and the column and row that correspond to the given frame, the UV coordinates can be calculated quite easily:
        *   u = uSize \* column
        *   v = vSize \* row
    *   Store the U and V in the x and y of the provided vector.

Once you have these functions implemented, you can move on to implementing Level 2 to test drawing a sprite with a texture. If you haven't yet implemented _CreateQuadMesh_ in _MeshHelper.cpp_, do that before continuing (see implementation notes in Part 2 above).

#### Part 6: Level 2 Class (using SpriteSource)

The following changes need to be made to the Level2.cpp file:

1.  In the **constructor**, initialize any new class variables to sane values. No changes need to be made to health or lives.
2.  In the **Load** function, add code to create a quad mesh and store it in the mesh pointer, load the Monkey.png texture, and create a sprite source that uses that texture (refer to the image to find the number of columns and rows).
3.  In the **Initialize** function, create a new Sprite, making sure it uses the mesh and sprite source you created in the Load function.
4.  The **Shutdown** and **Unload** functions should be deleting what you created in _Initialize_ and _Load_.
5.  In the **Update** function, draw the sprite. Also comment out the code that deals with health, lives, and shutting down the game. We'll restore that code later.

Once you've written this code, test to see if Level 2 is correctly drawing the first frame of the monkey sprite sheet.

#### Part 7: Animator Class

The purpose of the Animation class is to manage all of the animations for a given object, and to get the correct frame to set on the Sprite based on the amount of time that has passed and which animation is being used. You will need to implement the following functions in a new Animator.cpp file:

1.  Animation (constructor)
    *   Same procedure as for other constructors. The only exception to the usual sane defaults is _playbackSpeed, _which should be set to 1.0f.
2.  Play
    *   If the given animation index is invalid (i.e. at or beyond the number of animations in the animation list), return.
    *   Set the matching class variables (_isLooping, playbackSpeed,_ etc.) using the given parameters.
    *   _isRunning_ is whether the animation is currently playing, _isDone _is whether the animation is finished, and _elapsedTime_ is how much time has passed since the animation started playing. You've just started playing an animation; knowing that, use your best judgment on what these should be set to.
    *   Get the animation in the animation list at the given index and use it to do the following:
        *   Set the sprite's sprite source to the animation's sprite source
        *   Set the sprite's frame to the current frame index of the animation.
3.  Update
    *   Print out "Animation::Update" to the console.
    *   Animation code details:
        *   If an animation is not currently running, return. Otherwise, increase the elapsed time using _dt._
        *   Set the sprite's frame to the current frame index of the animation. Make sure to pass in the address of _isDone_ for the last param, or else we won't know when the animation is finished playing.
4.  AddAnimation
    *   Add the given animation to the animation list using the _PushBack_ function.
    *   Return the index used for the animation (size of the list - 1).
5.  GetAnimationIndex
    *   For each of the animations in the animation list
        *   Check if the animation matches the given name. If so, return it.
    *   If no animations matched the name, return 0. _(NOTE: This would be a place where we might consider throwing an exception, if we knew what an exception was...)_
6.  GetCurrentAnimationIndex, IsDone, SetPlaybackSpeed
    *   Simple accessors/mutators. Implement them.

Now we can finally test animations!

#### Part 8: Animation Class

The purpose of the Animation class is simply to figure out what frame the sprite should be at based on how much time has passed, the starting frame of the animation, and the number of frames in the animation. The current implementation assumes each frame of an animation has the same duration, but could easily be modified (either by changing the class directly or inheriting from it) to support animations with frames of varying durations. You will need to implement the following functions in a new Animation.cpp file:

1.  Animation (constructor)
    *   Most variables can be initialized using the given parameters or sane default values.
2.  GetCurrentFrameIndex
    *   Use the _GetVirtualIndex_ function to determine which frame of the animation we should be on based on the current time and playback speed. 
    *   If the animation is looping
        *   Make sure the frame index goes back to 0 if it reaches the last frame.
    *   Otherwise
        *   Make sure the frame index does not go past the last frame.
    *   If the _isDone _param is not null
        *   Set its value based on the current frame index. (Should be **true** if the current frame is the last frame.)
    *   Return the actual frame index the sprite should use by using by adding the starting frame to the frame index.
3.  GetVirtualIndex
    *   _\[NOTE: The goal of this function is to figure out which frame we should be on based on how much time has passed. We will do this by adding the change in time to an accumulator. If the accumulator accumulates enough time, we advance the frame.\]_
    *   Add time to the accumulator (_dt _times _playbackSpeed)._
    *   While the accumulator meets or exceeds the frame duration
        *   Increase the current frame index.
        *   Decrease the accumulator using _dt._
    *   Return the current frame.
    *   _\[You may run into issues if/when the frame duration is 0. I'll let you decide how to solve this if it becomes an issue.\]_
4.  GetName, GetSpriteSource
    *   Simple accessors. Implement them.

Now we can finally test animations!

#### Part 9: Level 2 Class (using Animation)

The following changes need to be made to the Level2.cpp file:

1.  In the **constructor,** initialize the animation frame count to 8 and duration to 0.2f.
2.  In the **Load** function, create an _Animation_ using the appropriate class variables as parameters for its constructor.
3.  In the **Initialize** function, create an _Animator_, add the animation you created in the load function, and play it. Use the default playback speed and make sure it loops.
4.  In the **Update** function,
    *   Update the animator using _dt_.
5.  Make sure you delete the proper things in the **Shutdown**, **Unload**.

Test to make sure the animation plays and loops correctly. Once you've done that, you're almost ready to test against the expected output in _traceMaster.log. _First, make the following changes:

1.  In the **Initialize** function, change the frame duration to 0.0f. This will ensure frame time won't affect your program's output when compared with mine.
2.  In the **Update** function,
    *   Uncomment the code that deals with health and lives.
    *   Add the following if statement before that code:
        *   if the animation is not done, return
    *   (Every time the animation finishes a loop, health goes down by 1.)

Now your program will run extremely quickly on Level 2. To redirect output to a text file, follow these procedures (different from last time):

*   In Main.cpp, add code to redirect the output of std::cout to a file called _trace.txt. _You can refer to your previous lab for how to do this.

Run the program again and look for _trace.txt_ in your project directory. Compare it against _traceMaster.txt_. If they diff cleanly and everything you did up to this point works correctly, you're good to go!

Make sure you have no memory leaks before submitting.

### Submission

Submit only the following files in a zip file:

*   Animation.cpp
*   Animator.cpp
*   Level1.cpp
*   Level2.cpp
*   MeshHelper.cpp
*   Sprite.cpp
*   SpriteSource.cpp