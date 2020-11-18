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

