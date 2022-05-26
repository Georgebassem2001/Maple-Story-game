#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <cstdlib> 
#include<iostream>
using namespace std;
using namespace sf;

struct enemy {
    float slowingmonstermove = 0;
    int monsterframe = 0, monsterframe_h = 0;
    int monsterframe_2 = 0, monsterframe2_h = 0;
    bool monstermoveright = false, monstermoveleft = false;
    bool monsterdead = false, monsterdying = false;
    bool monster_border = false, monsterdamage = false;
    int slowingmonster2_move = 0, slowingeffect_move = 0;
    int effectframe_x = 0;
    bool monster_attack = false;
} monsters_level1[5],monsters_level2[8],monsterlevel_3[8],monsters_level4[6], monsters_level5[4];

bool mainmenubool = true, restart = true, startlevel_1 = false, startlevel_2 = false, startlevel_3 = false, startlevel_4 = false,startlevel_5 = false, start_game = false, boss_dead = false;
int  onlymonstersoundonce1 = 0, onlymonstersoundonce2 = 0;
sf::RectangleShape blackmage_health(sf::Vector2f(350.0f, 15.0f));
sf::RectangleShape bosshealth(sf::Vector2f(350.0f, 15.0f));
sf::RectangleShape myhealth(sf::Vector2f(300.0f, 15.0f));
sf::RectangleShape xpbar(sf::Vector2f(0.0f, 20.0f));

int number_of_lives = 5;

void restart_bool() {
    //Level 1
    for (int i = 0; i < 5; i++) {
        monsters_level1[i].monstermoveright = false;
        monsters_level1[i].monstermoveleft = false;
        monsters_level1[i].monsterdead = false;
        monsters_level1[i].monsterdying = false;
        monsters_level1[i].monster_border = false;
        monsters_level1[i].monsterdamage = false;
        monsters_level1[i].monster_attack = false;
        monsters_level1[i].effectframe_x = 0;
        monsters_level1[i].monsterframe_2 = 0;
        monsters_level1[i].monsterframe2_h = 0;
        monsters_level1[i].slowingmonstermove = 0;
        monsters_level1[i].slowingmonster2_move = 0;
        monsters_level1[i].slowingeffect_move = 0;
        monsters_level1[i].monsterframe = 0;
        monsters_level1[i].monsterframe_h = 0;
    }
    //Level 2
    for (int i = 0; i < 8; i++) {
        monsters_level2[i].monstermoveright = false;
        monsters_level2[i].monstermoveleft = false;
        monsters_level2[i].monsterdead = false;
        monsters_level2[i].monsterdying = false;
        monsters_level2[i].monster_border = false;
        monsters_level2[i].monsterdamage = false;
        monsters_level2[i].monster_attack = false;
        monsters_level2[i].effectframe_x = 0;
        monsters_level2[i].monsterframe_2 = 0;
        monsters_level2[i].monsterframe2_h = 0;
        monsters_level2[i].slowingmonstermove = 0;
        monsters_level2[i].slowingmonster2_move = 0;
        monsters_level2[i].slowingeffect_move = 0;
        monsters_level2[i].monsterframe = 0;
        monsters_level2[i].monsterframe_h = 0;
    }
    //Level 3
    for (int i = 0; i < 8; i++) {
        monsterlevel_3[i].monstermoveright = false;
        monsterlevel_3[i].monstermoveleft = false;
        monsterlevel_3[i].monsterdead = false;
        monsterlevel_3[i].monsterdying = false;
        monsterlevel_3[i].monster_border = false;
        monsterlevel_3[i].monsterdamage = false;
        monsterlevel_3[i].monster_attack = false;
        monsterlevel_3[i].effectframe_x = 0;
        monsterlevel_3[i].monsterframe_2 = 0;
        monsterlevel_3[i].monsterframe2_h = 0;
        monsterlevel_3[i].slowingmonstermove = 0;
        monsterlevel_3[i].slowingmonster2_move = 0;
        monsterlevel_3[i].slowingeffect_move = 0;
        monsterlevel_3[i].monsterframe = 0;
        monsterlevel_3[i].monsterframe_h = 0;
    }
    //Level 4
    for (int i = 0; i < 6; i++) {
        monsters_level4[i].monstermoveright = false;
        monsters_level4[i].monstermoveleft = false;
        monsters_level4[i].monsterdead = false;
        monsters_level4[i].monsterdying = false;
        monsters_level4[i].monster_border = false;
        monsters_level4[i].monsterdamage = false;
        monsters_level4[i].monster_attack = false;
        monsters_level4[i].effectframe_x = 0;
        monsters_level4[i].monsterframe_2 = 0;
        monsters_level4[i].monsterframe2_h = 0;
        monsters_level4[i].slowingmonstermove = 0;
        monsters_level4[i].slowingmonster2_move = 0;
        monsters_level4[i].slowingeffect_move = 0;
        monsters_level4[i].monsterframe = 0;
        monsters_level4[i].monsterframe_h = 0;
    }
    //Level 5
    for (int i = 0; i < 4; i++) {
        monsters_level1[i].monstermoveright = false;
        monsters_level1[i].monstermoveleft = false;
        monsters_level1[i].monsterdead = false;
        monsters_level1[i].monsterdying = false;
        monsters_level1[i].monster_border = false;
        monsters_level1[i].monsterdamage = false;
        monsters_level1[i].monster_attack = false;
        monsters_level1[i].effectframe_x = 0;
        monsters_level1[i].monsterframe_2 = 0;
        monsters_level1[i].monsterframe2_h = 0;
        monsters_level1[i].slowingmonstermove = 0;
        monsters_level1[i].slowingmonster2_move = 0;
        monsters_level1[i].slowingeffect_move = 0;
        monsters_level1[i].monsterframe = 0;
        monsters_level1[i].monsterframe_h = 0;
    }
    myhealth.setSize(sf::Vector2f(300.0f, 15.0f));
    xpbar.setSize(sf::Vector2f(0.0f, 20.0f));
    blackmage_health.setSize(sf::Vector2f(350.0f, 15.0f));
    bosshealth.setSize(sf::Vector2f(350.0f, 15.0f));
    number_of_lives = 5;
}

void monster_hitting_animation(int numofmonster) {


    monsters_level2[numofmonster].monsterframe = 0;
    if (monsters_level2[numofmonster].monstermoveleft)
        monsters_level2[numofmonster].monsterframe_h = 1;
    if (monsters_level2[numofmonster].monstermoveright)
        monsters_level2[numofmonster].monsterframe_h = 4;
    monsters_level2[numofmonster].monsterdamage = false;

}
void Monster_dying(int numofmonster) {

    monsters_level2[numofmonster].monsterdead = true;
    if (monsters_level2[numofmonster].monstermoveright) {
        monsters_level2[numofmonster].monsterframe_h = 5;
    }
    if (monsters_level2[numofmonster].monstermoveleft) {
        monsters_level2[numofmonster].monsterframe_h = 2;
    }
    monsters_level2[numofmonster].slowingmonstermove++;
    if (monsters_level2[numofmonster].slowingmonstermove == 200) {
        monsters_level2[numofmonster].monsterframe++;
        monsters_level2[numofmonster].slowingmonstermove = 0;
    }
}


//Window
sf::RenderWindow window(sf::VideoMode(1024, 560), "Maple Story");

////////////////////////////
/////// MAIN MENU //////////
////////////////////////////

void main_menu() {

    //Sound
    sf::SoundBuffer main;
    main.loadFromFile("mainmenu.wav");
    sf::Sound mainmenusound;
    mainmenusound.setBuffer(main);
    mainmenusound.setPlayingOffset(sf::seconds(2.f));
    mainmenusound.play();

    //Main menu
    sf::Texture mainmenuimg;
    mainmenuimg.loadFromFile("mainmenu.png");
    sf::Sprite mainmenu(mainmenuimg);
    sf::Text mainmenutext, mainmenutext2, loading;
    sf::Font font2;
    font2.loadFromFile("font2.ttf");
    mainmenutext.setFont(font2);
    mainmenutext.setString("Start Game");
    mainmenutext.setFillColor(sf::Color::Yellow);
    mainmenutext2.setFont(font2);
    mainmenutext2.setString("Quit Game");
    mainmenutext2.setFillColor(sf::Color::Blue);
    loading.setFont(font2);
    loading.setString("Loading...");
    loading.setFillColor(sf::Color::Black);
    loading.setOutlineColor(sf::Color::Red);
    loading.setOutlineThickness(1.5);
    mainmenutext.setPosition(window.getSize().x / 2 - 100, 200);
    mainmenutext2.setPosition(window.getSize().x / 2 - 100, 250);
    loading.setPosition(window.getSize().x / 2 - 85, 350);


    //|=========|//
    //|GAME LOOP|//
    //|=========|//

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            mainmenutext2.setFillColor(sf::Color::Yellow);
            mainmenutext.setFillColor(sf::Color::Blue);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            mainmenutext2.setFillColor(sf::Color::Blue);
            mainmenutext.setFillColor(sf::Color::Yellow);
        }
        if (mainmenutext.getFillColor() == sf::Color::Yellow && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            startlevel_1 = true;
            startlevel_2 = false;
            startlevel_5 = false;
            mainmenusound.pause();
            window.draw(mainmenu);
            window.draw(mainmenutext);
            window.draw(mainmenutext2);
            window.draw(loading);
            window.display();
            break;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            window.close();
            break;
        }
        window.draw(mainmenu);
        window.draw(mainmenutext);
        window.draw(mainmenutext2);

        window.display();
    }
}

////////////////////////////
/////// LEVEL 1 ////////////
////////////////////////////

void level_1() {

    int onlysmashsoundonce = 0, onlylevelupsoundonce = 0;
    //Movement variables
    float ground2 = 355, ground3 = 390;
    float monster4movespeed = 0.15;
    float monster5movespeed = 0.15;
    sf::Vector2f velocity[4];
    //Character velocity
    velocity[0] = (sf::Vector2f(0, 0));
    //Big monsters velocity
    velocity[1] = (sf::Vector2f(0, 0));
    velocity[2] = (sf::Vector2f(0, 0));
    //Grave velocity
    velocity[3] = (sf::Vector2f(0, 0));
    //Animation variables
    int monsterindex;
    float  slowingcharactermove = 0, slowingcharacterhit = 0, slowingsmoke = 0;
    int characterframe = 0, characterframe_h = 1, characterhitframe = 0, characterhitframe_h = 1;
    int count[5];
    for (int index = 0; index < 5; index++) {
        count[index] = 0;
    }
    monsters_level1[0].monsterframe_h = 0;
    monsters_level1[1].monsterframe_h = 3;
    monsters_level1[2].monsterframe_h = 3;
    monsters_level1[3].monsterframe_h = 0;
    monsters_level1[4].monsterframe_h = 3;
    int smoke_frame = 0;
    int smash = 0;

    //Booleans
    bool smallmonstersdead = false;
    bool bigmonsterfloor = false;
    bool bigmonstersdead = false;
    bool canjump = false;
    bool characterhitting = false;

    //SFML Objects

    //Sound
    sf::Music back;
    back.openFromFile("BG.wav");
    back.setVolume(10.f);

    sf::SoundBuffer falling;
    falling.loadFromFile("falling.wav");
    sf::Sound monsterfalling;
    monsterfalling.setBuffer(falling);

    sf::SoundBuffer jumping;
    jumping.loadFromFile("jump.wav");
    sf::Sound jump;
    jump.setBuffer(jumping);

    sf::SoundBuffer leveling;
    leveling.loadFromFile("level up.wav");
    sf::Sound levelupsound;
    levelupsound.setBuffer(leveling);

    sf::SoundBuffer hitting;
    hitting.loadFromFile("hit.wav");
    sf::Sound hitsound;
    hitsound.setBuffer(hitting);

    sf::SoundBuffer monsterhit;
    monsterhit.loadFromFile("monstersound.wav");
    sf::Sound monstersound;
    monstersound.setBuffer(monsterhit);

    sf::SoundBuffer bigmonsterhit;
    bigmonsterhit.loadFromFile("big monster hit.wav");
    sf::Sound bigmonstersound;
    bigmonstersound.setBuffer(bigmonsterhit);

    sf::SoundBuffer bigmonsterdie;
    bigmonsterdie.loadFromFile("big monster die.wav");
    sf::Sound bigmonsterdiesound;
    bigmonsterdiesound.setBuffer(bigmonsterdie);

    sf::SoundBuffer movie;
    movie.loadFromFile("video.wav");
    sf::Sound blackmage;
    blackmage.setBuffer(movie);


    //Text and fonts
    sf::Text text;
    sf::Font font1;
    font1.loadFromFile("font.otf");
    text.setFont(font1);
    text.setString("Health  ");
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(10, 50);
    sf::Text text2;
    text2.setFont(font1);
    text2.setString("Do you want to restart this level? (Y/N)");
    text2.setFillColor(sf::Color::Yellow);
    text2.setPosition(window.getSize().x / 2 - 400, window.getSize().y / 2);
    sf::Text text3;
    text3.setFont(font1);
    text3.setString("XP");
    text3.setFillColor(sf::Color::Yellow);
    text3.setPosition(10, 10);
    sf::Text text4;
    text4.setFont(font1);
    text4.setString("Press UP to move to \n     the next level");
    text4.setFillColor(sf::Color::Yellow);
    text4.setPosition(630, 200);
    sf::Text text5;
    text5.setFont(font1);
    text5.setString("Press ESC to skip");
    text5.setPosition(window.getSize().x / 2 + 90, 500);
    text5.setFillColor(sf::Color::Yellow);
    sf::Text text6;
    text6.setFont(font1);
    text6.setString("Press X to read");
    text6.setFillColor(sf::Color::Yellow);
    text6.setPosition(100, 300);
    sf::Text text7;
    text7.setFont(font1);
    text7.setString("\t\t\t\t\t\tYou Lost!!\n\nPress 'Y' to move to the main menu");
    text7.setFillColor(sf::Color::Yellow);
    text7.setPosition(window.getSize().x / 2 - 400, window.getSize().y / 2-100);
    sf::Text guide_text;
    guide_text.setFont(font1);
    guide_text.setString("Right to Move right \n Left to Move left \n ALT to jump \n CTRL to attack \n\n\n\n C to close guide");
    guide_text.setFillColor(sf::Color::Yellow);
    guide_text.setCharacterSize(18);




    //XP Bar
    sf::RectangleShape xpbarborder(sf::Vector2f(300.0f, 20.0f));
    xpbar.setFillColor(sf::Color::Yellow);
    xpbarborder.setFillColor(sf::Color::Transparent);
    xpbarborder.setOutlineColor(sf::Color::Red);
    xpbarborder.setOutlineThickness(3);
    xpbar.setPosition(150, 20);
    xpbarborder.setPosition(150, 20);

    //Heart
    sf::Texture heart_pic;
    heart_pic.loadFromFile("heart.png");
    sf::Sprite heart[5];
    for (int i = 0; i < 5; i++) {
        heart[i].setTexture(heart_pic);
    }

    heart[0].setPosition(430, -20);
    heart[1].setPosition(490, -20);
    heart[2].setPosition(550, -20);
    heart[3].setPosition(610, -20);
    heart[4].setPosition(670, -20);



    //Background picture
    sf::Texture background;
    background.loadFromFile("back.png");
    sf::Sprite background_s;
    background_s.setTexture(background);

    //Player moving texture and sprites
    sf::Texture character;
    character.loadFromFile("character 1.png");
    sf::Sprite character_s(character);
    float movespeed = 0.3f, jumpspeed = 3.0f, gravity = 0.03, ground = 510;


    //Grave
    sf::Texture grave;
    grave.loadFromFile("grave.png");
    sf::Sprite grave_s;
    grave_s.setTexture(grave);
    int slowinggrave = 0, graveanimation = 0;

    //Character and grave positioning
    character_s.setPosition(50, 420);
    grave_s.setPosition(50, -300);

    //health Bar and border
    sf::RectangleShape myhealthborder(sf::Vector2f(300.0f, 15.0f));
    myhealth.setFillColor(sf::Color::Blue);
    myhealthborder.setFillColor(sf::Color::Transparent);
    myhealthborder.setOutlineColor(sf::Color::Yellow);
    myhealthborder.setOutlineThickness(3.5);
    myhealthborder.setPosition(150, 60);
    myhealth.setPosition(150, 60);


    //Player attacking texture and sprite
    sf::Texture character2;
    character2.loadFromFile("character 2.png");
    sf::Sprite character_s2;
    character_s2.setTexture(character2);


    //monsters texture and sprite
    sf::Texture firstmonster;
    firstmonster.loadFromFile("monster2.png");
    sf::Texture secondmonster;
    secondmonster.loadFromFile("secondmonster.png");
    sf::Sprite monster[5];
    monster[0].setTexture(firstmonster);
    monster[1].setTexture(firstmonster);
    monster[2].setTexture(firstmonster);
    monster[3].setTexture(secondmonster);
    monster[4].setTexture(secondmonster);

    //Positioning
    monster[0].setPosition(200, 446);
    monster[1].setPosition(450, 446);
    monster[2].setPosition(900, 446);
    monster[3].setPosition(800, -300);
    monster[4].setPosition(100, -300);

    //Health Bars and borders
    sf::RectangleShape monsterhealth[5];
    sf::RectangleShape monsterborder[5];
    for (int index = 0; index < 5; index++) {
        monsterhealth[index].setSize(sf::Vector2f(100.0f, 20.0f));
        monsterborder[index].setSize(sf::Vector2f(100.0f, 20.0f));
    }
    for (int index = 0; index < 5; index++) {
        monsterhealth[index].setFillColor(sf::Color::Red);
    }
    for (int index = 0; index < 5; index++) {
        monsterborder[index].setFillColor(sf::Color::Transparent);
        monsterborder[index].setOutlineThickness(3);
        monsterborder[index].setOutlineColor(sf::Color::Yellow);
    }

    //Smoke objects 
    sf::Texture smoke;
    smoke.loadFromFile("smoke.png");
    sf::Sprite smoke_s1, smoke_s2;
    smoke_s1.setTexture(smoke);
    smoke_s2.setTexture(smoke);
    smoke_s1.setPosition(800, 440);
    smoke_s2.setPosition(100, 440);

    //Leveling up objets 
    int width = 0;
    sf::Texture levelupimg;
    levelupimg.loadFromFile("levelup.png");
    sf::Sprite levelup;
    levelup.setTexture(levelupimg);
    bool level_upsound = false;
    int slowinglevel = 0;


    //Portal objects 
    int slowingportal = 0;
    int portalframes = 0;
    sf::Texture portalimg;
    portalimg.loadFromFile("portal.png");
    sf::Sprite portal(portalimg);
    portal.setPosition(760, 280);

    //Video
    sf::Sprite video[250];
    sf::Texture photos[250];
    bool drawvideo[250];
    if (!start_game) {
        for (int i = 0; i < 250; i++) {
            string name = to_string(i);
            photos[i].loadFromFile(name + ".png");
            cout << "Loading Image: " << name << "  of 249" << endl;
        }
        for (int i = 0; i < 250; i++) {
            video[i].setTexture(photos[i]);
            video[i].setScale(0.65, 0.65);
        }
        for (int i = 0; i < 250; i++) {
            drawvideo[i] = false;
        }
    }
    int timepressed = clock() / CLOCKS_PER_SEC;
    int videotime = -1, videotimefinished = 0, backgroundonce = 0;

    //Guide
    sf::Texture guidepic;
    guidepic.loadFromFile("guide.png");
    sf::Sprite guide(guidepic);
    guide.setPosition(100, 365);

    //Panel
    sf::Texture panel_pic;
    panel_pic.loadFromFile("panel.jfif");
    sf::Sprite panel(panel_pic);

    panel.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 - 100);
    guide_text.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 - 100);

    bool show_guide = false;

    //|=========|//
    //|GAME LOOP|//
    //|=========|//

    while (window.isOpen())
    {

        //Collision boxes

        //Character bounding boxes
        sf::FloatRect bound = character_s2.getGlobalBounds();
        sf::FloatRect bound2 = character_s.getGlobalBounds();

        //monsters
        sf::FloatRect monsterbound[5];
        for (int index = 0; index < 5; index++) {
            monsterbound[index] = monster[index].getGlobalBounds();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (!start_game) {
                if (videotime == -1) {
                    blackmage.play();
                    blackmage.setPlayingOffset(sf::seconds(0.5));
                }
            }
            if (start_game) {
                blackmage.pause();
                if (backgroundonce == 0)
                    back.play();

                if (smallmonstersdead && onlysmashsoundonce <= 200) {
                    monsterfalling.play();
                    monsterfalling.setPlayingOffset(sf::seconds(1.f));
                }

                if (myhealth.getSize().x > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && ((velocity[0].y >= -0.5 && velocity[0].y <= 0) || (velocity[0].y >= 0 && velocity[0].y <= 0.5))) {
                    jump.play();
                    jump.setPlayingOffset(sf::seconds(0.04f));
                }

                if (myhealth.getSize().x > 0 && level_upsound && onlylevelupsoundonce <= 100) {
                    levelupsound.play();
                }

                if (myhealth.getSize().x > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    if ((bound.intersects(monsterbound[0]) && characterhitframe == 0 && !monsters_level1[0].monsterdead) || (bound.intersects(monsterbound[1]) && characterhitframe == 0 && !monsters_level1[1].monsterdead) || (bound.intersects(monsterbound[2]) && characterhitframe == 0 && !monsters_level1[2].monsterdead)) {
                        monstersound.play();
                    }
                    if ((bound.intersects(monsterbound[3]) && characterhitframe == 0 && !monsters_level1[3].monsterdead) || (bound.intersects(monsterbound[4]) && characterhitframe == 0 && !monsters_level1[4].monsterdead)) {
                        bigmonstersound.play();
                    }
                    else if (characterhitframe == 0)
                        hitsound.play();
                }
                if (monsters_level1[3].monsterdead && onlymonstersoundonce1 <= 100)
                    bigmonsterdiesound.play();

                if (monsters_level1[4].monsterdead && onlymonstersoundonce2 <= 100)
                    bigmonsterdiesound.play();
            }
            break;
        }


        //Time to restart from 0
        videotime = ((clock() / CLOCKS_PER_SEC) - timepressed);

        //Hitting boolean
        characterhitting = false;

        //Health positioning
        for (int index = 0; index < 3; index++) {
            monsterhealth[index].setPosition(monster[index].getPosition().x - 15, 435);
            monsterborder[index].setPosition(monster[index].getPosition().x - 15, 435);
        }
        for (int index = 3; index < 5; index++) {
            monsterhealth[index].setPosition(monster[index].getPosition().x + 10, monster[index].getPosition().y - 30);
            monsterborder[index].setPosition(monster[index].getPosition().x + 10, monster[index].getPosition().y - 30);
        }

        //Player hitting positioning
        character_s2.setPosition(character_s.getPosition().x - 30, 355);


        //Monster positoning booleans
        if (!monsters_level1[0].monsterdead) {
            if (monster[0].getPosition().x <= 200) {
                monsters_level1[0].monstermoveright = true;
                monsters_level1[0].monstermoveleft = false;
            }
            if (monster[0].getPosition().x >= 600) {
                monsters_level1[0].monstermoveright = false;
                monsters_level1[0].monstermoveleft = true;
            }
        }

        if (!monsters_level1[1].monsterdead) {
            if (monster[1].getPosition().x >= 450) {
                monsters_level1[1].monstermoveright = false;
                monsters_level1[1].monstermoveleft = true;
            }
            if (monster[1].getPosition().x <= 150) {
                monsters_level1[1].monstermoveright = true;
                monsters_level1[1].monstermoveleft = false;
            }
        }

        if (!monsters_level1[2].monsterdead) {
            if (monster[2].getPosition().x >= 900) {
                monsters_level1[2].monstermoveright = false;
                monsters_level1[2].monstermoveleft = true;
            }
            if (monster[2].getPosition().x <= 500) {
                monsters_level1[2].monstermoveright = true;
                monsters_level1[2].monstermoveleft = false;
            }
        }

        if (!monsters_level1[3].monsterdead) {
            if (monster[3].getPosition().x >= 800) {
                monsters_level1[3].monstermoveright = false;
                monsters_level1[3].monstermoveleft = true;
            }
            if (monster[3].getPosition().x <= 550) {
                monsters_level1[3].monstermoveright = true;
                monsters_level1[3].monstermoveleft = false;
            }
        }

        if (!monsters_level1[4].monsterdead) {
            if (monster[4].getPosition().x >= 400) {
                monsters_level1[4].monstermoveright = false;
                monsters_level1[4].monstermoveleft = true;
            }
            if (monster[4].getPosition().x <= 100) {
                monsters_level1[4].monstermoveright = true;
                monsters_level1[4].monstermoveleft = false;
            }
        }

        //Hitting 
        if (start_game) {
            if (myhealth.getSize().x > 0) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    slowingcharacterhit++;
                    characterhitting = true;
                    characterhitframe_h = characterframe_h;
                    if (slowingcharacterhit == 70) {
                        characterhitframe++;
                        characterhitframe %= 4;
                        slowingcharacterhit = 0;
                    }
                    //Monster losing life
                    for (int index = 0; index < 5; index++) {
                        if (bound.intersects(monsterbound[index]) && characterhitframe == 1 && !monsters_level1[index].monsterdead) {
                            monsters_level1[index].monsterdamage = true;
                            monsters_level1[index].monster_border = true;
                            monsterhealth[index].setSize(sf::Vector2f(monsterhealth[index].getSize().x - 0.25, 20));
                            if (monster[index].getPosition().x >= character_s2.getPosition().x) {
                                monster[index].move(0.65, 0);
                                monsters_level1[index].monstermoveleft = true;
                                monsters_level1[index].monstermoveright = false;
                            }
                            else if (monster[index].getPosition().x < character_s2.getPosition().x) {
                                monster[index].move(-0.65, 0);
                                monsters_level1[index].monstermoveright = true;
                                monsters_level1[index].monstermoveleft = false;
                            }
                        }
                    }
                }
            }
        }
        //Monster movement

        //Monsters_level1 1,2,3

        for (int index = 0; index < 3; index++) {
            if (!monsters_level1[index].monsterdead) {
                if (monsters_level1[index].monstermoveright) {
                    monsters_level1[index].monsterframe_h = 3;
                    monsters_level1[index].slowingmonstermove++;
                    if (monsters_level1[index].slowingmonstermove == 80) {
                        monsters_level1[index].monsterframe++;
                        monsters_level1[index].monsterframe %= 5;
                        monsters_level1[index].slowingmonstermove = 0;
                    }
                    monster[index].move(0.15, 0);
                }
                if (monsters_level1[index].monstermoveleft) {
                    monsters_level1[index].monsterframe_h = 0;
                    monsters_level1[index].slowingmonstermove++;
                    if (monsters_level1[index].slowingmonstermove == 80) {
                        monsters_level1[index].monsterframe++;
                        monsters_level1[index].monsterframe %= 5;
                        monsters_level1[index].slowingmonstermove = 0;
                    }
                    monster[index].move(-0.15, 0);
                }
            }
        }

        //Monsters 4,5
        for (int index = 3; index < 5; index++) {
            if (smash >= 300) {
                if (!monsters_level1[index].monsterdead) {
                    if (monsters_level1[index].monstermoveright) {
                        velocity[index - 2].x = monster4movespeed;
                        monsters_level1[index].monsterframe_h = 3;
                        monsters_level1[index].slowingmonstermove++;
                        if (monsters_level1[index].slowingmonstermove == 80) {
                            monsters_level1[index].monsterframe++;
                            monsters_level1[index].monsterframe %= 4;
                            monsters_level1[index].slowingmonstermove = 0;
                        }
                    }
                    if (monsters_level1[index].monstermoveleft) {
                        velocity[index - 2].x = -monster4movespeed;
                        monsters_level1[index].monsterframe_h = 0;
                        monsters_level1[index].slowingmonstermove++;
                        if (monsters_level1[index].slowingmonstermove == 80) {
                            monsters_level1[index].monsterframe++;
                            monsters_level1[index].monsterframe %= 4;
                            monsters_level1[index].slowingmonstermove = 0;
                        }
                    }
                }
            }
        }

        //Big monsters_level1 falling

        if (smallmonstersdead) {
            if (monster[3].getPosition().y < ground2) {
                velocity[1].y += gravity;
            }
            else {
                velocity[1].y = 0;
            }
            if (monster[4].getPosition().y < ground2) {
                velocity[2].y += gravity;
            }
            else {
                velocity[2].y = 0;
            }
        }

        //Big monsters_level1 dead
        if (monsters_level1[3].monsterdead) {
            velocity[1].x = 0;
        }
        if (monsters_level1[4].monsterdead) {
            velocity[2].x = 0;
        }

        //Big monsters_level1 moving
        monster[3].move(velocity[1].x, velocity[1].y);
        monster[4].move(velocity[2].x, velocity[2].y);

        //Character movement
        //Right
        if (start_game) {
            if (character_s.getPosition().x <= 0)
                character_s.move(0.5, 0);
            if (character_s.getPosition().x >= 973)
                character_s.move(-0.5, 0);
            if (character_s.getPosition().x >= 0 && character_s.getPosition().x <= 973) {
                if (myhealth.getSize().x > 0) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        slowingcharactermove++;
                        velocity[0].x = movespeed;
                        if (slowingcharactermove == 50) {
                            characterframe++;
                            characterframe_h = 1;
                            characterframe %= 4;
                            slowingcharactermove = 0;
                        }
                    }
                    //Left
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        slowingcharactermove++;
                        velocity[0].x = -movespeed;
                        if (slowingcharactermove == 50) {
                            characterframe++;
                            characterframe_h = 0;
                            characterframe %= 4;
                            slowingcharactermove = 0;
                        }

                    }
                    else
                        velocity[0].x = 0;

                    //Jumping
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && canjump) {
                        canjump = false;
                        velocity[0].y = -jumpspeed;
                    }

                    if (character_s.getPosition().y + 85 < ground || velocity[0].y < 0) {
                        velocity[0].y += gravity;
                        if (velocity[0].x == -movespeed)
                            velocity[0].x -= 0.25;
                        else if (velocity[0].x == movespeed)
                            velocity[0].x += 0.25;
                        character_s2.setPosition(character_s.getPosition().x, character_s.getPosition().y - 50);
                    }
                    else
                    {
                        velocity[0].y = 0;
                        canjump = true;
                    }
                    //Player moving
                    character_s.move(velocity[0].x, velocity[0].y);
                }
            }
        }
        //Monsters_level1 dying

        //Monsters 1,2,3 
        for (int index = 0; index < 3; index++) {
            if (monsterhealth[index].getSize().x <= 0) {
                monsterindex = index;
                count[index]++;
                if (count[index] == 500)
                    monsters_level1[index].monsterdying = true;
                monsters_level1[monsterindex].monsterdead = true;
                if (monsters_level1[monsterindex].monstermoveright) {
                    monsters_level1[monsterindex].monsterframe_h = 5;
                }
                if (monsters_level1[monsterindex].monstermoveleft) {
                    monsters_level1[monsterindex].monsterframe_h = 2;
                }
                monsters_level1[monsterindex].slowingmonstermove++;
                if (monsters_level1[monsterindex].slowingmonstermove == 200) {
                    monsters_level1[monsterindex].monsterframe++;
                    monsters_level1[monsterindex].slowingmonstermove = 0;
                }
            }
        }

        //Monsters_level1 4,5 
        for (int index = 3; index < 5; index++) {
            if (monsterhealth[index].getSize().x <= 0) {
                monsterindex = index;
                if (index == 3)
                    onlymonstersoundonce1++;
                if (index == 4)
                    onlymonstersoundonce2++;
                count[index]++;
                if (count[index] == 1200)
                    monsters_level1[index].monsterdying = true;
                monsters_level1[monsterindex].monsterdead = true;
                if (monsters_level1[monsterindex].monstermoveright) {
                    monsters_level1[monsterindex].monsterframe_h = 5;
                }
                if (monsters_level1[monsterindex].monstermoveleft) {
                    monsters_level1[monsterindex].monsterframe_h = 2;
                }
                monsters_level1[monsterindex].slowingmonstermove++;
                if (monsters_level1[monsterindex].slowingmonstermove == 200) {
                    monsters_level1[monsterindex].monsterframe++;
                    monsters_level1[monsterindex].slowingmonstermove = 0;
                }
            }
        }

        //Smoke frames
        if (monster[4].getPosition().y >= ground2) {
            slowingsmoke++;
            smash++;
            if (slowingsmoke == 100) {
                smoke_frame++;
                slowingsmoke = 0;
            }
        }

        //Character losing life 
        for (int index = 0; index < 5; index++) {
            if (bound2.intersects(monsterbound[index]) && monsters_level1[index].monsterdead == false && myhealth.getSize().x>=0) {
                myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.2, 15));
            }
        }

        //Character death
        if (myhealth.getSize().x < 0) {
            if (grave_s.getPosition().y < ground3) {
                velocity[3].y += gravity;
            }
            else {
                velocity[3].y = 0;
            }
            grave_s.move(0, velocity[3].y);
            if (velocity[3].y == 0) {
                slowinggrave++;
                if (slowinggrave == 100) {
                    if (graveanimation == 5)
                        graveanimation = 5;
                    else
                        graveanimation++;
                    slowinggrave = 0;
                }
            }
        }

        //Big monsters_level1 appear
        if (monsters_level1[0].monsterdead && monsters_level1[1].monsterdead && monsters_level1[2].monsterdead) {
            onlysmashsoundonce++;
            smallmonstersdead = true;
        }

        //Monster attacking animation
        for (int index = 0; index < 5; index++) {
            if (monsters_level1[index].monsterdamage) {
                monsterindex = index;
                monsters_level1[monsterindex].monsterframe = 0;
                if (monsters_level1[monsterindex].monstermoveleft)
                    monsters_level1[monsterindex].monsterframe_h = 1;
                if (monsters_level1[monsterindex].monstermoveright)
                    monsters_level1[monsterindex].monsterframe_h = 4;
                monsters_level1[monsterindex].monsterdamage = false;
            }
        }

        //XP increase
        for (int index = 0; index < 5; index++) {
            if (xpbar.getSize().x >= 300)
                break;
            if (monsters_level1[index].monsterframe == 0 && (monsters_level1[index].monsterframe_h == 2 || monsters_level1[index].monsterframe_h == 5)) {
                xpbar.setSize(sf::Vector2f(xpbar.getSize().x + 0.37, 20));
            }
            if (monsters_level1[3].monsterdead && monsters_level1[4].monsterdead)
                xpbar.setSize(sf::Vector2f(300, 20));
        }


        //Displaying
        window.clear();

        //Displaying Background
        window.draw(background_s);

        //Displaying monsters_level1
        for (int index = 0; index < 5; index++) {
            if (!monsters_level1[index].monsterdead && monsters_level1[index].monster_border) {
                window.draw(monsterhealth[index]);
                window.draw(monsterborder[index]);
            }
        }
        //Monster IntRect
        for (int index = 0; index < 3; index++) {
            monster[index].setTextureRect(sf::IntRect(63 * monsters_level1[index].monsterframe, 61 * monsters_level1[index].monsterframe_h, 63, 61));
        }
        for (int index = 3; index < 5; index++) {
            monster[index].setTextureRect(sf::IntRect(144 * monsters_level1[index].monsterframe, 147 * monsters_level1[index].monsterframe_h, 144, 147));
        }
        //Drawing Monsters
        for (int index = 0; index < 5; index++) {
            if (!monsters_level1[index].monsterdying) {
                window.draw(monster[index]);
            }
        }

        //Leveling up animation and Displaying

        if (monsters_level1[3].monsterdead && monsters_level1[4].monsterdead) {
            level_upsound = true;
            onlylevelupsoundonce++;
            slowinglevel++;
            if (slowinglevel % 80 == 0) {
                width++;
            }
            levelup.setPosition(character_s.getPosition().x - 300, character_s.getPosition().y - 285);
            levelup.setTextureRect(sf::IntRect(width * 679, 0, 679, 400));
            window.draw(levelup);
            slowingportal++;
            if (slowingportal % 50 == 0) {
                portalframes++;
                if (portalframes == 4) {
                    portalframes = 0;
                }
            }
            portal.setTextureRect(sf::IntRect(portalframes * 300, 0, 300, 300));
            window.draw(portal);
            if (character_s.getPosition().x >= 790 && character_s.getPosition().x <= 880) {
                window.draw(text4);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    xpbar.setSize(sf::Vector2f(0, 20));
                    mainmenubool = false;
                    startlevel_1 = false;
                    startlevel_2 = true;
                    startlevel_5 = false;
                    break;
                }
            }
        }
        //Displaying Character
        if (myhealth.getSize().x > 0) {
            if (!characterhitting) {
                grave_s.setPosition(character_s.getPosition().x, -300);
                character_s.setTextureRect(sf::IntRect(56.5 * characterframe, 85 * characterframe_h, 56.5, 85));
                window.draw(character_s);
            }
            else if (characterhitting) {
                character_s2.setTextureRect(sf::IntRect(160 * characterhitframe, 150 * characterhitframe_h, 160, 150));
                window.draw(character_s2);
            }
            window.draw(myhealth);
        }
        else if (myhealth.getSize().x < 0) {
            window.draw(grave_s);
            //Restart level
            if (number_of_lives == 1) {
                window.draw(text7);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    restart = true;
                    startlevel_1 = false;
                    startlevel_2 = false;
                    startlevel_3 = false;
                    startlevel_4 = false;
                    mainmenubool = true;
                    break;
                }
            }
            else if(number_of_lives>1) {
                window.draw(text2);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    myhealth.setSize(sf::Vector2f(300.0f, 15.0f));
                    number_of_lives--;
                    startlevel_1 = true;
                    break;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
                    restart = true;
                    startlevel_1 = false;
                    startlevel_2 = false;
                    startlevel_3 = false;
                    startlevel_4 = false;
                    startlevel_5 = false;
                    mainmenubool = true;
                    break;
                }
            }
        }
        //Displaying Smoke
        if (monster[3].getPosition().y >= ground2 && !monsters_level1[3].monsterdead && smoke_frame <= 6) {
            window.draw(smoke_s1);
        }
        if (monster[4].getPosition().y >= ground2 && !monsters_level1[4].monsterdead && smoke_frame <= 6) {
            window.draw(smoke_s2);
        }
        //Displaying Others
        if (character_s.getPosition().x >= 50 && character_s.getPosition().x <= 75) {
            window.draw(text6);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                show_guide = true;
            }
            if (show_guide) {
                window.draw(panel);
                window.draw(guide_text);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                    show_guide = false;

                }
            }
        }
        else
            show_guide = false;

        for (int i = 0; i < number_of_lives; i++) {
            window.draw(heart[i]);
        }
        window.draw(guide);
        window.draw(xpbar);
        window.draw(xpbarborder);
        window.draw(myhealthborder);
        window.draw(text);
        window.draw(text3);
        if (!start_game) {
            if (videotime < 250 && videotime >= 0) {
                drawvideo[videotime] = true;
                if (drawvideo[videotime])
                    window.draw(video[videotime]);
            }
            if (videotime >= 249) {
                window.draw(video[249]);
                text5.setString("Press ESC to continue");
            }
            if (videotime >= 5) {
                window.draw(text5);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    start_game = true;
                    videotimefinished = videotime;
                }
            }
        }
        if (start_game) {
            backgroundonce = videotime - videotimefinished;
        }
        window.display();

        //Smoke IntRect
        smoke_s1.setTextureRect(sf::IntRect(116 * smoke_frame, 0, 116, 100));
        smoke_s2.setTextureRect(sf::IntRect(116 * smoke_frame, 0, 116, 100));
        //Grave IntRect
        grave_s.setTextureRect(sf::IntRect(105 * graveanimation, 0, 105, 125));
    }

}

