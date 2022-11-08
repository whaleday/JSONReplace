#include "JSONReplace.h"
string addzero(int para)
{
	string buf;
	if (para < 10)
		buf += '0';
	buf += to_string(para);
	return buf;
}
string nowtime()
{
	string ret;
	time_t stamp = time(NULL);
	tm* now = localtime(&stamp);
	ret = to_string(now->tm_year + 1900) + addzero(now->tm_mon + 1) + addzero(now->tm_mday)
		+ addzero(now->tm_hour) + addzero(now->tm_min) + addzero(now->tm_sec);
	return ret;
}
string dtrans(double d)
{
	char s[10];
	sprintf(s, "%.2lf", d);
	string str(s);
	return str;
}
string gettime(double d,double v)
{
	char s[10];
	double t = 3600 * d / v;
	sprintf(s, "%.lf", t);
	string str(s);
	return str;
}
void tinf::tget(ifile& f)
{
	static int count = 1;
	string buf;
	f.skip();
	char ch = f.ifget();
	if (ch != '0')
		buf += ch;
	buf += f.ifget();
	if (count--)
		t.tm_min = atoi(buf.data());
	else
		t.tm_sec = atoi(buf.data());
}
void tinf::rands()
{
    t.tm_sec = rand() % 60;
}
void tinf::randms()
{
	msec = rand() % 1000;
}
bool tinf::isleap()
{
	return (t.tm_year % 4 == 0 && t.tm_year % 100 != 0) || t.tm_year % 400 == 0;
}
bool tinf::isvaild()
{
	int map[] = { 1,-2 + isleap(),1,0,1,0,1,1,0,1,0,1 };
	if (t.tm_year >= 2000 && t.tm_year <= 2050
		&& t.tm_mon >= 1 && t.tm_mon <= 12
		&& t.tm_mday >= 1 && t.tm_mday <= 30 + map[t.tm_mon - 1]
		&& t.tm_hour >= 0 && t.tm_hour < 24
		&& t.tm_min >= 0 && t.tm_min < 60
		&& t.tm_sec >= 0 && t.tm_sec < 60
		&& msec >= 0 && msec < 1000)
		return 1;
	else
	{
		cerr << "无效的日期格式" << endl;
		system("pause");
		exit(-1);
	}
}
time_t tinf::tget(bool b)
{
	if (!b && isvaild())
	{
		t.tm_mon--;
		t.tm_year -= 1900;
		return mktime(&t) * 1000 + msec;
	}
	else
		return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}
