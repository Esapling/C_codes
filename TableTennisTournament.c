#include <stdio.h>
#include <stdlib.h>

// Hold each player's info 
struct players
{
    char name[10];
    char surname[10];
    int age;
    char category[10];
};
// Hold each team's info and  two player in each team 
struct tournament{
    char name_team[10];
    struct players player1;
    struct players player2;
};
// players' info are taken
void form_player(struct players *pl){
    printf("Enter player's name: ");
        scanf("%s",pl->name);

        printf("Enter player's surname: ");
        scanf("%s",pl->surname);
        
        printf("Enter player's age: ");
        scanf("%d",&pl->age); 
        
        printf("Enter player's competition category: ");
        scanf("%s",pl->category); 
}

// teams' info are taken 
void form_team(struct tournament *t)
{    
    printf("Enter team's name: ");
    scanf("%s",t->name_team); 
    printf("Player 1: \n");
    form_player(&t->player1);
    printf("Player 2: \n");
    form_player(&t->player2); 
    
}
// List players' info 
void list_Player(struct players *plyr)
{
    printf("Name: %s \n",plyr->name);    
    printf("Surame: %s \n",plyr->surname);
    printf("Age: %d \n",plyr->age);
    printf("Category: %s \n",plyr->category);
}
// List teams' info
void list_Team(struct tournament *ptr)
{
    printf("Team's Name: %s\n",ptr->name_team);
    printf("Player 1: \n");
    // in each team also list two players info in those team
    list_Player(&ptr->player1);
    printf("Player 2: \n");
    list_Player(&ptr->player2);
}
int main()
{
    int team_num, i;
    printf("------------\tTableTennisTournament\t------------\n");
    printf("Enter the number of team: ");
    scanf("%d",&team_num);
    struct tournament teams[team_num]; // each team info wil be held in a struct array
    
    for(i=0; i<team_num; i++)
    {
        printf("Team %d : \n",i+1);
        form_team(&teams[i]);
    }
    prinf("----List all information that are given----");
    for(i=0; i<team_num; i++){
        printf("Team %d: \n");
        list_Team(&teams[i]);
    }

    return 0;
}   
