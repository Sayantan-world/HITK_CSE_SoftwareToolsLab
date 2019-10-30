# Static Library (Linux guide)
---
Read the __[guide](https://www.geeksforgeeks.org/static-vs-dynamic-libraries/)__

Static Libraries contain object code linked with an end user  application and then they become the part of the executable at compilation time.

The steps are as follows:

- Downolad the files add.c,   add.h,   sub.c,   sub.h and driver.c
- go to the location of the downloaded files using terminal.
- Type this (Object code creation)
```
gcc -c add.c -o add.o
```
```
gcc -c sub.c -o sub.o
```
- Now type
```
ar rcs anyname.a add.o sub.o
```
ar-archive<br><br>
rcs-replace create save<br><br>
anyname.a - you can use any name u want to give it and .a extension shows its a static lib<br>
- Indexing is done using
```
ranlib anyname.a
```
-Now type
```
gcc driver.c -o driver -L. anyname.a
```
-L - tells the location of library then dot represents current working directory
- Finally run the code
```
./driver
```
