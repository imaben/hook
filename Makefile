all:
	gcc -o test test.c
	gcc -fPIC -shared -o ring3.so ring3hook.c -ldl

clean:
	rm -rf test
	rm -rf ring3.so
