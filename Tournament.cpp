#include "Tournament.h"
void CTournament::Hold_tournament() {
	string temp;
	string tteam_name;
	int tteam_strength, tteam_matches, tteam_points;
	vector<string> Teams;
	vector<int> Teams_matches;
	vector<int> Teams_points;
	cout << "Введiть назву чемпiонату: "; cin >> tournament_name;
	cout << "Кiлькiсть команд що беруть участь у чемпiонатi: "; cin >> team_count;
	cout << "Введiть назви команд що беруть участь в чемпіонатi:\n";
	for (int i = 0; i < team_count; i++) {
		cin >> tteam_name;
		Teams.push_back(tteam_name);
	}
	for (int i = 0; i < team_count; i++) {
		ifstream infile;
		infile.open(Teams[i] + "_matches.txt");
		if (!infile) cout << "Не можу вiдкрити файл\n";
		if (infile.is_open()) {
			infile >> temp;
			infile >> tteam_strength;
			infile >> tteam_matches;
			infile >> tteam_points;
		}
		Teams_matches.push_back(tteam_matches);
		Teams_points.push_back(tteam_points);
	}
	for (int i = team_count; i > 0; i--) {
		for (int j = 0, k = 1; k < i; j++, k++) {
			if (Teams_points[j] < Teams_points[k]) {
				int swap1 = Teams_points[j];
				Teams_points[j] = Teams_points[k];
				Teams_points[k] = swap1;
				int swap2 = Teams_matches[j];
				Teams_matches[j] = Teams_matches[k];
				Teams_matches[k] = swap2;
				string swap3 = Teams[j];
				Teams[j] = Teams[k];
				Teams[k] = swap3;
			}
		}
	}
	for (int i = 0; i < 46; i++)
	{
		cout << "-";
	}
	cout << endl << setw(3) << "#" << setw(25) << "Iм'я команди" << setw(9) << "Очки" << setw(9) << "Матчi" << endl;
	for (int i = 0; i < team_count; i++) {
		cout.width(3);
		cout << i + 1;
		cout.width(25);
		cout << Teams[i];
		cout.width(9);
		cout << Teams_points[i];
		cout.width(9);
		cout << Teams_matches[i];
		cout << endl;
	}
	for (int i = 0; i < 46; i++)
	{
		cout << "-";
	}
	fstream outfile(tournament_name + "_tournament.txt", ios::out);
	if (!outfile) {
		cout << "Не можу вiдкрити файл" << endl;
	}
	outfile.setf(ios::left);
	outfile.width(9);
	outfile << tournament_name << endl;
	outfile.width(9);
	outfile << team_count << endl;
	for (int i = 0; i < team_count; i++) {
		outfile.width(9);
		outfile << Teams[i] << ' ';
		outfile.width(9);
		outfile << Teams_points[i] << ' ';
		outfile.width(9);
		outfile << Teams_matches[i] << endl;
	}
}