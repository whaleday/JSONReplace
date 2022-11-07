#include "JSONReplace.h"
int main()
{
	srand((unsigned int)time(NULL));
	ifile fin = "body";
	ifile set = "setting.txt";
	ofile fout = nowtime();
	for (int i = 0; i < 274; i++)
	{
		fout.ofput(fin.ifget());
	}
	fout.~ofile();
	time_t t;
	tinf info;
	set.skip(62);
	info.mode = set.ifget();
	set.skip(2);
	if (info.mode >= '0' && info.mode <= '4')
	{
		if (info.mode != '2')
		{
			set.ifget("%d-%d-%d %d", &info.t.tm_year, &info.t.tm_mon, &info.t.tm_mday, &info.t.tm_hour);
			info.tget(set);
			if (info.mode == '0' || info.mode == '2')
			{
				info.tget(set);
				if (info.mode == '0')
					set.ifget(".%d", &info.msec);
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
			t = info.tget();
			set.skip(2);
		}
		set.skip(2);
	}
	else
	{
		cerr << "无效的参数" << endl;
		exit(-1);
	}
}
