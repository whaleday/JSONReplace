#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
#include <chrono>
#include <cstdarg>
#define SEEK_ENT 3
#define MAX 100
using size_mt = unsigned int;
using namespace std;
string nowtime();
string addzero(int para);
string dtrans(double d);
string gettime(double d, double v);
struct ifile
{
	FILE* pf;
	ifile(string name);
	ifile(ifile& fname);
	void skip(int ofs = 1, int para = 1);
	char ifget();
	void ifget(string fms, ...);
    char nextch();
	time_t readt();
	double reads();
	double readv();
	~ifile();
};
struct ofile
{
	FILE* pf;
	ofile(string name);
	void ofput(char c);
	void ofput(string str);
	void back(int ofs = 1);
	void putll(ifile& way);
	void copy(ifile& fin , size_mt size);
	int size();
	~ofile();
};
struct tinf
{
	tm t;
	int msec;
	void tget(ifile& f);
	void rands();
	void randms();
	bool isleap();
	bool isvaild();
	time_t tget(bool b = 0);
};
struct cinf
{
	string lat;
	string lng;
};