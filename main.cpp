// Project Creator v0.1
// BY KC_C4

// Free2Use
// Free2Mod

// Use GCC And C++ Version 11 to 20
// DO NOT ADD SPACES

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>

using namespace std;

int F_Menu();
string F_GetCurDir();
int F_CreateProj(string proName,string proDir);

int main()
{
	return F_Menu();
}

int F_Menu()
{
	int returnValue{-1};
	cout << "[Project Creator v0.1]" << endl;

	againMenu:;
	u_int16_t select{0};
	backToSwitchAfterSelect:;
	switch (select)
	{
		case 0:
		{
			cout << "1.Create New Project" << endl;
			cout << "2.Create New {...} File" << endl;
			cout << "3.Compile Project" << endl;
			cout << ": "; cin >> select;
			goto backToSwitchAfterSelect;
			break;
		}
		case 1:
		{
			char curDir;bool setuped{false};
			string proName{""},proDir{""};
			cout << "[Create New Project]" << endl;
			cout << "TYPE NAME: "; cin >> proName;
			if(proName.length() >= 1)
			{
				backToSelectCurDir:;
				cout << "Use Current Dir (Y/N)?: "; cin >> curDir;
				if (curDir == 'Y' || 'y' || '1' || ' ')
				{
					cout << "Using Current Dir... " << (proDir = F_GetCurDir()) << "\n"; setuped = true;
				}
				else if (curDir == 'N' || 'n' || '0')
				{
					cout << "TYPE DIR: "; cin >> proDir; setuped = true;
				}
				else
				{
					goto backToSelectCurDir;
				}
			}
			else
			{
				cout << "ERROR: NO PROJECT NAME or PROJECT NAME LENGTH TO SHORT!!!" << endl;
				goto againMenu;
			}

			if (setuped)
			{
				cout << "[Creating]\n";
				cout << "[PROJECT NAME: " << proName << " ]\n";
				cout << "[DIR : " << proDir << " ]\n";

				returnValue = F_CreateProj(proName,proDir);
				//returnValue = 0;
			}
			else
			{
				goto againMenu;
			}
			break;
		}
		case 2:
		{
			cout << "not implement yet :/" << endl; returnValue = 0;
			break;
		}
		case 3:
		{
			system("cd NewProject/.build");
			system("cmake NewProject -B NewProject/.build");
			system("make -C NewProject/.build");
			returnValue = 1;
			break;
		}
	}
	if(returnValue == -1)
		cout <<"APP_TERMINATED: SOMETHING GO WRONG :C\n";
	if(returnValue == 1)
		cout <<"APP_TERMINATED: APP WORK :D\n";
	if(returnValue == 0)
		cout <<"APP_TERMINATED: DEBUG ._.\n";
	return returnValue;
}

string F_GetCurDir()
{
	string curDir{""};
	ifstream file1 ("/tmp/ProCreate");
	if(file1) {system("rm -f /tmp/ProCreate");file1.close();}

	system("pwd >> /tmp/ProCreate");

	ifstream file2 ("/tmp/ProCreate");
	getline(file2,curDir);
	return curDir;
}

int F_CreateProj(string proName,string proDir)
{
	system("mkdir NewProject");
	proDir += "/NewProject/";
	string cppFile{proDir+"main.cpp"};
	string cmakeFile{proDir+"CMakeLists.txt"};

	ofstream file1 (cppFile);

	file1 << "int main()\n{\n     return 0; \n}";
	file1.close();

	ofstream file2 (cmakeFile);

	file2 << "cmake_minimum_required(VERSION 4.3)\n";
	file2 << "set(CMAKE_CXX_STANDARD 20) # GCC 16.1\n";
	file2 << endl;
	file2 << "project(" << proName << ")\n";
	file2 << "add_executable(${PROJECT_NAME} main.cpp)\n";
	file2 << endl;
	file2.close();

	system("mkdir NewProject/.build");
	system("mkdir NewProject/res");
	system("mkdir NewProject/src");

	return 1;
}
