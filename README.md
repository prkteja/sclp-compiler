# sclp-compiler
<pre>
Usage: sclp [options] [file]
                        Options:
                        -help     Show this help
                        -sa-scan  Stop after scanning
                        -sa-parse Stop after parsing
                        -sa-ast   Stop after constructing Abstract Syntac Tree (AST)
                        -sa-tac   Stop after constructing Three Address Code (TAC)
                        -sa-rtl   Stop after constructing Register Transfer Language (RTL) code
                        -tokens   Show the tokens in file.toks (or out.toks)
                        -ast      Show abstract syntax trees in file.ast (or out.ast)
                        -tac      Show the Three Address Code in file.tac (or out.tac)
                        -rtl      Show the Register Transfer Language code in file.rtl (or out.rtl)
                        -symtab   Show the symbol table of delcarations in file.sy, (or out.sym)
                        -d        Demo version. Use stdout for the outputs instead of files
</pre>
Reference: <https://www.cse.iitb.ac.in/~uday/sclp-web/>
