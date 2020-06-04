#include "Team.h"
#include "Match.h"
#include "Tournament.h"

int main() {
	setlocale(LC_ALL, "Ukrainian");
	cout.setf(ios::right);
	while (true) {
	label:
		for (int i = 0; i < 19; i++) {
			cout << "-";
		}
		cout << "�������-����";
		for (int i = 0; i < 19; i++) {
			cout << "-";
		}
		cout << endl;
		cout.width(50);
		cout << "������i� � ��������� - ������i�� 1" << endl; cout.width(50);
		cout << "�i����� ���� - ������i�� 2" << endl; cout.width(50);
		cout << "������� �������� - ������i�� 3" << endl; cout.width(50);
		cout << "������ ����i���� - ������i�� 4" << endl; cout.width(50);
		cout << "����� - ������i�� 5" << endl;
		for (int i = 0; i < 50; i++) {
			cout << "-";
		}
		cout << endl;
		cout.width(50);
		int choice;
		cin >> choice;
		if (choice == 1) {
			cout << "�������� ������� - ������i�� 1" << endl; cout.width(50);
			cout << "������i� � ������� �������� - ������i�� 2" << endl; cout.width(50);
			cin >> choice;
			if (choice == 1) {
				cout << endl;
				CTeam obj;
				obj.create_team();
				cout << endl;
			}

			if (choice == 2) {
				cout << "�������� ������� - ������i�� 1" << endl; cout.width(50);
				cout << "����������� ���i - ������i�� 2" << endl; cout.width(50);
				cout << "������ ������ - ������i�� 3" << endl; cout.width(50);
				cout << "��i���� �������������� �����i� - ������i�� 4" << endl; cout.width(50);
				cout << "�������� ������ - ������i�� 5" << endl;
				cin >> choice;
				if (choice == 1) {
					string fTeam_name;
					cout << endl;
					cout << "����i�� i�'� �������, ��� �� ������ ��������: ";  cin >> fTeam_name;
					CTeam obj;
					obj.show_team_from_file(fTeam_name);
					cout << endl;
				}

				if (choice == 2) {
					cout << endl;
					CTeam obj;
					obj.sort_team();
					cout << endl;
				}
				if (choice == 3) {
					cout << endl;
					CTeam obj;
					obj.add_players();
					cout << endl;
				}

				if (choice == 4) {
					cout << endl;
					CTeam obj;
					obj.redag_player();
					cout << endl;
				}
				if (choice == 5) {
					cout << endl;
					CTeam obj;
					obj.delete_players();
					cout << endl;
				}
			}
			goto label;
		}
		if (choice == 2) {
			cout << endl;
			CMatch obj;
			obj.play_match();
			cout << endl;
		}

		if (choice == 3) {
			cout << endl;
			CTeam obj;
			obj.transfer();
			cout << endl;
		}

		if (choice == 4) {
			cout << endl;
			CTournament obj;
			obj.Hold_tournament();
			cout << endl;
		}
		if (choice == 5) {
			break;
		}
	}
	return 0;
}





























































