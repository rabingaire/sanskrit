# Sanskrit

Sanskrit is a low level general purpose programming language

_Note: This programming language is in development phase, trying to write parser right now_

# Language Pipeline (for now)

Source Code -> Lexer -> Parser(recursive descent) -> LLVM -> Executable

.sk file -> Tokens -> AST -> .o file -> executable

# Parser implementation

Parser will be handwritten recursive descent parser, although for better understanding of parser rules I will write and add EBNF grammers rules.

# Language Syntax

Variable Declaration

```
let a: int = 10;
let b = 20;
c := 20 // this can be only done inside a function
```

Conditional

```
if true {
  // do something
}
```

```
let a = 10;
if a == 10 {
  // do something
} else if a == 20 {
  // do something
} else {
  // do something
}
```

Loops

```
for {
  // this is an infinite for loop
}
```

```
for value <= 10 {
  // this is a for loop
  value++;
}
```

```
for i := 0; i < 10; i++ {
  // this is a for loop
}
```

```
for index, number := range 10 {
  // this is a loop
}
```

Function Definition

```

fn add(a:int, b:int): int {
  return a + b;
}

```
