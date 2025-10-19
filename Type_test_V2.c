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
 *
 * Usage:
 * Compile: gcc typing_test_V2.c -o typing_test
 * Run: ./typing_test_V2
 *
 * Inputs:
 * - Number of sentences to include in the typing test
 * - User's typed paragraph
 *
 * Outputs:
 * - Words typed
 * - Time taken
 * - Typing speed (WPM)
 * - Accuracy percentage
 *
 * Limitations:
 * - Input paragraph length limited to 1000 characters, extend it if you want.
 * - Sentences read up to 200 lines from the input file, extend it if you want
 * - Can be somethimes incompelte as it dont measure live typed word some mistakes
 *   while writing paragraph not count in mistakes while accuracy checking.
 * - Other thing if some letter is missed typed double times then whole part
 *   after that will be given wrong.
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
    getch();
    int typed_char=0,mistakes=0;
    time_t start_time = time(NULL);
    while (1)
    {
        char user_input = getch();
        if (user_input==paragraph[typed_char])
        {
            printf("%c",user_input);
            typed_char++;
        }
        else
        {
            mistakes++;
        }
        if (typed_char==strlen(paragraph))
        {
            break;
        }
    }
    time_t end_time = time(NULL);
    
    double time_taken_min = (double)difftime(end_time,start_time)/60;
    double accuracy = ((double)(typed_char-mistakes)/typed_char)*100;
    
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
    double speed  = (double)No_of_Words/time_taken_min;
    //printing final results
    printf("\n=================== Result ===================\n");
    printf("No of Words is: %d \n",No_of_Words);
    printf("Total time taken is: %.2f sec \n",time_taken_min*60);
    printf("Your speed is: %.2f WPM\n",speed);
    printf("Your accuracy is: %.2f %% \n",accuracy);
    printf("\n==============================================\n");

    // freeing space
    for (int i = 0; i < sentences_read; i++)
    {
        free(sentences[i]);
    }
    return 0;
}