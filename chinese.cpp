// chinese.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "chinese_to_pinyin.hpp"
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
	string shengmu[23] = { "b","p","m", "f", "d", "t", "n", "l", "g", "k", "h", "j", "q", "x", "z", "c", "s", "zh", "ch", "sh", "r", "y", "w" };
	string yunmu[24] = { "a", "o", "e", "i", "u", "v", "ai", "ei", "ui", "ao", "ou", "iu", "ie", "ve", "er", "an", "en", "in", "un", "vn", "ang", "eng", "ing", "ong" };
	string shengdiao[4] = { "-","/","v","\\" };

	std::map<std::string, std::string> dic;
	std::ifstream f;
	srand(time(0));
	std::wcout.imbue(std::locale("chs")); 
	int counter=0;
	wstring hanzibiao[20253];
	string hanziunicodebiao[20253];
	string pinyinbiao[20253];
	string shengmubiao[20253];
	string yunmubiao[20253];
	string shengdiaobiao[20253];

/*
	for (int i = 0; i < 100; i++)
	{
		int i_shengmu = rand() % 23;
		int i_yunmu = rand() % 24;
		int i_shengdiao = rand() % 4;
		if (shengmu[i_shengmu] == "b")
		{
			while (yunmu[i_yunmu] == "un" || "vn")
			{
				int i_yunmu = rand() % 24;

			}
		}

		int space = shengmu[i_shengmu].length();
		for (int j = 0; j <= space - 1; j++)
		{
			cout << " ";

		}
		cout << shengdiao[i_shengdiao] << endl;
		cout << shengmu[i_shengmu] << yunmu[i_yunmu] << endl<<endl;
	}
	*/

	f.open("unicode_to_pinyin.txt");
	std::string line;
	while (std::getline(f, line)) {
		std::stringstream ss(line);
		std::string first;
		std::string second;
		ss >> first;
		ss >> second;
		dic[first] = second;
	}
	f.close();

	
	map<string, string>::iterator iter;
	iter = dic.begin();
	while (iter != dic.end()) {
		wstring hanzi;
		stringstream hanziunicodehex;
		int hanziunicodeint;
		hanziunicodehex <<hex<< iter->first;
		hanziunicodehex >> hanziunicodeint;
		hanzi = hanziunicodeint;
		wcout << hanzi;
		hanzibiao[counter] = hanzi;
		pinyinbiao[counter] = iter->second;
		cout << "-" << iter->second << endl;

		//hanzi = strtol(iter->first,NULL,16);
		//cout << hanzi;
		//cout << iter->first << "-" << iter->second << endl;
		iter++;
		counter++;
	}
	cout << counter;





}
