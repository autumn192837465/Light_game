#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int light_bulb_light[10][8]={
    0,0,0,0,0,0,0,0,
    0,0,0,1,1,0,0,0,
    0,0,1,1,1,1,0,0,
    0,1,1,1,1,1,1,0,
    0,1,1,1,1,1,1,0,
    0,1,1,1,1,1,1,0,
    0,1,1,1,1,1,1,0,
    0,0,1,1,1,1,0,0,
    0,0,1,0,0,1,0,0,
    0,0,1,1,1,1,0,0
};
int light_bulb_dark[10][8]={
    0,0,0,0,0,0,0,0,
    0,0,0,1,1,0,0,0,
    0,0,1,0,0,1,0,0,
    0,1,0,0,0,0,1,0,
    0,1,0,0,0,0,1,0,
    0,1,0,0,0,0,1,0,
    0,1,0,0,0,0,1,0,
    0,0,1,1,1,1,0,0,
    0,0,1,0,0,1,0,0,
    0,0,1,1,1,1,0,0
};
void draw_light_bulb(bool l[10]){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<80;j++){
            if(l[j/8]){
                if(light_bulb_light[i][j%8])
                    cout<<"1";
                else
                    cout<<" ";
            }
            else{
                if(light_bulb_dark[i][j%8])
                    cout<<"1";
                else
                    cout<<" ";
            }
        }
    }
}
bool check_ans(bool l[10]){
    for(int i=0;i<10;i++)
        if(!l[i]) return 1;
    return 0;
}
int get_light(bool l[10]){
    int c=0;
    for(int i=0;i<10;i++)
        if(l[i]) c++;
    return c;
}

int main()
{

    srand(time(NULL));

    while(1){
        int steps=0;
        int i=0;
        bool lights[10]={0};

        int start_light_num=rand()%8;
        while(start_light_num==0) start_light_num=rand()%8;
        //set start light
        while(i!=start_light_num){
            int temp=rand()%8;
            if(!lights[temp]){
                lights[temp]=1;
                i++;
            }
        }
        //user game
        string user_ans;
        while(check_ans(lights)){
            cout<<get_light(lights)<<" bulbs are lighted."<<endl;
            cout<<"steps: "<<steps<<endl;
            draw_light_bulb(lights);
            cout<<endl<<"Press which bulbs? ";
            getline(cin,user_ans);
            steps++;
            if(user_ans=="I will lose weight."){
                int cheat_ans;
                cout<<"Which bulb do you want to turn on or off ONLY? ";
                cin>>cheat_ans;
                lights[cheat_ans-1]=!lights[cheat_ans-1];
                system("cls");
                continue;
            }
            else{
                int ans=atoi(user_ans.c_str());


                while(ans>10||ans<1){
                    cout<<"The number must between 1 and 10. \nPlease retype. ";
                    getline(cin,user_ans);
                    ans=atoi(user_ans.c_str());
                }
                if(ans==10){
                    lights[ans-2]=!lights[ans-2];
                }
                else if(ans==1){
                    lights[ans]=!lights[ans];
                }
                else{
                    lights[ans]=!lights[ans];
                    lights[ans-2]=!lights[ans-2];
                }
                lights[ans-1]=!lights[ans-1];
            }

            system("cls");
            fflush(stdin);
        }
        draw_light_bulb(lights);
        cout<<"Congratulations!!"<<endl;
        cout<<"you have take "<<steps<<" steps!"<<endl;

        char c;
        cout<<endl;
        cout<<"Do you want to continue? (Y/N)";
        cin>>c;
        if(c=='N'||c=='n')break;
    }
    return 0;
}


