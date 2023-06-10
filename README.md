#  Competitive Programming C++

This repository contains my solutions to various competitive programming problems from Codeforces and Timus, as well as other items which I use for my environment.


## Directories
Completed stores all the solutions I have done with the names such as "4a.cpp" for the solution to the problem 4A on codeforces.    
Othercompleted stores other solutions to problems outside of codeforces.  
Failedapproaches stores interesting approaches I tried but either gave up on or they do not work.   
Timus contains timus problems (notice that in addition to the problem number, 't' is the prefix).   
Libraries stores some classes and such which I have to frequently use like bigint. I'll get around to turning them into headers and automating submission sometime.   



## Bash files

Presently there are 5 bash files I wrote (with a bit of help from ChatGPT of course):  
ed - creates and edits contest files using neovim (-n to not run the file).  
sb - submits solutions using the cf client and just regular curl for timus (-n to check if solution was accepted in timus).  
db - debugs files using gdb.  
cl - moves the to a completed directory and cleans the .stor directory
dsp - displays the problem statement for cf as well as initializes input/output files using python with BeautifulSoup4.  
tst - uses the input/output files to test with the sample test cases in the problem statement in cf.   

