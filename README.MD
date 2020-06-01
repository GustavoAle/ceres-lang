```
          ________  ________  _____
         / ___/ _ \/ ___/ _ \/ ___/
        / /__/  __/ /  /  __(__  ) 
        \___/\___/_/   \___/____/  
```                         
## Brief
Ceres is a semi-oop simple programming language targeting the S3MC RISC 
processor. It's main goal is to avoid the use of assembly and machine code 
during the development and testing of the S3MC processors and therefore helping 
the benchmarking of the HIPM pipeline model. 

## Examples
### Hello world 
Since the S3MC processor currently run on a FPGA the basic input and output is 
given by the serial port.
```
#extern {
    "serial.cr"
}

sub main()
{
    /*init serial with 115200 bps*/
    IO.init(115200)

    IO.print("hello world\n")
}
```


### Fibonacci
```
...

fun fib(n)
{
    if(n == 1 or n == 2)
    {
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

...
```

---
## Author

* Author: Gustavo Ale
* GitHub: https://github.com/GustavoAle
* Email: gustavo.engca@gmail.com

## Credits

* Tom Niemann - [Lex & Yacc tutorial](https://www.epaperpress.com/lexandyacc/). 
The first versions of the lexer and parser are strongly based on Niemann's 
examples presented in the book.
