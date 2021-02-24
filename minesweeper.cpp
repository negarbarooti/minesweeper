#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct strec
{
    bool open;
    bool flag;
    char value;
};
void chap ( strec home[30][30] , char name[20] , int *score )
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
         {
            if(home[i][j].open==true)
             {
                cout<<home[i][j].value<<" ";
             }
            else {
                if(home[i][j].flag==true)
                    cout<<'^'<<" ";
                else
                    cout<<'*'<<" ";
            }
         }
        cout<<endl;
    }
    puts(name);
    cout<<"score : "<<*score<<endl;
}
char star( strec home[30][30] , int x,int y)
{
        char count='0';
        for(int p=x-1;p<=x+1;p++)
            for(int q=y-1;q<=y+1;q++)
                if(p>=0&&p<30&&q>=0&&q<30)
                {
                if(home[p][q].value=='+')
                    count++;
                }
        return count;
}
void moon(strec home[30][30],int x,int y,int *score)
{
    home[x][y].open=true;
    for(int p=x-1;p<=x+1;p++)
    {
        for(int q=y-1;q<=y+1;q++)
        {
            if(p>=0&&p<30&&q>=0&&q<30)
            {
            if(home[p][q].value!='+'&&home[p][q].open==false)
            {
                home[p][q].open=true;
                (*score)++;
                if(home[p][q].value=='0')
                {
                    moon(home,p,q,score);
                }
            }
            }
        }
    }
}
int game(strec home[30][30],int x,int y ,int *score)
{
    cout<<"Do you want to open the home or mark it ?";
    char javab[20],open[20]="open";
    cin>>javab;
    if(strcmp(javab,open)==0)
    {
        if(home[x][y].flag==true)
        {
            cout<<"Are you sure?";
            char javab1[20];
            cin>>javab1;
            if(strcmp(javab1,"yes")==0)
            {
                if(home[x][y].value=='+')
                {
                    cout<<"Game over!"<<endl;
                    return 3;
                }
                else{
                    if(home[x][y].value=='0')
                    {
                        return 1;
                    }
                    else{
                        home[x][y].open=true;
                        (*score)++;
                        if(*score==900)
                            return 3;
                        return 2;
                    }
                }
            }
            else{
                return 2;
            }
        }
        else {
        if(home[x][y].value=='+')
        {
            cout<<"Game over!"<<endl;
            return 3;
        }
        else{
            if(home[x][y].value=='0')
            {
                (*score)++;
                if(*score==900)
                    return 3;
                return 1;
            }
            else{
                home[x][y].open=true;
                (*score)++;
                if(*score==900)
                    return 3;
                return 2;
            }
        }
            }
    }
    else {
        home[x][y].flag=true;
        return 2;
    }
}
int main()
{
    while (1) {
    strec home[30][30];
    int i,j;
    char name[20];
    int score=0;
    if(score==900)
        break;
    cout<<"Enter your name please :"<<endl;
    cin.getline(name,20);
    for(i=0;i<30;i++)
        for(j=0;j<30;j++)
        {
            home[i][j].open=false;
            home[i][j].flag=false;
        }
    chap(home,name,&score);
    int a=0,b=29;
    for(int z=0;z<90;z++)
    {
        int m=(rand()%(b-a+1)+a);
        int n=(rand()%(b-a+1)+a);
        home[m][n].value='+';
    }
    for(i=0;i<30;i++)
        for(j=0;j<30;j++)
            if(home[i][j].value!='+')
                home[i][j].value=star(home,i,j);
    int x,y;
    cout<<"Enter the coordinate : ";
    cin>>x>>y;
    cout<<"Do you want to open the home or mark it ?";
    char javab[20],open[20]="open";
    cin>>javab;
    if(strcmp(javab,open)==0)
    {
        if(home[x][y].value=='+')
        {
            cout<<"Game over!"<<endl;
            for(int i=0;i<30;i++)
            {
                for(int j=0;j<30;j++)
                        cout<<home[i][j].value<<" ";
                cout<<endl;
            }
            puts(name);
            cout<<"score : "<<score<<endl;
            cout<<"Do you want to play again ?";
            char javab2[20];
            cin>>javab2;
            if(strcmp(javab2,"no")==0)
                return 0;
        }
        else{
            if(home[x][y].value=='0')
            {
                (score)++;
                if(score==900)
                {
                    cout<<"You Win!"<<endl;
                    break;
                }
                moon(home,x,y,&score);
            }
            else{
                home[x][y].open=true;
                score++;
                if(score==900)
                {
                    cout<<"You Win!"<<endl;
                    break;
                }
            }
        }
            }
    else {
        home[x][y].flag=true;
    }
    chap(home,name,&score);
    for(int i=0;i<900;i++)
    {
        int d,s;
        cout<<"Enter the coordinate : ";
        cin>>d>>s;
        int sart=game(home,d,s,&score);
        if(sart==1)
        {
            moon(home,d,s,&score);
            chap(home,name,&score);
            continue;
        }
        if(sart==2)
        {
            chap(home,name,&score);
            continue;
        }
        if(sart==3)
            break;
     }
    if(i<900)
        for(int i=0;i<30;i++)
        {
            for(int j=0;j<30;j++)
                    cout<<home[i][j].value<<" ";
            cout<<endl;
        }
    puts(name);
    cout<<"score : "<<score<<endl;
    if(score==900)
        cout<<"You Win!"<<endl;
    cout<<"Do you want to play again ?";
    char javab2[20];
    cin>>javab2;
    if(strcmp(javab2,"no")==0)
        break;
     }
    return 0;
}
