//  Runway.cpp
//  EmergencyLanding
//
//  Implementation of Runway object which has a site number, name, and length

#include <stdio.h>
#include "Runway.h"
#include <sstream>
using namespace std;

Runway::Runway(std::string s) : site_number_(s.substr(0,10)), name_(s.substr(13,7)), length_(convert_length(s.substr(20,5))){}
string Runway::site_number(void) const{
    return site_number_;
}
string Runway::name(void) const{
    return name_;
}
int Runway::length(void) const{
    return length_;
}

//converts parameter of a string to an int
int Runway::convert_length(std::string s) const{
    int length;
    istringstream temp(s);
    temp>>length;
    
    return length;
    
}

