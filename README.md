# unixutils
This repo our implementation of a few unix utilities:
- cat
- grep
## Compiling
To compile the files type `make` in your unix shell
## Usage
### my-cat
To use the program, run `./my-cat <filename>` in your unix shell in the root of the folder. If multiple filenames are passed (e.g. `./my-cat <filename 1> <filename 2> <filename 3>`), the program will read them all in order, one by one. Filenames are separated with space.
### my-grep
Usage is similar to my-cat. Just type `./my-grep <search term> <filename>`, and my-grep will find the lines containing the search term from the specified file for you. You can also specify multiple files, in which case you just add the filenames after the initial filename: `./my-grep <search term> <filename 1> <filename 2> ...` </br>
You can also run the program without specifying any files, in which case it will take input directly from stdin but will otherwise function similarly.