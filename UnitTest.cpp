#include <gtest/gtest.h>
#include "main.hpp"

TEST(UnitTest, ResizeNeg1Fill){
    std::vector<vector<int>> matrix04 (4, vector<int>(4,0));
    std::vector<vector<int>> matrix08 (8, vector<int>(8,0));

    for (int i=0; i<matrix04.size()*2; i++) {
        for (int j=0; j<matrix04.size()*2; j++) {
	        if(i%2 == 0 && j%2 != 0)
	    	    matrix08[i][j] = -1;
	        else if (i%2 != 0)
		        matrix08[i][j] = -1;
	    }
    }
    ASSERT_EQ(matrix08, resize_matrix(matrix04));
}

TEST(UnitTest, PopulateSmallMatrix){
    char* filename = (char*)"PopulateSmallMatrix.txt";
    ifstream infile(filename);
    std::vector< vector<int> > matrix;

    if (infile.is_open()){
        string inputline;
        int nextint;
        char delim;
        while (getline(infile, inputline)) {
            istringstream linestream(inputline);
            vector<int> row;
            while (linestream >> nextint) {
                row.push_back(nextint);
                linestream >> delim;
            }
            matrix.push_back(row);
        }
        infile.close();
    }

    ASSERT_EQ(matrix, parse_input(filename));
}

TEST(UnitTest, TestNearestNeighbor){
    std::vector<vector<int>> matrix1= {{2,-1,3,-1}, {-1,-1,-1,-1}, {4,-1,5,-1}, {-1,-1,-1,-1}};

    ASSERT_EQ(2, nearest_neighbor(matrix1)[1][1]);
    ASSERT_EQ(2, nearest_neighbor(matrix1)[1][0]);
    ASSERT_EQ(2, nearest_neighbor(matrix1)[1][1]);

    ASSERT_EQ(3, nearest_neighbor(matrix1)[0][3]);
    ASSERT_EQ(3, nearest_neighbor(matrix1)[1][2]);
    ASSERT_EQ(3, nearest_neighbor(matrix1)[1][3]);

    ASSERT_EQ(4, nearest_neighbor(matrix1)[2][1]);
    ASSERT_EQ(4, nearest_neighbor(matrix1)[3][0]);
    ASSERT_EQ(4, nearest_neighbor(matrix1)[3][1]);

    ASSERT_EQ(5, nearest_neighbor(matrix1)[2][3]);
    ASSERT_EQ(5, nearest_neighbor(matrix1)[3][2]);
    ASSERT_EQ(5, nearest_neighbor(matrix1)[3][3]);
}

TEST(UnitTest, TestMyInterpolation){
    std::vector<vector<int>> matrix = {{0,-1},{-1,-1}};

    ASSERT_EQ(0, my_interpolation(matrix)[0][0]);
    ASSERT_EQ(1, my_interpolation(matrix)[0][1]);

    ASSERT_EQ(0, my_interpolation(matrix)[1][0]);
    ASSERT_EQ(2, my_interpolation(matrix)[1][1]);
}

TEST(UnitTest, TestPrintingMatricies){
    vector< vector<int> > matrix{{1,1},{1,1}};
    char* filename = (char*)"TestPrintingMatricies.txt";

    print_matrix(filename, matrix);

    bool isEmpty = true;
    ifstream file;
    string line;
    file.open(filename);
    if (file >> line)
	    isEmpty = false;

    ASSERT_FALSE(isEmpty);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

