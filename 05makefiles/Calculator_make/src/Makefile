IDIR=../include
OUTDIR=../out
CC=gcc
CFLAGS=-I$(IDIR)
_OUT=calculator
ODIR=obj

_DEPS=cal.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o calculator.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

OUT=$(patsubst %,$(OUTDIR)/%,$(_OUT))

$(ODIR)/%.o:%.c $(DEPS)
	cc -o $@ -c $< $(CFLAGS)
$(OUT):$(OBJ)
	cc -o $@ $^ $(CFLAGS)
	


help:
	@echo $(IDIR)
	@echo $(DEPS)	
	@echo $(OBJ)
	@echo $(OUT)

