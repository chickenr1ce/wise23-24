#include <stdio.h>
#include <stdlib.h>

enum PizzaType 
{
    Margherita,
    Salami_Classico,
    Funghi,
    Hawaiian_Dream
};

enum PizzaSize
{
    Small,
    Medium,
    Large,
    Extra_Large,
    XXL,
    Party_Size

};

struct PizzaOrder
{
    enum PizzaType type;
    enum PizzaSize size;
};

const char* pizzaTypeToString(enum PizzaType type)
{    
    switch (type) 
    {
        case Margherita:
            return "Pizza Margherita";
        case Salami_Classico:
            return "Salami Classico";
        case Funghi:
            return "Funghi";
        case Hawaiian_Dream:
            return "Hawaiian Dream";
        default:
            return "Unknown Pizza Type";
    }
}

const char* pizzaSizeToString(enum PizzaSize size)
{    
    switch (size) 
    {
        case Small:
            return "Small";
        case Medium:
            return "Medium";
        case Large:
            return "Large";
        case Extra_Large:
            return "Extra Large";
        case XXL:
            return "XXL";
        case Party_Size:
            return "Party Size";
        default:
            return "Unknown Pizza Size";
    }
}


int main()
{
    printf("Hello! Welcome to UASKPS! - University of Applied Sciences Kempten Pizza service!\n");
    printf("You can order up to 10 pizzas.\n\nPress any key to start your order.");

    getchar();
    
    int chosenType;
    int chosenSize;
    int pizza;
    int result;

    struct PizzaOrder TotalOrder[10];

    while(pizza<10)
    {
       
        do
        {
            printf("Please choose your pizza #%d\n\n",pizza+1);
            printf("Available pizza types:\n");
            printf("0: Pizza Margherita\n");
            printf("1: Salami Classico\n");
            printf("2: Funghi\n");
            printf("3: Hawaiian Dream\n");
            printf("\nYour choice: ");
            result = scanf("%d",&chosenType);

            if ( result!= 1|| chosenType < 0 || chosenType > 3) 
            {
                printf("\n\n\nPlease enter a number between 0 and 3.!!!!\n\n\n");

                while (getchar() != '\n');
            }
        }
        while (result!= 1 || chosenType < 0 || chosenType > 3);
        
        
        do
        {
            printf("Available pizza sizes:\n");
            printf("size 0: Small\n");
            printf("size 1: Medium\n");
            printf("size 2: Large\n");
            printf("size 3: Extra Large\n");
            printf("size 4: XXL\n");
            printf("size 5: Party Size\n");
            printf("\nYour choice: ");
            result = scanf("%d", &chosenSize);

            if (result!= 1 || chosenType < 0 || chosenType > 5) 
            {
                printf("\n\n\nPlease enter a number between 0 and 5.!!!!\n\n\n");

                while (getchar() != '\n');
            }
        }
        while (result != 1 || chosenSize < 0 || chosenSize > 5);

        switch (chosenType)
        {
        case 0:
            TotalOrder[pizza].type = Margherita;
            break;
        case 1:
            TotalOrder[pizza].type = Salami_Classico;
            break;
        case 2:
            TotalOrder[pizza].type = Funghi;
            break;
        case 3:
            TotalOrder[pizza].type = Hawaiian_Dream;
            break;
        default:
            break;
        }

        switch (chosenSize)
        {
        case 0:
            TotalOrder[pizza].size = Small;
            break;
        case 1:
            TotalOrder[pizza].size = Medium;
            break;
        case 2:
            TotalOrder[pizza].size = Large;
            break;
        case 3:
            TotalOrder[pizza].size = Extra_Large;
            break;
        case 4:
            TotalOrder[pizza].size = XXL;
            break;
        case 5:
            TotalOrder[pizza].size = Party_Size;
            break;
        default:
            break;
        }

        char input;
        do
        {
            printf("Do you want to order another pizza? (y/n)");
            scanf(" %c", &input);

            if (input=='n')
            {
                printf("\nHere is your complete order:\n\n");
                for (int i = 0; i <= pizza; i++)
                {
                    printf("Pizza #%d: %s (%s)\n",i+1,pizzaTypeToString(TotalOrder[i].type),pizzaSizeToString(TotalOrder[i].size));
                }
                printf("\nThank you for your order!\n");
                exit(1);
            }

            if (input=='y')
            {
                pizza++;
                break;
            }
            
        }
        while (1);

    }
}
