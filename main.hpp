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

void print_matrix(char* filename, vector< vector<int> > matrix){
    ofstream outfile(filename);

    if (outfile.is_open()){
        for (int i=0; i < matrix.size(); i++){
            for (int j=0; j < matrix[i].size(); j++){
                outfile << matrix[i][j] << ",";
            }
            outfile << endl;
        }
    }
}

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

vector< vector<int> > my_interpolation(vector< vector<int> > matrix){
    for (int i=0; i< matrix.size()*matrix.size(); i++){
        int row = i/matrix.size();
        int col = i%matrix.size();

        if ( row%2 == 0 && col != matrix.size()-1 ){
            if (matrix[row][col] == -1){
                int val = ceil(0.75*matrix[row][col-1] + 0.25*( abs( matrix[row][col+1] - matrix[row][col-1] ) ));
                matrix[row][col] = val;
            }
        }
        else if ( row%2 == 0 && col == matrix.size()-1 ){
            int val = ceil(0.75*matrix[row][col-1] + 0.25*( abs( matrix[row+1][col] - matrix[row][col-1] ) ));
            matrix[row][col] = val;
        }
        if ( row%2 != 0 && row != matrix.size()-1 ){
            int val = ceil(matrix[row-1][col] + 0.25*( abs( matrix[row+1][col] - matrix[row-1][col] ) ));
            matrix[row][col] = val;
        }
        else if ( row%2 != 0 && row == matrix.size()-1 ){
            int val = ceil(0.75*matrix[row-1][col] + 0.25*( abs( matrix[row][col+1] - matrix[row-1][col] ) ));
            matrix[row][col] = val;
        }
    }
    return matrix;
}

vector<vector<int> > nearest_neighbor(vector< vector<int> > matrix){
    for (int i=0; i<matrix.size()*matrix.size(); i++){
        if ( (i/matrix.size())%2 == 0 ){
            if (matrix[i/matrix.size()][i%matrix.size()] == -1)
                matrix[i/matrix.size()][i%matrix.size()] = matrix[i/matrix.size()][i%matrix.size() - 1];
        }
        else{
            matrix[i/matrix.size()][i%matrix.size()] = matrix[i/matrix.size() -1][i%matrix.size()];
	}
    }
    return matrix;
}

vector<vector<int> > parse_input(char* filename){
    ifstream infile(filename);
    vector< vector<int> > matrix;

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
        return matrix;
    }
}

