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

&nbsp;

# **Getting Started**
## Run Your First YUlanG Program
```
yug "Hello Butterflies" likhna hai
```
Output:
``` 
"Hello Butterflies" 
```
---

## 1. Variable, Numbers and Strings
### 1.1 Variable
- A ```variable``` is a location in memory where we store data.
- At present, ```YUlanG``` supports only int and string data types.
- Variable Definiton ```arey yug a = 5 int hai```

```
yug a = 5 int hai
yug b = "Hello Titli" string hai;
```
---
### 1.2 Number
YUlanG, at present, only support ```int``` data type.
> Note: we are working on other data types.

&nbsp;

```int``` Data type:
```
arey yug a = 5 int hai
```

---
### 1.3 String
YUlanG supports strings. String is a sequence of characters;

```string``` Data type:
```
arey yug a = "Hello Titli" string hai
```
---

## 2. Control Flow
### 2.1 If, Else
Structure of if condition:
```
yug agar (condition) hai to {
  do something
}
```
```
yug agar (5 < 7) hai to {
  yug "Hello Titli" likhna
}
```
```
"Hello Titli"
```

&nbsp;

Structure of If-Else condition:
```
yug agar (condition) hai to {
  do something
} nahi to {
  do something
}
```
```
yug a = 5 int hai

yug agar (a%2 == 0) hai to {
  yug "Even" likhna hai
} nahi to {
  yug "Odd" likhna hai
}
```
```
"Odd"
```

### 2.2 For loop
For loop is used to iterate.

Structure of for loop:
```
yug i ko [start] se [end] tak lejana hai {
  do something
} 
```
```
yug i ko 0 se 5 tak lejana hai {
  yug i likhna hai
}
```
```
0
1
2
3
4
```

```
yug i = 5 int hai

yug i ko 8 tak le jana hai {
  yug i likhna hai
}
```
```
5
6
7
```