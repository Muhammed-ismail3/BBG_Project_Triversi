#include <stdio.h>
#define max 23

int main() {
    int n, i, j, r, c, test, full,y ,x, dx , dy ,ny, nx;      // declaring variables 
    int firstMove = 0;
    int  tmp;
    int uselessCounter=0;

    int directions[8][2] = {{0,-1}, {0,1}, {1,0}, {-1,0},{-1,1},{1,1},{-1,-1},{1,-1}};
    int validPlace ;
    int countR, countY, countB;


    char board[max][max];

    do {
        printf("Please enter the square matrix dimension nxn: ");
        scanf("%d", &n);
    } while (n > 23 || n <= 3);  
    
    // making the empty matrix
    for (i = 0; i < n+1; i++) {   
        for (j = 0; j < n+1; j++) {
            board[i][j] = '*';
        } 
    }

    // printing the matrix in the beginning
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // players taking turns
    full = 0;
    while (full == 0) { // checking if there are any empty slots to go over
        full = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] == '*') {
                    full = 0;
                    // breaking out when an empty space is found
                    i = n;
                    j = n;
                }
            }
        }

        if (full == 0) {
            // selecting where to play while making sure that the first move is in the middle



            if (firstMove == 0) {
                // n is odd 
                if (n % 2 == 1) {
                    do {
                        printf("It is red's turn and it should be in the middle row %d column %d: ", n/2+1, n/2+1);
                        scanf("%d %d", &r, &c);
                    } while (board[r-1][c-1] != '*' || (r != n/2+1 || c != n/2+1));

                    board[r-1][c-1] = 'r';
                    firstMove = 1;
                } 
                // n is even
                else {
                    do {
                        printf("It is red's turn and it should be in one of these slots:\n");
                        printf("(%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", n / 2, n / 2, n / 2, n / 2 + 1, n / 2 + 1, n / 2, n / 2 + 1, n / 2 + 1);
                        scanf("%d %d", &r, &c);
                    } while (board[r-1][c-1] != '*' || !((r == n / 2 && c == n / 2) || (r == n / 2 && c == n / 2 + 1) || (r == n / 2 + 1 && c == n / 2) || (r == n / 2 + 1 && c == n / 2 + 1)));

                    board[r-1][c-1] = 'r';
                    firstMove = 1;
                }
                // Print after first red move
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("%c ", board[i][j]);
                    }
                    printf("\n");
                }
            } 

            else {
                // Subsequent red turns while making sure that it has at least on stone next to it 
            do {
                    printf("It is red's turn. Please enter where you want to place your color: ");
                    scanf("%d %d", &r, &c);
                    y = r-1;
                    x = c-1;
                    validPlace = 0;
                    if (y >= 0 && y < n && x >= 0 && x < n && board[y][x] == '*' )
                    {
                        validPlace = 0;
                        for ( i = 0; i < 8; i++)
                        {
                            dy = directions[i][0];
                            dx = directions[i][1];
                            ny = y + dy;
                            nx = x + dx;
                            if (ny >= 0 && ny < n && nx >= 0 && nx < n && board[ny][nx] != '*' && board[y][x] == '*' )
                            {
                                validPlace = 1;
                            }
                            
                        }
                        
                        
                    }
                    
                } while (validPlace == 0);  // when the player play in a valid place 

                board[r-1][c-1] = 'r';

                // checking if i can flip any stones 
                for ( i = 0; i < 8; i++)
                    {
                        dy = directions[i][0];
                        dx = directions[i][1];
                        ny = y + dy;         // ny and nx are the naghibor cells 
                        nx = x + dx;

                        if (board[y][x] == board[ny][nx]) // if the naghibor cell is the same we check the other directions 
                        {
                            uselessCounter++;
                        }
                        else if (board[y][x] != board[ny][nx] && board[ny][nx]!='*') 
                        {
                            int found = 0;
                            while (board[ny][nx] != '*' && found == 0 && ny >= 0 && ny < n && nx >= 0 && nx < n) // it is a differenet stone not empty we keep going in the same direction and save the location
                        {
                            found = 0;
                            if (board[y][x] == board[ny][nx])
                            {
                                found = 1;

                                //printf("we have found = %d \n" ,found);
                            }
                            ny = ny + dy;
                            nx = nx + dx;

                            if (found == 1)
                            {
                                //printf("the begining of if found = 1 \n");
                                int yy, xx;
                                yy = y+dy;
                                xx = x+dx;

                                do
                                {
                                    board[yy][xx] = board[y][x];
                                    yy = yy + dy;
                                    xx = xx + dx;
                                    //printf("we are in do before checking the while \n")
                                } while (yy != ny || xx != nx);
                            }
                         //printf(" we are about to go out of the main while \n");   
                        }
                        }
                        //printf("now we change the direction of checking"
                    }

                // Print after red turn
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("%c ", board[i][j]);
                    }
                    printf("\n");
                }
            }
        }
        
        // Yellow's turn 
        full = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] == '*') {
                    full = 0;
                    // breaking out when an empty space found
                    i = n;
                    j = n;
                }
            }
        }

        if (full == 0) {
           // taking yellow's turn while making sure that it has at least on stione next to it 
            do {
                    printf("It is yellow's turn. Please enter where you want to place your color: ");
                    scanf("%d %d", &r, &c);
                    y = r-1;
                    x = c-1;
                    validPlace = 0;
                    if (y >= 0 && y < n && x >= 0 && x < n && board[y][x] == '*' )
                    {
                        validPlace = 0;
                        for ( i = 0; i < 8; i++)
                        {
                            dy = directions[i][0];
                            dx = directions[i][1];
                            ny = y + dy;
                            nx = x + dx;
                            if (ny >= 0 && ny < n && nx >= 0 && nx < n && board[ny][nx] != '*' && board[y][x] == '*' )
                            {
                                validPlace = 1;
                            }
                            
                        }
                        
                        
                    }
                    
                } while (validPlace == 0);

                board[y][x] = 'y';

                // checking if i can flip any stones 
                for ( i = 0; i < 8; i++)
                    {
                        dy = directions[i][0];
                        dx = directions[i][1];
                        ny = y + dy;         // ny and nx are the naghibor cells 
                        nx = x + dx;

                        if (board[y][x] == board[ny][nx])
                        {
                            uselessCounter++;
                        }
                        else if (board[y][x] != board[ny][nx] && board[ny][nx]!='*')
                        {
                            int found = 0;
                            while (board[ny][nx] != '*' && found == 0 && ny >= 0 && ny < n && nx >= 0 && nx < n)
                        {
                            found = 0;
                            if (board[y][x] == board[ny][nx])
                            {
                                found = 1;

                                //printf("we have found = %d \n" ,found);
                            }
                            ny = ny + dy;
                            nx = nx + dx;

                            if (found == 1)
                            {

                                //printf("the begining of if found = 1 \n");
                                int yy, xx;
                                yy = y+dy;
                                xx = x+dx;

                                do
                                {
                                    
                                    board[yy][xx] = board[y][x];

                                    yy = yy + dy;
                                    xx = xx + dx;
                                    

                                    //printf("we are in do before checking the while \n");

                                } while (yy != ny || xx != nx);
                                
                                
                            }
                            

                         //printf(" we are out of the main while \n");   
                        }
                        }
                        
                        
                        //printf("now we change the direction of checking");
                            
                            
                    }
            

            // Print after yellow turn
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    printf("%c ", board[i][j]);
                }
                printf("\n");
            }
        }

         // Blue's turn 
        full = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] == '*') {
                    full = 0;
                    // breaking out when an empty space found
                    i = n;
                    j = n;
                }
            }
        }

        if (full == 0) {
           // taking Blue's turn while making sure that it has at least on stione next to it 
            do {
                    printf("It is Blue's turn. Please enter where you want to place your color: ");
                    scanf("%d %d", &r, &c);
                    y = r-1;
                    x = c-1;
                    validPlace = 0;
                    if (y >= 0 && y < n && x >= 0 && x < n && board[y][x] == '*' )
                    {
                        validPlace = 0;
                        for ( i = 0; i < 8; i++)
                        {
                            dy = directions[i][0];
                            dx = directions[i][1];
                            ny = y + dy;
                            nx = x + dx;
                            if (ny >= 0 && ny < n && nx >= 0 && nx < n && board[ny][nx] != '*' && board[y][x] == '*' )
                            {
                                validPlace = 1;
                            }
                            
                        }
                        
                        
                    }
                    
                } while (validPlace == 0);

                board[y][x] = 'b';

                // checking if i can flip any stones 
                for ( i = 0; i < 8; i++)
                    {
                        dy = directions[i][0];
                        dx = directions[i][1];
                        ny = y + dy;         // ny and nx are the naghibor cells 
                        nx = x + dx;

                        if (board[y][x] == board[ny][nx])
                        {
                            uselessCounter++;
                        }
                        else if (board[y][x] != board[ny][nx] && board[ny][nx]!='*')
                        {
                            int found = 0;
                            while (board[ny][nx] != '*' && found == 0 && ny >= 0 && ny < n && nx >= 0 && nx < n)
                        {
                            found = 0;
                            if (board[y][x] == board[ny][nx])
                            {
                                found = 1;

                                //printf("we have found = %d \n" ,found);
                            }
                            ny = ny + dy;
                            nx = nx + dx;

                            if (found == 1)
                            {

                                //printf("the begining of if found = 1 \n");
                                int yy, xx;
                                yy = y+dy;
                                xx = x+dx;

                                do
                                {
                                    
                                    board[yy][xx] = board[y][x];

                                    yy = yy + dy;
                                    xx = xx + dx;
                                    

                                    //printf("we are in do before checking the while \n");

                                } while (yy != ny || xx != nx);
                                
                                
                            }
                            

                         //printf(" we are out of the main while \n");   
                        }
                        }
                        
                        
                        //printf("now we change the direction of checking");
                            
                            
                    }
            

            // Print after blue's turn
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    printf("%c ", board[i][j]);
                }
                printf("\n");
            }
        }


    }
    // printing the winner 

    countR = 0;
    countY = 0;
    countB = 0;
    for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (board[i][j] == 'r')
                    {
                        countR ++;
                    }
                    else if (board[i][j] == 'y')
                    {
                        countY ++;
                    }
                    else if (board[i][j] == 'b')
                    {
                        countB ++;
                    }
                     
                }
            }

    if (countR > countY && countR > countB )
    {
        printf("there is %d red stons \n %d yellow stones \n %d blue stones \n ", countR, countY, countB);

        printf("the WINNER is RED (r) ");
    }
    else if (countY > countR && countY > countB)
    {
        printf("there is %d red stons \n  %d yellow stones \n %d blue stones \n  ", countR, countY, countB);

        printf("the WINNER is YELLOW (y) ");
    }
    else if (countB > countR && countB > countY)
    {
        printf("there is %d red stons \n  %d yellow stones \n %d blue stones \n  ", countR, countY, countB);

        printf("the WINNER is BLUE (b) ");
    }
    else if (countB == countR && countB == countY)
    {
        printf("there is %d red stons \n  %d yellow stones \n %d blue stones \n  ", countR, countY, countB);

        printf("It is a TIE ! ");
    }

    return 0;
}
