# C Data Structures

A set of generic data structure implementations in C, for use in other C
projects. When needed, void pointers are used to allow for generic usage. This
decision was made for the sake of both simplicity and ease-of-use
(for more info about the tradeoffs between void pointers and macros, see
[this StackOverflow thread](https://stackoverflow.com/questions/31867369/void-as-generic-in-c-is-it-safe)).

## Getting Started
This repo uses `make` as its build system, `gcc` as its compiler, and in general
it follows the C17 language standard.

```bash
# Clone the repo
git clone https://github.com/jkmuriithi/c-data-structures.git

# Enter repo directory
cd c-data-structures

# Build test executables
make
```

### Windows compatibility
Windows users without `gcc` or `make` can obtain both via [MinGW](https://www.mingw-w64.org/) and
[Chocolatey](https://community.chocolatey.org/). After installing Chocolately, simply call `choco install make mingw`.

## Working Implementations
- Stack
## Planned Implementations
- Queue
- List (Dynamic Array)
- Union-Find-Delete (for unsigned long operations)
- Priority Queue
- Hash Table
- Hash Set
- Trie (for char operations)


