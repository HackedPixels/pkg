#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <varargs.h>
#include <string.h>
#include"config.h"

#define OK 0
	
enum {
	UNZIP
};

void strnrev(char*, size_t);
void strrev(char*);
void unzip(char*);
void log(char*, char*);

int
main(argc, argv)
	int argc;
	char** argv;
{
	unzip("hello.world.tar.zip");
	return OK;
}


void
unzip(file)
	char* file;
{
	register int i;
	/* FIXME: remove double memory usage. */
	char buffer[128], * tok; /* to resolve suffixes */
	char filename[128], * pos; /* For commands */

	strcpy(buffer, file);
	strrev(buffer);
	strcpy(filename, buffer);
	pos = filename;

	/* FIXME: Make this more efficient. */
	tok = strtok(buffer, ".");
	do {
		strrev(tok);
	//	printf("%s\n", tok);
		for (i = 0; EXTRACT[i][0] != NULL; i++)
		{
			if (strcmp(tok, EXTRACT[i][0]) == 0)
			{
				pos = strpbrk(pos, ".");
				strrev(pos);
//				printf("%s\n", pos);
				printf("[%d]: %s -> %s\n", i, EXTRACT[i][0], pos);
				log("UNPACKING", "EXTRACT[i][0]");
				strrev(pos);
				pos++;
			}
		}
	} while ((tok = strtok(NULL, ".")) != NULL && *pos != '\0');
	
}

void
log(target, message)
	char* target, *message;
{
	static char strtarget[64];
	if (target != NULL && strcmp(target, strtarget) != 0)
	{
		strcpy(strtarget, target);
		printf("%s\t-> %s\n", strtarget, message);
	} else
	{
		printf("%*s\t-> %s\n", strlen(strtarget), "", message);
	}
}

void
strnrev(rev, len)
	char* rev;
	size_t len;
{
	size_t idx;

	for (idx = len >> 1; idx > 0; idx--)
	{
		rev[len] = rev[idx - 1];
		rev[idx - 1] = rev[len - idx];
		rev[len - idx] = rev[len];
	}
	rev[len] = '\0';
}

void
strrev(rev)
	char* rev;
{
	size_t len = 0;
	while (rev[len++]);
	strnrev(rev, --len);
}
