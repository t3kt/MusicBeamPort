//
//  BlackoutEffect.h
//  MusicBeamPort
//
//  Created by tekt on 1/30/15.
//
//

#ifndef __MusicBeamPort__BlackoutEffect__
#define __MusicBeamPort__BlackoutEffect__

#include "Effect.h"

class BlackoutEffect : public Effect {
public:
  BlackoutEffect(MusicBeam& ctrl) : Effect(ctrl) { }
  const std::string& getName() const override;
  char triggeredByKey() const override { return '0'; }
  void draw() override { }
};

#endif /* defined(__MusicBeamPort__BlackoutEffect__) */
