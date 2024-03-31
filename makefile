src = main.c
obj = main.o
prog = ergosniffer

$(prog):$(obj)
	gcc $(obj) -o $(prog)

$(obj):$(src)
	gcc -c $^
