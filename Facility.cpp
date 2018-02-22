//Facility.cpp
//  EmergencyLanding
//
// Implementation of Facility object which has a site number, type, code, name, latitute, and longitude

#include <stdio.h>
#include "Facility.h"
#include "gcdistance.h" //for the distance method
#include <iostream> 
#include<sstream>
using namespace std;

Facility::Facility(std::string s) : site_number_(s.substr(0,10)), type_(s.substr(11,13)), code_(s.substr(24,4)), name_(s.substr(130,50)), latitude_(convert_latitude(s.substr(535,12))),longitude_(convert_longitude(s.substr(562,12))){
}

string Facility::site_number(void) const{
    return site_number_;
}
string Facility::type(void) const{
    return type_;
}
string Facility::code(void) const{
    return code_;
}
string Facility::name(void) const{
    return name_;
}

//returns the latitude of the facility in degrees decimal. Latitudes in the southern hemisphere
//are negative numbers.
double Facility::latitude(void) const{
    return latitude_;
}

//returns the longitude of the facility in degrees decimal. Longitudes in the western hemisphere
//are negative numbers.
double Facility::longitude(void) const{
    return longitude_;
}
//returns the distance in nautical miles between the facility and the position
//defined by (lat,lon) in degrees decimal
double Facility::distance(double lat, double lon) const{
    return gcdistance(lat,lon,latitude_,longitude_);
}

//converts the string s representing a latitude in seconds decimal to a double value in degrees decimal
double Facility::convert_latitude(std::string s) const{
    
    double num;
    istringstream temp(s.substr(0,11));
    temp>>num;
    
    char direction;
    istringstream letter(s.substr(11,1));
    letter>>direction;
    
    num= num/3600.0;
    
    if(direction=='S')
       num = num*-1;
    
    return num;
    
}

double Facility::convert_longitude(std::string s) const{
    double num;
    istringstream temp(s.substr(0,11));
    temp>>num;
    
    char direction;
    istringstream letter(s.substr(11,1));
    letter>>direction;
    
    num= num/3600.0;
    
    if(direction=='W')
        num = num*-1;
        
    return num;
    
}
