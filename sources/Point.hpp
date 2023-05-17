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
            {///check this function.
                if(distance< 0.0)
                {
                    throw invalid_argument("the distance is always positive.");
                }
                double dist = pow((destination.getX()-source.getX()),2) + pow((destination.getY()-source.getY()),2); 
                if (dist <= distance)
                {
                    return destination;
                } 
                
                
                if(source.getX() == destination.getX())
                {
                    if(source.getY() > destination.getY())
                    {
                        return Point(source.getX(), source.getY()-distance);
                    }
                            
                    return Point(source.getX(), source.getY()+distance);
                        
                }
                if(source.getY() == destination.getY())
                {
                    if(source.getX() > destination.getX())
                    {
                        return Point(source.getX()-distance, source.getY());
                    }
                        
                    return Point(source.getX()+distance, source.getY());   
                }
                    
                    
                double the_m = (source.getY()-destination.getY())/(source.getX()-destination.getX());
                double the_x1 = ((2*source.getX()) + sqrt((pow(distance,2))/(1+pow(the_m,2))))/2;
                double the_x2 = ((2*source.getX()) - sqrt((pow(distance,2))/(1+pow(the_m,2))))/2;
                double the_y1 = the_m*(the_x1-source.getX())+source.getY();
                double the_y2 = the_m*(the_x2-source.getX())+source.getY();
                if(source.getX() > destination.getX())
                {
                    if(source.getX() > the_x1)
                    {
                        return Point(the_x1, the_y1);
                    }
                    return Point(the_x2, the_y2);
                }

                        
                        
                if(source.getX() < the_x1)
                {
                    return Point(the_x1, the_y1);
                }
                return Point(the_x2, the_y2);    
            }
        
        
    };
}
