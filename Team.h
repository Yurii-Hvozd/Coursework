#include "Field_Player.h"
#include "Goalkeeper.h"
#ifndef Team
#define Team

class CTeam : public CField_Player, public CGoalkeeper {
protected:
	string Team_name;
	long budget;
	int team_strength;
	vector<CGoalkeeper> goalkeepers;
	vector<CField_Player> players;
public:
	CTeam() : CField_Player(), CGoalkeeper(), Team_name("Noname"), budget(0) {}
	CTeam(string fTeam_name, long fbudget) : Team_name(fTeam_name), budget(fbudget) {}
	string get_team_name();
	long get_budget();
	void set_team_strength();
	int get_team_strength();
	void create_goalkeepers();
	void create_field_players();
	void enter_team_in_file();
	void create_team();
	void show_team_from_file(string fTeam_name);
	void redag_player();
	void delete_players();
	void sort_team();
	void transfer();
	void add_players();
};
#endif
