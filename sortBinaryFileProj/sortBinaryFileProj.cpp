//============================================================================
// Name        : MySort.cpp
// Author      : SomayeGhahari
// Version     :
// Copyright   : Your copyright notice
// Description : sort binary file in C++
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <windows.h>
#include "employee.h";
//using namespace std;

 bool compareId (const employee & obj1, const employee & obj2);

int main(int argc, char* argv[]) {
	SetConsoleTitle("EReport");
	std::string fileName;
	std::ifstream datFile;
	std::vector<employee> empList;
	std::vector<employee>::iterator iter;

	if(argc == 2){
		fileName = argv[1];
		if(fileName!=""){
			//reading dat file content
			datFile.open(fileName);
			while(!datFile.eof())
			{
				std::string tStr;
				employee emp;
				getline(datFile, tStr);
				if(tStr.size()>1 && tStr.at(0)!='#'){
	//				cout << tStr ;
					emp.parseLine(tStr);
					empList.push_back(emp);
				}

			 }
			datFile.close();

			//sorting based on employee id
			std::cout << std::endl<< "Processing by employee number..."<< std::endl;
			std::sort(empList.begin(), empList.end(), compareId);

			iter = empList.begin();

			for ( ; iter !=  empList.end(); iter++) {
				std::cout <<(*iter);
			}
			//sorting based on employee last name
			std::cout << std::endl<<"Processing by last(family) name..."<< std::endl;

			std::sort(empList.begin(), empList.end());
			iter = empList.begin();

			for ( ; iter !=  empList.end(); iter++) {
				std::cout <<(*iter);
			}

		}

	}

	return 0;
}
