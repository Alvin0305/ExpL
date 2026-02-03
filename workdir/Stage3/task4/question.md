## Break and Continue

- For proper implementation of break and continue, we need to know which is the latest loop. We need to keep track of the nesting loops.
- For this we use a data structure called Label Stack which is basically a stack which contains the info about loops.
- When we get into a loop, we push a new entry into the stack (loopConditionLabel, restOfCodeLabel). 
- When we get out of the loop, we pop the entry.

```C
typedef struct LabelStackNode {
    int loopConditionLabel;
    int restOfCodeLabel;
    struct LabelStackNode *next;
} LabelStackNode;
```

- The importance of this data structure is that, when a break or continue appears, we should be able to detect from which loop we want to break or continue. And to where we need to go.