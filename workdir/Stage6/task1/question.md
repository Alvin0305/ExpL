## Frontend for User Defined Types

- Update the parser.y to support declaration and usage of user defined types
- Create and populate `TypeTable` for keeping the type info of user defined type
- Before populating user defined types in `TypeTable`, populate primitive types
    - int
    - string
    - void
    - bool
