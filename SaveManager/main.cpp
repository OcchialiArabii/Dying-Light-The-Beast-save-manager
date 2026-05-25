#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <windows.h>
#include <ctime>


using namespace std;
using namespace std::filesystem;

void saving(int timer,string path);



int main() {
	
	int choose;


	if (!exists("settings.txt"))
	{
		ofstream file("settings.txt");
		if (file.is_open()) {
			cout << "Enter path to save files [Basic: C:/Program Files (x86)/Steam/userdata/[User_ID]/3008130/remote/out/]" << endl;
			string path;
			cin >> path;
			file << path << endl;
			file << 60 << endl;
		}
		file.close();
	}

	while (true) {
		cout << "Dying Light:The Beast Save Manager" << endl;
		cout << "Choose what to do: " << endl;
		cout << "[1] - start saving" << endl;
		cout << "[2] - Change save path" << endl;
		cout << "[3] - Change interval betweeen saves" << endl;
		cout << "[4] - Exit" << endl;
		cout << ">> ";
		cin >> choose;

		switch (choose) {
		case 1:
		{
			ifstream file("settings.txt");
			string path;
			getline(file, path);
			string timerS;
			getline(file, timerS);
			int timer = stoi(timerS);
			file.close();
			saving(timer, path);
			break;
		}
		case 2:
			break;

		case 3:
			break;

		case 4:
			return 0;
			break;
		}
	}
	
	return 0;
}



void saving(int timer, string path) {

	int tempTime = 0;

	while (true) {
		if (tempTime == timer)
		{
			copy(path+"/save", path + "/backups/save");
			string timeS = to_string(time(0));
			rename(path + "/backups/save", path + "/backups/" + timeS);
			return;
		}
		tempTime++;
		cout << tempTime << endl;
		Sleep(1000);
	}


}
