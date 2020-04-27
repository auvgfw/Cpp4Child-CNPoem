// chinese.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "chinese_to_pinyin.hpp"
#include <cmath>
#include <ctime>
using namespace std;
void randompoem();
void randompinyin(string req_shengmu = "*", string req_yunmu = "*");
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
	randompinyin("b");

}
void shengchengzidian()
{
	int counter = 0;
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
		playpoem = getchar();
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
		cout << counter << ":";
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
		if (j == 0 || j == 2 || j == 4 || j == 6)
		{
			cout << "，";
		}
		if (j == 1 || j == 3 || j == 5 || j == 7)
		{
			cout << "。";
		}
		cout << endl << endl;
	}

}


void randompinyin(string req_shengmu, string req_yunmu)
{
	string shengmu[23] = { "b","p","m", "f", "d", "t", "n", "l", "g", "k", "h", "j", "q", "x", "z", "c", "s", "zh", "ch", "sh", "r", "y", "w" };
	string yunmu[24] = { "a", "o", "e", "i", "u", "v", "ai", "ei", "ui", "ao", "ou", "iu", "ie", "ve", "er", "an", "en", "in", "un", "vn", "ang", "eng", "ing", "ong" };
	int shengmulenth = sizeof(shengmu) / sizeof(shengmu[0]);
	int yunmulenth = sizeof(yunmu) / sizeof(yunmu[0]);
	//合法的汉语拼音表
	string pinYinWhiteList_Temp = "ba bo bai bei bao ban ben bang beng bi bie biao bian bin bing pa po pai pao pou pan pen pang peng pi pie piao pian pin ping ma mo me mai mao mou man men mang meng mi mie miao miu mian min ming fa fo fei fou fan fen fang feng da de dai dei dao dou dan dang deng di die diao diu dian ding ta te tai tao tou tan tang teng ti tie tiao tian ting na nai nei nao no nen nang neng ni nie niao niu nian nin niang ning la le lai lei lao lou lan lang leng li lia lie liao liu lian lin liang ling ga ge gai gei gao gou gan gen gang geng ka ke kai kou kan ken kang keng ha he hai hei hao hou hen hang heng ji jia jie jiao jiu jian jin jiang jing qi qia qie qiao qiu qian qin qiang qing xi xia xie xiao xiu xian xin xiang xing zha zhe zhi zhai zhao zhou zhan zhen zhang zheng cha che chi chai chou chan chen chang cheng sha she shi shai shao shou shan shen shang sheng re ri rao rou ran ren rang reng za ze zi zai zao zou zang zeng ca ce ci cai cao cou can cen cang ceng sa se si sai sao sou san sen sang seng ya yao you yan yang yu ye yue yuan yi yin yun ying wa wo wai wei wan wen wang weng wu";
	string pinYinWhiteList[552];
	int shengdiao;
	int i_shengmu = 0;
	int i_yunmu = 0;
	char key;
	int i = 0;
	int n = 0;
	stringstream line(pinYinWhiteList_Temp);
	i = 0;
	//将temp白名单分割成数组。即是说，把一个字符串"aa bb cc dd"分割成"aa","bb","cc","dd"多个字符串，并分别保存在数组的一个个元素里
	while (getline(line, pinYinWhiteList_Temp, ' '))
	{
		pinYinWhiteList[i] = pinYinWhiteList_Temp;
		i++;
	}
	int pinYinWhiteListLenth = sizeof(pinYinWhiteList) / sizeof(pinYinWhiteList[0]);

	//使用sizeof（数组名）/sizeof（数组里的第一个元素）可以知道数组里一共有多少元素

	//从0到数组最后一位遍历，看看req_yunmu是否在韵母表里
	for (i = 0; i < yunmulenth; i++)
	{
		if (yunmu[i] == req_yunmu)
		{
			i_yunmu = i;
			break;
		}
	}
	//同上，判断声母在不在列表
	for (i = 0; i < shengmulenth; i++)
	{
		if (shengmu[i] == req_shengmu)
		{
			i_shengmu = i;
			break;
		}
	}

	n= 0;

	while (1)
	{
		if (shengmu[i_shengmu] != req_shengmu)
		{
			i_shengmu = rand() % 23;
		}
		if (yunmu[i_yunmu] != req_yunmu)
		{
			i_yunmu = rand() % 24;
		}
		shengdiao = rand() % 4 + 1;

		string pinyin = shengmu[i_shengmu] + yunmu[i_yunmu];
		//从遍历白名单，看看pinyin是否在里面
		for (int i = 0; i < pinYinWhiteListLenth; i++)
		{
			if (pinyin == pinYinWhiteList[i])
			{
				cout<<n<<":" << pinyin<<shengdiao<<endl<<endl;
				n++;
				break;
			}
		}


		if (n >= 100)
		{
			break;
		}
	}
}