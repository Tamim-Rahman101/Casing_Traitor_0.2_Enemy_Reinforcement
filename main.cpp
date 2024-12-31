////////////         MENU       ??????????????
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<sstream>
#include<iostream>
#include<fstream>
#include<math.h>
#include<ctime>
#include<cstdlib>

int gameWin(sf::RenderWindow& app, sf::Sprite& background1, sf::Sprite& background2)
{
    bool clickedSound = true, clicked = false, released = false, mouseMoveBool = true;
    int movedX, movedY;  //to collect moved position

    sf::Texture gameWinTex;
    gameWinTex.loadFromFile("Data/gameWin.png");

    sf::Sprite gameWinBg(gameWinTex);
    gameWinBg.setPosition(420, 0);

    sf::Font font;
    font.loadFromFile("Data/pausedFont.otf");
    sf::Text resumeText, menuText;

    menuText.setFont(font);
    menuText.setString("MENU");
    menuText.setCharacterSize(70);
    menuText.setPosition(1200, 650);    //700*550
    menuText.setColor(sf::Color::White);

    sf::SoundBuffer buff1;
    buff1.loadFromFile("Data/Sound/mouseMove.wav");
    sf::Sound mouseMove;
    mouseMove.setBuffer(buff1);

    sf::SoundBuffer buff2;
    buff2.loadFromFile("Data/Sound/mouseClick.wav");
    sf::Sound mouseClick;
    mouseClick.setBuffer(buff2);
    mouseClick.setVolume(150);

    sf::SoundBuffer buff3;
    buff3.loadFromFile("Data/Sound/gameWin.wav");
    sf::Sound gameWinSound;
    gameWinSound.setBuffer(buff3);
    gameWinSound.setLoop(true);
    gameWinSound.play();

    while(app.isOpen())
    {
        sf::Event event;
        while(app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                app.close();
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                clicked = true;
            else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                released = true;
            if(event.type == sf::Event::MouseMoved)
            {
                movedX = event.mouseMove.x;
                movedY = event.mouseMove.y;
            }
        }
        if(movedX > 1190 && movedX < 1355 && movedY > 655 && movedY < 730)
        {
            if(mouseMoveBool)
            {
                mouseMove.play();
                mouseMoveBool = false;
            }
            menuText.setPosition(1180,650);
            menuText.setColor(sf::Color::Black);
            if(clicked)
            {
                if(clickedSound)
                {
                    mouseClick.play();
                    clickedSound = false;
                }
                menuText.setColor(sf::Color::Green);
            }
            if(released)
            {
                gameWinSound.stop();
                return 1;  // take you to the main menu page
            }
        }
        else if(movedX < 1190 || movedX > 1355 || movedY < 655 || movedY > 730)
        {
            mouseMoveBool = true;
            menuText.setPosition(1200,650);
            menuText.setColor(sf::Color::White);
        }
        // to exit return 0

        app.clear();
        app.draw(background1);
        app.draw(background2);
        app.draw(gameWinBg);
        app.draw(menuText);

        app.display();
    }
}

int gameLose(sf::RenderWindow& app, sf::Sprite& background1, sf::Sprite& background2)
{
    bool clickedSound = true, clicked = false, released = false, mouseMoveBool = true;
    int movedX, movedY;  //to collect moved position

    sf::Texture gameWinTex;
    gameWinTex.loadFromFile("Data/gameLose.png");

    sf::Sprite gameLoseBg(gameWinTex);
    gameLoseBg.setPosition(420, 0);

    sf::Font font;
    font.loadFromFile("Data/pausedFont.otf");
    sf::Text resumeText, menuText;

    menuText.setFont(font);
    menuText.setString("MENU");
    menuText.setCharacterSize(70);
    menuText.setPosition(1200, 650);    //700*550
    menuText.setColor(sf::Color::White);

    sf::SoundBuffer buff1;
    buff1.loadFromFile("Data/Sound/mouseMove.wav");
    sf::Sound mouseMove;
    mouseMove.setBuffer(buff1);

    sf::SoundBuffer buff2;
    buff2.loadFromFile("Data/Sound/mouseClick.wav");
    sf::Sound mouseClick;
    mouseClick.setBuffer(buff2);
    mouseClick.setVolume(150);

    sf::SoundBuffer buff3;
    buff3.loadFromFile("Data/Sound/gameLose.wav");
    sf::Sound gameLoseSound;
    gameLoseSound.setBuffer(buff3);
    gameLoseSound.setLoop(true);
    gameLoseSound.play();

    while(app.isOpen())
    {
        sf::Event event;
        while(app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                app.close();
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                clicked = true;
            else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                released = true;
            if(event.type == sf::Event::MouseMoved)
            {
                movedX = event.mouseMove.x;
                movedY = event.mouseMove.y;
            }
        }
        if(movedX > 1190 && movedX < 1355 && movedY > 655 && movedY < 730)
        {
            if(mouseMoveBool)
            {
                mouseMove.play();
                mouseMoveBool = false;
            }
            menuText.setPosition(1180,650);
            menuText.setColor(sf::Color::Black);
            if(clicked)
            {
                if(clickedSound)
                {
                    mouseClick.play();
                    clickedSound = false;
                }
                menuText.setColor(sf::Color::Green);
            }
            if(released)
            {
                gameLoseSound.play();
                return 1;   // take you to the main menu page
            }
        }
        else if(movedX < 1190 || movedX > 1355 || movedY < 655 || movedY > 730)
        {
            mouseMoveBool = true;
            menuText.setPosition(1200,650);
            menuText.setColor(sf::Color::White);
        }
        // to exit return 0

        app.clear();
        app.draw(background1);
        app.draw(background2);
        app.draw(gameLoseBg);
        app.draw(menuText);

        app.display();
    }
}

int pause(sf::RenderWindow& app, sf::Sprite& background1, sf::Sprite& background2)
{
    bool clicked = false, released = false, mouseMoveBool = true;
    bool clickedSound = true, resumeButton = false, menuButton = false;
    int movedX, movedY;  //to collect moved position

    //Paused Background
    sf::Texture pausedBackgroundText;
    pausedBackgroundText.loadFromFile("Data/pausedBg.png");
    sf::Sprite pausedBackground(pausedBackgroundText);
    pausedBackground.setPosition(420,0);

    sf::Font font;
    font.loadFromFile("Data/pausedFont.otf");
    sf::Text resumeText, menuText;

    menuText.setFont(font);
    menuText.setString("MENU");
    menuText.setCharacterSize(70);
    menuText.setPosition(1200, 550);    //700*550
    menuText.setColor(sf::Color::White);

    resumeText.setFont(font);
    resumeText.setString("RESUME");
    resumeText.setCharacterSize(70);
    resumeText.setPosition(1200, 650);   //700*450
    resumeText.setColor(sf::Color::White);

    sf::SoundBuffer buff1;
    buff1.loadFromFile("Data/Sound/mouseMove.wav");
    sf::Sound mouseMove;
    mouseMove.setBuffer(buff1);

    sf::SoundBuffer buff2;
    buff2.loadFromFile("Data/Sound/mouseClick.wav");
    sf::Sound mouseClick;
    mouseClick.setBuffer(buff2);
    mouseClick.setVolume(150);

    while(app.isOpen())
    {
        sf::Event event;
        while(app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                app.close();
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                clicked = true;
            else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                released = true;
            if(event.type == sf::Event::MouseMoved)
            {
                movedX = event.mouseMove.x;
                movedY = event.mouseMove.y;
            }
        }

        if(movedX > 1190 && movedX < 1355 && movedY > 555 && movedY < 630 && resumeButton == false)
        {
            menuButton = true;
            if(mouseMoveBool)
            {
                mouseMove.play();
                mouseMoveBool = false;
            }
            menuText.setPosition(1180,550);
            menuText.setColor(sf::Color::Black);
            if(clicked)
            {
                if(clickedSound)
                {
                    mouseClick.play();
                    clickedSound = false;
                }
                menuText.setColor(sf::Color::Green);
            }
            if(released)
                return 1;
        }
        else if((movedX < 1190 || movedX > 1355 || movedY < 555 || movedY > 630) && resumeButton == false)
        {
            menuButton = false;
            mouseMoveBool = true;
            menuText.setPosition(1200,550);
            menuText.setColor(sf::Color::White);
        }

        if(movedX > 1190 && movedX < 1420 && movedY > 655 && movedY < 730 && menuButton == false)
        {
            resumeButton = true;
            if(mouseMoveBool)
            {
                mouseMove.play();
                mouseMoveBool = false;
            }
            resumeText.setPosition(1180,650);
            resumeText.setColor(sf::Color::Black);
            if(clicked)
            {
                if(clickedSound)
                {
                    mouseClick.play();
                    clickedSound = false;
                }
                resumeText.setColor(sf::Color::Green);
            }
            if(released)
                return 2;  //need deve
        }
        else if((movedX < 1190 || movedX > 1420 || movedY < 655 || movedY > 730) && menuButton == false)
        {
            resumeButton = false;
            mouseMoveBool = true;
            resumeText.setPosition(1200,650);
            resumeText.setColor(sf::Color::White);
        }

        if(released)
        {
            released = false;
            clicked = false;
        }

        app.clear();
        app.draw(background1);
        app.draw(background2);
        app.draw(pausedBackground);
        app.draw(resumeText);
        app.draw(menuText);
        app.display();
    }
}

