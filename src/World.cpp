#include "World.hpp"





    World::World( Pacman * pacman, const vector<Ghost *> & ghosts ,   Graphe<Peinture,InfoSommet> * graphe )
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
     Graphe< Peinture,InfoSommet> * World::getLaby() const{
        return laby;
    } ;

      void World::moveGhosts()const {
         vector<Ghost * >::const_iterator it ;
        for (it=ghosts.begin(); it != ghosts.end() ; it++){
            (*it)->move();

        }
    }
     void World::checkCollision()const{
        vector<Ghost * >::const_iterator it ;
        for (it=ghosts.begin(); it != ghosts.end() ; it++){
            hero->check(*it);
        }
    }