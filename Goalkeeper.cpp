#include "Goalkeeper.h"

void CGoalkeeper::delete_goalkeeper() {
	missed_goal = NULL;
	delete_player();
}
void CGoalkeeper::print_data_goalkeepers() {
	cout << endl;
	cout.setf(ios::right);
	cout.width(20);
	cout << "I�'�"; cout.width(12);
	cout << "�i�"; cout.width(12);
	cout << "�����"; cout.width(15);
	cout << "��������i ����"; cout.width(12);
	cout << "C���"; cout.width(15);
	cout << "�i��" << '\n';
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
	cout << "����i�� ���i ���i:";
	cin >> missed_goal;
}