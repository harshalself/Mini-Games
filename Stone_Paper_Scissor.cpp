#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random_choice();
void invalid();
void win(int,int,int*,int*);
void cpuch(int);
void dash();
void choose();

int main()
{
    int ch,ch1,ch2,playerchoice,cpuchoice,playerscore=0,cpuscore=0;
    char a1[]="STONE",a2[]="PAPER",a3[]="SCISSOR";
   
    
    dash();
    cout<<"\n WELCOME TO THE GAME ";
    
    do
    {

    dash();
    cout<<"\n **** MAIN MENU **** \n 1. PLAY GAME \n 2. SCORE TABLE \n 3. EXIT ";
    dash();
    choose();
    cin>>ch;
    dash();
    switch(ch)
    {
        case 1:
                cout<<"\n What Do You Want To Choose : \n 1. STONE \n 2. PAPER \n 3. SCISSOR ";
                dash();
                choose();
                cin>>ch1;
                dash();  

                if(ch1==1)
                {
                    playerchoice=1;
                    cout<<"\n Your Choice : "<<a1;
                    cpuchoice=random_choice();
                    cout<<"\n CPU Choice : ";
                    cpuch(cpuchoice); 
                    win(playerchoice,cpuchoice,&playerscore,&cpuscore);
                }  
                else if(ch1==2)
                {
                    playerchoice=2;
                    cout<<"\n Your Choice : "<<a2;
                    cpuchoice=random_choice();
                    cout<<"\n CPU Choice : ";
                    cpuch(cpuchoice);
                    win(playerchoice,cpuchoice,&playerscore,&cpuscore);
                }
                else if(ch1==3)
                {
                    playerchoice=3;
                    cout<<"\n Your Choice : "<<a3;
                    cpuchoice=random_choice();
                    cout<<"\n CPU Choice : ";
                    cpuch(cpuchoice);
                    win(playerchoice,cpuchoice,&playerscore,&cpuscore);
                }
                else
                {
                    invalid();
                }
                break;

        case 2:
                cout<<"\n YOUR Score : "<<playerscore<<"\n CPU Score : "<<cpuscore;
                break;
        case 3: 
                break;
                return 1;

        default:
                invalid();
                break;
    }
    dash();
    cout<<"\n PLAY AGAIN \n 1. YES \n 2. NO ";
    dash();
    choose();
    cin>>ch2;
    }while(ch2==1);
    return 0;
}

int random_choice()
{   
   srand(time(0));
   int random_num = (rand() % 3) + 1;
   return random_num;
}  
void invalid()
{
    cout<<"\n Invalid Choice... ";
}
void win(int playerchoice,int cpuchoice,int *playerscore,int *cpuscore)
{
    dash();
    if(playerchoice==cpuchoice)
    {
        cout<<"\n TIE :| ";
    }
    else if(playerchoice==1 && cpuchoice==3 || playerchoice==2 && cpuchoice==1 || playerchoice==3 && cpuchoice==2)
    {
        cout<<"\n YOU WIN :)";
        *playerscore=*playerscore+1;
    }
    else
    {
        cout<<"\n CPU WIN :(";
        *cpuscore=*cpuscore+1;
    }

}
void cpuch(int cpuchoice)
{
    if(cpuchoice==1)
    {
        cout<<"STONE";
    }
    else if(cpuchoice==2)
    {
        cout<<"PAPER";
    }
    else if(cpuchoice==3)
    {
        cout<<"SCISSOR";
    }

}
void dash()
{
    cout<<endl;
    for(int i=0;i<=20;i++)
    {
        cout<<"-";
    }
}
void choose()
{
    cout<<"\n Enter Your Choice : ";
}