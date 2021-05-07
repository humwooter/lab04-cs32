#include <sstream>
#include <string>
#include <iostream>
#include "psData.h"

/* print police data - fill in*/
std::ostream& operator<<(std::ostream &out, const psData &PD) {
  string gender = (PD.gender == true) ? "Female" : "Male";
  string fleeing = (PD.fleeing == true) ? "Fleeing" : "Not Fleeing";
  string mentalHealth = (PD.mentalHealth == true) ? "Not mentally ill" : "Mental illness";
    out << "Police Shotting Info: " << PD.state;
    out << "\nPerson name: " << PD.name;
    out << "\nAge: " << PD.age;
    out << "\nGender: " << gender;
    out << "\nRace:" << PD.race;
    out << "\nMental Illness:" << mentalHealth ;
    out << "\nFleeing:" << fleeing;
    return out;
}
