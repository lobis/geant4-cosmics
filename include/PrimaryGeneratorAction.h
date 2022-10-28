//
// Created by lobis on 22/10/2022.
//

#ifndef GEANT4_COSMICS_PRIMARYGENERATORACTION_H
#define GEANT4_COSMICS_PRIMARYGENERATORACTION_H

#include <G4ParticleGun.hh>
#include <G4VUserPrimaryGeneratorAction.hh>

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction() override = default;

    // method from the base class
    void GeneratePrimaries(G4Event*) override;

private:
    std::unique_ptr<G4ParticleGun> fParticleGun = nullptr; // pointer a to G4 gun class
};

#endif // GEANT4_COSMICS_PRIMARYGENERATORACTION_H
