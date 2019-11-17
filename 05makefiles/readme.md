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
![Dir Structure](https://github.com/Pratap2018/HITK_CSE_SoftwareToolsLab/blob/master/05makefiles/image/Screenshot%20from%202019-11-15%2019-05-29.png)

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

#### install make or cmake 

```
sudo apt-get install make
```
Alternate command
```    
sudo apt-get install cmake    
```

##### Run the makefile

GET  inside to folder src using terminal and type make and hit enter

![Run Make](https://github.com/Pratap2018/HITK_CSE_SoftwareToolsLab/blob/master/05makefiles/image/Screenshot%20from%202019-11-15%2019-27-15.png)