////////////////////////////
/////// LEVEL 2 ////////////
////////////////////////////

void level_2() {


    //  music for back ground 
    Music background_m;
    background_m.openFromFile("level 2 BG music.wav");
    background_m.play();

    // music for hit 
    SoundBuffer hitting;
    hitting.loadFromFile("hit.wav");
    Sound hittingsound(hitting);

    // music for jump

    SoundBuffer jumping;
    jumping.loadFromFile("jump.wav");
    Sound jumpingsound(jumping);


    // music for level up

    SoundBuffer levelup_sound;
    levelup_sound.loadFromFile("level up.wav");
    Sound levelupsound(levelup_sound);
    int forplaysound = 0;
    //monster hit sound
    SoundBuffer monster_being_hit;
    monster_being_hit.loadFromFile("big monster hit.wav");
    Sound monstersound(monster_being_hit);
    // music for big dead ;
    SoundBuffer bigdead;
    bigdead.loadFromFile("pig dead.wav");
    Sound bigdeadsound(bigdead);

    // music for octubus  ;
    SoundBuffer octubus;
    octubus.loadFromFile("octubus dead.wav");
    Sound octubusdeadsound(octubus);

    // grounds 

    //      1 
    RectangleShape ground1(Vector2f(140.0f, 10.0f));
    ground1.setFillColor(Color::Transparent);
    ground1.setPosition(80, 500);

    //   2 
    RectangleShape ground2(Vector2f(140.0f, 10.0f));
    ground2.setFillColor(Color::Transparent);
    ground2.setPosition(80, 350);

    // 3 
    RectangleShape ground3(Vector2f(130.0f, 3.0f));
    ground3.setFillColor(Color::Transparent);
    ground3.setPosition(173, 185);
    bool notground2 = false;

    //4 

    RectangleShape ground4(Vector2f(130.0f, 10.0f));
    ground4.setFillColor(Color::Transparent);
    ground4.setPosition(160, 83);






    //  declaraing background 
    Texture background;
    background.loadFromFile("background 2.jpg");

    Sprite background_s;
    background_s.setTexture(background);

    //The move (frame) varibles
    int playerframe_x = 0;
    int playerframe_y = 1;
    int slowingplayermove = 0;


    // cheak player  life 

    bool playerislive = true;




    //The hitting (frame) varibles
    int playerhitframe_x = 0;
    int playerhitframe_y = 1;
    int slowingplayerhitting = 0;







    // monster diying varibles

    int numofmonster;
    int counter[8];


    int numofdeadmonsters = 0;



    // jump varibles  

    int slowingjumping = 0;
    bool jumpingmode = false;
    float gravity = .03;
    float ground = 605;
    float jumpspeed = 3.0f;
    Vector2f vel(Vector2f(0, 0));
    Vector2f vel2(Vector2f(0, 0));


    // monster Smell 
    bool monstersmell = false;

    // climb 
    bool allmonsterisdead = false;
    bool 	hittingmode = false;


    // Health bar (for player)
    RectangleShape playerhealthborder(Vector2f(300.0f, 15.0f));

    // xp bar (formonster)
    RectangleShape xpborder(Vector2f(300.0f, 20.0f));

    xpborder.setFillColor(sf::Color::Transparent);
    xpborder.setOutlineColor(sf::Color::Yellow);
    xpborder.setOutlineThickness(3.5);



    //xp bar (for monster)position
    xpbar.setPosition(0, 100);
    xpborder.setPosition(0, 100);

    // player health
    playerhealthborder.setFillColor(sf::Color::Transparent);
    playerhealthborder.setOutlineColor(sf::Color::Yellow);
    playerhealthborder.setOutlineThickness(3.5);
    //health(for player)position
    /*playerhealthborder.setPosition(0, 40);
    myhealth.setPosition(0, 40);*/

    //health for monster

    RectangleShape  monstershealth[8];
    RectangleShape  monstersborder[8];

    for (int i = 0; i < 8; i++) {
        monstershealth[i].setSize(Vector2f(100.0f, 20.0f));
        monstershealth[i].setFillColor(Color::Red);
        monstersborder[i].setSize(Vector2f(100.0f, 20.0f));
        monstersborder[i].setFillColor(Color::Transparent);
        monstersborder[i].setOutlineThickness(3);
        monstersborder[i].setOutlineColor(Color::Yellow);

    }






    //coloers for health bars

    myhealth.setFillColor(Color::Blue);
    xpbar.setFillColor(Color::Yellow);



    //declaraing level up (sprite)

    Texture levelup;
    levelup.loadFromFile("levelup.png");


    Sprite levelup_s;
    levelup_s.setTexture(levelup);


    int levelupframe_y = 0;
    int slowingshowlevelup = 0;
    int levelupframe_x = 0;

    bool  forplaysound_1 = false;
    levelup_s.setPosition(400, 120);

    //declaraing protal

    Texture portal;
    portal.loadFromFile("portal.png");

    Sprite portal_s;
    portal_s.setTexture(portal);

    portal_s.setPosition(950, 360);

    int  portalframe_x = 0;
    int  portalframe_y = 0;
    int  slowingshowportal = 0;


    //Text for (player health)
    Font p_health1;
    p_health1.loadFromFile("font.otf");
    Text p_health;
    p_health.setFont(p_health1);
    p_health.setString("Health  ");
    p_health.setFillColor(sf::Color::Yellow);



    //text for (xp bar )
    Text xp;
    Font xp_f;
    xp_f.loadFromFile("font.otf");
    xp.setFont(xp_f);
    xp.setString("XP  ");
    xp.setFillColor(Color::Yellow);
    xp.setPosition(4, 60);


    //declaraing player (move)

    Texture player;
    player.loadFromFile("character 1.png");
    Sprite player_s;
    player_s.setTexture(player);

    //declaraing player (hit)

    Texture playerhit;
    playerhit.loadFromFile("character 2.png");
    Sprite playerhit_s;
    playerhit_s.setTexture(playerhit);

    // starting position (player)
    player_s.setPosition(35, 520);



    //Heart
    sf::Texture heart_pic;
    heart_pic.loadFromFile("heart.png");
    sf::Sprite heart[5];
    for (int i = 0; i < 5; i++) {
        heart[i].setTexture(heart_pic);
    }

    // declaraing monster2 (sprite)
    Texture monster2;
    monster2.loadFromFile("pig.png");

    Texture monster;
    monster.loadFromFile("octubes.png");

    Sprite monster1[8];
    for (int i = 0; i < 8; i++) {
        if (i < 4) {

            monster1[i].setTexture(monster);
        }
        else {
            monster1[i].setTexture(monster2);
        }
    }


    // starting position 

    monster1[0].setPosition(200, 530);
    monster1[1].setPosition(550, 530);
    monster1[2].setPosition(1000, 530);
    monster1[7].setPosition(300, 310);
    monster1[4].setPosition(550, 310);
    monster1[5].setPosition(450, 310);
    monster1[6].setPosition(340, 75);
    // last monster in ouctoubs
    monster1[3].setPosition(700, 52);



    monsters_level2[0].monsterframe_h = 0;
    monsters_level2[1].monsterframe_h = 3;
    monsters_level2[2].monsterframe_h = 3;
    monsters_level2[3].monsterframe_h = 0;
    monsters_level2[4].monsterframe_h = 3;
    monsters_level2[5].monsterframe_h = 0;
    monsters_level2[6].monsterframe_h = 3;
    monsters_level2[7].monsterframe_h = 3;



    //  declaraing  view  
    View view;
    view.setSize(771, 540);
    view.setCenter(player_s.getPosition().x + 350, 400);

    //Texts
    sf::Text text2;
    text2.setFont(p_health1);
    text2.setString("Do you want to restart this level? (Y/N)");
    text2.setFillColor(sf::Color::Yellow);

    sf::Text text7;
    text7.setFont(p_health1);
    text7.setString("\t\t\t\t\t\tYou Lost!!\n\nPress 'Y' to move to the main menu");
    text7.setFillColor(sf::Color::Yellow);


    // declaration (grave)

    Texture grave;
    grave.loadFromFile("grave.png");


    Sprite grave_s;
    grave_s.setTexture(grave);

    int graveframe_x = 0;
    int graveframe_y = 0;
    int slowingshowgrave = 0;



    bool donotclimb = false;

    //  ///////////////// // (Game Loop)     //  ///////////////// //
    while (window.isOpen())
    {
        // collision 
        FloatRect bound = playerhit_s.getGlobalBounds();
        FloatRect bound2 = player_s.getGlobalBounds();
        FloatRect monsterbound[8];
        for (int i = 0; i < 8; i++) {

            monsterbound[i] = monster1[i].getGlobalBounds();

        }

        FloatRect toground1 = ground1.getGlobalBounds();
        FloatRect toground2 = ground2.getGlobalBounds();
        FloatRect toground3 = ground3.getGlobalBounds();
        FloatRect toground4 = ground4.getGlobalBounds();



        sf::Event event;
        while (window.pollEvent(event))
        {
            if (myhealth.getSize().x > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && ((vel.y >= -0.5 && vel.y <= 0) || (vel.y >= 0 && vel.y <= 0.5))) {
                jumpingsound.play();
            }
            if (allmonsterisdead && forplaysound <= 500) {
                levelupsound.play();
            }
            if (myhealth.getSize().x > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                for (int i = 0; i < 8; i++) {
                    if ((bound.intersects(monsterbound[i]) && playerhitframe_x == 0 && !monsters_level2[i].monsterdead)) {
                        monstersound.play();
                    }
                }

                if (playerhitframe_x == 0)
                    hittingsound.play();
            }
            // music for frist 3 monsters_level2 
            for (int i = 0; i < 8; i++) {
                if (i < 4) {
                    if (monsters_level2[i].monsterdead && monsters_level2[i].monsterframe < 2 && (monsters_level2[i].monsterframe_h == 2 || monsters_level2[i].monsterframe_h == 5)) {
                        octubusdeadsound.play();
                    }
                }
                if (i >= 4) {
                    if (monsters_level2[i].monsterdead && monsters_level2[i].monsterframe < 2 && (monsters_level2[i].monsterframe_h == 2 || monsters_level2[i].monsterframe_h == 5)) {
                        bigdeadsound.play();

                    }
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();
            break;
        }

        //position for health bars  (for monster)

        monstershealth[0].setPosition(monster1[0].getPosition().x - 15, 505);
        monstersborder[0].setPosition(monster1[0].getPosition().x - 15, 505);

        monstershealth[1].setPosition(monster1[1].getPosition().x - 15, 510);
        monstersborder[1].setPosition(monster1[1].getPosition().x - 15, 510);

        monstershealth[2].setPosition(monster1[2].getPosition().x - 15, 510);
        monstersborder[2].setPosition(monster1[2].getPosition().x - 15, 510);

        monstershealth[7].setPosition(monster1[7].getPosition().x - 15, 290);
        monstersborder[7].setPosition(monster1[7].getPosition().x - 15, 290);

        monstershealth[4].setPosition(monster1[4].getPosition().x - 15, 290);
        monstersborder[4].setPosition(monster1[4].getPosition().x - 15, 290);

        monstershealth[5].setPosition(monster1[5].getPosition().x - 15, 290);
        monstersborder[5].setPosition(monster1[5].getPosition().x - 15, 290);


        monstershealth[6].setPosition(monster1[6].getPosition().x - 15, 50);
        monstersborder[6].setPosition(monster1[6].getPosition().x - 15, 50);


        monstershealth[3].setPosition(monster1[3].getPosition().x - 15, 32);
        monstersborder[3].setPosition(monster1[3].getPosition().x - 15, 32);

        //Position of Text and Hearts
        text7.setPosition(view.getCenter().x - 300, view.getCenter().y);
        text2.setPosition(view.getCenter().x - 360, view.getCenter().y - 50);
        heart[0].setPosition(view.getCenter().x - 420, view.getCenter().y - 250);
        heart[1].setPosition(view.getCenter().x - 360, view.getCenter().y - 250);
        heart[2].setPosition(view.getCenter().x - 300, view.getCenter().y - 250);
        heart[3].setPosition(view.getCenter().x - 240, view.getCenter().y - 250);
        heart[4].setPosition(view.getCenter().x - 180, view.getCenter().y - 250);

        if (Keyboard::isKeyPressed(Keyboard::Right) && donotclimb == false) {

            slowingplayermove++;

            vel.x = 0.15;
            if (slowingplayermove == 50) {


                playerframe_x++;
                playerframe_y = 1;
                playerframe_x %= 4;

                slowingplayermove = 0;
            }
        }
        else	if (Keyboard::isKeyPressed(Keyboard::Left) && donotclimb == false) {
            slowingplayermove++;

            vel.x = -0.15;


            if (slowingplayermove == 50) {

                playerframe_x++;
                playerframe_y = 0;
                playerframe_x %= 4;

                slowingplayermove = 0;
            }

        }
        else {
            vel.x = 0;
        }
        // jumping

        if (Keyboard::isKeyPressed(Keyboard::LAlt) && jumpingmode && !donotclimb) {
            jumpingmode = false;
            vel.y = -jumpspeed;
        }

        if ((player_s.getPosition().y + 85 < ground || vel.y < 0) && !donotclimb) {
            vel.y += gravity;
            if (vel.x == -0.15f) {

                vel.x -= 0.3f;
            }
            else if (vel.x == 0.15f) {

                vel.x += 0.3f;

            }
        }
        else {
            vel.y = 0;
            jumpingmode = true;
        }

        //  climbing
        if (player_s.getPosition().x >= 589 && player_s.getPosition().x <= 595 && player_s.getPosition().y > 285 && Keyboard::isKeyPressed(Keyboard::Up)) {
            donotclimb = true;
            playerframe_x++;
            playerframe_y = 2;
            playerframe_x %= 3;
            vel.y = -.15;
        }
        if (player_s.getPosition().x >= 589 && player_s.getPosition().x <= 595 && player_s.getPosition().y <= 285) {
            ground = 360;
            donotclimb = false;
        }

        if (player_s.getPosition().x >= 960 && player_s.getPosition().x <= 968 && ground == 360 && Keyboard::isKeyPressed(Keyboard::Up)) {
            donotclimb = true;
            playerframe_x++;
            playerframe_y = 2;
            playerframe_x %= 3;
            vel.y = -.15;
        }
        if (player_s.getPosition().x >= 960 && player_s.getPosition().x <= 968 && player_s.getPosition().y <= 40) {
            ground = 120;
            donotclimb = false;
        }
        player_s.move(vel.x, vel.y);


        // grave movement
        if (!playerislive) {

            if (grave_s.getPosition().y < ground - 110) {
                vel2.y += gravity;
            }
            else {
                vel2.y = 0;
            }
            grave_s.move(0, vel2.y * 1.75);
            if (vel2.y == 0) {
                slowingshowgrave++;
                if (slowingshowgrave == 80 && graveframe_x != 5) {
                    graveframe_x++;
                    graveframe_x %= 6;
                    slowingshowgrave = 0;
                }
                if (graveframe_x == 5) {
                    graveframe_x = 5;
                }
            }
        }



        //  second  ground 

        if (player_s.getPosition().y < 280 && player_s.getPosition().x >= 149) {
            ground = 360;
        }
        if (ground == 360 && player_s.getPosition().x <= 247) {

            ground = 600;
        }


        //   if for (levels)

        // first level 
        if (bound2.intersects(toground1) && player_s.getPosition().x >= 60 || player_s.getPosition().x <= 170) {


            ground = 480;

        }
        if (ground == 480)
        {

            if (player_s.getPosition().x <= 60 || player_s.getPosition().x >= 180) {
                ground = 600;
            }

        }
        // second level 
        if (bound2.intersects(toground2)) {

            ground = 425;

            if (player_s.getPosition().x <= 51 || player_s.getPosition().x >= 180) {
                ground = 600;
            }
        }


        // third level 
        if (bound2.intersects(toground3)) {

            ground = 240;
        }


        if (ground == 240) {

            if (player_s.getPosition().x <= 145) {
                ground = 450;
            }
            else if (player_s.getPosition().x >= 275)
            {
                ground = 360;
            }
        }


        // forth level
        if (bound2.intersects(toground4)) {

            ground = 176;
            if (player_s.getPosition().x <= 140) {
                ground = 450;
            }

        }


        // third ground 
        if (player_s.getPosition().y <= 38) {


            ground = 120;

        }

        if (ground == 120) {
            if (player_s.getPosition().x < 310) {

                ground = 475;
            }
        }


        //Player  and view moving
        if (ground > 120) {


            view.move(0, vel.y / 4);
        }
        hittingmode = false;
        //Hitting 
        if (Keyboard::isKeyPressed(Keyboard::LControl)) {
            slowingplayerhitting++;
            hittingmode = true;
            if (slowingplayerhitting == 80) {
                playerhitframe_y = playerframe_y;
                playerhitframe_x++;
                playerhitframe_x %= 4;
                slowingplayerhitting = 0;
            }

        }


        //Health bar position 
        p_health.setPosition(playerhealthborder.getPosition().x - 137, playerhealthborder.getPosition().y - 10);
        myhealth.setPosition(view.getCenter().x - 250, view.getCenter().y - 260);
        playerhealthborder.setPosition(view.getCenter().x - 250, view.getCenter().y - 260);



        // xp bar position 

        xp.setPosition(xpborder.getPosition().x - 137, xpborder.getPosition().y - 10);
        xpbar.setPosition(view.getCenter().x - 250, view.getCenter().y - 220);
        xpborder.setPosition(view.getCenter().x - 250, view.getCenter().y - 220);




        ////view condition ////
        if (view.getCenter().x - player_s.getPosition().x <= 150 && view.getCenter().x <= 880) {
            view.move(0.3, 0);
        }


        if (view.getCenter().x - player_s.getPosition().x >= 100 && view.getCenter().x > 400) {
            view.move(-0.3, 0);
        }


        window.setView(view);
        //monsters_level2 dying
         //Monster 1 dying
        for (int i = 0; i < 8; i++) {


            if (monstershealth[i].getSize().x <= 0) {


                numofmonster = i;
                counter[i]++;
                if (counter[i] == 500)
                    monsters_level2[i].monsterdying = true;
                Monster_dying(numofmonster);
            }
        }

        //Player hitting positioning (in groung)
        playerhit_s.setPosition(player_s.getPosition().x - 60, player_s.getPosition().y - 60);

        //Monster movement booleans
        if (!monsters_level2[0].monsterdead) {
            if (monster1[0].getPosition().x <= 200) {
                monsters_level2[0].monstermoveright = true;
                monsters_level2[0].monstermoveleft = false;
            }
            if (monster1[0].getPosition().x >= 700) {
                monsters_level2[0].monstermoveright = false;
                monsters_level2[0].monstermoveleft = true;
            }
        }

        if (!monsters_level2[1].monsterdead) {
            if (monster1[1].getPosition().x >= 550) {
                monsters_level2[1].monstermoveright = false;
                monsters_level2[1].monstermoveleft = true;
            }
            if (monster1[1].getPosition().x <= 350) {
                monsters_level2[1].monstermoveright = true;
                monsters_level2[1].monstermoveleft = false;
            }
        }

        if (!monsters_level2[2].monsterdead) {
            if (monster1[2].getPosition().x >= 1000) {
                monsters_level2[2].monstermoveright = false;
                monsters_level2[2].monstermoveleft = true;
            }
            if (monster1[2].getPosition().x <= 550) {
                monsters_level2[2].monstermoveright = true;
                monsters_level2[2].monstermoveleft = false;
            }
        }
        if (!monsters_level2[7].monsterdead) {
            if (monster1[7].getPosition().x >= 700) {
                monsters_level2[7].monstermoveright = false;
                monsters_level2[7].monstermoveleft = true;
            }
            if (monster1[7].getPosition().x <= 300) {
                monsters_level2[7].monstermoveright = true;
                monsters_level2[7].monstermoveleft = false;
            }
        }
        if (!monsters_level2[4].monsterdead) {
            if (monster1[4].getPosition().x >= 800) {
                monsters_level2[4].monstermoveright = false;
                monsters_level2[4].monstermoveleft = true;
            }
            if (monster1[4].getPosition().x <= 550) {
                monsters_level2[4].monstermoveright = true;
                monsters_level2[4].monstermoveleft = false;
            }
        }
        if (!monsters_level2[5].monsterdead) {
            if (monster1[5].getPosition().x >= 1200) {
                monsters_level2[5].monstermoveright = false;
                monsters_level2[5].monstermoveleft = true;
            }
            if (monster1[5].getPosition().x <= 750) {
                monsters_level2[5].monstermoveright = true;
                monsters_level2[5].monstermoveleft = false;
            }
        }
        if (!monsters_level2[6].monsterdead && !monstersmell) {
            if (monster1[6].getPosition().x >= 750) {
                monsters_level2[6].monstermoveright = false;
                monsters_level2[6].monstermoveleft = true;
            }
            if (monster1[6].getPosition().x <= 350) {
                monsters_level2[6].monstermoveright = true;
                monsters_level2[6].monstermoveleft = false;
            }
        }

        if (!monsters_level2[3].monsterdead) {
            if (monster1[3].getPosition().x >= 1200) {
                monsters_level2[3].monstermoveright = false;
                monsters_level2[3].monstermoveleft = true;
            }
            if (monster1[3].getPosition().x <= 750) {
                monsters_level2[3].monstermoveright = true;
                monsters_level2[3].monstermoveleft = false;
            }
        }





        //Monster 1
        for (int i = 0; i < 8; i++) {

            if (bound.intersects(monsterbound[i]) && playerhitframe_x == 1 && !monsters_level2[i].monsterdead && hittingmode) {

                monsters_level2[i].monsterdamage = true;
                monsters_level2[i].monster_border = true;
                monstershealth[i].setSize(Vector2f(monstershealth[i].getSize().x - 0.25, 20));
                if (monster1[i].getPosition().x >= playerhit_s.getPosition().x) {
                    monster1[i].move(0.65, 0);
                    monsters_level2[i].monstermoveleft = true;
                    monsters_level2[i].monstermoveright = false;
                }
                else if (monster1[i].getPosition().x < playerhit_s.getPosition().x) {
                    monster1[i].move(-0.65, 0);
                    monsters_level2[i].monstermoveright = true;
                    monsters_level2[i].monstermoveleft = false;
                }
                if (monsters_level2[i].monstermoveright)
                    monsters_level2[i].monsterframe_h = 4;
                if (monsters_level2[i].monstermoveleft)
                    monsters_level2[i].monsterframe_h = 2;
                monsters_level2[i].monsterframe = 0;
            }



        }


        //Monster movement
     //Monster 1
        for (int i = 0; i < 8; i++) {

            if (i <= 3) {
                if (!monsters_level2[i].monsterdead) {
                    if (monsters_level2[i].monstermoveright) {
                        monsters_level2[i].monsterframe_h = 3;
                        monsters_level2[i].slowingmonstermove++;
                        if (monsters_level2[i].slowingmonstermove == 80) {
                            monsters_level2[i].monsterframe++;
                            monsters_level2[i].monsterframe %= 5;
                            monsters_level2[i].slowingmonstermove = 0;
                        }
                        monster1[i].move(0.20, 0);
                    }
                    if (monsters_level2[i].monstermoveleft) {
                        monsters_level2[i].monsterframe_h = 0;
                        monsters_level2[i].slowingmonstermove++;
                        if (monsters_level2[i].slowingmonstermove == 80) {
                            monsters_level2[i].monsterframe++;
                            monsters_level2[i].monsterframe %= 5;
                            monsters_level2[i].slowingmonstermove = 0;

                        }
                        monster1[i].move(-0.15, 0);
                    }
                }
            }
            else if (i >= 4) {
                if (!monsters_level2[i].monsterdead) {
                    if (monsters_level2[i].monstermoveright) {
                        monsters_level2[i].monsterframe_h = 3;
                        monsters_level2[i].slowingmonstermove++;
                        if (monsters_level2[i].slowingmonstermove == 80) {
                            monsters_level2[i].monsterframe++;
                            monsters_level2[i].monsterframe %= 3;
                            monsters_level2[i].slowingmonstermove = 0;
                        }
                        monster1[i].move(0.20, 0);
                    }
                    if (monsters_level2[i].monstermoveleft) {
                        monsters_level2[i].monsterframe_h = 0;
                        monsters_level2[i].slowingmonstermove++;
                        if (monsters_level2[i].slowingmonstermove == 80) {
                            monsters_level2[i].monsterframe++;
                            monsters_level2[i].monsterframe %= 3;
                            monsters_level2[i].slowingmonstermove = 0;

                        }
                        monster1[i].move(-0.15, 0);
                    }
                }

            }
        }

        // xp bar masion
        for (int i = 0; i < 8; i++) {


            if (monsters_level2[i].monsterframe == 0 && (monsters_level2[i].monsterframe_h == 2 || monsters_level2[i].monsterframe_h == 5)) {
                xpbar.setSize(Vector2f(xpbar.getSize().x + 0.24, 20));
            }

            if (allmonsterisdead) {
                xpbar.setSize(Vector2f(300, 20));
            }

            if (xpbar.getSize().x >= 300) {
                break;
            }

        }




        // IntRect for player (In genral case )
        player_s.setTextureRect(IntRect(56.5 * playerframe_x, 85 * playerframe_y, 56.5, 85));
        // IntRect for player (In hitting mode)
        playerhit_s.setTextureRect(IntRect(160 * playerhitframe_x, 150 * playerhitframe_y, 160, 150));

        // IntRect for monster (1)
        for (int i = 0; i < 8; i++) {
            if (i <= 3) {

                monster1[i].setTextureRect(IntRect(70 * monsters_level2[i].monsterframe, 81 * monsters_level2[i].monsterframe_h, 70, 81));
            }
            else {
                monster1[i].setTextureRect(IntRect(72 * monsters_level2[i].monsterframe, 58 * monsters_level2[i].monsterframe_h, 72, 58));
            }
        }

        ////Character lose  his life life 
        if (myhealth.getSize().x >= 0) {

            for (int i = 0; i < 8; i++) {
                if (bound2.intersects(monsterbound[i]) && monsters_level2[i].monsterdead == false) {
                    myhealth.setSize(Vector2f(myhealth.getSize().x - 0.2, 15));
                }
            }
        }

        //monster hitting animation
        for (int i = 0; i < 8; i++) {
            if (monsters_level2[i].monsterdamage) {
                numofmonster = i;
                monster_hitting_animation(numofmonster);
            }
        }
        //displaying All sprite 
        window.clear();
        window.draw(background_s);



        //displaying the health (bars) for player 

        window.draw(myhealth);
        window.draw(playerhealthborder);
        window.draw(p_health);



        // displaying the xp (bars) for monster 

        window.draw(xpbar);
        window.draw(xpborder);
        window.draw(xp);





        // cheak the all monster is dead 
        numofdeadmonsters = 0;
        for (int i = 0; i < 8; i++) {
            if (monsters_level2[i].monsterdead)
                numofdeadmonsters++;
            if (numofdeadmonsters == 8)
                allmonsterisdead = true;
        }
        if (allmonsterisdead) {
            forplaysound++;
        }

        if (allmonsterisdead) {
            slowingshowportal++;
            if (slowingshowportal == 120) {
                portalframe_x++;
                portalframe_x %= 4;
                slowingshowportal = 0;

            }
        }
        if (allmonsterisdead) {
            window.draw(portal_s);
            if (player_s.getPosition().x >= 1020 && player_s.getPosition().x <= 1120)
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    xpbar.setSize(sf::Vector2f(0, 20));
                    mainmenubool = false;
                    startlevel_1 = false;
                    startlevel_2 = false;
                    startlevel_3 = true;
                    startlevel_4 = false;
                    startlevel_5 = false;
                    break;
                }
        }

        // level up animation

        if (allmonsterisdead) {
            slowingshowlevelup++;
            if (slowingshowlevelup == 100) {
                levelupframe_x++;
                slowingshowlevelup = 0;

            }
        }


        if (allmonsterisdead) {

            window.draw(levelup_s);
            levelup_s.setPosition(player_s.getPosition().x - 320, player_s.getPosition().y - 280);
        }


        // IntRect for level up


        levelup_s.setTextureRect(IntRect(679 * levelupframe_x, 400 * levelupframe_y, 679, 400));


        //intrect for portal
        portal_s.setTextureRect(IntRect(300 * portalframe_x, 300 * portalframe_y, 300, 300));

        //displaying playerhitting (sprite)
        for (int i = 0; i < 8; i++) {



            if (!monsters_level2[i].monsterdying) {
                window.draw(monster1[i]);
            }

        }

           // draw health bar for monsters
        for (int i = 0; i < 8; i++) {


            if (!monsters_level2[i].monsterdead && monsters_level2[i].monster_border) {
                window.draw(monstershealth[i]);
                window.draw(monstersborder[i]);
            }
        }


        if (myhealth.getSize().x > 0) {
            grave_s.setPosition(player_s.getPosition().x, -300);

            if (!hittingmode) {
                player_s.setTextureRect(IntRect(56.5 * playerframe_x, 85 * playerframe_y, 56.5, 85));
                window.draw(player_s);
            }
            else if (hittingmode) {
                playerhit_s.setTextureRect(IntRect(160 * playerhitframe_x, 150 * playerhitframe_y, 160, 150));
                window.draw(playerhit_s);
            }
        }
        if (myhealth.getSize().x < 0) {
            window.draw(grave_s);
            //Restart level
            if (number_of_lives == 1) {
                window.draw(text7);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    restart = true;
                    startlevel_1 = false;
                    startlevel_2 = false;
                    startlevel_3 = false;
                    startlevel_4 = false;
                    startlevel_5 = false;
                    mainmenubool = true;
                    window.setView(window.getDefaultView());
                    break;
                }
            }
            else if (number_of_lives > 1) {
                window.draw(text2);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    myhealth.setSize(sf::Vector2f(300.0f, 15.0f));
                    number_of_lives--;
                    startlevel_2 = true;
                    break;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
                    restart = true;
                    startlevel_1 = false;
                    startlevel_2 = false;
                    startlevel_3 = false;
                    startlevel_4 = false;
                    startlevel_5 = false;
                    mainmenubool = true;
                    window.setView(window.getDefaultView());
                    break;
                }
            }
        }

        // display grave 
        grave_s.setTextureRect(IntRect(105 * graveframe_x, 125 * graveframe_y, 105, 125));

        if (myhealth.getSize().x <= 0) {
            playerislive = false;
        }

        // Draw  hiden rect
        window.draw(ground1);
        window.draw(ground2);
        window.draw(ground3);
        window.draw(ground4);


        //dDrawing Hearts
        for (int i = 0; i < number_of_lives; i++) {
            window.draw(heart[i]);
        }

        window.display();

    }
}

