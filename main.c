#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PokemonNode {

  char name[20]; //pokemon's name
  char type[20]; //pokemon's type
  char ability[20]; //pokemon's primary ability
  struct PokemonNode *next; //next pokemon in the list

} PokemonNode;

typedef struct PlayerNode {

  char name[20]; //player's name
  int count; //count of pokemon owned
  PokemonNode* PokemonArray[20]; //array of pointers to pokemon the player owns
  struct PlayerNode *next; //next player in the list

} PlayerNode;

typedef struct Pokedex {

  PokemonNode *PokemonHead; //head of the pokemon list
  PlayerNode *PlayerHead; //head of the player list

} Pokedex;

//function declarations
PokemonNode* NewPokemonNode(char nameNew[20], char typeNew[20], char abilityNew[20]);
PlayerNode* NewPlayerNode(char nameNew[20]);
void AddPokemonNodeToList(Pokedex *pokedex, char nameNew[20], char typeNew[20], char abilityNew[20]);
void AddPlayerNodeToList(Pokedex *pokedex, char nameNew[20]);
PokemonNode* FindPokemon(Pokedex *pokedex, char nameSearch[20]);
PlayerNode* FindPlayer(Pokedex *pokedex, char nameSearch[20]);
void AddPokemonToPlayer(Pokedex *pokedex, char PokemonName[20], char PlayerName[20]);
void DisplayPokemonDetails(Pokedex *pokedex, char nameSearch[20]);
void DisplayPlayerDetails(Pokedex *pokedex, char nameSearch[20]);
void ListPokemon(Pokedex pokedex);
void ListPlayers(Pokedex pokedex);

