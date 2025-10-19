# Typing Speed and Accuracy Test version 2

This is a simple console-based typing test program written in C. It generates a random paragraph by combining sentences read from a text file. Users type the paragraph as quickly and accurately as possible. The program then calculates typing speed (words per minute) and accuracy percentage also shows how many and which charachter is missed typed

---

## Features

- Reads sentences from a `sentences.txt` file
- Allows user to select the number of sentences for the test
- Measures typing speed in Words Per Minute (WPM)
- Calculates typing accuracy
- Shows which charachter is missed typed
- Handles input with spaces, tabs, and newlines gracefully

---

## Requirements

- GCC compiler (or any standard C compiler)
- Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`, `time.h`, `ctype.h`)

---

## How to Compile and Run

1. Open a terminal in your project directory.(Run this in VS Code Terminal, Git Bash, or Windows Terminal for best color support.)
2. Compile the program using GCC:

   ```bash
   gcc typing_test_V3.c -o typing_test
3. Make sure your `sentences.txt` file is in the same directory as the executable.
4. Run the program:
    ```bash
    ./typing_test_V3

---

## How to Compile and Run

1. When prompted, enter the number of sentences you want in your typing test.
2. The program will display a paragraph made of randomly selected sentences.
3. Type the paragraph exactly as shown and press Enter.
4. The program will display:
    - Number of words typed
    - Time taken in seconds
    - Typing speed in Words Per Minute (WPM)
    - Typing accuracy percentage

---

## Example Output

    ```bash
    Give how many sentences type test want to do: 2
    Type given Para fast:
    Jumpy Fred boxed a dozen hazy jugs for the wizard queen Zippy wizards help Jack fix broken quaint magic boxes
    Press any key to Start: 
    Your input here...
    =================== Result ===================
    Words is: 20
    Time is: 33.00 sec
    Your speed is: 36.36 WPM
    Your accuracy is: 95.41 %
    Your Mistakes:
        "J": 1
        "e": 1
        "m": 1
        "u": 1
        "z": 1
    
    ==============================================

---

## Notes and limitations
- Input paragraph length limited to 1000 characters, extend it if you want.
- Sentences read up to 200 lines from the input file, extend it if you want
- It has only one type of typing test mode

---

## Version 3 changes
- Now it measure charachter lively accurate accuracy and red color for wrong and green for right entry also backspace support
- Probelm of accedentl new line charachter or missed press enter finish test is solvevd

---

## Author

Megh Bhut
Email: meghbhut90@gmail.com