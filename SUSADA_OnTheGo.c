// Stephanie Joy Susada 12045985 S11B //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum City 
{
    Manila, Makati, Alabang, Quezon
};

typedef struct _score {
    char name[24];
    int score;
} Score;

typedef struct _player 
{
    int day;
    int clearMinds;
    int energyBooster;
    int calming;
    int lemon;
    int rosemary;
    int mint;
    int lavender;
    int cash;
    int debt;
} Player;

typedef struct _city {
    char name[24];
    int clearMindsPrice;
    int energyBoosterPrice;
    int calmingPrice;
    int lemonPrice;
    int rosemaryPrice;
    int mintPrice;
    int lavenderPrice;
    int makingPrice;
} City;

/**
 * Description : Get the Random object
 * 
 * Parameter1 : min - the minimum random number 
 * Parameter 2: max - the maximum ramdom number
 *
 * Return : int random number
 */
 
int getRandom(int min, int max) 
{
    return rand() % (max - min) + min;
}

/**
 * Description:  Get the Random OIL object
 *
 * Parameter 1:  min - the minimum random number 
 * Parameter 2:  max - the maximum ramdom number
 * Return -  int random number
 */
int getRandomOIL(int min, int max) 
{
    return rand() % (max - min) + min;
}

/**
 * Description : This print the player
 * 
 * Parameter:  player - the player pointer to print
 */
void player_print(Player *player) 
{
    printf("============================================\n");
    printf("\nDAYS : %d\n", player->day);
    printf("--------------------------------------------\n");
    printf ("\n");
    printf("                 INVENTORY\n");
    printf("Oils :\n");
    printf("ClearMinds    := %d\n", player->clearMinds);
    printf("EnergyBooster := %d\n", player->energyBooster);
    printf("Calming       := %d\n", player->calming);
    printf("\nRaw Materials :\n");
    printf("Lemon         := %d\n", player->lemon);
    printf("Rosemary      := %d\n", player->rosemary);
    printf("Mint          := %d\n", player->mint);
    printf("Lavender      := %d\n", player->lavender);
    printf ("\n");
    printf("--------------------------------------------\n");
    printf("                 AMOUNT\n\n");
    printf("Cash          := %d$\n", player->cash);
    printf("Debt          := %d$\n", player->debt);
    printf("============================================\n");
}


/**
 * Description : This initialized the player
 *  
 * Return : Player - new player is returned
 */
Player player_init() 
{
    Player p;
    p.day = 15;
    p.clearMinds = 0;
    p.energyBooster = 0;
    p.calming = 0;
    p.lemon = 0;
    p.rosemary = 0;
    p.mint = 0;
    p.lavender = 0;
    p.cash = 1500;
    p.debt = 4000;
    return p;
}

/*
 * Description :  This prints the city
 * 
 * Parameter : City - the pointer of the city to print
 */
void city_print(City *city) {
    printf("============================================\n");
    printf("\nCITY :  %s\n\n", city->name);
    printf("============================================\n");
    printf("\nPRODUCT SELLING PRICE  \n\n");
    printf("Clear Mind       := %d\n", city->clearMindsPrice);
    printf("Energy Booster   := %d\n", city->energyBoosterPrice);
    printf("Calming          := %d\n", city->calmingPrice);
    printf("Raw Material ::\n");
    printf("Lemon            := %d\n", city->lemonPrice);
    printf("Rosemary         := %d\n", city->rosemaryPrice);
    printf("Mint             := %d\n", city->mintPrice);
    printf("Lavender         := %d\n", city->lavenderPrice);
    printf("Making Price::\n");
    printf("Making Price     := %d\n", city->makingPrice);
    printf("============================================\n");
}

/*
 * Description : Created the city on the basis of the number.
 * 
 * Parameter : Number - the city number
 * Return : City - the new city
 */
