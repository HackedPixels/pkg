all:
	$(CC) pkg.c -o pkg

debug:
	$(CC) -g pkg.c -o pkg
