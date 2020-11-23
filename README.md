# COP4531 Assignment 2
    Leylanni Quijano-Shafer
    Grayscale Image Upsampling in C++
    gitlab repo link: https://gitlab.com/leylannis/cop4531-assignment-2

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
        Will run main with input and output parameters
        Then will produce line coverage output to the console

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
    Each unit test contains one or more check for corectness of each of the functions in main.hpp as described below

    ResizeNeg1Fill:
        Tests resize_matrix()
        This function is used to resize a matrix to two times its size, mapping exsting values to corresponding indicies
        It fills in the unknows spaces with an invalid value of -1 to flag for later use
        In this test, there is a 4x4 matrix of zeros and 8x8 matrix with -1 in the gaps
        So it looks something like this:
        matrix04:      matrix08: 
        0 0 0 0         0  -1  0 -1  0  -1  0  -1
        0 0 0 0        -1  -1 -1 -1  -1 -1  -1 -1
        0 0 0 0         .... (repeated 4 times to complete 8x8)

        The test asserts that the output of resize_matrix(matrix04) is equal to matrix08

    PopulateSmallMatrix:
        Tests parse_input()
        

    TestNearestNeighbor:
        Tests nearest_neighbor()

    TestMyInterpolation:
        Tests my_interpolation()

    PrintingMatricies:
        Tests print_matrix()
