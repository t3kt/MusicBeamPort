//
//  MusicBeam.h
//  MusicBeamPort
//
//  Created by tekt on 1/28/15.
//
//

#ifndef __MusicBeamPort__MusicBeam__
#define __MusicBeamPort__MusicBeam__

#include <ofParameterGroup.h>
#include "BeatDetect.h"
#include "Stage.h"

class MusicBeam {
public:
  ofParameter<bool> projectorToggle;
  ofParameter<bool> randomToggle;
  ofParameter<float> randomTime;
  ofParameter<float> beatDelay;
  ofParameter<float> minLevel;
  ofParameter<float> inputMixLevel;
  BeatDetect frequencyDetect;
  BeatDetect soundDetect;
  Stage stage;
};

#endif /* defined(__MusicBeamPort__MusicBeam__) */
