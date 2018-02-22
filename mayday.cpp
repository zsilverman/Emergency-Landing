//  Zack Silverman 913618592
//
// mayday.cpp
//
// use: mayday latitude longitude min_length
//
// Provide a list of facilities and runways closest to the location specified
// by the coordinates (latitude,longitude).
// Only facilities having runways longer than min_length are printed.
// Only runways longer than min_length are printed.
//
// Input:
//   latitude, longitude in degrees decimal
//   min_length in ft
// Output:
//   list of nearest facilities and runways including distance in nautical miles

#include "Facility.h"
#include "Runway.h"
#include "Closer.h"
#include "SiteNumber.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;

int main(int argc, char **argv)
{
  // use: mayday current_latitude current_longitude min_runway_length
  // latitude and longitudes in degrees decimal
  // min runway length of runway in ft

  assert(argc==4);
  const double current_latitude = atof(argv[1]);
  const double current_longitude = atof(argv[2]);
  const int min_runway_length = atoi(argv[3]);

    // load facilities data
    // creates vector with Facility objects from Facility.txt
    vector<Facility*> facilities;
    
    string s;
    ifstream infile("Facilities.txt");
    
    while (getline(infile,s))
    {
        facilities.push_back(new Facility(s));
    }
    
  // sort facilities in order of proximity to the current position
 sort(facilities.begin(), facilities.end(), Closer(current_latitude,current_longitude));
    
     //load runways data
    // creates vector with Runway objects from Runways.txt
  vector<Runway*> runways;
  
    string st;
    ifstream infile1("Runways.txt");
    
    while (getline(infile1,st))
    {
        runways.push_back(new Runway(st));
    }
    

  // list up to 10 nearest facilities that have a long enough runway
  // lists each runway that is long enough
  int count = 0;
  for ( unsigned int i = 0; i < facilities.size() && count < 10; i++ )
  {
    Facility *a = facilities[i];
      
    // stores runways which are long enough to land on
    vector<Runway*> good_runways;

    vector<Runway*> :: iterator iter;
    iter = runways.begin();
    
      
    //uses iterator and find_if() algorithm to add runways which meet criteria to goodrunways
    while ((iter=find_if(iter,runways.end(),SiteNumber(*a))) != runways.end()) {
          if(min_runway_length <= (*iter)->length()){
              good_runways.push_back(*iter);
          }
              iter++;
    }

    // print this facility if it has long enough runways
    if ( !good_runways.empty() )
    {
      // increment count of good facilities
      count++;

      cout << a->type() << " " << a->code() << " "
           << a->name() << " ";
      cout.setf(ios_base::fixed,ios_base::floatfield);
      cout.setf(ios_base::right, ios_base::adjustfield);
      cout.width(5);
      cout.precision(1);
      cout << a->distance(current_latitude,current_longitude)
           << " NM" << endl;                                  

      // print all runways that are long enough
      for ( unsigned int i = 0; i < good_runways.size(); i++ )
      {
        Runway *r = good_runways[i];
        cout << "  Runway: " << r->name() << "  length: " << r->length()
             << " ft" << endl;
      }
    }
  }
}
