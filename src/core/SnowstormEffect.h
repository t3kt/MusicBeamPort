//
//  SnowstormEffect.h
//  MusicBeamPort
//
//  Created by tekt on 1/31/15.
//
//

#ifndef __MusicBeamPort__SnowstormEffect__
#define __MusicBeamPort__SnowstormEffect__

#include "Effect.h"
#include <list>
#include <ofVec3f.h>

class SnowstormEffect : public Effect {
public:
  SnowstormEffect(MusicBeam& ctrl);
  const std::string& getName() const override;
  char triggeredByKey() const override { return '6'; }
  void keyPressed(int key) override;
  bool isTriggered();
  void draw() override;
  
  ofParameter<float> radius;
  ofParameter<float> speed;
  ofParameter<float> hue;
  ofParameter<bool> aHueToggle;
  ofParameter<bool> bwToggle;
private:
  std::list<ofVec3f> _points;
};

#endif /* defined(__MusicBeamPort__SnowstormEffect__) */
