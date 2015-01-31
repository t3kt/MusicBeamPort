//
//  StrobeEffect.h
//  MusicBeamPort
//
//  Created by tekt on 1/30/15.
//
//

#ifndef __MusicBeamPort__StrobeEffect__
#define __MusicBeamPort__StrobeEffect__

#include "Effect.h"

class StrobeEffect : public Effect {
public:
  StrobeEffect(MusicBeam& ctrl);
  const std::string& getName() const override;
  char triggeredByKey() const override { return '1'; }
  void keyPressed(int key) override;
  bool isTriggered();
  void draw() override;
  
  ofParameter<float> delay;
  ofParameter<float> hue;
  ofParameter<bool> hatToggle;
  ofParameter<bool> snareToggle;
  ofParameter<bool> kickToggle;
  ofParameter<bool> onsetToggle;
  ofParameter<bool> aHueToggle;
  ofParameter<bool> bwToggle;
private:
  float _timer;
  bool _state;
};

#endif /* defined(__MusicBeamPort__StrobeEffect__) */
