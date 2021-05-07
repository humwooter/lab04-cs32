#ifndef POLICESTATEDATA_H
#define POLICESTATEDATA_H

#include "raceDemogData.h"
#include "psData.h"
#include <iostream>
#include <memory>
using namespace std;

class psState {
public:
  psState(string inS) : state(inS), cases_count(0), mental_count(0), fleeing_count(0), over65_count(0), over18to65_count(0), under18_count(0), males_count(0), females_count(0), raceData() {} 
  
  int getNumMentalI() const {return mental_count;};
  int getFleeingCount() const {return fleeing_count;};
  int getCasesOver65() const {return over65_count;};
  int getCasesUnder18() const {return under18_count;};
  raceDemogData getRacialData() const {return raceData; };
  int getnumMales() const {return males_count;};
  int getnumFemales() const {return females_count;};
  int getNumberOfCases() const {return cases_count;};
  string getState() const {return state; };

  void addCountyData(shared_ptr<psData> inCounty) {
    cases_count += 1;
    mental_count += !(inCounty->getMentalHealth()); //add one if false
    fleeing_count += inCounty->getFleeing();

    //age
    if (inCounty->getAge() > 65) over65_count += 1;
    else if (inCounty->getAge() < 18) under18_count += 1;
    else over18to65_count += 1;

    //gender
    if (inCounty->getGender() == true) females_count += 1;
    else males_count += 1;

    raceData += *(inCounty->caseRaceData);
    
  }

  friend std::ostream& operator<<(std::ostream &out, const psState& PD);
  raceDemogData raceData;
  
protected:
  const string state; 

  int cases_count; 
  int mental_count;
  int fleeing_count;
  
  int over65_count;
  int over18to65_count; 
  int under18_count;

  int males_count;
  int females_count; 
};

#endif
