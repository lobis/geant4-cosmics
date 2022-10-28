//
// Created by lobis on 22/10/2022.
//

#ifndef GEANT4_COSMICS_PRIMARYGENERATORACTION_H
#define GEANT4_COSMICS_PRIMARYGENERATORACTION_H

#include "CosmicGeneratorMessenger.h"

#include <G4ParticleGun.hh>
#include <G4VUserPrimaryGeneratorAction.hh>

#include <TF1.h>
#include <TF2.h>

class CosmicGeneratorMessenger;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction() override = default;

    // method from the base class
    void GeneratePrimaries(G4Event*) override;

private:
    std::unique_ptr<G4ParticleGun> fParticleGun = nullptr;

    std::unique_ptr<CosmicGeneratorMessenger> fMessenger = nullptr;

    std::unique_ptr<TF1> fEnergyDist = nullptr;
    std::unique_ptr<TF1> fAngularDist = nullptr;
    std::unique_ptr<TF2> fEnergyAngularDist = nullptr;

    double fCircumscribedSphereRadius = 0.0;
};

#endif // GEANT4_COSMICS_PRIMARYGENERATORACTION_H
