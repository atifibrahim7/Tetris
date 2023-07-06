/*
 ATIF IBRAHIM ABBASI 
 i221249 
 section k 
 to sir Toqueer */
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
using namespace std;
using namespace sf;
int main(){ 
        
    int score= 0, copyn , spacebar = 0;
    bool pause = false;
    int point_s[4][2];
    int B[1][1];
    int difcount = 0;
    int b = 4;
    for (int i=0;i<4;i++){                      //REMOVE 1st BLOCK
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
             point_1[i][1]+=35;  }
    
    std::fstream myfile;
    srand(time(0));
    RenderWindow mainwindow(VideoMode(450, 480), title );
    Texture obj1, obj2, obj3 , obj4 , obj5 , obj6 , obj7 , obj8 ,obj9 , obj10 , obj11;
    /*
        Load "frames.png","tiles.png" and "background.png" for Texture objects
    */
    obj1.loadFromFile("img/tiles.png");         //real block
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");
    obj4.loadFromFile("img/pause.png");
    obj5.loadFromFile("img/tiles.png");         //shadow
    obj6.loadFromFile("img/menu.png");
    obj8.loadFromFile("img/controls.png");
     obj9.loadFromFile("img/controls.png");
     obj10.loadFromFile("img/over.png");
     obj11.loadFromFile("img/highscores.jpeg");
 

    Sprite boxes(obj1), background(obj2), si(obj11), outerline(obj3) , pauseobj(obj4) , mirrorimage(obj5) , mainmenu(obj6) , controls(obj8) , ssss(obj9) , over(obj10);
    int delta_x=0, colorNum=1;
    float timer=0, delay=0.5;
    bool rotate=0;
    Clock clock, clock2;
    int Files[5];

    

               //Music
        Music gameplay_music;
        if (!gameplay_music.openFromFile("sound.wav"))
        return -1; // error
        gameplay_music.play();
//-----------------------------------------------

       //MENU
        while (mainwindow.isOpen())
        {   bool flag = false;
            mainwindow.clear(Color::Black);
            mainwindow.draw(mainmenu);
            mainwindow.display();
           Event ee;
             while (mainwindow.pollEvent(ee))
                {                                // Event is occurring - until the game is in running state
                    if (ee.type == Event::Closed) // If cross/close is clicked/pressed
                        mainwindow.close();  }    
            if (Keyboard::isKeyPressed(Keyboard::Enter))
            break;
            else if (Keyboard::isKeyPressed(Keyboard::Escape))
            break;
            else if (Keyboard::isKeyPressed(Keyboard::C))
            {   
                flag = true;                        // show RESTART FOR THAT
                while (flag)
                {
                    mainwindow.draw(controls);
                    mainwindow.display();
                    if (Keyboard::isKeyPressed(Keyboard::V))
                    flag = false;
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::B))
            {   
                flag = true;                        // show RESTART FOR THAT
                while (flag)
                {
                    mainwindow.draw(si);
                    mainwindow.display();
                    if (Keyboard::isKeyPressed(Keyboard::N))
                    flag = false;
                }
            }
        }
        

        
        
// Loadign FONTS : TEST 
    Font FONTS ; 
    FONTS.loadFromFile("font.otf");


//---------------------------------------------
            // GAME LOOP
            while (mainwindow.isOpen())
            {   
                float tiime = clock2.getElapsedTime().asSeconds();
                float time = clock.getElapsedTime().asSeconds();
                clock.restart();
                timer += time;

                // This shows current score
                // why is it in loop
                // because outside loop the Text text doesnt get updated thus in the loop
                Text text(scoreToString(score, tiime ,difcount), FONTS);                    // here text displayed in screen
                text.setCharacterSize(21);
                text.setFillColor(Color::White);
                text.setPosition(250, 150);

                //---Event Listening Part---//
                Event ee;
                while (mainwindow.pollEvent(ee))
                {                                // Event is occurring - until the game is in running state
                    if (ee.type == Event::Closed) // If cross/close is clicked/pressed
                        mainwindow.close();          // Opened mainwindow disposes
                    if (ee.type == Event::KeyPressed)
                    {                                           // If any other key (not cross) is pressed
                        if (ee.key.code == Keyboard::Up)         // Check if the other key pressed is UP key
                            rotate = true;                      // Rotation gets on
                        else if (ee.key.code == Keyboard::Left)  // Check if the other key pressed is LEFT key
                            delta_x = -1;                       // Change in X-Axis - Negative
                        else if (ee.key.code == Keyboard::Right) // Check if the other key pressed is RIGHT key
                            delta_x = 1;                        // Change in X-Axis - Positive
                        else if (ee.key.code == Keyboard::Space) // works on harddrop in falling piece where sapcebar is P.B.R
                            spacebar = 1;
                        else if (ee.key.code == Keyboard::Escape) // close the mainwindow via X key
                            mainwindow.close();
                        else if (ee.key.code == Keyboard::P)
                            {pause = true;
                            gameplay_music.pause();}
                    }
                }
                if (Keyboard::isKeyPressed(Keyboard::Down)) // Just another way to detect key presses without event listener
                {
                    if (copyn == 6)
                        delay = 0.5;
                    else
                    {
                        delay = 0.06; 
                    }
                }
            //
                if (pause)                      // for pause menu
                {   
                    while (true)
                    {   
                        bool check = false;
                        mainwindow.draw(pauseobj);
                        mainwindow.display();
                                //HALT THE PAUSE
                        if (Keyboard::isKeyPressed(Keyboard::H))
                        {   
                            gameplay_music.play();
                            pause = false;
                            break;
                        }
                        else if (Keyboard::isKeyPressed(Keyboard::X))
                            return 0;
                                       // Reset krne wastaaey
                        else if (Keyboard::isKeyPressed(Keyboard::R)) 
                        {
                            for (int t = 0; t < M;)
                            {                                   // RESET GRID
                                for (int j = 0; j < N;)
                                {
                                    gameGrid[t][j] = 0;
                                    j++;
                                }
                                t++;
                            }
                                for(int i = 0 ; i < 4  ; i++)                   // for block to go back to top of the grid
                                    point_1[i][1]= 0;
                                    gameplay_music.play();
                           if(!check)
                           {
                            pause = false;
                           break;
                            }
                        }
                    }
                }

                ///////////////////////////////////////////////
                ///*** START CALLING YOUR FUNCTIONS HERE ***///

                fallinPiece(timer, delay, colorNum, copyn, spacebar, point_s);
                    delay = 0.5; 
                 bombard(copyn , colorNum);
                Shadowmaker(point_s);
                left(delta_x, copyn);
                right(delta_x, copyn);
                lineclear(score, difcount);
                
                clockwiserotate(rotate, copyn ,difcount);
               

                if (game_close()) // gameover function true game stops
                {   
                    static int record  = 1;
                    Files[record]= score;
                    record++;
                    myfile.open("siu.txt" , ios::app);        //  to make edits in the file
                    if(myfile.is_open())
                        myfile << Files[record-1] <<endl;

                        myfile.close();
                    timer = 0;
                    over.setPosition(-20, -5);
                    mainwindow.draw(over);
                    mainwindow.display();
                    sleep(seconds(6)); // pauses the game for 5 seconds then breaks the loop
                    break;
                }
                 difficulty(difcount, delay ,score);
                 
                ///*** YOUR CALLING STATEMENTS END HERE ***///
                //////////////////////////////////////////////

                mainwindow.clear(Color::White);
                mainwindow.draw(background);
                for (int i = 0; i < M; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (gameGrid[i][j] == 0)
                            continue;
                        boxes.setTextureRect(IntRect(gameGrid[i][j] * 18, 0, 18, 18));
                        boxes.setPosition(j * 18, i * 18);
                        boxes.move(28, 31); // offset
                        mainwindow.draw(boxes);
                    }
                }
                for (int i = 0; i < b; i++)
                {
                    boxes.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
                    boxes.setPosition(point_1[i][0] * 18, point_1[i][1] * 18);
                    boxes.move(28, 31);
                    mainwindow.draw(boxes);
                }
                mainwindow.draw(text);

                // FOR SHADOW******************************************************888

                for (int i = 0; i < b; i++)
                {
                    mirrorimage.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
                    
                    mirrorimage.setColor(Color(80, 80, 80, 100));
                    mirrorimage.setPosition(point_s[i][0] * 18, point_s[i][1] * 18);
                    mirrorimage.move(28, 31);
                    mainwindow.draw(mirrorimage);
                }

                // END shadow*******************************************************************
                //---The Final on Which Everything is Drawn Over is Loaded---//
                mainwindow.draw(outerline);
                //---The Window that now Contains the Frame is Displayed---//
                mainwindow.display();
                int delta_x = 0;
                
                rotate = 0;
            }

            return 0;
        }
