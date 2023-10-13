#include <stdio.h>

int main(){
    int score;

    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);
    

    if (score == 0 || score == 1){

        return (1);
    }

    else if (score < 0){

        printf("Error.");
    }

    printf("Possible combinations of scoring plays:\n");
    
    // need to find all possible combinations that equal the score.
    
    for (int td2pt = 0; td2pt <= score/8; td2pt++){

        for (int tdxp = 0; tdxp <= score/7; tdxp++){

            for (int td = 0; td <= score/6; td++){

                for (int fg = 0; fg <= score/3; fg++){

                    for (int sfty = 0; sfty <= score/2; sfty++){

                        int scoreleft = score - (td2pt*8 + tdxp*7 + td*6 + fg*3 + sfty*2);

                        if (scoreleft == 0) {

                            printf("%d TD +2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, tdxp, td, fg, sfty);
                        }
                    }
                }
            }
        }
    }


    return (0);
}