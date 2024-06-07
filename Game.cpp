#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SinglyLinkedNode.h"
#include "SinglyLinkedNodeIterator.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"
#include "DoublyLinkedList.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"
#include "Game.h"

int main()
{

    srand(time(NULL)); //generate rand seed

    Game g;//Create Game object
    g.game_start();//call for function starting the game

    return 0;
}



