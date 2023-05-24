#pragma once
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Point
    {
        private:
            double the_x;
            double the_y;
    
        public:
            Point(double getx, double gety):the_x(getx), the_y(gety){};
            Point():the_x(0), the_y(0){}
            double getX()const{return the_x;}
            double getY()const{return the_y;}
            double distance(Point other)const;
            string print()const;
            static Point moveTowards(const Point source, const Point destination, double distance)
            {
                if(distance < 0)
                {
                    throw invalid_argument("the distance cant be negative.");
                }
                double the_dx = destination.the_x - source.the_x;
                double the_dy = destination.the_y - source.the_y;
                double dist = sqrt(the_dx * the_dx + the_dy * the_dy);

                if (dist <= distance) {
                    return destination;
                }
                
                double ratio = distance / dist;
                double new_x = source.the_x + (the_dx * ratio);
                double new_y = source.the_y + (the_dy * ratio);
                return Point(new_x, new_y);
            }
    };
}
