#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

// function declarations
vector< vector<int> > parse_input(char* filename);
void print_matrix(char* filename, vector< vector<int> > matrix);
vector< vector<int> > resize_matrix(vector< vector<int> > matrix);
vector< vector<int> > nearest_neighbor(vector< vector<int> > matrix);
vector< vector<int> > my_interpolation(vector< vector<int> > matrix);

int main(int argc, char* argv[]) {
    char* inputfile = argv[1];
    char* outputfile = argv[2];

    vector< vector<int> > matrix;
    vector< vector<int> > newmatrix;

    matrix = parse_input(inputfile);    
    newmatrix = resize_matrix(matrix);

    //newmatrix = nearest_neighbor(newmatrix);
    newmatrix = my_interpolation(newmatrix);

    print_matrix(outputfile, newmatrix);

    return 0;
}


vector< vector<int> > my_interpolation(vector< vector<int> > matrix){
    for (int i=0; i<matrix.size()*matrix.size(); i++){
        if ( (i/matrix.size())%2 == 0){
            if (matrix[i/matrix.size()][i%matrix.size()] == -1){
		int newval = (matrix[i/matrix.size()+1][i%matrix.size()] + abs((0.5*(matrix[i/matrix.size()+1][i%matrix.size()] - matrix[i/matrix.size()][i%matrix.size()-1]))));
                matrix[i/matrix.size()][i%matrix.size()] = newval;
	    }
        }
        else{              
            matrix[i/matrix.size()][i%matrix.size()] = matrix[i/matrix.size() -1][i%matrix.size()];
        }
    }
    return matrix;

/*
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
*/
}

vector<vector<int> > nearest_neighbor(vector< vector<int> > matrix){
    for (int i=0; i<matrix.size()*matrix.size(); i++){
        if ( (i/matrix.size())%2 == 0){
	    if (matrix[i/matrix.size()][i%matrix.size()] == -1)
		matrix[i/matrix.size()][i%matrix.size()] = matrix[i/matrix.size()][i%matrix.size() - 1];
	}
	else{
	    matrix[i/matrix.size()][i%matrix.size()] = matrix[i/matrix.size() -1][i%matrix.size()];
	}
    }
    return matrix;
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
		    newrow.push_back(-1);	// empty/invalid pixel marker
		}
	    }
	    else{
                newrow.push_back(-1);		// empty/invalid pixel marker
	    }
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
	infile.close();
        return matrix;	
    }
}

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
