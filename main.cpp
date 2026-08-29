// Project Creator v0.1
// BY KC_C4

// Free2Use
// Free2Mod

// Use GCC And C++ Version 11 to 20
// DO NOT ADD SPACES IN TYPE DIR

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <sys/types.h>

using namespace std;

string userName{"macmini"}; //repalce with our own :)

string F_SetDir();
int F_Menu();
string F_GetCurDir();
int F_CreateProj(string proName);
int F_CreateAsset(int a);
string F_SetFolder(u_int8_t a,string _proName);

int main()
{
	if(userName == ""){cout << "TYPE YOUR USR NAME: ";	cin >> userName;}

	return F_Menu();
}

int F_Menu()
{
	int returnValue{-1};
	cout << "[Project Creator v1.0]" << endl;

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
			bool setuped{false};	string proName{""};

			cout << "[Create New Project]" << endl;
			cout << "TYPE NAME: "; cin >> proName;

			if(proName.length() >= 1){if(proName != ""){setuped = true;}	}
			else{	cout << "ERROR: NO PROJECT NAME or PROJECT NAME LENGTH TO SHORT!!!" << endl;	goto againMenu;	}

			if (setuped){returnValue = F_CreateProj(proName);}
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

			cout << "10.New Folder" << endl;
			cout << "11.Source Folder" << endl;				// MACRO
			cout << "12.Resources Folder" << endl;			// MACRO
			cout << "13.CMake's Build Folder" << endl;		// MACRO

			cout << ": ";cin >> a;
			if(F_CreateAsset(a) >= 0) {goto backToCreateAsset;}; returnValue = 1;
			break;
		}
		case 3:
		{
			backToSelectYesNo:;
			char yesno{};

			cout << "WARNING: THIS OPTION WORKS ONLY WHEN YOU INSIDE .build IN YOUR PORJECT!!!\n";
			cout << "Continue? (Y/N):" ; cin >> yesno;

			if (yesno == 'Y'|| yesno == 'y' || yesno == '1')
			{
				system("cmake ..");
				system("make -C .build");
				returnValue = 1;
			}
			else if (yesno == 'N' || yesno == 'n' || yesno == '0')
			{
				returnValue = 0; goto againMenu;
			}
			else {cout << "NO MATCH FOR " << yesno << endl;;goto backToSelectYesNo;}


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

int F_CreateProj(string _proName)
{
	string _proDir =F_SetFolder(1,_proName);
	string cppFile{_proDir+"/"+"main.cpp"};
	string cmakeFile{_proDir+"/"+"CMakeLists.txt"};

	cout << "[Creating]\n";
	cout << "[PROJECT NAME: " << _proName << " ]\n";
	cout << "[DIR : " << _proDir << " ]\n";

	ofstream file1 (cppFile);

	file1 << "int main()\n{\n     return 0; \n}";
	file1.close();

	ofstream file2 (cmakeFile);

	file2 << "cmake_minimum_required(VERSION 4.3)\n";
	file2 << "set(CMAKE_CXX_STANDARD 20) # GCC 16.1\n";
	file2 << endl;
	file2 << "project(" << _proName << ")\n";
	file2 << "add_executable(${PROJECT_NAME} main.cpp)\n";
	file2 << endl;
	file2.close();

	filesystem::create_directories(_proDir+"/.build");
	filesystem::create_directories(_proDir+"/src");
	filesystem::create_directories(_proDir+"/res");

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
			cout << "IN DIR: " << proDir << endl;
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
			cout << "IN DIR: " << proDir << endl;

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
			cout << "IN DIR: " << proDir << endl;

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
			cout << "IN DIR: " << proDir << endl;

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
			cout << "IN DIR: " << proDir << endl;
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
			string folderName{""};
			proDir = F_SetDir();

			cout << "Create Folder: "; cin >> folderName;

			string folderDirName{proDir+"/"+folderName};

			cout << "Created New Folder\n";
			filesystem::create_directories(folderDirName);

			returnValue = 10;
			break;
		}
		// MACRO
		case 11:
		{
			cout << "Created Source Folder\n";
			system("mkdir src");
			returnValue = 11;
			break;
		}
		case 12:
		{
			cout << "Created Resources Folder\n";
			system("mkdir res");
			returnValue = 12;
			break;
		}
		case 13:
		{
			cout << "Created CMake's Build Folder\n";
			system("mkdir .build");
			returnValue = 13;
			break;
		}
		// MACRO END
		default: cout << "NO MATCH FOR " << a << endl; returnValue = 0;
	}

	return returnValue;
}

string F_SetDir()
{
	backToSelectCurDir:;
	char yesno{};
	string proDir{""};
	cout << "Use Current Dir (Y/N)?: "; cin >> yesno;
	if (yesno == 'Y'|| yesno == 'y' || yesno == '1')
	{
		proDir = F_GetCurDir();
		cout << "Using Current Dir... " << proDir << "\n";
	}
	else if (yesno == 'N' || yesno == 'n' || yesno == '0')
	{
		string abcd{"/home/"+userName+"/"};
		cout << "TYPE DIR: "; cin >> proDir;
		if(proDir[0] == '~' && proDir[1] == '/') // FIX: Before fix no "~" or "~/" (/home/user/) macro
		{
			int aaa=2;
			while(aaa < proDir.length())
			{
				abcd += proDir[aaa];
				cout << aaa << ": " << abcd << endl;
				aaa++;
			}
			if(aaa >= proDir.length()) {proDir = abcd;}
		}
	}
	else {cout << "NO MATCH FOR " << yesno <<endl;goto backToSelectCurDir;}

	return proDir;
}

string F_SetFolder(u_int8_t a,string _proName) // Pass 0 for Just Folder | Pass 1 For New project
{
	string folderName{""},proDir{""};
	proDir = F_SetDir();

	if(a == 0){cout << "Create Folder: "; cin >> folderName;}
	if(a == 1){cout << "Creating new Project: "<< _proName << endl;}

	string folderDirName{proDir+"/"+_proName};

	cout << "folderDirName = "<< folderDirName << endl;
	filesystem::create_directories(folderDirName);
	return folderDirName;
}
