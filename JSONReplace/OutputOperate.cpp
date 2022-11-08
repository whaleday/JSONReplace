#include "JSONReplace.h"
ofile::ofile(string name)
{
	pf = fopen(name.data(), "w+");
}
void ofile::ofput(char c)
{
	fputc(c, pf);
}
void ofile::ofput(string str)
{
	fputs(str.data(), pf);
}
void ofile::back(int ofs)
{
	fseek(pf, -ofs, SEEK_CUR);
}
void ofile::putll(ifile& way)
{
	cinf cor;
	char t[40];
	do
	{
		way.ifget("%s", t);
		cor.lat = strtok(t, ",");
		cor.lng = strtok(NULL, ",");
		ofput("{\\\"lat\\\":" + cor.lat + ", \\\"lng\\\":" + cor.lng + "}, ");
		way.skip(2);
	} while (way.nextch() != EOF);
	back(2);
}
void ofile::copy(ifile& fin , size_mt size)
{
	for (int i = 0; i < size; i++)
		ofput(fin.ifget());
}
int ofile::size()
{
	rewind(pf);
	int count = 0;
	while (fgetc(pf) != EOF)
		count++;
	return count;
}
ofile::~ofile()
{
	fclose(pf);
	pf = nullptr;
}