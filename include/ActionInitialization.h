//
// Created by lobis on 22/10/2022.
//

#ifndef GEANT4_COSMICS_ACTIONINITIALIZATION_H
#define GEANT4_COSMICS_ACTIONINITIALIZATION_H

#include <G4VUserActionInitialization.hh>

class ActionInitialization : public G4VUserActionInitialization {
public:
    ActionInitialization() = default;
    ~ActionInitialization() override = default;

    void BuildForMaster() const override;
    void Build() const override;
};

#endif // GEANT4_COSMICS_ACTIONINITIALIZATION_H
