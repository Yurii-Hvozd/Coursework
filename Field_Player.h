#include "Player.h"
#ifndef Field_Player
#define Field_Player

class CField_Player : public CPlayer {
protected:
	int scored_goal;
public:
	CField_Player() : scored_goal(0), CPlayer() {}
	CField_Player(string fname, string fsurname, int fage, int fnumber, int fstrength, long fprice, int fscored_goal) : CPlayer(fname, fsurname, fage, fnumber, fstrength, fprice), scored_goal(fscored_goal) {}
	int get_scored_goal() { return scored_goal; }
	void redag_scored_goal();
	void print_data_player();
	void delete_field_player();
};
#endif