int select(sf::RenderWindow& app, sf::Sprite& background, sf::Sound& menuMusic, sf::Sprite& myCar0, sf::Sprite& myCar1, sf::Sprite& myCar2)
{
    menuMusic.play();

    bool clickedSound = true;
    bool myCar0Bool = false, myCar1Bool = false, myCar2Bool = false;
    bool clicked = false, released = false, mouseMoveBool = true;
    int movedX, movedY;

    sf::Texture background1Tex;
    background1Tex.loadFromFile("Data/carSelectBg.png");
    sf::Sprite background1(background1Tex);
    background1.setPosition(420, 0);

    sf::Texture car0InfoTex, car1InfoTex, car2InfoTex;

    car0InfoTex.loadFromFile("Data/car1Info.png");
    sf::Sprite car0Info(car0InfoTex);
    car0Info.setPosition(500, 380);

    car1InfoTex.loadFromFile("Data/car2Info.png");
    sf::Sprite car1Info(car1InfoTex);
    car1Info.setPosition(760, 380);

    car2InfoTex.loadFromFile("Data/car3Info.png");
    sf::Sprite car2Info(car2InfoTex);
    car2Info.setPosition(1020, 380);

    myCar0.setPosition(670, 200);
    myCar1.setPosition(930, 200);
    myCar2.setPosition(1190, 200);

    sf::SoundBuffer buff1;
    buff1.loadFromFile("Data/Sound/mouseMove.wav");
    sf::Sound mouseMove;
    mouseMove.setBuffer(buff1);
    mouseMove.setVolume(200);

    sf::SoundBuffer buff2;
    buff2.loadFromFile("Data/Sound/mouseClick.wav");
    sf::Sound mouseClick;
    mouseClick.setBuffer(buff2);
    mouseClick.setVolume(200);

    while(app.isOpen())
    {
        sf::Event event;
        while(app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                app.close();
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                clicked = true;
            else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                released = true;

            if(event.type == sf::Event::MouseMoved)
            {
                movedX = event.mouseMove.x;
                movedY = event.mouseMove.y;
            }
        }

        if(movedX > 660 && movedX < 740 && movedY > 190 && movedY < 360 && myCar1Bool == false && myCar2Bool == false)
        {
            myCar0Bool = true;
            myCar0.setPosition(670, 190);
            if(mouseMoveBool)
            {
                mouseMove.play();
                mouseMoveBool = false;
            }
            if(clicked)
            {
                if(clickedSound)
                {
                    mouseClick.play();
                    clickedSound = false;
                }
                myCar0.setPosition(670, 200);
            }
            if(released)
            {
                clicked = false;
                released = false;
                clickedSound = true;
                menuMusic.pause();
                return 0;
            }
        }
        else if((movedX < 660 || movedX > 740 || movedY < 190 || movedY > 360) && myCar1Bool == false && myCar2Bool == false)
        {
            myCar0Bool = false;
            mouseMoveBool = true;
            myCar0.setPosition(670, 200);
        }

        if(movedX > 920 && movedX < 1000 && movedY > 190 && movedY < 360 && myCar0Bool == false && myCar2Bool == false)
        {
            myCar1Bool = true;
            myCar1.setPosition(930, 190);
            if(mouseMoveBool)
            {
                mouseMove.play();
                mouseMoveBool = false;
            }
            if(clicked)
            {
                if(clickedSound)
                {
                    mouseClick.play();
                    clickedSound = false;
                }
                myCar1.setPosition(930, 200);
            }
            if(released)
            {
                clicked = false;
                released = false;
                clickedSound = true;
                menuMusic.pause();
                return 1;
            }
        }
        else if((movedX < 920 || movedX > 1000 || movedY < 190 || movedY > 360) && myCar0Bool == false && myCar2Bool == false)
        {
            myCar1Bool = false;
            mouseMoveBool = true;
            myCar1.setPosition(930, 200);
        }

        if(movedX > 1180 && movedX < 1260 && movedY > 190.0 && movedY < 360 && myCar0Bool == false && myCar1Bool == false)
        {
            myCar2Bool = true;
            myCar2.setPosition(1190, 190);
            if(mouseMoveBool)
            {
                mouseMove.play();
                mouseMoveBool = false;
            }
            if(clicked)
            {
                if(clickedSound)
                {
                    mouseClick.play();
                    clickedSound = false;
                }
                myCar2.setPosition(1190, 200);
            }
            if(released)
            {
                clicked = false;
                released = false;
                clickedSound = true;
                menuMusic.pause();
                return 2;
            }
        }
        else if((movedX < 1180 || movedX > 1260 || movedY < 190.0 || movedY > 360) && myCar0Bool == false && myCar1Bool == false)
        {
            myCar2Bool = false;
            mouseMoveBool = true;
            myCar2.setPosition(1190, 200);
        }

        if(released)
        {
            clicked = false;
            released = false;
        }

        app.clear();
        app.draw(background);
        app.draw(background1);
        app.draw(myCar0);
        if(myCar0Bool)
            app.draw(car0Info);
        app.draw(myCar1);
        if(myCar1Bool)
            app.draw(car1Info);
        app.draw(myCar2);
        if(myCar2Bool)
            app.draw(car2Info);
        app.display();
    }
}

