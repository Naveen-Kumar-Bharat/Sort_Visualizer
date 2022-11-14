#include <SDL2/SDL.h>
#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Function draw_state is writter ti visualise what the state of sort will be after each iteration
//
void draw_state(std::vector<int> &vec,SDL_Renderer* renderer,unsigned int red, unsigned int blue )
{
    int index=0;
    for(auto i: vec)
    {
        if(index==red)
            SDL_SetRenderDrawColor(renderer,255,0,0,255);
        else if(index==blue)
            SDL_SetRenderDrawColor(renderer,0,0,255,255);
        else
            SDL_SetRenderDrawColor(renderer,255,255,255,255);

        SDL_RenderDrawLine(renderer,index,480,index,i);
        index++;
    }
}

int main(int argv, char** args)
{
    // Random number generator
    //
    std::random_device rd;
    std::uniform_int_distribution<> d(1,480);
    std::vector<int> vec;

    // storing random numbers in a container
    //
    for(int i=0;i<80;i++)
    {
        vec.push_back(d(rd));
    }

    // Creating a window and a renderer to visualise the state of sort
    //
    SDL_Window* window=nullptr;
    SDL_Renderer* renderer=nullptr;
    SDL_CreateWindowAndRenderer(
        640,480,0,
        &window,&renderer);
    
    // Giveing title to our display window
    //
    const char* str="SORT VISUALISER";
    SDL_SetWindowTitle(window,str);

    // Set the drawing scale for rendering on the current target.
    //
    SDL_RenderSetScale(renderer,8,1);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"2");

    // BUBBLE Sort Algorithm
    //
    for(unsigned int i=0;i<vec.size();i++)
    {
        for(unsigned int j=i+1;j<vec.size();j++)
        {
            if(vec[i]>vec[j])
                std::swap(vec[i],vec[j]);

            //CLear screen
            //
            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            SDL_RenderClear(renderer);

            //Draw the stat of the sort
            //
            draw_state(vec,renderer,i,j);

            //Show to window
            //
            SDL_RenderPresent(renderer);
            SDL_Delay(20);
        }
    }
    
    // Printing the conatiner on to the Terminal
    //
    for(auto i: vec)
    {
        std::cout<<i<<" ";
    }
    return 0;
}