#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <windows.h>

using namespace std;
using namespace std::filesystem;

void saving(int timer,string path);



int main() {
	
	int choose;


	if (!exists("settings.txt"))
	{
		ofstream file("settings.txt");
		if (file.is_open()) {
			file << "C:/Program Files (x86)/Steam/userdata/3008130/remote/out/save" << endl;
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

			ifstream file("settings.txt");
			string path;
			getline(file, path);
			string timerS;
			getline(file, timerS);
			int timer = stoi(timerS);
			file.close();

			saving(timer,path);

		}


	}
	
	return 0;
}



void saving(int timer, string path) {

	int tempTime = 0;

	while (true) {
		if (tempTime == timer)
		{

		}
		return;
	}


}
