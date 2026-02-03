### Adding Functions

- In this stage, we will be adding functions
    - First we need to update the grammar
        - Add function declarations, function definitions, arg lists, param list, param, etc
    - Then, Update the AST for these new grammar
    - Then, Update the GST to allow the insertion of functions in it.
        - Add functionLabel, args to GSymbol
    - Create Local Symbol Table for keeping local variables
        - Populate LST while parsing the AST
    - Do semantic analysis
        - does the function definition and function declaration match
        - does all function calls map to a function with same signature
            - signature refers to both name and type match in expl
        - return type matches with the declaration
    - Code generation
        - Generate code for the function along with the label for the function like $F_i$
        - On function calls, build the Activation Record of the callee by pushing needed registers, base pointers, etc.
    - Update the label lexer to handle Function Labels also.

