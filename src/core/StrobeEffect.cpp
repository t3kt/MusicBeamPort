//
//  StrobeEffect.cpp
//  MusicBeamPort
//
//  Created by tekt on 1/30/15.
//
//

#include "StrobeEffect.h"
#include "Stage.h"
#include "MusicBeam.h"
#include <ofMain.h>
#include <math.h>

static std::string name("Strobe");

const std::string& StrobeEffect::getName() const {
  return name;
}

StrobeEffect::StrobeEffect(MusicBeam& ctrl)
: Effect(ctrl)
, _timer(0)
, _state(false) { }

bool StrobeEffect::isTriggered() {
  if (_manualTriggered.get())
    return true;
  else if ((!onsetToggle.get() && hatToggle.get() && isHat()) || (onsetToggle.get() && isOnset() && hatToggle.get() && isHat()))
    return true;
  else if ((!onsetToggle.get() && snareToggle.get() && isSnare()) || (onsetToggle.get() && isOnset() && snareToggle.get() && isSnare()))
    return true;
  else if ((!onsetToggle.get() && kickToggle.get() && isKick()) || (onsetToggle.get() && isOnset() && kickToggle.get() && isKick()))
    return true;
  else if (onsetToggle.get() && isOnset())
    return true;
  else
    return false;
}

void StrobeEffect::draw() {
  auto frameRate = ofGetFrameRate();
  if (_state && (_timer <= 0 || _timer < frameRate/2-delay.get()-3)) {
    _state = false;
    _timer = frameRate/2-delay.get();
  }
  else if (!_state && isTriggered() && _timer <= 0) {
    _state = true;
    _timer = frameRate/2-delay.get();
  }
  
  if (_timer > 0)
    _timer--;
  
  if (aHueToggle.get())
    hue.set(std::fmod((hue.get()+1), 360));
  
  ofSetColor(ofColor::fromHsb(hue.get(), bwToggle.get()?0:100, 100));
  ofFill();
  if (_state) {
    auto maxRadius = _controller.stage.maxRadius.get();
    ofRect(-maxRadius/2, -maxRadius/2, maxRadius, maxRadius);
  }
}

void StrobeEffect::keyPressed(int key) {
  Effect::keyPressed(key);
  if (key == OF_KEY_LEFT)
    delay.set(delay.get()-1);
  else if (key == OF_KEY_RIGHT)
    delay.set(delay.get()+1);
}
