#include <stdio.h>
#include <string.h>

struct mach
{
    char name[20];
    int stock;
    int price;
    float weight;
} a[100];

void manage()
{
    FILE *fptr;

    for (int i = 0; i < 1000; i++)
    {

        printf("\t\t\t\t1.Add Items\n");

        printf("\t\t\t\t2.Sell Item\n");
        printf("\t\t\t\t3.Search Item\n");
        printf("\t\t\t\t4.View All Item\n");
        printf("\t\t\t\t_________________________\n");
        printf("\t\t\t\tType You Choice:");

        int count;
        int i = 0;
        int option;
        scanf("%d", &option);

        if (option == 1)
        {

            int n;
            printf("\t\t\t\tHow Many Items do you want to add?");
            scanf("%d", &n);
            count = n;

            fptr = fopen("product_list.txt", "w+");
            for (i = 0; i < n; i++)
            {

                char b[10];
                printf("\t\t\t\tFish Name:");
                scanf("%s", b);
                strcpy(a[i].name, b);
                fprintf(fptr, "\t\t\t\t%s", b);

                printf("\t\t\t\t%s in stock:", a[i].name);
                scanf("%d", &a[i].stock);
                fprintf(fptr, "\t%d", a[i].stock);
                printf("\t\t\t\t%s price:", a[i].name);
                scanf("%d", &a[i].price);
                fprintf(fptr, "\t%d", a[i].price);
                printf("\t\t\t\tWeight: %s", a[i].name);
                scanf("%f", &a[i].weight);
                fprintf(fptr, "\t%.2f\n", a[i].weight);
                printf("\n\n\n");
            }

            fclose(fptr);
        }

        else if (option == 4)
        {
            char line[500];

            printf("\n\n\n\t\t\t\tITEM LIST\n");
            printf("\t\t\t\t---------------------------\n");
            printf("\t\t\t\tNAME\tSTOCK\tPRICE\tWEIGHT\n\n");
            fptr = fopen("product_list.txt", "r");

            while (fgets(line, 500, fptr))
            {
                puts(line);
            }

            fclose(fptr);

            printf("\n\n\n");
        }
        else if (option == 2)
        {
            printf("\t\t\t\tWhat Do you want to Sell? ");
            char rch[10];
            scanf("%s", rch);
            int in;
            for (i = 0; i < count; i++)
            {
                if (strcmp(a[i].name, rch) == 0)
                {
                    in = i;
                    break;
                }
            }
            int amount;
            printf("\t\t\t\tHow many %s do you want?", a[in].name);
            int ac;
            scanf("%d", &ac);

            if (ac > a[i].stock)
            {
                printf("\t\t\t\tInvalid Input\n");
            }
            else
            {
                a[in].stock -= ac;

                amount = a[in].weight * a[in].price * ac;
            }

            printf("\t\t\t\t------------------\n");
            printf("\t\t\t\tTotal Price:%d\t", amount);
            printf("\n\n\n");
        }
        else if (option == 3)
        {
            printf("\t\t\t\tWhat Item Do you Want to Search?");

            char rch[10];
            scanf("%s", rch);
            printf("\n\n\n");
            for (i = 0; i < count; i++)
            {
                if (strcmp(a[i].name, rch) == 0)
                {
                    printf("\t\t\t\tSEARCHED ITEM \n");
                    printf("\t\t\t\t---------------------------\n");
                    printf("\t\t\t\tNAME\tSTOCK\tPRICE\tWEIGHT\n");
                    printf("\t\t\t\t%s\t", a[i].name);
                    printf("%d\t", a[i].stock);

                    printf("%d\t", a[i].price);

                    printf("%.2f\n", a[i].weight);
                    printf("\n\n\n");
                    break;
                }
            }
        }
        else
        {
            printf("\n\n\n\t\t\t\t\tInvalid Input\n\n\n");
        }
    }
}
int main()
{

    printf("\t\t\t\t*---------WELCOME TO FISH SHOP MANAGER----------*\n");
    printf("\t\t\t\t**************************************************\n\n\n\n\n");
    manage();
}