//
// Created by lobis on 22/10/2022.
//

#ifndef GEANT4_COSMICS_EVENTACTION_H
#define GEANT4_COSMICS_EVENTACTION_H

#include <G4Event.hh>
#include <G4UserEventAction.hh>

class RunAction;

class EventAction : public G4UserEventAction {
public:
    EventAction() = default;
    ~EventAction() override = default;

    void BeginOfEventAction(const G4Event* event) override;
    void EndOfEventAction(const G4Event* event) override;
};
#endif // GEANT4_COSMICS_EVENTACTION_H
