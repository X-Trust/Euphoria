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

void genQueue(std::queue<std::function<bool(MontageClip&,eff_args&)> > &q, MontageClip &mntg);

bool blur(MontageClip &mntg, eff_args &al);
bool starburst(MontageClip &mntg, eff_args &al);

}

#endif // EFFECTS_H
