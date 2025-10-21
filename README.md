# Typing Speed and Accuracy Test version 4

This is a simple console-based typing test program written in C. It generates a random paragraph by combining sentences read from a text file. Users type the paragraph as quickly and accurately as possible. The program then calculates typing speed (words per minute) and accuracy percentage also shows how many and which charachter is missed typed, and graph detail of where speed drops and which second you miss typed

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
- Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`, `time.h`, `ctype.h`, `conio.h`, `math.h`)

---

## How to Compile and Run

1. Open a terminal in your project directory.(Run this in VS Code Terminal, Git Bash, or Windows Terminal for best color support.)
2. Compile the program using GCC:

   ```bash
   gcc typing_test_V4.c -o typing_test_V4
   ```

3. Make sure your `sentences.txt` file is in the same directory as the executable.
4. Run the program:
   ```bash
   ./typing_test_V4
   ```

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
   - Which character is missd type
   - Every second graphical analysis

---

## Example Output

    ```bash
    Give how many sentences type test want to do: 1
    Type given Para fast:
    The quick brown fox jumps over the lazy dog
    Press any key to Start:
    Your input here...
    =================== Result ===================
    No of Words is: 11

    Total time taken is: 21.00 sec
    Your speed is: 31.43 WPM , max speed is: 60

    WPM speed
    63 |
    62 |
    61 |
    60 |    #
    59 |    #
    58 |    #
    57 |    #
    56 |    #
    55 |    #
    54 |    #
    53 |    #
    52 |    #
    51 |    #
    50 |    #
    49 |    #
    48 |    #
    47 |    #
    46 |    #
    45 |    #
    44 |    #
    43 |    #
    42 |    #
    41 |    #
    40 |    #
    39 |    #
    38 |    #
    37 |    #
    36 |    #
    35 |    #                                                  #       
    34 |    #                                                  # 
    33 |    #                                               #  #  #
    32 |    #                                      #     #  #  #  #
    31 |    #                                      #     #  #  #  #  #
    30 |    #                                   #  #  #  #  #  #  #  #
    29 |    #                                   #  #  #  #  #  #  #  #
    28 |    #                                #  #  #  #  #  #  #  #  # 
    27 |    #                    #           #  #  #  #  #  #  #  #  #
    26 |    #                    #           #  #  #  #  #  #  #  #  #
    25 |    #                    #        #  #  #  #  #  #  #  #  #  #
    24 |    #        #           #  #     #  #  #  #  #  #  #  #  #  #
    23 |    #        #        #  #  #     #  #  #  #  #  #  #  #  #  #
    22 |    #        #        #  #  #  #  #  #  #  #  #  #  #  #  #  #
    21 |    #        #        #  #  #  #  #  #  #  #  #  #  #  #  #  #
    20 |    #  #     #  #     #  #  #  #  #  #  #  #  #  #  #  #  #  #
    19 |    #  #     #  #     #  #  #  #  #  #  #  #  #  #  #  #  #  #
    18 |    #  #     #  #     #  #  #  #  #  #  #  #  #  #  #  #  #  #
    17 |    #  #     #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    16 |    #  #     #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
       ---   ---------------------------------------------------------------
            2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21

    Your accuracy is: 95.41 %
    Your Mistakes:
        "J": 1
        "e": 1
        "m": 1
        "u": 1
        "z": 1
    ==============================================
    ```

---

## Notes and limitations

- Input paragraph length limited to 1000 characters, extend it if you want.
- Sentences read up to 200 lines from the input file, extend it if you want
- It has only one type of typing test mode

---

## Version 4 changes

- Now graphical analysis is open we have every second graphical speed and mistakes

---

## Author

Megh Bhut
Email: meghbhut90@gmail.com
