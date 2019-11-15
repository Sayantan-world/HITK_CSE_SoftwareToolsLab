# Makefiles
#### Simplist Way of code compilations .

Filename for the makefile => Makefile [✔️]
Command for running the make utility => make ][✔️] 

Syntax of makefile
```
[TARGET]:[DEPENDENCIES]
[TAB][COMMAND]
```

###### Directory Stucture for this project 
![Dir Structure](05makefiles/image/Screenshot from 2019-11-15 19-05-29.png)

:+1:

[Resources](https://www.cs.ucy.ac.cy/~tsik/Others/Programming/Tutorials/Makefiles_Tutorial.pdf)


Makefile=>
---
```
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


```