# CPP_CustomInterpreter
This project is part of a hunt and contains code files available in `files` which should be interpreted. The task was to start with start.txt and given some criteria interpret it. After the file had been interpreted the solution would be another file name. This process kept looping untill the solution wasn't a file.

The correct order and final solution can be found below.

1. `start.txt`
2. `aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.txt`
3. `4812-9-6727.txt`
4. `AasHgsho.txt`
5. `Bososen-hosgen-in-warme-losden-aos-de-bososenboom.txt`
6. `we-zijn-er-bijna.txt`
7. `ninaf-zvabe-fjn-pcc1.txt`

Final solution: 
```
Real stupidity beats artificial intelligence every time.
                                      -- Terry Pratchett
```

## Prerequisites
- CMake >= 3.17
- C++ compiler
- [optional] valgrind (for testing leak detections)

## Getting started
1. Clone this repository.
2. Open the project with your ide of choice.
3. Modify main.cpp to use a valid starting baseUrl and endpoint.
4. Run the program and retrieve the solution 🔍:shipit:.

## Leak detection
Run leak detection on MacOS Catalina with [valgrind](https://valgrind.org/) using the command;
`valgrind --leak-check=yes --suppressions=darwin-19.supp out/debug/<project-name>`

## Author
- [Tjeu Foolen](https://github.com/tjeufoolen)