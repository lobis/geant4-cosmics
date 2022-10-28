//
// Created by lobis on 22/10/2022.
//

#include "DetectorConstruction.h"

#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4NistManager.hh>
#include <G4PVPlacement.hh>
#include <G4SystemOfUnits.hh>
#include <G4Tubs.hh>
#include <globals.hh>

G4VPhysicalVolume* DetectorConstruction::Construct() {

    const auto nist = G4NistManager::Instance();

    /*
     * The detector volume is a cylinder made of a generic plastic scintillator material
     */

    constexpr double detectorDiameter = 10.0 * cm, detectorLength = 20.0 * cm;
    const auto detectorMaterial = nist->FindOrBuildMaterial("G4_WATER");

    const auto detectorSolid =
            new G4Tubs("Detector", 0., detectorDiameter / 2.0, detectorLength / 2.0, 0., 2. * M_PI * rad);

    const auto detectorLogical =
            new G4LogicalVolume(detectorSolid, detectorMaterial, detectorSolid->GetName());

    /*
     * The detector volume is a box filled with air which contains the detector volume
     */

    constexpr double worldSize = 50 * cm;
    const auto worldMaterial = nist->FindOrBuildMaterial("G4_AIR");

    const auto worldSolid =
            new G4Box("World",
                      0.5 * worldSize, 0.5 * worldSize, 0.5 * worldSize);

    const auto worldLogical =
            new G4LogicalVolume(worldSolid,
                                worldMaterial,
                                worldSolid->GetName());

    // Placements
    constexpr bool checkOverlaps = true;

    G4VPhysicalVolume* worldPhysical =
            new G4PVPlacement(nullptr,
                              G4ThreeVector(0, 0, 0),
                              worldLogical,
                              worldLogical->GetName(),
                              nullptr,
                              false,
                              0,
                              checkOverlaps);

    new G4PVPlacement(new G4RotationMatrix{0, M_PI / 2, 0},
                      G4ThreeVector(),
                      detectorLogical,
                      detectorLogical->GetName(),
                      worldLogical,
                      false,
                      0,
                      checkOverlaps);

    return worldPhysical;
}