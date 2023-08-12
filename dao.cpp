#include "Base.h"
#include "dao.h"
#include "service.h"
#include "utils.h"
#include "view.h"


//ÅÅÐÐ°ñ´æ´¢
bool rankCompare(int n) {
	int i = 0, c, k = 0, flag = 0;
	int a[100];
	string b;
	ifstream file("ranking list.txt");
	if (file) {
		string line;
		while (getline(file, line)) {
			istringstream iss(line);
			iss >> c >> b >> a[i];
			i++;
		}
		file.close();
	}
	if (i <= 10)
		flag = 1;
	else {
		if (n > a[9]) {
			flag = 1;
		}
	}
	return flag;
}

void rankWriting(int n, string name) {
	if (rankCompare(n)) {
		int i = 0, k = 0;
		int a[100];
		int c[100];
		string b[100];
		ifstream file("ranking list.txt");
		if (file) {
			string line;
			while (getline(file, line)) {

				istringstream iss(line);
				iss >> c[i] >> b[i] >> a[i];
				i++;
			}
			file.close();
		}
		a[i] = n;
		c[i] = i + 1;
		b[i] = name;
		for (int j = 0; j <= i; j++) {
			for (int r = j; r <= i; r++) {
				if (a[r] > a[j]) {
					int d;
					d = a[r];
					a[r] = a[j];
					a[j] = d;
					string t;
					t = b[r];
					b[r] = b[j];
					b[j] = t;

				}
			}

		}
		i++;

		ofstream ofs;
		ofs.open("ranking list.txt", ios::out);
		ofs << left;
		for (int q = 0; q < i; q++) {
			ofs <<setw(8) << c[q] << setw(10) << b[q] << setw(9.5) << a[q] << endl;
		}



		ofs.close();

	}


}

void gameData(bool n) {
	if (n==1) {
		ofstream outfile;
		outfile.open("account.txt", ios::out);
		outfile << nuclear_bomb.getNum() <<endl;
		outfile <<resurrection_scroll.getNum() <<endl;
		outfile << decelerator.getNum() <<endl;
		outfile << myaircraft.getAttackLevel()<<endl;
		outfile <<  myaircraft.getHPLevel() <<endl;
		outfile <<  myaircraft.getDefenseLevel() << endl;
		outfile <<   myaircraft.getAttackLevel() << endl;
		outfile <<myaircraft.getHPLevel() << endl;
		outfile << coin << endl;
		outfile <<  level_succeeded << endl;
		outfile.close();
	}
	else {
		ifstream infile;
		infile.open("account.txt");
		int temp;
		infile >> temp;
		nuclear_bomb.setNum(temp);
		infile >> temp;
		resurrection_scroll.setNum(temp);
		infile >> temp;
		decelerator.setNum(temp);
		infile >> temp;
		myaircraft.setAttackLevel(temp);
		infile >> temp;
		myaircraft.setHPLevel(temp);
		infile >> temp;
		myaircraft.setDefenseLevel(temp);
		infile >> temp;
		myaircraft.setAttackLevel(temp);
		infile >> temp;
		myaircraft.setHPLevel(temp);
		infile >> coin;
		infile >> level_succeeded ;
		infile.close();
	}
}

