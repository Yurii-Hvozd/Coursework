#include "Goalkeeper.h"

void CGoalkeeper::delete_goalkeeper() {
	missed_goal = NULL;
	delete_player();
}
void CGoalkeeper::print_data_goalkeepers() {
	cout << endl;
	cout.setf(ios::right);
	cout.width(20);
	cout << "Iм'я"; cout.width(12);
	cout << "Вiк"; cout.width(12);
	cout << "Номер"; cout.width(15);
	cout << "Пропущенi голи"; cout.width(12);
	cout << "Cила"; cout.width(15);
	cout << "Цiна" << '\n';
	cout.setf(ios::right);
	cout << name + ' ' + surname; cout.width(12);
	cout << age; cout.width(12);
	cout << number; cout.width(15);
	cout << missed_goal; cout.width(12);
	cout << strength; cout.width(15);
	cout << price;
	cout << endl;

}
void CGoalkeeper::redag_missed_goal() {
	cout << "Введiть новi данi:";
	cin >> missed_goal;
}