City city_init(int number) 
{
    City city;
    city.lemonPrice = getRandomOIL(100, 150);
    city.lavenderPrice = getRandomOIL(20, 60);
    city.rosemaryPrice = getRandomOIL(70, 100);
    city.mintPrice = getRandomOIL(130, 200);
    if (number == 1) {  // for manila
        city.makingPrice = getRandom(20, 30);
        strcpy(city.name, "Manila");
    } else if (number == 2) { // for makati
        city.makingPrice = getRandom(80, 100);
        strcpy(city.name, "Makati");
    } else if (number == 3) { // for alabang
        city.makingPrice = getRandom(70, 90);
        strcpy(city.name, "Alabang");
    } else if (number == 4) { // for quezon
        city.makingPrice = getRandom(40, 60);
        strcpy(city.name, "Quezon");
    }
    double cmp = 1.15 * ((3 * city.lemonPrice) + (2 * city.rosemaryPrice) + (2 * city.mintPrice));
    double ebp = 1.15 * ((1 * city.rosemaryPrice) + (1 * city.mintPrice) + (1 * city.lemonPrice));
    double cp = 1.15 * ((3 * city.lavenderPrice) + (2 * city.rosemaryPrice) + (1 * city.lemonPrice));
    city.clearMindsPrice = (int) cmp;
    city.energyBoosterPrice = (int) ebp;
    city.calmingPrice = (int) cp;
    return city;
}

/**
 * Description : Function used to buy the bottles
 * 
 * Parameter1 : player - the pointer of player
 * Parameter2 :  city -the pointer of city
 */
void buy(Player *player, City *city) 
{
	int option;
	int maxBuy = 1;
    int price = 0;
    int exit = 0;
	
	printf("============================================\n\n");
	
    printf("1 to buy Lemon Bottle\n");
    printf("2 to buy Lavender Bottle\n");
    printf("3 to buy Rosemary Bottle\n");
    printf("4 to buy Mint Bottle\n");
    printf("5 to buy Clear Mind Bottle\n");
    printf("6 to buy Energy Booster Bottle\n");
    printf("7 to buy Calming Bottle\n");
    printf ("\nOption: ");
    scanf("%d%*c", &option);
    
    if (option == 1) {
        printf("\nYou Selected Lemon Bottle\n");
        maxBuy = player->cash / city->lemonPrice;
        price = city->lemonPrice;
    } else if (option == 2) {
        printf("\nYou Selected Lavender Bottle\n");
        maxBuy = player->cash / city->lavenderPrice;
        price = city->lavenderPrice;
    } else if (option == 3) {
        printf("\nYou Selected Rosemary Bottle\n");
        maxBuy = player->cash / city->rosemaryPrice;
        price = city->rosemaryPrice;
    } else if (option == 4) {
        printf("\nYou Selected Mint Bottle\n");
        maxBuy = player->cash / city->mintPrice;
        price = city->mintPrice;
    } else if (option == 5) {
        printf("\nYou Selected Clear Mind Bottle\n");
        maxBuy = player->cash / city->clearMindsPrice;
        price = city->clearMindsPrice;
    } else if (option == 6) {
        printf("\nYou Selected Energy Bottle\n");
        maxBuy = player->cash / city->energyBoosterPrice;
        price = city->energyBoosterPrice;
    } else if (option == 7) {
        printf("\nYou Selected Calming Bottle\n");
        maxBuy = player->cash / city->calmingPrice;
        price = city->calmingPrice;
    } else {
        printf("\nInvalid Input\n");
        exit = 1;
    }
    if (exit == 0) 
	{
        printf("\nCash                    %d\n", player->cash);
        printf("Max Bottles You can Buy %d\n", maxBuy);
        printf("Price per Bottle        %d\n", price);
        printf("\nEnter Amount Of Bottles you want to buy : ");
        int amount;
        scanf("%d%*c", &amount);
        if (amount >= 0 && amount <= maxBuy) {
            player->cash -= (amount * price);
            if (option == 1) {
                player->lemon = 10 * amount;
            } else if (option == 2) {
                player->lavender = 10 * amount;
            } else if (option == 3) {
                player->rosemary = 10 * amount;
            } else if (option == 4) {
                player->mint = 10 * amount;
            } else if (option == 5) {
                player->clearMinds = amount;
            } else if (option == 6) {
                player->energyBooster = amount;
            } else if (option == 7) {
                player->calming = amount;
            }
        } else {
            printf("Invalid Amount\n");
        }
    }
    
    system("cls");
}

