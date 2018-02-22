//  Closer.h
//  EmergencyLanding
//
//  Implements Closer functor to test distance of Facility objects

#ifndef Closer_h
#define Closer_h

class Closer {
public:
    Closer(const double tempA, const double tempB) : closer_lat(tempA),closer_lon(tempB){}
    bool operator()(Facility *a, Facility *b) {return a->distance(closer_lat,closer_lon) < b->distance(closer_lat,closer_lon);}
    
private:
    const double closer_lat;
    const double closer_lon;
};


#endif /* Closer_h */
