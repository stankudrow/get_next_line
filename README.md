# get_next_line

**Reading a line on a fd is way too tedious.**

Linted according to the `norminette` v3.3.51 rules.

## GNL versions

[libftx]: https://github.com/stankudrow/libftx

### GNL_v1

The first version of GNL, score: 125.

### GNL_v2

A refinment of the GNL v1. Tested with [gnlTester](#testers). Used in the [libftx] project.

### GNL_v3_std

The result of `getline` analysis. Resulting in the following functions suitable for the [libftx]:

* `ssize_t ft_getline(char **lineptr, size_t *n, FILE *stream);`

* `ssize_t ft_getdelim(char ** lineptr, size_t *n, int delim, FILE *stream);`

"Yes" answers why to embed the aforementioned functions:

1. the ordinary `get_next_line` returns **NULL** both when the end of stream is reached and if an error occured - this is misleading, therefore error-prone;

2. the return/status code is a good way to take: either a nonnegative number of bytes consumed or a negative error code - this strategy is cleaner than one immanent to the classic `get-next-line` contract.

## Testers

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
