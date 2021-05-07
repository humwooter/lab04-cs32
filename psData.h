#ifndef POLICE_H
#define POLICE_H

#include <string>
#include <iostream>
#include <utility>
#include <memory>
#include "raceDemogData.h"
using namespace std;

/*
  class to represent police shooting data
  from CORGIS
*/
class psData {
public:
  psData(string inState, string inCounty, string inName, int inAge, bool inGender, string inRace, bool inMentalHealth, bool inFleeing, shared_ptr<raceDemogData> inRaceData) {
    state = inState;
    county = inCounty;
    name = inName;
    age = inAge;
    gender = inGender;
    race = inRace;
    mentalHealth = inMentalHealth;
    fleeing = inFleeing;

    caseRaceData = inRaceData; 
    initializeRaceData(race);
  }


  string getState() const { return state; }
  string getCounty() const { return county; }
  string getName() const { return name; }
  int getAge() const { return age; }
  bool getGender() const { return gender; }
  string getRace() const { return race; }
  bool getMentalHealth() const { return mentalHealth; }
  bool getFleeing() { return fleeing; }
  void initializeRaceData(string race) {
    if (race == "N") caseRaceData->addFirstNationCount(1);
    else if (race == "A") caseRaceData->addAsianCount(1);
    else if (race == "B") caseRaceData->addBlackCount(1);
    else if (race == "H") caseRaceData->addLatinxCount(1);
    else if (race == "HPI") caseRaceData->addHIPacificIsleCount(1);
    else if (race == "MR") caseRaceData->addMultiRaceCount(1);
    else if (race == "W") {
      caseRaceData->addWhiteCount(1);
      caseRaceData->addWhiteNHCount(1);
    }
  }
   
  friend std::ostream& operator<<(std::ostream &out, const psData &PD);
  shared_ptr<raceDemogData> caseRaceData;

private:
  string state;
  string county;

  string name;
  int age;
  bool gender; //male if false and female if true
  string race;
  bool mentalHealth; //mental illness if false
  bool fleeing; 

};

#endif
