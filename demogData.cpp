#include "demogData.h"
#include <sstream>
using namespace std; 
/* print county demographic data */
/*- LAB01 starter - replace with your FULL version! */
std::ostream& operator<<(std::ostream &out, const demogData &DD) {
    out << "County Demographics Info: " << DD.getName() << ", " << DD.state;
    out << " total population: " << DD.pop14;
    //consider re-writing with getters....
    out << "\nPopulation info: \n(\% over 65): " << DD.popOver65;
    out <<  " Count: " << "fix";
    out << "\n(\% under 18): " << DD.popUnder18;
    out <<  " Count: " << "fix";
    out << "\n(\% under 5): " << DD.popUnder5;
    out <<  " Count: " << "fix";
    out << "\nEducation info: " << "fix this for lab01\n";
    return out;
}
