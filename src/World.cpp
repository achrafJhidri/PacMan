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
          if ( niveau == 1 ){
         vector<Ghost * >::const_iterator it ;
        for (it=ghosts.begin(); it != ghosts.end() ; it++){
            (*it)->moveRandom();

        }
          }
          else
          {
              vector<Ghost * >::const_iterator it ;
        for (it=ghosts.begin(); it != ghosts.end() ; it++){
            Orientation o = DynamicGameElement::vaVersOrientation(*(hero->position),*((*it)->position));
            (*it)->moveNiveau2(o);

        }
          }
    }
     void World::checkCollision()const{
        vector<Ghost * >::const_iterator it ;
        for (it=ghosts.begin(); it != ghosts.end() ; it++){
            hero->check(*it);
        }
    }

    void World::resetContent() {
	PElement<Sommet<InfoSommet>> *xs;
        for (xs = this->getLaby()->lSommets; xs != nullptr; xs = xs->s) {
	    Sommet<InfoSommet> *s = xs->v;
	    s->pacGomme = true;
        }
    }
