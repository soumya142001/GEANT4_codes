#include "event.hh"
#include "run.hh"

MyEventAction::MyEventAction(MyDetectorConstruction* det, MyRunAction*)
{
  
  fDetector = det;
  
  for(G4int k=0;k<1000;k++)
  {
   fEdep[k] = 0.;
  } 
}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
   for(G4int k=0;k<1000;k++)
  {
   fEdep[k] = 0.;
  } 
   

}

void MyEventAction::EndOfEventAction(const G4Event*)
{


  //get Run
  MyRunAction* run = static_cast<MyRunAction*>(
  G4RunManager::GetRunManager()->GetNonConstCurrentRun());

//const G4VTouchable *touchable = step->GetPreStepPoint()->GetTouchable();
  
//G4int copyNo = touchable->GetCopyNumber();
   
 for(G4int k=0;k<1000;k++)
 {
 
  G4cout<<fEdep[k]<<G4endl;
  
  //run->FillPerEvent(k,fEdep[k]);
 
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  
  man->FillNtupleDColumn(2,k,fEdep[k]);
  
  man->AddNtupleRow(2);
}
}  
 
