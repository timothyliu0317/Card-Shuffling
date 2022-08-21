#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "card.cpp"
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;


 


card::card(int a ,int b)
{
            face = b ;
            suit = a ;
}




string card::tostring() 
{
static const char *faces[13]=
{"ace","deuce","three","four","five","six","seven","eight","nine","ten","jack","queen",
"king"};
static const char *suits[4]=
{" hearts","diamonds","clubs","spades"};
             
         string a(faces[face]);
         string b(suits[suit]) ;   
        return   a+" of "+b    ;
}



     

class deckofcards
{
    public:
        vector<card> cards;
       
     int currentcard; 
     
        deckofcards()
        {
            
         for (int i=0;i < 13 ; i++)
         {cards.push_back(card(0,i));}
         for (int i=13;i < 26  ;i++)
         {cards.push_back(card(1,i-13));}
         for (int i=26;i < 39  ;i++)
         {cards.push_back(card(2,i-26));}
         for (int i=39;i < 52  ;i++)
         {cards.push_back(card(3,i-39));}
         
         currentcard=0;
         }
         
         void shuffle()
         {for (int i=currentcard;i<52;i++)
              {int change = rand()%(52-currentcard)+currentcard;
              card hold = cards[i];
              cards[i] = cards[change];
              cards[change] = hold;
               }
         }   
               
         card dealcard()
         {currentcard++;
         return cards[currentcard-1];
         }
        
         
         bool morecards()
         { if (currentcard < 52) 
              return true;
          else 
              return false;
          }
                  
};

int main()
{ deckofcards x;
  cout<<"before shuffling"<<endl;
  for (int i=0;i<52;i++)
  {cout<<x.cards[i].tostring()<<endl;
  }
  cout<<endl;
  x.shuffle();
  cout<<"after shuffling"<<endl;
  
  while (x.morecards())
  {cout<<x.dealcard().tostring()<<endl;
  }
}
