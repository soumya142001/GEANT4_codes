#include "stepping.hh"
#include "construction.hh"
#include "run.hh"

MySteppingAction::MySteppingAction(MyDetectorConstruction* det, MyEventAction* eventAction)
{
  fEventAction = eventAction;
  fDetector = det;
}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step *step)
{
   
   G4LogicalVolume *vol[10];
   G4LogicalVolume *fScoringVol[10];
   G4int copyNo;
   G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
   const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
   
   const G4VTouchable *touchable = step->GetPreStepPoint()->GetTouchable();
  
   copyNo = touchable->GetCopyNumber(0);
   
   G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
   
  // if(volume != fScoringVolume)
   //  return;
   
   //get Run
  MyRunAction* run = static_cast<MyRunAction*>(
             G4RunManager::GetRunManager()->GetNonConstCurrentRun());
             
   //if(volume != fDetector->GetphysDet(copyNo))
    //return;
   
   G4cout<<"Copy Number"<<copyNo<<G4endl;
   
   G4double edep = step->GetTotalEnergyDeposit();
   //G4double edep = step->GetNonIonizingEnergyDeposit();
   
   
   fEventAction->AddEdep(copyNo,edep);

}   

  
