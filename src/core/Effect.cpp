//
//  Effect.cpp
//  MusicBeamPort
//
//  Created by tekt on 1/28/15.
//
//

#include "Effect.h"

static int nextId() {
  static last = 0;
  return ++last;
}

Effect::Effect(const MusicBeam& ctrl)
: _controller(ctrl)
, id(nextId()) { }
