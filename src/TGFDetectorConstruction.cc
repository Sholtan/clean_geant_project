#include "TGFDetectorConstruction.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4Material.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4RunManager.hh"
#include "G4AutoDelete.hh"
#include "G4SDManager.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

#include "G4FieldManager.hh"


TGFDetectorConstruction::TGFDetectorConstruction()
{}

TGFDetectorConstruction::~TGFDetectorConstruction()
{}


G4VPhysicalVolume* TGFDetectorConstruction::Construct()
{
	

	G4Material *WorldMat = new G4Material("WorldMat", 0.81e-3 * g/cm3, 3);     
	WorldMat->AddElement(nist->FindOrBuildElement("N"), 75.5 * perCent);
	WorldMat->AddElement(nist->FindOrBuildElement("O"), 23.2 * perCent);
	WorldMat->AddElement(nist->FindOrBuildElement("Ar"), 1.28 * perCent);

	// World
	G4Box *solidWorld = new G4Box("solidWorld", 50 * m, 50 * m, 50 * m);
	flogicWorld = new G4LogicalVolume(solidWorld, WorldMat, "flogicWorld");
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), flogicWorld, "physWorld", 0, false, 0, true);
	



	return physWorld;
}



void TGFDetectorConstruction::ConstructSDandField()
{

}