/**
 * Description : Function used to Sell the bottles
 * 
 * Parameter1 : player - the pointer of player
 * Parameter2 : city -  the pointer of city
 */
void sell(Player *player, City *city) 
{
	int option;
    int amount;
    
    printf("============================================\n\n");
    
    printf("1 to sell Clear Minds Bottle\n");
    printf("2 to sell Energy Booster Bottle\n");
    printf("3 to sell Calming Bottle\n");
    
    printf("Enter Option : ");
    scanf("%d%*c", &option);
    if (option == 1) {
        printf("You have total %d Clear Mind Bottle\n", player->clearMinds);
        printf("Enter Amount You want to sell : ");
        scanf("%d%*c", &amount);
        if (amount >= 0 && amount <= player->clearMinds) 
		{
            player->clearMinds -= amount;
            player->cash += (city->clearMindsPrice * amount);
        } else {
            printf("Invalid Amount\n");
        }
    } else if (option == 2) {
        printf("You have total %d Energy Booster\n", player->energyBooster);
        printf("Enter Amount You want to sell : ");
        scanf("%d%*c", &amount);
        if (amount >= 0 && amount <= player->energyBooster) 
		{
            player->energyBooster -= amount;
            player->cash += (city->energyBoosterPrice * amount);
        } else {
            printf("Invalid Amount\n");
        }
    } else if (option == 3) {
        printf("You have total %d Calming Bottle\n", player->calming);
        printf("Enter Amount You want to sell : ");
        scanf("%d%*c", &amount);
        if (amount >= 0 && amount <= player->calming) 
		{
            player->calming -= amount;
            player->cash += (city->calmingPrice * amount);
        } else {
            printf("Invalid Amount\n");
        }

    } else {
        printf("Invalid Option\n");
    }
    system("cls");
}

/**
 * Description : Function used to set new travel city
 * /
 * Parameter 1:  player - the pointer of player
 * Parameter 2:  city  - the pointer of city
 */
void travel(Player *player, City *city) 
{
	printf("============================================\n\n");
    printf("1 to goto Manila\n");
    printf("2 to goto Makati\n");
    printf("3 to goto Alabang\n");
    printf("4 to goto Quezon City\n");
    printf("\nEnter Option : ");
    int option;
    scanf("%d%*c", &option);
    if (option == 1) {
        *city = city_init(1);
        player->day--;
    } else if (option == 2) {
        *city = city_init(2);
        player->day--;
    } else if (option == 3) {
        *city = city_init(3);
        player->day--;
    } else if (option == 4) {
        *city = city_init(4);
        player->day--;
    } 
    system("cls");
}
/**
 *	Desciption : Function used to pay loan for the pointer passed 
 * 
 *  Parameter : player - the pointer of player
 */
 
void playLoan(Player *player) 
{
    int amount;
    printf("============================================\n\n");
    printf("Enter the amount you want to pay : ");
    scanf("%d%*c", &amount);
    if (amount >= 0 && amount <= player->debt && amount <= player->cash) {
        player->debt -= amount;
        player->cash -= amount;
    } else {
        printf("Invalid Amount\n");
    }
    system("cls");
}

/**
 * Description : Function used to get loan for the pointer passed 
 * 
 * Parameter : player - the pointer of player
 */
void getLoan(Player *player) 
{
    int amount;
    printf("============================================\n\n");
    printf("Enter the amount you want to get : ");
    scanf("%d%*c", &amount);
    if (amount >= 0) {
        player->debt += amount;
        player->cash += amount;
    } 
    system("cls");
}

/**
 * Description : Function used to print the menu
 * 
 */
