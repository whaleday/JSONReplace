#include "JSONReplace.h"
ifile::ifile(string name)
{
	pf = fopen(name.data(), "r");
	if (!pf)
	{
		cerr << "文件打开出错";
		system("pause");
		exit(-1);
	}
}
ifile::ifile(ifile& fname)
{
	fname.skip(6);
	string route;
	fname.ifget("%s", route.data());
	pf = fopen(route.data(), "r");
	fname.skip(2);
}
void ifile::skip(int ofs, int para)
{
    char buf[MAX];
    if(para == 3)
    {
        while(ofs--)
            fgets(buf, MAX, pf);
        return;
    }
	fseek(pf, ofs, para);
}
char ifile::ifget()
{
	return fgetc(pf);
}
void ifile::ifget(string fms, ...)
{
	va_list _arglist;
	va_start(_arglist, fms);
	const char* _format = fms.data();
	vfscanf(pf, _format, _arglist);
	va_end(_arglist);
}
char ifile::nextch()
{
    char ch = ifget();
    if(ch == '\n')
        skip(-1);
    skip(-1);
    return ch;
}
time_t ifile::readt()
{
	time_t t;
	tinf info;
	skip(5);
	if (nextch() == '2' || nextch() == '\n')
	{
		if (nextch() == '2')
		{
			ifget("%d-%d-%d %d", &info.t.tm_year, &info.t.tm_mon, &info.t.tm_mday, &info.t.tm_hour);
			info.tget(*this);
			if (nextch() == ':')
			{
				info.tget(*this);
				if (nextch() == '.')
					ifget(".%d", &info.msec);
				else
					info.randms();
			}
			else
			{
				info.rands();
				info.randms();
			}
			t = info.tget();
		}
		else
		{
			t = info.tget(1);
		}
		skip(2);
	}
	else
	{
		cerr << "无效的参数" << endl;
		system("pause");
		exit(-1);
	}
	return t;
}
double ifile::reads()
{
	skip(9);
	double d;
	ifget("%lf", &d);
	skip(2);
	return d;
}
double ifile::readv()
{
	skip(6);
	double d;
	ifget("%lf", &d);
	skip(2);
	return d;
}
ifile::~ifile()
{
	fclose(pf);
	pf = nullptr;
}