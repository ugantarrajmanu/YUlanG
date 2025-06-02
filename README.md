# YUlanG
A Toy Programming language

**YUlanG** is a interpreted Esoteric Programming Language. 

+ It uses **` FLEX `** lexer for finding lexeme and token. 

+ It uses **` BISON `** parser for generating annotated parser tree and then evaluating line by line (interpreter).

## What is an Interpreter?
An interpreter is a program that converts the High Level Language like Python, JavaScript, etc to machine readable language i.e. Low Level Language. 

The interpreter reads and evaluate the program in High Level Language line by line. Therefore it runs the program to the line where error is therre.

For Example,

Lets take Python for example:
```
n = 5
print("n -> ", n)
u = 7
print("u -> ", u)
prit("n+u -> ", n+u)
```
This program give output:
```
n ->  5
u ->  7
ERROR!
Traceback (most recent call last):
  File "<main.py>", line 5, in <module>
NameError: name 'prit' is not defined. Did you mean: 'print'?
```

This helps in easy debugging but is slower as compared to compiler.