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
int parse_input(char* filename);

int main(int argc, char* argv[]) {

    char* inputfile = argv[1];
    if (parse_input(inputfile) == 0){	// parsing input matrix successful

    // process image here to double size

    /*  printing matrix contents for testing purposes  
        for (int i=0; i < matrix.size(); i++){
	    for (int j=0; j < matrix[i].size(); j++){
	        cout << matrix[i][j] << " ";
	    }
	    cout << endl;
        } */

}
else
    cout << "unable to open file\n";

return 0;
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
