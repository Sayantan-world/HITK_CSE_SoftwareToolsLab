# Dynamic Library or Shared Library
---

Read this __[guide](https://www.geeksforgeeks.org/working-with-shared-libraries-set-2/)__

### Follow the steps : 

- Download both the folders (libs and progs) [keep the .c files only and delete others]
- Use terminal to open the libs folder and do the following
```
gcc -c -fPIC fact.c -o fact.o
```
This generates the fact.o file
```
gcc -shared -o libanyname.so fact.o
```
This generates the libanyname.so.o file<br><br>
__lib__ anyname __.so__ -- Here lib and .so is very important u can name ur library anyrhing but do note to keep them intact
- Now come out of that dir and go to progs using
```
cd ../Progs
```
- Open a new terminal(2) and direct it to libs folder and then type __pwd__ , it shows u the location of libs folder in ur machine
- In terminal(1) type this
```
gcc driver.c -o driver -lanyname -L [copy paste the whole path that was shown in terminal(2)]
```
make sure to use inverted commas if u have space in ur path (folder name) <br><br>
for example if u have a folder named as __MY FOLDER__ use '__MY FOLDER__' in ur path
- Now export ur lib path using
```
export LD_LIBRARY_PATH=[copy paste the whole path that was shown in terminal(2)]
```
- Now run the code using
```
./driver
```
