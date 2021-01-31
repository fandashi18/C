# C 编译参数
COMPILE.c := gcc
C_STANDARD := -std=c11
C_OPTIMIZATION := -O1
C_INCLUDE := -I.
C_DEFINE := -DCOMPILETIME
CFLAGS := $(C_STANDARD) $(C_OPTIMIZATION)

# 编译输出目录
OUTDIR := out
                                                                    
all : $(OUTDIR) main

$(OUTDIR):
	mkdir $(OUTDIR)

main : $(OUTDIR)/mymalloc.o main.c
	$(COMPILE.c) $(CFLAGS) $(C_INCLUDE) $^ -o $@

$(OUTDIR)/mymalloc.o : mymalloc.c
	$(COMPILE.c) $(C_DEFINE) $(CFLAGS) -c $?
	mv *.o $(OUTDIR)

.PHONY: clean

clean : 
	rm -rf $(OUTDIR) main