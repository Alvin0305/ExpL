## Code generation

- allow code generation in the updated grammar
- make sure we set the SP to 4096 + 26
    - because the first 26 memory locations are reserved for variables in this stage
- traverse the AST build in last task and generate code on the go
