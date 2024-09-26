#include "TGFSteppingAction.hh"


TGFSteppingAction::TGFSteppingAction(TGFEventAction* eventAction)
{
	fEventAction = eventAction;
}

TGFSteppingAction::~TGFSteppingAction()
{}

void TGFSteppingAction::UserSteppingAction(const G4Step *aStep)
{

	
	G4Track* track = aStep->GetTrack();
	
	const G4ParticleDefinition* particleDefinition = track->GetParticleDefinition();
	const G4String& particlename = particleDefinition->GetParticleName();	

	G4double pdgcharge = particleDefinition->GetPDGCharge();
	G4int pdg = particleDefinition->GetPDGEncoding();

	G4int CurrentStepNumber = track->GetCurrentStepNumber();
	G4int track_id = track->GetTrackID();
	G4double globalTime = track->GetGlobalTime();

	const G4DynamicParticle* dParticle = track->GetDynamicParticle();
	//G4double depositEnergy = aStep->GetTotalEnergyDeposit();
	G4double kinEnergy = dParticle->GetKineticEnergy();
	G4double Energy = dParticle->GetTotalEnergy();

	G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
	G4ThreeVector positionParticle = preStepPoint->GetPosition();

	G4double trackLength = track->GetTrackLength();
	G4double stepLength = track->GetStepLength();



	if (CurrentStepNumber == 1)
	{
		G4cout << "track_id: " << track_id << ", energy: " << kinEnergy << G4endl;	
	}
	

/*****************************************************
// kill the particle
/*
	if (true)
	{
		track->SetTrackStatus(fStopAndKill);
		return;

	}
*/
/*****************************************************




}




