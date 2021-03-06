<p align="center">
    <a href="#">
        <img src="assets/logo.png" height="70" alt="Ceres - The S3MC language">
    </a>
</p>

<p align="center">
    <a href="#">
    <img src="https://img.shields.io/github/repo-size/gustavoale/ceres-lang?style=for-the-badge"
    style="max-width:100%;" alt="Repo size">
    </a>
    <a href="/LICENSE">
        <img src="https://img.shields.io/github/license/gustavoale/ceres-lang?style=for-the-badge" style="max-width:100%;" alt="Repo size">
    </a>
    <a href="#">
    <img src="https://img.shields.io/github/last-commit/gustavoale/ceres-lang?style=for-the-badge" style="max-width:100%;" alt="Repo size">
    </a>
</p>

---
## Development

**Ceres is not done yet, please refer to [Homemade Bread](https://github.com/GustavoAle/ceres-lang/tree/homemade-bread) as the development branch**

## Brief
Ceres is a semi-oop simple programming language targeting new RISC based
processors and custom architectures.  
It's main goal is to avoid the use of assembly and machine code during the
development and testing of the S3MC processors. This goal will be gradually
extended to provide a high-level language for new RISC based processors since LLVM
and other compiler toolchains are relatively hard to work with.

## Development
### Basic things
- [ ] Lexer based on Lex/Flex
- [ ] Parser based on Yacc/Bison
- [x] AST
- [x] Generic BST
- [ ] Symbols table
- [ ] Intermediate code generation
- [ ] Error handling
- [ ] Code generation for RISC-V targets

### Advanced things
- [ ] Semi-oop implementation
- [ ] Custom Lexer and Parser
- [ ] Code generation for user-defined targets 

## Documentation
### Usage, syntax and language related info.
Please refer to [Ceres Documentation](https://gustavoale.github.io/ceres-lang-doc/site/)
for documentation, examples and further information.

### New ports
How to port to a new architecture?  
I'm working on a guide on how to add a new port, since Ceres is built on that premise.

---
## Author

* Author: Gustavo Ale
* GitHub: https://github.com/GustavoAle
* Email: gustavo.engca@gmail.com

## Credits

* Tom Niemann - [Lex & Yacc tutorial](https://www.epaperpress.com/lexandyacc/).
The first versions of the lexer and parser are strongly based on Niemann's
examples presented in the book.
