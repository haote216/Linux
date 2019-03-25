libmymath.a:sub.o add.o
	ar -rc $@ $^
sub.o:sub.c
	gcc -c $^ -o $@
add.o:add.c
	gcc -c $^ -o $@

.PHONY:clean
clean:
	rm -rf *.o libmymath.a
