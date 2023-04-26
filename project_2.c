#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct student
{
    char id[40];
    char name[50];
    struct subject
    {
        int credite;
        char sname[20];
        float marks;
        float grade;

    } sub[5];
    float total;
    float cgpa;
    float totalgrade;

} student;

// create function;
void create()
{

    int i = 0, j = 0, n;
    printf("How many Student do you want to add:");
    scanf("%d", &n);
    getchar();
    student s[n];
    FILE *fptr;
    fptr = fopen("obayed.txt", "w");
    for (i = 0; i < n; i++)
    {
        printf("Name:");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';

        printf("Id:");
        fgets(s[i].id, sizeof(s[i].id), stdin);
        s[i].id[strcspn(s[i].id, "\n")] = '\0';

        s[i].totalgrade = 0;
        int sum = 0;
        for (j = 0; j < 3; j++)
        {
            printf("Enter Your Course Name:");
            fgets(s[i].sub[j].sname, sizeof(s[i].sub[j].sname), stdin);
            s[i].sub[j].sname[strcspn(s[i].sub[j].sname, "\n")] = '\0';

            printf("subject-%d Marks:", j + 1);
            scanf("%f", &s[i].sub[j].marks);
            if (s[i].sub[j].marks >= 90 && s[i].sub[j].marks <= 100)
            {
                s[i].sub[j].grade = 4;
            }
            else if (s[i].sub[j].marks >= 86 && s[i].sub[j].marks <= 89)
            {
                s[i].sub[j].grade = 3.67;
            }
            else if (s[i].sub[j].marks >= 82 && s[i].sub[j].marks <= 85)
            {
                s[i].sub[j].grade = 3.33;
            }
            else if (s[i].sub[j].marks >= 78 && s[i].sub[j].marks <= 81)
            {
                s[i].sub[j].grade = 3.00;
            }
            else if (s[i].sub[j].marks >= 74 && s[i].sub[j].marks <= 77)
            {
                s[i].sub[j].grade = 2.67;
            }
            else if (s[i].sub[j].marks >= 70 && s[i].sub[j].marks <= 73)
            {
                s[i].sub[j].grade = 2.33;
            }
            else if (s[i].sub[j].marks >= 66 && s[i].sub[j].marks <= 69)
            {
                s[i].sub[j].grade = 2.00;
            }
            else if (s[i].sub[j].marks >= 62 && s[i].sub[j].marks <= 65)
            {
                s[i].sub[j].grade = 1.67;
            }
            else if (s[i].sub[j].marks >= 58 && s[i].sub[j].marks <= 61)
            {
                s[i].sub[j].grade = 1.33;
            }
            else if (s[i].sub[j].marks >= 55 && s[i].sub[j].marks <= 57)
            {
                s[i].sub[j].grade = 1.00;
            }
            else
            {
                s[i].sub[j].grade = 0;
            }
            printf("Enter Your course Credite:");
            scanf("%d", &s[i].sub[j].credite);

            getchar();

            sum += s[i].sub[j].credite;
            s[i].totalgrade += (s[i].sub[j].grade * s[i].sub[j].credite);
            s[i].cgpa = s[i].totalgrade / sum;
        }

        fwrite(&s[i], sizeof(student), 1, fptr);
    }
    fclose(fptr);
}
void display()
{

    student s1;
    FILE *fptr;
    fptr = fopen("obayed.txt", "r");
    int j;
    while (fread(&s1, sizeof(student), 1, fptr))
    {
        printf("\nName:%-5s\tId:%-20s", s1.name, s1.id);
        for (j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                printf("Marks:");
            }
            printf("%7.2f", s1.sub[j].marks);
        }
        printf("\tCGPA:%7.2f", s1.cgpa);
    }
    printf("\n\n");
    fclose(fptr);
}
// append/insert function
void append()
{
    int i = 0, j = 0, n;
    printf("How many Student do you want to add:");
    scanf("%d", &n);
    getchar();
    student s[n];
    FILE *fptr;
    fptr = fopen("obayed.txt", "a");
    for (i = 0; i < n; i++)
    {
        printf("Name:");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';

        printf("Id:");
        fgets(s[i].id, sizeof(s[i].id), stdin);
        s[i].id[strcspn(s[i].id, "\n")] = '\0';

        s[i].totalgrade = 0;
        int sum = 0;
        for (j = 0; j < 3; j++)
        {
            printf("Enter Your Course Name:");
            fgets(s[i].sub[j].sname, sizeof(s[i].sub[j].sname), stdin);
            s[i].sub[j].sname[strcspn(s[i].sub[j].sname, "\n")] = '\0';

            printf("subject-%d Marks:", j + 1);
            scanf("%f", &s[i].sub[j].marks);
            if (s[i].sub[j].marks >= 90 && s[i].sub[j].marks <= 100)
            {
                s[i].sub[j].grade = 4;
            }
            else if (s[i].sub[j].marks >= 86 && s[i].sub[j].marks <= 89)
            {
                s[i].sub[j].grade = 3.67;
            }
            else if (s[i].sub[j].marks >= 82 && s[i].sub[j].marks <= 85)
            {
                s[i].sub[j].grade = 3.33;
            }
            else if (s[i].sub[j].marks >= 78 && s[i].sub[j].marks <= 81)
            {
                s[i].sub[j].grade = 3.00;
            }
            else if (s[i].sub[j].marks >= 74 && s[i].sub[j].marks <= 77)
            {
                s[i].sub[j].grade = 2.67;
            }
            else if (s[i].sub[j].marks >= 70 && s[i].sub[j].marks <= 73)
            {
                s[i].sub[j].grade = 2.33;
            }
            else if (s[i].sub[j].marks >= 66 && s[i].sub[j].marks <= 69)
            {
                s[i].sub[j].grade = 2.00;
            }
            else if (s[i].sub[j].marks >= 62 && s[i].sub[j].marks <= 65)
            {
                s[i].sub[j].grade = 1.67;
            }
            else if (s[i].sub[j].marks >= 58 && s[i].sub[j].marks <= 61)
            {
                s[i].sub[j].grade = 1.33;
            }
            else if (s[i].sub[j].marks >= 55 && s[i].sub[j].marks <= 57)
            {
                s[i].sub[j].grade = 1.00;
            }
            else
            {
                s[i].sub[j].grade = 0;
            }
            printf("Enter Your course Credite:");
            scanf("%d", &s[i].sub[j].credite);

            getchar();

            sum += s[i].sub[j].credite;
            s[i].totalgrade += (s[i].sub[j].grade * s[i].sub[j].credite);
            s[i].cgpa = s[i].totalgrade / sum;
        }

        fwrite(&s[i], sizeof(student), 1, fptr);
    }
    fclose(fptr);
}
// student record count function
void noOfrec()
{
    student s1;
    FILE *fptr;
    fptr = fopen("obayed.txt", "r");
    fseek(fptr, 0, SEEK_END);
    int n = ftell(fptr) / sizeof(student);
    printf("\n\n\nNO OF RECORDS=%d", n);
}
// string sheaker function
int substringChecker(char S1[], char S2[])
{
    int i = 0, j = 0, status = 0;

    while (S1[i] != '\0')
    {
        if (S1[i] == S2[j])
        {
            status = 1;
            int k = i;
            while (S2[j] != '\0')
            {
                if (S1[k] != S2[j])
                {
                    status = 0;
                    break;
                }
                j++;
                k++;
            }
        }
        if (status == 1)
            break;
        else
            j = 0;
        i++;
    }
    return status;
}
// search function
void search()
{

    student s1;
    FILE *fptr;
    fptr = fopen("obayed.txt", "r");
    getchar();
    char str[40];
    printf("\n\nEnter Id to search:");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    int j, status = 0;
    while (fread(&s1, sizeof(student), 1, fptr))
    {

        if (substringChecker(s1.id, str) == 1)
        {
            status = 1;
            printf("\nName:%-5s\tId:%-20s", s1.name, s1.id);
            for (j = 0; j < 3; j++)
            {
                if (j == 0)
                {
                    printf("Marks:");
                }
                printf("%7.2f", s1.sub[j].marks);
            }
            printf("\tCGPA:%7.2f", s1.cgpa);
        }
    }
    if (status != 1)
    {
        printf("\n\n\t\t\tSearch Result Not Found!!");
    }
    printf("\n\n");
    fclose(fptr);
}
// update function
void update()
{

    student s1;
    FILE *fptr, *fptr1;
    fptr = fopen("obayed.txt", "r");
    fptr1 = fopen("Ruhi.txt", "w");
    getchar();
    char str[40];
    printf("\n\nEnter Id to Update:");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    int j, status = 0;
    while (fread(&s1, sizeof(student), 1, fptr))
    {

        if (substringChecker(s1.id, str) == 1)
        {
            status = 1;
            printf("New Name:");
            fgets(s1.name, sizeof(s1.name), stdin);
            s1.name[strcspn(s1.name, "\n")] = '\0';

            s1.totalgrade = 0;
            int sum = 0;
            for (j = 0; j < 3; j++)
            {
                printf("Enter Your Course Name:");
                fgets(s1.sub[j].sname, sizeof(s1.sub[j].sname), stdin);
                s1.sub[j].sname[strcspn(s1.sub[j].sname, "\n")] = '\0';

                printf("subject-%d New Marks:", j + 1);
                scanf("%f", &s1.sub[j].marks);
                if (s1.sub[j].marks >= 90 && s1.sub[j].marks <= 100)
                {
                    s1.sub[j].grade = 4;
                }
                else if (s1.sub[j].marks >= 86 && s1.sub[j].marks <= 89)
                {
                    s1.sub[j].grade = 3.67;
                }
                else if (s1.sub[j].marks >= 82 && s1.sub[j].marks <= 85)
                {
                    s1.sub[j].grade = 3.33;
                }
                else if (s1.sub[j].marks >= 78 && s1.sub[j].marks <= 81)
                {
                    s1.sub[j].grade = 3.00;
                }
                else if (s1.sub[j].marks >= 74 && s1.sub[j].marks <= 77)
                {
                    s1.sub[j].grade = 2.67;
                }
                else if (s1.sub[j].marks >= 70 && s1.sub[j].marks <= 73)
                {
                    s1.sub[j].grade = 2.33;
                }
                else if (s1.sub[j].marks >= 66 && s1.sub[j].marks <= 69)
                {
                    s1.sub[j].grade = 2.00;
                }
                else if (s1.sub[j].marks >= 62 && s1.sub[j].marks <= 65)
                {
                    s1.sub[j].grade = 1.67;
                }
                else if (s1.sub[j].marks >= 58 && s1.sub[j].marks <= 61)
                {
                    s1.sub[j].grade = 1.33;
                }
                else if (s1.sub[j].marks >= 55 && s1.sub[j].marks <= 57)
                {
                    s1.sub[j].grade = 1.00;
                }
                else
                {
                    s1.sub[j].grade = 0;
                }
                printf("Enter Your course Credite:");
                scanf("%d", &s1.sub[j].credite);

                getchar();

                sum += s1.sub[j].credite;
                s1.totalgrade += (s1.sub[j].grade * s1.sub[j].credite);
                s1.cgpa = s1.totalgrade / sum;
            }
        }
        fwrite(&s1, sizeof(student), 1, fptr1);
    }
    fclose(fptr);
    fclose(fptr1);
    if (status)
    {
        fptr1 = fopen("Ruhi.txt", "r");
        fptr = fopen("obayed.txt", "w");
        while (fread(&s1, sizeof(student), 1, fptr1))
        {
            fwrite(&s1, sizeof(student), 1, fptr);
        }

        fclose(fptr);
        fclose(fptr1);
    }
    else
    {
        printf("\n\n\t\t\tSearch Result Not Found!!");
    }
    printf("\n\n");
}
// Delete function
void delete()
{

    student s1;
    FILE *fptr, *fptr1;
    fptr = fopen("obayed.txt", "r");
    fptr1 = fopen("Ruhi.txt", "w");
    getchar();
    char str[40];
    printf("\n\nEnter Id to Delete:");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    int j, status = 0;
    while (fread(&s1, sizeof(student), 1, fptr))
    {

        if (substringChecker(s1.id, str) == 1)
        {
            status = 1;
        }
        else
        {
            fwrite(&s1, sizeof(student), 1, fptr1);
        }
    }
    fclose(fptr);
    fclose(fptr1);
    if (status)
    {
        fptr1 = fopen("Ruhi.txt", "r");
        fptr = fopen("obayed.txt", "w");
        while (fread(&s1, sizeof(student), 1, fptr1))
        {
            fwrite(&s1, sizeof(student), 1, fptr);
        }

        fclose(fptr);
        fclose(fptr1);
    }
    else
    {
        printf("\n\n\t\t\tSearch Result Not Found!!");
    }
    printf("\n\n");
}
void cgpabase()
{
    
    student *s, s1;
    FILE *fptr;
    fptr = fopen("obayed.txt", "r");
    fseek(fptr, 0, SEEK_END);
    int n = ftell(fptr) / sizeof(student);
    s = (student *)calloc(n, sizeof(student));
    int i,j;
    rewind(fptr);

    for (i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(student), 1, fptr);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i].cgpa < s[j].cgpa)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("\nName:%-5s\tId:%-20s", s[i].name, s[i].id);
        for (j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                printf("Marks:");
            }
            printf("%7.2f", s[i].sub[j].marks);
        }
        printf("\tCGPA:%7.2f", s[i].cgpa);
    }
    fclose(fptr);
}

int main()
{
    printf("\t\t\t---------Welcome To Student Management System---------\n");
    printf("\t\t\t******************************************************\n\n");
    int n;
    do
    {
        printf("\n\t\t\t1.Add student Details.");
        printf("\n\t\t\t2.Display All Student Information.");
        printf("\n\t\t\t3.Append student Details:");
        printf("\n\t\t\t4:Number Of Records.");
        printf("\n\t\t\t5:Search The Student.");
        printf("\n\t\t\t6:Update Student Informatin.");
        printf("\n\t\t\t7:Delete Student Informatin.");
        printf("\n\t\t\t8:Intra university Scolarship List.");

        printf("\n\t\t\t0.Exit the menu.");

        printf("\nEnter Your choice:");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            append();
            break;
        case 4:
            noOfrec();
            break;
        case 5:
            search();
            break;
        case 6:
            update();
            break;
        case 7:
            delete ();
            break;
        case 8:
            cgpabase();
            break;
        }

    } while (n != 0);

    return 0;
}