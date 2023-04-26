#include<stdio.h>
#include<string.h>
typedef struct student
{
    char name[50];
    char id[50];
    float marks;
}stu;
int main()
{
    int n;
    printf("Enter Your Total student:");
    scanf("%d",&n);
    getchar();
    stu s[n];
    for(int i=0;i<n;i++)
    {
        printf("Student:%d\n\n",i+1);
        
        printf("Name:");
        fgets(s[i].name,sizeof(s[i].name),stdin);
        s[i].name[strcspn(s[i].name,"\n")]='\0';
        
        
        printf("Marks:");
        scanf("%f",&s[i].marks);
        getchar();
        printf("id:");
        fgets(s[i].id,sizeof(s[i].id),stdin);
        s[i].id[strcspn(s[i].id,"\n")]='\0';

        
        
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=s[i].marks;
        
    }
    float avg=sum/n;
    printf("\n");
    for(int i=0;i<n;i++)
    {
        
        printf("%s\t",s[i].name);
        printf("%s\t",s[i].id);
        printf("%.2f\t",s[i].marks);
        printf("\n");
    }
    printf("\n\n%.3f",avg);
    return 0;
}