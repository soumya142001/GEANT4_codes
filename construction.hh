#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4SystemOfUnits.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4GenericMessenger.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh"


#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
 public:
       MyDetectorConstruction();
       ~MyDetectorConstruction();
       
       G4LogicalVolume *GetScoringVolume() const {return fScoringVolume; }
       
       virtual G4VPhysicalVolume *Construct();
       void ConstructCherenkov();
       void ConstructScintillator();
       void ConstructTOF();
       void ConstructAtmosphere();
       void ConstructBeth();
       const G4VPhysicalVolume* GetphysDet(G4int i) const {return physDet[i];};
       
  private:
        G4LogicalVolume *logicDetector;    
        virtual void ConstructSDandField(); 
        
        G4GenericMessenger *fMessenger;
        
        G4LogicalVolume *fScoringVolume, *fScoringVol[10];
        
        G4int nCols, nRows; //G4int instead of int
        
        G4double xWorld, yWorld, zWorld;
        
        G4bool isCherenkov,isScintillator,isTOF, isAtmosphere, isBeth;
        
        G4OpticalSurface *mirrorSurface;
        
        G4Box *solidWorld,*solidRadiator,*solidDetector,*solidScintillator, *solidAtmosphere, *solidDet[1000];
        G4LogicalVolume *logicWorld,*logicRadiator,*logicScintillator,*logicAtmosphere[10], *logicDet[1000];
        G4VPhysicalVolume *physRadiator,*physWorld,*physDetector, *physScintillator, *physAtmosphere[10], *physDet[1000];
        
        G4Material *SiO2, *H2O, *Aerogel, *worldMat, *NaI, *Air[10], *mat[1000];
        G4Element *C, *Na, *I, *N, *O;
        
        void DefineMaterials();
        
        
};      
       
#endif
