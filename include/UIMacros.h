//
// Created by lobis on 28/10/2022.
//

#ifndef GEANT4_COSMICS_UIMACROS_H
#define GEANT4_COSMICS_UIMACROS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace macros {
    constexpr const char* visualization = R""""(
# Based on B1 example from Geant4 11.0.3 (https://github.com/Geant4/geant4/blob/3136fa97238bf2b24eba982206fb72b32b898d96/examples/basic/B1/vis.mac)

/vis/open OGL 600x600-0+0

/vis/viewer/set/autoRefresh false
/vis/verbose errors

/vis/drawVolume

# Specify view angle:
/vis/viewer/set/viewpointVector -1 0 0
/vis/viewer/set/lightsVector -1 0 0

/vis/viewer/set/style wireframe
/vis/viewer/set/auxiliaryEdge true
/vis/viewer/set/lineSegmentsPerCircle 100


# Draw smooth trajectories at end of event, showing trajectory points as markers 2 pixels wide:
/vis/scene/add/trajectories smooth
/vis/modeling/trajectories/create/drawByCharge
/vis/modeling/trajectories/drawByCharge-0/default/setDrawStepPts true
/vis/modeling/trajectories/drawByCharge-0/default/setStepPtsSize 2

/vis/scene/endOfEventAction accumulate

# Make the "World" box invisible
/vis/geometry/set/visibility World 0 false

/vis/viewer/set/autoRefresh true
/vis/verbose warnings
)"""";
}

void ExecuteMacro(const std::string& macro);
void ExecuteVisualizationMacro();

#endif // GEANT4_COSMICS_UIMACROS_H
