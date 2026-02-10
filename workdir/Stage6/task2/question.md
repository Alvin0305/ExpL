## Update library.lib for heapset, alloc and free

- currently library.lib file contains only code for:
    - read
    - write
    - exit
- now we add:
    - heap set -> initialize
    - alloc -> takes size as input
    - free -> frees the block
- update the code gen function for handling:
    - user type field access 
    - user type field assignment