int start(sf::RenderWindow& app, sf::Sound& menuMusic)
{
    bool wave1Starting = true, wave1 = false, wave2Starting = false, wave2 = false, losingWave = false, winningWave = false;  //to control waves
    bool firedMissile1Bool = false, firedMissile2Bool = false, firedMissile1Going = false, firedMissile2Going = false;
    bool explosion1Bool = false, explosion2Bool = false, explosion3Bool = false;
    bool grenadeBool = false, grenadeGoingBool = false;
    bool myCarBoost = false;
    bool upButton = false, downButton = false, leftButon = false, rightButton = false;
    bool explosion1Cela1Move = false, explosion1Cela2Move = false, explosion1BossMove = false;
    bool explosion2Cela1Move = false, explosion2Cela2Move = false, explosion2BossMove = false;
    bool explosion3CarMove = false;
    bool pauseButton = false;
    bool heliCopterApproachBool = true, helicopterCelaBool = true, helicopterBossBool = true;

    int i,j,x,y, selectedCar = 0;   //for loop
    int firedMissileSpeed, firedMissileBoostedSpeed = -15, firedMissileNormalSpeed = -10;
    int heliBossSpeedX = 6, heliCela1SpeedX = -4, heliCela2SpeedX = 4; //Moving helicopter speed on X
    int heliStartingSpeedY = 4, heliStartingSpeedX = 3;   // celapela & boss moving up
    int celapelaLife1 = 8, celapelaLife2 = 8, bossLife = 16;  //Every Celapela Life
    int celapelaLifePosition, bossLifePosition;   //To set the position of celapela & boss life
    int myLife = 5, myLifeMax = 7, myLifePositionX = 1280, myLifePositionY = 1020;
    int collectedMissileAmmo = 0, collectedMissileAmmoMax = 14;
    int explosion1PositionX, explosion1PositionY, explosion2PositionX, explosion2PositionY, explosion3PositionX, explosion3PositionY;
    int dividerPositionX = 925, dividerPositionY = 230;
    int myCarBoostingTime, myCarBoostingTimeMax = 14;
    int randomX, randomY;
    int winLoseTime;
    float backgroundSpeed = 5, myCarSpeedX = 7, myCarSpeedY = 7, myCarVelocityX, myCarVelocityY;

    ////////Background
    sf::Texture backgroundTex1;   ////1920*2160
    backgroundTex1.loadFromFile("Data/bg1.jpg");
    sf::Sprite background1;
    background1.setTexture(backgroundTex1);
    background1.setPosition(0,-1080);

    sf::Texture backgroundTex2;   ////1920*2160
    backgroundTex2.loadFromFile("Data/bg2.jpg");
    sf::Sprite background2;
    background2.setTexture(backgroundTex2);
    background2.setPosition(0,-3240);

    /////////Divider
    sf::Texture dividerTex;      ////70*800
    dividerTex.loadFromFile("Data/divider.png");
    sf::Sprite divider1(dividerTex);
    divider1.setPosition(dividerPositionX,dividerPositionY);
    sf::Sprite divider2(dividerTex);
    divider2.setPosition(dividerPositionX, dividerPositionY - 350 - 850);

    ////////Helicopter  //Celapela//
    sf::Texture helicopCelaTex;    ////1250*250*5*220
    helicopCelaTex.loadFromFile("Data/heli.png");
    sf::IntRect helicopCelaRect(0,0,250,220);
    sf::Sprite helicopCelaWave11, helicopCelaWave12;
    helicopCelaWave11.setTexture(helicopCelaTex);    //Celapela 1
    helicopCelaWave11.setTextureRect(helicopCelaRect);
    helicopCelaWave11.setPosition(-650,1820);   //700,20

    helicopCelaWave12.setTexture(helicopCelaTex);    //Celapela 2
    helicopCelaWave12.setTextureRect(helicopCelaRect);
    helicopCelaWave12.setPosition(2450,1820);

    ///////Celapela Lifes
    sf::Texture helicopCelaLifeTex;    //30*10
    helicopCelaLifeTex.loadFromFile("Data/celapelaLife.jpg");
    sf::Sprite helicopCelaLife1[celapelaLife1], helicopCelaLife2[celapelaLife2];

    celapelaLifePosition = helicopCelaWave11.getPosition().x + 5;
    for(i=0; i<celapelaLife1; i++)
    {
        helicopCelaLife1[i].setTexture(helicopCelaLifeTex);
        helicopCelaLife1[i].setPosition(celapelaLifePosition,10);
        celapelaLifePosition += 30;
    }

    celapelaLifePosition = helicopCelaWave12.getPosition().x + 5;
    for(i=0; i<celapelaLife2; i++)
    {
        helicopCelaLife2[i].setTexture(helicopCelaLifeTex);
        helicopCelaLife2[i].setPosition(celapelaLifePosition,10);
        celapelaLifePosition += 30;
    }

    /////////Helicopter  ///Boss//
    sf::Texture helicopBossTex;     ////1360*340*4*280
    helicopBossTex.loadFromFile("Data/heliBoss.png");
    sf::IntRect helicopBossRect(0,0,340,280);
    sf::Sprite helicopBoss(helicopBossTex, helicopBossRect);
    helicopBoss.setPosition(790,1400);

    /////////Boss Lifes
    sf::Texture helicopBossLifeTex;    //20*10
    helicopBossLifeTex.loadFromFile("Data/bossLife.jpg");
    sf::Sprite helicopBossLife[bossLife];

    bossLifePosition = helicopBoss.getPosition().x + 10;
    for(i=0; i<bossLife; i++)
    {
        helicopBossLife[i].setTexture(helicopBossLifeTex);
        helicopBossLife[i].setPosition(bossLifePosition,10);
        bossLifePosition += 20;
    }
    //Fast Aid
    sf::Texture fastAidTex;
    fastAidTex.loadFromFile("Data/fastAid.png");

    sf::Sprite fastAid(fastAidTex);
    fastAid.setPosition(1010 + rand()%250, -10940);    //-11880

    //Booster
    sf::Texture boosterTex;
    boosterTex.loadFromFile("Data/booster.png");

    sf::Sprite booster(boosterTex);
    booster.setPosition(1010 + rand()%250, -9440);    //-10880

    //Missile Ammo
    sf::Texture missileAmmoTex;
    missileAmmoTex.loadFromFile("Data/missileAmmo.png");

    sf::Sprite missileAmmo(missileAmmoTex);
    missileAmmo.setPosition(1010 + rand()%250, -7940);    //-7880

    //Collected Missile
    sf::Font collectedMissileAmmoFont;
    collectedMissileAmmoFont.loadFromFile("Data/missileFont.ttf");

    sf::Text collectedMissileAmmoText;
    collectedMissileAmmoText.setFont(collectedMissileAmmoFont);
    collectedMissileAmmoText.setCharacterSize(50);
    collectedMissileAmmoText.setPosition(670, 1015);
    collectedMissileAmmoText.setColor(sf::Color(32,32,32));

    sf::Texture collectedMissileTex;
    collectedMissileTex.loadFromFile("Data/missileCollected.png");
    sf::Sprite collectedMissileSprint(collectedMissileTex);
    collectedMissileSprint.setPosition(610,1025);

    //////Fired Missile
    sf::Texture firedMissileTex;    //250*30*10*100
    firedMissileTex.loadFromFile("Data/missile.png");
    sf::IntRect firedMissileRect(0,0,25,100);
    sf::Sprite firedMissile1,firedMissile2;

    firedMissile1.setTexture(firedMissileTex);
    firedMissile1.setTextureRect(firedMissileRect);

    firedMissile2.setTexture(firedMissileTex);
    firedMissile2.setTextureRect(firedMissileRect);

    //////Explosion
    sf::Texture explosionTex;    ////360*4*6*540
    explosionTex.loadFromFile("Data/explo.png");
    sf::Sprite explosion1, explosion2, explosion3;
    sf::IntRect explosionRect1(0,0,90,90), explosionRect2(0,0,90,90), explosionRect3(0,0,90,90);

    explosion1.setTexture(explosionTex);
    explosion1.setTextureRect(explosionRect1);

    explosion2.setTexture(explosionTex);
    explosion2.setTextureRect(explosionRect2);

    explosion3.setTexture(explosionTex);
    explosion3.setTextureRect(explosionRect3);

    //////Grenade from helicopter
    sf::Texture grenadeTex;    ////20*25
    grenadeTex.loadFromFile("Data/grenade.png");
    sf::Sprite grenade(grenadeTex);
    grenade.setOrigin(10,12);

    /////My Cars
    sf::Texture myCarTex1, myCarTex2, myCarTex3;    ////120*60*1*150
    myCarTex1.loadFromFile("Data/myCar1.png");
    myCarTex2.loadFromFile("Data/myCar2.png");
    myCarTex3.loadFromFile("Data/myCar3.png");

    sf::IntRect myCarRect(0,0,60,150);
    sf::Sprite myCar[3];
    myCar[0].setTexture(myCarTex1);
    myCar[0].setTextureRect(myCarRect);

    myCar[1].setTexture(myCarTex2);
    myCar[1].setTextureRect(myCarRect);

    myCar[2].setTexture(myCarTex3);
    myCar[2].setTextureRect(myCarRect);

    //My Life
    sf::Texture myLifeTex;
    myLifeTex.loadFromFile("Data/heart.png");

    sf::Sprite myCarLife[7];
    for(i=0;i<myLifeMax;i++)
    {
        myCarLife[i].setTexture(myLifeTex);
        myCarLife[i].setPosition(myLifePositionX, myLifePositionY);
        myLifePositionX -= 45;
    }

    ////Obstacles
    sf::Texture obstacleTex[6];
    obstacleTex[0].loadFromFile("Data/obs1.png");   //60*140
    obstacleTex[1].loadFromFile("Data/obs2.png");   //60*140
    obstacleTex[2].loadFromFile("Data/obs3.png");   //60*140
    obstacleTex[3].loadFromFile("Data/obs4.png");   //60*140
    obstacleTex[4].loadFromFile("Data/obs5.png");   //60*140
    obstacleTex[5].loadFromFile("Data/obs6.png");   //60*140

    sf::Sprite obstacle[6];
    for(i=0; i<6; i++)
        obstacle[i].setTexture(obstacleTex[i]);

    obstacle[0].setPosition(600 + rand()%260, -5530);    //50    -6730
    obstacle[1].setPosition(600 + rand()%260, -5130);    //450   -6330
    obstacle[2].setPosition(600 + rand()%260, -4730);    //850   -5930
    obstacle[3].setPosition(1010 + rand()%250, -4470);    //150  -4170
    obstacle[4].setPosition(1010 + rand()%250, -4070);    //550   -3770
    obstacle[5].setPosition(1010 + rand()%250, -3670);    //950   -3370

    //Sounds
    sf::SoundBuffer buff1;  // car starting while wave 1 starting
    buff1.loadFromFile("Data/Sound/carStart.wav");
    sf::Sound carStart;
    carStart.setBuffer(buff1);
    carStart.setVolume(40);

    sf::SoundBuffer buff2;
    buff2.loadFromFile("Data/Sound/carCollision.wav");
    sf::Sound carCollision;
    carCollision.setBuffer(buff2);

    sf::SoundBuffer buff3;
    buff3.loadFromFile("Data/Sound/grenadeExplo.wav");
    sf::Sound grenadeExplo;
    grenadeExplo.setBuffer(buff3);

    sf::SoundBuffer buff4;
    buff4.loadFromFile("Data/Sound/missileExplo.wav");
    sf::Sound missileExplo1, missileExplo2;
    missileExplo1.setBuffer(buff4);
    missileExplo2.setBuffer(buff4);

    sf::SoundBuffer buff5;
    buff5.loadFromFile("Data/Sound/pick.wav");
    sf::Sound pick;
    pick.setBuffer(buff5);

    sf::SoundBuffer buff6;
    buff6.loadFromFile("Data/Sound/helicopterCela.wav");
    sf::Sound helicopterCela;
    helicopterCela.setBuffer(buff6);

    sf::SoundBuffer buff7;
    buff7.loadFromFile("Data/Sound/helicopterApproaching1.wav");
    sf::Sound helicopterApproach;
    helicopterApproach.setBuffer(buff7);

    sf::SoundBuffer buff8;
    buff8.loadFromFile("Data/Sound/helicopterBoss.wav");
    sf::Sound helicopterBoss;
    helicopterBoss.setBuffer(buff8);
    helicopterBoss.setVolume(70);

    sf::SoundBuffer buff9;
    buff9.loadFromFile("Data/Sound/missileFired.wav");
    sf::Sound missileFired;
    missileFired.setBuffer(buff9);

    //Selecting Car
    selectedCar = select(app, background1, menuMusic, myCar[0], myCar[1], myCar[2]);
    if(selectedCar == 0)
    {
        myCarBoostingTimeMax = 10;
        myLifeMax = 7;
        collectedMissileAmmoMax = 8;
    }
    else if(selectedCar == 1)
    {
        myCarBoostingTimeMax = 8;
        myLifeMax = 5;
        collectedMissileAmmoMax = 10;
    }
    if(selectedCar == 0)
    {
        myCarBoostingTimeMax = 12;
        myLifeMax = 6;
        collectedMissileAmmoMax = 8;
    }
    myCar[selectedCar].setPosition(1100, 860);

    srand(time(NULL));
    sf::Clock helicopCloCela, helicopCloBoss, firedMissileClo;  //Helicopter IntRect (Animation)
    sf::Clock explosionClo1, explosionClo2, explosionClo3;  //1 & 2 missile, 3 grenade Explosion
    sf::Clock grenadeClo1, backgroundSpeedClo;
    sf::Clock myCarBoostingClo; // To count boosting time
    sf::Clock winningClo;

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                app.close();
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Up)
                    upButton = true;
                if(event.key.code == sf::Keyboard::Down)
                    downButton = true;
                if(event.key.code == sf::Keyboard::Left)
                    leftButon = true;
                if(event.key.code == sf::Keyboard::Right)
                    rightButton = true;
            }
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Up)
                    upButton = false;
                if(event.key.code == sf::Keyboard::Down)
                    downButton = false;
                if(event.key.code == sf::Keyboard::Left)
                    leftButon = false;
                if(event.key.code == sf::Keyboard::Right)
                    rightButton = false;
                if(event.key.code == sf::Keyboard::W)
                {
                    x = gameWin(app, background1, background2);
                }
                if(event.key.code == sf::Keyboard::L)
                {
                    x = gameLose(app, background1, background2);
                }
            }
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Space)
                {
                    if(wave1Starting)
                    {
                        carStart.pause();
                        helicopterApproach.pause();
                    }
                    else if(wave1)
                        helicopterCela.pause();
                    else
                        helicopterBoss.pause();
                    x = pause(app, background1, background2);   //// paused function
                    if(x == 1)
                        return x;

                    else if(x == 2)
                    {
                        if(wave1Starting)
                        {
                            carStart.play();
                            helicopterApproach.play();
                        }
                        else if(wave1)
                            helicopterCela.play();
                        else
                            helicopterBoss.play();
                    }
                    //// add exit option return x (0)
                }
                if(event.key.code == sf::Keyboard::N)
                {
                    if(wave1Starting)
                    {
                        wave1Starting = false;
                        wave1 = true;
                    }
                    else if(wave1)
                    {
                        wave1 = false;
                        wave2Starting = true;
                    }
                    else if(wave2Starting)
                    {
                        wave2Starting = false;
                        wave2 = true;
                    }
                }
                if(event.key.code == sf::Keyboard::F && firedMissile1Going == false && firedMissile2Going == false && collectedMissileAmmo > 0 && wave2Starting == false)
                {
                    if(myCarRect.left == 60 && collectedMissileAmmo > 1)
                    {
                        collectedMissileAmmo -= 2;
                        firedMissile1Bool = true;
                        firedMissile2Bool = true;
                        firedMissile1Going = true;
                        firedMissile2Going = true;
                        std::stringstream collectedMissileSSText;
                        collectedMissileSSText << collectedMissileAmmo;
                        collectedMissileAmmoText.setString(collectedMissileSSText.str());
                        firedMissile1.setPosition(myCar[selectedCar].getPosition().x + 5, myCar[selectedCar].getPosition().y -30);
                        firedMissile2.setPosition(myCar[selectedCar].getPosition().x + 30, myCar[selectedCar].getPosition().y -30);
                    }
                    else
                    {
                        collectedMissileAmmo--;
                        firedMissile1Bool = true;
                        firedMissile1Going = true;
                        std::stringstream collectedMissileSSText;
                        collectedMissileSSText << collectedMissileAmmo;
                        collectedMissileAmmoText.setString(collectedMissileSSText.str());
                        firedMissile1.setPosition(myCar[selectedCar].getPosition().x + 15, myCar[selectedCar].getPosition().y -30);
                    }
                    missileFired.play();
                }
            }
        }
        //Background Movement & Limits
        background1.move(0,backgroundSpeed);
        background2.move(0,backgroundSpeed);
        if(background1.getPosition().y >= 1080)
            background1.setPosition(0, background2.getPosition().y - 2160);
        if(background2.getPosition().y >= 1080)
            background2.setPosition(0, background1.getPosition().y - 2160);

        //Background Speed
        if(backgroundSpeedClo.getElapsedTime().asMilliseconds() > 1000 && backgroundSpeed <= 17)
            {
                backgroundSpeed += 0.5;
                backgroundSpeedClo.restart();
            }
        //My Car Speed Up Down on X
        if(backgroundSpeed > 8)
            myCarSpeedX = 9;
        else if(backgroundSpeed > 10)
            myCarSpeedX = 11;
        else if(backgroundSpeed > 14)
            myCarSpeedX = 12;

        //Divider Movement & Limits
        divider1.move(0, backgroundSpeed);
        divider2.move(0, backgroundSpeed);
        if(divider1.getPosition().y >= 1080)
            divider1.setPosition(dividerPositionX, divider2.getPosition().y - 350 - 850);
        if(divider2.getPosition().y >= 1080)
            divider2.setPosition(dividerPositionX, divider1.getPosition().y - 350 - 850);

        //Fast Aid Movement & Limits
        fastAid.move(0, backgroundSpeed);
        if(fastAid.getPosition().y > 1080)
        {
            if(myCar[selectedCar].getPosition().x > 870)
                fastAid.setPosition(1010 + rand()%250, -8500);
            else
                fastAid.setPosition(600 + rand()%260, -8500);
        }

        //Booster Movement & Limits
        booster.move(0, backgroundSpeed);
        if(booster.getPosition().y > 1080)
        {
            if(myCar[selectedCar].getPosition().x > 870)
                booster.setPosition(1010 + rand()%250, -9000);
            else
                booster.setPosition(600 + rand()%260, -9000);
        }

        //Missile Ammo Movement & Limits
        missileAmmo.move(0, backgroundSpeed);
        if(missileAmmo.getPosition().y > 1080)
        {
            if(myCar[selectedCar].getPosition().x > 870)
                missileAmmo.setPosition(1010 + rand()%250, -4000);
            else
                missileAmmo.setPosition(600 + rand()%260, -4000);
        }

        //////Obstacle Movement
        obstacle[0].move(0, backgroundSpeed + 1.5);
        obstacle[1].move(0, backgroundSpeed + 1.5);
        obstacle[2].move(0, backgroundSpeed + 1.5);
        obstacle[3].move(0, backgroundSpeed - 2);
        obstacle[4].move(0, backgroundSpeed - 2);
        obstacle[5].move(0, backgroundSpeed - 2);

        //Obstacles Limit Check
        for(i=0;i<3; i++)
        {
            if(obstacle[i].getPosition().y >= 1080)
            {
                randomX = 600 + rand()%260;
                obstacle[i].setPosition(randomX, -150);
            }
        }
        for(i=3;i<6; i++)
        {
            if(obstacle[i].getPosition().y >= 1080)
            {
                randomX = 1010 + rand()%250;
                obstacle[i].setPosition(randomX, -150);
            }
        }

        ////My Car Boosting
        if(myCarBoost)
        {
            myCarBoostingTime = myCarBoostingClo.getElapsedTime().asSeconds();
            myCarRect.left = 60;
            myCar[selectedCar].setTextureRect(myCarRect);
            myCarBoost = false;
        }

        if(myCarBoostingClo.getElapsedTime().asSeconds() - myCarBoostingTime > myCarBoostingTimeMax)
        {
            myCarRect.left = 0;
            myCar[selectedCar].setTextureRect(myCarRect);
        }

        ////My car Movement
        if((upButton == true && downButton == true) || (upButton == false && downButton == false))
            myCarVelocityY = 0;
        if((leftButon == true && rightButton == true)  || (upButton == false && downButton == false))
            myCarVelocityX = 0;
        if(upButton == true && downButton == false)
            myCarVelocityY = -myCarSpeedY;
        if(upButton == false && downButton == true)
            myCarVelocityY = myCarSpeedY;
        if(leftButon == true && rightButton == false)
            myCarVelocityX = -myCarSpeedX;
        if(leftButon == false && rightButton == true)
            myCarVelocityX = myCarSpeedX;

        //My car Limits & Collision    ///  X   ///
        myCar[selectedCar].move(myCarVelocityX, 0);
        if(myCar[selectedCar].getPosition().x > 1260 || myCar[selectedCar].getPosition().x < 600)
            myCar[selectedCar].move(-myCarVelocityX, 0);

        //Divider collision X
        if(myCar[selectedCar].getGlobalBounds().intersects(divider1.getGlobalBounds()) == true)
        {
            if(leftButon)
                myCar[selectedCar].move(-(myCarVelocityX + 2), 0);    // to slow down on X
            if(rightButton)
                myCar[selectedCar].move(-(myCarVelocityX - 2), 0);    // to slow down on X
            myCarBoostingTime = 16;     // will loss boosting
        }
        else if(myCar[selectedCar].getGlobalBounds().intersects(divider2.getGlobalBounds()) == true)
        {
            if(leftButon)
                myCar[selectedCar].move(-(myCarVelocityX + 2), 0);    // to slow down on X
            if(rightButton)
                myCar[selectedCar].move(-(myCarVelocityX - 2), 0);   // to slow down on X
            myCarBoostingTime = 16;    // will loss boosting
        }
        //Obstacle collision    //   x  //
        for(i=0; i<6; i++)
        {
            if(myCar[selectedCar].getGlobalBounds().intersects(obstacle[i].getGlobalBounds()) == true)
            {
                myCar[selectedCar].move(-myCarVelocityX, 0);   //need develop
                if(backgroundSpeed > 14)
                    backgroundSpeed -= 0.4;
                else if(backgroundSpeed > 9)   // max speed 17
                    backgroundSpeed -= 0.3;
                else if(backgroundSpeed > 4)
                    backgroundSpeed -= 0.2;
            }
        }
        //Grenade Collision  X
        if(myCar[selectedCar].getGlobalBounds().intersects(grenade.getGlobalBounds()) == true)
        {
            myLife--;
            grenadeExplo.play();
            explosion3Bool = true;
            explosion3CarMove = true;
            if(grenade.getPosition().x < myCar[selectedCar].getPosition().x + 30)    //explosion size 90*90
                explosion3PositionX = grenade.getPosition().x -35;   //left side -45 to -35
            else
                explosion3PositionX = grenade.getPosition().x - 55;   // right side -45 to -55
            explosion3PositionY =  grenade.getPosition().y - 40;
            explosion3.setPosition(explosion3PositionX, explosion3PositionY);
            grenade.setPosition(-50, 500);
            myCarBoostingTime -= 5;     // will short the boosting time
            if(backgroundSpeed > 12)
                backgroundSpeed -= 4;
            else if(backgroundSpeed > 8)
                backgroundSpeed -= 3;
            else
                backgroundSpeed--;
        }

        //My car Limits & Collision    ///  Y   ///
        myCar[selectedCar].move(0, myCarVelocityY);
        if(myCar[selectedCar].getPosition().y > 860 || myCar[selectedCar].getPosition().y < 400)
            myCar[selectedCar].move(0, -myCarVelocityY);

        //Divider Collision     //    Y
        if(myCar[selectedCar].getGlobalBounds().intersects(divider1.getGlobalBounds()) == true)
        {
            if(backgroundSpeed > 13)
                backgroundSpeed -= 0.35;
            else if(backgroundSpeed > 8)
                backgroundSpeed -= 0.2;
            else if(backgroundSpeed > 4)
                backgroundSpeed -= 0.15;
            myCar[selectedCar].move(0, -myCarVelocityY); //to slow down the car
        }
        else if(myCar[selectedCar].getGlobalBounds().intersects(divider2.getGlobalBounds()) == true)
        {
            if(backgroundSpeed > 13)
                backgroundSpeed -= 0.35;
            else if(backgroundSpeed > 8)
                backgroundSpeed -= 0.2;
            else if(backgroundSpeed > 4)
                backgroundSpeed -= 0.15;
            myCar[selectedCar].move(0, -myCarVelocityY);  // cant speed up on Y
        }

        //Obstacle Collision Y
        if(myCar[selectedCar].getGlobalBounds().intersects(obstacle[0].getGlobalBounds()) == true)
        {
            myLife--;
            carCollision.play();
            y = obstacle[2].getPosition().y - 800;
            obstacle[0].setPosition(600 + rand()%260, y);
            if(backgroundSpeed > 14)
                backgroundSpeed -= 7;
            else if(backgroundSpeed > 10)
                backgroundSpeed  -= 5;
            else if(backgroundSpeed > 6)
                backgroundSpeed -= 3;
            myCarBoostingTime = 16;
            if(myLife < 1)
            {
                wave1 = false;
                wave2Starting = false;
                wave2 = false;
                losingWave = true;
            }
        }
        else if(myCar[selectedCar].getGlobalBounds().intersects(obstacle[1].getGlobalBounds()) == true)
        {
            myLife--;
            carCollision.play();
            y = obstacle[0].getPosition().y - 800;
            obstacle[1].setPosition(600 + rand()%260, y);
            if(backgroundSpeed > 14)
                backgroundSpeed -= 7;
            else if(backgroundSpeed > 10)
                backgroundSpeed  -= 5;
            else if(backgroundSpeed > 6)
                backgroundSpeed -= 3;
            myCarBoostingTime = 16;
            if(myLife < 1)
            {
                wave1 = false;
                wave2Starting = false;
                wave2 = false;
                losingWave = true;
            }
        }
        else if(myCar[selectedCar].getGlobalBounds().intersects(obstacle[2].getGlobalBounds()) == true)
        {
            myLife--;
            carCollision.play();
            y = obstacle[1].getPosition().y - 800;
            obstacle[2].setPosition(600 + rand()%260, y);
            if(backgroundSpeed > 14)
                backgroundSpeed -= 7;
            else if(backgroundSpeed > 10)
                backgroundSpeed  -= 5;
            else if(backgroundSpeed > 6)
                backgroundSpeed -= 3;
            myCarBoostingTime = 16;
            if(myLife < 1)
            {
                wave1 = false;
                wave2Starting = false;
                wave2 = false;
                losingWave = true;
            }
        }

        if(myCar[selectedCar].getGlobalBounds().intersects(obstacle[3].getGlobalBounds()) == true)
        {
            myLife--;
            carCollision.play();
            y = obstacle[5].getPosition().y - 800;
            obstacle[3].setPosition(1010 + rand()%250, y);
            if(backgroundSpeed > 14)
                backgroundSpeed -= 6;
            else if(backgroundSpeed > 10)
                backgroundSpeed  -= 4;
            else if(backgroundSpeed > 7)
                backgroundSpeed -= 3;
            else if(backgroundSpeed > 5)
                backgroundSpeed--;
            myCarBoostingTime = 16;
            if(myLife < 1)
            {
                wave1 = false;
                wave2Starting = false;
                wave2 = false;
                losingWave = true;
            }
        }
        else if(myCar[selectedCar].getGlobalBounds().intersects(obstacle[4].getGlobalBounds()) == true)
        {
            myLife--;
            carCollision.play();
            y = obstacle[3].getPosition().y - 800;
            obstacle[4].setPosition(1010 + rand()%250, y);
            if(backgroundSpeed > 14)
                backgroundSpeed -= 6;
            else if(backgroundSpeed > 10)
                backgroundSpeed  -= 4;
            else if(backgroundSpeed > 7)
                backgroundSpeed -= 3;
            else if(backgroundSpeed > 5)
                backgroundSpeed--;
            myCarBoostingTime = 16;
            if(myLife < 1)
            {
                wave1 = false;
                wave2Starting = false;
                wave2 = false;
                losingWave = true;
            }
        }
        else if(myCar[selectedCar].getGlobalBounds().intersects(obstacle[5].getGlobalBounds()) == true)
        {
            myLife--;
            carCollision.play();
            y = obstacle[4].getPosition().y - 800;
            obstacle[5].setPosition(1010 + rand()%250, y);
            if(backgroundSpeed > 14)
                backgroundSpeed -= 6;
            else if(backgroundSpeed > 10)
                backgroundSpeed  -= 4;
            else if(backgroundSpeed > 7)
                backgroundSpeed -= 3;
            else if(backgroundSpeed > 5)
                backgroundSpeed--;
            myCarBoostingTime = 16;
            if(myLife < 1)
            {
                wave1 = false;
                wave2Starting = false;
                wave2 = false;
                losingWave = true;
            }
        }
        //Grenade Collision  Y
        if(myCar[selectedCar].getGlobalBounds().intersects(grenade.getGlobalBounds()) == true)
        {
            myLife--;
            grenadeExplo.play();
            explosion3Bool = true;
            explosion3CarMove = true;
            explosion3PositionX = grenade.getPosition().x - 45;
            explosion3PositionY =  grenade.getPosition().y - 30;
            explosion3.setPosition(explosion3PositionX, explosion3PositionY);
            grenade.setPosition(-50, 500);
            myCarBoostingTime -= 5;     // will short the boosting time
            if(backgroundSpeed > 12)
                backgroundSpeed -= 4;
            else if(backgroundSpeed > 8)
                backgroundSpeed -= 3;
            else
                backgroundSpeed--;
        }

        ///////////       Collecting Collision
        //Missile Ammo Collection
        if(myCar[selectedCar].getGlobalBounds().intersects(missileAmmo.getGlobalBounds()) == true)
        {
            pick.play();
            if(collectedMissileAmmo <= collectedMissileAmmoMax)
                collectedMissileAmmo += 4;
            if(missileAmmo.getPosition().x > 870)
                missileAmmo.setPosition(1010 + rand()%250, -4500);     // 600 + rand()%260
            else
                missileAmmo.setPosition(600 + rand()%260, -4500);   // 1010 + rand()%250
            std::stringstream collectedMissileSSText;
            collectedMissileSSText << collectedMissileAmmo;
            collectedMissileAmmoText.setString(collectedMissileSSText.str());
        }
        //Booster Collection
        if(myCar[selectedCar].getGlobalBounds().intersects(booster.getGlobalBounds()) == true)
        {
            pick.play();
            myCarBoost = true;
            if(booster.getPosition().x > 870)
                booster.setPosition(1010 + rand()%250, -10000);
            else
                booster.setPosition(600 + rand()%260, -10000);
        }
        //Fast Aid Collection
        if(myCar[selectedCar].getGlobalBounds().intersects(fastAid.getGlobalBounds()) == true)
        {
            pick.play();
            if(myLife < myLifeMax)
                myLife++;
            if(fastAid.getPosition().x > 870)
                fastAid.setPosition(1010 + rand()%250, -9500);
            else
                fastAid.setPosition(600 + rand()%260, -9500);
        }

        /////Fired Missile
        if(firedMissile2Bool && firedMissile2Going)
        {
            firedMissileSpeed = firedMissileBoostedSpeed;
            if(firedMissileClo.getElapsedTime().asMilliseconds() > 80)
            {
                if(firedMissileRect.left == 225)
                    firedMissileRect.left = 0;
                else
                    firedMissileRect.left += 25;
                firedMissile1.setTextureRect(firedMissileRect);
                firedMissile2.setTextureRect(firedMissileRect);
                firedMissileClo.restart();
            }

            firedMissile1.move(0, firedMissileSpeed);
            firedMissile2.move(0, firedMissileSpeed);

            if(firedMissile1.getPosition().y < -50)
            {
                firedMissile1Bool = false;
                firedMissile1Going = false;
                firedMissile1.setPosition(-200,-200);
            }
            if(firedMissile2.getPosition().y < -50)
            {
                firedMissile2Bool = false;
                firedMissile2Going = false;
                firedMissile2.setPosition(-200,-200);
            }
        }
        else if(firedMissile1Bool && firedMissile1Going)
        {
            firedMissileSpeed = firedMissileNormalSpeed;
            if(firedMissileClo.getElapsedTime().asMilliseconds() > 80)
            {
                if(firedMissileRect.left == 225)
                    firedMissileRect.left = 0;
                else
                    firedMissileRect.left += 25;
                firedMissile1.setTextureRect(firedMissileRect);
                firedMissileClo.restart();
            }
            firedMissile1.move(0, firedMissileSpeed);

            if(firedMissile1.getPosition().y < -50)
            {
                firedMissile1Bool = false;
                firedMissile1Going = false;
                firedMissile1.setPosition(-200,-200);
            }
        }

        ////////Explosion
        if(explosion1Bool)     //// for missile 1
        {
            if(explosionClo1.getElapsedTime().asMilliseconds() > 60)
            {
                if(explosionRect1.left == 270)
                {
                    explosionRect1.top += 90;
                    explosionRect1.left = 0;
                }
                else
                    explosionRect1.left += 90;
                if(explosionRect1.top == 540)
                {
                    explosion1Bool = false;
                    explosion1Cela1Move = false;
                    explosion1Cela2Move = false;
                    explosion1BossMove = false;
                    explosionRect1.top = 0;
                    explosionRect1.left = 0;
                    if(celapelaLife1 < 1)
                        helicopCelaWave11.setPosition(700, -300);
                    else if(celapelaLife2 < 1)
                        helicopCelaWave12.setPosition(1100, -300);
                    if(bossLife < 1)  // winning check
                    {
                        wave2 = false;
                        winningWave = true;
                        helicopterBoss.pause();
                    }
                    else if(celapelaLife1 < 1 && celapelaLife2 < 1)
                    {
                        wave1 = false;
                        wave2Starting = true;
                        helicopterCela.pause();
                    }
                }
                explosion1.setTextureRect(explosionRect1);
                explosionClo1.restart();
            }
            if(explosion1Cela1Move)
                explosion1.move(heliCela1SpeedX, 0);
            else if(explosion1Cela2Move)
                explosion1.move(heliCela2SpeedX, 0);
            else if(explosion1BossMove)
                explosion1.move(heliBossSpeedX, 0);
        }

        if(explosion2Bool)    //// for missile 2
        {
            if(explosionClo2.getElapsedTime().asMilliseconds() > 60)
            {
                if(explosionRect2.left == 270)
                {
                    explosionRect2.top += 90;
                    explosionRect2.left = 0;
                }
                else
                    explosionRect2.left += 90;
                if(explosionRect2.top == 540)
                {
                    explosion2Bool = false;
                    explosion2Cela1Move = false;
                    explosion2Cela2Move = false;
                    explosion2BossMove = false;
                    explosionRect2.top = 0;
                    explosionRect2.left = 0;
                    if(celapelaLife1 < 1)
                        helicopCelaWave11.setPosition(700, -300);
                    else if(celapelaLife2 < 1)
                        helicopCelaWave12.setPosition(1100, -300);
                    if(bossLife < 1) // winning check
                    {
                        wave2 = false;
                        winningWave = true;
                        helicopterBoss.pause();
                    }
                    else if(celapelaLife1 < 1 && celapelaLife2 < 1)
                    {
                        wave1 = false;
                        wave2Starting = true;
                        helicopterCela.pause();
                    }
                }
                explosion2.setTextureRect(explosionRect2);
                explosionClo2.restart();
            }
            if(explosion2Cela1Move)
                explosion2.move(heliCela1SpeedX, 0);
            else if(explosion2Cela2Move)
                explosion2.move(heliCela2SpeedX, 0);
            else if(explosion2BossMove)
                explosion2.move(heliBossSpeedX, 0);
        }

        if(explosion3Bool)     //// for grenade
        {
            if(explosionClo3.getElapsedTime().asMilliseconds() > 60)
            {
                if(explosionRect3.left == 270)
                {
                    explosionRect3.top += 90;
                    explosionRect3.left = 0;
                }
                else
                    explosionRect3.left += 90;
                if(explosionRect3.top == 540)
                {
                    explosion3Bool = false;
                    explosion3CarMove = false;
                    explosionRect3.top = 0;
                    explosionRect3.left = 0;
                    if(myLife < 1)
                    {
                        wave1 = false;
                        wave2Starting = false;
                        wave2 = false;
                        losingWave = true;
                    }
                }
                explosion3.setTextureRect(explosionRect3);
                explosionClo3.restart();
            }
            if(explosion3CarMove)
                explosion3.move(myCarVelocityX, myCarVelocityY);
        }

        if(wave1Starting)   // 2 helicopter & Boss Going Up
        {
            if(heliCopterApproachBool)
            {
                carStart.play();
                helicopterApproach.play();
                heliCopterApproachBool = false;
            }
            if(helicopCloCela.getElapsedTime().asMilliseconds() > 10) //Celapela
            {
                if(helicopCelaRect.left == 1000)
                    helicopCelaRect.left = 0;
                else
                    helicopCelaRect.left += 250;
                helicopCelaWave11.setTextureRect(helicopCelaRect);
                helicopCelaWave12.setTextureRect(helicopCelaRect);
                helicopCloCela.restart();
            }
            helicopCelaWave11.move(heliStartingSpeedX, -heliStartingSpeedY);
            helicopCelaWave12.move(-heliStartingSpeedX, -heliStartingSpeedY);

            if(helicopCloBoss.getElapsedTime().asMilliseconds() > 30)  //Boss
            {
                if(helicopBossRect.left == 1020)
                    helicopBossRect.left = 0;
                else
                    helicopBossRect.left += 340;
                helicopBoss.setTextureRect(helicopBossRect);
                helicopCloBoss.restart();
            }
            helicopBoss.move(0, -heliStartingSpeedY);

            if(helicopCelaWave11.getPosition().y < 20)
            {
                wave1Starting = false;
                wave1 = true;
                helicopterApproach.pause();
                celapelaLifePosition = helicopCelaWave11.getPosition().x + 15;
                for(i=0; i<celapelaLife1; i++)
                {
                    helicopCelaLife1[i].setTexture(helicopCelaLifeTex);
                    helicopCelaLife1[i].setPosition(celapelaLifePosition,10);
                    celapelaLifePosition += 30;
                }

                celapelaLifePosition = helicopCelaWave12.getPosition().x + 15;
                for(i=0; i<celapelaLife2; i++)
                {
                    helicopCelaLife2[i].setTexture(helicopCelaLifeTex);
                    helicopCelaLife2[i].setPosition(celapelaLifePosition,10);
                    celapelaLifePosition += 30;
                }
            }
            app.clear();
            app.draw(background1);
            app.draw(background2);
            app.draw(divider1);
            app.draw(divider2);
            app.draw(myCar[selectedCar]);
            app.draw(helicopCelaWave11);
            app.draw(helicopCelaWave12);
            app.draw(helicopBoss);
            app.display();
        }

        if(wave1)  //2 helicopter moving
        {
            //Helicopter Cela Sound
            if(helicopterCelaBool)
            {
                helicopterApproach.pause();  // comment it
                helicopterCela.play();
                helicopterCelaBool = false;
            }
            helicopterCela.setLoop(true);

            //Helicopter Animetion & Movement Celapela
            if(helicopCloCela.getElapsedTime().asMilliseconds() > 10) //Celapela
            {
                if(helicopCelaRect.left == 1000)
                    helicopCelaRect.left = 0;
                else
                    helicopCelaRect.left += 250;
                helicopCelaWave11.setTextureRect(helicopCelaRect);
                helicopCelaWave12.setTextureRect(helicopCelaRect);
                helicopCloCela.restart();
            }
            //Helicopter and Life Movement
            helicopCelaWave11.move(heliCela1SpeedX,0);
            for(i=0; i<celapelaLife1; i++)
                helicopCelaLife1[i].move(heliCela1SpeedX,0);
            if(helicopCelaWave11.getPosition().x < 450 || helicopCelaWave11.getPosition().x > 770)
                heliCela1SpeedX = -heliCela1SpeedX;

            helicopCelaWave12.move(heliCela2SpeedX,0);
            for(i=0; i<celapelaLife2; i++)
                helicopCelaLife2[i].move(heliCela2SpeedX,0);
            if(helicopCelaWave12.getPosition().x <  900|| helicopCelaWave12.getPosition().x > 1220)
                heliCela2SpeedX = -heliCela2SpeedX;

            //Missile    1    Collision
            //Celapela 1 Collision
            if((helicopCelaWave11.getPosition().x - firedMissile1.getPosition().x < -50) && (helicopCelaWave11.getPosition().x  - firedMissile1.getPosition().x > - 175) && firedMissile1.getPosition().y < 210 && firedMissile1.getPosition().y > 70 && celapelaLife1 > 0)
            {
                explosion1PositionX = firedMissile1.getPosition().x - 30;
                if((helicopCelaWave11.getPosition().x  - firedMissile1.getPosition().x < -70) && (helicopCelaWave11.getPosition().x  - firedMissile1.getPosition().x > -155) && firedMissile1.getPosition().y > 150)
                {
                    missileExplo1.play();
                    explosion1Bool = true;    //// lej
                    firedMissile1Bool = false;
                    firedMissile1Going = false;
                    explosion1Cela1Move = true;
                    explosion1PositionY = 190;
                    firedMissile1.setPosition(50, 500);
                    explosion1.setPosition(explosion1PositionX, explosion1PositionY);
                    celapelaLife1--;
                }
                else if(firedMissile1.getPosition().y < 130)
                {
                    missileExplo1.play();
                    explosion1Bool = true;     //body
                    firedMissile1Bool = false;
                    firedMissile1Going = false;
                    explosion1Cela1Move = true;
                    explosion1PositionY = 100;
                    firedMissile1.setPosition(50, 500);
                    explosion1.setPosition(explosion1PositionX, explosion1PositionY);
                    celapelaLife1--;
                }
            }
            //Celapela 2 Collision
            if((helicopCelaWave12.getPosition().x - firedMissile1.getPosition().x < -50) && (helicopCelaWave12.getPosition().x - firedMissile1.getPosition().x > -175) && firedMissile1.getPosition().y < 210 && firedMissile1.getPosition().y > 70 && celapelaLife2 > 0)
            {
                explosion1PositionX = firedMissile1.getPosition().x - 30;
                if((helicopCelaWave12.getPosition().x - firedMissile1.getPosition().x < -70) && (helicopCelaWave12.getPosition().x - firedMissile1.getPosition().x > -155) && firedMissile1.getPosition().y > 150)
                {
                    missileExplo1.play();
                    explosion1Bool = true;   //lej
                    firedMissile1Bool = false;
                    firedMissile1Going = false;
                    explosion1Cela2Move = true;
                    explosion1PositionY = 190;
                    firedMissile1.setPosition(50, 500);
                    explosion1.setPosition(explosion1PositionX, explosion1PositionY);
                    celapelaLife2--;
                }
                else if(firedMissile1.getPosition().y < 130)
                {
                    missileExplo1.play();
                    explosion1Bool = true;    //body
                    firedMissile1Bool = false;
                    firedMissile1Going = false;
                    explosion1Cela2Move = true;
                    explosion1PositionY = 100;
                    firedMissile1.setPosition(50, 500);
                    explosion1.setPosition(explosion1PositionX, explosion1PositionY);
                    celapelaLife2--;
                }
            }
            //Missile    2    Collision
            //Celapela 1 collision
            if((helicopCelaWave11.getPosition().x - firedMissile2.getPosition().x < -50) && (helicopCelaWave11.getPosition().x  - firedMissile2.getPosition().x > - 175) && firedMissile2.getPosition().y < 210 && firedMissile2.getPosition().y > 70 && celapelaLife1 > 0)
            {
                explosion2PositionX = firedMissile2.getPosition().x - 30;
                if((helicopCelaWave11.getPosition().x  - firedMissile2.getPosition().x < -70) && (helicopCelaWave11.getPosition().x  - firedMissile2.getPosition().x > -155) && firedMissile2.getPosition().y > 150)
                {
                    missileExplo2.play();
                    explosion2Bool = true;  //lej
                    firedMissile2Bool = false;
                    firedMissile2Going = false;
                    explosion2Cela1Move = true;
                    explosion2PositionY = 190;
                    firedMissile2.setPosition(50, 500);
                    explosion2.setPosition(explosion2PositionX, explosion2PositionY);
                    celapelaLife1--;
                }
                else if(firedMissile2.getPosition().y < 130)
                {
                    missileExplo2.play();
                    explosion2Bool = true;   //body
                    firedMissile2Bool = false;
                    firedMissile2Going = false;
                    explosion2Cela1Move = true;
                    explosion2PositionY = 100;
                    firedMissile2.setPosition(50, 500);
                    explosion2.setPosition(explosion2PositionX, explosion2PositionY);
                    celapelaLife1--;
                }
            }
            //Celapela 2 Collision
            if((helicopCelaWave12.getPosition().x - firedMissile2.getPosition().x < -50) && (helicopCelaWave12.getPosition().x - firedMissile2.getPosition().x > -175) && firedMissile2.getPosition().y < 210 && firedMissile2.getPosition().y > 70 && celapelaLife2 > 0)
            {
                explosion2PositionX = firedMissile2.getPosition().x - 30;
                if((helicopCelaWave12.getPosition().x - firedMissile2.getPosition().x < -70) && (helicopCelaWave12.getPosition().x - firedMissile2.getPosition().x > -155) && firedMissile2.getPosition().y > 150)
                {
                    missileExplo2.play();
                    explosion2Bool = true;   //lej
                    firedMissile2Bool = false;
                    firedMissile2Going = false;
                    explosion2Cela2Move = true;
                    explosion2PositionY = 190;
                    firedMissile2.setPosition(50, 500);
                    explosion2.setPosition(explosion2PositionX, explosion2PositionY);
                    celapelaLife2--;
                }
                else if(firedMissile2.getPosition().y < 130)
                {
                    missileExplo2.play();
                    explosion2Bool = true;   //body
                    firedMissile2Bool = false;
                    firedMissile2Going = false;
                    explosion2Cela2Move = true;
                    explosion2PositionY = 100;
                    firedMissile2.setPosition(50, 500);
                    explosion2.setPosition(explosion2PositionX, explosion2PositionY);
                    celapelaLife2--;
                }
            }

            app.clear();
            app.draw(background1);
            app.draw(background2);
            app.draw(divider1);
            app.draw(divider2);
            app.draw(missileAmmo);
            app.draw(booster);
            app.draw(fastAid);
            for(i=0;i<6;i++)
                app.draw(obstacle[i]);
            if(celapelaLife1 > 0 || explosion1Bool || explosion2Bool)
            {
                app.draw(helicopCelaWave11);
                for(i=0; i<celapelaLife1; i++)
                    app.draw(helicopCelaLife1[i]);
            }
            if(celapelaLife2 > 0 || explosion1Bool || explosion2Bool)
            {
                app.draw(helicopCelaWave12);
                for(i=0; i<celapelaLife2; i++)
                    app.draw(helicopCelaLife2[i]);
            }
            app.draw(myCar[selectedCar]);
            for(i=0;i<myLife;i++)
                app.draw(myCarLife[i]);
            app.draw(collectedMissileAmmoText);
            app.draw(collectedMissileSprint);
            if(firedMissile1Bool)
                app.draw(firedMissile1);
            if(firedMissile2Bool)
                app.draw(firedMissile2);
            if(explosion1Bool)
                app.draw(explosion1);
            if(explosion2Bool)
                app.draw(explosion2);
            if(explosion3Bool)
                app.draw(explosion3);
            app.display();
        }

        else if(wave2Starting)
        {
            if(helicopterBossBool)
            {
                helicopterCela.pause();  // comment it
                helicopterBoss.play();
                helicopterBossBool = false;
            }
            helicopterBoss.setLoop(true);

            //Helicopter Animetion & Movement Boss
            if(helicopCloBoss.getElapsedTime().asMilliseconds() > 30)
            {
                if(helicopBossRect.left == 1020)
                    helicopBossRect.left = 0;
                else
                    helicopBossRect.left += 340;
                helicopBoss.setTextureRect(helicopBossRect);
                helicopCloBoss.restart();
            }
            helicopBoss.move(0, heliStartingSpeedY - 2);  //heliStartingSpeedY = 4

            if(helicopBoss.getPosition().y >= 20)
            {
                wave2Starting = false;
                wave2 = true;
            }

            app.clear();
            app.draw(background1);
            app.draw(background2);
            app.draw(divider1);
            app.draw(divider2);
            app.draw(missileAmmo);
            app.draw(booster);
            app.draw(fastAid);
            for(i=0;i<6;i++)
                app.draw(obstacle[i]);
            app.draw(helicopBoss);
            app.draw(myCar[selectedCar]);
            for(i=0;i<myLife;i++)
                app.draw(myCarLife[i]);
            app.draw(collectedMissileAmmoText);  // to print the number of missiles collected
            app.draw(collectedMissileSprint);
            app.display();
        }

        else if(wave2)  //Wave Boss
        {
            //Helicopter Animetion & Movement Boss
            if(helicopCloBoss.getElapsedTime().asMilliseconds() > 30)
            {
                if(helicopBossRect.left == 1020)
                    helicopBossRect.left = 0;
                else
                    helicopBossRect.left += 340;
                helicopBoss.setTextureRect(helicopBossRect);
                helicopCloBoss.restart();
            }
            helicopBoss.move(heliBossSpeedX,0);
            for(i=0; i<bossLife; i++)
                helicopBossLife[i].move(heliBossSpeedX,0);
            if(helicopBoss.getPosition().x < 370 || helicopBoss.getPosition().x > 1250)
                heliBossSpeedX = -heliBossSpeedX;

            //Grenade Throwing
            if(((helicopBoss.getPosition().x + 120 - myCar[selectedCar].getPosition().x) < 20) && ((helicopBoss.getPosition().x + 120 - myCar[selectedCar].getPosition().x)  > 0) && grenadeGoingBool == false)
            {
                grenadeBool = true;
                grenadeGoingBool = true;
                grenade.setPosition(helicopBoss.getPosition().x + 140, 150);
            }
            //Missile    1    Collision
            if((helicopBoss.getPosition().x - firedMissile1.getPosition().x < -40) && (helicopBoss.getPosition().x  - firedMissile1.getPosition().x > - 265) && firedMissile1.getPosition().y < 260 && firedMissile1.getPosition().y > 80 && bossLife > 0)
            {
                explosion1PositionX = firedMissile1.getPosition().x - 30;
                if((helicopBoss.getPosition().x  - firedMissile1.getPosition().x < -115) && (helicopBoss.getPosition().x  - firedMissile1.getPosition().x > -205) && firedMissile1.getPosition().y > 220)
                {
                    missileExplo1.play();
                    explosion1Bool = true;
                    firedMissile1Bool = false;
                    firedMissile1Going = false;
                    explosion1BossMove = true;
                    explosion1PositionY = 240;
                    firedMissile1.setPosition(50, 500);
                    explosion1.setPosition(explosion1PositionX, explosion1PositionY);
                    bossLife--;
                }
                else if(firedMissile1.getPosition().y < 130)
                {
                    missileExplo1.play();
                    explosion1Bool = true;
                    firedMissile1Bool = false;
                    firedMissile1Going = false;
                    explosion1BossMove = true;
                    explosion1PositionY = 120;
                    firedMissile1.setPosition(50, 500);
                    explosion1.setPosition(explosion1PositionX, explosion1PositionY);
                    bossLife--;
                }
            }
            //Missile    2    Collision
            if((helicopBoss.getPosition().x - firedMissile2.getPosition().x < -40) && (helicopBoss.getPosition().x  - firedMissile2.getPosition().x > - 265) && firedMissile2.getPosition().y < 260 && firedMissile2.getPosition().y > 80 && bossLife > 0)
            {
                explosion2PositionX = firedMissile2.getPosition().x - 30;
                if((helicopBoss.getPosition().x  - firedMissile2.getPosition().x < -115) && (helicopBoss.getPosition().x  - firedMissile2.getPosition().x > -205) && firedMissile1.getPosition().y > 220)
                {
                    missileExplo2.play();
                    explosion2Bool = true;
                    firedMissile2Bool = false;
                    firedMissile2Going = false;
                    explosion2BossMove = true;
                    explosion2PositionY = 240;
                    firedMissile2.setPosition(50, 500);
                    explosion2.setPosition(explosion2PositionX, explosion2PositionY);
                    bossLife--;
                }
                else if(firedMissile2.getPosition().y < 130)
                {
                    missileExplo2.play();
                    explosion2Bool = true;
                    firedMissile2Bool = false;
                    firedMissile2Going = false;
                    explosion2BossMove = true;
                    explosion2PositionY = 120;
                    firedMissile2.setPosition(50, 500);
                    explosion2.setPosition(explosion2PositionX, explosion2PositionY);
                    bossLife--;
                }
            }

            grenade.move(0,backgroundSpeed);
            if(grenade.getPosition().y > 1080)
                grenadeGoingBool = false;

            app.clear();
            app.draw(background1);
            app.draw(background2);
            app.draw(divider1);
            app.draw(divider2);
            app.draw(missileAmmo);
            app.draw(booster);
            app.draw(fastAid);
            if(grenadeBool)
                app.draw(grenade);
            for(i=0;i<6;i++)
                app.draw(obstacle[i]);
            app.draw(helicopBoss);
            for(i=0; i<bossLife; i++)
                app.draw(helicopBossLife[i]);
            app.draw(myCar[selectedCar]);
            for(i=0;i<myLife;i++)
                app.draw(myCarLife[i]);
            app.draw(collectedMissileAmmoText);
            app.draw(collectedMissileSprint);
            if(firedMissile1Bool)
                app.draw(firedMissile1);
            if(firedMissile2Bool)
                app.draw(firedMissile2);
            if(explosion1Bool)
                app.draw(explosion1);
            if(explosion2Bool)
                app.draw(explosion2);
            if(explosion3Bool)
                app.draw(explosion3);
            app.display();
        }

        else if(losingWave)
        {
            //Helicopter Animetion & Movement Boss
            if(helicopCloBoss.getElapsedTime().asMilliseconds() > 30)
            {
                if(helicopBossRect.left == 1020)
                    helicopBossRect.left = 0;
                else
                    helicopBossRect.left += 340;
                helicopBoss.setTextureRect(helicopBossRect);
                helicopCloBoss.restart();
            }

            helicopBoss.move(0, -1.5);
            myCar[selectedCar].move(-myCarVelocityX, -myCarVelocityY);
            backgroundSpeed = 5;
            myCar[selectedCar].move(0, backgroundSpeed);

            if(helicopBoss.getPosition().y < -280)
            {
                helicopterBoss.pause();
                x = gameLose(app, background1, background2);
                return x;
            }

            app.clear();
            app.draw(background1);
            app.draw(background2);
            app.draw(divider1);
            app.draw(divider2);
            app.draw(missileAmmo);
            app.draw(booster);
            app.draw(fastAid);
            //if(grenadeBool)
                //app.draw(grenade);
            for(i=0;i<6;i++)
                app.draw(obstacle[i]);
            app.draw(helicopBoss);
            //for(i=0; i<bossLife; i++)
                //app.draw(helicopBossLife[i]);
            app.draw(myCar[selectedCar]);
            //for(i=0;i<myLife;i++)
                //app.draw(myCarLife[i]);
            //app.draw(collectedMissileAmmoText);
            //app.draw(collectedMissileSprint);
            if(firedMissile1Bool)
                app.draw(firedMissile1);
            if(firedMissile2Bool)
                app.draw(firedMissile2);
            if(explosion1Bool)
                app.draw(explosion1);
            if(explosion2Bool)
                app.draw(explosion2);
            if(explosion3Bool)
                app.draw(explosion3);
            app.display();
        }

        else if(winningWave)
        {
            if(backgroundSpeed > 5)
                backgroundSpeed -= 2;

            if(helicopBoss.getPosition().x < 700 && helicopBoss.getPosition().y < 150)
            {
                helicopBoss.move(1,2);
                helicopBoss.rotate(0.1);
            }
            else if(helicopBoss.getPosition().x > 700 && helicopBoss.getPosition().y < 150)
            {
                helicopBoss.move(-1,2);
                helicopBoss.rotate(-0.1);
            }
            else
                helicopBoss.move(0,backgroundSpeed);

            if(helicopBoss.getPosition().y > 600)
            {
                x = gameWin(app, background1, background2);
                return x;
            }

            app.clear();
            app.draw(background1);
            app.draw(background2);
            app.draw(divider1);
            app.draw(divider2);
            app.draw(missileAmmo);
            app.draw(booster);
            app.draw(fastAid);
            //if(grenadeBool)
                //app.draw(grenade);
            for(i=0;i<6;i++)
                app.draw(obstacle[i]);
            app.draw(helicopBoss);
            //for(i=0; i<bossLife; i++)
                //app.draw(helicopBossLife[i]);
            app.draw(myCar[selectedCar]);
            for(i=0;i<myLife;i++)
                app.draw(myCarLife[i]);
            app.draw(collectedMissileAmmoText);
            app.draw(collectedMissileSprint);
            if(firedMissile1Bool)
                app.draw(firedMissile1);
            if(firedMissile2Bool)
                app.draw(firedMissile2);
            if(explosion1Bool)
                app.draw(explosion1);
            if(explosion2Bool)
                app.draw(explosion2);
            if(explosion3Bool)
                app.draw(explosion3);
            app.display();
        }
    }
}

