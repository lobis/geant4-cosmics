//
// Created by lobis on 22/10/2022.
//

#include "PrimaryGeneratorAction.h"

#include <G4Box.hh>
#include <G4Event.hh>
#include <G4Geantino.hh>
#include <G4LogicalVolumeStore.hh>
#include <G4MuonMinus.hh>
#include <G4ParticleDefinition.hh>
#include <G4SystemOfUnits.hh>

PrimaryGeneratorAction::PrimaryGeneratorAction() {
    fParticleGun = std::make_unique<G4ParticleGun>(1); // One particle at a time

    const auto particle = G4MuonMinus::Definition();
    fParticleGun->SetParticleDefinition(particle);

    const auto worldLogicalName = "World";
    G4LogicalVolume* worldLogical = G4LogicalVolumeStore::GetInstance()->GetVolume("World");
    if (!worldLogical) {
        G4ExceptionDescription errorMessage;
        errorMessage << "World volume (" << worldLogicalName << ")not found" << G4endl;
        G4Exception("PrimaryGeneratorAction::PrimaryGeneratorAction()", "1", FatalException, errorMessage);
    }
    const auto worldSolid = dynamic_cast<G4Box*>(worldLogical->GetSolid());
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {

    fParticleGun->SetParticlePosition(G4ThreeVector(0, 20 * cm, 0));
    fParticleGun->SetParticleEnergy(1000. * MeV);
    fParticleGun->SetParticleMomentumDirection({0., -1., 0});

    fParticleGun->GeneratePrimaryVertex(event);
}
