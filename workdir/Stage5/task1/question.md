### Populate GST

- Update the grammar to handle global function declarations
    - Add attributes functionLabel, paramList
    - paramList -> { type, name, next }
- Populate the GST on parsing the AST
- Do basic semantic check like: 
    - No two functions or variables should have the same name