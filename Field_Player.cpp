#include "Field_Player.h"
void CField_Player::delete_field_player() {
	scored_goal = NULL;
	delete_player();
}
void CField_Player::print_data_player() {
	cout << endl;
	cout.setf(ios::right);
	cout.width(20);
	cout << "Iм'я"; cout.width(12);
	cout << "Вiк"; cout.width(12);
	cout << "Номер"; cout.width(15);
	cout << "Забитi голи"; cout.width(12);
	cout << "Cила"; cout.width(15);
	cout << "Цiна" << '\n';
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
	cout << "Введiть новi данi:";
	cin >> scored_goal;
}