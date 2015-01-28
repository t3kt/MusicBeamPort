//
//  Effect.h
//  MusicBeamPort
//
//  Created by tekt on 1/28/15.
//
//

#ifndef __MusicBeamPort__Effect__
#define __MusicBeamPort__Effect__

#include <string>
#include <ofParameterGroup.h>
#include "MusicBeam.h"

class Effect {
public:
  explicit Effect(const MusicBeam& ctrl);
  
  const int id;
  
  virtual const std::string& getName() const = 0;
  virtual void draw() = 0;
  
  void refresh() {
    draw();
    resetStage();
  }
  
  void resetStage() {
    //...
  }
  
  float getLevel() const {
    return _controller.inputMixLevel.get();
  }
private:
  const MusicBeam& _controller;
};

#endif /* defined(__MusicBeamPort__Effect__) */
