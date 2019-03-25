#include "World.hpp"





    World::World( Pacman * pacman, const vector<Ghost *> & ghosts ,   Graphe<InfoArete,InfoSommet> * graphe )
    :hero(pacman),ghosts(ghosts),laby(graphe){
            
    }
     World::~World(){
    
    };

     Pacman *World::getHero() const {
        return hero;
    };
    const vector<Ghost *> & World::getGhosts()const   {
        return ghosts;
    }; 
     Graphe< InfoArete,InfoSommet> * World::getLaby() const{
        return laby;
    } ;

    void World::moveGhosts(int niveau)const {
          if ( niveau == 1 ) // Random
          {
                vector<Ghost * >::const_iterator it ;
                for (it=ghosts.begin(); it != ghosts.end() ; it++)
                    (*it)->moveRandom();    
          }
          else if ( niveau == 2) // Serpent
          {
                vector<Ghost * >::const_iterator it ;
                for (it=ghosts.begin(); it != ghosts.end() ; it++)
                {
                    Orientation o = DynamicGameElement::vaVersOrientation(*(hero->position),*((*it)->position));
                    if (o != Orientation::NONE )
                        (*it)->moveNiveau2(o);
                    else
                        (*it)->moveRandom(); 
                }
          }
          else // Astar
          {
                vector<Ghost * >::const_iterator it ;
                OutilsCarte::cible = hero->position;
                //cout << hero->position->v.vSommet<< endl ;
                for (it=ghosts.begin(); it != ghosts.end() ; it++)
                {
                    AStarT< Graphe<InfoArete,InfoSommet>,Sommet<InfoSommet> >::aStar( *laby, (*it)->position,  OutilsCarte::hh);
                    PElement<Sommet<InfoSommet>> * c;
                    chemin(hero->position,c);	
                    (*it)->position=c->s->v;
                    c = nullptr;
                    delete c ;
                }
           }
        }
    void World::checkCollision()const{
        vector<Ghost * >::const_iterator it ;
        for (it=ghosts.begin(); it != ghosts.end() ; it++){
            hero->check(*it);
        }
    }

    void World::resetContent() 
    {
	    PElement<Sommet<InfoSommet>> *xs;
        for (xs = this->getLaby()->lSommets; xs != nullptr; xs = xs->s) {
	    Sommet<InfoSommet> *s = xs->v;
	    s->pacGomme = true;
        }
        xs = NULL ;
        delete xs ;
    }