void printMenu() 
{
	printf ("\n");
    printf("1 Buy\n");
    printf("2 Sell\n");
    printf("3 Make\n");
    printf("4 Pay Debt\n");
    printf("5 Loan\n");
    printf("6 Travel\n");
    printf ("\nEnter Option: ");
}

/**
 * Description : This will find the minimum form x,y,z
 * 
 * Parameter1 : x
 * Parameter2 : y
 * Parameter3 : z
 * Return : int the minimum form x,y,z
 */
int smallest(int x, int y, int z) {
    int smallest = 99999;
    if (x < smallest)
        smallest = x;
    if (y < smallest)
        smallest = y;
    if (z < smallest)
        smallest = z;
    return smallest;
}

/**
 * Description : Function used to create new bottles of player
 * 
 * Parameter1 : player - the pointer of player
 * Parameter2 : city - the pointer of city
 */
void make(Player *player, City *city) 
{
    int a = 0, b = 0, c = 0;
    if (player->cash >= city->makingPrice) {

        int x, y, z;
        printf("============================================\n\n");
        printf("The Oil Making Price : %d\n", city->makingPrice);
        x = player->lemon / 3;
        y = player->rosemary / 2;
        z = player->mint / 2;
        int cm = smallest(x, y, z);
        if (cm > 0) {
            printf("1 to make Clear Mind Bottle (%d)\n", cm);
            a = 1;
        }
        x = player->rosemary;
        y = player->mint;
        z = player->lemon;
        int pb = smallest(x, y, z);
        if (pb > 0) {
            printf("2 to make Energy Booster Bottle (%d)\n", pb);
            b = 1;
        }
        x = player->lavender / 3;
        y = player->rosemary / 2;
        z = player->lemon / 2;
        int clm = smallest(x, y, z);
        if (clm > 0) {
            printf("3 to make Calming Bottle (%d)\n", clm);
            c = 1;
        }
        printf("Enter Option : ");
        int option;
        int amount;
        scanf("%d%*c", &option);
        if (option == 1 && a == 1) 
		{
            printf("Enter amount : ");
            scanf("%d%*c", &amount);
            if (amount >= 0 && amount <= cm && player->cash >= (amount * city->makingPrice)) {
                player->cash -= (amount * city->makingPrice);
                player->clearMinds += amount;
                player->lemon = player->lemon - 3 * amount;
                player->rosemary -= 2 * amount;
                player->mint -= 2 * amount;
            } else {
                printf("Invalid Option\n");
            }
        } else if (option == 2 && b == 1) {
            printf("Enter amount : ");
            scanf("%d%*c", &amount);
            if (amount >= 0 && amount <= pb && player->cash >= (amount * city->makingPrice)) {
                player->cash -= (amount * city->makingPrice);
                player->energyBooster += amount;
                player->rosemary -= 1 * amount;
                player->mint -=1 * amount;
                player->lemon -=1 * amount;
            } else {
                printf("Invalid Option\n");
            }
        } else if (option == 3 && c == 1) {
            printf("Enter amount : ");
            scanf("%d%*c", &amount);
            if (amount >= 0 && amount <= clm && player->cash >= (amount * city->makingPrice)) {
                player->cash -= (amount * city->makingPrice);
                player->calming += amount;
                player->lavender-=3 * amount;
                player->rosemary-=2 * amount;
                player->lemon-=1 * amount;
            } else {
                printf("Invalid Option\n");
            }
        } else {
            printf("Invalid Option");
        }
    } else {
        printf("You dont have manufacturing price\n");
    }
    system("cls");
}
/**
 * Description : this will read file and set new scores in scores pointer
 * 
 * Parameter1 : scores - the scores pointer
 * Return : int the responce
 */
int readFile(Score scores[10]) 
{
    int err = 0;
    FILE *fp = fopen("./scores.txt", "r");
    if (fp == NULL) 
	{
        printf("Unable to open File\n");
        err = 1;
    } else {
        int x;
        for (x = 0; x < 10; x++) {
            if (fscanf(fp, "%s%d", scores[x].name, &scores[x].score) > 0) {
            } else 
			{
                x = 100;
            }
        }
        fclose(fp);
    }
    return err;
}

