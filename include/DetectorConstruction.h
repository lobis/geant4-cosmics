//
// Created by lobis on 22/10/2022.
//

#ifndef GEANT4_COSMICS_DETECTORCONSTRUCTION_H
#define GEANT4_COSMICS_DETECTORCONSTRUCTION_H

#include <G4VUserDetectorConstruction.hh>

class G4VPhysicalVolume;
class G4LogicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction {
public:
    inline DetectorConstruction() = default;
    inline ~DetectorConstruction() override = default;

    G4VPhysicalVolume* Construct() override;
};

#endif // GEANT4_COSMICS_DETECTORCONSTRUCTION_H
