#include <gtest/gtest.h>
#include "main.hpp"

TEST(UnitTest, FillNeg1Gaps){
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

}

TEST(UnitTest, TestMyInterpolation){

}

TEST(UnitTest, PrintingMatricies){

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

