//
// Created by lobis on 22/10/2022.
//

#ifndef GEANT4_COSMICS_RUNACTION_H
#define GEANT4_COSMICS_RUNACTION_H

#include <G4Run.hh>
#include <G4UserRunAction.hh>

class RunAction : public G4UserRunAction {
public:
    RunAction() = default;
    ~RunAction() override = default;

    void BeginOfRunAction(const G4Run*) override;
    void EndOfRunAction(const G4Run*) override;
};

#endif // GEANT4_COSMICS_RUNACTION_H
