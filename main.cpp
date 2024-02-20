#include<iostream>
#include<SDL2/SDL.h>
#include<random>
#include<algorithm>
using namespace std;

void draw_state(vector<int>& v,SDL_Renderer* renderer, unsigned int red, unsigned int blue)
    {
        unsigned int index =0;
        for(int i : v){
            if(index == red)
            {
                SDL_SetRenderDrawColor(renderer, 255,0,0,255);}//sets color of graph to red//
            else if(index == blue)
            {
            SDL_SetRenderDrawColor(renderer, 0,0,255,255);}//sets color of the graph to blue//
            else{
                SDL_SetRenderDrawColor(renderer, 255,255,255,255);//sets color of graph to white//
                }
            
            SDL_RenderDrawLine(renderer,index,99,index, i);//draws line , whose height is determined by i and position by index
            index +=1;

        }
        

    }

int main(int argc,char* argv[]){    
    random_device rd;
    uniform_int_distribution d(1,99);
    vector<int> v;

    // loading the vector with 100 random values between 1-99//
    for(int i=0; i<100;i++){
        v.push_back(d(rd));


    }
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    cout << "SDL initialization failed: " << SDL_GetError() << endl;//simple error handling
    return 1;
}

    //creating a window in renderer using sdl //
  
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    if (SDL_CreateWindowAndRenderer(100*10, 100*10, 0, &window, &renderer) != 0) {
        cout << "Window and renderer creation failed: " << SDL_GetError() << endl; //simple error handling ,
        SDL_Quit();   //dunno how it works but code works because of it
        return 1;
}
SDL_RenderSetScale(renderer, 10, 10);

    // sorting algorithm , selection sorting for now//

 for(int i=0;i<v.size();i++){
        int key=v[i];
        int j=i-1;
        while(j>=0 && v[j]>key){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
                SDL_SetRenderDrawColor(renderer,0,0,0,255);//drew the screen black//
                SDL_RenderClear(renderer);//cleared the screen//

                draw_state(v, renderer,i,j);//draw the state of the sort//

                SDL_RenderPresent(renderer);//used to show what draw state has whipped up

                SDL_Delay(100);//waits 10ms 
        }
    
SDL_SetRenderDrawColor(renderer,0,0,0,255);
draw_state(v,renderer,0,0);//shows the final state of the visualizer//
SDL_Delay(5000);

SDL_DestroyRenderer(renderer);//does as its name suggests ll of them//
SDL_DestroyWindow(window);
SDL_Quit();
  

return EXIT_SUCCESS;

}