////////////////////////////
/////// LEVEL 3 ////////////
////////////////////////////

void level_3() {

    //Text
    sf::Font font1;
    font1.loadFromFile("font.otf");
    sf::Text text6;
    text6.setFont(font1);
    text6.setString("Press X to read");
    text6.setFillColor(sf::Color::Yellow);
    text6.setPosition(100, 420);

    sf::Text guide_text;
    guide_text.setString("You unlocked a new skill\n Z to use it! \n\n\n Press C to close");
    guide_text.setFillColor(sf::Color::Yellow);
    guide_text.setCharacterSize(14);
    guide_text.setFont(font1);
    //Guide
    sf::Texture guidepic;
    guidepic.loadFromFile("guide.png");
    sf::Sprite guide(guidepic);
    guide.setPosition(50, 690);

    //Panel
    sf::Texture panel_pic;
    panel_pic.loadFromFile("panel.jfif");
    sf::Sprite panel(panel_pic);

    panel.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 + 100);
    guide_text.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 + 150);

    bool show_guide = false;

    // * movement variables * //
    // character
    int characterframe_x = 0, characterframe_y = 1, characterhitframe_x = 0, characterhitframe_y = 1;
    int  slowingcharactermove = 0, slowingcharacterhit = 0;
    int ground = 830;
    bool characterhitting1 = false, characterhitting2 = false;
    bool canjump = false, canclimb = false;
    float jumpspeed = 3.0, gravity = 0.03, movespeed = 0.4;

    //Velocity of character
    sf::Vector2f vel[2];
    for (int i = 0; i < 2; i++) {
        vel[i] = (sf::Vector2f(0, 0));
    }

    //monster
    int monster_index, monster_index2;
    int count[8];
    for (int index = 0; index < 8; index++) {
        count[index] = 0;
    }

    bool monsterhit[8];
    for (int i = 0; i < 8; i++)
        monsterhit[i] = false;

    //*****//

   // * texture and sprite * //

    // backgroung texture and sprite 
    Texture background;
    background.loadFromFile("background 1.png");
    Sprite background_s, background2_s;
    background_s.setTexture(background);

    // character texture and sprite 
    Texture character1, character2, character3;
    character1.loadFromFile("character 1.png");
    character2.loadFromFile("character 2.png");
    character3.loadFromFile("character 3.png");
    Sprite character1_s, character2_s, character3_s;
    character1_s.setTexture(character1);
    character2_s.setTexture(character2);
    character3_s.setTexture(character3);

    // monster texture and sprite
    Texture monster1;
    monster1.loadFromFile("blue monster.png");
    Texture monster2;
    monster2.loadFromFile("snow beast.png");
    Sprite monster_s[8];
    //blue monster
    for (int i = 0; i < 8; i++) {
        if (i < 4) {
            monster_s[i].setTexture(monster1);
        }
        //snow beast
        else
        {
            monster_s[i].setTexture(monster2);
        }
    }

    // monster attack texture and sprite
    Texture monster1_attack;
    monster1_attack.loadFromFile("blue monster_2.png");
    Texture monster2_attack;
    monster2_attack.loadFromFile("snow beast_2.png");
    Sprite monsterattack_s[8];
    //blue monster
    for (int i = 0; i < 8; i++) {
        if (i < 4) {
            monsterattack_s[i].setTexture(monster1_attack);
        }
        //snow beast
        else
        {
            monsterattack_s[i].setTexture(monster2_attack);
        }
    }

    // monster effect texture and sprite
    Texture monster1_effect;
    monster1_effect.loadFromFile("blue monster hit.png");
    Texture monster2_effect;
    monster2_effect.loadFromFile("snow beast hit.png");
    Sprite monstereffect_s[8];
    //blue monster
    for (int i = 0; i < 8; i++) {
        if (i < 4) {
            monstereffect_s[i].setTexture(monster1_effect);
            monstereffect_s[i].setScale(2, 2);
        }
        //snow beast
        else
        {
            monstereffect_s[i].setTexture(monster2_effect);
            monstereffect_s[i].setScale(2, 2);
        }
    }

    // boss texture and sprite
    Texture boss;
    boss.loadFromFile("snow beast boss.png");
    Sprite boss_s;
    boss_s.setTexture(boss);
    boss_s.setPosition(1600, 630);

    // boss hit texture and sprite
    Texture bosshit;
    bosshit.loadFromFile("snow ball.png");
    Sprite bosshit_s;
    bosshit_s.setTexture(bosshit);

    // boss effect texture and sprite
    Texture bosseffect;
    bosseffect.loadFromFile("snow ball effect.png");
    Sprite bosseffect_s;
    bosseffect_s.setTexture(bosseffect);



    int count_dead_monsters = 0, returnview = 0;
    int slowingbossmove = 0, bossframe_x = 0, bossframe_y = 0, num_of_frames = 0, bosseffectframe_x = 0, bosseffectframe_y = 0, slowingbosseffect = 0, bossballframe_x = 0;
    bool bossfight = false, boss_dead = false, boss_damage = false, bossmoveright = false, bossmoveleft = false, firsthit = false, secondhit = false, drawball = false;

    //**//

    // * position * //

    // character
    character1_s.setPosition(120, 740);

    // monster
    monster_s[0].setPosition(300, 705);
    monster_s[1].setPosition(500, 705);
    monster_s[2].setPosition(1450, 400);
    monster_s[3].setPosition(1220, 100);
    monster_s[4].setPosition(800, 700);
    monster_s[5].setPosition(1000, 700);
    monster_s[6].setPosition(200, 400);
    monster_s[7].setPosition(350, 175);

    //**//

  // * Rectangles * //

    // character health
    RectangleShape myhealthborder(Vector2f(300.0f, 15.0f));
    myhealth.setFillColor(Color::Red);
    myhealthborder.setFillColor(Color::Transparent);
    myhealthborder.setOutlineThickness(3);
    myhealthborder.setOutlineColor(Color::Yellow);

    // XP 
    sf::RectangleShape xpbarborder(sf::Vector2f(300.0f, 20.0f));
    xpbar.setFillColor(sf::Color::Yellow);
    xpbarborder.setFillColor(sf::Color::Transparent);
    xpbarborder.setOutlineColor(sf::Color::Red);
    xpbarborder.setOutlineThickness(3);

    // grounds
    RectangleShape grounds[12];
    grounds[1].setSize(Vector2f(70.0f, 3.0f));
    grounds[1].setPosition(360, 540);

    grounds[2].setSize(Vector2f(170.0f, 3.0f));
    grounds[2].setPosition(120, 445);

    grounds[3].setSize(Vector2f(200.0f, 3.0f));
    grounds[3].setPosition(130, 170);

    grounds[4].setSize(Vector2f(70.0f, 3.0f));
    grounds[4].setPosition(468, 200);

    grounds[5].setSize(Vector2f(70.0f, 3.0f));
    grounds[5].setPosition(580, 120);

    grounds[6].setSize(Vector2f(70.0f, 3.0f));
    grounds[6].setPosition(1245, 560);

    grounds[7].setSize(Vector2f(170.0f, 3.0f));
    grounds[7].setPosition(1364, 450);

    grounds[8].setSize(Vector2f(70.0f, 3.0f));
    grounds[8].setPosition(1245, 370);

    grounds[9].setSize(Vector2f(50.0f, 3.0f));
    grounds[9].setPosition(1145, 250);

    grounds[10].setSize(Vector2f(270.0f, 3.0f));
    grounds[10].setPosition(1270, 150);

    grounds[11].setSize(Vector2f(50.0f, 3.0f));
    grounds[11].setPosition(1145, 80);

    for (int i = 0; i < 12; i++) {
        grounds[i].setFillColor(Color::Transparent);
    }

    // monster health
    RectangleShape monsterhealth[8];
    RectangleShape monsterborder[8];

    for (int i = 0; i < 8; i++) {
        monsterhealth[i].setSize(Vector2f(100.0f, 20.0f));
        monsterborder[i].setSize(Vector2f(100.0f, 20.0f));
        monsterhealth[i].setFillColor(Color::Red);
        monsterborder[i].setFillColor(Color::Transparent);
        monsterborder[i].setOutlineThickness(3);
        monsterborder[i].setOutlineColor(sf::Color::Yellow);
    }

    // boss health 
    RectangleShape bosshealth(Vector2f(200.0f, 20.0f));
    RectangleShape bosshealthborder(Vector2f(200.0f, 20.0f));
    bosshealth.setFillColor(Color::Red);
    bosshealthborder.setFillColor(Color::Transparent);
    bosshealthborder.setOutlineThickness(3);
    bosshealthborder.setOutlineColor(Color::Yellow);
    //**//

    // * Text and fonts * //
  
    Text text1;
    text1.setFont(font1);
    text1.setString("Health  ");
    text1.setFillColor(sf::Color::Yellow);
    text1.setPosition(10, 50);

    Text text2;
    text2.setFont(font1);
    text2.setString("XP");
    text2.setFillColor(sf::Color::Yellow);
    text2.setPosition(10, 10);

    sf::Text text3;
    text3.setFont(font1);
    text3.setString("Do you want to restart this level? (Y/N)");
    text3.setFillColor(sf::Color::Yellow);

    sf::Text text7;
    text7.setFont(font1);
    text7.setString("\t\t\t\t\t\tYou Lost!!\n\nPress 'Y' to move to the main menu");
    text7.setFillColor(sf::Color::Yellow);

    //**//
      //Leveling up objets 
    int width = 0, onlylevelupsoundonce = 0;
    sf::Texture levelupimg;
    levelupimg.loadFromFile("levelup.png");
    sf::Sprite levelup;
    levelup.setTexture(levelupimg);
    bool level_upsound = false;
    int slowinglevel = 0;


    //Portal objects 
    int slowingportal = 0;
    int portalframes = 0;
    sf::Texture portalimg;
    portalimg.loadFromFile("portal.png");
    sf::Sprite portal(portalimg);
    portal.setPosition(760, 280);

    //Grave
    sf::Texture grave;
    grave.loadFromFile("grave.png");
    sf::Sprite grave_s;
    grave_s.setTexture(grave);
    int slowinggrave = 0, graveanimation = 0;
    grave_s.setPosition(50, -300);
    sf::Vector2f velocity(0, 0);

    //Hearts
       //Heart
    sf::Texture heart_pic;
    heart_pic.loadFromFile("heart.png");
    sf::Sprite heart[5];
    for (int i = 0; i < 5; i++) {
        heart[i].setTexture(heart_pic);
    }

    //Sounds
    //Background Music
    sf::Music backgroundmusic;
    backgroundmusic.openFromFile("level 3 BG music.wav");
    backgroundmusic.play();

    // music for hit 
    SoundBuffer hitting;
    hitting.loadFromFile("hit.wav");
    Sound hittingsound(hitting);

    // music for jump
    SoundBuffer jumping;
    jumping.loadFromFile("jump.wav");
    Sound jumpingsound(jumping);


    // music for level up
    SoundBuffer levelup_sound;
    levelup_sound.loadFromFile("level up.wav");
    Sound levelupsound(levelup_sound);

    // music for blue monster
    SoundBuffer bluemonsters1;
    bluemonsters1.loadFromFile("blue monster bing hit.wav");
    Sound bluemonstersound(bluemonsters1);
    SoundBuffer bluemonsters3;
    bluemonsters3.loadFromFile("blue moster hit.wav");
    Sound bluemonsterhitsound(bluemonsters3);

    // music for Snow Beast
    SoundBuffer snowbeast1;
    snowbeast1.loadFromFile("snow beast being hit.wav");
    Sound snowbeastsound(snowbeast1);
    SoundBuffer snowbeast3;
    snowbeast3.loadFromFile("snow beast hit.wav");
    Sound snowbeasthitsound(snowbeast3);

    //Music for Boss
    SoundBuffer snowboss1;
    snowboss1.loadFromFile("snow boss being hit.wav");
    Sound snowbosssound(snowboss1);
    SoundBuffer snowboss2;
    snowboss2.loadFromFile("snow boss dying.wav");
    Sound snowbossdyingsound(snowboss2);
    SoundBuffer snowboss3;
    snowboss3.loadFromFile("snow boss hit 1.wav");
    Sound snowbossattack1sound(snowboss3);
    SoundBuffer snowboss4;
    snowboss4.loadFromFile("snow boss hit 2.wav");
    Sound snowbossattack2sound(snowboss4);

    // * view * //
    View view;
    view.setSize(1000, 700);
    view.setCenter(530, 550);


     ///////////////
    // GAME LOOP //
   ///////////////

    while (window.isOpen())
    {
        //**//

   // * collision boxes * //
     // Character bounds
        FloatRect bound = character1_s.getGlobalBounds();
        FloatRect bound2 = character2_s.getGlobalBounds();
        FloatRect bound3 = character3_s.getGlobalBounds();

        // ground bound
        FloatRect groundbound[12];
        for (int i = 0; i < 12; i++) {
            groundbound[i] = grounds[i].getGlobalBounds();
        }

        // monster bound
        FloatRect monsterbound[8];
        for (int i = 0; i < 8; i++) {
            monsterbound[i] = monster_s[i].getGlobalBounds();
        }

        // effect bound 
        FloatRect monsterbound_effect[8];
        for (int i = 0; i < 8; i++) {
            monsterbound_effect[i] = monstereffect_s[i].getGlobalBounds();
        }

        // boss bounds
        FloatRect bossbound = boss_s.getGlobalBounds();
        FloatRect bossbound_hit = bosshit_s.getGlobalBounds();
        FloatRect bossbound_effect = bosseffect_s.getGlobalBounds();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
                break;
            }
            if (myhealth.getSize().x > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && ((vel[0].y >= -0.5 && vel[0].y <= 0) || (vel[0].y >= 0 && vel[0].y <= 0.5))) {
                jumpingsound.play();
            }
            if (bosshealth.getSize().x <= 0 && onlylevelupsoundonce <= 200) {
                levelupsound.play();
            }
            for (int i = 0; i < 8; i++) {
                if (i < 4) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                        if (bound2.intersects(monsterbound[i]) && characterhitframe_x == 1 && !monsterlevel_3[i].monsterdead)
                            bluemonstersound.play();
                        else if (characterhitframe_x == 1)
                            hittingsound.play();
                    }
                }
                if (i >= 4) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                        if (bound2.intersects(monsterbound[i]) && characterhitframe_x == 1 && !monsterlevel_3[i].monsterdead)
                            snowbeastsound.play();
                        else if (characterhitframe_x == 1)
                            hittingsound.play();
                    }
                }
            }
            for (int i = 0; i < 8; i++) {
                if (i < 4) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                        if (bound3.intersects(monsterbound[i]) && characterhitframe_x == 1 && !monsterlevel_3[i].monsterdead)
                            bluemonstersound.play();
                        else if (characterhitframe_x == 1)
                            hittingsound.play();
                    }
                }
                if (i >= 4) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                        if (bound3.intersects(monsterbound[i]) && characterhitframe_x == 1 && !monsterlevel_3[i].monsterdead)
                            snowbeastsound.play();
                        else if (characterhitframe_x == 1)
                            hittingsound.play();
                    }
                }
            }
            for (int i = 0; i < 8; i++) {
                if (myhealth.getSize().x >= 0) {
                    if (i < 4) {
                        if (monsterhit[i] && !monsterlevel_3[i].monsterdead && monsterlevel_3[i].monsterframe_2 == 3)
                            bluemonsterhitsound.play();
                    }
                    else if (i >= 4) {
                        if (monsterhit[i] && !monsterlevel_3[i].monsterdead && monsterlevel_3[i].monsterframe_2 == 0)
                            snowbeasthitsound.play();
                    }
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                if (bound2.intersects(bossbound) && characterhitframe_x == 1 && bosshealth.getSize().x >= 0) {
                    snowbosssound.play();
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                if (bound3.intersects(bossbound) && characterhitframe_x == 1 && bosshealth.getSize().x >= 0) {
                    snowbosssound.play();
                }
            }
            if (firsthit && bosshealth.getSize().x >= 0 && bossframe_x == 5)
                snowbossattack2sound.play();
            else if (secondhit && bosshealth.getSize().x >= 0 && bossframe_x == 7)
                snowbossattack1sound.play();
            if(bosshealth.getSize().x <= 0 && onlylevelupsoundonce <= 200)
                snowbossdyingsound.play();
        }



        //***//
        //XP increase
        for (int i = 0; i < 8; i++) {
            if (xpbar.getSize().x >= 300) {
                break;
            }
            //blue monster
            if (i < 4) {
                if (monsterlevel_3[i].monsterdead && monsterlevel_3[i].monsterframe == 1 && (monsterlevel_3[i].monsterframe2_h == 1 || monsterlevel_3[i].monsterframe2_h == 0)) {
                    xpbar.setSize(sf::Vector2f(xpbar.getSize().x + 0.37, 20));
                }
            }
            //snow Beast
            else
            {
                if (monsterlevel_3[i].monsterframe == 0 && (monsterlevel_3[i].monsterframe_h == 5 || monsterlevel_3[i].monsterframe_h == 4)) {
                    xpbar.setSize(sf::Vector2f(xpbar.getSize().x + 0.40, 20));
                }
            }
        }

        //**//

     // * movement * //
        //characte movement
        if (!canclimb) {
            if (myhealth.getSize().x > 0) {
                if (character1_s.getPosition().x <= 20)
                    character1_s.move(0.5, 0);
                if (character1_s.getPosition().x >= 1550)
                    character1_s.move(-0.5, 0);
                if (character1_s.getPosition().x >= 0 && character1_s.getPosition().x <= 1700) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        slowingcharactermove++;
                        vel[0].x = movespeed;
                        characterframe_y = 1;
                        if (slowingcharactermove == 80) {
                            characterframe_x++;
                            characterframe_x %= 4;
                            slowingcharactermove = 0;
                        }
                    }
                    //Left
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        slowingcharactermove++;
                        vel[0].x = -movespeed;
                        characterframe_y = 0;
                        if (slowingcharactermove == 80) {
                            characterframe_x++;
                            characterframe_x %= 4;
                            slowingcharactermove = 0;
                        }

                    }
                    else {
                        vel[0].x = 0;
                    }

                    //Jumping

                    if (Keyboard::isKeyPressed(Keyboard::LAlt) && canjump) {
                        canjump = false;
                        vel[0].y = -jumpspeed;
                    }
                    if (character1_s.getPosition().y + 85 < ground || vel[0].y < 0) {
                        vel[0].y += gravity;
                        if (vel[0].x == -0.05f)
                            vel[0].x -= 0.2f;
                        else if (vel[0].x == 0.05f)
                            vel[0].x += 0.2f;
                    }
                    else
                    {
                        vel[0].y = 0;
                        canjump = true;
                    }
                    //character moving
                    character1_s.move(vel[0].x, vel[0].y);

                }

                // character hitting 
                characterhitting1 = false;
                characterhitting2 = false;
                //first hit
                character2_s.setPosition(character1_s.getPosition().x - 70, character1_s.getPosition().y - 70);
                character3_s.setPosition(character1_s.getPosition().x - 70, character1_s.getPosition().y - 53);
                if (Keyboard::isKeyPressed(Keyboard::LControl)) {
                    slowingcharacterhit++;
                    characterhitting1 = true;
                    characterhitframe_y = characterframe_y;
                    if (slowingcharacterhit == 65) {
                        characterhitframe_x++;
                        characterhitframe_x %= 4;
                        slowingcharacterhit = 0;
                    }
                    //monster lose life
                    for (int i = 0; i < 8; i++) {
                        if (bound2.intersects(monsterbound[i]) && characterhitframe_x == 1 && !monsterlevel_3[i].monsterdead) {
                            monsterlevel_3[i].monsterdamage = true;
                            monsterlevel_3[i].monster_border = true;
                            monsterhealth[i].setSize(sf::Vector2f(monsterhealth[i].getSize().x - 0.25, 20));
                            if (monster_s[i].getPosition().x >= character2_s.getPosition().x) {
                                monster_s[i].move(0.3, 0);
                                monsterlevel_3[i].monstermoveleft = true;
                                monsterlevel_3[i].monstermoveright = false;
                            }
                            else if (monster_s[i].getPosition().x < character2_s.getPosition().x) {
                                monster_s[i].move(-0.3, 0);
                                monsterlevel_3[i].monstermoveright = true;
                                monsterlevel_3[i].monstermoveleft = false;
                            }
                        }
                    }

                    // boss lose life 
                    if (bound2.intersects(bossbound) && characterhitframe_x == 1 && !boss_dead) {
                        boss_damage = true;
                        bosshealth.setSize(sf::Vector2f(bosshealth.getSize().x - 0.25, 20));
                        if (boss_s.getPosition().x >= character2_s.getPosition().x) {
                            boss_s.move(0.3, 0);
                            bossmoveleft = true;
                            bossmoveright = false;
                        }
                        else if (boss_s.getPosition().x < character2_s.getPosition().x) {
                            boss_s.move(-0.3, 0);
                            bossmoveright = true;
                            bossmoveleft = false;
                        }
                    }
                }


                //second hit
                else if (Keyboard::isKeyPressed(Keyboard::Z)) {
                    slowingcharacterhit++;
                    characterhitting2 = true;
                    characterhitframe_y = characterframe_y;
                    if (slowingcharacterhit == 50) {
                        characterhitframe_x++;
                        characterhitframe_x %= 4;
                        slowingcharacterhit = 0;
                    }
                    //monster lose life
                    for (int i = 0; i < 8; i++) {
                        if (bound3.intersects(monsterbound[i]) && characterhitframe_x == 2 && !monsterlevel_3[i].monsterdead) {
                            monsterlevel_3[i].monsterdamage = true;
                            monsterlevel_3[i].monster_border = true;
                            monsterhealth[i].setSize(sf::Vector2f(monsterhealth[i].getSize().x - 0.25, 20));
                            if (monster_s[i].getPosition().x >= character3_s.getPosition().x) {
                                monster_s[i].move(0.3, 0);
                                monsterlevel_3[i].monstermoveleft = true;
                                monsterlevel_3[i].monstermoveright = false;
                            }
                            else if (monster_s[i].getPosition().x < character3_s.getPosition().x) {
                                monster_s[i].move(-0.3, 0);
                                monsterlevel_3[i].monstermoveright = true;
                                monsterlevel_3[i].monstermoveleft = false;
                            }
                        }
                    }
                    // boss lose life 
                    if (bound3.intersects(bossbound) && characterhitframe_x == 2 && !boss_dead) {
                        boss_damage = true;
                        bosshealth.setSize(sf::Vector2f(bosshealth.getSize().x - 0.25, 20));
                        if (boss_s.getPosition().x >= character3_s.getPosition().x) {
                            boss_s.move(0.3, 0);
                            bossmoveleft = true;
                            bossmoveright = false;
                        }
                        else if (boss_s.getPosition().x < character2_s.getPosition().x) {
                            boss_s.move(-0.3, 0);
                            bossmoveright = true;
                            bossmoveleft = false;
                        }
                    }
                }
            }
        }

        //Monster movement
        for (int i = 0; i < 8; i++) {
            if (!monsterlevel_3[i].monsterdead && !monsterhit[i]) {
                if (monsterlevel_3[i].monstermoveright) {
                    monsterlevel_3[i].monsterframe_h = 2;
                    monsterlevel_3[i].slowingmonstermove++;
                    if (monsterlevel_3[i].slowingmonstermove == 80) {
                        monsterlevel_3[i].monsterframe++;
                        monsterlevel_3[i].monsterframe %= 4;
                        monsterlevel_3[i].slowingmonstermove = 0;
                    }
                    monster_s[i].move(0.15, 0);
                }
                if (monsterlevel_3[i].monstermoveleft) {
                    monsterlevel_3[i].monsterframe_h = 0;
                    monsterlevel_3[i].slowingmonstermove++;
                    if (monsterlevel_3[i].slowingmonstermove == 80) {
                        monsterlevel_3[i].monsterframe++;
                        monsterlevel_3[i].monsterframe %= 4;
                        monsterlevel_3[i].slowingmonstermove = 0;
                    }
                    monster_s[i].move(-0.15, 0);
                }
            }
        }

        // monster attacking Positioning
        for (int i = 0; i < 8; i++) {
            // blue monster
            if (i < 4)
                monsterattack_s[i].setPosition(monster_s[i].getPosition().x - 50, monster_s[i].getPosition().y - 15);
            else if (monsterlevel_3[i].monstermoveright)
                monsterattack_s[i].setPosition(monster_s[i].getPosition().x, monster_s[i].getPosition().y - 100);
            // snow beast
            else
                monsterattack_s[i].setPosition(monster_s[i].getPosition().x - 100, monster_s[i].getPosition().y - 100);
        }

        //Monster attacking ( blue monster )
        for (int i = 0; i < 4; i++) {
            if (myhealth.getSize().x >= 0) {
                if (abs(character1_s.getPosition().x - monster_s[i].getPosition().x) <= 200 && abs(character1_s.getPosition().y - monster_s[i].getPosition().y) <= 150) {
                    monsterhit[i] = true;
                }
                else if (monsterlevel_3[i].monsterframe_2 == 6 || myhealth.getSize().x <= 0 || abs(character1_s.getPosition().x - monster_s[i].getPosition().x) - 30 >= 180 || abs(character1_s.getPosition().y - monster_s[i].getPosition().y) >= 150)
                    monsterhit[i] = false;
                if (monsterlevel_3[i].monsterdead)
                    monsterhit[i] = false;
            }
            if (myhealth.getSize().x <= 0)
                monsterhit[i] = false;
        }

        for (int i = 0; i < 4; i++) {
            if (myhealth.getSize().x >= 0) {
                if (monsterhit[i]) {
                    if (abs(monsterattack_s[i].getPosition().x - (character1_s.getPosition().x - 50)) <= 120) {

                    }
                    else if (monsterattack_s[i].getPosition().x >= character1_s.getPosition().x) {
                        monsterlevel_3[i].monstermoveleft = true;
                        monsterlevel_3[i].monstermoveright = false;
                    }
                    else if (monsterattack_s[i].getPosition().x <= character1_s.getPosition().x) {
                        monsterlevel_3[i].monstermoveright = true;
                        monsterlevel_3[i].monstermoveleft = false;
                    }
                    if (monsterlevel_3[i].monstermoveright) {
                        monsterlevel_3[i].monsterframe_h = 2;
                        monsterlevel_3[i].monsterframe2_h = 3;
                    }
                    else if (monsterlevel_3[i].monstermoveleft) {
                        monsterlevel_3[i].monsterframe_h = 0;
                        monsterlevel_3[i].monsterframe2_h = 2;
                    }
                    monsterlevel_3[i].slowingmonster2_move++;
                    if (monsterlevel_3[i].slowingmonster2_move == 50) {
                        monsterlevel_3[i].monsterframe_2++;
                        monsterlevel_3[i].monsterframe_2 %= 9;
                        monsterlevel_3[i].slowingmonster2_move = 0;
                    }
                }
            }
        }

        //Monster attacking (snow beast)
        for (int i = 4; i < 8; i++) {
            if (myhealth.getSize().x >= 0) {
                if (abs(character1_s.getPosition().x - monster_s[i].getPosition().x) <= 200 && abs(character1_s.getPosition().y - monster_s[i].getPosition().y) <= 150) {
                    monsterhit[i] = true;
                }
                else if (monsterlevel_3[i].monsterframe_2 == 6 || monsterlevel_3[i].monsterdead || abs(character1_s.getPosition().x - monster_s[i].getPosition().x) - 30 >= 180 || abs(character1_s.getPosition().y - monster_s[i].getPosition().y) >= 150)
                    monsterhit[i] = false;
            }
            if (myhealth.getSize().x <= 0)
                monsterhit[i] = false;
        }

        for (int i = 4; i < 8; i++) {
            if (myhealth.getSize().x >= 0) {
                if (monsterhit[i]) {
                    if (abs(monsterattack_s[i].getPosition().x - (character1_s.getPosition().x - 50)) <= 120) {

                    }
                    else if (monsterattack_s[i].getPosition().x >= character1_s.getPosition().x) {
                        monsterlevel_3[i].monstermoveleft = true;
                        monsterlevel_3[i].monstermoveright = false;
                    }
                    else if (monsterattack_s[i].getPosition().x <= character1_s.getPosition().x) {
                        monsterlevel_3[i].monstermoveright = true;
                        monsterlevel_3[i].monstermoveleft = false;
                    }
                    if (monsterlevel_3[i].monstermoveright) {
                        monsterlevel_3[i].monsterframe_h = 2;
                        monsterlevel_3[i].monsterframe2_h = 1;
                    }
                    else if (monsterlevel_3[i].monstermoveleft) {
                        monsterlevel_3[i].monsterframe_h = 0;
                        monsterlevel_3[i].monsterframe2_h = 0;
                    }
                    monsterlevel_3[i].slowingmonster2_move++;
                    if (monsterlevel_3[i].slowingmonster2_move == 100) {
                        monsterlevel_3[i].monsterframe_2++;
                        monsterlevel_3[i].monsterframe_2 %= 6;
                        monsterlevel_3[i].slowingmonster2_move = 0;
                    }
                }
            }
        }
        //BOSS
        count_dead_monsters = 0;
        for (int i = 0; i < 8; i++) {
            if (monsterlevel_3[i].monsterdead)
                count_dead_monsters++;
            if (count_dead_monsters == 8)
                bossfight = true;
        }
        if (bossfight) {
            if (firsthit)
                num_of_frames = 12;
            else if (secondhit)
                num_of_frames = 13;
            else if (bosshealth.getSize().x <= 0)
                num_of_frames = 11;
            else
                num_of_frames = 8;
            returnview++;
            if (bosshealth.getSize().x >= 0) {
                if ((boss_s.getPosition().x + 150) < character1_s.getPosition().x) {
                    bossmoveright = true;
                    bossmoveleft = false;
                    if (!firsthit && !secondhit) {
                        boss_s.move(0.15, 0);
                        bossframe_y = 2;
                        slowingbossmove++;
                        if (slowingbossmove == 100) {
                            bossframe_x++;
                            bossframe_x %= num_of_frames;
                            slowingbossmove = 0;
                        }
                    }
                }
                else if ((boss_s.getPosition().x + 150) > character1_s.getPosition().x) {
                    bossmoveleft = true;
                    bossmoveright = false;
                    if (!firsthit && !secondhit) {
                        boss_s.move(-0.15, 0);
                        bossframe_y = 0;
                        slowingbossmove++;
                        if (slowingbossmove == 100) {
                            bossframe_x++;
                            bossframe_x %= num_of_frames;
                            slowingbossmove = 0;
                        }
                    }
                }
                if (myhealth.getSize().x >= 0) {
                    if (abs(character1_s.getPosition().x - (boss_s.getPosition().x + 150)) <= 250 && abs(character1_s.getPosition().y - boss_s.getPosition().y) <= 150) {
                        firsthit = true;
                    }
                    else if (bossframe_x == 11 || boss_dead || abs(character1_s.getPosition().x - (boss_s.getPosition().x + 150)) >= 250 || abs(character1_s.getPosition().y - boss_s.getPosition().y) >= 150)
                        firsthit = false;

                    if (!boss_dead && !firsthit && abs(character1_s.getPosition().x - (boss_s.getPosition().x + 150)) <= 350 && abs(character1_s.getPosition().y - boss_s.getPosition().y) <= 150) {
                        secondhit = true;
                    }
                    else if (firsthit || bossframe_x == 13 || boss_dead || abs(character1_s.getPosition().x - (boss_s.getPosition().x + 150)) >= 350 || abs(character1_s.getPosition().y - boss_s.getPosition().y) >= 150) {
                        secondhit = false;
                    }
                }
                if (myhealth.getSize().x <= 0) {
                    firsthit = false;
                    secondhit = false;
                }

                if (firsthit) {
                    if (bossmoveleft)
                        bossframe_y = 6;
                    else if (bossmoveright)
                        bossframe_y = 7;
                    slowingbossmove++;
                    if (slowingbossmove == 100) {
                        bossframe_x++;
                        bossframe_x %= num_of_frames;
                        slowingbossmove = 0;
                    }
                    if (bound.intersects(bossbound) && (bossframe_x == 5 || bossframe_x == 6) && bosshealth.getSize().x>0)
                        myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.1, 15));
                }
                if (secondhit) {
                    if (bossmoveleft) {
                        bosseffectframe_y = 1;
                        bossframe_y = 8;
                        bosshit_s.move(-0.5, 0);
                    }
                    else if (bossmoveright) {
                        bosseffectframe_y = 0;
                        bossframe_y = 9;
                        bosshit_s.move(0.5, 0);
                    }
                    slowingbossmove++;
                    if (slowingbossmove == 100) {
                        bossframe_x++;
                        if (bossframe_x == 7) {
                            bossballframe_x++;
                            bossballframe_x %= 3;
                        }
                        bossframe_x %= num_of_frames;
                        slowingbossmove = 0;
                    }

                }
            }
        }





        //**//
 // * losing life * //
   // character losing life
        for (int i = 0; i < 8; i++) {
            if (!monsterlevel_3[i].monsterdead && bound.intersects(monsterbound[i]) && myhealth.getSize().x > 0) {
                myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.1, 15));
            }
        }

        //Character death
        if (myhealth.getSize().x < 0) {
            if (grave_s.getPosition().y < ground - 120) {
                velocity.y += gravity;
            }
            else {
                velocity.y = 0;
            }
            grave_s.move(0, velocity.y * 4);
            if (velocity.y == 0) {
                slowinggrave++;
                if (slowinggrave == 100) {
                    if (graveanimation == 5)
                        graveanimation = 5;
                    else
                        graveanimation++;
                    slowinggrave = 0;
                }
            }
        }

        //monster hitting animation
        for (int i = 0; i < 8; i++) {
            if (monsterlevel_3[i].monsterdamage) {
                monster_index = i;
                monsterlevel_3[monster_index].monsterframe = 0;
                if (monsterlevel_3[monster_index].monstermoveleft)
                    monsterlevel_3[monster_index].monsterframe_h = 1;
                if (monsterlevel_3[monster_index].monstermoveright)
                    monsterlevel_3[monster_index].monsterframe_h = 3;
                monsterlevel_3[monster_index].monsterdamage = false;
            }
        }

        // boss hitting animation
        if (boss_damage && firsthit && bosshealth.getSize().x >= 0) {
            bossframe_x = 0;
            if (bossmoveleft)
                bossframe_y = 1;
            if (bossmoveright)
                bossframe_y = 3;
            boss_damage = false;
        }

        //**//
  // * monster dying  * //

    // blue monster
        for (int i = 0; i < 4; i++) {
            if (monsterhealth[i].getSize().x <= 0) {
                monster_index = i;
                count[i]++;
                if (count[i] == 1000)
                    monsterlevel_3[i].monsterdying = true;
                // blue monster
                monsterlevel_3[monster_index].monsterdead = true;
                if (monsterlevel_3[monster_index].monstermoveright) {
                    monsterlevel_3[monster_index].monsterframe2_h = 1;
                }
                if (monsterlevel_3[monster_index].monstermoveleft) {
                    monsterlevel_3[monster_index].monsterframe2_h = 0;
                }
                monsterlevel_3[monster_index].slowingmonster2_move++;
                if (monsterlevel_3[monster_index].slowingmonster2_move == 50) {
                    monsterlevel_3[monster_index].monsterframe++;
                    monsterlevel_3[monster_index].slowingmonster2_move = 0;
                }
            }
        }

        // snow beast
        for (int i = 4; i < 8; i++) {
            if (monsterhealth[i].getSize().x <= 0) {
                monster_index2 = i;
                count[i]++;
                if (count[i] == 1000)
                    monsterlevel_3[i].monsterdying = true;
                // snow beast
                monsterlevel_3[monster_index2].monsterdead = true;
                if (monsterlevel_3[monster_index2].monstermoveright) {
                    monsterlevel_3[monster_index2].monsterframe_h = 5;
                }
                if (monsterlevel_3[monster_index2].monstermoveleft) {
                    monsterlevel_3[monster_index2].monsterframe_h = 4;
                }
                monsterlevel_3[monster_index2].slowingmonstermove++;
                if (monsterlevel_3[monster_index2].slowingmonstermove == 100) {
                    monsterlevel_3[monster_index2].monsterframe++;
                    monsterlevel_3[monster_index2].slowingmonstermove = 0;
                }
            }
        }

        // boss 
        if (bosshealth.getSize().x <= 0) {
            if (bossmoveright) {
                bossframe_y = 5;
            }
            if (bossmoveleft) {
                bossframe_y = 4;
            }
            slowingbossmove++;
            if (slowingbossmove == 100) {
                bossframe_x++;
                slowingbossmove = 0;
            }
            if (bossframe_x == num_of_frames)
                boss_dead = true;
            xpbar.setSize(Vector2f(300, 20));

        }


        //**//
  //  * GROUNDS * //

     //ground 1
        if (bound.intersects(groundbound[1])) {
            ground = 610;

        }
        if (ground == 610 && character1_s.getPosition().x <= 317 || ground == 610 && character1_s.getPosition().x >= 403) {
            ground = 830;
        }

        // ground 2
        if (bound.intersects(groundbound[2])) {
            canclimb = false;
            ground = 530;
        }
        if (ground == 530 && character1_s.getPosition().x >= 280 && character1_s.getPosition().x <= 317 || character1_s.getPosition().x <= 1344 && character1_s.getPosition().x >= 1295 || character1_s.getPosition().x <= 1218 && character1_s.getPosition().x >= 403) {
            ground = 830;
        }

        // ground 3
        if (bound.intersects(groundbound[3])) {
            ground = 310;
            canclimb = false;
        }
        if (ground == 310 && character1_s.getPosition().x >= 385 && character1_s.getPosition().x <= 1140 || character1_s.getPosition().x >= 1190 && character1_s.getPosition().x <= 1218) {
            ground = 830;

        }

        // ground 4
        if (bound.intersects(groundbound[4])) {
            ground = 230;
        }
        if (ground == 230 && character1_s.getPosition().x >= 385 && character1_s.getPosition().x <= 420 || character1_s.getPosition().x >= 505 && character1_s.getPosition().x <= 1140 || character1_s.getPosition().x >= 1190 && character1_s.getPosition().x <= 1218) {
            ground = 830;

        }

        // ground 5
        if (bound.intersects(groundbound[5])) {
            ground = 160;
        }
        if (ground == 160 && character1_s.getPosition().x <= 515 || character1_s.getPosition().x >= 612 && character1_s.getPosition().x <= 1140 || character1_s.getPosition().x >= 1190 && character1_s.getPosition().x <= 1218) {
            ground = 830;
        }

        //ground 6
        if (bound.intersects(groundbound[6])) {
            ground = 610;

        }
        if (ground == 610 && character1_s.getPosition().x <= 1218 && character1_s.getPosition().x >= 403 || character1_s.getPosition().x >= 1295 && character1_s.getPosition().x <= 1344) {

            ground = 830;
        }

        // ground 7
        if (bound.intersects(groundbound[7])) {
            canclimb = false;
            ground = 530;
        }

        //ground 8
        if (bound.intersects(groundbound[8])) {
            ground = 450;
        }
        if (ground == 450 && character1_s.getPosition().x <= 1218 && character1_s.getPosition().x >= 403 || ground == 450 && character1_s.getPosition().x >= 1295 && character1_s.getPosition().x <= 1344) {

            ground = 830;
        }

        // ground 9
        if (bound.intersects(groundbound[9])) {
            canclimb = false;
            ground = 310;
        }


        // ground 10
        if (bound.intersects(groundbound[10])) {
            canclimb = false;
            ground = 230;
        }


        // ground 11
        if (bound.intersects(groundbound[11])) {

            ground = 160;
        }


        //**//
      // * climbing * //

         // Rob 1
        if (character1_s.getPosition().x >= 206 && character1_s.getPosition().x <= 216 && ground == 830 && Keyboard::isKeyPressed(Keyboard::Up)) {
            canclimb = true;
            slowingcharactermove++;
            characterframe_y = 2;
            characterframe_x++;
            characterframe_x %= 3;
            slowingcharactermove = 0;
            character1_s.move(0, -0.4);
        }

        // Rob 2
        if (character1_s.getPosition().x >= 151 && character1_s.getPosition().x <= 161 && ground == 530 && Keyboard::isKeyPressed(Keyboard::Up)) {
            canclimb = true;
            slowingcharactermove++;
            characterframe_y = 2;
            characterframe_x++;
            characterframe_x %= 3;
            slowingcharactermove = 0;
            character1_s.move(0, -0.4);
        }

        // Rob 3
        if (character1_s.getPosition().x >= 1406 && character1_s.getPosition().x <= 1416 && ground == 830 && Keyboard::isKeyPressed(Keyboard::Up)) {
            canclimb = true;
            slowingcharactermove++;
            characterframe_y = 2;
            characterframe_x++;
            characterframe_x %= 3;
            slowingcharactermove = 0;
            character1_s.move(0, -0.4);
        }
        // Rob 4
        if (character1_s.getPosition().x >= 1241 && character1_s.getPosition().x <= 1251 && ground == 450 && Keyboard::isKeyPressed(Keyboard::Up)) {
            canclimb = true;
            slowingcharactermove++;
            characterframe_y = 2;
            characterframe_x++;
            characterframe_x %= 3;
            slowingcharactermove = 0;
            character1_s.move(0, -0.4);
        }


        //**//

    // * position * //

        // character Health positioning
        myhealth.setPosition(view.getCenter().x - 350, view.getCenter().y - 320);
        myhealthborder.setPosition(view.getCenter().x - 350, view.getCenter().y - 320);
        text1.setPosition(myhealthborder.getPosition().x - 135, myhealthborder.getPosition().y - 10);

        // XP bar positioning
        xpbar.setPosition(view.getCenter().x - 350, view.getCenter().y - 270);
        xpbarborder.setPosition(view.getCenter().x - 350, view.getCenter().y - 270);
        text2.setPosition(xpbarborder.getPosition().x - 90, xpbarborder.getPosition().y - 10);

        // boss health positioning
        bosshealth.setPosition(boss_s.getPosition().x + 20, boss_s.getPosition().y - 15);
        bosshealthborder.setPosition(boss_s.getPosition().x + 20, boss_s.getPosition().y - 15);

        if (firsthit || secondhit) {
            bosshealth.setPosition(boss_s.getPosition().x + 50, boss_s.getPosition().y - 15);
            bosshealthborder.setPosition(boss_s.getPosition().x + 50, boss_s.getPosition().y - 15);
        }

        // monster health positioning
        for (int i = 0; i < 8; i++) {
            if (i < 4) {
                monsterhealth[i].setPosition(monster_s[i].getPosition().x + 20, monster_s[i].getPosition().y - 15);
                monsterborder[i].setPosition(monster_s[i].getPosition().x + 20, monster_s[i].getPosition().y - 15);
            }
            else if (monsterhit[i]) {
                monsterhealth[i].setPosition(monster_s[i].getPosition().x + 70, monster_s[i].getPosition().y - 15);
                monsterborder[i].setPosition(monster_s[i].getPosition().x + 70, monster_s[i].getPosition().y - 15);
            }
            else {
                monsterhealth[i].setPosition(monster_s[i].getPosition().x + 20, monster_s[i].getPosition().y - 15);
                monsterborder[i].setPosition(monster_s[i].getPosition().x + 20, monster_s[i].getPosition().y - 15);
            }
        }
        //Heart Positioning
        heart[0].setPosition(view.getCenter().x - 90, view.getCenter().y - 410);
        heart[1].setPosition(view.getCenter().x - 30, view.getCenter().y - 410);
        heart[2].setPosition(view.getCenter().x + 30, view.getCenter().y - 410);
        heart[3].setPosition(view.getCenter().x + 90, view.getCenter().y - 410);
        heart[4].setPosition(view.getCenter().x + 150, view.getCenter().y - 410);

        //monster positoning booleans
        if (!monsterlevel_3[0].monsterdead) {
            if (monster_s[0].getPosition().x <= 300) {
                monsterlevel_3[0].monstermoveright = true;
                monsterlevel_3[0].monstermoveleft = false;
            }
            if (monster_s[0].getPosition().x >= 600) {
                monsterlevel_3[0].monstermoveright = false;
                monsterlevel_3[0].monstermoveleft = true;
            }
        }

        if (!monsterlevel_3[1].monsterdead) {
            if (monster_s[1].getPosition().x <= 500) {
                monsterlevel_3[1].monstermoveright = true;
                monsterlevel_3[1].monstermoveleft = false;
            }
            if (monster_s[1].getPosition().x >= 750) {
                monsterlevel_3[1].monstermoveright = false;
                monsterlevel_3[1].monstermoveleft = true;
            }
        }

        if (!monsterlevel_3[2].monsterdead) {
            if (monster_s[2].getPosition().x <= 1350) {
                monsterlevel_3[2].monstermoveright = true;
                monsterlevel_3[2].monstermoveleft = false;
            }
            if (monster_s[2].getPosition().x >= 1450) {
                monsterlevel_3[2].monstermoveright = false;
                monsterlevel_3[2].monstermoveleft = true;
            }
        }

        if (!monsterlevel_3[3].monsterdead) {
            if (monster_s[3].getPosition().x <= 1220) {
                monsterlevel_3[3].monstermoveright = true;
                monsterlevel_3[3].monstermoveleft = false;
            }
            if (monster_s[3].getPosition().x >= 1450) {
                monsterlevel_3[3].monstermoveright = false;
                monsterlevel_3[3].monstermoveleft = true;
            }
        }

        if (!monsterlevel_3[4].monsterdead) {
            if (monster_s[4].getPosition().x <= 800) {
                monsterlevel_3[4].monstermoveright = true;
                monsterlevel_3[4].monstermoveleft = false;
            }
            if (monster_s[4].getPosition().x >= 1100) {
                monsterlevel_3[4].monstermoveright = false;
                monsterlevel_3[4].monstermoveleft = true;
            }
        }

        if (!monsterlevel_3[5].monsterdead) {
            if (monster_s[5].getPosition().x >= 1000) {
                monsterlevel_3[5].monstermoveright = false;
                monsterlevel_3[5].monstermoveleft = true;
            }
            if (monster_s[5].getPosition().x <= 500) {
                monsterlevel_3[5].monstermoveright = true;
                monsterlevel_3[5].monstermoveleft = false;
            }
        }

        if (!monsterlevel_3[6].monsterdead) {
            if (monster_s[6].getPosition().x <= 50) {
                monsterlevel_3[6].monstermoveright = true;
                monsterlevel_3[6].monstermoveleft = false;
            }
            if (monster_s[6].getPosition().x >= 200) {
                monsterlevel_3[6].monstermoveright = false;
                monsterlevel_3[6].monstermoveleft = true;
            }

        }

        if (!monsterlevel_3[7].monsterdead) {
            if (monster_s[7].getPosition().x >= 350) {
                monsterlevel_3[7].monstermoveright = false;
                monsterlevel_3[7].monstermoveleft = true;
            }
            if (monster_s[7].getPosition().x <= 50) {
                monsterlevel_3[7].monstermoveright = true;
                monsterlevel_3[7].monstermoveleft = false;
            }
        }

        //**//

     // * view * //
        // view on x
        if (returnview == 0 || returnview >= 3000) {
            if (view.getCenter().x - character1_s.getPosition().x <= 150 && view.getCenter().x <= 1100) {
                view.move(0.5, 0);
            }

            if (view.getCenter().x - character1_s.getPosition().x >= 100 && view.getCenter().x > 520) {
                view.move(-0.5, 0);

            }
            // view on y
            if (character1_s.getPosition().y - view.getCenter().y <= 30) {
                if (view.getCenter().y >= 350)
                    view.move(0, -0.3);
            }
            if (character1_s.getPosition().y - view.getCenter().y > 200) {
                if (view.getCenter().y <= 550)
                    view.move(0, 2);
            }
        }
        if (returnview <= 3000 && !returnview == 0) {
            if (view.getCenter().x <= 1100)
                view.move(2, 0);
            if (view.getCenter().y <= 550)
                view.move(0, 2);
        }

        //**//
 // * Displaying * //
        window.setView(view);
        window.clear();

        // * Displaying background * //
        window.draw(background_s);

        //**//
        //Level up and Portal
        if (bosshealth.getSize().x <= 0) {
            level_upsound = true;
            onlylevelupsoundonce++;
            slowinglevel++;
            if (slowinglevel % 80 == 0) {
                width++;
            }
            levelup.setPosition(character1_s.getPosition().x - 300, character1_s.getPosition().y - 285);
            levelup.setTextureRect(sf::IntRect(width * 679, 0, 679, 400));
            window.draw(levelup);
            slowingportal++;
            if (slowingportal % 50 == 0) {
                portalframes++;
                if (portalframes == 4) {
                    portalframes = 0;
                }
            }
            portal.setTextureRect(sf::IntRect(portalframes * 300, 0, 300, 300));
            portal.setPosition(1200, 620);
            window.draw(portal);
            if (character1_s.getPosition().x >= 1280 && character1_s.getPosition().x <= 1350) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    xpbar.setSize(sf::Vector2f(0, 20));
                    mainmenubool = false;
                    startlevel_1 = false;
                    startlevel_2 = false;
                    startlevel_3 = false;
                    startlevel_4 = true;
                    startlevel_5 = false;
                    break;
                }
            }
        }

        // * Displaying Character * //
        if (myhealth.getSize().x > 0) {
            grave_s.setPosition(character1_s.getPosition().x, -300);
            if (!characterhitting1 && !characterhitting2) {
                character1_s.setTextureRect(sf::IntRect(56.5 * characterframe_x, 85 * characterframe_y, 56.5, 85));
                window.draw(character1_s);
            }
            else if (characterhitting1) {
                character2_s.setTextureRect(sf::IntRect(160 * characterhitframe_x, 150 * characterhitframe_y, 160, 150));
                window.draw(character2_s);
            }
            else if (characterhitting2) {
                character3_s.setTextureRect(sf::IntRect(195 * characterhitframe_x, 200 * characterhitframe_y, 195, 200));
                window.draw(character3_s);
            }
        }
        else if (myhealth.getSize().x < 0) {
            text7.setPosition(view.getCenter().x - 300, view.getCenter().y);
            text3.setPosition(view.getCenter().x - 360, view.getCenter().y - 50);
            window.draw(grave_s);
            //Restart level
            if (number_of_lives == 1) {
                window.draw(text7);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    restart = true;
                    startlevel_3 = false;
                    mainmenubool = true;
                    window.setView(window.getDefaultView());
                    break;
                }
            }
            else if (number_of_lives > 1) {
                window.draw(text3);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    myhealth.setSize(sf::Vector2f(300.0f, 15.0f));
                    number_of_lives--;
                    startlevel_3 = true;
                    break;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
                    restart = true;
                    startlevel_1 = false;
                    startlevel_2 = false;
                    startlevel_3 = false;
                    startlevel_4 = false;
                    startlevel_5 = false;
                    mainmenubool = true;
                    window.setView(window.getDefaultView());
                    break;
                }
            }
        }

        //**//

      // * Displaying monster * //
        // blue monster
        //Drawing Health
        for (int index = 0; index < 4; index++) {
            if (!monsterlevel_3[index].monsterdead && monsterlevel_3[index].monster_border) {
                window.draw(monsterhealth[index]);
                window.draw(monsterborder[index]);
            }
        }
        //Drawing Monster
        for (int index = 0; index < 4; index++) {
            if (!monsterlevel_3[index].monsterdying) {
                if ((monsterhit[index] || monsterlevel_3[index].monsterdead)) {
                    window.draw(monsterattack_s[index]);
                }
                else if (!monsterlevel_3[index].monsterdead) {
                    window.draw(monster_s[index]);
                }
            }
        }
        //Drawing Effect
        for (int index = 0; index < 4; index++) {

            monsterlevel_3[index].slowingeffect_move++;
            if (monsterlevel_3[index].slowingeffect_move == 80) {
                monsterlevel_3[index].effectframe_x++;
                monsterlevel_3[index].effectframe_x %= 3;
                monsterlevel_3[index].slowingeffect_move = 0;
            }

            if (monsterhit[index] && monsterlevel_3[index].monsterframe_2 >= 3 && monsterlevel_3[index].monsterframe_2 <= 6 && canjump && !monsterlevel_3[index].monsterdead && myhealth.getSize().x >= 0) {
                if (bound.intersects(monsterbound_effect[index]))
                    myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.1, 15));
                window.draw(monstereffect_s[index]);
            }
        }

        // snow beast
        //Drawing Health
        for (int index = 4; index < 8; index++) {
            if (!monsterlevel_3[index].monsterdead && monsterlevel_3[index].monster_border) {
                window.draw(monsterhealth[index]);
                window.draw(monsterborder[index]);
            }
        }
        //Drawing Monster
        for (int index = 4; index < 8; index++) {
            if (!monsterlevel_3[index].monsterdying) {
                if (monsterhit[index] && !monsterlevel_3[index].monsterdead) {
                    window.draw(monsterattack_s[index]);
                }
                else {
                    window.draw(monster_s[index]);
                }
            }
        }
        //Drawing Effect
        for (int index = 4; index < 8; index++) {
            if (monsterlevel_3[index].monsterframe_2 < 3 || monsterlevel_3[index].monsterframe_2 > 5) {
                monsterlevel_3[index].effectframe_x = 0;
                monstereffect_s[index].setPosition(character1_s.getPosition().x - 20, ground - 150);
            }
            if (monsterlevel_3[index].monsterframe_2 >= 3) {
                monsterlevel_3[index].slowingeffect_move++;
                if (monsterlevel_3[index].slowingeffect_move == 120) {
                    monsterlevel_3[index].effectframe_x++;
                    monsterlevel_3[index].effectframe_x %= 3;
                    monsterlevel_3[index].slowingeffect_move = 0;
                }
            }

            if (monsterhit[index] && monsterlevel_3[index].monsterframe_2 >= 3 && monsterlevel_3[index].monsterframe_2 <= 5 && !monsterlevel_3[index].monsterdead && myhealth.getSize().x >= 0) {
                if (bound.intersects(monsterbound_effect[index]) && canjump)
                    myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.1, 15));
                window.draw(monstereffect_s[index]);
            }
        }

        //Draw Boss
          // Drawing health
        if (!boss_dead) {
            if (bosshealth.getSize().x >= 0) {
                window.draw(bosshealth);
                window.draw(bosshealthborder);
            }
            window.draw(boss_s);
        }

        // Drawing ball
        if (secondhit && bosshealth.getSize().x >= 0) {
            if (bossframe_x >= 8) {
                if (drawball) {
                    window.draw(bosshit_s);
                    if (bound.intersects(bossbound_hit)) {
                        myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 10, 15));
                        drawball = false;
                    }
                }
            }
            else {
                drawball = true;
                bosseffectframe_x = 0;
                if (bossmoveleft)
                    bosshit_s.setPosition(boss_s.getPosition().x + 30, boss_s.getPosition().y + 100);
                else if (bossmoveright)
                    bosshit_s.setPosition(boss_s.getPosition().x + 160, boss_s.getPosition().y + 100);
            }
            if (!drawball) {
                slowingbosseffect++;
                if (slowingbosseffect == 60) {
                    bosseffectframe_x++;
                    slowingbosseffect = 0;
                }
                bosseffect_s.setPosition(character1_s.getPosition().x - 30, character1_s.getPosition().y - 20);
                bosseffect_s.setTextureRect(sf::IntRect(95 * bosseffectframe_x, 105 * bosseffectframe_y, 95, 105));
                window.draw(bosseffect_s);
            }
        }
        window.draw(guide);
        if (character1_s.getPosition().x >= 100 && character1_s.getPosition().x <= 125) {
            window.draw(text6);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                show_guide = true;
            }
            if (show_guide) {
                window.draw(panel);
                window.draw(guide_text);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                    show_guide = false;

                }
            }
        }
        else
            show_guide = false;

        // Drawing Hearts
        for (int i = 0; i < number_of_lives; i++)
            window.draw(heart[i]);


        // Displaying text
        window.draw(text1);
        window.draw(text2);
        window.draw(myhealth);
        window.draw(myhealthborder);
        window.draw(xpbar);
        window.draw(xpbarborder);

        window.display();

        //IntRects
        //Blue Monster
        for (int index = 0; index < 4; index++) {
            if (monsterhit[index] && !monsterlevel_3[index].monsterdead && myhealth.getSize().x > 0) {
                monsterattack_s[index].setTextureRect(sf::IntRect(190 * monsterlevel_3[index].monsterframe_2, 155 * monsterlevel_3[index].monsterframe2_h, 190, 155));
                monstereffect_s[index].setTextureRect(sf::IntRect(55 * monsterlevel_3[index].effectframe_x, 0, 55, 80));
                monstereffect_s[index].setPosition(character1_s.getPosition().x - 20, ground - 80);
            }
            else if (monsterlevel_3[index].monsterdead && myhealth.getSize().x > 0)
                monsterattack_s[index].setTextureRect(sf::IntRect(190 * monsterlevel_3[index].monsterframe, 155 * monsterlevel_3[index].monsterframe2_h, 190, 155));
            else {
                monster_s[index].setTextureRect(sf::IntRect(125 * monsterlevel_3[index].monsterframe, 125 * monsterlevel_3[index].monsterframe_h, 125, 125));
            }
        }
        //Snow Beast
        for (int index = 4; index < 8; index++) {
            if (monsterhit[index] && !monsterlevel_3[index].monsterdead && myhealth.getSize().x > 0) {
                monsterattack_s[index].setTextureRect(sf::IntRect(255 * monsterlevel_3[index].monsterframe_2, 235 * monsterlevel_3[index].monsterframe2_h, 255, 235));
                monstereffect_s[index].setTextureRect(sf::IntRect(55 * monsterlevel_3[index].effectframe_x, 0, 55, 80));

            }
            else if (!monsterlevel_3[index].monsterdead || myhealth.getSize().x <= 0) {
                monster_s[index].setTextureRect(sf::IntRect(135 * monsterlevel_3[index].monsterframe, 135 * monsterlevel_3[index].monsterframe_h, 135, 135));
            }
            else if (monsterlevel_3[index].monsterdead) {
                monster_s[index].setTextureRect(sf::IntRect(200 * monsterlevel_3[index].monsterframe, 135 * monsterlevel_3[index].monsterframe_h, 200, 135));
            }
        }
        //Boss
        if (firsthit || bosshealth.getSize().x <= 0)
            boss_s.setTextureRect(IntRect(bossframe_x * 320, bossframe_y * 200, 320, 200));
        else if (secondhit) {
            boss_s.setTextureRect(IntRect(bossframe_x * 250, bossframe_y * 200, 250, 200));
            bosshit_s.setTextureRect(IntRect(bossballframe_x * 52, 0, 52, 53));
        }
        else
            boss_s.setTextureRect(IntRect(bossframe_x * 200, bossframe_y * 200, 200, 200));

        //Grave IntRect
        grave_s.setTextureRect(sf::IntRect(105 * graveanimation, 0, 105, 125));
    }
}

