#ifndef EFFECTS_H
#define EFFECTS_H

#include "Unit.hpp"
#include "MontageClip.hpp"
#include "form.hpp"

#include <list>
#include <iostream>
#include <queue>
#include <functional>

namespace Effects {

void genQueue(std::queue<std::pair<std::function<bool(MontageClip&,eff_args&)>, std::string> > &q, MontageClip &mntg, bool tFlag);

bool blur(MontageClip &mntg, eff_args &al);
bool starburst(MontageClip &mntg, eff_args &al);
bool rotateImage(MontageClip &mntg, eff_args &al);
bool lensFlare(MontageClip &mntg, eff_args &al);
bool addImage(MontageClip &mntg, eff_args &al);
bool diceCheck(MontageClip &mntg, eff_args &al);
bool addHat(MontageClip &mntg, eff_args &al);

}

#endif // EFFECTS_H
