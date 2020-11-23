#include "main.hpp"

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
