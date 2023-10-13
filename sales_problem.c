#include <stdio.h>


int main() 

{
    //Sales report
    double saleArray[] = {
        23458.01,
        40112.00,
        56011.85,
        37820.88,
        37904.67,
        60200.22,
        72400.31,
        56210.89,
        67230.84,
        68233.12,
        80950.34,
        95225.22
    };
    
    const char* monthArray[] = {

        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
        
    };

    printf("Monthly Sales Report for 2022:\n");
    printf("\nMonth\tSales\n\n");

    for (int i = 0; i < sizeof(saleArray) / sizeof(saleArray[0]); i++) {

        printf("%s  $%.2f\n", monthArray[i], saleArray[i]); //prints the month and the total sales for the month

    }
    //Sales summary

    double lowest_val = saleArray[0];
    double highest_val = saleArray[0];
    const char* monthlow = monthArray[0];
    const char* monthhigh = monthArray[0];
    double average;
    int numelements = sizeof(saleArray) / sizeof(saleArray[0]);


    for (int i = 0; i < sizeof(saleArray) / sizeof(saleArray[0]); i++) { //finding average

        average += saleArray[i];

        }

    average = average/numelements;

    for (int i = 0; i < sizeof(saleArray) / sizeof(saleArray[0]); i++) { //finding lowest sale

        if (saleArray[i] < lowest_val) {

            lowest_val = saleArray[i];
            monthlow = monthArray[i];
        }

        if (saleArray[i] > highest_val) {

            highest_val = saleArray[i];
            monthhigh = monthArray[i];
        }
    }
    printf("\nSales summary:\n");
    printf("\nMinimum sales:\t$%.2f\t(%s)\n", lowest_val, monthlow);
    printf("Maximum sales:\t$%.2f\t(%s)\n", highest_val, monthhigh);
    printf("Average sales:\t$%-.2f\n", average);

    //Moving Average
    
    double movingaverage = 0;
    int j = 0;

    printf("\nSix-Month Moving Average Report:\n\n");

    while(j < 7){

        movingaverage = 0;

        for (int i = j ; i < 6+j; i++) {

            movingaverage += saleArray[i];
        
        }

        movingaverage = movingaverage/6;

        printf("%s\t-\t%s\t$%.2f\n", monthArray[j], monthArray[j+5], movingaverage);

        j += 1;
    }


    //Sales Report (highest to lowest)
    //Create a sort function

    double temp;
    const char* temp1;
    for (int i = 0; i < sizeof(saleArray) / sizeof(saleArray[0]); i++) {

        for (int j = i+1; j < sizeof(saleArray) / sizeof(saleArray[0]); j++) {

                if (saleArray[i] < saleArray[j]){

                    temp = saleArray[j];

                    temp1 = monthArray[j];

                    saleArray[j] = saleArray[i];
                    saleArray[i] = temp;

                    monthArray[j] = monthArray[i];
                    monthArray[i] = temp1;

                    
                }
    
        }

    }

    printf("\nSales Report(Highest to Lowest):\n");
    printf("\nMonth\tSales\n\n");
    for (int i = 0; i < sizeof(saleArray) / sizeof(saleArray[0]); i++) {

        printf("%s\t$%.2f\n", monthArray[i], saleArray[i]); //prints the month and the total sales for the month
    
        }

    return (0);
    

}