////////////////////////////
/////// LEVEL 4 ////////////
////////////////////////////

void level_4() {
    //Character dying texts
    sf::Font font1;
    font1.loadFromFile("font.otf");
    sf::Text text3;
    text3.setFont(font1);
    text3.setString("Do you want to restart this level? (Y/N)");
    text3.setFillColor(sf::Color::Yellow);

    sf::Text text7;
    text7.setFont(font1);
    text7.setString("\t\t\t\t\t\tYou Lost!!\n\nPress 'Y' to move to the main menu");
    text7.setFillColor(sf::Color::Yellow);

    /////////////
    //Variables//
    /////////////
    float movingspeed = 2;
    float jumpspeed = 2.5;
    float gravity = 0.02;
    int ground = 565;
    sf::Vector2f velocity(sf::Vector2f(0, 0));
    //Moving counters
    int boyx = 0;
    int boyy = 0;
    //Hitting counters
    int boyhitx = 0;
    int boyhity = 0;


    //dragon counter
    int dragonx = 0;
    int dragony = 0;
    //hit
    int dragonhitx = 0;
    int dragonhity = 0;

    /////////////////////
    //Slowing animation//
    ////////////////////
    //Boy
    int slowboymovment = 0;
    int slowhit = 0;
    int slowclimb = 0;

    //Dragon
    int slowdragon = 0, slowdragon2 = 0;
    int slowhitdragon = 0;
    int dragon_x = 0, dragon_y = 0, dragon_x_hit = 0, dragon_y_hit = 0;
    int effect1 = 0, sloweffect1 = 0;
    int effect2 = 0, sloweffect2 = 0;

    /////////////
    // booleans//
    /////////////
    bool hitcharacter = false;
    bool right = false;
    bool left = true;
    bool canjump = false;
    bool canclimb = false;
    bool canmove = true;
    bool boydead = false;

    //Dragon 
    bool dragonright = false;
    bool dragonleft = false;
    bool dragonmove = true;
    bool dragonattack = false, dragonattack2 = false;
    bool dragondead = false;
    bool dragondamage = false;

    //Grave variables
    int grave_x = 0, slowing_grave = 0;

    //Show health bar
    bool showdragonhealth = false;

    //Monster Dead
    bool small_monsters_dead = false;

    //Text
    sf::Text text6;
    text6.setFont(font1);
    text6.setString("Press X to read");
    text6.setFillColor(sf::Color::Yellow);
    text6.setPosition(100, 420);

    sf::Text guide_text;
    guide_text.setString("You unlocked a new skill\n Left Shift to use it! \n\n\n Press C to close");
    guide_text.setFillColor(sf::Color::Yellow);
    guide_text.setCharacterSize(14);
    guide_text.setFont(font1);
    //Guide
    sf::Texture guidepic;
    guidepic.loadFromFile("guide.png");
    sf::Sprite guide(guidepic);
    guide.setPosition(100, 510);

    //Panel
    sf::Texture panel_pic;
    panel_pic.loadFromFile("panel.jfif");
    sf::Sprite panel(panel_pic);

    panel.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 + 100);
    guide_text.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 + 150);

    bool show_guide = false;

    //views
    sf::View view;
    view.setSize(800, 470);
    view.setCenter(400, 470);
    //////////////
    //Background//
    //////////////
    sf::Texture background;
    background.loadFromFile("back4.png");
    sf::Sprite image(background);
    //Font

    //Health text
    sf::Text healthtext;
    healthtext.setFont(font1);
    healthtext.setFillColor(sf::Color::Yellow);
    healthtext.setString("Health  ");
    healthtext.setPosition(10, 50);
    //Health bar
    myhealth.setFillColor(sf::Color::Red);
    myhealth.setPosition(150, 60);
    //health boarder 
    sf::RectangleShape healthboarder(sf::Vector2f(300, 15));
    healthboarder.setFillColor(sf::Color::Transparent);
    healthboarder.setOutlineThickness(3);
    healthboarder.setOutlineColor(sf::Color::Yellow);
    healthboarder.setPosition(150, 60);
    //XP text
    sf::Text xptext;
    xptext.setFont(font1);
    xptext.setFillColor(sf::Color::Yellow);
    xptext.setString("XP");
    xptext.setPosition(10, 10);
    //XP bar
    xpbar.setFillColor(sf::Color::Yellow);
    xpbar.setPosition(150, 20);
    //XP boarder 
    sf::RectangleShape xpboarder(sf::Vector2f(300, 20));
    xpboarder.setFillColor(sf::Color::Transparent);
    xpboarder.setOutlineThickness(3);
    xpboarder.setOutlineColor(sf::Color::Red);
    xpboarder.setPosition(150, 20);
    //////////////////
    //Main Objects////
    //////////////////

    //Grave
    sf::Texture grave_pic;
    grave_pic.loadFromFile("grave.png");
    sf::Sprite grave(grave_pic);
    grave.setPosition(0, -300);



    // Character
    sf::Texture character;
    character.loadFromFile("move.png");
    sf::Sprite boy(character);
    boy.setPosition(0, ground);
    //hit 
    sf::Texture hit;
    hit.loadFromFile("hit.png");
    sf::Sprite ko(hit);

    sf::Texture character3;
    character3.loadFromFile("character 3.png");
    sf::Sprite character_s3(character3);
    bool characterhitting2 = false;
    int characterhitframe2 = 0, characterhitframe2_h = 1, slowingcharacterhit = 0;
    //Wolves 
    sf::Texture mon[6];
    sf::Texture monhit[6];
    sf::Sprite monster[6];
    sf::Sprite monsterhit[6];
    for (int i = 0; i < 3; i++) {
        mon[i].loadFromFile("wolve.png");
        monhit[i].loadFromFile("wolf2.png");
    }
    for (int i = 3; i < 6; i++) {
        mon[i].loadFromFile("dino.png");
        monhit[i].loadFromFile("dino2.png");
    }
    for (int i = 0; i < 6; i++) {
        monster[i].setTexture(mon[i]);
        monsterhit[i].setTexture(monhit[i]);
    }
    monster[0].setPosition(1260, 396);
    monster[1].setPosition(200, 585);
    monster[2].setPosition(990, 310);
    monster[3].setPosition(750, 545);
    monster[4].setPosition(380, 120);
    monster[5].setPosition(1300, 100);


    //Wolf effect
    sf::Texture wolfeffect_pic;
    wolfeffect_pic.loadFromFile("wolve hit.png");
    sf::Sprite wolfeffect(wolfeffect_pic);

    int slowing_wolfeffect = 0, wolfeffect_x = 0;

    //Dinosaur effect
    sf::Texture dinoeffect_pic;
    dinoeffect_pic.loadFromFile("dinasour hit.png");
    sf::Sprite dinoeffect(dinoeffect_pic);

    int slowing_dinoeffect = 0, dinoeffect_x = 0;
    dinoeffect.setScale(2, 1);

    sf::RectangleShape monsterhealth[6];
    sf::RectangleShape monsterhealthborder[6];
    for (int i = 0; i < 6; i++) {
        //Health bar
        monsterhealth[i].setSize(sf::Vector2f(100, 10));
        monsterhealth[i].setFillColor(sf::Color::Red);
        //health boarder 
        monsterhealthborder[i].setSize(sf::Vector2f(100, 10));
        monsterhealthborder[i].setFillColor(sf::Color::Transparent);
        monsterhealthborder[i].setOutlineThickness(3.5);
        monsterhealthborder[i].setOutlineColor(sf::Color::Yellow);
    }

    //Dragon
    sf::Texture mon7;
    mon7.loadFromFile("dragon_1.png");
    sf::Sprite dragon(mon7);
    dragon.setPosition(200, -300);
    //hit
    sf::Texture monhit7;
    monhit7.loadFromFile("dragon2.png");
    sf::Sprite dragonhit(monhit7);


    int dragonhit2_x = 0, dragonhit2_y = 0;
    int slowing_effect2 = 0, effect2_x = 0;
    int slowingdragon2 = 0;
    int slowingdragon3 = 0;
    int slowdragondeath = 0;

    //EFFFECTS
    sf::Texture dragon_effect1pic;
    dragon_effect1pic.loadFromFile("dragon effect_1.png");
    sf::Sprite dragon_effect1(dragon_effect1pic);

    sf::Texture dragon_effect2pic;
    dragon_effect2pic.loadFromFile("dragon effect_2.png");
    sf::Sprite dragon_effect2(dragon_effect2pic);



    //Health bar
    sf::RectangleShape dragonhealth(sf::Vector2f(100, 10));
    dragonhealth.setFillColor(sf::Color::Red);
    //health boarder 
    sf::RectangleShape dragonhealthboarder(sf::Vector2f(100, 10));
    dragonhealthboarder.setFillColor(sf::Color::Transparent);
    dragonhealthboarder.setOutlineThickness(3.5);
    dragonhealthboarder.setOutlineColor(sf::Color::Yellow);





    sf::Music backgroundmusic;
    backgroundmusic.openFromFile("level 4 BG music.wav");
    backgroundmusic.play();

    sf::SoundBuffer jumpsound;
    jumpsound.loadFromFile("jump.wav");
    sf::Sound jumpingsound(jumpsound);

    sf::SoundBuffer levelup_sound;
    levelup_sound.loadFromFile("level up.wav");
    sf::Sound levelupsound(levelup_sound);
    int onlylevelupsoundonce = 0;

    sf::SoundBuffer dragondying_sound;
    dragondying_sound.loadFromFile("dragon dying.wav");
    sf::Sound dragondyingsound(dragondying_sound);

    sf::SoundBuffer dragonhit1_sound;
    dragonhit1_sound.loadFromFile("dragon hit 1.wav");
    sf::Sound dragonhit1sound(dragonhit1_sound);

    sf::SoundBuffer dragonhit2_sound;
    dragonhit2_sound.loadFromFile("dragon hit 2.wav");
    sf::Sound dragonhit2sound(dragonhit2_sound);

    //music for hit
    sf::SoundBuffer hitting;
    hitting.loadFromFile("hit.wav");
    sf::Sound hittingsound(hitting);

    sf::SoundBuffer dinosaurbeinghit_sound;
    dinosaurbeinghit_sound.loadFromFile("dinasour being hit.wav");
    sf::Sound dinosaur_being_hit(dinosaurbeinghit_sound);

    sf::SoundBuffer wolfbeinghit_sound;
    wolfbeinghit_sound.loadFromFile("big monster hit.wav");
    sf::Sound wolf_being_hit(wolfbeinghit_sound);

    sf::SoundBuffer dinosaurhit_sound;
    dinosaurhit_sound.loadFromFile("dinasour hit.wav");
    sf::Sound dinosaurhitsound(dinosaurhit_sound);

    sf::SoundBuffer wolfhit_sound;
    wolfhit_sound.loadFromFile("small ghost attack.wav");
    sf::Sound wolfhitsound(wolfhit_sound);

    sf::SoundBuffer dinosaurdying_sound;
    dinosaurdying_sound.loadFromFile("dinasour dying.wav");
    sf::Sound dinosaurdyingsound(dinosaurdying_sound);





    sf::RectangleShape line1(sf::Vector2f(180, 5));
    line1.setPosition(150, 255);
    sf::RectangleShape line2(sf::Vector2f(180, 5));
    line2.setPosition(190, 200);
    sf::RectangleShape line3(sf::Vector2f(180, 5));
    line3.setPosition(200, 60);
    sf::RectangleShape line4(sf::Vector2f(280, 5));
    line4.setPosition(415, 140);
    sf::RectangleShape line5(sf::Vector2f(280, 5));
    line5.setPosition(700, 305);
    sf::RectangleShape line6(sf::Vector2f(180, 5));
    line6.setPosition(360, 380);
    sf::RectangleShape line7(sf::Vector2f(180, 5));
    line7.setPosition(1080, 400);
    sf::RectangleShape line8(sf::Vector2f(180, 5));
    line8.setPosition(1110, 125);
    sf::RectangleShape line9(sf::Vector2f(180, 5));
    line9.setPosition(1210, 500);
    sf::RectangleShape line10(sf::Vector2f(180, 5));
    line10.setPosition(1210, 305);

    sf::Texture port;
    port.loadFromFile("portal.png");
    sf::Sprite portal(port);
    portal.setPosition(990, 400);
    //levelup
    sf::Texture level;
    level.loadFromFile("levelup.png");
    sf::Sprite levelup(level);


    //Portal variables 
    int portalx = 0;
    int slowportal = 0;
    //levelup
    int levelupx = 0;
    int slowlevelup = 0;

    //Heart
    sf::Texture heart_pic;
    heart_pic.loadFromFile("heart.png");
    sf::Sprite heart[5];
    for (int i = 0; i < 5; i++) {
        heart[i].setTexture(heart_pic);
    }

    /////////////
    //Game Loop//
    /////////////
    while (window.isOpen()) {
        //Collision boxes
        sf::FloatRect boybound = boy.getGlobalBounds();
        sf::FloatRect boyhitbound = ko.getGlobalBounds();
        sf::FloatRect bound3 = character_s3.getGlobalBounds();
        sf::FloatRect monsterbounds[6];
        sf::FloatRect dinoeffectbound = dinoeffect.getGlobalBounds();
        sf::FloatRect wolfeffectbound = wolfeffect.getGlobalBounds();
        for (int i = 0; i < 6; i++) {
            monsterbounds[i] = monster[i].getGlobalBounds();
        }
        sf::FloatRect dragonbound = dragon.getGlobalBounds();
        sf::FloatRect dragonattackbound = dragonhit.getGlobalBounds();
        sf::FloatRect dragoneffectbound = dragon_effect1.getGlobalBounds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (myhealth.getSize().x > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && ((velocity.y >= -0.5 && velocity.y <= 0) || (velocity.y >= 0 && velocity.y <= 0.5))) {
                jumpingsound.play();
            }
            if (dragonhealth.getSize().x <= 0 && onlylevelupsoundonce <= 200) {
                levelupsound.play();
                dragondyingsound.play();
            }


            if (dragonattack && dragonhealth.getSize().x >= 0 && dragonx == 3) {
                dragonhit1sound.play();
            }
            else if (dragonattack2 && dragonhealth.getSize().x >= 0 && dragon_x_hit == 4) {
                dragonhit2sound.play();
            }


            for (int i = 0; i < 6; i++) {
                if (i < 3) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                        if (boyhitbound.intersects(monsterbounds[i]) && boyhitx == 1 && !monsters_level4[i].monsterdead)
                            wolf_being_hit.play();
                        else if (boyhitx == 1)
                            hittingsound.play();
                    }
                }
                else {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                        if (boyhitbound.intersects(monsterbounds[i]) && boyhitx == 1 && !monsters_level4[i].monsterdead)
                            dinosaur_being_hit.play();
                        else if (boyhitx == 1)
                            hittingsound.play();
                    }
                }
            }

            for (int i = 0; i < 6; i++) {
                if (i < 3) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                        if (bound3.intersects(monsterbounds[i]) && characterhitframe2 == 1 && !monsters_level4[i].monsterdead)
                            wolf_being_hit.play();
                        else if (characterhitframe2 == 1)
                            hittingsound.play();
                    }
                }
                else {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                        if (bound3.intersects(monsterbounds[i]) && characterhitframe2 == 1 && !monsters_level4[i].monsterdead)
                            dinosaur_being_hit.play();
                        else if (characterhitframe2 == 1)
                            hittingsound.play();
                    }
                }
            }

            for (int i = 0; i < 6; i++) {
                if (myhealth.getSize().x >= 0) {
                    if (i < 3) {
                        if (monsters_level4[i].monster_attack && !monsters_level4[i].monsterdead && monsters_level4[i].monsterframe_2 == 3)
                            wolfhitsound.play();
                    }
                    else {
                        if (monsters_level4[i].monster_attack && !monsters_level4[i].monsterdead && monsters_level4[i].monsterframe_2 == 4)
                            dinosaurhitsound.play();
                    }
                }
            }

            for (int i = 3; i < 6; i++) {
                if (monsters_level4[i].monsterdead && monsters_level4[i].monsterframe <= 2) {
                    dinosaurdyingsound.play();
                }
            }

        }
        //views
        window.setView(view);
        if (view.getCenter().x - boy.getPosition().x <= 50 && view.getCenter().x <= 1200) {
            view.move(0.3, 0);
        }
        if (view.getCenter().x - boy.getPosition().x >= 100 && view.getCenter().x > 400) {
            view.move(-0.3, 0);
        }

        if (boy.getPosition().y <= 350 && view.getCenter().y >= 220) {
            view.move(0, -0.5);
        }
        else if (boy.getPosition().y > 345 && view.getCenter().y < 500) {
            view.move(0, 0.5);
        }

        heart[4].setPosition(view.getCenter().x - 210, view.getCenter().y - 220);
        heart[3].setPosition(view.getCenter().x - 270, view.getCenter().y - 220);
        heart[2].setPosition(view.getCenter().x - 330, view.getCenter().y - 220);
        heart[1].setPosition(view.getCenter().x - 390, view.getCenter().y - 220);
        heart[0].setPosition(view.getCenter().x - 450, view.getCenter().y - 220);

        xptext.setPosition(view.getCenter().x - 390, view.getCenter().y - 230);
        xpboarder.setPosition(view.getCenter().x - 240, view.getCenter().y - 220);
        xpbar.setPosition(view.getCenter().x - 240, view.getCenter().y - 220);
        healthtext.setPosition(view.getCenter().x - 390, view.getCenter().y - 190);
        healthboarder.setPosition(view.getCenter().x - 240, view.getCenter().y - 182);
        myhealth.setPosition(view.getCenter().x - 240, view.getCenter().y - 182);
        // positions
        character_s3.setPosition(boy.getPosition().x - 70, boy.getPosition().y - 50);
        ko.setPosition(boy.getPosition().x - 65, boy.getPosition().y - 70);
        monsterhealth[0].setPosition(monster[0].getPosition().x, monster[0].getPosition().y - 25);
        monsterhealthborder[0].setPosition(monster[0].getPosition().x, monster[0].getPosition().y - 25);
        monsterhealth[1].setPosition(monster[1].getPosition().x, monster[1].getPosition().y - 25);
        monsterhealthborder[1].setPosition(monster[1].getPosition().x, monster[1].getPosition().y - 25);
        monsterhealth[2].setPosition(monster[2].getPosition().x, monster[2].getPosition().y - 25);
        monsterhealthborder[2].setPosition(monster[2].getPosition().x, monster[2].getPosition().y - 25);
        monsterhealth[3].setPosition(monster[3].getPosition().x, monster[3].getPosition().y - 22);
        monsterhealthborder[3].setPosition(monster[3].getPosition().x, monster[3].getPosition().y - 22);
        monsterhealth[4].setPosition(monster[4].getPosition().x, monster[4].getPosition().y - 22);
        monsterhealthborder[4].setPosition(monster[4].getPosition().x, monster[4].getPosition().y - 22);
        monsterhealth[5].setPosition(monster[5].getPosition().x, monster[5].getPosition().y - 22);
        monsterhealthborder[5].setPosition(monster[5].getPosition().x, monster[5].getPosition().y - 22);

        sf::FloatRect line1_bound = line1.getGlobalBounds();
        sf::FloatRect line2_bound = line2.getGlobalBounds();
        sf::FloatRect line3_bound = line3.getGlobalBounds();
        sf::FloatRect line4_bound = line4.getGlobalBounds();
        sf::FloatRect line5_bound = line5.getGlobalBounds();
        sf::FloatRect line6_bound = line6.getGlobalBounds();
        sf::FloatRect line7_bound = line7.getGlobalBounds();
        sf::FloatRect line8_bound = line8.getGlobalBounds();
        sf::FloatRect line9_bound = line9.getGlobalBounds();
        sf::FloatRect line10_bound = line10.getGlobalBounds();



        //charcter 
        hitcharacter = false;
        characterhitting2 = false;
        if (myhealth.getSize().x > 0) {
            //Charcter moving
            if (!canclimb == true) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    boy.move(-0.3, 0);
                    left = true;
                    right = false;
                    boyy = 0;
                    slowboymovment++;
                    if (slowboymovment % 50 == 0) {
                        boyx++;
                        boyx %= 4;
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    boy.move(0.3, 0);
                    left = false;
                    right = true;
                    boyy = 1;
                    slowboymovment++;
                    if (slowboymovment % 50 == 0) {
                        boyx++;
                        boyx %= 4;
                    }
                }

                //Character hit
                for (int i = 0; i < 6; i++)
                    monsters_level4[i].monsterdamage = false;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    slowhit++;
                    if (slowhit % 50 == 0) {
                        boyhitx++;
                        if (boyhitx == 4) {
                            boyhitx = 0;
                        }
                    }
                    hitcharacter = true;
                    if (right) {
                        boyhity = 1;
                    }
                    if (left) {
                        boyhity = 0;
                    }

                    for (int i = 0; i < 6; i++) {
                        if (boyhitbound.intersects(monsterbounds[i]) && boyhitx == 2) {
                            monsters_level4[i].monsterdamage = true;
                            monsters_level4[i].monster_border = true;
                            if (monsterhealth[i].getSize().x > 0)
                                monsterhealth[i].setSize(sf::Vector2f(monsterhealth[i].getSize().x - 0.1, 10));
                            if (monster[i].getPosition().x > boy.getPosition().x) {
                                monster[i].move(0.4, 0);
                            }
                            if (monster[i].getPosition().x < boy.getPosition().x) {
                                monster[i].move(-0.4, 0);
                            }
                        }
                    }
                    if (boyhitbound.intersects(dragonbound) && boyhitx == 2) {
                        showdragonhealth = true;
                        if (dragonhealth.getSize().x >= 0) {
                            dragonhealth.setSize(sf::Vector2f(dragonhealth.getSize().x - 0.1, 10));
                        }
                        if (dragonright) {
                            dragon.move(-0.4, 0);
                        }
                        if (dragonleft) {
                            dragon.move(0.4, 0);
                        }
                    }
                }
                //Second Hit

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                    slowingcharacterhit++;
                    characterhitting2 = true;
                    if (boyy == 0 || boyy == 1)
                        characterhitframe2_h = boyy;
                    else if (boyy == 3 || boyy == 4)
                        characterhitframe2_h = boyy - 3;
                    if (slowingcharacterhit == 70) {
                        characterhitframe2++;
                        characterhitframe2 %= 4;
                        slowingcharacterhit = 0;
                    }
                    for (int i = 0; i < 6; i++) {
                        if (bound3.intersects(monsterbounds[i]) && characterhitframe2 == 2) {
                            monsters_level4[i].monsterdamage = true;
                            monsters_level4[i].monster_border = true;
                            if (monsterhealth[i].getSize().x > 0)
                                monsterhealth[i].setSize(sf::Vector2f(monsterhealth[i].getSize().x - 0.1, 10));
                            if (monster[i].getPosition().x > boy.getPosition().x) {
                                monster[i].move(0.4, 0);
                            }
                            if (monster[i].getPosition().x < boy.getPosition().x) {
                                monster[i].move(-0.4, 0);
                            }
                        }
                    }
                    if (bound3.intersects(dragonbound) && characterhitframe2 == 2) {
                        showdragonhealth = true;
                        if (dragonhealth.getSize().x >= 0) {
                            dragonhealth.setSize(sf::Vector2f(dragonhealth.getSize().x - 0.1, 10));
                        }
                        if (dragonright) {
                            dragon.move(-0.4, 0);
                        }
                        if (dragonleft) {
                            dragon.move(0.4, 0);
                        }
                    }
                }
                //Third Hit

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                    slowingcharacterhit++;
                    characterhitting2 = true;
                    if (boyy == 0 || boyy == 1)
                        characterhitframe2_h = boyy + 2;
                    else if (boyy == 3 || boyy == 4)
                        characterhitframe2_h = boyy - 1;
                    if (slowingcharacterhit == 70) {
                        characterhitframe2++;
                        characterhitframe2 %= 4;
                        slowingcharacterhit = 0;
                    }
                    for (int i = 0; i < 6; i++) {
                        if (bound3.intersects(monsterbounds[i]) && (characterhitframe2 == 1 || characterhitframe2 == 3)) {
                            monsters_level4[i].monsterdamage = true;
                            monsters_level4[i].monster_border = true;
                            if (monsterhealth[i].getSize().x > 0)
                                monsterhealth[i].setSize(sf::Vector2f(monsterhealth[i].getSize().x - 0.1, 10));
                            if (monster[i].getPosition().x > boy.getPosition().x) {
                                monster[i].move(0.4, 0);
                            }
                            if (monster[i].getPosition().x < boy.getPosition().x) {
                                monster[i].move(-0.4, 0);
                            }
                        }
                    }
                    if (bound3.intersects(dragonbound) && (characterhitframe2 == 1 || characterhitframe2 == 3)) {
                        showdragonhealth = true;
                        if (dragonhealth.getSize().x >= 0) {
                            dragonhealth.setSize(sf::Vector2f(dragonhealth.getSize().x - 0.1, 10));
                        }
                        if (dragonright) {
                            dragon.move(-0.4, 0);
                        }
                        if (dragonleft) {
                            dragon.move(0.4, 0);
                        }
                    }
                }
                //Character jump
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && canjump) {
                    velocity.y = -jumpspeed;
                    canjump = false;
                }
                if (boy.getPosition().y < ground || velocity.y < 0) {
                    velocity.y += gravity;
                }
                else {
                    velocity.y = 0;
                    canjump = true;
                }

                boy.move(velocity.x, velocity.y);
            }

            //Charcter climb
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (((boy.getPosition().x >= 120 && boy.getPosition().x <= 130) && (boy.getPosition().y >= 260 && boy.getPosition().y <= 520)) || ((boy.getPosition().x >= 785 && boy.getPosition().x <= 786) && (boy.getPosition().y <= 490 && boy.getPosition().y > 300)) || ((boy.getPosition().x > 471 && boy.getPosition().x < 477) && (boy.getPosition().y <= 364 && boy.getPosition().y >= 140)) || ((boy.getPosition().x >= 1187 && boy.getPosition().x <= 1192) && boy.getPosition().y <= 387 && boy.getPosition().y >= 122))) {
                canclimb = true;
                boyy = 2;
                slowclimb++;
                if (slowclimb % 50 == 0) {
                    boyx++;
                    boyx %= 2;
                }
                boy.move(0, -0.7);
            }

            if (boybound.intersects(line1_bound)) {
                ground = 255;
                canclimb = false;

            }
            if (ground == 255) {
                if (boy.getPosition().x <= 35.7) {
                    ground = 565;
                }
                if (boy.getPosition().x >= 328.3) {
                    ground = 363;

                }
            }
            if (boybound.intersects(line6_bound)) {
                ground = 363;
            }
            if (ground == 363) {
                if (boy.getPosition().x < 322.7 || boy.getPosition().x >= 505) {
                    ground = 565;
                }
            }

            if (boybound.intersects(line2_bound)) {
                ground = 175;
            }

            if (ground == 175) {
                if (boy.getPosition().x >= 348) {
                    ground = 363;
                }
                if (boy.getPosition().x <= 155.4) {
                    ground = 255;
                }
            }

            if (boybound.intersects(line3_bound)) {

                ground = 85;
            }
            if (ground == 85) {
                if (boy.getPosition().x <= 112) {
                    ground = 255;
                }
                if (boy.getPosition().x >= 313) {
                    ground = 175;
                }
            }

            if (boybound.intersects(line4_bound)) {
                canclimb = false;
                ground = 137;
            }


            if (ground == 137) {
                if (boy.getPosition().x <= 370) {
                    ground = 565;
                }
                if (boy.getPosition().x >= 694) {
                    ground = 565;
                }
            }

            if (boybound.intersects(line5_bound)) {
                canclimb = false;
                ground = 285;
            }

            if (ground == 285) {
                if (boy.getPosition().x <= 723) {
                    ground = 565;
                }
                if (boy.getPosition().x >= 1018) {
                    ground = 565;
                }
            }

            if (boybound.intersects(line7_bound)) {
                ground = 376;
            }
            if (ground == 376) {
                if (boy.getPosition().x <= 1050) {
                    ground = 565;
                }
                if (boy.getPosition().x >= 1350)
                    ground = 454;
            }

            if (boybound.intersects(line8_bound)) {
                canclimb = false;
                ground = 120;
            }
            if (ground == 120) {
                if (boy.getPosition().x <= 1098 || boy.getPosition().x >= 1396) {
                    ground = 565;
                }
            }

            if (boybound.intersects(line9_bound)) {
                ground = 454;
            }
            if (ground == 454) {
                if (boy.getPosition().x <= 1198 || boy.getPosition().x >= 1374) {
                    ground = 565;
                }

            }

            if (boybound.intersects(line10_bound)) {
                ground = 298;
            }
            if (ground == 298) {
                if (boy.getPosition().x <= 1214) {
                    ground = 376;
                }
                if (boy.getPosition().x >= 1396) {
                    ground = 565;
                }
            }
        }

        //FIRST monster MOVING
        if (monster[0].getPosition().x <= 1035) {
            monsters_level4[0].monstermoveleft = false;
            monsters_level4[0].monstermoveright = true;
        }
        if (monster[0].getPosition().x >= 1260) {
            monsters_level4[0].monstermoveright = false;
            monsters_level4[0].monstermoveleft = true;
        }


        //SECOND monster MOVING
        if (monster[1].getPosition().x <= 200) {
            monsters_level4[1].monstermoveleft = false;
            monsters_level4[1].monstermoveright = true;
        }
        if (monster[1].getPosition().x >= 550) {
            monsters_level4[1].monstermoveright = false;
            monsters_level4[1].monstermoveleft = true;
        }


        //THIRD monster MOVING
        if (monster[2].getPosition().x <= 734) {
            monsters_level4[2].monstermoveleft = false;
            monsters_level4[2].monstermoveright = true;
        }
        if (monster[2].getPosition().x >= 990) {
            monsters_level4[2].monstermoveright = false;
            monsters_level4[2].monstermoveleft = true;
        }

        //WOLVES MOVEMENT
        for (int i = 0; i < 3; i++) {
            if (!monsters_level4[i].monsterdead) {
                if (abs(monster[i].getPosition().x + 60 - boy.getPosition().x) <= 100 && abs(monster[i].getPosition().y - boy.getPosition().y) <= 100) {
                    monster[i].move(0, 0);
                    if (monsters_level4[i].monstermoveright) {
                        monsters_level4[i].monsterframe_h = 2;
                        monsters_level4[i].slowingmonstermove++;
                        if (monsters_level4[i].slowingmonstermove == 50) {
                            monsters_level4[i].monsterframe++;
                            monsters_level4[i].monsterframe %= 4;
                            monsters_level4[i].slowingmonstermove = 0;
                        }
                    }
                    else if (monsters_level4[i].monstermoveleft) {
                        monsters_level4[i].monsterframe_h = 0;
                        monsters_level4[i].slowingmonstermove++;
                        if (monsters_level4[i].slowingmonstermove == 50) {
                            monsters_level4[i].monsterframe++;
                            monsters_level4[i].monsterframe %= 4;
                            monsters_level4[i].slowingmonstermove = 0;
                        }
                    }
                }
                else if (monsters_level4[i].monstermoveright) {
                    monsters_level4[i].monsterframe_h = 2;
                    monsters_level4[i].slowingmonstermove++;
                    if (monsters_level4[i].slowingmonstermove == 50) {
                        monsters_level4[i].monsterframe++;
                        monsters_level4[i].monsterframe %= 4;
                        monsters_level4[i].slowingmonstermove = 0;
                    }
                    monster[i].move(0.15, 0);
                }

                else if (monsters_level4[i].monstermoveleft) {
                    monsters_level4[i].monsterframe_h = 0;
                    monsters_level4[i].slowingmonstermove++;
                    if (monsters_level4[i].slowingmonstermove == 50) {
                        monsters_level4[i].monsterframe++;
                        monsters_level4[i].monsterframe %= 4;
                        monsters_level4[i].slowingmonstermove = 0;
                    }
                    monster[i].move(-0.15, 0);
                }
            }

        }


        if (monster[3].getPosition().x <= 750) {
            monsters_level4[3].monstermoveleft = false;
            monsters_level4[3].monstermoveright = true;
        }
        if (monster[3].getPosition().x >= 1150) {
            monsters_level4[3].monstermoveright = false;
            monsters_level4[3].monstermoveleft = true;
        }

        if (monster[4].getPosition().x <= 380) {
            monsters_level4[4].monstermoveleft = false;
            monsters_level4[4].monstermoveright = true;
        }
        if (monster[4].getPosition().x >= 630) {
            monsters_level4[4].monstermoveright = false;
            monsters_level4[4].monstermoveleft = true;
        }

        if (monster[5].getPosition().x <= 1100) {
            monsters_level4[5].monstermoveleft = false;
            monsters_level4[5].monstermoveright = true;
        }
        if (monster[5].getPosition().x >= 1300) {
            monsters_level4[5].monstermoveright = false;
            monsters_level4[5].monstermoveleft = true;
        }

        for (int i = 3; i < 6; i++) {

            if (!monsters_level4[i].monsterdead) {
                if (abs(monster[i].getPosition().x + 70 - boy.getPosition().x) <= 100 && abs(monster[i].getPosition().y - boy.getPosition().y) <= 100) {
                    monster[i].move(0, 0);
                    if (monsters_level4[i].monstermoveright) {
                        monsters_level4[i].monsterframe_h = 2;
                        monsters_level4[i].slowingmonstermove++;
                        if (monsters_level4[i].slowingmonstermove == 50) {
                            monsters_level4[i].monsterframe++;
                            monsters_level4[i].monsterframe %= 4;
                            monsters_level4[i].slowingmonstermove = 0;
                        }
                    }
                    else if (monsters_level4[i].monstermoveleft) {
                        monsters_level4[i].monsterframe_h = 0;
                        monsters_level4[i].slowingmonstermove++;
                        if (monsters_level4[i].slowingmonstermove == 50)
                        {
                            monsters_level4[i].monsterframe++;
                            monsters_level4[i].monsterframe %= 4;
                            monsters_level4[i].slowingmonstermove = 0;
                        }
                    }
                }
                else if (monsters_level4[i].monstermoveright) {
                    monsters_level4[i].monsterframe_h = 2;
                    monsters_level4[i].slowingmonstermove++;
                    if (monsters_level4[i].slowingmonstermove == 50) {
                        monsters_level4[i].monsterframe++;
                        monsters_level4[i].monsterframe %= 4;
                        monsters_level4[i].slowingmonstermove = 0;
                    }
                    monster[i].move(0.15, 0);
                }
                else if (monsters_level4[i].monstermoveleft) {
                    monsters_level4[i].monsterframe_h = 0;
                    monsters_level4[i].slowingmonstermove++;
                    if (monsters_level4[i].slowingmonstermove == 50)
                    {
                        monsters_level4[i].monsterframe++;
                        monsters_level4[i].monsterframe %= 4;
                        monsters_level4[i].slowingmonstermove = 0;
                    }
                    monster[i].move(-0.15, 0);
                }
            }
        }



        //Monster attacks
        for (int i = 0; i < 6; i++) {
            if (myhealth.getSize().x > 0) {
                if (i < 3) {
                    if (abs(monster[i].getPosition().x + 60 - boy.getPosition().x) <= 160 && abs(monster[i].getPosition().y - boy.getPosition().y) <= 150 && !monsters_level4[i].monsterdead) {
                        monsters_level4[i].monster_attack = true;
                    }
                    else if (abs(monster[i].getPosition().x + 60 - boy.getPosition().x) >= 160 || abs(monster[i].getPosition().y - boy.getPosition().y) >= 150 || monsters_level4[i].monsterdead) {
                        monsters_level4[i].monster_attack = false;
                    }
                }
                else if (i >= 3) {
                    if (abs(monster[i].getPosition().x + 70 - boy.getPosition().x) <= 160 && abs(monster[i].getPosition().y - boy.getPosition().y) <= 150 && !monsters_level4[i].monsterdead) {
                        monsters_level4[i].monster_attack = true;
                    }
                    else if (abs(monster[i].getPosition().x + 70 - boy.getPosition().x) >= 160 || abs(monster[i].getPosition().y - boy.getPosition().y) >= 150 || monsters_level4[i].monsterdead) {
                        monsters_level4[i].monster_attack = false;
                    }
                }
                if (monsters_level4[i].monster_attack) {
                    if (monsters_level4[i].monstermoveright) {
                        monsters_level4[i].monsterframe2_h = 1;
                    }
                    if (monsters_level4[i].monstermoveleft) {
                        monsters_level4[i].monsterframe2_h = 0;
                    }
                    monsters_level4[i].slowingmonster2_move++;
                    if (monsters_level4[i].slowingmonster2_move == 50) {
                        monsters_level4[i].monsterframe_2++;
                        monsters_level4[i].monsterframe_2 %= 8;
                        monsters_level4[i].slowingmonster2_move = 0;
                    }
                }
            }
            else  if (myhealth.getSize().x <= 0)
                monsters_level4[i].monster_attack = false;
        }
        // DRAGON
        if (small_monsters_dead) {
            if (!dragondead) {
                if (dragon.getPosition().y <= 470) {
                    dragon.move(0, 0.2);
                }
                if (abs(dragon.getPosition().x + 100 - boy.getPosition().x) <= 120) {
                    dragon.move(0, 0);
                    if (dragonright) {
                        dragony = 2;
                        slowdragon++;
                        if (slowdragon == 50) {
                            dragonx++;
                            dragonx %= 5;
                            slowdragon = 0;
                        }
                    }
                    else if (dragonleft) {
                        dragony = 0;
                        slowdragon++;
                        if (slowdragon == 50) {
                            dragonx++;
                            dragonx %= 5;
                            slowdragon = 0;

                        }
                    }
                }
                else if (dragon.getPosition().x + 100 > boy.getPosition().x) {
                    dragonleft = true;
                    dragonright = false;
                    dragony = 0;
                    slowdragon++;
                    if (slowdragon == 50) {
                        dragonx++;
                        dragonx %= 5;
                        slowdragon = 0;
                    }
                    dragon.move(-0.1, 0);
                }
                else if (dragon.getPosition().x + 100 < boy.getPosition().x) {
                    dragonright = true;
                    dragonleft = false;
                    dragony = 2;
                    slowdragon++;
                    if (slowdragon == 50) {
                        dragonx++;
                        dragonx %= 5;
                        slowdragon = 0;
                    }
                    dragon.move(0.1, 0);
                }


                //ATTACKS

                if (dragon.getPosition().y >= 470) {

                    if (abs(dragon.getPosition().x + 100 - boy.getPosition().x) <= 200 && abs(dragon.getPosition().y - boy.getPosition().y) <= 150 && !dragondead) {
                        dragonattack2 = true;
                    }
                    else if (abs(dragon.getPosition().x + 100 - boy.getPosition().x) >= 200 || abs(dragon.getPosition().y - boy.getPosition().y) >= 150 || dragondead) {
                        dragonattack2 = false;
                    }
                    if (abs(dragon.getPosition().x + 100 - boy.getPosition().x) >= 200 && abs(dragon.getPosition().x + 100 - boy.getPosition().x) <= 300 && abs(dragon.getPosition().y - boy.getPosition().y) <= 150 && !dragondead && !dragonattack2) {
                        dragonattack = true;
                    }
                    else if (abs(dragon.getPosition().x + 100 - boy.getPosition().x) >= 350 || abs(dragon.getPosition().y - boy.getPosition().y) <= 200 || dragondead || dragonattack2) {
                        dragonattack = false;
                    }

                    if (dragonattack) {
                        if (dragonright) {
                            dragony = 7;
                        }
                        if (dragonleft) {
                            dragony = 6;
                        }
                        slowdragon2++;
                        if (slowdragon == 50) {
                            dragonx++;
                            dragonx %= 6;
                            slowdragon = 0;
                        }
                    }
                    if (dragonattack2) {
                        if (dragonright) {
                            dragon_y_hit = 1;
                        }
                        if (dragonleft) {
                            dragon_y_hit = 0;
                        }
                        slowingdragon3++;
                        if (slowingdragon3 == 50) {
                            dragon_x_hit++;
                            dragon_x_hit %= 10;
                            slowingdragon3 = 0;
                        }
                    }
                }
            }

            if (dragonhealth.getSize().x <= 0) {
                dragondead = true;
                dragonattack = false;
                dragonattack2 = false;

                if (dragonleft) {
                    dragony = 4;
                }
                if (dragonright) {
                    dragony = 5;
                }
                slowdragondeath++;
                if (slowdragondeath == 50) {
                    dragonx++;
                    slowdragondeath = 0;
                }
                xpbar.setSize(Vector2f(300, 20));
            }
        }

        //Monsters death
        for (int i = 0; i < 6; i++) {
            if (monsterhealth[i].getSize().x <= 0) {
                monsters_level4[i].monsterdead = true;
            }
        }

        //Monster death 
        for (int i = 0; i < 6; i++) {
            if (monsters_level4[i].monsterdead) {
                if (monsters_level4[i].monstermoveleft) {
                    monsters_level4[i].monsterframe_h = 4;
                }
                if (monsters_level4[i].monstermoveright) {
                    monsters_level4[i].monsterframe_h = 5;
                }
                monsters_level4[i].slowingmonstermove++;
                if (monsters_level4[i].slowingmonstermove == 50) {
                    monsters_level4[i].monsterframe++;
                    monsters_level4[i].slowingmonstermove = 0;
                }
            }
        }


        //Player death
        if (myhealth.getSize().x <= 0) {
            boydead = true;
            dragonattack = false;
            dragonattack2 = false;
            grave.setPosition(boy.getPosition().x, grave.getPosition().y);
            if (grave.getPosition().y < ground - 20) {
                grave.move(0, 2.5);
            }
            slowing_grave++;
            if (grave_x == 5)
                grave_x = 5;
            else if (slowing_grave == 50) {
                grave_x++;
                grave_x %= 6;
                slowing_grave = 0;
            }
        }
        for (int i = 0; i < 6; i++) {
            if (monsters_level4[i].monster_attack) {
                if (boy.getPosition().x > monster[i].getPosition().x) {
                    monsters_level4[i].monstermoveright = true;
                    monsters_level4[i].monstermoveleft = false;
                }
                if (boy.getPosition().x < monster[i].getPosition().x) {
                    monsters_level4[i].monstermoveleft = true;
                    monsters_level4[i].monstermoveright = false;
                }
            }
        }



        //////////////
        //COLLISIONS//
        //////////////

        if (!boydead) {
            for (int i = 0; i < 6; i++) {
                if (monsterbounds[i].intersects(boybound) && !monsters_level4[i].monsterdead) {
                     myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.05, 15));
                }
            }
        }
        if (monsters_level4[0].monsterdead && monsters_level4[1].monsterdead && monsters_level4[2].monsterdead && monsters_level4[3].monsterdead && monsters_level4[4].monsterdead && monsters_level4[5].monsterdead) {
            small_monsters_dead = true;
        }


        //xpbar
        for (int i = 0; i < 6; i++) {
            if ((monsters_level4[i].monsterframe <= 4) && (monsters_level4[i].monsterdead)) {
                xpbar.setSize(sf::Vector2f(xpbar.getSize().x + 0.1, 20));
            }
            if (i > 3) {
                if ((monsters_level4[i].monsterframe <= 3) && (monsters_level4[i].monsterdead)) {
                    xpbar.setSize(sf::Vector2f(xpbar.getSize().x + 0.1, 20));
                }
            }
        }


        //WINDOW
        window.clear();
        window.draw(image);

        //levelup
        if (dragondead) {
            //levelup
            onlylevelupsoundonce++;
            slowlevelup++;
            if (slowlevelup % 60 == 0) {
                levelupx++;
            }
            levelup.setTextureRect(sf::IntRect(levelupx * 679, 0, 679, 400));
            levelup.setPosition(boy.getPosition().x - 300, boy.getPosition().y - 280);
            window.draw(levelup);
            // portal
            slowportal++;
            if (slowportal % 40 == 0) {
                portalx++;
                if (portalx == 4) {
                    portalx = 0;
                }
            }
            portal.setTextureRect(sf::IntRect(portalx * 297, 0, 304, 300));
            window.draw(portal);
            if (boy.getPosition().x >= 1070 && boy.getPosition().x <= 1140) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    xpbar.setSize(sf::Vector2f(0, 20));
                    mainmenubool = false;
                    startlevel_1 = false;
                    startlevel_2 = false;
                    startlevel_3 = false;
                    startlevel_4 = false;
                    startlevel_5 = true;
                    break;
                }
            }
        }
        
        if (myhealth.getSize().x > 0) {
            if (hitcharacter) {
                window.draw(ko);
            }
            else if (characterhitting2) {
                character_s3.setTextureRect(sf::IntRect(195 * characterhitframe2, 200 * characterhitframe2_h, 195, 200));
                window.draw(character_s3);
            }
            else {
                window.draw(boy);
            }
        }
        else if (myhealth.getSize().x < 0) {
            text7.setPosition(view.getCenter().x - 300, view.getCenter().y);
            text3.setPosition(view.getCenter().x - 360, view.getCenter().y - 50);
            window.draw(grave);
            //Restart level
            if (number_of_lives == 1) {
                window.draw(text7);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    restart = true;
                    startlevel_4 = false;
                    mainmenubool = true;
                    window.setView(window.getDefaultView());
                    break;
                }
            }
            else if (number_of_lives > 1) {
                window.draw(text3);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    myhealth.setSize(sf::Vector2f(300.0f, 15.0f));
                    number_of_lives--;
                    startlevel_4 = true;
                    break;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
                    restart = true;
                    startlevel_1 = false;
                    startlevel_2 = false;
                    startlevel_3 = false;
                    startlevel_4 = false;
                    startlevel_5 = false;
                    mainmenubool = true;
                    window.setView(window.getDefaultView());
                    break;
                }
            }
        }
        for (int i = 0; i < 6; i++) {
            if (!monsters_level4[i].monster_attack) {
                window.draw(monster[i]);
            }
            if (monsters_level4[i].monster_attack && !monsters_level4[i].monsterdead) {
                window.draw(monsterhit[i]);
                if (i < 3) {
                    monsterhit[i].setPosition(monster[i].getPosition().x - 10, monster[i].getPosition().y - 30);
                    slowing_wolfeffect++;
                    if (slowing_wolfeffect == 50) {
                        wolfeffect_x++;
                        wolfeffect_x %= 5;
                        slowing_wolfeffect = 0;
                    }
                    wolfeffect.setTextureRect(sf::IntRect(wolfeffect_x * 65, 0, 65, 70));
                    wolfeffect.setPosition(boy.getPosition().x, boy.getPosition().y);
                    if (boybound.intersects(wolfeffectbound) && wolfeffect_x == 4 && myhealth.getSize().x >= 0)
                        myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.1, 15));
                    window.draw(wolfeffect);
                }
                else {
                    monsterhit[i].setPosition(monster[i].getPosition().x, monster[i].getPosition().y - 15);
                    slowing_dinoeffect++;
                    if (slowing_dinoeffect == 50) {
                        dinoeffect_x++;
                        dinoeffect_x %= 5;
                        slowing_dinoeffect = 0;
                    }
                    dinoeffect.setTextureRect(sf::IntRect(dinoeffect_x * 50, 0, 50, 85));
                    dinoeffect.setPosition(boy.getPosition().x - 10, boy.getPosition().y - 10);
                    if (monsters_level4[i].monsterframe_2 >= 4) {
                        if (boybound.intersects(dinoeffectbound) && dinoeffect_x == 2 && myhealth.getSize().x >= 0)
                            myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.1, 15));
                        window.draw(dinoeffect);
                    }
                }
            }
            if (monsters_level4[i].monster_border && !monsters_level4[i].monsterdead) {
                window.draw(monsterhealthborder[i]);
                window.draw(monsterhealth[i]);
            }

        }


        if (showdragonhealth && !dragondead) {
            window.draw(dragonhealthboarder);
            window.draw(dragonhealth);
            dragonhealth.setPosition(dragon.getPosition().x, dragon.getPosition().y - 20);
            dragonhealthboarder.setPosition(dragon.getPosition().x, dragon.getPosition().y - 20);
        }

        if (!dragonattack && !dragonattack2 || dragonhealth.getSize().x <= 0) {
            dragon.setTextureRect(sf::IntRect(dragonx * 200, dragony * 200, 200, 200));
        }
        else if (dragonattack) {
            dragon.setTextureRect(sf::IntRect(dragonx * 280, dragony * 200, 260, 208));
        }
        if (!dragonattack2)
            window.draw(dragon);
        if (dragonattack2) {
            window.draw(dragonhit);
            dragonhit.setTextureRect(sf::IntRect(dragon_x_hit * 350, dragon_y_hit * 250, 350, 250));
            dragonhit.setPosition(dragon.getPosition().x, dragon.getPosition().y - 55);
        }



        //Effect
        if (dragonattack && !dragondead) {
            sloweffect1++;
            if (sloweffect1 == 50) {
                effect1++;
                effect1 %= 4;
                sloweffect1 = 0;
            }
            dragon_effect1.setPosition(boy.getPosition().x - 10, boy.getPosition().y);
            dragon_effect1.setTextureRect(sf::IntRect(effect1 * 100, 0, 100, 100));
            if (boybound.intersects(dragoneffectbound) && effect1 == 2 && myhealth.getSize().x >= 0)
                myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.1, 15));
            window.draw(dragon_effect1);
        }
        if (dragonattack2 && !dragondead) {
            slowing_effect2++;
            if (slowing_effect2 == 50) {
                effect2_x++;
                effect2_x %= 3;
                slowing_effect2 = 0;
            }
            dragon_effect2.setPosition(boy.getPosition().x + 10, boy.getPosition().y);
            dragon_effect2.setTextureRect(sf::IntRect(effect2_x * 65, 0, 55, 95));
            if (boybound.intersects(dragonattackbound) && dragon_x_hit == 4 && myhealth.getSize().x >= 0)
                myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.2, 15));
            window.draw(dragon_effect2);
        }

        if (boy.getPosition().x >= 50 && boy.getPosition().x <= 75) {
            window.draw(text6);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                show_guide = true;
            }
            if (show_guide) {
                window.draw(panel);
                window.draw(guide_text);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                    show_guide = false;

                }
            }
        }
        else
            show_guide = false;

        for (int i = 0; i < number_of_lives; i++)
            window.draw(heart[i]);

        window.draw(guide);
        window.draw(healthtext);
        window.draw(xptext);
        window.draw(xpboarder);
        window.draw(xpbar);
        window.draw(healthboarder);
        window.draw(myhealth);

        window.display();


        /////////////////////////////
        // Player moving animation //
        /////////////////////////////
        boy.setTextureRect(sf::IntRect(boyx * 56.5, boyy * 85, 56.5, 85));
        ko.setTextureRect(sf::IntRect(boyhitx * 160, boyhity * 150, 160, 150));
        for (int i = 0; i < 3; i++) {
            monster[i].setTextureRect(sf::IntRect(monsters_level4[i].monsterframe * 110, monsters_level4[i].monsterframe_h * 65, 110, 65));
            monsterhit[i].setTextureRect(sf::IntRect(monsters_level4[i].monsterframe_2 * 215, monsters_level4[i].monsterframe2_h * 115, 215, 115));
        }
        for (int i = 3; i < 6; i++) {
            monster[i].setTextureRect(sf::IntRect(monsters_level4[i].monsterframe * 135, monsters_level4[i].monsterframe_h * 105, 135, 105));
            monsterhit[i].setTextureRect(sf::IntRect(monsters_level4[i].monsterframe_2 * 200, monsters_level4[i].monsterframe2_h * 130, 200, 130));
            if (monsters_level4[i].monsterdead) {
                monster[i].setTextureRect(sf::IntRect(monsters_level4[i].monsterframe * 180, monsters_level4[i].monsterframe_h * 105, 180, 105));
            }
        }



        grave.setTextureRect(sf::IntRect(grave_x * 105, 0, 105, 125));
    }
}

