// Project Creator v0.1
// BY KC_C4

// Free2Use
// Free2Mod

// Use GCC And C++ Version 11 to 20
// DO NOT ADD SPACES IN TYPE DIR

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>

using namespace std;

string F_SetDir();
int F_Menu();
string F_GetCurDir();
int F_CreateProj(string proName,string proDir);
int F_CreateAsset(int a);

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
			}
			else
			{
				goto againMenu;
			}
			break;
		}
		case 2:
		{
			backToCreateAsset:;
			int a{0};
			cout << "[SELET WHAT YOU WANT TO CREATE]" << endl;
			cout << "[-1 - Exit | 1-4 Create File | 10/20/30/40 Create Folder]" << endl;
			cout << "1.Default .cpp File" << endl;
			cout << "2.Default .h File" << endl;
			cout << "3.Default .hpp File" << endl;
			cout << "4.Default CMakeLists.txt File" << endl;

			cout << "5.Default C++ Class Files" << endl;

			cout << "10.New Project Folder" << endl;
			cout << "20.Source Folder" << endl;
			cout << "30.Resources Folder" << endl;
			cout << "40.CMake's Build Folder" << endl;

			cout << ": ";cin >> a;
			if(F_CreateAsset(a) >= 0) {goto backToCreateAsset;}; returnValue = 1;
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

int F_CreateAsset(int a)
{
	int returnValue{0};
	string proDir{""};
	string name{""};

	switch(a)
	{
		case -1: returnValue = -1; break;
		case 1:
		{
			string cppFile{""};
			cout << "[Create New .cpp file]\n";
			cout << "! - main.cpp MACRO\n";
			cout << ":";cin >> name;

			 proDir = F_SetDir();

			if(name == "!")
			{
				cout << "CREATING main.cpp\n";
				cppFile={proDir+"/"+"main.cpp"};

				ofstream file (cppFile);

				file << "int main()\n{\n     return 0; \n}";
				file.close();
			}
			else {
				name += ".cpp";
				cout << "CREATING " << name << endl;;
				cppFile={proDir+"/"+name};

				ofstream file (cppFile);

				file << "";
				file.close();
			}
			returnValue = 1;
			break;
		}
		case 2:
		{
			string hFile{""};
			cout << "[Create New .h file]\n";
			cout << ":";cin >> name;

			proDir = F_SetDir();

			name += ".h";
			cout << "CREATING " << name << endl;;
			hFile={proDir+"/"+name};

			ofstream file (hFile);

			file << "";
			file.close();
			returnValue = 2;
			break;
		}
		case 3:
		{
			string hppFile{""};
			cout << "[Create New .hpp file]\n";
			cout << ":";cin >> name;

			proDir = F_SetDir();

			name += ".hpp";
			cout << "CREATING " << name << endl;;
			hppFile={proDir+"/"+name};

			ofstream file (hppFile);

			file << "";
			file.close();
			returnValue = 3;
			break;
		}
		case 4:
		{
			string cmakeFile{""};
			cout << "[Create New CMakeLists.txt file]\n";
			name = "CMakeLists.txt";
			proDir = F_SetDir();
			cout << "CREATING " << name << endl;;
			cmakeFile={proDir+"/"+name};

			ofstream file (cmakeFile);

			file << "cmake_minimum_required(VERSION 4.3)\n";
			file << "set(CMAKE_CXX_STANDARD 20) # GCC 16.1\n";
			file << endl;
			file << "project(" << "PROJECT" << ")\n";
			file << "add_executable(${PROJECT_NAME} main.cpp)\n";
			file << endl;
			file.close();
			returnValue = 4;
			break;

		}
		case 5:
		{
			string cppFile{""};
			string hppFile{""};
			cout << "[Create New .cpp&.hpp files]\n";
			cout << ":"; cin >> name;
			proDir = F_SetDir();
			cout << "CREATING CLASS" << name << endl;;

			cppFile={proDir+"/"+name+".cpp"};
			hppFile={proDir+"/"+name+".hpp"};

			ofstream file1 (cppFile);
			ofstream file2 (hppFile);
			file1 << "#include " << name << ".hpp" << "\"" << endl;
			file1.close();

			file2 << endl;
			file2.close();

			returnValue = 5;
			break;
		}
		case 10:
		{
			cout << "Created NewProject Folder\n";
			system("mkdir NewProject");
			returnValue = 10;
			break;
		}
		case 20:
		{
			cout << "Created Source Folder\n";
			system("mkdir src");
			returnValue = 20;
			break;
		}
		case 30:
		{
			cout << "Created Resources Folder\n";
			system("mkdir res");
			returnValue = 30;
			break;
		}
		case 40:
		{
			cout << "Created CMake's Build Folder\n";
			system("mkdir .build");
			returnValue = 40;
			break;
		}
		default: cout << "NO MATCH FOR " << a << endl; returnValue = 0;
	}

	return returnValue;
}

string F_SetDir()
{
	char curDir;
	string proDir;
	cout << "Use Current Dir (Y/N)?: "; cin >> curDir;
	if (curDir == 'Y' || 'y' || '1' || ' ')
	{
		cout << "Using Current Dir... " << (proDir = F_GetCurDir()) << "\n";
	}
	else if (curDir == 'N' || 'n' || '0')
	{
		cout << "TYPE DIR: "; cin >> proDir;
	}

	return proDir;
}
