all: recursived loopd recursives loops mains maindloop maindrec

loops: libclassloops.a

recursives: libclassrec.a

loopd: libclassloops.so

recursived: libclassrec.so




libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o 
	
libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o 
	
libclassrec.so: basicClassification.c advancedClassificationRecursion.c
	gcc -Wall -fPIC -c basicClassification.c advancedClassificationRecursion.c
	gcc -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o
	export LD_LIBARY_PATH=.:$LD_LIBARY_PATH
	
libclassloops.so: basicClassification.c advancedClassificationLoop.c
	gcc -Wall -fPIC -c basicClassification.c advancedClassificationLoop.c
	gcc -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o
	export LD_LIBARY_PATH=.:$LD_LIBARY_PATH


	
mains: main.c
	gcc -Wall main.c ./libclassrec.a -L. -o mains
	
maindloop: main.c
	gcc -Wall main.c ./libclassloops.so -L. -o maindloop
	
maindrec: main.c 
	gcc -Wall main.c ./libclassrec.so -L. -o maindrec

.PHONY: clean all loops recursives loopd recursived

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec
