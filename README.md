# Typing Speed and Accuracy Test

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
   gcc typing_test_V1.c -o typing_test
3. Make sure your `sentences.txt` file is in the same directory as the executable.
4. Run the program:
    ```bash
    ./typing_test_V1

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
    Give how many sentences type test want to do: 3
    Type given Para fast:
    The quick brown fox jumps over the lazy dog The early bird catches the worm A journey of a thousand miles begins with a single  step
    Start
    Your input here...
    =================== Result ===================
    Words is: 22
    Time is: 39.00 sec
    Your speed is: 33.80 WPM
    Your accuracy is: 99.10 %
    
    ==============================================

---

## Notes and limitations
- Input paragraph length limited to 1000 characters, extend it if you want.
- Sentences read up to 200 lines from the input file, extend it if you want
- Can be somethimes incompelte as it dont measure live typed word some mistakes
  while writing paragraph not count in mistakes while accuracy checking.
- Other thing if some letter is missed typed double times then whole part
  after that will be given wrong.

---

## Author

Megh Bhut
Email: meghbhut90@gmail.com