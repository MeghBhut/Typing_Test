/*
 * Typing Speed and Accuracy Test Program
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
 * Compile: gcc typing_test.c -o typing_test
 * Run: ./typing_test
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
    printf("\nStart\n");
    getchar(); // buffer clear
    time_t start_time = time(NULL); // defining starting time
    fgets(user_input,sizeof(user_input),stdin);
    user_input[strcspn(user_input,"\n")]='\0';
    time_t end_time = time(NULL); // defining end time
    double time_taken_min = (double)difftime(end_time,start_time)/60; // calculating total time taken in min

    // caluculating no of word in user input
    int No_of_words=0;
    int is_inside_word=0;
    for (int i = 0; i < strlen(user_input); i++)
    {
        if (isspace(user_input[i])) //cheking if any whitespaces(space,newline,tab,vertical tab,horizontal tab)
        {
            is_inside_word=0; //if it found white space then says that it is not inside word
        }
        else if(!is_inside_word)//if it will be inside it will run
        {
            is_inside_word = 1;// defining that cursor is inside word
            No_of_words++; // counting that as number
        }
    }
    //calculating speed
    double speed = (double)No_of_words/time_taken_min;

    //finding accuracy
    int mistakes =0;
    for (int i = 0; i < strlen(user_input); i++)
    {
        if (paragraph[i] != user_input[i]) // if charachter not matched it will count as mistake
        {
            mistakes++;
        }
    }
    if (abs(strlen(paragraph)-strlen(user_input))>1)
    {
        mistakes+= abs(strlen(paragraph)-strlen(user_input)); // if some charachter are cuted or extra it will be counted as mistake
    }
    //calculating accurasy
    double accuracy = ((double)(strlen(paragraph)-mistakes)/strlen(paragraph))*100;

    //printing final results
    printf("\n=================== Result ===================\n");
    printf("No of Words is: %d \n",No_of_words);
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