int main(void) {

  Pokedex pokedex = {0}; //create a pokedex with NULL pointers

  //add 20 pokemon to the pokemon list using the address of "pokedex"
  AddPokemonNodeToList(&pokedex, "Bulbasaur", "Grass", "Overgrow");
  AddPokemonNodeToList(&pokedex, "Charmander", "Fire", "Blaze");
  AddPokemonNodeToList(&pokedex, "Squirtle", "Water", "Torrent");
  AddPokemonNodeToList(&pokedex, "Caterpie", "Bug", "Shield Dust");
  AddPokemonNodeToList(&pokedex, "Weedle", "Bug", "Shield Dust");
  AddPokemonNodeToList(&pokedex, "Pidgey", "Normal", "Keen Eye");
  AddPokemonNodeToList(&pokedex, "Rattata", "Normal", "Guts");
  AddPokemonNodeToList(&pokedex, "Oddish", "Grass", "Chlorophyll");
  AddPokemonNodeToList(&pokedex, "Jigglypuff", "Normal", "Cute Charm");
  AddPokemonNodeToList(&pokedex, "Diglett", "Ground", "Sand Veil");
  AddPokemonNodeToList(&pokedex, "Meowth", "Normal", "Pickup");
  AddPokemonNodeToList(&pokedex, "Psyduck", "Water", "Damp");
  AddPokemonNodeToList(&pokedex, "Growlithe", "Fire", "Intimidate");
  AddPokemonNodeToList(&pokedex, "Abra", "Psychic", "Inner Focus");
  AddPokemonNodeToList(&pokedex, "Tentacool", "Water", "Clear Body");
  AddPokemonNodeToList(&pokedex, "Geodude", "Rock", "Rock Head");
  AddPokemonNodeToList(&pokedex, "Ponyta", "Fire", "Run Away");
  AddPokemonNodeToList(&pokedex, "Onix", "Rock", "Rock Head");
  AddPokemonNodeToList(&pokedex, "Exeggcute", "Grass", "Chlorophyll");
  AddPokemonNodeToList(&pokedex, "Magikarp", "Water", "Swift Swim");

  //add 10 players to the player list
  AddPlayerNodeToList(&pokedex, "John");
  AddPlayerNodeToList(&pokedex, "Sam");
  AddPlayerNodeToList(&pokedex, "Daniel");
  AddPlayerNodeToList(&pokedex, "Jimmy");
  AddPlayerNodeToList(&pokedex, "Joe"); 
  AddPlayerNodeToList(&pokedex, "Georgina"); 
  AddPlayerNodeToList(&pokedex, "Joeseph"); 
  AddPlayerNodeToList(&pokedex, "Ciaran"); 
  AddPlayerNodeToList(&pokedex, "Matt"); 
  AddPlayerNodeToList(&pokedex, "Jenny"); 

  //add 3 pokemon to each player
  AddPokemonToPlayer(&pokedex, "Tentacool", "John");
  AddPokemonToPlayer(&pokedex, "Jigglypuff", "John");
  AddPokemonToPlayer(&pokedex, "Onix", "John");

  AddPokemonToPlayer(&pokedex, "Onix", "Sam");
  AddPokemonToPlayer(&pokedex, "Diglett", "Sam");
  AddPokemonToPlayer(&pokedex, "Squirtle", "Sam");

  AddPokemonToPlayer(&pokedex, "Meowth", "Daniel");
  AddPokemonToPlayer(&pokedex, "Psyduck", "Daniel");
  AddPokemonToPlayer(&pokedex, "Exeggcute", "Daniel");

  AddPokemonToPlayer(&pokedex, "Rattata", "Jimmy");
  AddPokemonToPlayer(&pokedex, "Weedle", "Jimmy");
  AddPokemonToPlayer(&pokedex, "Ponyta", "Jimmy");

  AddPokemonToPlayer(&pokedex, "Squirtle", "Joe");
  AddPokemonToPlayer(&pokedex, "Charmander", "Joe");
  AddPokemonToPlayer(&pokedex, "Pidgey", "Joe");

  AddPokemonToPlayer(&pokedex, "Magikarp", "Georgina");
  AddPokemonToPlayer(&pokedex, "Psyduck", "Georgina");
  AddPokemonToPlayer(&pokedex, "Bulbasaur", "Georgina");

  AddPokemonToPlayer(&pokedex, "Geodude", "Joeseph");
  AddPokemonToPlayer(&pokedex, "Weedle", "Joeseph");
  AddPokemonToPlayer(&pokedex, "Exeggcute", "Joeseph");

  AddPokemonToPlayer(&pokedex, "Squirtle", "Ciaran");
  AddPokemonToPlayer(&pokedex, "Growlithe", "Ciaran");
  AddPokemonToPlayer(&pokedex, "Bulbasaur", "Ciaran");

  AddPokemonToPlayer(&pokedex, "Magikarp", "Matt");
  AddPokemonToPlayer(&pokedex, "Psyduck", "Matt");
  AddPokemonToPlayer(&pokedex, "Rattata", "Matt");

  AddPokemonToPlayer(&pokedex, "Oddish", "Jenny");
  AddPokemonToPlayer(&pokedex, "Psyduck", "Jenny");
  AddPokemonToPlayer(&pokedex, "Exeggcute", "Jenny");
 
  //list all players and pokemon in the lists
  ListPokemon(pokedex);
  printf("\n");
  ListPlayers(pokedex);
  printf("\n");

  //show details of 3 pokemon
  DisplayPokemonDetails(&pokedex, "Charmander");
  printf("\n");
  DisplayPokemonDetails(&pokedex, "Onix");
  printf("\n");
  DisplayPokemonDetails(&pokedex, "Ponyta");
  printf("\n");

  //show details of 3 players
  DisplayPlayerDetails(&pokedex, "Daniel");
  printf("\n");
  DisplayPlayerDetails(&pokedex, "Georgina");
  printf("\n");
  DisplayPlayerDetails(&pokedex, "Matt");
  printf("\n");

  return 0;
}

