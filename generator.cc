#include "generator.hh"


MyPrimaryGenerator::MyPrimaryGenerator()
{
  fParticleGun = new G4ParticleGun(1);
  
  /*G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName ="proton";
  G4ParticleDefinition *particle = particleTable->FindParticle("proton");
  //G4ParticleDefinition *particle = particleTable->FindParticle("chargedgeantino");
   
  G4ThreeVector pos(0.,0.,0.);
  G4ThreeVector mom(0.,0.,1.);
   
  fParticleGun->SetParticlePosition(pos);
  fParticleGun->SetParticleMomentumDirection(mom);
  fParticleGun->SetParticleMomentum(100.*GeV);
  fParticleGun->SetParticleDefinition(particle);*/
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
  delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
   
  G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName ="alpha";
  G4ParticleDefinition *particle = particleTable->FindParticle("alpha");
  //G4ParticleDefinition *particle = particleTable->FindParticle("chargedgeantino");
   
  G4ThreeVector pos(0.,0.,-0.5*m);
  G4ThreeVector mom(0.,0.,1.);
   
  fParticleGun->SetParticlePosition(pos);
  fParticleGun->SetParticleMomentumDirection(mom);
  //fParticleGun->SetParticleMomentum(50.*GeV);
  fParticleGun->SetParticleEnergy(5.49*MeV);
  fParticleGun->SetParticleDefinition(particle);
  
   /*G4ParticleDefinition* particle = fParticleGun->GetParticleDefinition();
   
   if(particle == G4ChargedGeantino::ChargedGeantino())
   {
       G4int Z = 27;
       G4int A = 60;
       
       
       G4double charge = 0.*eplus;
       G4double energy = 0.*keV;
       
       
       G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(Z, A, energy);
       
       fParticleGun->SetParticleDefinition(ion);
       fParticleGun->SetParticleCharge(charge);
   }*/
   
   fParticleGun->GeneratePrimaryVertex(anEvent);
}  
    
  
