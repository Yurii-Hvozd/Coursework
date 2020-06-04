#include "Team.h"
#ifndef Match
#define Match

class CMatch : public CTeam {
protected:
	string team1_name, team2_name, stadium;
	int team1_point, team2_point, team1_goal, team2_goal, team1_match, team2_match;
public:
	CMatch() : CTeam(), team1_name("NoName"), team2_name("NoName"), stadium("NoName"), team1_point(0), team2_point(0), team1_goal(0), team2_goal(0), team1_match(0), team2_match(0) {}
	CMatch(string t1n, string t2n, string stad) : team1_name(t1n), team2_name(t2n), stadium(stad) {}
	string get_team1_name();
	string get_team2_name();
	string get_stadium();
	int get_team1_point();
	int get_team2_point();
	int get_team1_goal();
	int get_team2_goal();
	int get_team1_match();
	int get_team2_match();
	void play_match();
};
#endif
