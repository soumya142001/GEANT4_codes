#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "globals.hh"
#include "construction.hh"

#include "g4root.hh"

#include "run.hh"

class MyEventAction : public G4UserEventAction
{
   public:
      MyEventAction(MyDetectorConstruction*, MyRunAction*);
      ~MyEventAction();
      
      virtual void BeginOfEventAction(const G4Event*);
      virtual void EndOfEventAction(const G4Event*);
      
      void AddEdep(G4int k, G4double edep) { 
      fEdep[k] += edep; 
      }
      
      
   private:
   
      MyDetectorConstruction* fDetector;
   
      G4double fEdep[1000];
      
      
};

#endif
