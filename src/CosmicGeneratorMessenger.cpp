//
// Created by lobis on 28/10/2022.
//

#include "CosmicGeneratorMessenger.h"

using namespace std;

CosmicGeneratorMessenger::CosmicGeneratorMessenger(PrimaryGeneratorAction* primaryGeneratorAction) : fPrimaryGeneratorAction(primaryGeneratorAction) {

    fCosmicGeneratorDirectory = make_unique<G4UIdirectory>("/cosmic/");
    fCosmicGeneratorDirectory->SetGuidance("Cosmic primary generator controls");

    fPrintCommand = make_unique<G4UIcmdWithoutParameter>("/cosmic/print", this);
    fPrintCommand->SetGuidance("Print generator info");
}

void CosmicGeneratorMessenger::SetNewValue(G4UIcommand* command, G4String newValues) {
    G4UImessenger::SetNewValue(command, newValues);
}

G4String CosmicGeneratorMessenger::GetCurrentValue(G4UIcommand* command) {
    return G4UImessenger::GetCurrentValue(command);
}
