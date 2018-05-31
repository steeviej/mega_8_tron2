void setup() {
  DDRA = B11111111;
  DDRC = B00000111;
  DDRG = B00000001;
  DDRL = B00000111;
  DDRB = B00000011;
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
  randomSeed(analogRead(5));
}

// Basic Cube Functions
void displayCube(int);
void cubeClear();
void displayLayer(int, int);
void displayMenu();
void writeLatch(int, int, int);
void copySingleFrame(int[][8][8], int);
void powerOff();
int seeCubeVal(int *);
void setCubeVal(int, int *);

// Menu Functions
int menuExecute();
int animationExecute();
int snakeExecute();
int tronExecute();
//void executeConway();

// Animation Functions
//void animationFillUpdate(int, bool, bool, bool, int);
//void animationWaveLongUpdate();
void animationRainUpdate();
void animationRandom();
void animationSnake();
void animationTwinkle();
void animationWindUpdate();

// Game Functions
void updateGame(int, int *, int *);

// Snake Game Functions
bool updateSnakeDir();
void updateSnakeHead();
void updateFood();
void cubeSubtract(int);
bool snakeEatsBody();
void gameOver();
void placeFood();

// Tron Game Functions
//gameOver = tronPlayerTurn(p2Head,p2Dir,&p2Length,p2Data,p1Path);
bool tronPlayerTurn(int *, int *, int *, int);

int cubeDisplay[][8][8] = {
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  },
  {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  }
};

byte mainMenu[][8][8] {
  ///////////////////////////////////////// 1
  {
    { B0,
      B0,
      B0,
      B00111100,
      B00111100,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00111100,
      B00111100,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00011000,
      B00011000,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00011000,
      B00011000,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00011000,
      B00011000,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00011000,
      B00011000,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00111000,
      B00111000,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00011000,
      B00011000,
      B0,
      B0,
      B0
    }
  },
  //////////////////////////////////////////// 2
  {
    { B0,
      B0,
      B0,
      B01111110,
      B01111110,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00111110,
      B00111110,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00011000,
      B00011000,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00001100,
      B00001100,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00000110,
      B00000110,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B01100110,
      B01100110,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B01111110,
      B01111110,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00111100,
      B00111100,
      B0,
      B0,
      B0
    }
  },
  //////////////////////////////////////////// 3
  {
    { B0,
      B0,
      B0,
      B00111100,
      B00111100,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B01111110,
      B01111110,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B01100110,
      B01100110,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00011100,
      B00011100,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00011100,
      B00011100,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B01100110,
      B01100110,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B01111110,
      B01111110,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00111100,
      B00111100,
      B0,
      B0,
      B0
    }
  },
  //////////////////////////////////////////// 4
  {
    { B0,
      B0,
      B0,
      B00001100,
      B00001100,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00001100,
      B00001100,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B00001100,
      B00001100,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B01111110,
      B01111110,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B01111110,
      B01111110,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B01101100,
      B01101100,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B01101100,
      B01101100,
      B0,
      B0,
      B0
    },
    { B0,
      B0,
      B0,
      B01101100,
      B01101100,
      B0,
      B0,
      B0
    }
  }
};


// For loop variables
int i, j, k, I, J, K; // "for" loop variables

// Software Variables
int STATE = 0;  // Current state of the software menu
char DATA;      // Storage for Bluetooth Data
bool POWER = 1; // Used when turning cube on/off (1=on, 0=off)
bool UPDATE_AVAILABLE = 1;

// Input Control Characters
const char LEFT = 'a';
const char RIGHT = 'd';
const char UP = 'w';
const char DOWN = 's';
const char SEL = 'r';
const char STRT = 't';

const char SQR = 'h';
const char TRI = 'u';
const char EX = 'k';
const char CIR = 'j';

// Main Menu Variables
int MENU_INDEX = 1; // Used to keep track of current menu index (1-3);
int MENU_SIZE = 4;  // Used for cycling through menu.

