#include <iostream>
#include "State.h"


std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,160);
auto getRand = std::bind(distribution, generator);

SplashState::SplashState(){
    if(!_font.loadFromFile("assets/arial.ttf")){
        std::cerr << "Error while loading a font\n";
    }
    _txt.setFont(_font);
    _txt.setString("Sorting!");
    _txt.setFillColor(sf::Color::White);
    _txt.setCharacterSize(30);
    _txt.setPosition(350,260);
    _txt.setStyle(sf::Text::Bold);
}
void SplashState::draw(sf::RenderWindow* window){
    window->draw(_txt);
}
void SplashState::update(Machine* machine){
    if(_clock.getElapsedTime().asSeconds() > 3.f){
        machine->setState(new MenuState());
    }
}
void SplashState::handleEvents(sf::Event event, Machine* machine){

}
SplashState::~SplashState(){
    
}

MenuState::MenuState(){
    _btn = new Button[7];
    _btn[0] = Button("Splash",sf::Vector2f(100,100));
    _btn[1] = Button("Bubble sort",sf::Vector2f(100,200));
    _btn[2] = Button("Merge sort",sf::Vector2f(100,300));
    _btn[3] = Button("Bucket sort",sf::Vector2f(100,400));
    _btn[4] = Button("Insertion sort",sf::Vector2f(100,500));
    _btn[5] = Button("Quick sort",sf::Vector2f(300,100));
    _btn[6] = Button("Exit",sf::Vector2f(700,500));
    _rect.setFillColor(sf::Color::Magenta);
    _rect.setSize(sf::Vector2f(700,500));
    _rect.move(50,50);
}
void MenuState::draw(sf::RenderWindow* window){
    window->draw(_rect);
    for(int i=0;i<7;i++){
        window->draw(_btn[i]);
    }

}
void MenuState::update(Machine* machine){
    for(int i=0;i<7;i++){
        _btn[i].hover(machine->getWindow());
    }
}
void MenuState::handleEvents(sf::Event event, Machine* machine){
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button==sf::Mouse::Left){
            _btn[0].onClick(machine, [](Machine* machine){machine->setState(new SplashState());});
            _btn[1].onClick(machine, [](Machine* machine){machine->setState(new BubbleState());machine->draw();machine->windowDisplay();});
            _btn[2].onClick(machine, [](Machine* machine){machine->setState(new MergeState()); machine->draw();machine->windowDisplay();});
            _btn[6].onClick(machine, [](Machine* machine){machine->getWindow()->close();});
        }
    }else if(event.type==sf::Event::EventType::KeyPressed){
        switch(event.key.code){
            case sf::Keyboard::B:
                machine->setState(new BubbleState());
                break;
        }

    }
}
MenuState::~MenuState(){
    delete[] _btn;
}

BubbleState::BubbleState(){
    _rect = new sf::RectangleShape[20];
    _btn = new Button("Back",sf::Vector2f(740,510));
    for(int i=0;i<20;i++){
        _rect[i].setSize(sf::Vector2f(20,5+getRand()*3));
        _rect[i].setPosition(sf::Vector2f(100+i*30,500-_rect[i].getSize().y));
    }
}
void BubbleState::update(Machine* machine){
    _btn->hover(machine->getWindow());

    if(_clock.getElapsedTime().asSeconds()>0.2f){
        for(int j=0;j<19;j++){
            if(_rect[j].getPosition().y<_rect[j+1].getPosition().y){
                sf::RectangleShape tmpRect(_rect[j]);
                _rect[j]=_rect[j+1];
                _rect[j+1]=tmpRect;
                _rect[j].setPosition(_rect[j].getPosition().x-30,_rect[j].getPosition().y);
                _rect[j+1].setPosition(_rect[j+1].getPosition().x+30,_rect[j+1].getPosition().y);
                break;
            }
        }
        _clock.restart();
    }
}
void BubbleState::draw(sf::RenderWindow* window){
    for(int i=0;i<20;i++){
        window->draw(_rect[i]);
    }
    window->draw(*_btn);
}
void BubbleState::handleEvents(sf::Event event, Machine* machine){
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button==sf::Mouse::Left){
            _btn->onClick(machine, [](Machine* machine){machine->setState(new MenuState());});
        }
    }
}
BubbleState::~BubbleState(){    
    delete[] _rect;
    delete _btn;
}

MergeState::MergeState(){
    _btn = new Button("Back",sf::Vector2f(740,510));
    for(int i=0;i<20;i++){
        _rect.push_back(sf::RectangleShape(sf::Vector2f(20,5+getRand()*3)));
        _rect.at(i).setPosition(sf::Vector2f(100+i*30,500-_rect[i].getSize().y));
    }
}
void MergeState::update(Machine* machine){
    _btn->hover(machine->getWindow());

    for(int i=_arrSize;i<20;i=i*2){
        for(int j=0;j<20;j=j+2*i){
            std::vector<sf::RectangleShape> tmpArr;
            int k=j, l=j+i;
            while(tmpArr.size()<2*i){
                if(tmpArr.size()<=20){
                    if(l>j+2*i || l==19){
                        tmpArr.push_back(_rect.at(k));
                        k++;
                    }else if(k==l){
                        tmpArr.push_back(_rect.at(l));
                        l++;
                        break;
                    }else if(_rect.at(k).getPosition().y<_rect.at(l).getPosition().y){
                        tmpArr.push_back(_rect.at(l));
                        l++;
                    }else{
                        tmpArr.push_back(_rect.at(k));
                        k++;
                    }
                }else{
                    break;
                }
            }
            while(!tmpArr.empty()){
                _rect.at(j + tmpArr.size()-1) = tmpArr.back();
                tmpArr.pop_back();
            }
            machine->draw();
            machine->windowDisplay();
        }
        _arrSize=i;
    }
}
void MergeState::draw(sf::RenderWindow* window){
    for(int i=0;i<20;i++){
        window->draw(_rect[i]);
    }
    window->draw(*_btn);
}
void MergeState::handleEvents(sf::Event event, Machine* machine){
     if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button==sf::Mouse::Left){
            _btn->onClick(machine, [](Machine* machine){machine->setState(new MenuState());});
        }
    }
}
MergeState::~MergeState(){
    delete _btn;
}