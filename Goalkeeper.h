#include "Player.h"
#ifndef Goalkeeper
#define Goalkeeper

class CGoalkeeper : public CPlayer {
protected:
	int missed_goal;
public:
	CGoalkeeper() : missed_goal(0), CPlayer() {}
	CGoalkeeper(string fname, string fsurname, int fage, int fnumber, int fstrength, long fprice, int fmissed_goal) : CPlayer(fname, fsurname, fage, fnumber, fstrength, fprice), missed_goal(fmissed_goal) {}
	int get_missed_goal() { return missed_goal; }
	void redag_missed_goal();
	void print_data_goalkeepers();
	void delete_goalkeeper();
};
#endif