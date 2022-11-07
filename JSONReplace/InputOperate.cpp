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
ifile::~ifile()
{
	fclose(pf);
	pf = nullptr;
}