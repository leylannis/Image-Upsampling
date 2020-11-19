#include <gtest/gtest.h>
#include "main.hpp"

TEST(UnitTest, ResizeNeg1Fill){
    // resize_matrix() maps original image matrix to double the size
    // a 4x4 matrix will be resized to an 8x8 with -1 in all new spaces

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
	// unit test for parse_input
}

TEST(UnitTest, TestNearestNeighbor){
    std::vector<vector<int>> matrix1;
    std::vector<int> row0 = {2,-1,3,-1};
    std::vector<int> row13 = {-1,-1,-1,-1};
    std::vector<int> row2 = {4,-1,5,-1};
    matrix1.push_back(row0);
    matrix1.push_back(row13);
    matrix1.push_back(row2);
    matrix1.push_back(row13);

    ASSERT_EQ(2, nearest_neighbor(matrix1)[1][1]);
    ASSERT_EQ(2, nearest_neighbor(matrix1)[0][1]);

// add more statements here !!

}

TEST(UnitTest, TestMyInterpolation){
	// unit test for my_interpolation()
}

TEST(UnitTest, PrintingMatricies){
	// test for correct printing of matricies
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

