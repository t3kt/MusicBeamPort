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
#include <ofVec2f.h>

class MusicBeam;

class Effect {
public:
  explicit Effect(MusicBeam& ctrl);
  
  virtual void setup();
  
  int getId() const { return _id; }
  
  virtual const std::string& getName() const = 0;
  virtual void draw() = 0;
  
  void refresh() {
    draw();
    resetStage();
  }
  
  bool isHat();
  
  bool isSnare();
  
  bool isKick();
  
  bool isOnset();
  
  bool isActive();
  
  void activate();
  
  float getLevel() const;
  
  void hideControls();
  void showControls();
  
  void rotate(float r);
  void resetRotation();
  
  void translate(const ofVec2f& t);
  void resetTranslation();
  
  void resetStage();
  
  virtual char triggeredByKey() const = 0;
  
  virtual void keyPressed(int key) {}
  virtual void keyReleased(int key) {}
protected:
  const int _id;
  MusicBeam& _controller;
  ofParameterGroup _paramGroup;
  ofParameter<bool> _randomToggle;
  ofParameter<bool> _manualTriggered;
  float _rotationHistory;
  ofVec2f _translationHistory;
};

#endif /* defined(__MusicBeamPort__Effect__) */
