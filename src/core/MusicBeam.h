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
#include <ofxBeatDetector.h>
#include "Stage.h"

class MusicBeam {
public:
  ofParameter<bool> projectorToggle;
  ofParameter<bool> randomToggle;
  ofParameter<float> randomTime;
  ofParameter<float> beatDelay;
  ofParameter<float> minLevel;
  ofParameter<float> inputMixLevel;
  ofxBeatDetector frequencyDetect;
  ofxBeatDetector soundDetect;
  Stage stage;
};

#endif /* defined(__MusicBeamPort__MusicBeam__) */
