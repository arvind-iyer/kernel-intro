obj-m += hello-1.o

all:
	make -C /usr/src/kernels/$(shell uname -r)+debug M=$(PWD) modules 
clean:
	make -C /usr/src/kernels/$(shell uname -r)+debug M=$(PWD) clean

