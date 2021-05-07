#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include<iostream>
#include "raceDemogData.h"
#include <memory>
using namespace std;

class demogData {
public:

  demogData(string inN, string inS, double in65, double in18,
            double in5) :
    name(inN), state(inS), popOver65(in65), popUnder18(in18),
    popUnder5(in5), popBA(0.0), popHS(0.0), popUnderPoverty(0.0), pop14(0), raceData(nullptr) {
  }
  demogData(string inN, string inS, double in65, double in18,
            double in5, int totalPop) :
    name(inN), state(inS), popOver65(in65), popUnder18(in18),
    popUnder5(in5), popBA(0.0), popHS(0.0), popUnderPoverty(0.0), pop14(totalPop), raceData(nullptr) {
  }

  demogData(string inN, string inS, double in65, double in18,
            double in5, double BAup, double HSup) :
    name(inN), state(inS), popOver65(in65), popUnder18(in18),
    popUnder5(in5), popBA(BAup), popHS(HSup), popUnderPoverty(0.0), pop14(0.0), raceData(nullptr) {
  }

  demogData(string inN, string inS, double in65, double in18,
            double in5, double BAup, double HSup, double povPop, double totalPop, shared_ptr<raceDemogData> inRaceData) :
    name(inN), state(inS), popOver65(in65), popUnder18(in18),
    popUnder5(in5), popBA(BAup), popHS(HSup), popUnderPoverty(povPop), pop14(totalPop), raceData(inRaceData) {
  }

  string getName() const { return name; }
  string getState() const { return state; }
  double getpopOver65() const { return popOver65; }
  double getpopUnder18() const { return popUnder18; }
  double getpopUnder5() const { return popUnder5; }
  double getBAup() const { return popBA; }
  double getHSup() const { return popHS; }
  int getPop() const { return pop14; }

  int getpopOver65Count() const { return (int)(((popOver65/100.0) * pop14) + 0.5); }
  int getpopUnder18Count() const { return (int)(((popUnder18/100.0) * pop14) + 0.5); }
  int getpopUnder5Count() const { return (int)(((popUnder5/100.0) * pop14) + 0.5); }
  int getBAupCount() const { return (int)(((popBA/100.0) * pop14) + 0.5); }
  int getHSupCount() const { return (int)(((popHS/100.0) * pop14) + 0.5); }
  double getPopUnderPovCount() const { return int(((popUnderPoverty/100.0)*pop14) + 0.5); }

  friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

  shared_ptr<raceDemogData> raceData; //public
private:
  const string name;
  const string state;
  const double popOver65;
  const double popUnder18;
  const double popUnder5;
  const double popBA;
  const double popHS;
  const double popUnderPoverty;
  const double pop14;
  //shared_ptr<raceDemogData> raceData; 
};
#endif
