//
// Created by lobis on 22/10/2022.
//

#include "PrimaryGeneratorAction.h"

#include <G4Box.hh>
#include <G4Event.hh>
#include <G4Geantino.hh>
#include <G4LogicalVolume.hh>
#include <G4MuonMinus.hh>
#include <G4ParticleDefinition.hh>
#include <G4PhysicalVolumeStore.hh>
#include <G4SystemOfUnits.hh>
#include <Randomize.hh>

using namespace std;

G4VPhysicalVolume* GetWorldVolume() {
    for (const auto& [name, volumes]: G4PhysicalVolumeStore::GetInstance()->GetMap()) {
        for (const auto& volume: volumes) {
            if (volume->GetMotherLogical() == nullptr) {
                return volume;
            }
        }
    }
    // we didn't find the world volume
    G4cout << "Error trying to find world volume" << endl;
    exit(1);
}

PrimaryGeneratorAction::PrimaryGeneratorAction() : fMessenger(make_unique<CosmicGeneratorMessenger>(this)) {

    fParticleGun = std::make_unique<G4ParticleGun>(1); // One particle at a time

    const auto particle = G4Geantino::Definition();
    fParticleGun->SetParticleDefinition(particle);

    const auto worldPhysical = GetWorldVolume();
    const auto worldSolid = dynamic_cast<G4Box*>(worldPhysical->GetLogicalVolume()->GetSolid());

    // get distance from center of box to one of its corners
    fCircumscribedSphereRadius = G4ThreeVector(worldSolid->GetXHalfLength(), worldSolid->GetYHalfLength(), worldSolid->GetZHalfLength()).mag();
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {

    fParticleGun->SetParticleEnergy(0.1 * MeV);

    // World volume is always centered at (0, 0, 0)

    // Random azimuthal and zenithal angles
    const auto phi = G4UniformRand() * 2. * M_PI;
    const auto theta = G4UniformRand() * M_PI / 2.; // TODO: use distribution

    const auto direction = G4ThreeVector(0., -1., 0.).rotateX(theta).rotateY(phi);
    fParticleGun->SetParticleMomentumDirection(direction);

    // Get random point in a disk
    const double u1 = G4UniformRand(), u2 = G4UniformRand();
    const auto positionInDisk = G4ThreeVector(sqrt(u1) * cos(2. * M_PI * u2), 0, sqrt(u1) * sin(2. * M_PI * u2)).rotateX(theta).rotateY(phi) * fCircumscribedSphereRadius;

    // Get intersection with sphere
    const G4ThreeVector toCenter = positionInDisk;
    double t = sqrt(fCircumscribedSphereRadius * fCircumscribedSphereRadius - toCenter.dot(toCenter));
    const auto position = positionInDisk - t * direction;

    fParticleGun->SetParticlePosition(position);

    fParticleGun->GeneratePrimaryVertex(event);
}
