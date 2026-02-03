### Build LST and Code generation

#### Build LST

- Populate LST on parsing the local declarations block in each function.
- For each variable, check the LST first and then the GST
- address of the local variables will be $BP + x$, where BP value will be available only on runtime, so we will just save the x value (offset from BP, starts from 0 for each function) in the binding field of a LST entry.
- Do semantic analysis
    - Variable redeclaration
    - Type mismatch

#### Code generation

- We should generate the function code while parsing the AST for function itself. And after the function's sub tree is parsed, it can be freed.
    - On parsing the global function declarations, we set the functionLabels for each of the function. 
    - Using these functionLabels and the body of the functions (from the AST), we generate the code for each function
- Now, for function calls, the caller need to create the activation record for the callee. 

##### Caller's Work

- Save Registers in the stack for restoring after callee return
- Evaluate the arguments
- Pushes the arguments in reverse order
- Reserve a space for return value
- write CALL $F_i$ (pushes $IP + 2$ to the stack and transfers control to $F_i$)

##### Callee's Work

- Push Old BP to the stack for restoring after callee return
- 