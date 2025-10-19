# Typing Speed and Accuracy Test version 2

This is a simple console-based typing test program written in C. It generates a random paragraph by combining sentences read from a text file. Users type the paragraph as quickly and accurately as possible. The program then calculates typing speed (words per minute) and accuracy percentage.

---

## Features

- Reads sentences from a `sentences.txt` file
- Allows user to select the number of sentences for the test
- Measures typing speed in Words Per Minute (WPM)
- Calculates typing accuracy
- Handles input with spaces, tabs, and newlines gracefully

---

## Requirements

- GCC compiler (or any standard C compiler)
- Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`, `time.h`, `ctype.h`)

---

## How to Compile and Run

1. Open a terminal or command prompt in your project directory.
2. Compile the program using GCC:

   ```bash
   gcc typing_test_V2.c -o typing_test
3. Make sure your `sentences.txt` file is in the same directory as the executable.
4. Run the program:
    ```bash
    ./typing_test_V2

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
    The wizards vault hid five quirky boxing jackals Queen Victorias jester jumped boldly on hazy fox trails
    Press any key to Start: 
    Your input here...
    =================== Result ===================
    Words is: 17
    Time is: 33.00 sec
    Your speed is: 30.91 WPM
    Your accuracy is: 87.50 %
    
    ==============================================

---

## Notes and limitations
- Input paragraph length limited to 1000 characters, extend it if you want.
- Sentences read up to 200 lines from the input file, extend it if you want
- It dont show which wrong charachter is typed.

---

## Version 2 changes
- Now it measure charachter lively accurate accuracy
- Probelm of accedentl new line charachter or missed press enter finish test is solvevd

---

## Author

Megh Bhut
Email: meghbhut90@gmail.com