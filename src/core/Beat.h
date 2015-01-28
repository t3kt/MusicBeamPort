//
//  Beat.h
//  MusicBeamPort
//
//  Created by tekt on 1/28/15.
//
//

#ifndef __MusicBeamPort__Beat__
#define __MusicBeamPort__Beat__

class Beat
{
public:
  bool hat, snare, kick, onset;
  
  float level;
  
  Beat(bool h, bool s, bool k, bool o, float l)
  : hat(h), snare(s), kick(k), onset(o), level(l) { }
};

#endif /* defined(__MusicBeamPort__Beat__) */
