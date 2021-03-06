CFLAGS=-Wall -g

ifeq ($(shell echo "check_quotes"),"check_quotes")
WINDOWS := yes
clean:
	del exer1.exe
	del ex3.exe
	del ex8.exe
	del ex9.exe
	del ex10.exe
	del ex11.exe
	del ex12.exe
	del ex13.exe
	del ex14.exe
	del ex15.exe
	del ex16.exe
	del ex17.exe
	del ex18.exe
	del ex19.exe
	del ex22.o
	del ex22_main.exe
	del ex23.exe
all:
	del exer1.exe
	del ex3.exe
	del ex8.exe
	del ex9.exe
	del ex10.exe
	del ex11.exe
	del ex12.exe
	del ex13.exe
	del ex14.exe
	del ex15.exe
	del ex16.exe
	del ex17.exe
	del ex18.exe
	del ex19.exe
	del ex22.o
	del ex22_main.exe
	del ex23.exe
	del wingrep.exe
	gcc exer1.c -o exer1
	gcc ex3.c -o ex3
	gcc ex8.c -o ex8
	gcc ex9.c -o ex9
	gcc ex10.c -o ex10
	gcc ex11.c -o ex11
	gcc ex12.c -o ex12
	gcc ex13.c -o ex13
	gcc ex14.c -o ex14
	gcc ex15.c -o ex15
	gcc ex16.c -o ex16
	gcc ex17.c -o ex17
	gcc ex18.c -o ex18
	gcc ex19.c -o ex19
	gcc -Wall -g -DNDEBUG -c -o ex22.o ex22.c
	gcc -Wall -g -DNDEBUG ex22_main.c ex22.o -o ex22_main
	gcc ex23.c -o ex23
	gcc wingrep.c -o wingrep	
else
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
	rm -f ex15
	rm -f ex16
	rm -f ex17
	rm -f ex18
	rm -f ex19
	rm -f ex22.o
	rm -f ex22_main
	rm -f ex23
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
	rm -f ex15
	rm -f ex16
	rm -f ex17
	rm -f ex18
	rm -f ex19
	rm -f ex22.o
	rm -f ex22_main
	rm -f ex23
	rm -f wingrep
	gcc exer1.c -o exer1
	gcc ex3.c -o ex3
	gcc ex8.c -o ex8
	gcc ex9.c -o ex9
	gcc ex10.c -o ex10
	gcc ex11.c -o ex11
	gcc ex12.c -o ex12
	gcc ex13.c -o ex13
	gcc ex14.c -o ex14
	gcc ex15.c -o ex15
	gcc ex16.c -o ex16
	gcc ex17.c -o ex17
	gcc ex18.c -o ex18
	gcc ex19.c -o ex19
	gcc -Wall -g -DNDEBUG -c -o ex22.o ex22.c
	gcc -Wall -g -DNDEBUG ex22_main.c ex22.o -o ex22_main
	gcc ex23.c -o ex23
	gcc wingrep.c -o wingrep
WINDOWS := no

endif


	

