const char* SHELL = "/bin/sh";
const char* DATABASELOCATION = "/home/jan/Documents/packages/";  
const char* EXTRACT[10][2] = {
/* %s is the current filename */
/*	Suffix	Command */
	{"xz",	"xz -d %s"},
	{"zip",	"unzip %s"},
	{"gz",	"gunzip %s"},
	{"tar",	"tar -xf %s"},
	{NULL,	NULL} /* Terminator. */
};
