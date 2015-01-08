vrs: vrs.c
	gcc -Wall vrs.c builtin.c look.c enter.c open.c fmt_stdout.c help.c path.c start.c make.c util.c -o vrs
	sudo cp vrs /usr/bin/vrs