int main()
{
    sf::RenderWindow app(sf::VideoMode(), "SFML window", sf::Style::Fullscreen);
    app.setFramerateLimit(30);

    bool clickedSound = true;
    bool clicked = false, released = false, mouseMoveBool = true;
    bool exitButton = false, rulesButton = false, storyButton = false, startButton = false;
    float movedX, movedY;

    int abc;

    sf::Font font;
    font.loadFromFile("Data/pausedFont.otf");
    sf::Text exitText, rulesText, bestText, storyText, startText;

    exitText.setFont(font);
    exitText.setString("EXIT");
    exitText.setCharacterSize(70);
    exitText.setPosition(1500, 400);
    exitText.setColor(sf::Color::White);

    rulesText.setFont(font);
    rulesText.setString("RULES");
    rulesText.setCharacterSize(70);
    rulesText.setPosition(1500, 500);
    rulesText.setColor(sf::Color::White);

    storyText.setFont(font);
    storyText.setString("STORY");
    storyText.setCharacterSize(70);
    storyText.setPosition(1500, 700);
    storyText.setColor(sf::Color::White);

    startText.setFont(font);
    startText.setString("START");
    startText.setCharacterSize(70);
    startText.setPosition(1500, 800);
    startText.setColor(sf::Color::White);

    //Background
    sf::Texture backgroundTex;
    backgroundTex.loadFromFile("Data/menuBg.png");
    sf::Sprite background(backgroundTex);

    sf::SoundBuffer buff1;
    buff1.loadFromFile("Data/Sound/menuMusic.wav");
    sf::Sound menuMusic;
    menuMusic.setBuffer(buff1);
    menuMusic.play();

    sf::SoundBuffer buff2;
    buff2.loadFromFile("Data/Sound/mouseClick.wav");
    sf::Sound mouseClick;
    mouseClick.setBuffer(buff2);
    mouseClick.setVolume(150);

    sf::SoundBuffer buff3;
    buff3.loadFromFile("Data/Sound/mouseMove.wav");
    sf::Sound mouseMove;
    mouseMove.setBuffer(buff3);

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                app.close();
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                clicked = true;
            }
            else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                released = true;

            if(event.type == sf::Event::MouseMoved)
            {
                movedX = event.mouseMove.x;
                movedY = event.mouseMove.y;
            }

        }

        if(movedX > 1490.0 && movedX < 1640.0 && movedY > 405.0 && movedY < 475.0 && rulesButton == false && storyButton == false && startButton == false)
        {
            exitButton = true;
            if(mouseMoveBool)
            {
                mouseMove.play();
                mouseMoveBool = false;
            }
            exitText.setPosition(1480, 400);
            exitText.setColor(sf::Color::Black);
            if(clicked)
            {
                if(clickedSound)
                {
                    mouseClick.play();
                    clickedSound = false;
                }
                exitText.setColor(sf::Color::Green);
                exitText.setCharacterSize(65);
            }
            if(released)
            {
                clicked = false;
                released = false;
                clickedSound = true;
                exitText.setCharacterSize(70);
                app.close();
            }
        }
        else if((movedX < 1490.0 || movedX > 1640.0 || movedY < 405.0 || movedY > 475.0) && rulesButton == false && storyButton == false && startButton == false)
        {
            exitButton = false;
            mouseMoveBool = true;
            exitText.setPosition(1500, 400);
            exitText.setColor(sf::Color::White);
        }

        if(movedX > 1490.0 && movedX < 1670.0 && movedY > 510.0 && movedY < 575.0 && exitButton == false && storyButton == false && startButton == false)
        {
            rulesButton = true;
            if(mouseMoveBool)
            {
                mouseMove.play();
                mouseMoveBool = false;
            }
            rulesText.setPosition(1480, 500);
            rulesText.setColor(sf::Color::Black);
            if(clicked)
            {
                if(clickedSound)
                {
                    mouseClick.play();
                    clickedSound = false;
                }
                rulesText.setColor(sf::Color::Green);
                rulesText.setCharacterSize(60);
            }
            if(released)
            {
                clicked = false;
                released = false;
                clickedSound = true;
                rulesText.setCharacterSize(70);
                //// rules function
            }
        }
        else if((movedX < 1490.0 || movedX > 1670.0 || movedY < 510.0 || movedY > 575.0) && exitButton == false && storyButton == false && startButton == false)
        {
            rulesButton = false;
            mouseMoveBool = true;
            rulesText.setPosition(1500, 500);
            rulesText.setColor(sf::Color::White);
        }

        if(movedX > 1490.0 && movedX < 1670.0 && movedY > 605.0 && movedY < 675.0 && exitButton == false && rulesButton == false && startButton == false)
        {
            storyButton = true;
            if(mouseMoveBool)
            {
                mouseMove.play();
                mouseMoveBool = false;
            }
            storyText.setPosition(1480, 600);
            storyText.setColor(sf::Color::Black);
            if(clicked)
            {
                if(clickedSound)
                {
                    mouseClick.play();
                    clickedSound = false;
                }
                storyText.setColor(sf::Color::Green);
                storyText.setCharacterSize(60);
            }
            if(released)
            {
                clicked = false;
                released = false;
                clickedSound = true;
                storyText.setCharacterSize(70);
                // story function
            }
        }
        else if((movedX < 1490.0 || movedX > 1670.0 || movedY < 605.0 || movedY > 675.0) && exitButton == false && rulesButton == false && startButton == false)
        {
            storyButton = false;
            mouseMoveBool = true;
            storyText.setPosition(1500, 600);
            storyText.setColor(sf::Color::White);
        }

        if(movedX > 1490.0 && movedX < 1670.0 && movedY > 705.0 && movedY < 780.0 && exitButton == false && rulesButton == false && storyButton == false)
        {
            startButton = true;
            if(mouseMoveBool)
            {
                mouseMove.play();
                mouseMoveBool = false;
            }
            startText.setPosition(1480, 700);
            startText.setColor(sf::Color::Black);
            if(clicked)
            {
                if(clickedSound)
                {
                    mouseClick.play();
                    clickedSound = false;
                }
                startText.setColor(sf::Color::Green);
                startText.setCharacterSize(60);
            }
            if(released)
            {
                clicked = false;
                released = false;
                clickedSound = true;
                startText.setCharacterSize(70);
                // Start Function
                menuMusic.pause();
                abc = start(app,menuMusic);
                if(abc == 1)
                    menuMusic.play();
                if(abc == 0)
                    app.close();
            }
        }
        else if((movedX < 1490.0 || movedX > 1670.0 || movedY < 705.0 || movedY > 780.0) && exitButton == false && rulesButton == false && storyButton == false)
        {
            startButton = false;
            mouseMoveBool = true;
            startText.setPosition(1500, 700);
            startText.setColor(sf::Color::White);
        }

        app.clear();
        app.draw(background);
        app.draw(exitText);
        app.draw(rulesText);
        app.draw(storyText);
        app.draw(startText);
        app.display();
    }

    return EXIT_SUCCESS;
}

