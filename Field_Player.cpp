#include "Field_Player.h"
void CField_Player::delete_field_player() {
	scored_goal = NULL;
	delete_player();
}
void CField_Player::print_data_player() {
	cout << endl;
	cout.setf(ios::right);
	cout.width(20);
	cout << "I�'�"; cout.width(12);
	cout << "�i�"; cout.width(12);
	cout << "�����"; cout.width(15);
	cout << "�����i ����"; cout.width(12);
	cout << "C���"; cout.width(15);
	cout << "�i��" << '\n';
	cout.setf(ios::right);
	cout.width(20);
	cout << name + ' ' + surname; cout.width(12);
	cout << age; cout.width(12);
	cout << number; cout.width(15);
	cout << scored_goal; cout.width(12);
	cout << strength; cout.width(15);
	cout << price;
	cout << endl;
}
void CField_Player::redag_scored_goal() {
	cout << "����i�� ���i ���i:";
	cin >> scored_goal;
}