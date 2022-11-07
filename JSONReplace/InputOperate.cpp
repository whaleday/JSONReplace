#include "JSONReplace.h"
ifile::ifile(string name)
{
	pf = fopen(name.data(), "r");
	if (!pf)
	{
		cerr << "文件打开出错";
		exit(-1);
	}
}
void ifile::skip(int ofs, int para)
{
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
ifile::~ifile()
{
	fclose(pf);
	pf = nullptr;
}