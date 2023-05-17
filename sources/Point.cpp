#include <iostream>
#include <cmath>
#include "Point.hpp"
using namespace std;
using namespace ariel;

    
double Point::distance( Point other)const {
    return sqrt(pow(this->the_x - other.the_x, 2) + pow(this->the_y - other.the_y, 2));
}
    
string Point::print()const {
    string result = "(" + to_string(the_x) + "," + to_string(the_y) + ")\n";
    return result;
}
 