/*
 * Typing Speed and Accuracy Test Program version 2
 * --------------------------------------
 * Author: Megh Bhut
 * Date: 2025-10-19
 * --------------------------------------
 * Description:
 * This program reads sentences from a text file and generates
 * a random paragraph composed of user-specified number of sentences.
 * The user types the paragraph, and the program calculates
 * typing speed in words per minute (WPM) and accuracy percentage.
 * shows missed typed words
 *
 * Usage:
 * Compile: gcc typing_test_V3.c -o typing_test
 * Run: ./typing_test_V3
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
 *
 * Limitations:
 * - Input paragraph length limited to 1000 characters, extend it if you want.
 * - Sentences read up to 200 lines from the input file, extend it if you want
 * - Only one mode of typing test
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

# define MAX_SENTENCES 200
# define MAX_PARAGRAPH_LENGTH 1000
# define MAX_LINE_LENGTH 300
# define MAX_USER_INPUT 1000
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define RESET   "\033[0m"

int main(){
    // declaring file
    FILE *file=fopen("sentences.txt","r");
    /// declaring variable
    char *sentences[MAX_SENTENCES];
    char paragraph[MAX_PARAGRAPH_LENGTH] ="";
    char user_input[MAX_USER_INPUT];
    char line[MAX_LINE_LENGTH];
    // reading sentences and first storing them in line
    int sentences_read =0;
    while(fgets(line,MAX_SENTENCES,file)!=NULL){
        line[strcspn(line,"\n")]='\0';
        // now making a enough space for line using malloc and giving this addres to sentences[i]
        sentences[sentences_read] = malloc(strlen(line)+1);
        if (sentences[sentences_read]!=NULL) // checking if malloc cant get enough space
        {
            // writing line on that address we stored
            strcpy(sentences[sentences_read],line);
            sentences_read++; // updating sentences read evrytime it stored in given position
        }
    }
    fclose(file);

    srand(time(NULL)); // giving unique seed.

    // asking user inputs for number of sentences
    int No_Of_Sentences;
    printf("Give how many sentances type test want to do: ");
    scanf("%d",&No_Of_Sentences);
    // genrating a paragraph from 5 random sentances
    for (int i = 0; i < No_Of_Sentences; i++) // running loop No_Of_Sentences times
    {
        strcat(paragraph,sentences[rand()%sentences_read]);// using rand()%sentences_read to get random number btw 0 to sentences_read
        if(i!=No_Of_Sentences-1) // checking last part should not be white space
        {
            strcat(paragraph," "); // giving white space after every sentences
        }
    }

    // starting user input
    printf("Type given Para fast: \n");
    printf("%s",paragraph); // givining on screen para
    printf("\nPress any key to Start: \n");
    getch(); // buffer clear
    int typed_char=0,mistakes=0;
    int mistake_freq[256]={0}; // defining misstake freq here unsiged charachter so 1-256 represent charchters
    time_t start_time = time(NULL); //starting time
    while (1)
    {
        char user_input = getch(); //taking input

        if (user_input == 8 || user_input == 127) // here 8 and 127 are backspaces
        {
            if (typed_char>0)
            {
                typed_char--;
                printf("\b \b"); // \b shifts cursor back ' ' will erase charchter and \b again to back cursor
            }
            continue; // skipping loop
        }
        if (user_input==paragraph[typed_char]) // if input matched paragraph
        {
            printf(GREEN"%c"RESET,user_input); // print it with green color
        }
        else
        {
            printf(RED"%c"RESET,user_input); // else print it with red coloe
            mistakes++; // adding mistake
            mistake_freq[(unsigned char)paragraph[typed_char]]++; // increasing mistake freq by one.
        }
        typed_char++;
        if (typed_char==strlen(paragraph)) // if paragraph finish break loop
        {
            break;
        }
    }
    time_t end_time = time(NULL); // ending time
    
    double time_taken_min = (double)difftime(end_time,start_time)/60; // taking duration of time
    double accuracy = ((double)(typed_char-mistakes)/typed_char)*100; // measuring accuracy
    
    // checking no of words in this paragraph
    int is_inside_word=0,No_of_Words=0;
    for (int i = 0; i < strlen(paragraph); i++)
    {
        if (isspace(paragraph[i]))
        {
            is_inside_word =0;
        }
        else if(!is_inside_word)
        {
            is_inside_word=1;
            No_of_Words++;
        }
    }
    // measuring speed
    double speed  = (double)No_of_Words/time_taken_min;
    //printing final results
    printf("\n=================== Result ===================\n");
    printf("No of Words is: %d \n",No_of_Words);
    printf("Total time taken is: %.2f sec \n",time_taken_min*60);
    printf("Your speed is: %.2f WPM\n",speed);
    printf("Your accuracy is: %.2f %% \n",accuracy);
    printf("Your Mistakes: \n");
    for (int i = 0; i < 256; i++)
    {
        if (mistake_freq[i]>0)
        {
            if (i ==' ')
            {
                printf("\tspaces(' '): %d\n",mistake_freq[i]);
            }
            else if(i== '\n')
            {
                printf("\tnewline(Enter): %d\n",mistake_freq[i]); 
            }
            else
            {
                printf("\t\"%c\": %d\n",i,mistake_freq[i]);
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