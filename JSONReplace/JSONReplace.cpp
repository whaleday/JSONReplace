#include "JSONReplace.h"
int main()
{
	srand((unsigned int)time(NULL));
	ifile set("setting.txt");
	time_t t = set.readt();
	ifile fin("body");
	ofile fout = nowtime();
	fout.copy(fin, 16);
	ifile way = set;
	double s = way.reads();
	string str = dtrans(s);
	fout.ofput(str);
	fin.skip(4);
	fout.copy(fin, 255);
	fout.putll(way);
	while (fin.ifget() != ']');
	fin.skip(-1);
	fout.copy(fin, 39);
	fout.ofput(str);
	fin.skip(4);
	fout.copy(fin, 28);
	double v = set.readv();
	str = dtrans(60 / v);
	fout.ofput(str);
	fin.skip(4);
	fout.copy(fin, 10);
	str = to_string(t);
	fout.ofput(str);
	fin.skip(13);
	fout.copy(fin, 9);
	str = gettime(s, v);
	fout.ofput(str);
	while (fin.ifget() != ',');
	fin.skip(-1);
	fout.copy(fin, 11);
	cout << "生成成功" << endl << "Content-Length应修改为" << fout.size() << endl;
	system("pause");
    return 0;
}
