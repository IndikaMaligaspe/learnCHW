CFLAGS=-Wall -g

clean:
	rm -f exer1
	rm -f ex3
	rm -f ex8
	rm -f ex9
	rm -f ex10
	rm -f ex11
	rm -f ex12
	rm -f ex13
	rm -f ex14
all:
	rm -f exec1
	rm -f ex3
	rm -f ex8
	rm -f ex9
	rm -f ex10
	rm -f ex11
	rm -f ex12
	rm -f ex13
	rm -f ex14

	gcc exer1.c -o exer1
	gcc ex3.c -o ex3
	gcc ex8.c -o ex8
	gcc ex9.c -o ex9
	gcc ex10.c -o ex10
	gcc ex11.c -o ex11
	gcc ex12.c -o ex12
	gcc ex13.c -o ex13
	gcc ex14.c -o ex14

