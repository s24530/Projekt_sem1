#include <iostream>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <windows.h>

bool gameover;
int width = 23;
int height = 23;
int tx[100]; 
int ty[100];
int n;
int x, y, fx,fy,score=0;

enum whereGoing{
    stop=0,
    left,
    right,
    up,
    down,
};

whereGoing face;

void Setup()
{
    srand(time(NULL));
    gameover = false;
    face = stop;
    x = width/2;
    y = height/2;
    fx = rand() % width;
    fy = rand() % height;
    score = 0;
}

void MapDraw()
{
    
    system("cls");
    for(int i=0; i<width+2; i++){
        std::cout<<"*";
    }
    std::cout<<"\n";
    
    for(int i=0; i< height; i++){
        for(int j=0; j< width; j ++){
            if(j==0){
                std::cout<<"*";
            }
            if (j==x && i==y){
                std::cout<<"@";
            }
            else if(j==fx && i==fy ){
                std::cout<<"$";
            }
            else{
            	bool inc =false;
            	for(int z=0; z<n; z++){
            		
            		if(tx[z]== j && ty[z]==i ){
            			std::cout<<"#";
            			inc = true;
					}
					
				}
			if(!inc) std::cout<<" ";
            }
            if(j==width-1){
                std::cout<<"*";
            }
        }
        std::cout<<"\n";
    }

    for(int i=0; i<width+2; i++){
        std::cout<<"*";
    }
    std::cout<<"\n";
    std::cout<<"SCORE: "<<score<<"\n";
}

void WhereToGO()
{
    if(_kbhit()){
        switch(_getch()){
            case 72:  //Up arrow
                face=up;
                              
                break;
            case 80:  //Down arrow
                face=down;
                               
                break;
            case 75:  //Left arrow
                face=left; 
                              
                break;
            case 77:  //Right arrow
                face=right; 
                               
                break;
        }
	}
        
}

void Running()
{
	int px = tx[0];
	int py = ty[0];
	int pxx, pyy;
	tx[0]=x;
	ty[0]=y;
	for(int i=1; i<n; i++){
		pxx=tx[i];
		pyy=ty[i];
		tx[i]=px;
		ty[i]=py;
		px=pxx;
		py=pyy;
	}
    switch(face){
        case up:
            y--;
            break;
        case down:
            y++;
            break;
        case left:
            x--;
            break;
        case right:
            x++;
            break;
    }
    if(x>width || x<0 || y>height || y<0) {
	
    	system("cls");
    	std::cout<<"Game Over !!! "<<"\n"<<"You got "<<score<<" points!\n";
		gameover = true;	
	}
	for(int i=0; i<n; i++){
		if(tx[i]==x && ty[i]==y){
			system("cls");
    		std::cout<<"Game Over !!! "<<"\n"<<"You got "<<score<<" points!\n";
			gameover = true;	
		}
	}
    if(x==fx && y==fy){
    	
    	score ++;
    	fx = rand() % width;
    	fy = rand() % height;
    	n++;
	}
}

int main()
{
    Setup();
    
	
    while(!gameover){
        MapDraw();
        WhereToGO();
        Running();
        Sleep(25);
    }

    return 0;
}
