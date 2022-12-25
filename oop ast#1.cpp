#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
using namespace std;
class worldcup
{
public:
    string coach;   //declaring string type variable
    string nation;
    int wins, loss;
    int team_info();    //function prototype 
    int display_team_info();    //function prototype for displaying team details
    int player_info();      //function prototype
    int display_players();  //function prototype for displaying all players

    struct player   //creating structure
    {
        string active_player[15];    //string type active player variable 
        string passive_player[15];  //string type passive player variable
        int contact;    //contact variable to store players official contact
        string lisence; //variable for storing players official lisence

    }struct_player; //structure instance
};
int worldcup::team_info()//FUNCTION DEFINITION with scope resolution
{
    system("cls");   //clear screen built in function for clear interface
    cout << "\t\t\t\t\tWelcome to Worldcup Application" << endl;
    cout << "\n\n\n\t\t\t\t\t      Enter Team Details " << endl;
    cout << "\t\t\t------------------------------------------------------------\n\n" << endl;
    cout << "\n\t\t\tEnter Nation = ";  //prompt user to input country
    cin >> nation;
    cout << "\n\n\t\t\tEnter coach name = ";    //prompt user to input coach nname
    cin >> coach;
    cout << "\n\n\t\t\tEnter Team Lisence = ";
    cin>>struct_player.lisence;
    cout << "\n\n\t\t\tEnter Team Conatct = ";
    cin>>struct_player.contact;
    cout << "\n\n\t\t\tEnter number of matches win = "; //prompt user to input total win matches
    cin >> wins;
    cout << "\n\n\t\t\tEnter number of matches loss = ";    //prompt user to input total loss matches
    cin >> loss;
    system("cls");
    _getch();
    return 0;
}
int worldcup::display_team_info()   //function definition using scope resolution operator
{   //what this whole function does is to display all the team information like nation,coach name,matches wins and match loss
    system("cls");
    cout << "\t\t\t\t\tWelcome to Worldcup Application" << endl;
    cout << "\n\n\n\t\t\t\t\t          Team Details " << endl;
    cout << "\t\t\t------------------------------------------------------------\n\n" << endl;
    cout << "\t\t\t\tNation                  :: \t" << nation << endl;   //display nation
    cout << "\t\t\t\t---------------------------------------------" << endl;
    cout << "\t\t\t\tCoach                   :: \t" << coach << endl;    //display coach name
    cout << "\t\t\t\t---------------------------------------------" << endl;
    cout << "\t\t\t\tTeam Official Contact   :: \t" << struct_player.contact << endl;
    cout << "\t\t\t\t---------------------------------------------" << endl;
    cout << "\t\t\t\tTeam Official Lisence   :: \t" << struct_player.lisence << endl;
    cout << "\t\t\t\t---------------------------------------------" << endl;
    cout << "\t\t\t\tMatches win             :: \t" << wins << endl; //display matches win
    cout << "\t\t\t\t---------------------------------------------" << endl;
    cout << "\t\t\t\tMatches loss            :: \t" << loss << endl; //display matches loss
    _getch();
    return 0;
}
int worldcup::player_info()  //function definition using scope resolution operator
{//this whole function will take player name from user
    system("cls");
    cout << "\t\t\t\t\tWelcome to Worldcup Application" << endl;
    cout << "\n\n\n\t\t\t\t\t      Enter Team Details " << endl;
    cout << "\t\t\t------------------------------------------------------------\n\n" << endl;
    int ch;
    cout << "\n\t\t\t\tChoose from below :\n\n";
    cout << "\t\t\t\t1 :\tEnter active player\n"; //prompts user to either choose active player category
    cout << "\n\t\t\t\t2 :\tEnter passive player\n";  //or choose passive player category
    cout << "\n\n\t\t\t\tYour choice = ";
    cin >> ch;    //recieves choice
    if (ch == 1)
    {
        system("cls");
        for (int i = 1; i < 15; i++)    //loop for taking player info as active player
        {
            cout << "\n\t\t\t\tEnter player name = ";
            cin >> struct_player.active_player[i];
        }
    }
    else if (ch == 2)
    {
        system("cls");
        for (int i = 1; i < 15; i++)    //loop for taking player info as passive player
        {
            cout << "\n\t\t\t\tEnter player name = ";
            cin >> struct_player.passive_player[i];
        }
    }
    else
        cout << "\nInvalid input!!! ";
    _getch();
    return 0;
}
int worldcup::display_players() //function definition using scope resolution operator
{//this function will display all the player name 
    system("cls");
    cout << "\t\t\t\t\tWelcome to Worldcup Application" << endl;
    cout << "\n\n\n\t\t\t\t\t       Team Players " << endl;
    cout << "\t\t\t------------------------------------------------------------\n\n" << endl;
    for (int t = 1; t < 15; t++)
    {
        if (struct_player.active_player[t] == " ")    //checks if there are no active player then it will display msg
        {
            cout << "\n\t\t\t\tNo Active players :" << endl;
            continue;
        }
        else     //other wise it will display all active player name
            cout << "\n\t\t\t\tActive Player : " << t << " : " << struct_player.active_player[t];
    }

    for (int t = 1; t < 15; t++)
    {
        if (struct_player.passive_player[t] == " ")   //checks if there are no passive player then it will show msg
        {
            cout << "\n\t\t\t\tNo Passive players :" << endl;
            continue;
        }
        else    //other wise it will display all players of team
            cout << "\n\t\t\t\tPassive Player : " << t << " : " << struct_player.passive_player[t];
    }
    _getch();
    return 0;
}
int main()  //DRIVER PROGRAM
{
    worldcup team[8];   //array object team of class worldcup
    string fire, remove_team; //some variable declaration
    int ch;
    do  //do while condition for repeatition and updating of application
    {
        system("cls");
        cout << "\t\t\t\t\tWelcome to Worldcup Application" << endl;    //along with this line below 10 lines will be displayed for user to choose option
        cout << "\n\n\n\t\t\t\t\t      Enter Your Choice " << endl;
        cout << "\t\t\t------------------------------------------------------------\n\n" << endl;
        cout << "\n\t\t\t\tpress : 1 :\t to Add all Teams ";
        cout << "\n\t\t\t\tpress : 2 :\t to Add all Players ";
        cout << "\n\t\t\t\tpress : 3 :\t to view Players ";
        cout << "\n\t\t\t\tpress : 4 :\t to view Team Detail ";
        cout << "\n\t\t\t\tpress : 5 :\t to Fire or Hire a coach ";
        cout << "\n\t\t\t\tpress : 6 :\t to Remove Team ";
        cout << "\n\t\t\t\tpress : 0 :\t to Exit ";
        cout << "\n\n\t\t\t\tYour Choice = ";
        cin >> ch;    //prompts the user to enter choice from above
        if (ch == 1)
        {
            for (int x = 0; x <= 2; x++) //for loop will iterate till 8 teams
            {
                team[x].team_info(); //function will jump back to definition and collects all team info
            }
        }
        else if (ch == 2)
        {
            for (int y = 0; y < 2; y++)  //for loop will iterate till 8 teams with 8 objects
            {
                team[y].player_info();  //function will jump to function definiition 
            }
        }
        else if (ch == 3)
        {
            for (int z = 0; z < 2; z++)  //for loop will iterate till 8 teams with 8 objects
            {
                team[z].display_players();  //function call to display all players
            }
        }
        else if (ch == 4)
        {
            for (int m = 0; m < 2; m++)  //for loop will iterate till 8 teams with 8 objects
            {
                team[m].display_team_info();    //function call to display all team info
            }
        }
        else if (ch == 5)
        {
            system("cls");
            string fire,hire;
            cout << "\t\t\t\t\tWelcome to Worldcup Application" << endl;
            cout << "\n\n\n\t\t\t\t\t      Fire a Coach " << endl;
            cout << "\t\t\t------------------------------------------------------------\n\n" << endl;
            cout << "\n\t\t\t\twhich coach to remove = "; //prompt the user to enter coach name
            cin >> fire;
            cout << "\n\t\t\t\twhich coach to replace = ";
            cin>>hire;
            for (int l = 0; l < 2; l++)  //for loop will iterate till 8 teams with 8 objects
            {
                if (team[l].coach == fire)  //this will check name of coach in all team
                {
                    team[l].coach=hire;  //built in function for erazing coach name
                    cout << "\n\n\t\t\t\tDone\n";
                    Sleep(3000);
                }
            }
        }
        else if (ch == 6)
        {
            system("cls");
            cout << "\t\t\t\t\tWelcome to Worldcup Application" << endl;
            cout << "\n\n\n\t\t\t\t\t    Which team to remove " << endl;
            cout << "\t\t\t------------------------------------------------------------\n\n" << endl;

            cout << "\n\t\t\t\tEnter Team name to Remove from worldcup = ";   //prompt user to enter team name to remove team
            cin >> remove_team;
            for (int i = 0; i < 2; i++)  //for loop will iterate till 8 teams with 8 objects
            {
                if (team[i].nation == remove_team)    //checks for team nation in all team
                {
                    if (team[i].wins > team[i].loss)  //checks if team played matches win is greater then then loss matchses
                    {   //when condition is true followinfg code will run
                        team[i].coach.erase();  //delete coach name
                        team[i].struct_player.active_player[i].erase(); //delete all active players
                        team[i].struct_player.passive_player[i].erase();    //delete all passive players
                        team[i].wins = int();     //delete win record
                        team[i].loss = int(); //delete loss record
                        team[i].nation.erase();  //clears nation name
                        team[i].struct_player.contact=int(); 
                        team[i].struct_player.lisence.erase();
                        cout << "\ndone";
                    }
                    else
                    cout << "\nDelete Failed!!!\n";
                }
            }
        }
        else
        cout << "\n\t\t\t\tInvalid input !!!";

    } while (ch != 0); //0 is for exit if user enters 0 program will terminate

    _getch();
    return 0;
}