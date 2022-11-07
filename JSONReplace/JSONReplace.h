#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
#include <chrono>
#include <cstdarg>
#define SEEK_ENT 3
#define MAX 100
using namespace std;
string nowtime();
string addzero(int para);
struct ifile
{
	FILE* pf;
	ifile(string name);
	void skip(int ofs = 1, int para = 1);
	char ifget();
	void ifget(string fms, ...);
    char nextch();
	~ifile();
};
struct ofile
{
	FILE* pf;
	ofile(string name);
	void ofput(char c);
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