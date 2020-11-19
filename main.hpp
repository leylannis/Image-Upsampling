#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

void print_matrix(char* filename, vector< vector<int> > matrix);
vector< vector<int> > parse_input(char* filename);
vector< vector<int> > resize_matrix(vector< vector<int> > matrix);
vector< vector<int> > nearest_neighbor(vector< vector<int> > matrix);
vector< vector<int> > my_interpolation(vector< vector<int> > matrix);

vector< vector<int> > resize_matrix(vector< vector<int> > matrix){
    vector< vector<int> > newmatrix;

    for (int i=0; i<matrix.size()*2; i++) {
        vector<int> newrow;
        for (int j=0; j<matrix.size()*2; j++) {
            if (i%2 == 0){
                if (j%2 == 0){
                    newrow.push_back(matrix[i/2][j/2]);
                }
                else{
                    newrow.push_back(-1);       // empty/invalid pixel marker
                }
            }
            else{
                newrow.push_back(-1);           // empty/invalid pixel marker
            }
        }
        newmatrix.push_back(newrow);
    }
    return newmatrix;
}

