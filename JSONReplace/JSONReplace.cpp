#include "JSONReplace.h"
int main()
{
	srand((unsigned int)time(NULL));
	ifile fin("body");
	ifile set("setting.txt");
	ofile fout = nowtime();
	for (int i = 0; i < 274; i++)
		fout.ofput(fin.ifget());
	time_t t;
	tinf info;
    set.skip(1,SEEK_ENT);
	if (set.nextch() == '2' || set.nextch() == '\n')
	{
		if (set.nextch() == '2')
		{
			set.ifget("%d-%d-%d %d", &info.t.tm_year, &info.t.tm_mon, &info.t.tm_mday, &info.t.tm_hour);
			info.tget(set);
			if (set.nextch() == ':')
			{
				info.tget(set);
				if (set.nextch() == '.')
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
			t = info.tget(1);
			set.skip(2);
		}
		set.skip(2);
	}
	else
    {
		cerr << "无效的参数" << endl;
        system("pause");
		exit(-1);
	}
    return 0;
}
