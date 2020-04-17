// chinese.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "chinese_to_pinyin.hpp"
#include <cmath>
#include <ctime>
using namespace std;

void randompinyin();
void randompoem();
void lesson_guide();
void shengchengzidian();

std::map<std::string, std::string> dic;
map<string, string>::iterator iter;
std::ifstream f;
char hanziunicodebiao[4][20253];
char* pinyinbiao[20253];
wstring hanzibiao[20253];
char shengmubiao[4][20253];
char yunmubiao[4][20253];
int shengdiaobiao[20253];


int main()
{
	srand(time(0));
	std::wcout.imbue(std::locale("chs"));
	randompinyin();

}
void shengchengzidian()
{
	int counter=0;
	std::ifstream f;

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

	iter = dic.begin();
	while (iter != dic.end()) {
		wstring hanzi;
		stringstream hanziunicodehex;
		int hanziunicodeint;
		hanziunicodehex << hex << iter->first;
		hanziunicodehex >> hanziunicodeint;
		hanzi = hanziunicodeint;
		hanzibiao[counter] = hanzi;
		pinyinbiao[counter] = const_cast<char*>(iter->second.c_str());
		iter++;
		counter++;
	}
}
void lesson_guide()
{
	int counter;
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "                                                     ";
	cout << "大家久等了" << endl;
	getchar();
	system("cls");
	char playpoem;
	while (1)
	{
		
		randompoem();
		playpoem=getchar();
		system("cls");
		if (playpoem == 'q')
		{
			break;
		}
	}
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "             ";
	cout << "1.C++的算法有什么用：从20000字的汉字字库里找到我们需要的字，不进行算法优化，处理起来很困难；" << endl;
	getchar();
	getchar();
	system("cls");

	iter = dic.begin();
	counter = 1;
	while (iter != dic.end()) {
		wstring hanzi;
		stringstream hanziunicodehex;
		int hanziunicodeint;
		hanziunicodehex << hex << iter->first;
		hanziunicodehex >> hanziunicodeint;
		hanzi = hanziunicodeint;
		cout << counter<<":";
		wcout << hanzi;
		cout << "-" << iter->second << "  ";
		iter++;
		counter++;
	}
	getchar();
	getchar();
	system("cls");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "             ";
	cout << "1.C++的算法有什么用：从20000字的汉字字库里找到我们需要的字，不进行算法优化，处理起来很困难；" << endl;
	getchar();
	cout << "             ";
	cout << "2.刘慈欣写过一本《诗云》，推荐大家看看" << endl;
	getchar();
	cout << "             ";
	cout << "3.对计算机里的字典库进行处理，将每个字的汉语拼音分割为声母和韵母" << endl;
	getchar();
	cout << "             ";
	cout << "4.根据平仄的要求，设定我们声母、韵母、找到对应的汉字" << endl;
	getchar();
	cout << "             ";
	cout << "5.设定其他规则，如避开不喜欢的字，设定一定要有的字" << endl;
	getchar();
	cout << "             ";
	cout << "6.视频每周更新一次，老师把不完整的源代码发到群里，大家看视频学会了后完善代码" << endl;
	getchar();
	cout << "             ";
	cout << "7.欢迎找老师提问" << endl;
	getchar();
}

void randompoem()
{	
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	cout << "                                           计      算      机      作      诗" << endl << endl << endl;
	int i, j;
	for (j = 0; j < 8; j++)
	{

		cout << "                                                  ";
		for (i = 0; i < 7; i++)
		{
			wcout << hanzibiao[rand() % 20253];
			cout << " ";
		}
		if (j == 0 || j == 2 || j == 4||j==6)
		{
			cout << "，";
		}
		if (j == 1 || j == 3 || j == 5 || j == 7)
		{
			cout << "。";
		}
		cout << endl<<endl;
	}

}


void randompinyin()
{
	string shengmu[23] = { "b","p","m", "f", "d", "t", "n", "l", "g", "k", "h", "j", "q", "x", "z", "c", "s", "zh", "ch", "sh", "r", "y", "w" };
	string yunmu[24] = { "a", "o", "e", "i", "u", "v", "ai", "ei", "ui", "ao", "ou", "iu", "ie", "ve", "er", "an", "en", "in", "un", "vn", "ang", "eng", "ing", "ong" };
	int shengdiao[4] = { 1,2,3,4 };
	int i_shengmu;
	int i_yunmu;
	int i_shengdiao;
	char key;
	int i=0;
	while(1)
	{ 
		i_shengmu = rand() % 23;
		i_yunmu = rand() % 24;
		i_shengdiao = rand() % 4;

		string pinyin = shengmu[i_shengmu] + yunmu[i_yunmu];
		if (pinyin != "ba"&&pinyin!="bo"&&pinyin!="bi") //拼音不在白名单
		{
			cout << "拼音不在白名单"<<endl;
			continue;
		}


		cout <<i<<":"<< pinyin<<shengdiao[i_shengdiao]<< endl << endl;
		i++;
		key=getchar();
		if (key == 'q')
		{
			break;
		}

	}
}