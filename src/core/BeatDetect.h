//
//  BeatDetect.h
//  MusicBeamPort
//
//  Created by tekt on 1/28/15.
//
//

#ifndef __MusicBeamPort__BeatDetect__
#define __MusicBeamPort__BeatDetect__

class BeatDetect {
public:
  bool isKick() const;
  bool isSnare() const;
  bool isHat() const;
  bool isOnset() const;
};

#endif /* defined(__MusicBeamPort__BeatDetect__) */
