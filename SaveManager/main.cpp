#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <windows.h>
#include <ctime>


using namespace std;
namespace fs =  std::filesystem;

void saving(int timer,string path);



int main() {
	
	int choose;


	if (!fs::exists("settings.txt"))
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
		system("cls");
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
	bool isOver = false;

	if (!fs::exists(path + "/backups")) {
		fs::create_directory(path + "/backups");
	}


	while (true) {
		system("cls");
		if (tempTime == timer)
		{

			if (!isOver) {
				int fileCount = 0;
				for (auto const& dir_entry : fs::directory_iterator{ path + "/backups/" }) {
					fileCount++;
					cout << fileCount << endl;
					if (fileCount >= 5)
					{
						cout << "isOver" << endl;
						isOver = true;
					}
				}

			}

			if(isOver){		
				int min = INT_MAX;
				for (auto const& dir_entry : fs::directory_iterator{ path + "/backups/" }) {
					if (min > stoi(filesystem::path(dir_entry).filename())) {
						min = stoi(filesystem::path(dir_entry).filename());
					}
				}
				string minS = to_string(min);
				bool isRemoved = fs::remove_all(path + "/backups/" + minS);
				cout << "minS: " << minS << endl;
				cout << "isRemoved: " << isRemoved << endl;
			}
			
			

			fs::copy(path+"/save", path + "/backups/save");
			string timeS = to_string(time(0));
			fs::rename(path + "/backups/save", path + "/backups/" + timeS);
			tempTime = 0;
			cout << "File saved" << endl;
		}
		else {
		cout << "Saving in: " << timer - tempTime<<endl;
		cout << "Hold space bar to exit" << endl;
		}
		tempTime++;

		if (GetAsyncKeyState(0x20) & 0x8000) {
			return;
		}


		Sleep(1000);
	}


}
