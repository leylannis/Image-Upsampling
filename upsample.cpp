#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

// function declarations
vector< vector<int> > parse_input(char* filename);
vector< vector<int> > nearest_neighbor(vector< vector<int> > matrix);
vector< vector<int> > my_interpolation(vector< vector<int> > matrix);

int main(int argc, char* argv[]) {
    char* inputfile = argv[1];

    vector< vector<int> > matrix;
    vector< vector<int> > newmatrix;

    matrix = parse_input(inputfile);    

    newmatrix = nearest_neighbor(matrix);
    //newmatrix = my_interpolation(matrix);

    // printing matrix contents for testing purposes  
    for (int i=0; i < newmatrix.size(); i++){
	for (int j=0; j < newmatrix[i].size(); j++){
	    cout << newmatrix[i][j] << ",";
	}
	cout << endl;
    } 
    return 0;
}


vector< vector<int> > my_interpolation(vector< vector<int> > matrix){
    vector< vector <int> > newmatrix;

    for (int i=0; i<matrix.size()*2; i++){
        vector<int> newrow;
        for (int j=0; j<matrix.size(); j++){ 
	    newrow.push_back(matrix[i%matrix.size()][j%matrix.size()]);
	    int val = (matrix[i%matrix.size()][j%matrix.size()] + abs((0.5*(matrix[i%matrix.size()][j%matrix.size()] - matrix[i%matrix.size()][j%matrix.size()]))) );
	    newrow.push_back(val);
        }
	newmatrix.push_back(newrow);
    }
    return newmatrix;
}

vector<vector<int> > nearest_neighbor(vector< vector<int> > matrix){
    vector< vector<int> > newmatrix;
    for (int i=0; i<matrix.size()*2; i++) {
        vector<int> newrow;
        for (int j=0; j<matrix.size()*2; j++) {
	    newrow.push_back(matrix[i/2][j/2]);
        }                
	newmatrix.push_back(newrow);
    }
    return newmatrix;
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
        return matrix;	
    }
}
