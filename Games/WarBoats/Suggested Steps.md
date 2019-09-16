### Suggested Steps

1.  CS170 projects need to compile with both the GNU compiler and the Microsoft compiler. Because of this, I have not provided a Visual Studio Solution/Project for this lab, but you are welcome to create one yourself if you like.
2.  **Read the PDF included in the zip file above.** It contains descriptions of each function you will need to implement along with answers to frequently asked questions.
3.  Prototypes for all the functions are already declared in _WarBoats.h._ You will be defining them in _Ocean.cpp_.
4.  Familiarize yourself with the way the program will be tested.  
    *   Take a look at the expected outputs for each test, located in the output folder.
    *   Find the main function inside _driver\_sample.cpp. _Inside this function there are calls to the functions for each test. To enable or disable tests, simply uncomment/comment the line of code that runs that test. Running more than one test at a single time is not recommended.
    *   There is a second driver, _driver\_big.cpp, _which has additional tests that should be run after you've verified that the tests from _driver\_sample.cpp _produce the correct output.
5.  Implement the functions in the order they are being tested, starting with _CreateOcean _and _DestroyOcean__._
6.  Compile the project.  
    *   To compile using the GNU compiler, g++, you can use the following command:
        *   g++ Ocean.cpp PRNG.cpp driver\_sample.cpp -Wall -Wextra -Werror -std=c++11 -pedantic -o WarBoats.exe
    *   To compile using Microsoft's compiler, you have two options:
        1.  Create a Visual Studio Solution and compile the project that way. Before compiling, go into your project properties, find the C/C++ section and set the "Warning Level" to "Level 4" and "Warnings treated as errors" to "Yes".
        2.  Compile using the command line:
            *   cl /W4 /EHa /Za /WX /FeWarBoats.exe Ocean.cpp PRNG.cpp driver\_sample.cpp
            *   If you are using Windows 10 and this doesn't work, look for a separate command line shortcut in your Start Menu called "x86 Native Tools Command Prompt VS 2017" or "Developer Command Prompt for VS 2017."
            *   If you are not using Windows 10, you'll want to add the folder containing cl.exe to your path. It should be located within your Visual Studio installation directory in a directory called VC. Note that you may need to go a few levels deeper within the VC directory to find the actual executable.
7.  Run the project.
    *   Running the executable will run the test that is currently uncommented in whichever driver you're using.
8.  Save your output.
    *   For the first couple tests in this project, just eyeballing the output can tell you whether it is correct. However, I don't recommend doing this for the majority of them. You'll want to save your output and diff it against the master output. To do this, simply run the executable like so:  
        *   WarBoats.exe > myOutput.txt
    *   This will redirect the output to a text file so you can diff your output against the master.
9.  Diff the output against the master output.
    *   Many versioning systems such as SVN or git have built in diff features that you can access when right clicking on a file.
    *   If you would like to diff using the command line (and have diff installed through cygwin or something similar), enter the following command in your command line interface:
        *   diff file1.txt file2.txt --strip-trailing-cr
    *   Make sure to substitute your output text file and a master output text file in place of file1 and file2.
    *   If the diff command does not give any output, the files are identical.
10.  Don't forget comments!  
    *   You'll need to write file headers and function headers for each file you submit (see below) as well as inline comments for any sufficiently complex code (your code in TakeShot or PlaceBoat).