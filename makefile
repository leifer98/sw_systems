all: loops recursives recursived loopd mains maindloop maindrec

loops: libclassloops.a

recursives: libclassrec.a

loopd: libclassloops.so

recursived: libclassrec.so




libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rc libclassloops.a basicClassification.o advancedClassificationLoop.o 
	
libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rc libclassrec.a basicClassification.o advancedClassificationRecursion.o 
	
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so basicClassification.c advancedClassificationRecursion.c 
	export LD_LIBARY_PATH=.:$LD_LIBARY_PATH
	
libclassloops.so: basicClassification.c advancedClassificationLoop.c
	gcc -shared -o libclassloops.so basicClassification.c advancedClassificationLoop.c
	export LD_LIBARY_PATH=.:$LD_LIBARY_PATH


	
mains: main.c recursives 
	gcc -Wall main.c ./libclassrec.a -L. -o mains
	
maindloop: main.c loopd 
	gcc -Wall -fPIC main.c ./libclassloops.so -o maindloop
	
maindrec: main.c recursived 
	gcc -Wall -fPIC main.c ./libclassrec.so -o maindrec

.PHONY: clean all loops recursives loopd recursived

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec
