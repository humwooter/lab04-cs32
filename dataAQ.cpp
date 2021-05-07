/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include "demogState.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std; 

void dataAQ::createStateDemogData(std::vector<shared_ptr<demogData>> theData) {
  map<string, shared_ptr<demogState>> stateData; 
  string state;
  vector<string> States;
  
  for (int i = 0; i < theData.size(); i++) {
    state = theData[i]->getState();
    
    if (stateData.find(state) == stateData.end()) {
      stateData[state] = make_shared<demogState>(); 
      stateData[state]->name = state;
    }
    if (find(States.begin(), States.end(), state) == States.end()) States.push_back(state);


    stateData[state]->addCountyData(theData[i]);

  }

  setAllStateData(stateData);
  states = States;
}

void dataAQ::createStatePoliceData(std::vector<shared_ptr<psData>> theData) {
  map<string, shared_ptr<psState>> statePoliceData;
  string state;

  for (int i = 0; i < theData.size(); i++) {
    state = theData[i]->getState();
    if (statePoliceData.find(state) == statePoliceData.end()) {
      statePoliceData[state] = make_shared<psState>(state);
    }
    statePoliceData[state]->addCountyData(theData[i]); 
   
  }
  setPoliceData(statePoliceData);
}


//return the name of the state with the largest population under age 5
string dataAQ::youngestPop() {
  string stateYoungestPop;
  double greatestPopUnder5 = 0.0; 
  for (int i = 0; i < states.size(); i++) {
    string state = states[i];
    double popUnder5 = allStateData[state]->PopUnder5;
    double totalStatePop = allStateData[state]->totalPop;
    double percentUnder5 = (popUnder5/totalStatePop)*100.0;

    if (percentUnder5 > greatestPopUnder5) {
      greatestPopUnder5 = percentUnder5;
      stateYoungestPop = state;
    }

  }
  return stateYoungestPop; 
} 

//return the name of the state with the largest population under age 18
string dataAQ::teenPop()  {
  string stateTeenPop;
  double greatestPopUnder18 = 0.0;
  for (int i = 0; i <  states.size(); i++) {
    string state = states[i];
    double popUnder18 = allStateData[state]->PopUnder18;
    double totalStatePop = allStateData[state]->totalPop;
    double percentUnder18 = (popUnder18/totalStatePop)*100.0;

    if (percentUnder18 > greatestPopUnder18) {
      greatestPopUnder18 = percentUnder18;
      stateTeenPop = state;
    }

  }
  return stateTeenPop;
 
}

//return the name of the state with the largest population over age 65
string dataAQ::wisePop()  {
  string stateWisePop;
  double greatestPopOver65 = 0.0;
  for (int i = 0; i <  states.size(); i++) {
    string state = states[i];
    double popOver65 = allStateData[state]->PopOver65;
    double totalStatePop = allStateData[state]->totalPop;
    double percentOver65 = (popOver65/totalStatePop)*100.0;

    if (percentOver65 > greatestPopOver65) {
      greatestPopOver65 = percentOver65;
      stateWisePop = state;
    }

  }
  return stateWisePop;
}

//return the name of the state with the largest population who did not receive high school diploma
string dataAQ::underServeHS() {
  string stateUnderServeHS;
  double greatestUnderServeHS = 100.0;
  for (int i = 0; i <  allStateData.size(); i++) {
    string state = states[i];
    double popHS = allStateData[state]->popHS;
    double totalStatePop = allStateData[state]->totalPop;
    double percentHSup = (popHS/totalStatePop)*100.0;

    if (percentHSup < greatestUnderServeHS) {
      greatestUnderServeHS = percentHSup;
      stateUnderServeHS = state;
    }

  }
  return stateUnderServeHS;
} 

//return the name of the state with the largest population who did receive bachelors degree and up
string dataAQ::collegeGrads() {
  string stateGreatestBA;
  double greatestBA = 0.0;
  for (int i = 0; i <  states.size(); i++) {
    string state = states[i];
    double popBA = allStateData[state]->popBA;
    double totalStatePop = allStateData[state]->totalPop;
    double percentBA = (popBA/totalStatePop)*100.0;

    if (percentBA > greatestBA) {
      greatestBA = percentBA;
      stateGreatestBA = state;
    }

  }
  return stateGreatestBA;
}

//return the name of the state with the largest population below the poverty line
string dataAQ::belowPoverty() {
  string stateGreatestBelowPov;
  double greatestBelowPov = 0.0;
  for (int i = 0; i <  states.size(); i++) {
    string state = states[i];
    double popBelowPov = allStateData[state]->PopBelowPoverty;
    double totalStatePop = allStateData[state]->totalPop;
    double percentBelowPov = (popBelowPov/totalStatePop)*100.0;

    if (percentBelowPov > greatestBelowPov) {
      greatestBelowPov = percentBelowPov;
      stateGreatestBelowPov = state;
    }

  }
  return stateGreatestBelowPov;
} 

