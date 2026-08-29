## C++ PROJECT CREATOR by KC_C4 / KC-3705

Simple Terminal App For Linux to Create Your C++ + CMake Project.
Use how ever you want.
On this moment (29.08.2026) current version of this App is v1.0 aka."Release 1".

## HOW TO COMPILE?
	Simple...
	1.Download Source Code
	2.Download CMake and GCC
	3.Go to SourceCode Dir and type "g++ main.cpp -o ProCreator"
	4.Copy "ProCreator" in your project contain folder
	5.Launch "ProCreator"

## What New Created Project Look Like:
	.build/			| Build Folder for CMake Project
	res/			| Resource Folder (Music/Sprites/Fonts)
	src/			| Source Folder (.cpp / .h / .hpp)
	main.cpp		| Main Program File
	CMakeLists.txt	| CMake Link Lib File

## Options to chose:
	1. Create Project
		1.1.TYPE NAME: <string>
		1.2.USE CURRENT DIR?: <bool>
			1.2.1.TYPE YOUR DIR: <string>
	2. Create...
		2.1. Default/Main .cpp File
		2.2. Default .h File
		2.3. Default .hpp File
		2.4. Default CMakeLists.txt File
		2.5. Default C++ Class
		2.10. Created NewProject Folder
		2.11. Created Source Folder 
		2.12. Created Resources Folder
		2.13. Created CMake's Build Folder
	3. Compile Project
	Exit [CTRL+C]

## Inside...:
	main.cpp 			| just main() func.
	CMakeLists.txt 		| Default CMake/C++ Version (CMake 4.3 or 3.21 , C++11 to C++20)
	Default .cpp Class	| just #include "yourClass.hpp"
