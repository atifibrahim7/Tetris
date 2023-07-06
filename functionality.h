/*
 ATIF IBRAHIM ABBASI 
 i221249 
 section k 
 to sir Toqueer* */

//---Piece Starts to Fall When Game Starts---//
void fallinPiece(float& timer, float& delay, int& colorNum , int& copyn , int &spacebar , int point_s[][2])
{
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
              
            point_s[i][0]=point_1[i][0];
            point_s[i][1]=point_1[i][1];

            point_1[i][1]+=1;                   //How much units downward
        }
        
        // Code for harddrop
        switch (spacebar)
        {
        case 1:
            for(int k= 0;anamoly();)
            {
                for (int i = 0; i < 4; i++)
                {
                    point_2[i][0] = point_1[i][0];
                    point_2[i][1] = point_1[i][1];
                    point_1[i][1] += 1;             // old position is updated to current one and then on y axis move until it hits anomoly
                }
                k++;                        //used later
            }
            spacebar = 0;             //  reset;
            break;

        default:
            break;
        }
        //PRE _ CODED
        if (!anamoly())
        {
            for(int i = 0 ; i < 4; i++)
        	gameGrid[point_2[i][1]][point_2[i][0]] = colorNum;
        	colorNum = 1 + rand()%7;
            int n=rand()%8;
            copyn = n;

            //--- Un-Comment this Part When You Make BLOCKS array---//
            
                for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 2;
                    point_1[i][1] = BLOCKS[n][i] / 2;
                }
            if(copyn == 6)
            {
                int x = rand()%9;
                 for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
             point_1[i][0]+=x;
                 }
            }
            
        }
        timer=0;
        delay = 0.5;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
 
 // 1
   bool game_close()
   {
       bool flag = false;
       for (int i = 0; i < N; i++)
       {
           if (gameGrid[0+1][i] > 0)
           {
               flag = true;
           }
       }
       return flag;
   }
 // 2
    void left(int& delta_x, int& copyn)         //// bomb not moveable
   {       if(copyn == 6)
           { delta_x = 0; return ; }
        bool flag=false;
       if(delta_x == -1)
       {
        for (int i=0;i<4;i++){
                if( point_1[i][0] == 0)
                    flag=true;
                }
    if(!flag)   
    {
       
       for (int i=0;i<4;i++)
        {      
            point_1[i][0]+=delta_x; 
        }
            if(!!!anamoly())                  //  Block the Blocks from going inwards horiotally into other boxes
            {
                 for (int i=0;i<4;i++)
        {      
            point_1[i][0]-=delta_x; 
        }
            }
        delta_x = 0;
   }

      delta_x = 0; 
        } 
    }  
 // 3
  void right(int& delta_x, int copyn)
   {    
    if(copyn == 6)                      // bomb not moveable
           { delta_x = 0; return ; }
        bool flag=false;
        if(delta_x == 1)
        {
            for (int i=0;i<4;i++){
                if( point_1[i][0] >N-2)
                    flag=true;
                }
    if(!flag)   
    {
       
       for (int i=0;i<4;i++)
        {      
            point_1[i][0]+=delta_x; 
        }
        if(!anamoly())
            {
                 for (int i=0;i<4;i++)
        {      
            point_1[i][0]-=delta_x; 
        }
        delta_x = 0;
   }
        }
   delta_x = 0;
   }
   }
 
 // 4 
   void lineclear(int& score, int& difcount)
   {
       int counter = 0;
       int counter2 = 0;
       for (int i = 0; i < M; i++)      //iterate through M rows
       {
           counter = 0;
           for (int j = 0; j < N; j++)
           {
               if (gameGrid[i][j] > 0)
                   counter++;
           }
           
           if (counter == N)
           {
               for (int k = i; k >= 0; k--)             //swapping algo 
                   for (int z = 0; z < N; z++)
                       {
                        gameGrid[k][z] = gameGrid[k - 1][z];
                       }
                       counter2++;
           }
       }
        if(counter2 == 1)                   // score calculator
       score +=10 ;
       else if(counter2 == 2)
       score +=30;
       else if(counter2 == 3)
       score +=60;
       else if(counter2 == 4)
       score +=100;
        
       counter2 = 0;
       
   }
// 5
    int displacement_x(int px, int py , int point_1[4][2] , int& i)
    {
        return point_1[i][1] - py;
    }
//6
     int displacement_y(int px, int py , int point_1[4][2] , int& i)
    {
        return point_1[i][0] - px;
    }
 // 7
 void clockwiserotate(bool& rotate, int& copyn ,int difcount)             // formula from internet 
 {  
    if(copyn == 5)                  // copyn is the copy 
    {
        return;
    }
    int py = point_1[1][1];
    int px = point_1[1][0];
    int xaxis, yaxis ;
    if(rotate)                  // rotation logic on paper
        for (int i = 0; i < 4; i++)
        {
            xaxis = displacement_x(px ,py , point_1 ,i );
            yaxis = displacement_y(px ,py , point_1 ,i );
            point_1[i][0] = px - xaxis;
            point_1[i][1] =  yaxis + py ;
        }
    if (!anamoly())                                         //  doesnt merge into other block
    {       
        for (int i = 0; i < 4; i++)
        {

            point_1[i][0] = point_2[i][0];
            point_1[i][1] = point_2[i][1];
            point_1[i][1]+=1;
        }
    }
 }
   //8                  // this function shows  inteer to string
    std::string scoreToString ( int&score , float &time , int& difcount)
    {
            return  "Level :"+ std::to_string(difcount)+"\nSCORE = \n" + std::to_string(score) + "\nTime : "+ std::to_string(time);
    }
    //9
    float  difficulty (int& difcount , float& delay , int& score)
    {   if(score > 99)                                                          //controls level 
            difcount++;
        if(difcount>0)
        delay= 0.3;
            return delay;
    }
    //10                                        to use new anamoly for the shadow function
    bool ultis_new_anomoly(int point_s[4][2]){
    for (int i=0;i<4;i++)
        if (point_s[i][1]>=M-1)
            return 0;
        else if (gameGrid[point_s[i][1]+1][point_s[i][0]])
            return 0;
    return 1;
}
    // 11 
    void Shadowmaker(int point_s[4][2])                     // shadow working as a spaceba always true in a loop
    {
         while(ultis_new_anomoly(point_s))
                {
                    for (int l = 0; l < 4; l++)
                    {   point_2[l][1]+=1;
                        point_s[l][1] += 1; 
                    }
                }
    }
    //1
    void bombard(int& copyn , int& colorNum)
    {
        if (copyn == 6)                         // Clear whole grid if colour matches
        {
            for (int i = 0; i < 4; i++)
                if (gameGrid[1 + point_1[i][1]][point_1[i][0]] == colorNum)
                {
                    for (int q = 0; q < M; )
                    {
                        for (int w = 0; w < N; w++)
                        {
                            gameGrid[q][w] = 0;
                        }
                        q++;
                    }
                    
                }
              else
              { int loop = 4;                           // 4 blocks clear but issue : bomb doesnt disappeear
                for (int i = 0; i < loop; i++)
                if (gameGrid[1 + point_1[i][1]][point_1[i][0]] != 0)
                {
                    for(int qwerty = 0 ; qwerty < loop ; qwerty ++)
                    {
                        gameGrid[qwerty + point_1[i][1]][point_1[i][0]] = 0;
                    }
                }
                
              }
        }
        
    }
///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////