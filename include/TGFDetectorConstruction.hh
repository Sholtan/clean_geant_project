#ifndef TGFDetectorConstruction_HH
#define TGFDetectorConstruction_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "tools/colors"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

#include "G4SystemOfUnits.hh"

#include "G4Cache.hh"



class TGFDetectorConstruction: public G4VUserDetectorConstruction
{
public:
	TGFDetectorConstruction();
	~TGFDetectorConstruction();

	virtual G4VPhysicalVolume *Construct();

	

private:
	G4LogicalVolume *flogicWorld;
	virtual void ConstructSDandField();

	G4NistManager *nist = G4NistManager::Instance();

};

#endif



