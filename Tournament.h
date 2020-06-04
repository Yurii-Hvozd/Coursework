#include "Match.h"
#ifndef Tournament
#define Tournament

class CTournament : public CMatch {
protected:
	string tournament_name;
	int team_count;
public:
	CTournament() : CMatch(), tournament_name("NoName"), team_count(0) {}
	void Hold_tournament();
};
#endif