PokemonNode* NewPokemonNode(char nameNew[20], char typeNew[20], char abilityNew[20]){

  PokemonNode *New_Pokemon = NULL; //create the pointer to the new node and allocate memory
  New_Pokemon =malloc(sizeof(PokemonNode)); 
  if (New_Pokemon != NULL){
    strcpy(New_Pokemon->name,nameNew); //copy in the details
    strcpy(New_Pokemon->type,typeNew);
    strcpy(New_Pokemon->ability,abilityNew);
  }
  return New_Pokemon;
}

PlayerNode* NewPlayerNode(char nameNew[20]){

  PlayerNode *New_Player = NULL; //create the pointer to the new node and allocate memory
  New_Player =malloc(sizeof(PlayerNode));
  if (New_Player != NULL){
    strcpy(New_Player->name,nameNew); //copy in the details
    New_Player->count = 0; //set count to 0 and leave the pokemon array empty
  }
  return New_Player;
}

void AddPokemonNodeToList(Pokedex *pokedex, char nameNew[20], char typeNew[20], char abilityNew[20]){

  if (pokedex->PokemonHead != NULL){ //if there are items in the list, check the list for the same name
    PokemonNode *tempSearch = pokedex->PokemonHead;

    while(strcmp(tempSearch->name, nameNew) != 0 && tempSearch->next != NULL){
      tempSearch = tempSearch->next;
    }

    if(strcmp(tempSearch->name, nameNew) == 0){ //if the name exists, return early and do nothing
      return;
    }
  }

  PokemonNode *New_Pokemon = NewPokemonNode(nameNew, typeNew, abilityNew); //create the new node
  PokemonNode *temp = pokedex->PokemonHead; //create a temp node to traverse the list

  if (pokedex->PokemonHead == NULL){ //if the list is empty, make the new pokemon the head
    pokedex->PokemonHead = New_Pokemon;
    return;
  }

  while (temp->next != NULL){ //traverse to the end of the list
    temp = temp->next;
  }

  temp->next = New_Pokemon; //link the new pokemon to the end of the list

  return;
}

void AddPlayerNodeToList(Pokedex *pokedex, char nameNew[20]){

  if (pokedex->PlayerHead != NULL){ //if there are items in the list, check the list for the same name
    PlayerNode *tempSearch = pokedex->PlayerHead;

    while(strcmp(tempSearch->name, nameNew) != 0 && tempSearch->next != NULL){
      tempSearch = tempSearch->next;
    }

    if(strcmp(tempSearch->name, nameNew) == 0){ //if the name exists, return early and do nothing
      return;
    }
  }

  PlayerNode *New_Player = NewPlayerNode(nameNew); //create the new node
  PlayerNode *temp = pokedex->PlayerHead; //create a temp node to traverse the list

  if (pokedex->PlayerHead == NULL){ //if the list is empty, make the new player the head
    pokedex->PlayerHead = New_Player;
    return;
  }

  while (temp->next != NULL){ //traverse to the end of the list
    temp = temp->next;
  }

  temp->next = New_Player; //link the new pokemon to the end of the list

  return;
}

PokemonNode* FindPokemon(Pokedex *pokedex, char nameSearch[20]){

  if (pokedex->PokemonHead == NULL){ //if the list is empty, return NULL
    return NULL;
  }

  PokemonNode *temp = pokedex->PokemonHead; //create a temp node to traverse the list

  while(strcmp(temp->name, nameSearch) != 0 && temp->next != NULL){ //check the list for the same name
    temp = temp->next;
  }

  if(strcmp(temp->name, nameSearch) == 0){ //if the name matches, return the current node
    return temp;
  }
  return NULL;
}

PlayerNode* FindPlayer(Pokedex *pokedex, char nameSearch[20]){ 

  if (pokedex->PlayerHead == NULL){ //if the list is empty, return NULL
    return NULL;
  }

  PlayerNode *temp = pokedex->PlayerHead; //create a temp node to traverse the list

  while(strcmp(temp->name, nameSearch) != 0 && temp->next != NULL){ //check the list for the same name
    temp = temp->next;
  }

  if(strcmp(temp->name, nameSearch) == 0){ //if the name matches, return the current node
    return temp;
  }
  return NULL;
}