/**
 * Description : this will swap the entries of s1 with s2
 * 
 * Parameter1 : s1 score 1
 * Parameter2 : s2 score 2
 */
void swap(Score *s1, Score *s2) {
    Score temp;
    temp.score = s1->score;
    strcpy(temp.name,s1->name);
    s1->score = s2->score;
    strcpy(s1->name , s2->name);
    s2->score = temp.score;
    strcpy(s2->name , temp.name);
}

/**
 * Description : this will sort and write file
 * 
 * Parameter1 : scores - the pointer os score
 * Parameter2 : score the new score
 */
void writeFile(Score scores[10], Score score) 
{
    Score t[11];
    int i, j;
    for (i = 0; i < 10; ++i) {
        t[i].score = scores[i].score;
        strcpy(t[i].name , scores[i].name);
    }
    t[10].score = score.score;
    strcpy(t[10].name , score.name);
    for (i = 0; i < 11; ++i)
    {
        for (j = i + 1; j < 11; ++j)
        {
            if (t[i].score < t[j].score)
            {
                swap(&t[i],&t[j]);
            }
        }
    }

    FILE *fp = fopen("./scores.txt", "w");
    if (fp == NULL) {
        printf("Unable to open File\n");
    } else {
        int x;
        for (x = 0; x < 10; x++) {
            fprintf(fp, "%s %d\n", t[x].name, t[x].score);
        }
        fclose(fp);
    }
}

/**
 * Description : This will play the game
 * 
 */
void play() {
    Score scores[10];
    if (readFile(scores) == 0) 
	{
        Player player = player_init();
        City city = city_init(1);
        char option[100];
        while (player.day != 0) 
		{
            city_print(&city);
            player_print(&player);
            printMenu();
            scanf("%s%*c", option);
            if (strcmp(option, "1") == 0) {
                buy(&player, &city);
            } else if (strcmp(option, "2") == 0) {
                sell(&player, &city);
            } else if (strcmp(option, "3") == 0) {
                make(&player, &city);
            } else if (strcmp(option, "4") == 0) {
                playLoan(&player);
            } else if (strcmp(option, "5") == 0) {
                getLoan(&player);
            } else if (strcmp(option, "6") == 0) {
                travel(&player, &city);
            }
        }
        int min = 999999999;
        int i;
        for (i = 0; i < 10; ++i) {
            if (min > scores[i].score)
                min = scores[i].score;
        }
        if (min < player.cash) {
            Score score;
            score.score = player.cash;
            printf("You make to top 10\n");
            printf("Enter your name : ");
            scanf("%s%*c", score.name);
            writeFile(scores,score);
        }
    } else {
        printf("Problem with File\n");
    }
}

/*
 * Description : This will print the Top Ten Player
 */
void printTop10() 
{
    FILE *fp = fopen("./scores.txt", "r");
    if (fp == NULL) {
        printf("Unable to Open File\n");
    } else {
        int x = 0;
        int score;
        char name[24];
        for (x = 0; x < 10; x++) {
            if (fscanf(fp, "%s%d", name, &score) > 0) {
                    printf("%d-> %s %d\n",x+1 ,name,score);
            } else {
                x = 100;
            }
        }
        fclose(fp);
    }
    
}

/*
 * Description : This is the main menu of the Game
 * 
 * Return: int the return type
 */
int main() 
{
    int option;
    int running = 1;
    while (running == 1) 
	{
		
		printf("Oil-bularyo on the Go!\n\n");
        printf("1 to Start Sales Trip\n");
        printf("2 to Top Ten List\n");
        printf("3 to Exit The Game\n\n");
        printf("Enter option : ");
        
        scanf("%d%*c", &option);
        if (option == 1) 
		{
            play();
        } else if (option == 2) {
            printTop10();
        } else if (option == 3) {
            running = 0;
        } else {
            printf("Invalid Option\n");
        }
    }
    
    return 0;
}
