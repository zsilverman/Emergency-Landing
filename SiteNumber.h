//  Zack Silverman 913618592
//
//  SiteNumber.h
//  EmergencyLanding
//
//  Implementation of the SiteNumber functor

#ifndef SiteNumber_h
#define SiteNumber_h

class SiteNumber{
public:
    SiteNumber(Facility fac) : current_siteNum(fac.site_number()){}
    bool operator() (Runway* r) {
        return r->site_number()==current_siteNum;
    };
    
private:
    const std::string current_siteNum;
};


#endif /* SiteNumber_h */