void AddPokemonToPlayer(Pokedex *pokedex, char PokemonName[20], char PlayerName[20]){

  if (pokedex->PlayerHead == NULL){ //if the list is empty, do nothing
    return;
  }

  PlayerNode *tempPlayer = pokedex->PlayerHead; //create a temp node to traverse the player list

  while(strcmp(tempPlayer->name, PlayerName) != 0 && tempPlayer->next != NULL){ //find the correct player
    tempPlayer = tempPlayer->next;
  }

  if(strcmp(tempPlayer->name, PlayerName) == 0){ //if we find the correct player, continue

    PokemonNode *tempPokemon = pokedex->PokemonHead; //create a temp node to traverse the pokemon list

    while(strcmp(tempPokemon->name, PokemonName) != 0 && tempPokemon->next != NULL){ //find the correct pokemon
      tempPokemon = tempPokemon->next;
    }

    if(strcmp(tempPokemon->name, PokemonName) == 0){  //if we find the correct pokemon, continue

      for(int i = 0; i < tempPlayer->count; i++){ //if the the player already has the pokemon, do nothing
        PokemonNode *tempPokemonName = tempPlayer->PokemonArray[i];
        if (strcmp(tempPokemonName->name, PokemonName) == 0){ 
          return;
        }
      }
      
      tempPlayer->PokemonArray[tempPlayer->count] = tempPokemon; //add the pokemon and increase the player's count
      tempPlayer->count++;
    }
    return;
  }
  return;
}

void DisplayPokemonDetails(Pokedex *pokedex, char nameSearch[20]){

  if (pokedex->PokemonHead == NULL){ //if the list is empty, do nothing
    return;
  }

  PokemonNode *temp = pokedex->PokemonHead; //create a temp node to traverse the list

  while(strcmp(temp->name, nameSearch) != 0 && temp->next != NULL){ //check the list for the same name or the end
    temp = temp->next;
  }

  if(strcmp(temp->name, nameSearch) == 0){ //if the name matches, display the current pokemon node's details
    printf("Name: %s\nType: %s\nAbility: %s\n",temp->name,temp->type,temp->ability);
  }
  return;
}

void DisplayPlayerDetails(Pokedex *pokedex, char nameSearch[20]){

  if (pokedex->PlayerHead == NULL){ //if the list is empty, do nothing
    return;
  }

  PlayerNode *temp = pokedex->PlayerHead; //create a temp node to traverse the list

  while(strcmp(temp->name, nameSearch) != 0 && temp->next != NULL){ //check the list for the same name or the end
    temp = temp->next;
  }

  if(strcmp(temp->name, nameSearch) == 0){ //if the name matches, display the current player node's details
    printf("Name: %s\nPokemon Count: %i\nPokemon: ", temp->name, temp->count);
    for(int i = 0; i < temp->count; i++){
      PokemonNode *tempPokemon = temp->PokemonArray[i]; //iterate through the player's pokemon array and display
      printf("%s, ", tempPokemon->name);
    }
  }
  printf("\n");
  return;
}

void ListPokemon(Pokedex pokedex){

  PokemonNode *ptr = pokedex.PokemonHead; //create a pointer to the head of the list

  while(ptr != NULL){ //iterate through the list and display each node's name
    printf("%s\n",ptr->name);
    ptr = ptr->next;
  }
}

void ListPlayers(Pokedex pokedex){ 

  PlayerNode *ptr = pokedex.PlayerHead; //create a pointer to the head of the list

  while(ptr != NULL){ //iterate through the list and display each node's name
    printf("%s\n",ptr->name);
    ptr = ptr->next;
  }
}
