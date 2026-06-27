*This project has been created as part of the 42 curriculum by rzenteno.*

# get_next_line

## Description

`get_next_line` is a project from the 42 curriculum whose objective is to implement a function capable of reading a file descriptor one line at a time.

Unlike a traditional file reader, the function must preserve its reading state between successive calls, allowing it to continue exactly where it previously stopped. This behavior must work independently of the chosen `BUFFER_SIZE`, correctly handling files of any size, lines longer than the buffer, and dynamic memory management.

The function prototype is:

```c
char *get_next_line(int fd);
```

Each call returns:

* The next available line from the file descriptor.
* The newline character (`\n`) when it belongs to the returned line.
* `NULL` when the end of the file has been reached or an error occurs.

---

# Instructions

## Compilation

Compile the mandatory version with:

```bash
cc -Wall -Wextra -Werror \
get_next_line.c get_next_line_utils.c \
-D BUFFER_SIZE=42
```

Compile the bonus version with:

```bash
cc -Wall -Wextra -Werror \
get_next_line_bonus.c get_next_line_utils_bonus.c \
-D BUFFER_SIZE=42
```

`BUFFER_SIZE` may be replaced with any positive integer.

Examples:

```bash
-D BUFFER_SIZE=1
-D BUFFER_SIZE=42
-D BUFFER_SIZE=1024
```

---

## Usage

The function is intended to be called repeatedly until it returns `NULL`.

Example:

```c
int fd = open("text.txt", O_RDONLY);

char *line;

while ((line = get_next_line(fd)))
{
	printf("%s", line);
	free(line);
}

close(fd);
```

---

# Algorithm

The implementation is based on a **static stash**, which stores the unread portion of the file between function calls.

The algorithm is divided into four steps.

## 1. Read

A temporary buffer of size `BUFFER_SIZE + 1` is allocated.

The function repeatedly calls `read()` until one of the following conditions is met:

* a newline (`\n`) is found,
* the end of the file is reached,
* or a read error occurs.

Each successful read stores new data inside the temporary buffer.

---

## 2. Accumulate

Every chunk read from the file is appended to the current stash using a string concatenation function.

For example, with:

```
BUFFER_SIZE = 4
```

and the file:

```
Hello World\n
```

the reads are:

```
Hell
o Wo
rld\n
```

which progressively build:

```
Hell
Hello Wo
Hello World\n
```

The stash therefore always contains every unread character.

---

## 3. Extract the next line

Once a newline exists inside the stash (or EOF has been reached), the function extracts the next complete line.

The returned string contains:

* every character from the beginning of the stash,
* including the newline when present.

For example:

```
stash

Hello World\nRemaining text...
```

returns

```
Hello World\n
```

---

## 4. Preserve the remaining data

After returning one line, the consumed part of the stash is removed.

Only the unread fragment is kept for the next call.

Example:

Before extraction:

```
Hello World\nRemaining text
```

After extraction:

```
Remaining text
```

On the next invocation, reading continues from this remaining data before requesting additional bytes from the file.

If no characters remain, the stash is freed and the function returns `NULL` on subsequent calls.

---

# Bonus

The bonus version extends the mandatory implementation while respecting the project constraint of using **only one static variable**.

Instead of storing a single stash, one independent stash is maintained for every file descriptor.

Conceptually:

```
stash[3] -> remaining data of fd 3

stash[4] -> remaining data of fd 4

stash[5] -> remaining data of fd 5
```

This allows calls such as:

```
get_next_line(fd3);
get_next_line(fd4);
get_next_line(fd5);
get_next_line(fd3);
get_next_line(fd4);
```

without losing the reading state of any descriptor or mixing data between files.

The bonus implementation is contained in:

```
get_next_line_bonus.c
get_next_line_bonus.h
get_next_line_utils_bonus.c
```

---

# Project Structure

Mandatory:

```
get_next_line.c
get_next_line_utils.c
get_next_line.h
```

Bonus:

```
get_next_line_bonus.c
get_next_line_bonus.h
get_next_line_utils_bonus.c
```

---

# Resources

Useful references:

* `man 2 read`
* `man 2 open`
* `man 3 malloc`
* `man 3 free`
* `man 3 strchr`
* Linux Programmer's Manual
* The official 42 get_next_line subject
* C standard library documentation

## AI Usage

Artificial Intelligence was used only as a supporting tool for:

* reviewing the README structure,
* improving technical explanations,
* verifying documentation completeness,
* proofreading English grammar and wording.
