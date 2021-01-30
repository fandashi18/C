# C 编译参数
COMPILE.c := gcc
C_STANDARD := -std=gnu11
C_OPTIMIZATION := -O1
CFLAGS := $(C_STANDARD) $(C_OPTIMIZATION)

# 编译输出目录
OUTDIR := out
                                                                    
all : $(OUTDIR) main

$(OUTDIR):
	mkdir $(OUTDIR)

main : $(OUTDIR)/*.o main.c
	$(COMPILE.c) $(CFLAGS) $^ -o $@

$(OUTDIR)/%.o : insert/%.c swap/%.c
	$(COMPILE.c) $(CFLAGS) -c $?
	mv *.o $(OUTDIR)

.PHONY: clean

clean : 
	rm -rf $(OUTDIR) main