////////////////////////////
/////// LEVEL 5 ////////////
////////////////////////////

void level_5() {

    //Text and fonts
    sf::Text text;
    sf::Font font1;
    font1.loadFromFile("font.otf");
    text.setFont(font1);
    text.setString("Health  ");
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(10, 50);
    sf::Text text2;
    text2.setFont(font1);
    text2.setString("Do you want to restart this level? (Y/N)");
    text2.setFillColor(sf::Color::Yellow);
    sf::Text start_blackmage;
    start_blackmage.setFont(font1);
    start_blackmage.setString("Press Enter to Continue");
    start_blackmage.setFillColor(sf::Color::Yellow);
    sf::Text finaltext;
    finaltext.setFont(font1);
    finaltext.setString("\t \t \t \t \tCONGRATULATIONS!!!\n\n\t YOU HAVE DEFEATED THE BLACKMAGE \n \n \t \t\t \t \t AND SAVED THE WORLD \n \n \n \n \n \n \npress Enter to move to the main menu");
    finaltext.setFillColor(sf::Color::Yellow);
    sf::Text characterdead;
    characterdead.setFont(font1);
    characterdead.setString("\t\t\t\t\t\tYou Lost!!\n\nPress 'Y' to move to the main menu");
    characterdead.setFillColor(sf::Color::Yellow);

    //Heart and life
    sf::Texture heart_pic;
    heart_pic.loadFromFile("heart.png");
    sf::Sprite heart[5];
    for (int i = 0; i < 5; i++) {
        heart[i].setTexture(heart_pic);
    }
    heart[0].setPosition(20, 100);
    heart[1].setPosition(80, 100);
    heart[2].setPosition(140, 100);
    heart[3].setPosition(200, 100);
    heart[4].setPosition(360, 100);


    //Background Texture and Sprite
    sf::Texture backgroundimg;
    backgroundimg.loadFromFile("background level5.jpg");
    sf::Sprite background(backgroundimg);

    //Character texture and sprite
    sf::Texture character1, character2, character3;
    character1.loadFromFile("character 1.png");
    character2.loadFromFile("character 2.png");
    character3.loadFromFile("character 3.png");
    sf::Sprite character_s(character1);
    sf::Sprite character_s2(character2);
    sf::Sprite character_s3(character3);
    //Character positioning
    character_s.setPosition(50, 560);
    //Character Health
    sf::RectangleShape myhealthborder(sf::Vector2f(300.0f, 15.0f));
    myhealth.setFillColor(sf::Color::Blue);
    myhealthborder.setFillColor(sf::Color::Transparent);
    myhealthborder.setOutlineThickness(2.5);
    myhealthborder.setOutlineColor(sf::Color::Yellow);
    //Character Variables
    int ground = 650;
    float gravity = 0.01, movespeed = 0.3, jumpspeed = 2.0;
    bool characterhitting = false, characterhitting2 = false, canjump = false;
    int characterframe = 0, characterframe_h = 1, characterhitframe = 0, characterhitframe_h = 1, characterhitframe2 = 0, characterhitframe2_h = 1;
    int  slowingcharactermove = 0, slowingcharacterhit = 0, slowingmonsterhit = 0, effectframe = 0, slowingeffectframe = 0, slowingeffectframeboss2 = 0;
    //Velocity of character
    sf::Vector2f velocity[2];
    for (int i = 0; i < 2; i++) {
        velocity[i] = (sf::Vector2f(0, 0));
    }

    //Grave Sprite and Texture
    sf::Texture  grave;
    grave.loadFromFile("grave.png");
    sf::Sprite grave_s;
    grave_s.setTexture(grave);
    //grave variables
    int slowinggrave = 0, graveanimation = 0;

    //Ghosts Texture and Sprites
    sf::Texture ghost_motion;
    sf::Texture ghost_attacking;
    ghost_motion.loadFromFile("ghost.png");
    ghost_attacking.loadFromFile("ghost_2.png");
    sf::Sprite ghost[4];
    sf::Sprite ghost_attack[4];
    for (int i = 0; i < 4; i++) {
        ghost[i].setTexture(ghost_motion);
    }
    for (int i = 0; i < 4; i++) {
        ghost_attack[i].setTexture(ghost_attacking);
    }
    //Positioning
    ghost[0].setPosition(200, 550);
    ghost[1].setPosition(600, 550);
    ghost[2].setPosition(900, 550);
    ghost[3].setPosition(800, 550);
    //Small Ghost Attack
    sf::Texture bosshit;
    bosshit.loadFromFile("ghost hit.png");
    sf::Sprite hittingeffect(bosshit);
    bool ghosthit[4];
    for (int i = 0; i < 4; i++) {
        ghosthit[i] = false;
    }
    //Ghosts Health Bars and borders
    sf::RectangleShape monsterhealth[4];
    sf::RectangleShape monsterborder[4];
    for (int index = 0; index < 4; index++) {
        monsterhealth[index].setSize(sf::Vector2f(100.0f, 10.0f));
        monsterborder[index].setSize(sf::Vector2f(100.0f, 10.0f));
        monsterhealth[index].setFillColor(sf::Color::Red);
        monsterborder[index].setFillColor(sf::Color::Transparent);
        monsterborder[index].setOutlineThickness(2);
        monsterborder[index].setOutlineColor(sf::Color::Yellow);
    }
    //Ghost Variables
    int monsterindex, count[5];
    for (int index = 0; index < 5; index++) {
        count[index] = 0;
    }

    //Boss fight Texture and Sprite
    sf::RectangleShape bosshealthborder(sf::Vector2f(350.0, 15.0f));
    sf::Texture bosspic1;
    sf::Texture bosspic2;
    bosspic1.loadFromFile("boss ghost.png");
    bosspic2.loadFromFile("boss ghost_2.png");
    sf::Sprite boss1(bosspic1);
    sf::Sprite boss2(bosspic2);
    sf::Texture bosseffect_1;
    bosseffect_1.loadFromFile("hit-effect-png-2.png");
    sf::Sprite bosseffect1(bosseffect_1);
    sf::Texture bosseffect_2;
    bosseffect_2.loadFromFile("ghost_boss_hit.png");
    sf::Sprite bosseffect2(bosseffect_2);
    sf::Texture bosseffect_3;
    bosseffect_3.loadFromFile("bosseffect3.png");
    sf::Sprite bosseffect3(bosseffect_3);
    sf::Texture boss_iconpic;
    boss_iconpic.loadFromFile("bossicon.jpg");
    sf::Sprite boss_icon(boss_iconpic);

    boss_icon.setScale(0.3, 0.4);



    boss1.setPosition(300, -300);
    boss2.setPosition(300, -300);
    bosshealth.setFillColor(sf::Color::Red);
    bosshealthborder.setFillColor(sf::Color::Transparent);
    bosshealthborder.setOutlineColor(sf::Color::Yellow);
    bosshealthborder.setOutlineThickness(2.5);
    //Boss Fight Variables
    int bossframe = 0, bosshitframe = 0, bossframe_h = 0, bosshitframe_h = 0, slowingbossmove = 0, slowingbossdeath = 0, slowingeffectframeboss1 = 0, effect1_frame = 0, effect2_frame = 0, effect3_frame = 0;
    int bosssecondandthirdframe = 0, bosssecondandthirdframe_h = 0, slowingbossattack1 = 0, slowingbossattack2 = 0, slowingbossattack3 = 0, slowingeffect3frameboss = 0;
    sf::Vector2f boss_velocity(sf::Vector2f(0.0f, 0.0f));
    bool bossmoveright = false, bossmoveleft = false, bossfight = false, showbosshealth = false, bosshit1bool = false, bosshit2bool = false, bosshit3bool = false;
    int numofattack = 0, delayingattack = 0, thismomenttime = 0;

    //Wings texture and sprite

    sf::Texture wingsimg;
    wingsimg.loadFromFile("wings.png");
    sf::Sprite wings(wingsimg);
    wings.setPosition(50, ground - 200);
    //Wings variables
    int wingframe = 0, wingframe_h = 0, slowingwing = 0;
    bool start_wings = false;
 


    //Black Mage hits
    sf::Texture firepic;
    firepic.loadFromFile("fire.png");
    sf::Sprite fire[8];
    for (int i = 0; i < 8; i++) {
        fire[i].setTexture(firepic);
    }
    int fire_frame = 0, slowing_fire = 0, fire_position = 50;
    bool drawfire = false;

    sf::Texture stormpic;
    stormpic.loadFromFile("lightning.png");
    sf::Sprite lightning[2];
    for (int i = 0; i < 2; i++) {
        lightning[i].setTexture(stormpic);
    }
    int storm_frame = 0, slowing_storm = 0, storm_position = 0, storm_position2 = 0;
    bool drawstorm = false;

    sf::Texture warningpic;
    warningpic.loadFromFile("warning.png");
    sf::Sprite warning[8];
    for (int i = 0; i < 8; i++) {
        warning[i].setTexture(warningpic);
    }
    int warning_frame = 0, slowing_warning = 0;
    bool drawwarning = false;

    sf::Texture redhitpic;
    redhitpic.loadFromFile("red-hit.png");
    sf::Sprite redhit[8];
    for (int i = 0; i < 8; i++) {
        redhit[i].setTexture(redhitpic);
    }
    redhit[0].setPosition(20, -20);
    redhit[1].setPosition(170, -100);
    redhit[2].setPosition(320, -180);
    redhit[3].setPosition(470, -260);
    redhit[4].setPosition(620, -340);
    redhit[5].setPosition(770, -420);
    redhit[6].setPosition(920, -500);
    redhit[7].setPosition(1070, -580);
    int redhit_frame = 0, slowing_redhit = 0, draw_red = 0;

    sf::Texture lightiningball_t;
    lightiningball_t.loadFromFile("lightningball.png");
    sf::Sprite lightiningball(lightiningball_t);
    sf::Texture lightiningball_t2;
    lightiningball_t2.loadFromFile("lightningball_2.png");
    sf::Sprite lightiningball_2(lightiningball_t2);
    sf::Texture lightiningball_t3;
    lightiningball_t3.loadFromFile("lightningball_3.png");
    sf::Sprite lightiningball_3(lightiningball_t3);
    int lightball_frame = 0, slowing_lightball = 0, lightball_frame2 = 0, slowing_lightball2 = 0, lightball_frame3 = 0, slowing_lightball3 = 0;
    int ballmovementtimestart = 0, ballmovementtimestop = 0;
    bool firstlight = false, secondlight = false, ballsmoke = false;


    //Blackmage
    sf::Sprite blackmage[35];
    sf::Texture mage[35];
    bool blackmagefight = false;
    for (int i = 0; i < 35; i++) {
        string name = to_string(i + 3);
        mage[i].loadFromFile("8cbd3679cf874065a0d34638396b42f2kqQ7KJuZyZsple6t-" + name + "-removebg-preview.png");
    }
    for (int i = 0; i < 35; i++) {
        blackmage[i].setScale(0.7, 0.7);
        blackmage[i].setTexture(mage[i]);
        blackmage[i].setPosition(500, 150);
    }


    //Black mage intro
    sf::Texture mage_intro_pic[89];
    for (int i = 0; i < 89; i++) {
        string pic_name = to_string(i + 1);

        if (i >= 0 && i < 9) {
            mage_intro_pic[i].loadFromFile("000" + pic_name + ".jpg");
        }
        else
            mage_intro_pic[i].loadFromFile("00" + pic_name + ".jpg");

    }
    sf::Sprite mage_intro[89];
    for (int i = 0; i < 89; i++) {
        mage_intro[i].setTexture(mage_intro_pic[i]);
        mage_intro[i].setScale(0.68, 0.73);
        mage_intro[i].setPosition(-220, 100);
    }
    int intro_frame = 0, slowing_intro = 0;

    //Black mage final
    sf::Texture mage_final_pic[48];
    for (int i = 0; i < 48; i++) {
        string pic_name = to_string(i);

        if (i >= 0 && i <= 9) {
            mage_final_pic[i].loadFromFile("blackmage dead_00" + pic_name + ".jpg");
        }
        else
            mage_final_pic[i].loadFromFile("blackmage dead_0" + pic_name + ".jpg");

    }

    sf::Sprite mage_final[48];
    for (int i = 0; i < 48; i++) {
        mage_final[i].setTexture(mage_final_pic[i]);
        mage_final[i].setScale(0.68, 0.73);
        mage_final[i].setPosition(-220, 100);
    }
    int final_frame = 0, slowing_final = 0;

    sf::RectangleShape blackmage_border(sf::Vector2f(350.0f, 15.0f));

    blackmage_health.setFillColor(sf::Color::Black);
    blackmage_border.setFillColor(sf::Color::Transparent);
    blackmage_border.setOutlineColor(sf::Color::Red);
    blackmage_border.setOutlineThickness(2.5);

    int mageframe = 0, slowingmage = 0;

    sf::Texture black_mageicon;
    black_mageicon.loadFromFile("mage_icon.jpg");
    sf::Sprite mage_icon(black_mageicon);

    mage_icon.setScale(0.1, 0.1);
    //Views
    sf::View view;
    view.setSize(800, 550);
    view.setCenter(400, 445);

    //Sounds 
    sf::Music background1;
    background1.openFromFile("background1.wav");
    background1.setVolume(50);

    sf::Music intro;
    intro.openFromFile("mageintro.wav");

    sf::Music final;
    final.openFromFile("blackmage final sound.wav");

    sf::Music background2;
    background2.openFromFile("background2.wav");
    background2.setVolume(50);

    sf::SoundBuffer ghostbeinghit;
    ghostbeinghit.loadFromFile("small ghost being hit.wav");
    sf::Sound ghostbeinghitsound(ghostbeinghit);

    sf::SoundBuffer bossghostbeinghit;
    bossghostbeinghit.loadFromFile("ghost being hit.wav");
    sf::Sound bossghostbeinghitsound(bossghostbeinghit);

    sf::SoundBuffer boosghostattack1;
    boosghostattack1.loadFromFile("ghost hit 1.wav");
    sf::Sound bossattacksound1(boosghostattack1);

    sf::SoundBuffer boosghostattack2;
    boosghostattack2.loadFromFile("ghost hit 2.wav");
    sf::Sound bossattacksound2(boosghostattack2);

    sf::SoundBuffer boosghostattack3;
    boosghostattack3.loadFromFile("ghost hit 3.wav");
    sf::Sound bossattacksound3(boosghostattack3);

    sf::SoundBuffer fireeffect;
    fireeffect.loadFromFile("fire soundeffect.wav");
    sf::Sound firesoundeffect(fireeffect);

    sf::SoundBuffer lightiningeffect;
    lightiningeffect.loadFromFile("lightining soundeffect.wav");
    sf::Sound lightiningsoundeffect(lightiningeffect);

    sf::SoundBuffer hitting;
    hitting.loadFromFile("hit.wav");
    sf::Sound hitsound(hitting);

    if (!boss_dead)
        background1.play();

    //////////////////////GAME LOOP///////////////////////////
    while (window.isOpen()) {


        //Character bounds
        sf::FloatRect bound = character_s2.getGlobalBounds();
        sf::FloatRect bound2 = character_s.getGlobalBounds();
        sf::FloatRect bound3 = character_s3.getGlobalBounds();
        //Ghost Attack effect bounds
        sf::FloatRect effect = hittingeffect.getGlobalBounds();
        //Monsters bounds
        sf::FloatRect monsterbound[4];
        for (int index = 0; index < 4; index++) {
            monsterbound[index] = ghost[index].getGlobalBounds();
        }
        //Boss bound
        sf::FloatRect bossbound1 = boss1.getGlobalBounds();
        //Boss hits Bounds
        sf::FloatRect bossattackbound_1 = bosseffect1.getGlobalBounds();
        sf::FloatRect bossattackbound_2 = bosseffect2.getGlobalBounds();
        sf::FloatRect bossattackbound_3 = bosseffect3.getGlobalBounds();
        //Wings bound
        sf::FloatRect wingbound = wings.getGlobalBounds();
        //Black mage bound
        sf::RectangleShape blackmagerect(sf::Vector2f(200, 200));
        blackmagerect.setPosition(550, 220);
        sf::FloatRect blackmagebound = blackmagerect.getGlobalBounds();
        //Black mage hits bound
        sf::FloatRect fire_bound[8];
        sf::FloatRect red_hitbounds[8];
        sf::RectangleShape redhitrectangle[8];
        sf::FloatRect lightning_bound[2];
        sf::FloatRect lightningballbound = lightiningball_2.getGlobalBounds();
        for (int i = 0; i < 8; i++) {
            fire_bound[i] = fire[i].getGlobalBounds();
        }
        for (int i = 0; i < 8; i++) {
            redhitrectangle[i].setSize(sf::Vector2f(100, 100));
            redhitrectangle[i].setPosition(redhit[i].getPosition().x+25, redhit[i].getPosition().y+25);
            red_hitbounds[i] = redhitrectangle[i].getGlobalBounds();
        }
        for (int i = 0; i < 2; i++) {
            lightning_bound[i] = lightning[i].getGlobalBounds();
        }

        //Event Loop
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (intro_frame >= 0 && intro_frame <= 10 && boss_dead) {
                background1.pause();
                intro.play();
            }

            if (boss_dead && intro_frame == 88 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                intro_frame += 1;
                intro.pause();
                background2.play();
            }
            if (myhealth.getSize().x > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                for (int i = 0; i < 4; i++) {
                    if (bound.intersects(monsterbound[i]) && characterhitframe == 0 && !monsters_level5[i].monsterdead) {
                        ghostbeinghitsound.play();
                    }
                    else if (bossfight && bound.intersects(bossbound1) && characterhitframe == 0 && !boss_dead) {
                        bossghostbeinghitsound.play();
                    }
                    else if (characterhitframe == 0)
                        hitsound.play();
                }
            }
            if (myhealth.getSize().x > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                for (int i = 0; i < 4; i++) {
                    if (bound3.intersects(monsterbound[i]) && characterhitframe2 == 2 && !monsters_level5[i].monsterdead) {
                        ghostbeinghitsound.play();
                    }
                    else if (bossfight && bound3.intersects(bossbound1) && characterhitframe2 == 2 && !boss_dead) {
                        bossghostbeinghitsound.play();
                    }
                    else if (characterhitframe2 == 0)
                        hitsound.play();
                }
            }
            if (myhealth.getSize().x > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                for (int i = 0; i < 4; i++) {
                    if (bound3.intersects(monsterbound[i]) && characterhitframe2 == 2 && !monsters_level5[i].monsterdead) {
                        ghostbeinghitsound.play();
                    }
                    else if (bossfight && bound3.intersects(bossbound1) && characterhitframe2 == 2 && !boss_dead) {
                        bossghostbeinghitsound.play();
                    }
                    else if (characterhitframe2 == 0)
                        hitsound.play();
                }
            }
            if (myhealth.getSize().x >= 0) {
                if (bosshit1bool && !boss_dead && bosshitframe == 2)
                    bossattacksound1.play();

                if (bosshit2bool && !boss_dead && bosssecondandthirdframe == 2)
                    bossattacksound2.play();


                if (bosshit3bool && !boss_dead && bosssecondandthirdframe == 3)
                    bossattacksound3.play();

                if (blackmagefight && drawfire && fire_frame == 2 && blackmage_health.getSize().x >= 0)
                    bossattacksound2.play();

                if (blackmagefight && !drawstorm && storm_frame == 0 && clock() / CLOCKS_PER_SEC % 2 == 0 && blackmage_health.getSize().x <= 250 && blackmage_health.getSize().x >= 0)
                    lightiningsoundeffect.play();
            }
            if (blackmage_health.getSize().x <= 0 && final_frame >= 0 && final_frame <= 10) {
                background2.pause();
                final.play();
            }

        }

        //Monster Health bars Positioning
        for (int index = 0; index < 4; index++) {
            if (!ghosthit[index]) {
                monsterhealth[index].setPosition(ghost[index].getPosition().x - 15, 520);
                monsterborder[index].setPosition(ghost[index].getPosition().x - 15, 520);
            }
            else if (ghosthit) {
                monsterhealth[index].setPosition(ghost_attack[index].getPosition().x - 15, 520);
                monsterborder[index].setPosition(ghost_attack[index].getPosition().x - 15, 520);
            }
        }
        //Boss health positioning
        boss_icon.setPosition(bosshealthborder.getPosition().x - 60, bosshealth.getPosition().y - 15);
        bosshealth.setPosition(view.getCenter().x - 200, view.getCenter().y - 210);
        bosshealthborder.setPosition(view.getCenter().x - 200, view.getCenter().y - 210);
        //Black Mage health positioning
        mage_icon.setPosition(bosshealthborder.getPosition().x - 20, bosshealth.getPosition().y - 20);
        blackmage_health.setPosition(view.getCenter().x - 160, view.getCenter().y - 220);
        blackmage_border.setPosition(view.getCenter().x - 160, view.getCenter().y - 220);
        //CHaracter Health bar positioning
        text.setPosition(myhealthborder.getPosition().x - 140, myhealth.getPosition().y - 10);
        myhealth.setPosition(view.getCenter().x - 250, view.getCenter().y + 239);
        myhealthborder.setPosition(view.getCenter().x - 250, view.getCenter().y + 239);
        //Intro positioning
        for (int i = 0; i < 89; i++) {
            mage_intro[i].setPosition(view.getCenter().x - 580, view.getCenter().y - 345);
        }
        start_blackmage.setPosition(bosshealthborder.getPosition().x - 20, bosshealth.getPosition().y - 35);
        //final positioning
        for (int i = 0; i < 48; i++) {
            mage_final[i].setPosition(view.getCenter().x - 580, view.getCenter().y - 345);
        }
        finaltext.setPosition(bosshealthborder.getPosition().x - 150, bosshealth.getPosition().y - 35);
        //Heart positioning
        heart[0].setPosition(view.getCenter().x - 360, view.getCenter().y - 345);
        heart[1].setPosition(view.getCenter().x - 300, view.getCenter().y - 345);
        heart[2].setPosition(view.getCenter().x - 240, view.getCenter().y - 345);
        heart[3].setPosition(view.getCenter().x - 180, view.getCenter().y - 345);
        heart[4].setPosition(view.getCenter().x - 120, view.getCenter().y - 345);
        //Character Dead Texts Positioning
        text2.setPosition(view.getCenter().x - 360, view.getCenter().y);
        characterdead.setPosition(view.getCenter().x - 300, view.getCenter().y);
        //Views
        if (view.getCenter().x - character_s.getPosition().x <= 50 && view.getCenter().x <= 820) {
            view.move(0.3, 0);
        }
        if (view.getCenter().x - character_s.getPosition().x >= 100 && view.getCenter().x > 400) {
            view.move(-0.3, 0);
        }

        //Character hitting
        characterhitting = false;
        characterhitting2 = false;
        character_s2.setPosition(character_s.getPosition().x - 50, character_s.getPosition().y - 70);
        character_s3.setPosition(character_s.getPosition().x - 70, character_s.getPosition().y - 50);
        //First Hit
        if (myhealth.getSize().x > 0) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                slowingcharacterhit++;
                characterhitting = true;
                if (characterframe_h == 0 || characterframe_h == 1)
                    characterhitframe_h = characterframe_h;
                else if (characterframe_h == 3 || characterframe_h == 4)
                    characterhitframe_h = characterframe_h - 3;
                if (slowingcharacterhit == 70) {
                    characterhitframe++;
                    characterhitframe %= 4;
                    slowingcharacterhit = 0;
                }
                //Monster losing life
                for (int index = 0; index < 4; index++) {
                    if (bound.intersects(monsterbound[index]) && characterhitframe == 1 && !monsters_level5[index].monsterdead) {
                        monsters_level5[index].monsterdamage = true;
                        monsters_level5[index].monster_border = true;
                        monsterhealth[index].setSize(sf::Vector2f(monsterhealth[index].getSize().x - 0.1, 10));
                        if (ghost[index].getPosition().x >= character_s2.getPosition().x) {
                            ghost[index].move(0.5, 0);
                        }
                        else if (ghost[index].getPosition().x < character_s2.getPosition().x) {
                            ghost[index].move(-0.5, 0);
                        }
                    }
                }
                //Boss losing life
                if (bossfight) {

                    if (bound.intersects(bossbound1) && characterhitframe == 1 && bosshealth.getSize().x > 0) {
                        showbosshealth = true;
                        bosshealth.setSize(sf::Vector2f(bosshealth.getSize().x - 0.1, 15));
                        if (boss1.getPosition().x >= character_s2.getPosition().x) {
                            boss1.move(0.5, 0);
                        }
                        else if (boss1.getPosition().x < character_s2.getPosition().x) {
                            boss1.move(-0.5, 0);
                        }
                    }

                }
                //Blackmage losing life
                if (blackmagefight) {
                    if (bound.intersects(blackmagebound) && characterhitframe == 1 && blackmage_health.getSize().x > 0)
                        blackmage_health.setSize(sf::Vector2f(blackmage_health.getSize().x - 0.03, 15));

                }
            }

            //Second Hit

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                slowingcharacterhit++;
                characterhitting2 = true;
                if (characterframe_h == 0 || characterframe_h == 1)
                    characterhitframe2_h = characterframe_h;
                else if (characterframe_h == 3 || characterframe_h == 4)
                    characterhitframe2_h = characterframe_h - 3;
                if (slowingcharacterhit == 70) {
                    characterhitframe2++;
                    characterhitframe2 %= 4;
                    slowingcharacterhit = 0;
                }
                //Monster losing life
                for (int index = 0; index < 4; index++) {
                    if (bound3.intersects(monsterbound[index]) && characterhitframe2 == 2 && !monsters_level5[index].monsterdead) {
                        monsters_level5[index].monsterdamage = true;
                        monsters_level5[index].monster_border = true;
                        monsterhealth[index].setSize(sf::Vector2f(monsterhealth[index].getSize().x - 0.3, 10));
                        if (ghost[index].getPosition().x >= character_s2.getPosition().x) {
                            ghost[index].move(0.5, 0);
                        }
                        else if (ghost[index].getPosition().x < character_s2.getPosition().x) {
                            ghost[index].move(-0.5, 0);
                        }
                    }
                }

                if (bossfight) {
                    if (bound3.intersects(bossbound1) && characterhitframe2 == 2 && bosshealth.getSize().x > 0) {
                        showbosshealth = true;
                        bosshealth.setSize(sf::Vector2f(bosshealth.getSize().x - 0.2, 15));
                        if (boss1.getPosition().x >= character_s2.getPosition().x) {
                            boss1.move(0.5, 0);
                        }
                        else if (boss1.getPosition().x < character_s2.getPosition().x) {
                            boss1.move(-0.5, 0);
                        }
                    }
                }
                //Blackmage losing life
                if (blackmagefight) {
                    if (bound3.intersects(blackmagebound) && characterhitframe2 == 2 && blackmage_health.getSize().x > 0)
                        blackmage_health.setSize(sf::Vector2f(blackmage_health.getSize().x - 0.06, 15));
                }
            }

            //Third Hit

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                slowingcharacterhit++;
                characterhitting2 = true;
                if (characterframe_h == 0 || characterframe_h == 1)
                    characterhitframe2_h = characterframe_h + 2;
                else if (characterframe_h == 3 || characterframe_h == 4)
                    characterhitframe2_h = characterframe_h - 1;
                if (slowingcharacterhit == 70) {
                    characterhitframe2++;
                    characterhitframe2 %= 4;
                    slowingcharacterhit = 0;
                }
                //Monster losing life
                for (int index = 0; index < 4; index++) {
                    if (bound3.intersects(monsterbound[index]) && (characterhitframe2 == 1 || characterhitframe2 == 3) && !monsters_level5[index].monsterdead) {
                        monsters_level5[index].monsterdamage = true;
                        monsters_level5[index].monster_border = true;
                        monsterhealth[index].setSize(sf::Vector2f(monsterhealth[index].getSize().x - 0.09, 10));
                        if (ghost[index].getPosition().x >= character_s2.getPosition().x) {
                            ghost[index].move(0.4, 0);
                        }
                        else if (ghost[index].getPosition().x < character_s2.getPosition().x) {
                            ghost[index].move(-0.4, 0);
                        }
                    }
                }

                if (bossfight) {
                    if (bound3.intersects(bossbound1) && (characterhitframe2 == 1 || characterhitframe2 == 3) && bosshealth.getSize().x > 0) {
                        showbosshealth = true;
                        bosshealth.setSize(sf::Vector2f(bosshealth.getSize().x - 0.09, 15));
                        if (boss1.getPosition().x >= character_s2.getPosition().x) {
                            boss1.move(0.4, 0);
                        }
                        else if (boss1.getPosition().x < character_s2.getPosition().x) {
                            boss1.move(-0.4, 0);
                        }
                    }
                }
                //Blackmage losing life
                if (blackmagefight) {
                    if (bound3.intersects(blackmagebound) && (characterhitframe2 == 1 || characterhitframe2 == 3) && blackmage_health.getSize().x > 0)
                        blackmage_health.setSize(sf::Vector2f(blackmage_health.getSize().x - 0.04, 15));
                }
            }
        }
        //Character movement
        if (myhealth.getSize().x > 0) {
            if (character_s.getPosition().x <= 0)
                character_s.move(0.5, 0);
            if (character_s.getPosition().x >= 1162)
                character_s.move(-0.5, 0);
            if (character_s.getPosition().x >= 0 && character_s.getPosition().x <= 1162) {
                if (!start_wings) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        slowingcharactermove++;
                        velocity[0].x = movespeed;
                        if (slowingcharactermove == 50) {
                            characterframe++;
                            characterframe_h = 1;
                            characterframe %= 4;
                            slowingcharactermove = 0;
                        }
                    }
                    //Left
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        slowingcharactermove++;
                        velocity[0].x = -movespeed;
                        if (slowingcharactermove == 50) {
                            characterframe++;
                            characterframe_h = 0;
                            characterframe %= 4;
                            slowingcharactermove = 0;
                        }
                    }
                    else
                        velocity[0].x = 0;

                    //Jumping
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && canjump) {
                        canjump = false;
                        velocity[0].y = -jumpspeed;
                    }
                    if (character_s.getPosition().y + 85 < ground || velocity[0].y < 0) {
                        velocity[0].y += gravity;
                        if (velocity[0].x == -movespeed)
                            velocity[0].x -= 0.2;
                        else if (velocity[0].x == movespeed)
                            velocity[0].x += 0.2;
                        character_s2.setPosition(character_s.getPosition().x, character_s.getPosition().y - 50);
                    }
                    else
                    {
                        velocity[0].y = 0;
                        canjump = true;
                    }
                    //Player moving
                    character_s.move(velocity[0].x, velocity[0].y);
                    view.move(0, velocity[0].y / 4);
                }
            }
        }

        //Character losing life 
        if (myhealth.getSize().x > 0) {
            //From Small Ghosts
            for (int index = 0; index < 4; index++) {
                if (bound2.intersects(monsterbound[index]) && monsters_level5[index].monsterdead == false) {
                    myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.15, 15));
                }
            }
            //From Boss
            if (bound2.intersects(bossbound1) && bosshealth.getSize().x > 0 && bossfight) {
                if (myhealth.getSize().x > 0) {
                    myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.02, 15));
                }
            }
        }

        //Character death
        if (myhealth.getSize().x < 0) {
            if (grave_s.getPosition().y < ground - 100) {
                velocity[1].y += gravity;
            }
            else {
                velocity[1].y = 0;
            }
            grave_s.move(0, velocity[1].y * 2);
            if (velocity[1].y == 0) {
                slowinggrave++;
                if (graveanimation == 5)
                    graveanimation = 5;
                else if (slowinggrave == 100) {
                    graveanimation++;
                    graveanimation %= 6;
                    slowinggrave = 0;
                }

            }
        }

        //Attacking Ghost Positioning
        for (int i = 0; i < 4; i++)
            ghost_attack[i].setPosition(ghost[i].getPosition().x, ghost[i].getPosition().y);
        //Monster positoning booleans
        if (!monsters_level5[0].monsterdead) {
            if (ghost[0].getPosition().x <= 200) {
                monsters_level5[0].monstermoveright = true;
                monsters_level5[0].monstermoveleft = false;
            }
            if (ghost[0].getPosition().x >= 600) {
                monsters_level5[0].monstermoveright = false;
                monsters_level5[0].monstermoveleft = true;
            }
        }

        if (!monsters_level5[1].monsterdead) {
            if (ghost[1].getPosition().x >= 600) {
                monsters_level5[1].monstermoveright = false;
                monsters_level5[1].monstermoveleft = true;
            }
            if (ghost[1].getPosition().x <= 300) {
                monsters_level5[1].monstermoveright = true;
                monsters_level5[1].monstermoveleft = false;
            }
        }

        if (!monsters_level5[2].monsterdead) {
            if (ghost[2].getPosition().x >= 900) {
                monsters_level5[2].monstermoveright = false;
                monsters_level5[2].monstermoveleft = true;
            }
            if (ghost[2].getPosition().x <= 500) {
                monsters_level5[2].monstermoveright = true;
                monsters_level5[2].monstermoveleft = false;
            }
        }

        if (!monsters_level5[3].monsterdead) {
            if (ghost[3].getPosition().x >= 800) {
                monsters_level5[3].monstermoveright = false;
                monsters_level5[3].monstermoveleft = true;
            }
            if (ghost[3].getPosition().x <= 550) {
                monsters_level5[3].monstermoveright = true;
                monsters_level5[3].monstermoveleft = false;
            }
        }
        //Monster movement
        for (int index = 0; index < 4; index++) {
            if (!monsters_level5[index].monsterdead) {
                if (monsters_level5[index].monstermoveright) {
                    monsters_level5[index].monsterframe_h = 3;
                    monsters_level5[index].slowingmonstermove++;
                    if (monsters_level5[index].slowingmonstermove == 80) {
                        monsters_level5[index].monsterframe++;
                        monsters_level5[index].monsterframe %= 6;
                        monsters_level5[index].slowingmonstermove = 0;
                    }
                    ghost[index].move(0.15, 0);
                }
                if (monsters_level5[index].monstermoveleft) {
                    monsters_level5[index].monsterframe_h = 0;
                    monsters_level5[index].slowingmonstermove++;
                    if (monsters_level5[index].slowingmonstermove == 80) {
                        monsters_level5[index].monsterframe++;
                        monsters_level5[index].monsterframe %= 6;
                        monsters_level5[index].slowingmonstermove = 0;
                    }
                    ghost[index].move(-0.15, 0);
                }
            }
        }

        //Monster attacking
        for (int i = 0; i < 4; i++) {
            if (myhealth.getSize().x >= 0) {
                if (abs(character_s.getPosition().x - ghost[i].getPosition().x) - 30 <= 180) {
                    ghosthit[i] = true;
                }
                else if (monsters_level5[i].monsterframe_2 == 7 || myhealth.getSize().x <= 0 || monsters_level5[i].monsterdead || abs(character_s.getPosition().x - ghost[i].getPosition().x) - 30 >= 180)
                    ghosthit[i] = false;
            }
        }

        for (int i = 0; i < 4; i++) {
            if (myhealth.getSize().x >= 0) {
                if (ghosthit[i]) {
                    if (ghost_attack[i].getPosition().x >= character_s.getPosition().x) {
                        monsters_level5[i].monstermoveleft = true;
                        monsters_level5[i].monstermoveright = false;
                    }
                    if (ghost_attack[i].getPosition().x <= character_s.getPosition().x) {
                        monsters_level5[i].monstermoveright = true;
                        monsters_level5[i].monstermoveleft = false;
                    }
                    if (monsters_level5[i].monstermoveright) {
                        monsters_level5[i].monsterframe_h = 3;
                        monsters_level5[i].monsterframe2_h = 1;
                    }
                    else if (monsters_level5[i].monstermoveleft) {
                        monsters_level5[i].monsterframe_h = 0;
                        monsters_level5[i].monsterframe2_h = 0;
                    }
                    slowingmonsterhit++;
                    if (slowingmonsterhit == 49) {
                        monsters_level5[i].monsterframe_2++;
                        monsters_level5[i].monsterframe_2 %= 7;
                        slowingmonsterhit = 0;
                    }
                }
            }
        }
        //Monster hitting animation
        for (int index = 0; index < 5; index++) {
            if (monsters_level5[index].monsterdamage) {
                monsterindex = index;
                monsters_level5[monsterindex].monsterframe = 0;
                if (monsters_level5[monsterindex].monstermoveleft)
                    monsters_level5[monsterindex].monsterframe_h = 1;
                if (monsters_level5[monsterindex].monstermoveright)
                    monsters_level5[monsterindex].monsterframe_h = 4;
                monsters_level5[monsterindex].monsterdamage = false;
            }
        }

        //Monsters_level5 dying
        for (int index = 0; index < 4; index++) {
            if (monsterhealth[index].getSize().x <= 0) {
                monsterindex = index;
                count[index]++;
                if (count[index] == 500)
                    monsters_level5[index].monsterdying = true;
                monsters_level5[monsterindex].monsterdead = true;
                if (monsters_level5[monsterindex].monstermoveright) {
                    monsters_level5[monsterindex].monsterframe_h = 5;
                }
                if (monsters_level5[monsterindex].monstermoveleft) {
                    monsters_level5[monsterindex].monsterframe_h = 2;
                }
                monsters_level5[monsterindex].slowingmonstermove++;
                if (monsters_level5[monsterindex].slowingmonstermove == 100) {
                    monsters_level5[monsterindex].monsterframe++;
                    monsters_level5[monsterindex].slowingmonstermove = 0;
                }
            }
        }



        //BOSS FIGHT
        if (monsters_level5[0].monsterdead && monsters_level5[1].monsterdead && monsters_level5[2].monsterdead && monsters_level5[3].monsterdead) {
            bossfight = true;
        }

        if (bossfight) {
            if (boss1.getPosition().y + 200 < ground || boss_velocity.y < 0) {
                boss_velocity.y += gravity;
                boss1.move(0, boss_velocity.y);
            }
            else {
                boss_velocity.y = 0;
            }
            if (!boss_dead) {
                if (abs(boss1.getPosition().x - (character_s.getPosition().x - 50)) <= 120) {
                    boss1.move(0, 0);
                    if (bossmoveright) {
                        bossframe_h = 1;
                        slowingbossmove++;
                        if (slowingbossmove == 100) {
                            bossframe++;
                            bossframe %= 8;
                            slowingbossmove = 0;
                        }
                    }
                    else if (bossmoveleft) {
                        bossframe_h = 0;
                        slowingbossmove++;
                        if (slowingbossmove == 100) {
                            bossframe++;
                            bossframe %= 8;
                            slowingbossmove = 0;
                        }
                    }
                }
                else if (boss1.getPosition().x < character_s.getPosition().x) {
                    bossmoveright = true;
                    bossmoveleft = false;
                    boss1.move(0.15, 0);
                    bossframe_h = 1;
                    slowingbossmove++;
                    if (slowingbossmove == 100) {
                        bossframe++;
                        bossframe %= 8;
                        slowingbossmove = 0;
                    }
                }
                else if (boss1.getPosition().x > character_s.getPosition().x) {
                    bossmoveleft = true;
                    bossmoveright = false;
                    boss1.move(-0.15, 0);
                    bossframe_h = 0;
                    slowingbossmove++;
                    if (slowingbossmove == 100) {
                        bossframe++;
                        bossframe %= 8;
                        slowingbossmove = 0;
                    }
                }
            }
            delayingattack = clock() / CLOCKS_PER_SEC - thismomenttime;
            if (!bosshit1bool && !bosshit2bool && !bosshit3bool && delayingattack % 5 == 0 && delayingattack != 0) {
                numofattack = rand() % 3;
                if (numofattack == 0)
                    bosshit1bool = true;
                else if (numofattack == 1)
                    bosshit2bool = true;
                else if (numofattack == 2)
                    bosshit3bool = true;
            }

            //Boss first Attack
            if (bosshit1bool) {
                if (myhealth.getSize().x >= 0) {
                    if (bossmoveleft)
                        bosshitframe_h = 4;
                    else if (bossmoveright)
                        bosshitframe_h = 5;
                    slowingbossattack1++;
                    if (slowingbossattack1 == 100) {
                        bosshitframe++;
                        bosshitframe %= 8;
                        slowingbossattack1 = 0;
                    }
                }
                if (bosshitframe % 8 == 0 || myhealth.getSize().x <= 0) {
                    bosshit1bool = false;
                    if (bosshitframe != 0)
                        thismomenttime = clock() / CLOCKS_PER_SEC;
                }
            }
            //Boss Second Attack
            if (bosshit2bool) {
                if (myhealth.getSize().x >= 0) {
                    if (bossmoveleft)
                        bosssecondandthirdframe_h = 0;
                    else if (bossmoveright)
                        bosssecondandthirdframe_h = 2;
                    slowingbossattack2++;
                    if (slowingbossattack2 == 70) {
                        slowingbossattack2 = 0;
                        bosssecondandthirdframe++;
                        bosssecondandthirdframe %= 11;
                    }
                }
                if (bosssecondandthirdframe % 11 == 0 || myhealth.getSize().x <= 0) {
                    bosshit2bool = false;
                    if (bosssecondandthirdframe != 0)
                        thismomenttime = clock() / CLOCKS_PER_SEC;
                }
            }
            //Boss Third Attack
            if (bosshit3bool) {
                if (myhealth.getSize().x >= 0) {
                    if (bossmoveleft)
                        bosssecondandthirdframe_h = 1;
                    else if (bossmoveright)
                        bosssecondandthirdframe_h = 3;
                    slowingbossattack3++;
                    if (slowingbossattack3 == 50) {
                        slowingbossattack3 = 0;
                        bosssecondandthirdframe++;
                        bosssecondandthirdframe %= 14;
                    }
                }
                if (bosssecondandthirdframe % 14 == 0 || myhealth.getSize().x <= 0) {
                    bosshit3bool = false;
                    if (bosssecondandthirdframe != 0)
                        thismomenttime = clock() / CLOCKS_PER_SEC;
                }
            }

            //Boss dying
            if (bosshealth.getSize().x <= 0) {
                boss_dead = true;
                bosshit1bool = false;
                bosshit2bool = false;
                bosshit3bool = false;
                if (bossmoveleft) {
                    bossframe_h = 2;
                    slowingbossdeath++;
                    if (slowingbossdeath == 100) {
                        bossframe++;
                        slowingbossdeath = 0;
                    }
                }
                if (bossmoveright) {
                    bossframe_h = 3;
                    slowingbossdeath++;
                    if (slowingbossdeath == 100) {
                        bossframe++;
                        slowingbossdeath = 0;
                    }
                }
            }
        }


        //Drawing
        window.clear();
        //Setting view
        window.setView(view);
        window.draw(background);
        //Drawing Ghost health
        for (int index = 0; index < 4; index++) {
            if (!monsters_level5[index].monsterdead && monsters_level5[index].monster_border) {
                window.draw(monsterhealth[index]);
                window.draw(monsterborder[index]);
            }
        }
        //Ghost IntRect and drawing
        for (int index = 0; index < 4; index++) {
            if (monsters_level5[index].monsterdead || !ghosthit[index] || myhealth.getSize().x <= 0) {
                ghost[index].setTextureRect(sf::IntRect(105 * monsters_level5[index].monsterframe, 110 * monsters_level5[index].monsterframe_h, 105, 110));
                window.draw(ghost[index]);
            }
            else if (ghosthit[index]) {
                ghost_attack[index].setTextureRect(sf::IntRect(135 * monsters_level5[index].monsterframe_2, 120 * monsters_level5[index].monsterframe2_h, 135, 120));
                window.draw(ghost_attack[index]);
            }
        }

        //Displaying Black Mage
        if (blackmagefight && blackmage_health.getSize().x >= 0) {
            window.draw(blackmage[mageframe]);
        }
        //Displaying wings
        if (start_wings && myhealth.getSize().x > 0) {
            if (characterframe_h == 3) {
                wingframe_h = 0;
            }
            if (characterframe_h == 4) {
                wingframe_h = 1;
            }
            slowingwing++;
            if (slowingwing == 60) {
                wingframe++;
                wingframe %= 4;
                slowingwing = 0;
            }
            slowingcharactermove++;
            if (slowingcharactermove == 200) {
                characterframe++;
                characterframe %= 2;
                slowingcharactermove = 0;
            }
            wings.setTextureRect(sf::IntRect(wingframe * 260, wingframe_h * 200, 260, 200));
            wings.setPosition(character_s.getPosition().x - 100, character_s.getPosition().y - 80);
            window.draw(wings);
            if (character_s.getPosition().y >= 0) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    character_s.move(0, -0.5);
                    if (view.getCenter().y >= 278)
                        view.move(0, -0.5);
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                character_s.move(-0.3, 0);
                characterframe_h = 3;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                character_s.move(0.3, 0);
                characterframe_h = 4;
            }
            if (character_s.getPosition().y + 85 < ground || velocity[0].y < 0) {
                velocity[0].y += 0.0001;
            }
            else {
                velocity[0].y = 0;
            }

            character_s.move(0, velocity[0].y);
            if (view.getCenter().y <= 446.320)
                view.move(0, velocity[0].y);
        }


        //Displaying Character
        if (myhealth.getSize().x > 0) {
            if (!characterhitting && !characterhitting2) {
                grave_s.setPosition(character_s.getPosition().x, -300);
                character_s.setTextureRect(sf::IntRect(56.5 * characterframe, 85 * characterframe_h, 56.5, 85));
                window.draw(character_s);
            }
            else if (characterhitting) {
                character_s2.setTextureRect(sf::IntRect(160 * characterhitframe, 150 * characterhitframe_h, 160, 150));
                window.draw(character_s2);
            }
            else if (characterhitting2) {
                character_s3.setTextureRect(sf::IntRect(195 * characterhitframe2, 200 * characterhitframe2_h, 195, 200));
                window.draw(character_s3);
            }
            window.draw(myhealth);
        }
        else if (myhealth.getSize().x <= 0) {
            window.draw(grave_s);
            //Restart level
            if (number_of_lives == 1) {
                window.draw(characterdead);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    restart = true;
                    startlevel_1 = false;
                    startlevel_5 = false;
                    mainmenubool = true;
                    window.setView(window.getDefaultView());
                    break;
                }
            }
            else if (number_of_lives > 1) {
                window.draw(text2);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    myhealth.setSize(sf::Vector2f(300.0f, 20.0f));
                    number_of_lives--;
                    startlevel_5 = true;
                    break;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
                    restart = true;
                    startlevel_1 = false;
                    startlevel_5 = false;
                    mainmenubool = true;
                    window.setView(window.getDefaultView());
                    break;
                }
            }
        }
        //Drawing Small Ghost's hitting effect
        for (int i = 0; i < 4; i++) {
            if (myhealth.getSize().x >= 0) {
                if (ghosthit[i]) {
                    slowingeffectframe++;
                    if (slowingeffectframe == 50) {
                        effectframe++;
                        slowingeffectframe = 0;
                    }
                    effectframe %= 2;
                    if (monsters_level5[i].monsterframe_2 >= 5) {
                        hittingeffect.setTextureRect(sf::IntRect(effectframe * 105, 0, 105, 100));
                        hittingeffect.setPosition(character_s.getPosition().x - 20, character_s.getPosition().y);
                        if (!monsters_level5[i].monsterdead && canjump) {
                            window.draw(hittingeffect);
                            if (effect.intersects(bound2)) {
                                myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.05, 15));
                            }
                        }
                    }
                }
            }
        }
        //Drawing Boss Ghost
        if (bossfight && !boss_dead) {
            
            window.draw(bosshealthborder);
            window.draw(bosshealth);
            window.draw(boss_icon);
            

            if (bosshit1bool) {
                boss1.setTextureRect(sf::IntRect(bosshitframe * 155, bosshitframe_h * 200, 155, 200));
                window.draw(boss1);
                slowingeffectframeboss1++;
                if (slowingeffectframeboss1 == 45) {
                    effect1_frame++;
                    slowingeffectframeboss1 = 0;
                    effect1_frame %= 2;
                }
                bosseffect1.setPosition(character_s.getPosition().x - 50, character_s.getPosition().y - 50);
                bosseffect1.setTextureRect(sf::IntRect(effect1_frame * 150, 0, 150, 170));
                if (bossframe >= 4 && myhealth.getSize().x > 0) {
                    if(bound2.intersects(bossattackbound_1) && myhealth.getSize().x >= 0)
                        myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.1, 15));
                    window.draw(bosseffect1);
                }
            }
            else if (bosshit2bool || bosshit3bool) {
                boss2.setTextureRect(sf::IntRect(bosssecondandthirdframe * 270, bosssecondandthirdframe_h * 400, 270, 400));
                boss2.setPosition(boss1.getPosition().x - 80, boss1.getPosition().y - 120);
                window.draw(boss2);

                if (bosshit2bool) {
                    slowingeffect3frameboss++;
                    if (slowingeffect3frameboss == 40) {
                        effect3_frame++;
                        effect3_frame %= 4;
                        slowingeffect3frameboss = 0;
                    }
                    bosseffect3.setTextureRect(sf::IntRect(200 * effect3_frame, 0, 200, 200));
                    bosseffect3.setPosition(character_s.getPosition().x - 70, character_s.getPosition().y - 70);
                    if (bosssecondandthirdframe >= 3 && bosssecondandthirdframe <= 8)
                        if (bound2.intersects(bossattackbound_3) && myhealth.getSize().x >= 0)
                            myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.1, 15));
                        window.draw(bosseffect3);
                }

                if (bosshit3bool) {

                    if (bosssecondandthirdframe >= 0 && bosssecondandthirdframe < 9) {
                        slowingeffectframeboss2++;
                        if (slowingeffectframeboss2 == 50) {
                            effect2_frame++;
                            effect2_frame %= 4;
                            slowingeffectframeboss2 = 0;
                        }
                    }
                    else if (bosssecondandthirdframe == 9) {
                        effect2_frame = 4;
                    }
                    else if (bosssecondandthirdframe >= 10 && bosssecondandthirdframe <= 14) {
                        effect2_frame = 5;
                    }
                    bosseffect2.setPosition(character_s.getPosition().x - 120, character_s.getPosition().y - 70);
                    bosseffect2.setTextureRect(sf::IntRect(300 * effect2_frame, 0, 300, 165));
                    if (bosssecondandthirdframe >= 0 && bosssecondandthirdframe < 14) {
                        if (bosssecondandthirdframe >= 10 && bosssecondandthirdframe <= 14) {
                            if (bound2.intersects(bossattackbound_2) && myhealth.getSize().x >= 0)
                                myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.2, 15));
                        }
                        window.draw(bosseffect2);
                    }
                }
            }
            else {
                boss1.setTextureRect(sf::IntRect(bossframe * 155, bossframe_h * 200, 155, 200));
                window.draw(boss1);
            }
        }
        //displaying blackmage hits

        if (blackmagefight && blackmage_health.getSize().x >= 0) {
            start_wings = true;
            slowingmage++;
            if (slowingmage == 50) {
                mageframe++;
                slowingmage = 0;
                mageframe %= 35;
            }
            for (int i = 0; i < 8; i++)
            {
                if (i == 0) {
                    fire_position = 0;
                }
                if (i == 1) {
                    fire_position = 200;
                }
                if (i == 2) {
                    fire_position = 400;
                }
                if (i == 3) {
                    fire_position = 600;
                }
                if (i == 4) {
                    fire_position = 800;
                }
                if (i == 5) {
                    fire_position = 1000;
                }
                if (i == 6) {
                    fire_position = 1200;
                }
                if (i == 7) {
                    fire_position = 1400;
                }
                fire[i].setPosition(fire_position, 320);
                fire[i].setTextureRect(sf::IntRect(fire_frame * 85, 0, 85, 350));
                warning[i].setTextureRect(sf::IntRect(warning_frame * 85, 0, 85, 30));
                warning[i].setPosition(fire_position, 650);
            }
            if (clock() / CLOCKS_PER_SEC % 8 == 0) {
                drawwarning = true;
            }
            if (drawwarning) {
                slowing_warning++;
                if (slowing_warning == 150) {
                    warning_frame++;
                    warning_frame %= 6;
                    slowing_warning = 0;
                }
                for (int index = 0; index < 8; index++) {
                    window.draw(warning[index]);
                }
                if (warning_frame == 5) {
                    warning_frame += 1;
                    drawwarning = false;
                    drawfire = true;
                }
            }
            if (drawfire) {
                slowing_fire++;
                if (slowing_fire == 70) {
                    fire_frame++;
                    fire_frame %= 10;
                    slowing_fire = 0;
                }
                for (int index = 0; index < 8; index++) {
                    window.draw(fire[index]);
                    if (bound2.intersects(fire_bound[index]) && myhealth.getSize().x >= 0)
                       myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.1, 15));
               }
                if (fire_frame == 9) {
                    fire_frame += 1;
                    drawfire = false;
                }
            }


            slowing_redhit++;
            if (slowing_redhit == 30) {
                redhit_frame++;
                redhit_frame %= 4;
                slowing_redhit = 0;
            }
            for (int i = 0; i < 8; i++) {
                redhit[i].setTextureRect(sf::IntRect(150 * redhit_frame, 0, 150, 150));

                if (redhit[i].getPosition().y + 150 < 4000) {
                    redhit[i].move(0, 0.3);

                }
                else {
                    redhit[0].setPosition(20, -10);
                    redhit[1].setPosition(170, -150);
                    redhit[2].setPosition(320, -300);
                    redhit[3].setPosition(470, -450);
                    redhit[4].setPosition(620, -600);
                    redhit[5].setPosition(770, -750);
                    redhit[6].setPosition(920, -900);
                    redhit[7].setPosition(1070, -1050);

                }
                if (bound2.intersects(red_hitbounds[i]) && myhealth.getSize().x >= 0) {
                    myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.1, 15));

                }
                window.draw(redhit[i]);


            }

            if (blackmage_health.getSize().x <= 250) {
                slowing_storm++;
                if (slowing_storm == 100) {
                    storm_frame++;
                    storm_frame %= 3;
                    slowing_storm = 0;
                }
                drawstorm = true;
                for (int i = 0; i < 2; i++) {
                    if (clock() / CLOCKS_PER_SEC % 6 == 0) {
                        window.draw(lightning[i]);
                        if (bound2.intersects(lightning_bound[i]) && myhealth.getSize().x >= 0)
                            myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 0.1, 15));
                        drawstorm = false;
                    }
                    lightning[i].setTextureRect(sf::IntRect(storm_frame * 300, 0, 300, 1000));
                    if (drawstorm) {
                        storm_position = rand() % 999;
                    }
                    lightning[0].setPosition(storm_position, -300);
                    if (drawstorm) {
                        storm_position2 = rand() % 999;
                    }
                    lightning[1].setPosition(storm_position2, -300);
                }

                if (clock() / CLOCKS_PER_SEC % 13 == 0) {
                    firstlight = true;
                }
                if (firstlight) {
                    slowing_lightball++;
                    if (slowing_lightball == 200) {
                        lightball_frame++;
                        lightball_frame %= 5;
                        slowing_lightball = 0;
                    }
                    if (lightball_frame == 4) {
                        lightball_frame += 1;
                        ballmovementtimestop = clock() / CLOCKS_PER_SEC;
                        firstlight = false;
                        secondlight = true;
                    }
                    lightiningball.setTextureRect(sf::IntRect(200 * lightball_frame, 0, 200, 200));
                    lightiningball.setPosition(550, 100);
                    lightiningball_2.setPosition(550, 100);
                    window.draw(lightiningball);
                }
                if (secondlight) {
                    slowing_lightball2++;
                    if (slowing_lightball2 == 70) {
                        lightball_frame2++;
                        lightball_frame2 %= 5;
                        slowing_lightball2 = 0;
                    }
                    lightiningball_2.setTextureRect(sf::IntRect(200 * lightball_frame2, 0, 200, 200));
                    if (lightiningball_2.getPosition().x <= character_s.getPosition().x) {
                        lightiningball_2.move(0.2, 0);
                    }
                    else if (lightiningball_2.getPosition().x > character_s2.getPosition().x) {
                        lightiningball_2.move(-0.2, 0);
                    }
                    if (lightiningball_2.getPosition().y >= character_s.getPosition().y) {
                        lightiningball_2.move(0, -0.2);
                    }
                    else if (lightiningball_2.getPosition().y < character_s2.getPosition().y) {
                        lightiningball_2.move(0, 0.2);
                    }
                    ballmovementtimestart = clock() / CLOCKS_PER_SEC - ballmovementtimestop;
                    if (ballmovementtimestart >= 8) {
                        ballsmoke = true;
                        secondlight = false;
                    }
                    if (bound2.intersects(lightningballbound)) {
                        if (myhealth.getSize().x > 50)
                            myhealth.setSize(sf::Vector2f(myhealth.getSize().x - 50, 15));
                        else
                            myhealth.setSize(sf::Vector2f(0, 15));

                        ballsmoke = true;
                        secondlight = false;
                    }
                    window.draw(lightiningball_2);
                }
                if (ballsmoke) {
                    slowing_lightball3++;
                    if (slowing_lightball3 == 50) {
                        lightball_frame3++;
                        lightball_frame3 %= 7;
                        slowing_lightball3 = 0;
                    }
                    if (lightball_frame3 == 6) {
                        lightball_frame3 += 1;
                        ballsmoke = false;
                    }
                    lightiningball_3.setTextureRect(sf::IntRect(200 * lightball_frame3, 0, 200, 200));
                    lightiningball_3.setPosition(lightiningball_2.getPosition().x, lightiningball_2.getPosition().y);
                    window.draw(lightiningball_3);
                }
            }
            window.draw(blackmage_border);
            window.draw(blackmage_health);
            window.draw(mage_icon);
        }

        //drawing health bar

        for (int i = 0; i < number_of_lives; i++) {
            window.draw(heart[i]);
        }
        window.draw(myhealth);
        window.draw(myhealthborder);
        window.draw(text);
        
        //Intro
        if (boss_dead && !blackmagefight) {
            if (intro_frame < 88) {
                slowing_intro++;
                if (slowing_intro == 15) {
                    intro_frame++;
                    slowing_intro = 0;
                }
                window.draw(mage_intro[intro_frame]);
            }
            if (intro_frame >= 88) {
                window.draw(mage_intro[88]);
                window.draw(start_blackmage);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    blackmagefight = true;
                }
            }
        }
        if (blackmage_health.getSize().x <= 0) {
            if (final_frame < 47) {
                slowing_final++;
                if (slowing_final == 30) {
                    final_frame++;
                    slowing_final = 0;
                }
                window.draw(mage_final[final_frame]);
            }
            if (final_frame >= 47) {
                window.draw(mage_final[47]);
                window.draw(finaltext);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    startlevel_1 = false;
                    startlevel_5 = false;
                    mainmenubool = true;
                    restart = true;
                    window.setView(window.getDefaultView());
                    break;
                }
            }
        }

        //Displaying
        window.display();


        //Grave IntRect
        grave_s.setTextureRect(sf::IntRect(105 * graveanimation, 0, 105, 125));
    }
}

int main() {
    while (restart) {
        restart_bool();
        restart = false;
        if (mainmenubool)
            main_menu();
        while (number_of_lives > 0) {
            if (startlevel_1)
                level_1();
            else break;
        }
        while (number_of_lives > 0) {
            if (startlevel_2)
                level_2();
            else break;
        }
        while (number_of_lives > 0) {
            if (startlevel_3)
                level_3();
            else break;
        }
        while (number_of_lives > 0) {
            if (startlevel_4)
                level_4();
            else break;
        }
        while (number_of_lives > 0) {
            if (startlevel_5)
                level_5();
            else break;
        }
    }
    return 0;
}