//predicates:
bool sortByPS(shared_ptr<psState> & a, shared_ptr<psState> & b)
{
  return (a->getNumberOfCases() > b->getNumberOfCases());
}

bool sortByBP(shared_ptr<demogState> & a, shared_ptr<demogState> & b)
{
  return (a->PopBelowPovertyPercent > b->PopBelowPovertyPercent);
}

//sort and report the top ten states in terms of number of police shootings      
void dataAQ::reportTopTenStatesPS() {
  map<string, shared_ptr<psState>> policeData = getPoliceStateData();
  vector<shared_ptr<psState>> psStates;

  for (string state: states) psStates.push_back(policeData[state]);
  std::sort(psStates.begin(), psStates.end(), &sortByPS);
  cout << "Testing sort on PS state data..." << endl;
  cout << "Top ten states sorted on number of police shootings & the associated census data:" << endl;

  cout << std::fixed << std::showpoint << std::setprecision(2);

  for (int i = 0; i < 10; i++) {
    cout << psStates[i]->getState() << endl;
    cout <<  "Total population: " << int(this->allStateData[psStates[i]->getState()]->totalPop) << endl;
    cout << "Police shooting incidents: " << psStates[i]->getNumberOfCases() << endl;
    cout << "Percent below poverty: " << (this->allStateData[psStates[i]->getState()]->PopBelowPoverty/this->allStateData[psStates[i]->getState()]->totalPop)*100 << endl; 
  }

  cout << "**Full listings for top 3 police shootings & the associated census data:" << endl;
  for (int i = 0; i < 3; i++) {
    cout << *(psStates[i]);
  }

}

//sort and report the top ten states with largest population below poverty              
void dataAQ::reportTopTenStatesBP() {
  map<string, shared_ptr<demogState>> stateData = getAllStateData();
  vector<shared_ptr<demogState>> demogStates;

  for (string state: states) demogStates.push_back(stateData[state]);
  std::sort(demogStates.begin(), demogStates.end(), &sortByBP);
  cout << "Testing sort on BP state data..." << endl;
  cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:" << endl;

  cout << std::fixed << std::showpoint << std::setprecision(2);

  for (int i = 0; i < 10; i++) {
    cout << demogStates[i]->name << endl;
    cout << "Total population: " << int(demogStates[i]->totalPop) << endl;
    cout << "Percent below poverty: " << (demogStates[i]->PopBelowPoverty/demogStates[i]->totalPop)*100 << endl;
    cout << "Police shooting incidents: " << this->getStatePoliceData(demogStates[i]->name)->getNumberOfCases() << endl;
  }

  cout << "**Full listings for top 3 Below Poverty data & the associated police shooting data for top 3:" << endl;
  for (int i = 0; i < 3; i++) {
    cout << *(demogStates[i]);
  }
}



std::ostream& operator<<(std::ostream &out, dataAQ &allStateDemogData) {
    out << "*** the state that needs the most pre-schools**" << endl;
    string needPK = allStateDemogData.youngestPop();
    demogState stateMostUnder5 = *(allStateDemogData.getStateData(needPK));
    out << stateMostUnder5;
    psState psUnder5 = *(allStateDemogData.getStatePoliceData(needPK));
    out << psUnder5; 

    out <<"*** the state that needs the most high schools**" << endl;

    string mostHS = allStateDemogData.teenPop();
    demogState stateMostHS = *(allStateDemogData.getStateData(mostHS));
    out << stateMostHS;
    psState psMostHS = *(allStateDemogData.getStatePoliceData(mostHS));
    out << psMostHS;
    
    out <<"*** the state that needs the most vaccines**" << endl;

    string mostOver65 = allStateDemogData.wisePop();
    demogState stateMostVaccines = *(allStateDemogData.getStateData(mostOver65));
    out << stateMostVaccines;
    psState psOver65 = *(allStateDemogData.getStatePoliceData(mostOver65));
    out << psOver65;

    out <<"*** the state that needs the most help with education**" << endl;

    string leastHS = allStateDemogData.underServeHS();
    demogState stateLeastHS = *(allStateDemogData.getStateData(leastHS));
    out << stateLeastHS;
    psState psLeastHS = *(allStateDemogData.getStatePoliceData(leastHS));
    out << psLeastHS;

    out <<"*** the state with most college grads**" << endl;

    string mostBA = allStateDemogData.collegeGrads();
    demogState stateMostBA = *(allStateDemogData.getStateData(mostBA));
    out << stateMostBA;
    psState psMostBA = *(allStateDemogData.getStatePoliceData(mostBA));
    out << psMostBA;

    out <<"*** the state with largest percent of the population below the poverty line**" << endl;

    string mostPoverty = allStateDemogData.belowPoverty();
    demogState stateMostPoverty = *(allStateDemogData.getStateData(mostPoverty));
    out << stateMostPoverty;
    psState psMostPoverty = *(allStateDemogData.getStatePoliceData(mostPoverty));
    out << psMostPoverty;

    return out;
}



