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

void mergesort(std::vector<sf::RectangleShape> &arr,int left ,int elements){
    int end = left + 2 * elements;
    int middle = elements + left;
    std::vector<sf::RectangleShape> tmpArr;
    std::vector<sf::RectangleShape> tmpArr2;
    for(int i=0;i<elements;i++){
        if(left+i<20){
            tmpArr.push_back(arr.at(left+i));
        }
    }
    if(end>=20){
        if(middle>=20){
            return;
        }else{
           for(int i=0;i<elements;i++){
               if(middle+i<20){
                   tmpArr2.push_back(arr.at(middle+i));
               }
           } 
        }
    }else{
        for(int i=0;i<elements;i++){
            if(middle+i<20){
                tmpArr2.push_back(arr.at(middle+i));
            }
        }
    }
    std::vector<sf::RectangleShape> sorted;
    while(!tmpArr.empty() && !tmpArr2.empty()){
        if(tmpArr.front().getPosition().y>tmpArr2.front().getPosition().y){
            sorted.push_back(tmpArr.front());
            tmpArr.erase(tmpArr.cbegin());
        }else{
            sorted.push_back(tmpArr2.front());
            tmpArr2.erase(tmpArr2.cbegin());
        }
    }
    while(!tmpArr.empty()){
        sorted.push_back(tmpArr.front());
        tmpArr.erase(tmpArr.cbegin());
    }
    while(!tmpArr2.empty()){
        sorted.push_back(tmpArr2.front());
        tmpArr2.erase(tmpArr2.cbegin());
    }
    for(int i=0;i<sorted.size();i++){
        sorted.at(i).setPosition(100 + 30*left + 30*i, sorted.at(i).getPosition().y);
    }
    for(int i=0;i<sorted.size();i++){
        arr.at(left+i)=sorted.at(i);
    }
}

void MergeState::update(Machine* machine){
    _btn->hover(machine->getWindow());

    for(int i=_arrSize;i<20;i=i*2){
        for(int j=0;j<20;j=j+2*i){
            mergesort(_rect, j, i);
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