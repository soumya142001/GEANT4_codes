#ifndef RUN_HH
#define RUN_HH

#include "g4root.hh"
#include "G4Run.hh"
#include "globals.hh"

#include "G4UserRunAction.hh"

class MyRunAction : public G4UserRunAction, public G4Run
{
 public:
     MyRunAction();
     ~MyRunAction();
     
     virtual void BeginOfRunAction(const G4Run*);
     virtual void EndOfRunAction(const G4Run*);
 
};


#endif
