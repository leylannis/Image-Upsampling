# COP4531 Assignment 2
Leylanni Quijano-Shafer

Image Upsampling in C++

### How To Run:
    Makefile provided simplifies compilation and running process.
    Once the codebase in this repository is downloaded, ensure googletest and gcov are installed in your home directory.
    The command options are listed and described below.

    "make"
        Will compile main.cpp and produce the executable ./main
    "make test"
        Will compile UnitTest.cpp and run unit tests
        Will produce googletest output to the console accordingly
    "make coverage"
        Will compile main.cpp for gcov to be run
        Ensure "sample1_input_image.txt" is in your current directory
        Will produce line coverage output to the console

### Code Details and Complexity:
    Interpolation Method 1:
        The one to be graded is my nearest_neighbor() method
        When starting implementation, I had two nested for loops that pushed back on the new vector
        to create the larger image, grabbing the value of the nearest pixel as expected
        With the introduction of my resize_matrix() function that doubles the size of the matrix and 
        gives a temporary value to the new gaps, I was able to achieve the same results
        in a for loop that runs 512*512 times

    Interpolation Method 2:
        The other method implemented is my_interpolation()
        Unfortunately I was unable to achieve an improved L1 metric over using nearest nearest_neighbor
        Therefore this is commented out (not called) in main.cpp as the worse performing one should be
        Here I used the same looping convention as before, but created an algorithm that is inspired
        by the linear interpolation method
        I use the value of two nearby pixels, weighted so that the one that would normally be
        copied during nearest neighbor had more weight over the other point sampled

### Unit Test Descriptions:

    