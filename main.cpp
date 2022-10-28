//
// Created by lobis on 22/10/2022.
//

#include <G4RunManagerFactory.hh>
#include <G4UIExecutive.hh>
#include <G4UImanager.hh>
#include <G4VModularPhysicsList.hh>
#include <G4VisExecutive.hh>
#include <QBBC.hh>
#include <iostream>

#include "ActionInitialization.h"
#include "DetectorConstruction.h"
#include "UIMacros.h"

using namespace std;

int main(int argc, char** argv) {

    // Detect interactive mode (if no arguments) and define UI session
    //
    auto ui = make_unique<G4UIExecutive>(argc, argv);

    // Optionally: choose a different Random engine...
    // G4Random::setTheEngine(new CLHEP::MTwistEngine);

    auto* runManager =
            G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

    // Set mandatory initialization classes
    //
    // Detector construction
    runManager->SetUserInitialization(new DetectorConstruction());

    // Physics list
    G4VModularPhysicsList* physicsList = new QBBC;
    physicsList->SetVerboseLevel(1);
    runManager->SetUserInitialization(physicsList);

    // User action initialization
    runManager->SetUserInitialization(new ActionInitialization());

    // Initialize visualization
    //
    auto visManager = make_unique<G4VisExecutive>();
    // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
    // G4VisManager* visManager = new G4VisExecutive("Quiet");
    visManager->Initialize();

    // Get the pointer to the User Interface manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    UImanager->ApplyCommand("/run/initialize");
    ExecuteVisualizationMacro();

    ui->SessionStart();

    delete runManager;
}