#include <iomanip>
#include "psState.h"

/* print state data - as aggregate of all incidents in this state */
//fill in for lab4
std::ostream& operator<<(std::ostream &out, const psState& PD) {
  out << "**Police shooting incidents:" << "State Info: " << PD.state;
  out << "\nNumber of incidents: " << PD.cases_count;
  out << "\nIncidents with age \n(over 65): " << PD.over65_count;
  out << "\n(19 to 64): " << PD.cases_count - PD.over65_count - PD.under18_count;
  out << "\n(under 18): " << PD.under18_count;
  out << "\nIncidents involving fleeing: " << PD.fleeing_count;
  out << "\nIncidents involving mental illness: " << PD.mental_count;
  out << "\nMale incidents: " << PD.males_count <<  " female incidents: " << PD.females_count;
  out << "\nRacial demographics of state incidents: " << PD.getRacialData() << endl;
    return out;
}
