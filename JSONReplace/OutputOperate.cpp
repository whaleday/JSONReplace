#include "JSONReplace.h"
ofile::ofile(string name)
{
	pf = fopen(name.data(), "w");
}
void ofile::ofput(char c)
{
	fputc(c, pf);
}
ofile::~ofile()
{
	fclose(pf);
	pf = nullptr;
}