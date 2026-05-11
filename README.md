# get_next_line

*This project has been created as part of the 42 curriculum by jperez-u.*

---

# Description

`get_next_line` is a project from the 42 curriculum whose goal is to create a function capable of reading a file descriptor line by line.

The function must return one line each time it is called, while correctly handling memory management, file reading, buffering, and persistent data between function calls.

This implementation uses a linked list to temporarily store chunks read from the file descriptor until a newline (`\n`) or the end of the file is reached.

---

# Instructions

## Compilation

Compile using:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c -o gnl
```

You can test different buffer sizes:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 \
get_next_line.c get_next_line_utils.c main.c -o gnl
```

## Execution

Run the executable:

```bash
./gnl
```

# Algorithm Explanation

## General Idea

The project works by reading data from a file descriptor in chunks of size `BUFFER_SIZE`.

Because `read()` does not read complete lines, the implementation must accumulate partial data until a newline character (`\n`) is found.

This implementation uses a linked list where each node stores one chunk read from the file descriptor.

Example:

```txt
[ "Hel" ] -> [ "lo\nWo" ] -> NULL
```

From this data, the function extracts:

```txt
"Hello\n"
```

and preserves:

```txt
"Wo"
```

for the next function call.

---

## Reading Phase

The function `read_to_list()` repeatedly calls `read()` and appends each buffer to the linked list until a newline is found or EOF is reached.

Pseudo-flow:

```txt
read()
↓
store chunk in node
↓
append node to list
↓
stop when '\n' appears
```

---

## Extracting the Line

The function `extract_line()` traverses the linked list and copies characters into a newly allocated string until a newline is found.

This creates the final line returned by `get_next_line()`.

---

## Cleaning the List

After returning a line, the used nodes are freed.

If characters exist after the newline, they are stored in a new node as leftover data for the next function call.

Example:

Before cleaning:

```txt
[ "Hel" ] -> [ "lo\nWo" ]
```

Returned line:

```txt
"Hello\n"
```

Remaining list:

```txt
[ "Wo" ]
```

---

# Resources

## Tutorials and References

- [Linked Lists in C](https://www.geeksforgeeks.org/linked-list-set-1-introduction/?utm_source=chatgpt.com)
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/?utm_source=chatgpt.com)
- [Youtube tutorial](https://www.youtube.com/watch?v=8E9siq7apUU)
- [Notion tuto](https://suspectedoceano.notion.site/get_next_line-b3fa44d60dc24817bfd6a642183a93a0)
