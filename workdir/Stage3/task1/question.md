## Build AST for flow control

- in this stage, we will be adding the flow control feature.
- we will add
    - if statements
    - if else statements
    - while loops
- extends expressions to support boolean expressions

- first task is to build AST
- we need to add few more nodes like:
    - if
    - if-else
    - while
    - ge, le, lt, gt, ne, eq, ...
- and save the type of the value in the node for semantic analysis
