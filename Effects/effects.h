#ifndef EFFECTS_H
#define EFFECTS_H

#include "Unit.hpp"
#include "MontageClip.hpp"
#include "form.hpp"

#include <list>
#include <iostream>
#include <queue>
#include <functional>
#include <string>


class EffectFactory{
private:
    static std::vector< std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string > > funcs;
public:
    unsigned getFCount();
    static std::function<bool(MontageClip&, eff_args&)> makeEffect(int x=-1);
    static std::string getFName( int x );
};

namespace Effects {

//have functions perform single opperations and have themselves to the Actions
// I wrote ^this^ at 4am lel

void genQueue(std::queue<std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string> > &q, MontageClip &mntg, bool tFlag);

bool blur(MontageClip &mntg, eff_args &al);
bool addHat(MontageClip &mntg, eff_args &al);
bool addText(MontageClip &mntg, eff_args &al);
bool addImage(MontageClip &mntg, eff_args &al);
bool starburst(MontageClip &mntg, eff_args &al);
bool lensFlare(MontageClip &mntg, eff_args &al);
bool doNothing(MontageClip &mntg, eff_args &al);
bool rotateImage(MontageClip &mntg, eff_args &al);
}

namespace Actions{
// this is new
// what does this does?1
}
#endif // EFFECTS_H
