#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>



bool validate(int creditLength, long numArray[]);


int main(void)
{
    long userNumber = get_long("Number: ");


//making a temp copy on the userInput to find its lenth

    long tempNumber = userNumber;

    //variable of counting the number lenth
    int creditLength = 0;

    //loop to count the lenth
    while (tempNumber > 0)
    {
        tempNumber = tempNumber / 10;
        creditLength++ ;
    };
    
    //check the lenth of the numbers
    if (creditLength != 15 && creditLength != 16 && creditLength != 13)
    {
        printf("INVALID\n");
        exit(0);
    };

    //adding numbers to an array to start the Luhn’s algorithm
    long numArray[creditLength];

    long numberClone = userNumber;

    for (int i = 0 ; i < creditLength ; i++)
    {
        numArray[i] = numberClone % 10;

        numberClone = numberClone / 10;
    };

    //checksum of the card number to in Luhn's algorithm 
    bool valid = validate(creditLength, numArray);
    
    //if th card is valid find it's company if its not valid end the program 
    if (valid)
    {
        // geeting the first and the sec digit
        int firstdig = numArray[creditLength - 1];
        int secdig = numArray[creditLength - 2];

        switch (firstdig)
        {
            case 3:

                if (secdig == 4 || secdig == 7)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                    exit(0);
                }

                break;
            case 5:

                if (secdig == 1 || secdig == 2 || secdig == 3 || secdig == 4 || secdig == 5)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                    exit(0);
                }

                break;

            case 4:
                printf("VISA\n");
                break;

        };

    }
    else
    {
        printf("INVALID\n");
        exit(0);
    };


};




//validate the card number
bool validate(int creditLength, long numArray[])
{


    //Multiply every other digit by 2, starting with the number’s second-to-last digit
    int sum = 0;

    for (int i = 1; i < creditLength; i = i + 2)
    {

        int currunt_number = numArray[i] * 2;

        if (currunt_number < 9)
        {

            sum += currunt_number ;

        }
        else
        {

            sum += currunt_number % 10;

            currunt_number = currunt_number / 10;

            sum += currunt_number;

        };
    };

    //Add the sum to the sum of the digits that weren’t multiplied by 2.

    for (int i = 0; i < creditLength; i = i + 2)
    {

        sum += numArray[i];

    };

    //check if the number is valied or not
    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
};
