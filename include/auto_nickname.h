#ifndef GUARD_AUTO_NICKNAME_H
#define GUARD_AUTO_NICKNAME_H

// Assigns a random nickname to a Pokemon, used by the "Auto Nickname" option.
// Picks a name from gendered name pools (ported from Radical Red / CFRU).
void ApplyAutoNickname(struct Pokemon *mon);

#endif // GUARD_AUTO_NICKNAME_H