// Animation Variables
int ANIMATION_INDEX = 0; // used to iterate through cubeAnimation animation frames
int ANIMATION = 0;
int NUM_OF_ANIMATIONS = 5;
int ANIMATION_SPEED[] = {2, 1, 8, 1, 3, 1, 1};
int ANIMATION_FLAVE[] = {12, 15, 10, 1, 10, 1, 10};
int SNAKE[] = {2,2,2,0,0,0}; // x, y, z, same dir?, axis, dir

// Game Variables
int GAME_SPEED = 50;

// The main software loop
void loop() {

  switch (STATE) {
    case 0:
      Serial.print("\nmenuExecute()");
      STATE = menuExecute();
      cubeClear();
      break;

    case 1:
      Serial.print("\nanimationExecute()");
      STATE = animationExecute();
      break;

    case 2:
      Serial.print("\ndrawExecute()");
      STATE = drawExecute();
      break;

    case 3:
      Serial.print("\nsnakeExecute()");
      STATE = snakeExecute();
      break;

    case 4:
      Serial.print("\ntronExecute()");
      STATE = tronExecute();
      break;

    default:
      STATE = 0;
      break;
  }
  displayCube(1);
}

int menuExecute() {
  while (1)
  {
    if (Serial1.available())
    {
      DATA = Serial1.read();

      switch (DATA) {
        case LEFT:
          if (MENU_INDEX == 1)
            MENU_INDEX = MENU_SIZE;
          else
            MENU_INDEX--;
          break;

        case RIGHT:
          if (MENU_INDEX == MENU_SIZE)
            MENU_INDEX = 1;
          else
            MENU_INDEX++;
          break;

        case 'h':
          return MENU_INDEX;
          break;

        case 'N':
          powerOff();
          break;

        default:
          break;
      }

    }
    copyByteFrame(mainMenu, (MENU_INDEX - 1));
    displayCube(1);
  }
}

int animationExecute() {
  int animationFrame = 0;
  unsigned int cycleCount = 0;
  bool cycleAnimations = false;
  bool i1 = 0;
  bool j1 = 1;
  bool k1 = 0;
  int a = 0;
  while (1)
  {
    if (Serial1.available())
    {
      DATA = Serial1.read();
      switch (DATA) {
        case 'r':
          return 0;
          break;

        case UP:
          if (ANIMATION_SPEED[ANIMATION] > 2)
            ANIMATION_SPEED[ANIMATION]--;
          break;

        case DOWN:
          ANIMATION_SPEED[ANIMATION]++;
          break;

        case LEFT:
          {
            ANIMATION--;
            if (ANIMATION < 0)
              ANIMATION = NUM_OF_ANIMATIONS - 1;
            cubeClear();
          }
          break;

        case RIGHT:
          {
            ANIMATION++;
            if (ANIMATION > NUM_OF_ANIMATIONS - 1)
              ANIMATION = 0;
            cubeClear();
          }
          break;

        case 'u':
          ANIMATION_FLAVE[ANIMATION]++;
          break;

        case 'j':
          if (ANIMATION_FLAVE[ANIMATION] > 2)
            ANIMATION_FLAVE[ANIMATION]--;
          break;

        case 'N':
          powerOff();
          break;

        case STRT:
            cycleAnimations = !cycleAnimations;
          break;

        default:
          break;
      }
    }

    if(cycleAnimations)
    {
      cycleCount++;
      Serial.print("\n Cycle Count: ");
      Serial.print(cycleCount);
      if(cycleCount > (10000/ANIMATION_SPEED[ANIMATION]))
      {
        ANIMATION++;
        ANIMATION %= NUM_OF_ANIMATIONS;
        cycleCount = 0;
      }
    }
    switch (ANIMATION)
    {
        //      case 0:
        //      {
        //        animationWaveLongUpdate();
        //        displayCube(ANIMATION_SPEED[ANIMATION]);
        //      }
        break;

      case 0:
        {
          animationRainUpdate();
          displayCube(ANIMATION_SPEED[ANIMATION]);
        }
        break;

      case 1:
        {
          animationRandom();
          ANIMATION_SPEED[ANIMATION] = min(ANIMATION_SPEED[ANIMATION], 8);
          displayCube(ANIMATION_SPEED[ANIMATION]);
        }
        break;

      case 2:
        {
          animationSnake();
          displayCube(ANIMATION_SPEED[ANIMATION]);
        }
        break;

      case 3:
        {
          animationTwinkle();
          displayCube(ANIMATION_SPEED[ANIMATION]);
        }
        break;

      case 4:
        {
          animationWindUpdate();
          displayCube(ANIMATION_SPEED[ANIMATION]);
        }
        break;

        //      case 6:
        //      break;

    }

  }
}

int drawExecute() {
  int cursorPos[] = {1, 1, 1}; // The position of the cursor in the cube (x,y,z)
  //  int t2 = 1000;
  unsigned int blink_count = 0;
  cubeClear();

  while (1)
  {
    cubeDisplay[cursorPos[2]][cursorPos[1]][cursorPos[0]] &= B10000;
    //    Serial.print("Initial: ");
    //    Serial.print(cubeDisplay[cursorPos[2]][cursorPos[1]][cursorPos[0]]);
    //    Serial.print('\n');
    //    delay(t2);
    int previousCursor[] =  {cursorPos[0], cursorPos[1], cursorPos[2]};
    bool moved = 0;

    //    Serial.print("Initial: ");
    //    Serial.print(cubeDisplay[cursorPos[2]][cursorPos[1]][cursorPos[0]]);
    //    Serial.print('\n');
    //    delay(t2);

    blink_count++;
    blink_count %= 50;
    if (blink_count < 25)
      cubeDisplay[cursorPos[2]][cursorPos[1]][cursorPos[0]] |= B1111;
    else
      cubeDisplay[cursorPos[2]][cursorPos[1]][cursorPos[0]] &= B10000;

    //    Serial.print("Blink: ");
    //    Serial.print(cubeDisplay[cursorPos[2]][cursorPos[1]][cursorPos[0]]);
    //    Serial.print('\n');
    //    delay(t2);

    if (Serial1.available())
    {
      DATA = Serial1.read();

      switch (DATA) {
        case UP:
          if (cursorPos[1] > 0)
          {
            cursorPos[1]--;
            moved = 1;
          }
          else
            cursorPos[1] = 0;
          break;

        case LEFT:
          if (cursorPos[0] > 0)
          {
            cursorPos[0]--;
            moved = 1;
          }
          else
            cursorPos[0] = 0;
          break;

        case DOWN:
          if (cursorPos[1] < 7)
          {
            cursorPos[1]++;
            moved = 1;
          }
          else
            cursorPos[1] = 7;
          break;

        case RIGHT:
          if (cursorPos[0] < 7)
          {
            cursorPos[0]++;
            moved = 1;
          }
          else
            cursorPos[0] = 7;
          break;

        case TRI:
          if (cursorPos[2] < 7)
          {
            cursorPos[2]++;
            moved = 1;
          }
          else
            cursorPos[2] = 7;
          break;

        case CIR:
          if (cursorPos[2] > 0)
          {
            cursorPos[2]--;
            moved = 1;
          }
          else
            cursorPos[2] = 0;
          break;

        case SQR:
          cubeDisplay[cursorPos[2]][cursorPos[1]][cursorPos[0]] = B11111;
          break;

        case EX:
          cubeDisplay[cursorPos[2]][cursorPos[1]][cursorPos[0]] = 0;
          break;

        case SEL:
          return 0;
          break;

        //        case 't':
        //          cubeDisplay[cursorPos[2]][cursorPos[1]][cursorPos[0]] = 0;
        //          executeConway();
        //        break;

        case 'N':
          powerOff();
          break;

        default:
          break;
      }

      if (moved)
      {
        if ((cubeDisplay[previousCursor[2]][previousCursor[1]][previousCursor[0]])& B10000)
          cubeDisplay[previousCursor[2]][previousCursor[1]][previousCursor[0]] = B11111;
        else
          cubeDisplay[previousCursor[2]][previousCursor[1]][previousCursor[0]] = 0;
        //        Serial.print("Moved (previous val): ");
        //        Serial.print(cubeDisplay[previousCursor[2]][previousCursor[1]][previousCursor[0]]);
        //        Serial.print('\n');
        //        delay(t2);
      }
    }

    displayCube(1);
  }
}

int snakeExecute(){
  cubeClear();
  int snakeHead[] = {4, 7, 5}; // x, y, z, same dir?, axis, dir
  int snakeDir[] = {0, -1, 0};
  int foodPos[] = {1, 1, 5};
  int snakeLength = 5;
  int snakeSpeed = 50;
  int snakeData;
  while(1)
  {
    for (i = snakeSpeed; i > 0; i--){
      displayCube(1);
      if (Serial1.available())
      {
        snakeData = Serial1.read();
        if(snakeData == SEL)
          return 0;
      }
    }
    
    updateGame(snakeData,snakeDir,snakeHead);
      
//    updateSnakeHead();

  // Check to see if the snake has eaten food. If so...
    if ((snakeHead[0] == foodPos[0])&&(snakeHead[1] == foodPos[1])&&(snakeHead[2] == foodPos[2])){
      Serial.print("The Snake Feasts!");
      snakeSpeed = 50 - snakeSpeed/10;
      snakeLength++;

      // Place New Food
      bool foodPlaced = 0;
      while(!foodPlaced)
      {
        i = random(0, 8);
        j = random(0, 8);
        k = random(0, 8);
        if(cubeDisplay[k][j][i] == 0)
        {
          foodPos[0] = i;
          foodPos[1] = j;
          foodPos[2] = k;
          foodPlaced = true;
        }
      }
      
//      updateFood();

      
    }

  // If the snake did NOT eat food:
    else{
      // Move the snakes body
      cubeSubtract(1);

      if(cubeDisplay[snakeHead[2]][snakeHead[1]][snakeHead[0]])
      {
        int snakeBite = cubeDisplay[snakeHead[2]][snakeHead[1]][snakeHead[0]];
        cubeSubtract(snakeBite);
        snakeLength -= snakeBite;
        snakeSpeed = 50 - snakeLength/10;
      }

      // If the snake eats its body: Game Over()
//      if(cubeDisplay[snakeHead[2]][snakeHead[1]][snakeHead[0]])
//      {
//        gameOver();
//        return 0;
//      }
    }
    
    cubeDisplay[snakeHead[2]][snakeHead[1]][snakeHead[0]] = snakeLength;  // Write the Snake Head to the next position
    cubeDisplay[foodPos[2]][foodPos[1]][foodPos[0]] = 1;                               // Write the food to the next food location
  }
}

int tronExecute(){
  cubeClear();

  // Game Variables
    int tronSpeed = 50;
    int ti;
    bool p1Turn = true;
    bool gameOver = false;
  
  // Player 1 Data
    int p1Head[] = {5, 7, 5}; // x, y, z, same dir?, axis, dir
    int p1Dir[] = {0, -1, 0};
    int p1Path[128][3];
    int p1Length = 1;
    int p1Data;
    bool p1Ready = false;

  // Player 2 Data
    int p2Head[] = {2, 7, 2}; // x, y, z, same dir?, axis, dir
    int p2Dir[] = {0, -1, 0};
    int p2Path[128][3];
    int p2Length = 1;
    int p2Data;
    bool p2Ready = false;
  
  setCubeVal(p1Length,p1Head);
  setCubeVal(p2Length,p2Head);

  // Wait for both players to be ready
  while(!p1Ready || !p2Ready){
    displayCube(1);
    if (Serial1.available())
      {
        p1Data = Serial1.read();
        if(p1Data == STRT)
        {
          p1Ready = true;
          Serial.print("\nPlayer 1 Ready!");
        }
        if(p1Data == SEL)
          return 0;
      }
    if (Serial2.available())
      {
        p2Data = Serial2.read();
        if(p2Data == STRT)
        {
          p2Ready = true;
          Serial.print("\nPlayer 2 Ready!");
        }
        if(p2Data == SEL)
          return 0;
      }
  }

  Serial.print("\nTron Start!");
  
  while(!gameOver)
  {
    for (ti = tronSpeed; ti > 0; ti--){
      displayCube(1);
      if (Serial1.available())
      {
        p1Data = Serial1.read();
        if(p1Data == SEL)
          return 0;
      }
      if (Serial2.available())
      {
        p2Data = Serial2.read();
        if(p2Data == SEL)
          return 0;
      }
    }


//    tronPlayerTurn(int *pHead, int *pDir, int pLength, pData)
    if(p1Turn)
    {
      Serial.print("\nPlayer 1 Turn");
      gameOver = tronPlayerTurn(p1Head,p1Dir,&p1Length,p1Data);
      p1Length++;
      p1Path[p1Length][0] = p1Head[0];
      p1Path[p1Length][1] = p1Head[1];
      p1Path[p1Length][2] = p1Head[2];
    }
    else
    {
      gameOver = tronPlayerTurn(p2Head,p2Dir,&p2Length,p2Data);
      Serial.print("\nPlayer 2 Turn");
      p2Length++;
      p2Path[p2Length][0] = p2Head[0];
      p2Path[p2Length][1] = p2Head[1];
      p2Path[p2Length][2] = p2Head[2];
    }
    if(gameOver)
    {
      Serial.print("\nGame Over!");
      if(p1Turn)
      {
        for(ti=p1Length-1;ti>0;ti--)
        {
          cubeDisplay[p1Path[ti][2]][p1Path[ti][1]][p1Path[ti][0]] = 0;
          displayCube(10);
        }
        Serial.print("\nPlayer 2 Wins!");
      }
      else
      {
        for(ti=p2Length-1;ti>0;ti--)
        {
          cubeDisplay[p2Path[ti][2]][p2Path[ti][1]][p2Path[ti][0]] = 0;
          displayCube(10);
        }
        Serial.print("\nPlayer 1 Wins!");
      }
      
    }
    else
    {
      // If no Game Over;
//      p1Length++;
      p1Turn = !p1Turn;
      setCubeVal(p1Length,p1Head);
      setCubeVal(p2Length,p2Head);
    }
  }

  while(1)
  {
    displayCube(1);
    if(Serial1.available());
    {
      char next = Serial1.read();
      if(next == SEL)
      {
      Serial.print("no...");
        return 0;
      }
      if(next == STRT)
      {
        Serial.print("YES!");
        return 4;
      }
    }
  }
}

bool tronPlayerTurn(int *pHead, int *pDir, int *pLength, int pData){
  
    updateGame(pData,pDir,pHead);
    
    // Check for Game Over
    if(seeCubeVal(pHead))
    {
      Serial.print("\nTron Game Over!");
      return 1;
    }
    *pLength++;
    return 0;
}

void animationRainUpdate() {
  ANIMATION_FLAVE[ANIMATION] = constrain(ANIMATION_FLAVE[ANIMATION], 3, 16);
  int randomRate = ANIMATION_FLAVE[ANIMATION] * 16;
  int r;
  for (k = 0; k < 8; k++)
  {
    for (j = 0; j < 8; j++)
    {
      for (i = 0; i < 8; i++)
      {
        if (k == 7)
        {
          r = random(1, randomRate);
          if (r == 1)
            cubeDisplay[7][j][i] = 0xF;
          else if (cubeDisplay[7][j][i] > 0)
            cubeDisplay[7][j][i] /= 2;
        }
        else
          cubeDisplay[k][j][i] = cubeDisplay[k + 1][j][i];
      }
    }
  }
}

void animationWindUpdate() {
  ANIMATION_FLAVE[ANIMATION] = constrain(ANIMATION_FLAVE[ANIMATION], 3, 16);
  int randomRate = ANIMATION_FLAVE[ANIMATION] * 8;
  int r;
  for (k = 0; k < 8; k++)
  {
    for (j = 0; j < 8; j += 2)
    {
      for (i = 0; i < 8; i++)
      {
        if (i == 7)
        {
          r = random(1, randomRate);
          if (r == 1)
            cubeDisplay[k][j][i] = 0xF;
          else if (cubeDisplay[k][j][i] > 0)
            cubeDisplay[k][j][i] /= 2;
        }
        else
          cubeDisplay[k][j][i] = cubeDisplay[k][j][i + 1];
      }
    }

    for (j = 1; j < 8; j += 2)
    {
      for (i = 7; i >= 0; i--)
      {
        if (i == 0)
        {
          r = random(1, randomRate);
          if (r == 1)
            cubeDisplay[k][j][i] = 0xF;
          else if (cubeDisplay[k][j][i] > 0)
            cubeDisplay[k][j][i] /= 2;
        }
        else
          cubeDisplay[k][j][i] = cubeDisplay[k][j][i - 1];
      }
    }
  }
}

void animationRandom() {
  int rx, ry, rz;

  for (i = 0; i < ANIMATION_FLAVE[ANIMATION]; i++)
  {
    rx = random(0, 8);
    ry = random(0, 8);
    rz = random(0, 8);
    cubeDisplay[rz][ry][rx] ^= 0xF;
  }
  //  for(k=0;k<8;k++)
  //  {
  //    for(j=0;j<8;j++)
  //    {
  //      for(i=0;i<8;i++)
  //      {
  //          r = random(1,16*ANIMATION_FLAVE[ANIMATION]);
  //          if(r == 10)
  //
  //      }
  //    }
  //  }
}

void animationSnake() {

  ANIMATION_FLAVE[ANIMATION] = constrain(ANIMATION_FLAVE[ANIMATION], 3, 15);
  int error = 0;
  bool working = 1;
  for (k = 0; k < 8; k++)
  {
    for (j = 0; j < 8; j++)
    {
      for (i = 0; i < 8; i++)
      {
        cubeDisplay[k][j][i] /= 2;
      }
    }
  }

  while (working)
  {
    if (!SNAKE[3])
    {
      SNAKE[4] = random(0, 3);
      SNAKE[5] = random(0, 2) * 2 - 1;
    }
    SNAKE[SNAKE[4]] += SNAKE[5];

    if ((SNAKE[SNAKE[4]] >= 0) && (SNAKE[SNAKE[4]] < 8))
    {
      if ((cubeDisplay[SNAKE[2]][SNAKE[1]][SNAKE[0]]) == 0)
      {
        for (i = 0; i < ANIMATION_FLAVE[ANIMATION]; i++)
        {
          cubeDisplay[SNAKE[2]][SNAKE[1]][SNAKE[0]] |= (1 << i);
        }
        working = 0;
        if (SNAKE[3])
          SNAKE[3] = 0;
        else
          SNAKE[3] = 1;
      }
      else
      {
        SNAKE[SNAKE[4]] -= SNAKE[5];
        SNAKE[3] = 0;
      }
    }
    else
    {
      SNAKE[SNAKE[4]] -= SNAKE[5];
      SNAKE[3] = 0;
    }

    error++;
    if (error > 10)
      working = 0;
  }
}

void animationTwinkle() {

  int r;
  r = random(1, 2 * ANIMATION_FLAVE[ANIMATION]);
  if (r == 1)
  {
    i = random(0, 8);
    j = random(0, 8);
    k = random(0, 8);
    cubeDisplay[k][j][i] ^= random(1, 0xFFFF);
  }

  for (k = 0; k < 8; k++)
  {
    for (j = 0; j < 8; j++)
    {
      for (i = 0; i < 8; i++)
      {
        cubeDisplay[k][j][i] /= 2;
      }
    }
  }
}

