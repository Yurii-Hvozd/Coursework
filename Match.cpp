#include "Match.h"
string CMatch::get_team1_name() { return team1_name; }
string CMatch::get_team2_name() { return team2_name; }
string CMatch::get_stadium() { return stadium; }
int CMatch::get_team1_point() { return team1_point; }
int CMatch::get_team2_point() { return team2_point; }
int CMatch::get_team1_goal() { return team1_goal; }
int CMatch::get_team2_goal() { return team2_goal; }
int CMatch::get_team1_match() { return team1_match; }
int CMatch::get_team2_match() { return team2_match; }
void CMatch::play_match() {
	srand(time(NULL));
	long budget1, budget2, t1_koef, t2_koef;
	int t1_strength, t2_strength;
	cout << "Введіть iм'я першої команди: "; cin >> team1_name;
	cout << "Введіть iм'я другої команди: "; cin >> team2_name;
	cout << "Введіть стадiон: "; cin >> stadium;
	ifstream infile1;
	infile1.open(team1_name + "_matches.txt");
	if (!infile1) {
		ifstream infile11;
		infile11.open(team1_name + ".txt");
		if (!infile11) cout << "Не можу вдiкрити файл\n";
		if (infile11.is_open()) {
			infile11 >> team1_name;
			infile11 >> budget1;
			infile11 >> t1_strength;
			team1_match = 0;
			team1_point = 0;
		}
	}
	if (infile1.is_open()) {
		infile1 >> team1_name;
		infile1 >> t1_strength;
		infile1 >> team1_match;
		infile1 >> team1_point;
	}

	ifstream infile2;
	infile2.open(team2_name + "_matches.txt");
	if (!infile2) {
		ifstream infile22;
		infile22.open(team2_name + ".txt");
		if (!infile22) cout << "Не можу вiдкрити файл\n";
		if (infile22.is_open()) {
			infile22 >> team2_name;
			infile22 >> budget2;
			infile22 >> t2_strength;
			team2_match = 0;
			team2_point = 0;
		}
	}
	if (infile2.is_open()) {
		infile2 >> team2_name;
		infile2 >> t2_strength;
		infile2 >> team2_match;
		infile2 >> team2_point;
	}
	t1_koef = t1_strength * 1 + rand() % 10;
	t2_koef = t2_strength * 1 + rand() % 10;
	if (t1_koef > t2_koef) {
		team1_goal = 1 + rand() % 7;
		team2_goal = 0 + rand() % (team1_goal - 1);
		team1_point += 3;
	}
	if (t1_koef == t2_koef) {
		team1_goal = 0 + rand() % 7;
		team2_goal = team1_goal;
		team1_point += 1;
		team2_point += 1;
	}
	if (t1_koef < t2_koef) {
		team2_goal = 1 + rand() % 7;
		team1_goal = 0 + rand() % (team2_goal - 1);
		team2_point += 3;
	}
	team1_match++;
	team2_match++;
	cout << "Результати матчу:\n" << team1_name << " " << team1_goal << ":" << team2_goal << " " << team2_name << endl;
	fstream outfile1(team1_name + "_matches.txt", ios::out);
	if (!outfile1) {
		cout << "Не можу вiдкрити файл" << endl;
	}
	outfile1.setf(ios::left);
	outfile1.width(10);
	outfile1 << team1_name << '\n';
	outfile1.width(10);
	outfile1 << t1_strength << '\n';
	outfile1.width(10);
	outfile1 << team1_match << '\n';
	outfile1.width(10);
	outfile1 << team1_point << endl;
	fstream outfile2(team2_name + "_matches.txt", ios::out);
	if (!outfile2) {
		cout << "Не можу вiдкрити файл" << endl;
	}
	outfile2.setf(ios::left);
	outfile2.width(10);
	outfile2 << team2_name << '\n';
	outfile2.width(10);
	outfile2 << t2_strength << '\n';
	outfile2.width(10);
	outfile2 << team2_match << '\n';
	outfile2.width(10);
	outfile2 << team2_point << endl;
}