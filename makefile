all: recursived loopd recursives loops mains maindloop maindrec

loops: libclassloops.a

recursives: libclassrec.a

loopd: libclassloops.so

recursived: libclassrec.so




libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o 
	
libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o 
	
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o
	export LD_LIBARY_PATH=.:$LD_LIBARY_PATH
	
libclassloops.so: basicClassification.o advancedClassificationLoop.o
	gcc -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o
	export LD_LIBARY_PATH=.:$LD_LIBARY_PATH


	
mains: main.o recursives 
	gcc -Wall main.o ./libclassrec.a -L. -o mains
	
maindloop: main.c loopd 
	gcc -Wall -Werror -fPIC main.c ./libclassloops.so -L. -o maindloop
	
maindrec: main.c recursived 
	gcc -Wall -Werror -fPIC main.c ./libclassrec.so -L. -o maindrec

.PHONY: clean all loops recursives loopd recursived

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec
