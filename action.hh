#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"

#include "generator.hh"
#include "run.hh"
#include "event.hh"
#include "stepping.hh"
#include "construction.hh"

class MyActionInitialization : public G4VUserActionInitialization
{
  public:
        MyActionInitialization(MyDetectorConstruction*);
        ~MyActionInitialization();
        
        virtual void BuildForMaster() const;
        virtual void Build() const;
        
  private:
  
       MyDetectorConstruction* fDetector;      
       

};


#endif
