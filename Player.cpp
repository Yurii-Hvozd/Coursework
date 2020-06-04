#include "Player.h"
string CPlayer::get_name() { return name; }
string CPlayer::get_surname() { return surname; }
int CPlayer::get_number() { return number; }
int CPlayer::get_age() { return age; }
int CPlayer::get_strength() { return strength; }
long CPlayer::get_price() { return price; }
void CPlayer::redag_name() {
	cout << "¬ведiть нов≥ данi:";
	cin >> name;
}
void CPlayer::redag_surname() {
	cout << "¬ведiть новi данi:";
	cin >> surname;
}
void CPlayer::redag_age() {
	cout << "¬ведiть новi данi:";
	cin >> age;
}
void CPlayer::redag_number() {
	cout << "¬ведiть новi данi:";
	cin >> number;
}
void CPlayer::redag_strength() {
	cout << "¬ведiть новi данi:";
	cin >> strength;
}
void CPlayer::redag_price() {
	cout << "¬ведiть новi данi:";
	cin >> price;
}
void CPlayer::delete_player() {
	name = ' ';
	surname = ' ';
	age = NULL;
	number = NULL;
	strength = NULL;
	price = NULL;
}
