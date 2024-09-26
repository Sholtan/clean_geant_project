#include <iostream>

//#include "G4MTRunManager.hh"
#include "G4RunManager.hh"


#include "G4UImanager.hh"
#include"G4UIExecutive.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"


#include "TGFDetectorConstruction.hh"
#include "TGFActionInitialization.hh"
#include <QGSP_BERT_HP.hh>

//#include "Randomize.hh"


int main(int argc, char** argv)
{

    //G4MTRunManager* runManager = new G4MTRunManager();     // Multithreaded mode
    //runManager->SetNumberOfThreads(4);

    G4RunManager* runManager = new G4RunManager();     //  Single thread mode

    G4cout << G4endl << G4endl << "NUMBER THREADS: " << runManager->GetNumberOfThreads() << G4endl<< G4endl;


    TGFDetectorConstruction *detectorConstruction = new TGFDetectorConstruction();
    runManager->SetUserInitialization(detectorConstruction);
    
    runManager->SetUserInitialization(new QGSP_BERT_HP(0));   // ARGUMENT IS VERBOSE LEVEL

    TGFActionInitialization *actionInitialization = new TGFActionInitialization();
    runManager->SetUserInitialization(actionInitialization);
    
    runManager->Initialize();


    //executing run.mac
    /*
    G4UImanager* UI = G4UImanager::GetUIpointer();
    UI->ApplyCommand("/control/execute run.mac");
    */
    //visualization
    //-----------------------------   
    
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);

    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();

    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 0 1 -1");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
    //UImanager->ApplyCommand("/vis/scene/add/axes 0 0 0 5 m");

    ui->SessionStart();
    delete ui;
    delete visManager;
    //-----------------------------   
    
    
    delete runManager;

    return 0;
}
