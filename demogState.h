#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"

class demogState {

public:
  friend std::ostream& operator<<(std::ostream &out, const demogState &SD);

  demogState() {
    name = "";
    numCounties = 0;
    PopOver65 = 0.0;
    PopUnder18 = 0.0;
    PopUnder5 = 0.0;
    PopBelowPoverty = 0.0;
    PopBelowPovertyPercent = 0.0;
    popBA = 0.0;
    popHS = 0.0;
    totalPop = 0.0;
    FirstNationCount = 0;
    AsianCount = 0;
    BlackCount = 0;
    LatinxCount = 0;
    HIPacificIsleCount = 0;
    MultiRaceCount = 0;
    WhiteCount = 0;
    WhiteNHCount = 0; 
  }

void addCountyData(shared_ptr<demogData> inCounty) {
    numCounties += 1;
    
    PopOver65 += inCounty->getpopOver65Count();
    PopUnder18 += inCounty->getpopUnder18Count();
    PopUnder5 += inCounty->getpopUnder5Count();
    PopBelowPoverty += inCounty->getPopUnderPovCount();
    popBA += inCounty->getBAupCount();
    popHS += inCounty->getHSupCount();
    totalPop += inCounty->getPop();
    PopBelowPovertyPercent = (PopBelowPoverty/totalPop)*100.0;
    state_raceData += *(inCounty->raceData);
}


  string name;
  int numCounties;
  
  double PopOver65;
  double PopUnder18;
  double PopUnder5;
  double PopBelowPoverty;
  double PopBelowPovertyPercent;
  double popBA;
  double popHS;

  double totalPop;

  raceDemogData state_raceData; 
  int FirstNationCount; //Native American/First Nation                                                                                                                                                      
  int AsianCount; //Asian American                                                                                                                                                                          
  int BlackCount; //African American/Black                                                                                                                                                                  
  int LatinxCount; //Hispanic/Latinx                                                                                                                                                                        
  int HIPacificIsleCount; //Hawaiian Pacific Islander                                                                                                                                                       
  int MultiRaceCount; //Multi-racial                                                                                                                                                                        
  int WhiteCount; //White (includes Hispanic)                                                                                                                                                               
  int WhiteNHCount; //
};
#endif
