// Text_parsing.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include<stdio.h>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include  <vector>
#include <windows.h>




int main(int argc, char**argv)
{
	string filePath = "character.txt";
	char* index[123];
	char* time[123];
	char* x[123];
	char* y[123];
	

	ifstream openFile(filePath.data());
	if (openFile.is_open()) {
		string line;
		int num = 0;
		while (getline(openFile, line)) {
			
			std::vector<char> writable(line.begin(), line.end());
			writable.push_back('\0');
			char* ptr = &writable[0];
			//std::cout << ptr;
			
			char* token = strtok(ptr, "/");
			//자신의 번호, 현재시간, x좌표, y좌표 
			
			int count = 0;
			while (token) {
				if (count == 0) {
					index[num] = token;
					count++;
				}
				else if (count == 1) {
					time[num] = token;
					count++;
				}
				else if (count == 2) {
					x[num] = token;
					count++;
				}
				else if (count == 3) {
					y[num] = token;
					count++;
				}
				//cout << token;
				//cout << "\n";
				token = strtok(NULL, "/");
			}
			
			cout << index[num] << endl;
			cout << time[num] << endl;
			cout << x[num] << endl;
			cout << y[num] << endl;
			num++;
			
		}
		openFile.close();
	}



	system("pause");
	

	



}

