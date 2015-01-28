//
//  Effect.cpp
//  MusicBeamPort
//
//  Created by tekt on 1/28/15.
//
//

#include "Effect.h"
#include "MusicBeam.h"

static int nextId() {
  static int last = 0;
  return ++last;
}

Effect::Effect(const MusicBeam& ctrl)
: _controller(ctrl)
, _id(nextId()) { }

void Effect::setup() {
  _paramGroup.setName(getName() + " Settings");
//  ctrl.activeEffect.addItem("("+triggeredByKey() + ")  " + getName(),i);
//  ctrl.activeSetting.addItem("settings"+getName(),i);
  _paramGroup.add(_randomToggle.set("RND", true));
  _paramGroup.add(_manualTriggered.set("Manual Trigger", false));
}

bool Effect::isHat() const {
  return getLevel() > _controller.minLevel.get() ? _controller.frequencyDetect.isHat() : false;
}

bool Effect::isSnare() const {
  return getLevel() > _controller.minLevel.get() ? _controller.frequencyDetect.isSnare() : false;
}

bool Effect::isKick() const {
  return getLevel() > _controller.minLevel.get() ? _controller.frequencyDetect.isKick() : false;
}

bool Effect::isOnset() const {
  return getLevel() > _controller.minLevel.get() ? _controller.soundDetect.isOnset() : false;
}

float Effect::getLevel() const {
  return _controller.inputMixLevel.get();
}
