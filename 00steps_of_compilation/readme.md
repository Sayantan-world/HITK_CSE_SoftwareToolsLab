# Steps of Compilation (in Linux-detailed)
![Tree](https://github.com/Sayantan-world/HITK_CSE_SoftwareToolsLab/blob/master/00steps_of_compilation/img1.jpg?raw=true)
---

## Follow the steps --
---

View the source code in code.c
```
#include <stdio.h>
#define MAX 30
#define MIN 5
int main(){
        int x;
        x = MAX + MIN;
        printf("RESULT: %d\n",x);
        return 0;
}

```
---

### Preprocessing
---
- Source Code -> Preprocessed Code
```
gcc -E code.c > code.i
```
Generates code.i

---

### Compiling
---
- Preprocessed Code -> Assembly Code
```
gcc -S code.i
```
Generates code.s

---

### Assembling
---
- Assembly Code -> Object Code
```
gcc -c code.i -o code.o
```
OR
```
as code.s -o code.o
```
Generates code.o

---

### Linking
---
- Object Code -> Executable Code
```
gcc -o code code.o
```
Generates code (executable file)

---
