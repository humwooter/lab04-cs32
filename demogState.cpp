#include "demogState.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <fstream>

std::ostream& operator<<(std::ostream &out, const demogState& SD) {
  out << std::fixed << std::showpoint << std::setprecision(2);
  out << "State Info: " << SD.name << endl; 
  out << "Number of Counties: " <<int(SD.numCounties) << endl;
  out << "Population info:" << endl;
  out << "(over 65): " << (SD.PopOver65/SD.totalPop)*100 << "% and total: " <<int(SD.PopOver65) << endl;
  out << "(under 18): " << (SD.PopUnder18/SD.totalPop)*100 << "% and total: " <<int(SD.PopUnder18) << endl;
  out << "(under 5): " << (SD.PopUnder5/SD.totalPop)*100 << "% and total: " <<int(SD.PopUnder5) << endl;
  out << "Education info:" << endl;
  out << "(Bachelor or more): " << (SD.popBA/SD.totalPop)*100 << "% and total: " <<int(SD.popBA) << endl;
  out << "(high school or more): " << (SD.popHS/SD.totalPop)*100 << "% and total: " <<int(SD.popHS) << endl;
  out << "persons below poverty: " << (SD.PopBelowPoverty/SD.totalPop)*100 << "% and total: " <<int(SD.PopBelowPoverty) << endl;
  out << "community racial demographics: " << SD.state_raceData << endl;    
  out << "Total population: " << int(SD.totalPop) << endl;
  return out;
}

