/*
 * Typing Speed and Accuracy Test Program version 2
 * --------------------------------------
 * Author: Megh Bhut
 * Date: 2025-10-22
 * --------------------------------------
 * Description:
 * This program reads sentences from a text file and generates
 * a random paragraph composed of user-specified number of sentences.
 * The user types the paragraph, and the program calculates
 * typing speed in words per minute (WPM) and accuracy percentage.
 * shows missed typed words
 * shows graph detail of every second where speed drops and mistake is made.
 *
 * Usage:
 * Compile: gcc typing_test_V4.c -o typing_test_V4
 * Run: ./typing_test_V4
 *
 * Inputs:
 * - Number of sentences to include in the typing test
 * - User's typed paragraph geen text is corrected and red will be wrong
 *
 * Outputs:
 * - Words typed
 * - Time taken
 * - Typing speed (WPM)
 * - Accuracy percentage
 * - Which charachter is miss typed
 * - Graph detail of where is misstyped and where speed drops
 *
 * Limitations:
 * - Input paragraph length limited to 1000 characters, extend it if you want.
 * - Sentences read up to 200 lines from the input file, extend it if you want
 * - Only one mode of typing test
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>

#define MAX_SENTENCES 200
#define MAX_PARAGRAPH_LENGTH 1000
#define MAX_LINE_LENGTH 300
#define MAX_USER_INPUT 1000
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

int no_of_words(int letters_typed, char *para)
{
    int is_inside_word = 0, Words = 0;
    for (int i = 0; i < letters_typed; i++)
    {
        if (isspace(para[i]))
        {
            is_inside_word = 0;
        }
        else if (!is_inside_word)
        {
            is_inside_word = 1;
            Words++;
        }
    }
    return Words;
}

int arry_highest(int range, int *data)
{
    int max = 1;
    for (int i = 0; i < range; i++)
    {
        if (max < data[i] && data[i] > 1)
        {
            max = data[i];
        }
    }
    return max;
}
int arry_lowest(int range, int *data)
{
    int min = 400;
    for (int i = 0; i < range; i++)
    {
        if (min > data[i] && data[i] > 1)
        {
            min = data[i];
        }
    }
    return min;
}

int main()
{
    // declaring file
    FILE *file = fopen("sentences.txt", "r");
    /// declaring variable
    char *sentences[MAX_SENTENCES];
    char paragraph[MAX_PARAGRAPH_LENGTH] = "";
    char line[MAX_LINE_LENGTH];
    // reading sentences and first storing them in line
    int sentences_read = 0;
    while (fgets(line, MAX_SENTENCES, file) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        // now making a enough space for line using malloc and giving this addres to sentences[i]
        sentences[sentences_read] = malloc(strlen(line) + 1);
        if (sentences[sentences_read] != NULL) // checking if malloc cant get enough space
        {
            // writing line on that address we stored
            strcpy(sentences[sentences_read], line);
            sentences_read++; // updating sentences read evrytime it stored in given position
        }
    }
    fclose(file);

    srand(time(NULL)); // giving unique seed.

    // asking user inputs for number of sentences
    int No_Of_Sentences;
    printf("Give how many sentances type test want to do: ");
    scanf("%d", &No_Of_Sentences);
    // genrating a paragraph from 5 random sentances
    for (int i = 0; i < No_Of_Sentences; i++) // running loop No_Of_Sentences times
    {
        strcat(paragraph, sentences[rand() % sentences_read]); // using rand()%sentences_read to get random number btw 0 to sentences_read
        if (i != No_Of_Sentences - 1)                          // checking last part should not be white space
        {
            strcat(paragraph, " "); // giving white space after every sentences
        }
    }

    // starting user input
    printf("Type given Para fast: \n");
    printf("%s", paragraph); // givining on screen para
    printf("\nPress any key to Start: \n");
    getch(); // buffer clear
    int typed_char = 0, mistakes = 0;
    int mistake_freq[256] = {0}; // defining misstake freq here unsiged charachter so 1-256 represent charchters
    int mistake_time[300] = {0};
    int per_second_speed[300] = {0};
    int last_recorded_second = -1;
    time_t current_time;
    time_t start_time = time(NULL); // starting time
    while (1)
    {
        char user_input = getch(); // taking input
        current_time = time(NULL);
        int elapsed_sec = (int)difftime(current_time, start_time);

        if (user_input == 8 || user_input == 127) // here 8 and 127 are backspaces
        {
            if (typed_char > 0)
            {
                typed_char--;
                printf("\b \b"); // \b shifts cursor back ' ' will erase charchter and \b again to back cursor
            }
            continue; // skipping loop
        }
        if (user_input == paragraph[typed_char]) // if input matched paragraph
        {
            printf(GREEN "%c" RESET, user_input); // print it with green color
        }
        else
        {
            printf(RED "%c" RESET, user_input); // else print it with red color
            mistakes++;                         // adding mistake
            mistake_time[elapsed_sec]++;
            mistake_freq[(unsigned char)paragraph[typed_char]]++; // increasing mistake freq by one.
        }
        
        if (elapsed_sec != last_recorded_second && elapsed_sec < 300)
        {
            if (elapsed_sec == 0 || elapsed_sec == 1)
            {
                typed_char++;
                continue;
            } // skip first second
            per_second_speed[elapsed_sec] = round((float)no_of_words(typed_char, paragraph) / ((float)elapsed_sec / 60));
            last_recorded_second = elapsed_sec;
        }
        typed_char++;
        if (typed_char == strlen(paragraph)) // if paragraph finish break loop
        {
            break;
        }
    }
    time_t end_time = time(NULL); // ending time

    double time_taken_min = (double)difftime(end_time, start_time) / 60;    // taking duration of time
    double accuracy = ((double)(typed_char - mistakes) / typed_char) * 100; // measuring accuracy

    // checking no of words in this paragraph
    int No_of_Words = no_of_words(typed_char, paragraph);
    // measuring speed
    double speed = (double)No_of_Words / time_taken_min;
    // printing final results
    printf("\n=================== Result ===================\n");
    printf("No of Words is: %d \n", No_of_Words);
    printf("Total time taken is: %.2f sec \n", time_taken_min * 60);
    int y_max_speed = arry_highest(round(time_taken_min * 60), per_second_speed);
    int y_min_speed = arry_lowest(round(time_taken_min * 60), per_second_speed);
    printf("Your speed is: %.2f WPM , max speed is: %d\n", speed, y_max_speed);
    printf("\nWPM speed\n");
    for (int i = 0; i <= y_max_speed - y_min_speed + 5; i++)
    {
        for (int j = 0; j < round(time_taken_min * 60) + 1; j++)
        {
            if (j == 0 && i < y_max_speed - y_min_speed + 3)
            {
                printf("%-2d |", y_max_speed + 3 - i);
            }
            else if (y_max_speed + 2 - i >= per_second_speed[j])
            {
                printf("   ");
            }
            else
            {
                if (i < y_max_speed - y_min_speed + 3)
                {
                    if (mistake_time[j]>0)
                    {
                        printf(RED" # "RESET);
                    }
                    else
                    {
                        printf(" # ");
                    }
                }
            }
            if (i == y_max_speed - y_min_speed + 3)
            {
                printf("---");
            }
            if (i == y_max_speed - y_min_speed + 4)
            {
                if (j > 1)
                {
                    printf("%-3d", j);
                }
                else
                {
                    printf(" ");
                }
                if(j>round(time_taken_min * 60))
                {
                    printf("(Seconds)");
                }
            }
        }
        printf("\n");
    }
    printf("Your accuracy is: %.2f %% \n", accuracy);
    printf("Your Mistakes: \n");
    for (int i = 0; i < 256; i++)
    {
        if (mistake_freq[i] > 0)
        {
            if (i == ' ')
            {
                printf("\tspaces(' '): %d\n", mistake_freq[i]);
            }
            else if (i == '\n')
            {
                printf("\tnewline(Enter): %d\n", mistake_freq[i]);
            }
            else
            {
                printf("\t\"%c\": %d\n", i, mistake_freq[i]);
            }
        }
    }
    printf("\n==============================================\n");

    // freeing space
    for (int i = 0; i < sentences_read; i++)
    {
        free(sentences[i]);
    }
    return 0;
}