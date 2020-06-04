#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <time.h>
#ifndef Player
#define Player
using namespace std;

class CPlayer {
protected:
	string name, surname;
	int age, number, strength;
	long price;
public:
	CPlayer() : name("NoName"), surname("NoSurname"), number(0), age(0), strength(0), price(0) {}
	CPlayer(string fname, string fsurname, int fage, int fnumber, int fstrength, long fprice) : name(fname), surname(fsurname), number(fnumber), age(fage), strength(fstrength), price(fprice) {}
	string get_name();
	string get_surname();
	int get_number();
	int get_age();
	int get_strength();
	long get_price();
	void redag_name();
	void redag_surname();
	void redag_age();
	void redag_number();
	void redag_strength();
	void redag_price();
	void delete_player();
};
#endif