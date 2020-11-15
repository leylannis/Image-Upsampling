// reads input matricies of 256x256 (ints 0-255)
// data is stored in row major order
// upsample.cpp will output 512x512 matrix of the same type as input (2x upsample)

// implement 2 methods
// comment out worse one in bottom of file; better one above

//w1 = 256		h1 = 256
//w2 = 512 (256*2)	h2 = 512 (256*2)

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// global definitions
vector< vector<int> > matrix;
vector< vector<int> > newmatrix;
int parse_input(char* filename);
void nearest_neighbor();

int main(int argc, char* argv[]) {

    char* inputfile = argv[1];
    if (parse_input(inputfile) == 0){	// parsing input matrix successful

    nearest_neighbor();

    // printing matrix contents for testing purposes  
        for (int i=0; i < newmatrix.size(); i++){
	    for (int j=0; j < newmatrix[i].size(); j++){
	        cout << newmatrix[i][j] << ", ";
	    }
	    cout << endl;
        } 

    }
    else
        cout << "unable to open file\n";

    return 0;
}


void nearest_neighbor(){
    for (int i=0; i<matrix.size()*2; i++) {
        vector<int> newrow;
        for (int j=0; j<matrix.size()*2; j++) {
	    newrow.push_back(matrix[i/2][j/2]);
        }                
	newmatrix.push_back(newrow);
    }                
}

int parse_input(char* filename){
    ifstream infile(filename);

    if (infile.is_open()){
        string inputline;
        int nextint;
        char delim;
        while (getline(infile, inputline)) {
            istringstream iss(inputline);
            vector<int> row;
            while (iss >> nextint) {
                row.push_back(nextint);
                iss >> delim;
            }
            matrix.push_back(row);
        }
        return 0;	
    }
    else	// failed to open file
        return -1;
}
