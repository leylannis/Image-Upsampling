// reads input matricies of 256x256 (ints 0-255)
// data is stored in row major order
// upsample.cpp will output 512x512 matrix of the same type as input (2x upsample)

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

// global definitions
vector< vector<int> > matrix;
vector< vector<int> > newmatrix;
int parse_input(char* filename);
void nearest_neighbor();
void my_interpolation();

int main(int argc, char* argv[]) {

    char* inputfile = argv[1];
    if (parse_input(inputfile) == 0){	// parsing input matrix successful

    //nearest_neighbor();
    my_interpolation();

    // printing matrix contents for testing purposes  
        for (int i=0; i < newmatrix.size(); i++){
	    for (int j=0; j < newmatrix[i].size(); j++){
	        cout << newmatrix[i][j] << ",";
	    }
	    cout << endl;
        } 

    }
    else
        cout << "unable to open file\n";

    return 0;
}

void my_interpolation(){
    for (int i=0; i<matrix.size()*2; i++){
        vector<int> newrow;
        int val1, val2, val3, val4, val5, val6, val7, val8, val9;
        for (int j=0; j<matrix.size()*2; j++){ 
	    
            val1 = matrix[abs(i%256)][abs(j%256)];
            val2 = matrix[abs(i%256)][abs((j+1)%256)];
            val3 = matrix[abs(i%256)][abs((j-1)%256)];

            val4 = matrix[abs((i+1)%256)][abs(j%256)];
            val5 = matrix[abs((i+1)%256)][abs((j+1)%256)];
            val6 = matrix[abs((i+1)%256)][abs((j-1)%256)];

            val7 = matrix[abs((i-1)%256)][abs(j%256)];
            val8 = matrix[abs((i-1)%256)][abs((j+1)%256)];
	    val9 = matrix[abs((i-1)%256)][abs((j-1)%256)];

	    newrow.push_back(floor((val1+val2+val3+val4+val7)/5));
            newrow.push_back(floor((val1+val2+val3+val4+val5+val6+val7+val8+val9)/9));
        }
	newmatrix.push_back(newrow);
    }
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
            istringstream linestream(inputline);
            vector<int> row;
            while (linestream >> nextint) {
                row.push_back(nextint);
                linestream >> delim;
            }
            matrix.push_back(row);
        }
        return 0;	
    }
    else	// failed to open file
        return -1;
}