void displayMenu() {

  for (k = 0; k < 8; k++)
  {
    for (j = 0; j < 8; j++)
    {
      for (i = 0; i < 8; i++)
      {
        cubeDisplay[k][j][i] = mainMenu[MENU_INDEX - 1][k][j] & (1 << i);
      }
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////

void updateGame(int data, int *dir, int *head){
//                                                              Serial.print("\nupdateSnakeDir()");
  switch (data) {
    case TRI:
      if (dir[2] != -1)
      {
        dir[0] = 0;
        dir[1] = 0;
        dir[2] = 1;
      }
      break;

    case CIR:
      if (dir[2] != 1)
      {
        dir[0] = 0;
        dir[1] = 0;
        dir[2] = -1;
      }
      break;

    case RIGHT:
      if (dir[0] != -1)
      {
        dir[0] = 1;
        dir[1] = 0;
        dir[2] = 0;
      }
      break;

    case LEFT:
      if (dir[0] != 1)
      {
        dir[0] = -1;
        dir[1] = 0;
        dir[2] = 0;
      }
      break;

    case DOWN:
      if (dir[1] != -1)
      {
        dir[0] = 0;
        dir[1] = 1;
        dir[2] = 0;
      }
      break;

    case UP:
      if (dir[1] != 1)
      {
        dir[0] = 0;
        dir[1] = -1;
        dir[2] = 0;
      }
      break;

    default:
      break;
  }
  head[0] = (head[0] + dir[0]+8) % 8;
  head[1] = (head[1] + dir[1]+8) % 8;
  head[2] = (head[2] + dir[2]+8) % 8;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void cubeSubtract(int sub) {
//  Serial.print("\ncubeSubtract()");
  for (k = 0; k < 8; k++)
  {
    for (j = 0; j < 8; j++)
    {
      for (i = 0; i < 8; i++)
      {
        if(cubeDisplay[k][j][i])
          cubeDisplay[k][j][i] -= sub;
          
        if( cubeDisplay[k][j][i] < 0 )
          cubeDisplay[k][j][i] = 0;
      }
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////

void copyByteFrame(byte copyMatrix[][8][8], int index) {
  int cx, cy, cz;
  for (cz = 0; cz < 8; cz++)
  {
    for (cy = 0; cy < 8; cy++)
    {
      for (cx = 0; cx < 8; cx++)
      {
        cubeDisplay[cz][cy][cx] = ((copyMatrix[index][cz][cy]) >> (7 - cx)) & 1;
      }
    }
  }
}

//This function displays the matrix cubeDisplay to the LED cube
//inputs: number of times to display entire cube
void displayCube(int dispNum) {
  int mux = 0;
  int displayOut = 0;
  int iteration = 0;
  PORTB = B11;  //Enable Muxes;
  do {
    for (K = 0; K < 8; K++) // Four iterations, one for each layer of the cube
    {
      PORTG = 1;  //Disable Flipflops

      for (J = 0; J < 8; J++)
      {
        for (I = 0; I < 8; I++)
        {
          displayOut = displayOut << 1;
          displayOut = displayOut | (((cubeDisplay[K][I][7-J])&&1));
//          displayOut = displayOut | (((cubeDisplay[K][J][I]) >> iteration)&B1);
          //            displayOut = displayOut | 1;
        }

        PORTA = displayOut; // Write out to LEDs
        mux = J;      // Select the Flip-Flop to Write to
        PORTC = mux;
        displayOut = 0;     // Erase the display out
        PORTA = 0;

      }
      PORTL = K;    // Select Grounding Layer
      PORTG = 0;    // Enable Flip-Flops
      delay(1);     // Alow layer to display for 1ms
      PORTG = 1;    // Enable Flip-Flops
    }
    dispNum--;
  } while (dispNum > 0);
}

// This function clears the matrix cubeDisplay, setting all entries to zero
void cubeClear() {
  for (k = 0; k < 8; k++)
  {
    for (j = 0; j < 8; j++)
    {
      for (i = 0; i < 8; i++)
      {
        cubeDisplay[k][j][i] = 0;
      }
    }
  }
}

// This function is used to toggle the cube on and off.
// This function is entered when the char 'N' is received, and will not exit until 'P' is received.
void powerOff() {
  while (1)
  {
    if (Serial1.available())
    {
      DATA = Serial1.read();
      if (DATA == 'P')
        return;
    }
  }
}

void printCube(){
  Serial.print("\n\n");
  for (k = 0; k < 8; k++)
  {
    for (j = 0; j < 8; j++)
    {
      for (i = 0; i < 8; i++)
      {
        Serial.print(cubeDisplay[k][j][i]);
        Serial.print(" ");
      }
      Serial.print('\n');
    }
    Serial.print('\n');
  }
}

int seeCubeVal(int *index)
{
  return cubeDisplay[index[2]][index[1]][index[0]];
}

void setCubeVal(int val, int *index)
{
  cubeDisplay[index[2]][index[1]][index[0]] = val;
}

//Serial.print("");
//Serial.print();
//Serial.print('\n');

