#include "TGFPrimaryGenerator.hh"

TGFPrimaryGenerator::TGFPrimaryGenerator()
{
	fParticleGun = new G4ParticleGun(1);
}

TGFPrimaryGenerator::~TGFPrimaryGenerator()
{
	delete fParticleGun;
}

	


void TGFPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{

	

	G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
	G4IonTable* Iontable = particleTable->GetIonTable();
	G4ParticleDefinition* particle = particleTable->FindParticle(11);  // electron


	G4ThreeVector pos(0.*m,0., 0.); 
    
    G4ThreeVector mom(0., 0., 1.);

    G4double PrimaryEnergy = 100*GeV;

    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleEnergy(PrimaryEnergy);

    fParticleGun->GeneratePrimaryVertex(anEvent);
}



