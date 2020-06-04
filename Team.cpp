#include "Team.h"
string CTeam::get_team_name() { return Team_name; }
long CTeam::get_budget() { return budget; }
void CTeam::set_team_strength() {
	int goalkeepers_strength = 0, players_strength = 0;
	if (goalkeepers.size() > 0) {
		for (int i = 0; i < goalkeepers.size(); i++) {
			goalkeepers_strength += goalkeepers[i].get_strength();
		}
		goalkeepers_strength = goalkeepers_strength / goalkeepers.size();
	}
	if (players.size() > 0) {
		for (int i = 0; i < players.size(); i++) {
			players_strength += players[i].get_strength();
		}
		players_strength = players_strength / players.size();
	}
	team_strength = (players_strength + goalkeepers_strength) / 2;
}
int CTeam::get_team_strength() { return team_strength; }
void CTeam::create_goalkeepers() {
	string fname, fsurname;
	int fage, fnumber, fstrength, fmissed_goal, ch;
	long fprice;
	do {
		cout << "������ i�'� ����i����: "; cin >> fname;
		cout << "������ ��i����� ����i����: "; cin >> fsurname;
		cout << "������ �i� ����i����: "; cin >> fage;
		cout << "����i�� ����� ����i����: "; cin >> fnumber;
		cout << "����i�� �-��� ���������� ���i� ����i�����: "; cin >> fmissed_goal;
		cout << "����i�� ���� ����i����: "; cin >> fstrength;
		cout << "����i�� �i�� ����i���� "; cin >> fprice;
		goalkeepers.push_back(CGoalkeeper(fname, fsurname, fage, fnumber, fstrength, fprice, fmissed_goal));
		cout << "�������� �� ������ ����i����?\n��� - ������i�� 1;\n�i - ������i�� 0;\n"; cin >> ch;
	} while (ch == 1);
}
void CTeam::create_field_players() {
	string fname, fsurname;
	int fage, fnumber, fstrength, fscored_goal, ch;
	long fprice;
	do {
		cout << "����i�� i�'� ������: "; cin >> fname;
		cout << "����i�� ��i����� ������: "; cin >> fsurname;
		cout << "����i�� �i� ������: "; cin >> fage;
		cout << "����i�� ����� ������: "; cin >> fnumber;
		cout << "����i�� �-�� ������� ���i� �������: "; cin >> fscored_goal;
		cout << "����i�� ���� ������: "; cin >> fstrength;
		cout << "����i�� ���� ������: "; cin >> fprice;
		players.push_back(CField_Player(fname, fsurname, fage, fnumber, fstrength, fprice, fscored_goal));
		cout << "�������� �� ������ ������?\n��� - ������i�� 1;\n�i - ������i�� 0;\n"; cin >> ch;
	} while (ch == 1);
}
void CTeam::enter_team_in_file() {
	fstream outfile(Team_name + ".txt", ios::out);
	if (!outfile) {
		cout << "H� ���� �i������ ����" << endl;
	}
	outfile.setf(ios::left);
	outfile.width(10);
	outfile << Team_name << '\n';
	outfile.width(10);
	outfile << budget << '\n';
	outfile.width(10);
	outfile << team_strength << '\n';
	outfile.width(10);
	outfile << goalkeepers.size() << '\n';
	for (int i = 0; i < goalkeepers.size(); i++) {
		outfile << goalkeepers[i].get_name() << ' ';
		outfile << goalkeepers[i].get_surname() << ' ';
		outfile << goalkeepers[i].get_age() << ' ';
		outfile << goalkeepers[i].get_number() << ' ';
		outfile << goalkeepers[i].get_missed_goal() << ' ';
		outfile << goalkeepers[i].get_strength() << ' ';
		outfile << goalkeepers[i].get_price() << endl;
	}
	outfile.width(10);
	outfile << players.size() << '\n';
	for (int i = 0; i < players.size(); i++) {
		outfile << players[i].get_name() << ' ';
		outfile << players[i].get_surname() << ' ';
		outfile << players[i].get_age() << ' ';
		outfile << players[i].get_number() << ' ';
		outfile << players[i].get_scored_goal() << ' ';
		outfile << players[i].get_strength() << ' ';
		outfile << players[i].get_price() << endl;
	}
}
void CTeam::create_team() {
	cout << "����i�� i�'� �������: "; cin >> Team_name;
	cout << "����i�� ������ �������: "; cin >> budget;
	create_goalkeepers();
	create_field_players();
	set_team_strength();
	enter_team_in_file();
}
void CTeam::show_team_from_file(string fTeam_name) {
	string fname, fsurname;
	int fage, fnumber, fstrength, fscored_goal, fmissed_goal, goalkeepers_count, players_count;
	long fprice;
	ifstream infile;
	infile.open(fTeam_name + ".txt");
	if (!infile) cout << "�� ���� �i������ ����\n";
	if (infile.is_open()) {
		infile >> Team_name;
		infile >> budget;
		infile >> team_strength;
		infile >> goalkeepers_count;
		for (int i = 0; i < goalkeepers_count; i++) {
			infile >> fname;
			infile >> fsurname;
			infile >> fage;
			infile >> fnumber;
			infile >> fmissed_goal;
			infile >> fstrength;
			infile >> fprice;
			goalkeepers.push_back(CGoalkeeper(fname, fsurname, fage, fnumber, fstrength, fprice, fmissed_goal));
		}
		infile >> players_count;
		for (int i = 0; i < players_count; i++) {
			infile >> fname;
			infile >> fsurname;
			infile >> fage;
			infile >> fnumber;
			infile >> fscored_goal;
			infile >> fstrength;
			infile >> fprice;
			players.push_back(CField_Player(fname, fsurname, fage, fnumber, fstrength, fprice, fscored_goal));
		}
		for (int i = 0; i < 81; i++)
		{
			cout << "-";
			if (i == 27)
			{
				cout << "����������-����";
				i += 13;
			}
		}

		cout << endl << "I�'� �������: " << Team_name << '\n';
		cout << "������ �������: " << budget << '\n';
		cout << "���� �������: " << team_strength << '\n';
		cout << "����i����:\n";
		cout.setf(ios::right);
		cout.width(20);
		cout << "I�'�"; cout.width(12);
		cout << "�i�"; cout.width(12);
		cout << "�����"; cout.width(15);
		cout << "��������i ����"; cout.width(12);
		cout << "C���"; cout.width(12);
		cout << "�i��" << '\n';
		for (int i = 0; i < goalkeepers.size(); i++) {
			cout.setf(ios::right);
			cout.width(20);
			cout << goalkeepers[i].get_name() + ' ' + goalkeepers[i].get_surname(); cout.width(12);
			cout << goalkeepers[i].get_age(); cout.width(12);
			cout << goalkeepers[i].get_number(); cout.width(15);
			cout << goalkeepers[i].get_missed_goal(); cout.width(12);
			cout << goalkeepers[i].get_strength(); cout.width(12);
			cout << goalkeepers[i].get_price() << '\n';
		}

		cout << "������i �����i:\n";
		cout.setf(ios::right);
		cout.width(20);
		cout << "I�'�"; cout.width(12);
		cout << "�i�"; cout.width(12);
		cout << "�����"; cout.width(15);
		cout << "3����i ����"; cout.width(12);
		cout << "C���"; cout.width(12);
		cout << "�i��\n\n";
		for (int i = 0; i < players.size(); i++) {

			cout.setf(ios::right);
			cout.width(20);
			cout << players[i].get_name() + ' ' + players[i].get_surname(); cout.width(12);
			cout << players[i].get_age(); cout.width(12);
			cout << players[i].get_number(); cout.width(15);
			cout << players[i].get_scored_goal(); cout.width(12);
			cout << players[i].get_strength(); cout.width(12);
			cout << players[i].get_price() << '\n';
		}
	}
	for (int i = 0; i < 83; i++)
	{
		cout << "-";
	}
	infile.close();
}
void CTeam::redag_player() {
	cout << "����i�� ����� ������� �������������� �����i� ��� ����i��� ��i����:" << endl;
	string fTeam_name;
	cin >> fTeam_name;
	string fname, fsurname;
	int fage, fnumber, fstrength, fscored_goal, fmissed_goal, goalkeepers_count, players_count;
	long fprice;
	ifstream infile;
	infile.open(fTeam_name + ".txt");
	if (!infile) cout << "�� ���� �i������ ����\n";
	if (infile.is_open()) {
		infile >> Team_name;
		infile >> budget;
		infile >> team_strength;
		infile >> goalkeepers_count;
		for (int i = 0; i < goalkeepers_count; i++) {
			infile >> fname;
			infile >> fsurname;
			infile >> fage;
			infile >> fnumber;
			infile >> fmissed_goal;
			infile >> fstrength;
			infile >> fprice;
			goalkeepers.push_back(CGoalkeeper(fname, fsurname, fage, fnumber, fstrength, fprice, fmissed_goal));
		}
		infile >> players_count;
		for (int i = 0; i < players_count; i++) {
			infile >> fname;
			infile >> fsurname;
			infile >> fage;
			infile >> fnumber;
			infile >> fscored_goal;
			infile >> fstrength;
			infile >> fprice;
			players.push_back(CField_Player(fname, fsurname, fage, fnumber, fstrength, fprice, fscored_goal));
		}
	}
	cout << "������� � ����i�����?\n" << "��� - ������i�� 1\n" << "Hi - ������i�� 2\n";
	int choice;
	cin >> choice;
	if (choice == 2) {
		cout << "����i�� i�'� ������ ����� ����i��� ��i���� ��������������:" << endl;
		string name;
		cin >> name;
		cout << "�����i�� �������������� ��� ����i��� ��i����\n";
		for (int i = 0; i < players_count; i++) {
			if (players[i].get_name() == name) {
				players[i].print_data_player();
			}
		}
		cout << "\nI�'� - ������i�� 1\n" << "��i����� - ������i�� 2\n" << "�i� - ������i�� 3\n" << "����� - ������i�� - 4\n" << "�-�� ������� ���i� - ������i�� - 5\n" << "���� - ������i�� 6\n" << "�i�� - ������i�� 7\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			for (int i = 0; i < players_count; i++) {
				if (players[i].get_name() == name) {
					players[i].redag_name();
				}
			}
			break;
		}
		case 2: {
			for (int i = 0; i < players_count; i++) {
				if (players[i].get_name() == name) {
					players[i].redag_surname();
				}
			}
			break;
		}
		case 3: {
			for (int i = 0; i < players_count; i++) {
				if (players[i].get_name() == name) {
					players[i].redag_age();
				}
			}
			break;
		}
		case 4: {
			for (int i = 0; i < players_count; i++) {
				if (players[i].get_name() == name) {
					players[i].redag_number();
				}
			}
			break;
		}
		case 5: {
			for (int i = 0; i < players_count; i++) {
				if (players[i].get_name() == name) {
					players[i].redag_scored_goal();
				}
			}
			break;
		}
		case 6: {
			for (int i = 0; i < players_count; i++) {
				if (players[i].get_name() == name) {
					players[i].redag_strength();
				}
			}
			break;
		}
		case 7: {
			for (int i = 0; i < players_count; i++) {
				if (players[i].get_name() == name) {
					players[i].redag_price();
				}
			}
			break;
		}
		}
	}
	if (choice == 1) {
		cout << "����i�� i�'� ����i���� ����� ����i��� ��i���� ��������������:" << endl;
		string name;
		cin >> name;
		cout << "�����i�� �������������� ��� ����i��� ��i����\n";
		for (int i = 0; i < goalkeepers_count; i++) {
			if (goalkeepers[i].get_name() == name) {
				goalkeepers[i].print_data_goalkeepers();
			}
		}
		cout << "I�'� - ������i�� 1\n" << "��i����� - ������i�� 2\n" << "�i� - ������i�� 3\n" << "����� - ������i�� - 4\n" << "�-�� ���������� ���i� - ������i�� - 5\n" << "���� - ������i�� 6\n" << "�i�� - ������i�� 7\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			for (int i = 0; i < goalkeepers_count; i++) {
				if (goalkeepers[i].get_name() == name) {
					goalkeepers[i].redag_name();
				}
			}
			break;
		}
		case 2: {
			for (int i = 0; i < goalkeepers_count; i++) {
				if (goalkeepers[i].get_name() == name) {
					goalkeepers[i].redag_surname();
				}
			}
			break;
		}
		case 3: {
			for (int i = 0; i < goalkeepers_count; i++) {
				if (goalkeepers[i].get_name() == name) {
					goalkeepers[i].redag_age();
				}
			}
			break;
		}
		case 4: {
			for (int i = 0; i < goalkeepers_count; i++) {
				if (goalkeepers[i].get_name() == name) {
					goalkeepers[i].redag_number();
				}
			}
			break;
		}
		case 5: {
			for (int i = 0; i < goalkeepers_count; i++) {
				if (goalkeepers[i].get_name() == name) {
					goalkeepers[i].redag_missed_goal();
				}
			}
			break;
		}
		case 6: {
			for (int i = 0; i < goalkeepers_count; i++) {
				if (goalkeepers[i].get_name() == name) {
					goalkeepers[i].redag_strength();
				}
			}
			break;
		}
		case 7: {
			for (int i = 0; i < goalkeepers_count; i++) {
				if (goalkeepers[i].get_name() == name) {
					goalkeepers[i].redag_price();
				}
			}
			break;
		}
		}

	}
	{
		fstream outfile(fTeam_name + ".txt", ios::out);
		if (!outfile) {
			cout << "H� ���� �i������ ����" << endl;
		}
		outfile.setf(ios::left);
		outfile.width(10);
		outfile << Team_name << '\n';
		outfile.width(10);
		outfile << budget << '\n';
		outfile.width(10);
		outfile << team_strength << '\n';
		outfile.width(10);
		outfile << goalkeepers.size() << '\n';
		for (int i = 0; i < goalkeepers.size(); i++) {
			outfile << goalkeepers[i].get_name() << ' ';
			outfile << goalkeepers[i].get_surname() << ' ';
			outfile << goalkeepers[i].get_age() << ' ';
			outfile << goalkeepers[i].get_number() << ' ';
			outfile << goalkeepers[i].get_missed_goal() << ' ';
			outfile << goalkeepers[i].get_strength() << ' ';
			outfile << goalkeepers[i].get_price() << endl;
		}
		outfile.width(10);
		outfile << players.size() << '\n';
		for (int i = 0; i < players.size(); i++) {
			outfile << players[i].get_name() << ' ';
			outfile << players[i].get_surname() << ' ';
			outfile << players[i].get_age() << ' ';
			outfile << players[i].get_number() << ' ';
			outfile << players[i].get_scored_goal() << ' ';
			outfile << players[i].get_strength() << ' ';
			outfile << players[i].get_price() << endl;
		}
	}
}
void CTeam::delete_players() {
	cout << "����i�� ����� ������� �� ����i��� �������� ������:" << endl;
	string fTeam_name;
	cin >> fTeam_name;
	string fname, fsurname;
	int fage, fnumber, fstrength, fscored_goal, fmissed_goal, goalkeepers_count, players_count;
	long fprice;
	ifstream infile;
	infile.open(fTeam_name + ".txt");
	if (!infile) cout << "�� ���� �i������ ����\n";
	if (infile.is_open()) {
		infile >> Team_name;
		infile >> budget;
		infile >> team_strength;
		infile >> goalkeepers_count;
		for (int i = 0; i < goalkeepers_count; i++) {
			infile >> fname;
			infile >> fsurname;
			infile >> fage;
			infile >> fnumber;
			infile >> fmissed_goal;
			infile >> fstrength;
			infile >> fprice;
			goalkeepers.push_back(CGoalkeeper(fname, fsurname, fage, fnumber, fstrength, fprice, fmissed_goal));
		}
		infile >> players_count;
		for (int i = 0; i < players_count; i++) {
			infile >> fname;
			infile >> fsurname;
			infile >> fage;
			infile >> fnumber;
			infile >> fscored_goal;
			infile >> fstrength;
			infile >> fprice;
			players.push_back(CField_Player(fname, fsurname, fage, fnumber, fstrength, fprice, fscored_goal));
		}
	}
	cout << "������� � ����i�����?\n" << "��� - ������i�� 1\n" << "Hi - ������i�� 2\n";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << "����i�� i�� ����i����:" << endl;
		string player;
		cin >> player;
		for (int i = 0; i < goalkeepers_count; i++) {
			if (goalkeepers[i].get_name() == player)
				goalkeepers.erase(goalkeepers.begin() + i);
		}
	}
	case 2: {
		cout << "����i�� i�� ������:" << endl;
		string player;
		cin >> player;
		for (int i = 0; i < players_count; i++) {
			if (players[i].get_name() == player)
				players.erase(players.begin() + i);
		}

	}
	}
	fstream outfile(fTeam_name + ".txt", ios::out);
	if (!outfile) {
		cout << "H� ���� �i������ ����" << endl;
	}
	outfile.setf(ios::left);
	outfile.width(10);
	outfile << Team_name << '\n';
	outfile.width(10);
	outfile << budget << '\n';
	outfile.width(10);
	outfile << team_strength << '\n';
	outfile.width(10);
	outfile << goalkeepers.size() << '\n';
	for (int i = 0; i < goalkeepers.size(); i++) {
		outfile << goalkeepers[i].get_name() << ' ';
		outfile << goalkeepers[i].get_surname() << ' ';
		outfile << goalkeepers[i].get_age() << ' ';
		outfile << goalkeepers[i].get_number() << ' ';
		outfile << goalkeepers[i].get_missed_goal() << ' ';
		outfile << goalkeepers[i].get_strength() << ' ';
		outfile << goalkeepers[i].get_price() << endl;
	}
	outfile.width(10);
	outfile << players.size() << '\n';
	for (int i = 0; i < players.size(); i++) {
		outfile << players[i].get_name() << ' ';
		outfile << players[i].get_surname() << ' ';
		outfile << players[i].get_age() << ' ';
		outfile << players[i].get_number() << ' ';
		outfile << players[i].get_scored_goal() << ' ';
		outfile << players[i].get_strength() << ' ';
		outfile << players[i].get_price() << endl;
	}

}
void CTeam::sort_team() {
	cout << "����i�� ����� ������� ���i ��� ����i��� �����������:" << endl;
	string fTeam_name;
	cin >> fTeam_name;
	string fname, fsurname;
	int fage, fnumber, fstrength, fscored_goal, fmissed_goal, goalkeepers_count, players_count;
	long fprice;
	ifstream infile;
	infile.open(fTeam_name + ".txt");
	if (!infile) cout << "�� ���� �i������ ����\n";
	if (infile.is_open()) {
		infile >> Team_name;
		infile >> budget;
		infile >> team_strength;
		infile >> goalkeepers_count;
		for (int i = 0; i < goalkeepers_count; i++) {
			infile >> fname;
			infile >> fsurname;
			infile >> fage;
			infile >> fnumber;
			infile >> fmissed_goal;
			infile >> fstrength;
			infile >> fprice;
			goalkeepers.push_back(CGoalkeeper(fname, fsurname, fage, fnumber, fstrength, fprice, fmissed_goal));
		}
		infile >> players_count;
		for (int i = 0; i < players_count; i++) {
			infile >> fname;
			infile >> fsurname;
			infile >> fage;
			infile >> fnumber;
			infile >> fscored_goal;
			infile >> fstrength;
			infile >> fprice;
			players.push_back(CField_Player(fname, fsurname, fage, fnumber, fstrength, fprice, fscored_goal));
		}
	}

	cout << endl << "�����i�� ��� ����������:\n" << "�� i��� - 1\n" << "�� �i��� - 2\n" << "�� ������� - 3\n" << "�� �������� ������ - 4\n" << "�� ����� - 5\n" << "�� �i��� - 6\n";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1: {
		for (int j = 0; j < players_count; j++) {
			for (int i = 0; i < players_count - 1; i++) {
				if (players[i].get_name() > players[i + 1].get_name())
					swap(players[i], players[i + 1]);
			}
		}
		break;
	}
	case 2: {
		for (int j = 0; j < players_count; j++) {
			for (int i = 0; i < players_count - 1; i++) {
				if (players[i].get_age() > players[i + 1].get_age())
					swap(players[i], players[i + 1]);
			}
		}
		break;
	}
	case 3: {
		for (int j = 0; j < players_count; j++) {
			for (int i = 0; i < players_count - 1; i++) {
				if (players[i].get_number() > players[i + 1].get_number())
					swap(players[i], players[i + 1]);
			}
		}
		break;
	}
	case 4: {
		for (int j = 0; j < players_count; j++) {
			for (int i = 0; i < players_count - 1; i++) {
				if (players[i].get_scored_goal() > players[i + 1].get_scored_goal())
					swap(players[i], players[i + 1]);
			}
		}
		break;
	}
	case 5: {
		for (int j = 0; j < players_count; j++) {
			for (int i = 0; i < players_count - 1; i++) {
				if (players[i].get_strength() > players[i + 1].get_strength())
					swap(players[i], players[i + 1]);
			}
		}
		break;
	}
	case 6: {
		for (int j = 0; j < players_count; j++) {
			for (int i = 0; i < players_count - 1; i++) {
				if (players[i].get_price() > players[i + 1].get_price())
					swap(players[i], players[i + 1]);
			}
		}
		break;
	}
	}
	{
		fstream outfile(fTeam_name + ".txt", ios::out);
		if (!outfile) {
			cout << "H� ���� �i������ ����" << endl;
		}
		outfile.setf(ios::left);
		outfile.width(10);
		outfile << Team_name << '\n';
		outfile.width(10);
		outfile << budget << '\n';
		outfile.width(10);
		outfile << team_strength << '\n';
		outfile.width(10);
		outfile << goalkeepers.size() << '\n';
		for (int i = 0; i < goalkeepers.size(); i++) {
			outfile << goalkeepers[i].get_name() << ' ';
			outfile << goalkeepers[i].get_surname() << ' ';
			outfile << goalkeepers[i].get_age() << ' ';
			outfile << goalkeepers[i].get_number() << ' ';
			outfile << goalkeepers[i].get_missed_goal() << ' ';
			outfile << goalkeepers[i].get_strength() << ' ';
			outfile << goalkeepers[i].get_price() << endl;
		}
		outfile.width(10);
		outfile << players.size() << '\n';
		for (int i = 0; i < players.size(); i++) {
			outfile << players[i].get_name() << ' ';
			outfile << players[i].get_surname() << ' ';
			outfile << players[i].get_age() << ' ';
			outfile << players[i].get_number() << ' ';
			outfile << players[i].get_scored_goal() << ' ';
			outfile << players[i].get_strength() << ' ';
			outfile << players[i].get_price() << endl;
		}
	}
}
void CTeam::transfer() {
	string p_surname = "", p_name = "", t1_name, t2_name, fname1, fsurname1, fname2, fsurname2;
	int p_number = 0, p_age = 0, p_goals = 0, p_strength = 0, ch, g_count1, p_count1, g_count2, p_count2, fage1, fage2, fnumber1, fnumber2, fmissed_goal1, fmissed_goal2, fscored_goal1, fscored_goal2, fstrength1, fstrength2;
	long p_price = 0, fprice1, fprice2;
	string Team_name1;
	long budget1;
	int team_strength1;
	vector<CGoalkeeper> goalkeepers1;
	vector<CField_Player> players1;
	string Team_name2;
	long budget2;
	int team_strength2;
	vector<CGoalkeeper> goalkeepers2;
	vector<CField_Player> players2;
	cout << "����i�� ����� �������, ��� � ���������: "; cin >> t1_name;
	cout << "����i�� ����� �������, ��� � ��������: "; cin >> t2_name;
	cout << "����i�� ��i����� ������: "; cin >> p_surname;
	cout << "��� ������� ����i���?\n��� - �������� 1;\nͳ - �������� 0;\n"; cin >> ch;
	ifstream infile1;
	infile1.open(t1_name + ".txt");
	if (!infile1) cout << "�� ���� �i������ ����\n";
	if (infile1.is_open()) {
		infile1 >> Team_name1;
		infile1 >> budget1;
		infile1 >> team_strength1;
		infile1 >> g_count1;
		for (int i = 0; i < g_count1; i++) {
			infile1 >> fname1;
			infile1 >> fsurname1;
			infile1 >> fage1;
			infile1 >> fnumber1;
			infile1 >> fmissed_goal1;
			infile1 >> fstrength1;
			infile1 >> fprice1;
			goalkeepers1.push_back(CGoalkeeper(fname1, fsurname1, fage1, fnumber1, fstrength1, fprice1, fmissed_goal1));
		}
		infile1 >> p_count1;
		for (int i = 0; i < p_count1; i++) {
			infile1 >> fname1;
			infile1 >> fsurname1;
			infile1 >> fage1;
			infile1 >> fnumber1;
			infile1 >> fscored_goal1;
			infile1 >> fstrength1;
			infile1 >> fprice1;
			players1.push_back(CField_Player(fname1, fsurname1, fage1, fnumber1, fstrength1, fprice1, fscored_goal1));
		}
		if (ch == 1) {
			for (int i = 0; i < goalkeepers.size(); i++) {
				if (p_surname == goalkeepers1[i].get_surname()) {
					p_name = goalkeepers1[i].get_name();
					p_age = goalkeepers1[i].get_age();
					p_number = goalkeepers1[i].get_number();
					p_strength = goalkeepers1[i].get_strength();
					p_goals = goalkeepers1[i].get_missed_goal();
					p_price = goalkeepers1[i].get_price();
					goalkeepers1.erase(goalkeepers1.begin() + i);
				}
			}
		}
		if (ch == 0) {
			for (int i = 0; i < players1.size(); i++) {
				if (p_surname == players1[i].get_surname()) {
					p_name = players1[i].get_name();
					p_age = players1[i].get_age();
					p_number = players1[i].get_number();
					p_strength = players1[i].get_strength();
					p_goals = players1[i].get_scored_goal();
					p_price = players1[i].get_price();
					players1.erase(players1.begin() + i);
				}
			}
		}
	}infile1.close();
	fstream outfile1(t1_name + ".txt", ios::out);
	if (!outfile1) {
		cout << "�� ���� �i������ ����" << endl;
	}
	outfile1.setf(ios::left);
	outfile1.width(10);
	outfile1 << Team_name1 << '\n';
	budget1 += p_price;
	outfile1.width(10);
	outfile1 << budget1 << '\n';
	outfile1.width(10);
	outfile1 << team_strength1 << '\n';
	outfile1.width(10);
	outfile1 << goalkeepers1.size() << '\n';
	for (int i = 0; i < goalkeepers1.size(); i++) {
		outfile1 << goalkeepers1[i].get_name() << ' ';
		outfile1 << goalkeepers1[i].get_surname() << ' ';
		outfile1 << goalkeepers1[i].get_age() << ' ';
		outfile1 << goalkeepers1[i].get_number() << ' ';
		outfile1 << goalkeepers1[i].get_missed_goal() << ' ';
		outfile1 << goalkeepers1[i].get_strength() << ' ';
		outfile1 << goalkeepers1[i].get_price() << endl;
	}
	outfile1.width(10);
	outfile1 << players1.size() << '\n';
	for (int i = 0; i < players1.size(); i++) {
		outfile1 << players1[i].get_name() << ' ';
		outfile1 << players1[i].get_surname() << ' ';
		outfile1 << players1[i].get_age() << ' ';
		outfile1 << players1[i].get_number() << ' ';
		outfile1 << players1[i].get_scored_goal() << ' ';
		outfile1 << players1[i].get_strength() << ' ';
		outfile1 << players1[i].get_price() << endl;
	}
	outfile1.close();

	ifstream infile2;
	infile2.open(t2_name + ".txt");
	if (!infile2) cout << "�� ���� �i������ ����\n";
	if (infile2.is_open()) {
		infile2 >> Team_name2;
		infile2 >> budget2;
		infile2 >> team_strength2;
		infile2 >> g_count2;
		for (int i = 0; i < g_count2; i++) {
			infile2 >> fname2;
			infile2 >> fsurname2;
			infile2 >> fage2;
			infile2 >> fnumber2;
			infile2 >> fmissed_goal2;
			infile2 >> fstrength2;
			infile2 >> fprice2;
			goalkeepers2.push_back(CGoalkeeper(fname2, fsurname2, fage2, fnumber2, fstrength2, fprice2, fmissed_goal2));
		}
		infile2 >> p_count2;
		for (int i = 0; i < p_count2; i++) {
			infile2 >> fname2;
			infile2 >> fsurname2;
			infile2 >> fage2;
			infile2 >> fnumber2;
			infile2 >> fscored_goal2;
			infile2 >> fstrength2;
			infile2 >> fprice2;
			players2.push_back(CField_Player(fname2, fsurname2, fage2, fnumber2, fstrength2, fprice2, fscored_goal2));
		}
		if (ch == 1) {
			goalkeepers2.push_back(CGoalkeeper(p_name, p_surname, p_age, p_number, p_strength, p_price, p_goals));
		}
		if (ch == 0) {
			players2.push_back(CField_Player(p_name, p_surname, p_age, p_number, p_strength, p_price, p_goals));
		}
	}infile2.close();
	fstream outfile2(t2_name + ".txt", ios::out);
	if (!outfile2) {
		cout << "�� ���� �i������ ����" << endl;
	}
	outfile2.setf(ios::left);
	outfile2.width(10);
	outfile2 << Team_name2 << '\n';
	budget2 -= p_price;
	outfile2.width(10);
	outfile2 << budget2 << '\n';
	outfile2.width(10);
	outfile2 << team_strength2 << '\n';
	outfile2.width(10);
	outfile2 << goalkeepers2.size() << '\n';
	for (int i = 0; i < goalkeepers2.size(); i++) {
		outfile2 << goalkeepers2[i].get_name() << ' ';
		outfile2 << goalkeepers2[i].get_surname() << ' ';
		outfile2 << goalkeepers2[i].get_age() << ' ';
		outfile2 << goalkeepers2[i].get_number() << ' ';
		outfile2 << goalkeepers2[i].get_missed_goal() << ' ';
		outfile2 << goalkeepers2[i].get_strength() << ' ';
		outfile2 << goalkeepers2[i].get_price() << endl;
	}
	outfile2.width(10);
	outfile2 << players2.size() << '\n';
	for (int i = 0; i < players2.size(); i++) {
		outfile2 << players2[i].get_name() << ' ';
		outfile2 << players2[i].get_surname() << ' ';
		outfile2 << players2[i].get_age() << ' ';
		outfile2 << players2[i].get_number() << ' ';
		outfile2 << players2[i].get_scored_goal() << ' ';
		outfile2 << players2[i].get_strength() << ' ';
		outfile2 << players2[i].get_price() << endl;
	}
	outfile2.close();
	cout << "�������� ���������!\n";
}
void CTeam::add_players() {
	cout << "����i�� ����� ������� ���� ������ ������:" << endl;
	string fTeam_name;
	cin >> fTeam_name;
	string fname, fsurname;
	int fage, fnumber, fstrength, fscored_goal, fmissed_goal, goalkeepers_count, players_count;
	long fprice;
	ifstream infile;
	infile.open(fTeam_name + ".txt");
	if (!infile) cout << "�� ���� �i������ ����\n";
	if (infile.is_open()) {
		infile >> Team_name;
		infile >> budget;
		infile >> team_strength;
		infile >> goalkeepers_count;
		for (int i = 0; i < goalkeepers_count; i++) {
			infile >> fname;
			infile >> fsurname;
			infile >> fage;
			infile >> fnumber;
			infile >> fmissed_goal;
			infile >> fstrength;
			infile >> fprice;
			goalkeepers.push_back(CGoalkeeper(fname, fsurname, fage, fnumber, fstrength, fprice, fmissed_goal));
		}
		infile >> players_count;
		for (int i = 0; i < players_count; i++) {
			infile >> fname;
			infile >> fsurname;
			infile >> fage;
			infile >> fnumber;
			infile >> fscored_goal;
			infile >> fstrength;
			infile >> fprice;
			players.push_back(CField_Player(fname, fsurname, fage, fnumber, fstrength, fprice, fscored_goal));
		}
	}
	cout << "������ ����i���� - ������i�� 1" << endl;
	cout << "������ ��������� ������ - ������i�� 2" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1: {
		create_goalkeepers();
	}
	case 2: {
		create_field_players();
	}
	}
	fstream outfile(fTeam_name + ".txt", ios::out);
	if (!outfile) {
		cout << "H� ���� �i������ ����" << endl;
	}
	outfile.setf(ios::left);
	outfile.width(10);
	outfile << Team_name << '\n';
	outfile.width(10);
	outfile << budget << '\n';
	outfile.width(10);
	outfile << team_strength << '\n';
	outfile.width(10);
	outfile << goalkeepers.size() << '\n';
	for (int i = 0; i < goalkeepers.size(); i++) {
		outfile << goalkeepers[i].get_name() << ' ';
		outfile << goalkeepers[i].get_surname() << ' ';
		outfile << goalkeepers[i].get_age() << ' ';
		outfile << goalkeepers[i].get_number() << ' ';
		outfile << goalkeepers[i].get_missed_goal() << ' ';
		outfile << goalkeepers[i].get_strength() << ' ';
		outfile << goalkeepers[i].get_price() << endl;
	}
	outfile.width(10);
	outfile << players.size() << '\n';
	for (int i = 0; i < players.size(); i++) {
		outfile << players[i].get_name() << ' ';
		outfile << players[i].get_surname() << ' ';
		outfile << players[i].get_age() << ' ';
		outfile << players[i].get_number() << ' ';
		outfile << players[i].get_scored_goal() << ' ';
		outfile << players[i].get_strength() << ' ';
		outfile << players[i].get_price() << endl;
	}
}