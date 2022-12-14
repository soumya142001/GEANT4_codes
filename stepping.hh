#ifndef STEPPING_HH
#define STEPPING_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "construction.hh"
#include "event.hh"

class MySteppingAction : public G4UserSteppingAction
{
 public:
    MySteppingAction(MyDetectorConstruction* det, MyEventAction* eventAction);
    ~MySteppingAction();
    
    virtual void UserSteppingAction(const G4Step*);
    
  private:
     MyEventAction* fEventAction;
     MyDetectorConstruction* fDetector;

};

#endif
