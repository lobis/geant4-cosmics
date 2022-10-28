//
// Created by lobis on 28/10/2022.
//

#ifndef GEANT4_COSMICS_COSMICGENERATORMESSENGER_H
#define GEANT4_COSMICS_COSMICGENERATORMESSENGER_H

#include <G4UImessenger.hh>

#include "PrimaryGeneratorAction.h"

#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithADoubleAndUnit.hh>
#include <G4UIcmdWithAString.hh>
#include <G4UIcmdWithoutParameter.hh>

#include <memory>

class PrimaryGeneratorAction;

class CosmicGeneratorMessenger : public G4UImessenger {
public:
    explicit CosmicGeneratorMessenger(PrimaryGeneratorAction* action);

public:
    void SetNewValue(G4UIcommand* command, G4String newValues) override;
    G4String GetCurrentValue(G4UIcommand* command) override;

private:
    const PrimaryGeneratorAction* fPrimaryGeneratorAction;

private:
    std::unique_ptr<G4UIdirectory> fCosmicGeneratorDirectory;
    std::unique_ptr<G4UIcmdWithoutParameter> fPrintCommand;

    std::unique_ptr<G4UIcmdWithAString> fEnergyFormulaCommand;
    std::unique_ptr<G4UIcmdWithAString> fAngularFormulaCommand;
    std::unique_ptr<G4UIcmdWithAString> fEnergyAngularFormulaCommand;

    std::unique_ptr<G4UIcmdWithADoubleAndUnit> fEnergyMinCommand;
    std::unique_ptr<G4UIcmdWithADoubleAndUnit> fEnergyMaxCommand;
    std::unique_ptr<G4UIcmdWithADoubleAndUnit> fAngularMinCommand;
    std::unique_ptr<G4UIcmdWithADoubleAndUnit> fAngularMaxCommand;
};

#endif // GEANT4_COSMICS_COSMICGENERATORMESSENGER_H
