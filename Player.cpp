#include "Player.h"
string CPlayer::get_name() { return name; }
string CPlayer::get_surname() { return surname; }
int CPlayer::get_number() { return number; }
int CPlayer::get_age() { return age; }
int CPlayer::get_strength() { return strength; }
long CPlayer::get_price() { return price; }
void CPlayer::redag_name() {
	cout << "����i�� ��� ���i:";
	cin >> name;
}
void CPlayer::redag_surname() {
	cout << "����i�� ���i ���i:";
	cin >> surname;
}
void CPlayer::redag_age() {
	cout << "����i�� ���i ���i:";
	cin >> age;
}
void CPlayer::redag_number() {
	cout << "����i�� ���i ���i:";
	cin >> number;
}
void CPlayer::redag_strength() {
	cout << "����i�� ���i ���i:";
	cin >> strength;
}
void CPlayer::redag_price() {
	cout << "����i�� ���i ���i:";
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
