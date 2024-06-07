#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "DoublyLinkedList.h"
#include "Item.h"
#include "GameMap.h"
#include "DynamicArray.h"
#include "Tree.h"
#include "DoublyLinkedNodeIterator.h"

using namespace std;

//Game Introduction
const string game_introduce = "\t\t--------------------------------------------------------------------------------------\n"\
"\t\tYou were on a plane heading towards a tropical island for a vacation.\n"\
"\t\tSuddenly the plane encountered attacks from unknown sources and had crashed terribly.\n"\
"\t\tEveryone on the plane had unfortunately deceased and you were the only survivor.\n"\
"\t\t--------------------------------------------------------------------------------------\n"\


"\t\t--------------------------------------------------------------------------------------\n\n"\
"\t\tUpon waking up, you found yourself stranded alone on an isolated island.\n"\
"\t\tWithin your sight was a wooden signboard carved with the words:\n"\
"\t\tWelcome to the Devil's Island\n"\
"\t\t--------------------------------------------------------------------------------------\n";

//Level Introduction
const string level_introduce = "\t\t---Level Introduction---\n"\
"\t\tYou will be encountering extreme climates and deadly beasts randomly.\n"\
"\t\tDefeat the beasts and survive the weathers to make your way out of the island alive\n"
"\t\tKilling beasts earn you gold and you could use them to purchase from the shop\n"
"\t\tThe longer you survived, the more perilous it could be so watch out!\n";

const string show_help = "\t\tType \"Help\" to show Command Menu";

//Storing game menu strings
const string game_menus[] = {
	"g. Show Game Introduction",
	"s. Start a New Game",
	"l. Load an Old Game",
	"a. View all saved games",
	"h. Game history",
	"e. Exit Game"
};

//Storing menu keys strings
const string menu_keys[] = {
	"g",
	"s",
	"l",
	"a",
	"h",
	"e"
};

//Storing command keys strings
const string command_keys[] = {
	"Help",
	"Enemy",
	"Me",
	"Shop",
	"Bag",
	"Attack",
	"Escape",
	"Drop",
	"Exit"
};

//Help in Commands
const string command_help = "\t\t--------------------------------\n"\
"\t\tHelp: Show Help\n"\
"\t\tEnemy: Show Enemy Status\n"\
"\t\tMe: Show My Status\n"\
"\t\tShop: Enter Shop\n"\
"\t\tBag: Open Bag\n"\
"\t\tAttack: Attack\n"\
"\t\tEscape: Escape\n"\
"\t\tDrop: Drop Armor\n"\
"\t\tExit: Exit Game";

//Storing shop keys strings
const string shop_keys[]{
	"Help",
	"Next",
	"Previous",
	"Buy",
	"Exit"
};

//Help Menu in the shop
const string shop_help = "\t\t--------------------------------\n"\
"\t\tHelp: Show Help Menu\n"\
"\t\tNext: Next Item\n"\
"\t\tPrevious: Previous Item\n"\
"\t\tBuy: Buy Item\n"\
"\t\tExit: Exit shop";

//Storing bag keys strings
const string bag_keys[]{
	"Help",
	"List",
	"Use Number",
	"Exit"
};
const string bag_key_use_first_word = "Use";

//Help Menu in bag
const string bag_help = "\t\t--------------------------------\n"\
"\t\tHelp: Show Help Menu\n"\
"\t\tList: List All Items In the Bag\n"\
"\t\tUse Numbers: For Example 'Use 3' for Accessing the Third Item\n"\
"\t\tExit: Exit Bag";

const string shop_first_item = "\t\tThis is the First Item\n";
const string shop_last_item = "\t\tThis is the Last Item\n";

const string escape_fail = "\t\tYou failed in escaping, game over!\n";
const string escape_success = "\t\tCongratulations! You had successfully escaped! .\n";

const string character_name_command = "Enter character name: ";
const string game_command = "\n\nEnter your command >>>";
const string error_command = "\t\tError command";
const string exit_game_command = "\t\tAre you sure you want to exit the game(Y/N):";
const string save_game_command = "\t\tDo you want to save the game(Y/N):";
const string buy_item_success = "\t\tYou bought ";
const string buy_item_fail = "\t\tYou dont have enough gold to buy: ";
const string exit_shop_command = "\t\tYou exited the shop";
const string use_item_success = "\t\tYou used ";
const string exit_bag_command = "\t\tYou exited the bag";
const string naturaldisaster_escape = "\t\tUnable to attack the weather, escape for your live!\n";
const string nothing_inshop = "\t\tThe shop is empty\n";
const string nothing_inbag = "\t\tThe bag is empty\n";

const string game_level_win = "\t\tYou won the level\n\n";
const string game_level_lose = "\t\tYou lost the level, game over!\n";

const string drop_item_success = "\t\tYou Dropped: ";
const string drop_item_fail = "\t\tYou are not wearing any armor at the moment";

//Storing navigation keys strings
const string move_keys[]{
	"Help",
	"Turn Left",
	"Turn Right",
	"Exit"
};

//Navigation Help Menu
const string move_help = "\t\t--------------------------------\n"\
"\t\tHelp: Show Help Menu\n"\
"\t\tTurn Left: Chooses the Left Path\n"\
"\t\tTurn Right: Chooses the Right Path\n"\
"\t\tExit: Exit Game";
const string next_level_command = "\t\tWhich turn are you taking?\n";

const string game_win = "\t\tYou won the game.\n";

const string earn_gold_first = "\t\tYou earned ";
const string earn_gold_last = " golds from this combat\n";

const string save_game_name = "Enter the name you want to save your game as: ";
const string load_game_name = "Enter the name of the game you want to load: ";

const string save_game_sucess = "\t\tGame successfully saved\n";
const string save_game_fail = "\t\tFailed to save game\n";

const string load_game_fail = "\t\tFailed to load game\n";
const string game_list_empty = "\t\tNo saved game is found\n";

const string no_game_history = "\t\tNo game history is found\n";

const string overwrite_saved_game = "\t\tThere is already a saved game with the same name. Do you want to overwrite it(Y/N):";

//Storing shop items
const Item items[] = {
	Item("PainKiller", 10, 20, itCure),
	Item("Serotonin", 20, 30, itCure),
	Item("Rock", 10, 20, itAttack),
	Item("Arrow", 20, 40, itAttack),
	Item("Blade", 30, 60, itAttack),
	Item("Vest", 10, 20, itArmor),
	Item("Helmet", 20, 30, itArmor),
	Item("Boots", 50, 20, itSpeed),
	Item("Rubber gloves", 10, 20, itInsulates),
	Item("Antibiotic", 10, 20, itAntitoxic)
};

const int max_gold = 50;
const int map_count = 10;

//Storing names of the different maps
const string map_name[map_count] = {
	"Tornado",
	"Forest Fire",
	"Thunderstorm",
	"Piranha",
	"Sun Bear",
	"Jaguar",
	"Electric Eel",
	"Stingray",
	"Poison Dart Frog",
	"Spider"
};

struct History
{
	string name;
	int level;
	int experience;
	bool pass;
};

class Game
{
private:
	int level;
	List<Item>* shop;//Shop
	DynamicArray<int> map_index;//Index for the maps
	BTree<GameMap>* game_map_root;
	BTree<GameMap>* current_map;
public:
	//Default Constructor
	Game() : level(0), map_index(map_count), game_map_root(&BTree<GameMap>::NIL),
		current_map(&BTree<GameMap>::NIL)
	{
		shop = new DoublyLinkedList<Item>;
	}

	//Destructor
	~Game()
	{
		delete shop;
		game_map_root->detach_all(game_map_root);
		game_map_root = current_map = &BTree<GameMap>::NIL;
	}
private:
	//Game Introduction
	void game_intro()
	{
		cout << game_introduce;
	}

	//Display Main Menu
	void game_menu()
	{
		cout << "\n\n";
		for (string s : game_menus)
			cout << s << endl;
	}

	//Initialize the shop
	void init_shop()
	{
		//load the shop with items
		for (Item it : items)
			shop->push_back(it);
	}

	//Initialize the map
	void init_map(int direction = 0) //0-root 1-left 2-right
	{
		if (map_index.size() > 0)
		{
			//randomly select an index number, restricted to the range of the available map index
			int aIndex = rand() % map_index.size();
			int index = map_index[aIndex];
			map_index.remove(aIndex);

			GameMap* gmap;
			EnemyType eType;
			//First three maps in the array are the maps with weather enemies
			if (index < 3)
				eType = etNaturalDisaster;
			//Maps with normal enemy
			else if (index < 6)
				eType = etEnemy;
			//Maps with electrical enemy
			else if (index < 8)
				eType = etElectric;
			//Maps with poisonous enemy
			else
				eType = etPoisonous;
			gmap = new GameMap(map_name[index], index, level, eType);

			if (direction == 0) //root
			{
				game_map_root = new BTree<GameMap>(gmap); //map root
				current_map = game_map_root;
			}
			else if (direction == 1) //left 
			{
				BTree<GameMap>* new_map = new BTree<GameMap>(gmap);
				current_map->attachLeft(new_map);
				current_map = new_map;
			}
			else if (direction == 2) //right
			{
				BTree<GameMap>* new_map = new BTree<GameMap>(gmap);
				current_map->attachRight(new_map);
				current_map = new_map;
			}
		}
	}

	//Start game
	void start(Player& p)
	{
		bool pass;
		while (true)
		{
			cout << level_introduce << endl;

			current_map->key().Map_intro();

			cout << show_help << endl;
			//If the chosen map contains weather enemy
			if (current_map->key().Get_Type() == etNaturalDisaster)
				pass = game_with_naturaldisaster(p, *(current_map->key().Get_NaturalDisaster()));
			else
				//if the chosen map contains beasts enemy
				pass = game_with_enemy(p, *(current_map->key().Get_Enemy()));

			if (!pass)
				break;
			//If all the maps have been used up
			if (map_index.size() == 0)
			{
				cout << game_win;
				save_history(p, true);
				break;
			}

			cout << next_level_command;
			string command;
			while (true)
			{
				cout << game_command;
				getline(cin, command);
				//Player asks for help in navigation command
				if (command == move_keys[0])
					show_move_help();
				//Player chooses to turn left
				else if (command == move_keys[1])
				{
					level++;
					init_map(1);
					break;
				}
				//Player chooses to turn right
				else if (command == move_keys[2])
				{
					level++;
					init_map(2);
					break;
				}
				else
					cout << error_command;
			}
		}
	}

	//Game with beasts
	bool game_with_enemy(Player& p, Enemy& e)
	{
		string command;
		while (true)
		{
			cout << game_command;
			getline(cin, command);
			//Show Command Help Menu
			if (command == command_keys[0])
				show_command_help();
			//Print Enemy Status
			else if (command == command_keys[1])
				e.print();
			//Print Player Status
			else if (command == command_keys[2])
				p.print();
			//Enter shop
			else if (command == command_keys[3])
				enter_shop(p);
			else if (command == command_keys[4])
				open_bag(p);
			//Attack Command
			else if (command == command_keys[5])
			{
				if (e.Is_Alive() && p.Is_Alive())
				{
					//player attacks enemy
					p >> e;
					//if enemy is alive
					if (e.Is_Alive())
						//enemy attacks player too
						e >> p;
					//if player dies
					if (!p.Is_Alive())
					{
						cout << game_level_lose;
						save_history(p, false);
						return false;
					}
					//if player is alive and enemy dies
					if (!e.Is_Alive())
					{
						cout << game_level_win;
						//earn experience
						p.Set_Experience(p.Get_Experience() + e.Get_MaxHP());

						//earn gold, rand() generates a random number but % restricts it to within the range of MaxHP value
						int gold = e.Get_MaxHP() + rand() % e.Get_MaxHP();
						p.Set_Gold(p.Get_Gold() + gold);

						cout << earn_gold_first << gold << earn_gold_last;

						return true;
					}
				}
			}
			//Escape Command
			else if (command == command_keys[6])
			{
				//if enemy's speed is greater than player's speed
				if (e.Get_Speed() > p.Get_Speed())
				{
					cout << escape_fail;
					p.Set_CurrentHP(0);
					return false;
				}
				else
				{
					cout << escape_success;
					return true;
				}
			}
			//Drop Armor
			else if (command == command_keys[7])
				drop_armor(p);
			//If player wants to exit game halfway
			else if (command == command_keys[8])
			{
				cout << exit_game_command;
				string s;
				getline(cin, s);
				if (s == "Y" || s == "y")
				{
					cout << save_game_command;
					getline(cin, s);
					if (s == "Y" || s == "y")
					{
						save_game(p);
					}
					return false;
				}
			}
			else
				cout << error_command;
		}

	}

	//Game with weather enemies
	bool game_with_naturaldisaster(Player& p, NaturalDisaster& n)
	{
		string command;
		while (true)
		{
			cout << game_command;
			getline(cin, command);
			//Show Command Help Menu
			if (command == command_keys[0])
				show_command_help();
			//Print Enemy Status
			else if (command == command_keys[1])
				n.print();
			//Print Player Status
			else if (command == command_keys[2])
				p.print();
			//Enter Shop
			else if (command == command_keys[3])
				enter_shop(p);
			//Open bag
			else if (command == command_keys[4])
				open_bag(p);
			//If player chooses to attack weather enemy, tell them they could only escape
			else if (command == command_keys[5])
				cout << naturaldisaster_escape;
			//If player chooses to escape, calculate the times of attack based on
			//Enemy's distance and player's speed
			else if (command == command_keys[6])
			{
				int count = n.Get_Distance() / p.Get_Speed();
				if (n.Get_Distance() % p.Get_Speed() > 0)
					++count;
				while (count > 0 && p.Is_Alive())
				{
					//Weather enemy attacks player
					n >> p;
					--count;
				}

				if (p.Is_Alive()) //if player wins
				{
					//earn experience
					p.Set_Experience(p.Get_Experience() + n.Get_Damage());
					//earn gold
					int gold = n.Get_Damage() + rand() % n.Get_Damage();
					p.Set_Gold(p.Get_Gold() + gold);
					cout << escape_success;
					cout << earn_gold_first << gold << earn_gold_last;

					return true;
				}
				else
				{
					cout << escape_fail;
					save_history(p, false);
					return false;
				}
			}
			//Drop armor
			else if (command == command_keys[7])
				drop_armor(p);
			//If player wants to exit game halfway
			else if (command == command_keys[8])
			{
				cout << exit_game_command;
				string s;
				getline(cin, s);
				if (s == "Y" || s == "y")
				{
					cout << save_game_command;
					getline(cin, s);
					if (s == "Y" || s == "y")
					{
						save_game(p);
					}
					return false;
				}
			}
			else
				cout << error_command;
		}

	}

	//Enter shop
	void enter_shop(Player& p)
	{
		DoublyLinkedNodeIterator<Item> it =dynamic_cast<DoublyLinkedList<Item>*>(shop)->begin();
		if (it != it.end())
		{
			it.getCurrent()->getValue().print();
			string command;
			while (true)
			{
				cout << game_command;
				getline(cin, command);
				//Show Shop Command Help Menu 
				if (command == shop_keys[0])
					show_shop_help();
				else if (command == shop_keys[1])
				{//Using iterator to loop through shop items (Next item)
					DoublyLinkedNodeIterator<Item> tmp = it;
					if (++tmp != it.end())
					{
						it = tmp;
						it.getCurrent()->getValue().print();
					}
					else
						cout << shop_last_item;
				}
				else if (command == shop_keys[2])
				{//(Previous item)
					if (it != dynamic_cast<DoublyLinkedList<Item>*>(shop)->begin())
					{
						--it;
						it.getCurrent()->getValue().print();
					}
					else
						cout << shop_first_item;
				}
				else if (command == shop_keys[3])
				{//Buy an item
					if (p.buy(it.getCurrent()->getValue()))
						cout << buy_item_success << it.getCurrent()->getValue().Get_Name();
					else
						cout << buy_item_fail << it.getCurrent()->getValue().Get_Name();
				}
				else if (command == shop_keys[4])
				{//Exit shop
					cout << exit_shop_command;
					break;
				}
				else
					cout << error_command;
			}
		}
		else
			cout << nothing_inshop;
	}

	// Function to open the player's bag and interact with its contents
	void open_bag(Player& p)
	{
		// Check if the player's bag is not empty
		if (p.Get_Bag()->size() > 0)
		{
			// Print the contents of the player's bag
			p.print_bag();

			// Command input loop
			string command;
			while (true)
			{
				// Prompt the user for a command
				cout << game_command;
				getline(cin, command);

				// Check for different commands
				if (command == bag_keys[0])
					show_bag_help(); // Display help for bag commands
				else if (command == bag_keys[1])
				{
					// Show the contents of the bag again
					if (p.Get_Bag()->size() > 0)
						p.print_bag();
					else
						cout << nothing_inbag;
				}
				else if (command.find(bag_key_use_first_word) == 0)
				{
					// Extract and process the "use" command with an index
					command = command.erase(0, 3);
					command = command.erase(0, command.find_first_not_of(" \t\v"));
					command = command.erase(command.find_last_not_of(" \t\v") + 1);
					int index = atoi(command.c_str());
					Item item;

					// Attempt to use the item at the specified index
					if (p.uses(index, item))
						cout << use_item_success << item.Get_Name() << endl;
					else
						cout << error_command;
				}
				else if (command == bag_keys[3])
				{
					cout << exit_bag_command; // Display exit bag command
					break; // Exit the bag command loop
				}
				else
					cout << error_command; // Display an error message for unrecognized commands
			}
		}
		else
			cout << nothing_inbag; // Display a message if the bag is empty
	}


	void drop_armor(Player& p)
	{
		Item item;
		if (p.drop(item))
			cout << drop_item_success << item.Get_Name();
		else
			cout << drop_item_fail;
	}

	//Command Help Menu
	void show_command_help()
	{
		cout << command_help << endl;
	}

	//Shop Help Menu
	void show_shop_help()
	{
		cout << shop_help << endl;
	}

	//Bag Help Menu
	void show_bag_help()
	{
		cout << bag_help << endl;
	}

	//Navigation Help Menu
	void show_move_help()
	{
		cout << move_help << endl;
	}

	void new_game()
	{
		string name;
		cout << character_name_command;
		getline(cin, name);

		cout << endl;
		cout << "\t\tHello " << name << endl;
		//1.generate a new player
		Player p(name);

		//2.generate shops
		init_shop();

		//3.generate map, the map is a tree now the player is at the root of tree
		for (int i = 0; i < map_count; i++)
			map_index.add(i);

		//4. init game level
		level = 1;

		//5. init game map
		init_map();

		//6.start
		start(p);

		//7.delete map
		game_map_root->detach_all(game_map_root);
		game_map_root = current_map = &BTree<GameMap>::NIL;
	}

	void save_game(Player& p)
	{
		cout << save_game_name;
		string filename;
		getline(cin, filename);

		bool iscover = false;
		ifstream iFile;
		iFile.open(filename);
		if (iFile.good())
		{
			cout << overwrite_saved_game;
			string s;
			getline(cin, s);
			if (s == "Y" || s == "y")
			{
				iscover = true;
			}
			else
			{
				//to not save 2 files with the exact same name
				filename = filename + "(2)";

			}
		}


		ofstream oFile;
		oFile.open(filename);
		//checks if the file is successfully opened
		if (oFile.good())
		{
			//1. save player
			oFile << p;


			//2. save bag
			oFile << p.Get_Bag()->size() << endl;
			for (auto it = dynamic_cast<SinglyLinkedList<Item>*>(p.Get_Bag())->begin(); it != it.end(); it++)
			{
				it.getCurrent()->getValue().save(oFile);
			}

			//3. save armors
			Stack<Item> temp;
			Item item;
			while (p.drop(item))
			{
				temp.push(item);
			}

			oFile << temp.size() << endl;
			while (temp.pop(item))
			{
				oFile << item;
			}

			//4. save current enemy 
			oFile << current_map->key().Get_Type() << endl;
			if (current_map->key().Get_Type() == etNaturalDisaster)
				oFile << *(current_map->key().Get_NaturalDisaster());
			else
				oFile << *(current_map->key().Get_Enemy());

			//5. save Map
			game_map_root->saveBreadthFirst(oFile);

			oFile.close();

			if (!iscover)
			{
				oFile.open("savegame", fstream::app);
				if (oFile.good())
				{
					oFile << filename << "\n";

					oFile.close();
				}
			}

			cout << save_game_sucess;
		}
		else
			cout << save_game_fail;
	}

	void load_game()
	{
		cout << load_game_name;
		string filename;
		getline(cin, filename);

		ifstream iFile;
		iFile.open(filename);

		if (iFile.good())
		{
			string Name;
			int MaxHP, CurrentHP, Attack, Armor, Speed;
			int Gold, Level, Experience, Antitoxic_protected, Insulator_protected;

			getline(iFile, Name);
			iFile >> MaxHP >> CurrentHP >> Attack >> Armor >> Speed
				>> Gold >> Level >> Experience >> Antitoxic_protected >> Insulator_protected;
			//1.generate player
			Player p(Name, MaxHP, CurrentHP, Attack, Armor, Speed,
				Gold, Level, Experience, Antitoxic_protected, Insulator_protected);


			int count;
			//2.generate bag
			iFile >> count;
			string itemName;
			int itemValue, itemGold;
			int itemType;

			for (int i = 0; i < count; i++)
			{
				iFile.ignore();
				getline(iFile, itemName);
				iFile >> itemValue >> itemGold >> itemType;
				Item item(itemName, itemValue, itemGold, ItemType(itemType));
				p.Get_Bag()->pop_back(item);
			}

			//3.generate wears
			iFile >> count;
			for (int i = 0; i < count; i++)
			{
				iFile.ignore();
				getline(iFile, itemName);
				iFile >> itemValue >> itemGold >> itemType;
				Item item(itemName, itemValue, itemGold, ItemType(itemType));
				p.Get_Armors().push(item);
			}

			//4.get eneny info
			string enemyName;
			int enemyLevel, enemyHp;
			int eType;
			iFile >> eType;
			iFile.ignore();
			getline(iFile, enemyName);
			iFile >> enemyLevel;
			if (EnemyType(eType) != etNaturalDisaster)
			{
				iFile >> enemyHp;
			}

			//5.generate map, the map is a tree and now you are at the root of tree
			game_map_root = current_map = &BTree<GameMap>::NIL;

			map_index.delAll();
			for (int i = 0; i < map_count; i++)
				map_index.add(i);

			int mapDirection = -1;
			string mapName;
			int mapIndex, mapLevel, mapType;
			while (iFile >> mapDirection && mapDirection >= 0)
			{
				iFile.ignore();
				getline(iFile, mapName);
				iFile >> mapIndex >> mapLevel >> mapType;

				for (int i = 0; i < map_index.size(); i++)
				{
					if (mapIndex == map_index[i])
						map_index.remove(i);
				}
				//map_index.remove(mapIndex);omg this is killing me

				GameMap* gmap;
				EnemyType eType;
				if (mapIndex < 3)
					eType = etNaturalDisaster;
				else if (mapIndex < 6)
					eType = etEnemy;
				else if (mapIndex < 8)
					eType = etElectric;
				else
					eType = etPoisonous;
				gmap = new GameMap(map_name[mapIndex], mapIndex, mapLevel, eType);

				if (mapDirection == 0) //root
				{
					game_map_root = new BTree<GameMap>(gmap); //map root
					current_map = game_map_root;
				}
				else if (mapDirection == 1) //left 
				{
					BTree<GameMap>* new_map = new BTree<GameMap>(gmap);
					current_map->attachLeft(new_map);
					current_map = new_map;
				}
				else if (mapDirection == 2) //right
				{
					BTree<GameMap>* new_map = new BTree<GameMap>(gmap);
					current_map->attachRight(new_map);
					current_map = new_map;
				}

				mapDirection = -1;
			}
			//6.set enemy info
			if (EnemyType(eType) != etNaturalDisaster)
			{
				current_map->key().Get_Enemy()->Set_CurrentHP(enemyHp);
			}

			//7.generate shops
			init_shop();

			//8.start
			start(p);

			//9.delete map
			game_map_root->detach_all(game_map_root);
			game_map_root = current_map = &BTree<GameMap>::NIL;
		}
		else
			cout << load_game_fail;
	}

	void save_history(Player& p, bool ispass)
	{
		ofstream oFile;
		oFile.open("history",fstream::app);

		if (oFile.good())
		{
			//1. save player
			oFile << p.Get_Name() << "\n" << p.Get_Level() << "\t" << p.Get_Experience() << "\t";
			oFile << (ispass ? 1 : 0)<<"\n";
		}
	}

	void show_all_save_game()
	{
		// Create a queue to store game names
		Queue<string> games;

		// Open the file "savegame" for reading
		ifstream iFile;
		iFile.open("savegame");

		// Check if the file is successfully opened
		if (iFile.good())
		{
			string gamename = "";

			// Read each line from the file and enqueue it into the 'games' queue
			while (getline(iFile, gamename) && gamename.size() > 0)
			{
				games.enqueue(gamename);

				// Reset gamename for the next iteration
				gamename = "";
			}

			iFile.close(); // Close the file

			int count = games.size(); // Get the number of records in the 'games' queue

			// Check if there are records in the 'games' queue
			if (count > 0)
			{
				cout << "\t\t-------------\n";

				// Dequeue and print each game name
				while (!games.isEmpty())
					cout << "\t\t" << games.dequeue() << endl;

				cout << "\t\t-------------\n";
				cout << "\t\t" << count << " record" << (count > 1 ? "s" : "") << endl;
			}
			else
				cout << game_list_empty; // Display a message if the game list is empty
		}
		else
			cout << game_list_empty; // Display a message if the file couldn't be opened
	}

	void game_history()
	{
		// Create a queue to store game history information
		Queue<History> games;

		// Open the file "history" for reading
		ifstream iFile;
		iFile.open("history");

		// Check if the file is successfully opened
		if (iFile.good())
		{
			History his;

			// Read each line from the file and enqueue it into the 'games' queue
			while (getline(iFile, his.name) && his.name.size() > 0)
			{
				iFile >> his.level >> his.experience >> his.pass;

				games.enqueue(his);

				// Reset his.name for the next iteration
				his.name = "";

				iFile.ignore(); // Ignore the newline character after reading 'his.name'
			}

			iFile.close(); // Close the file

			int count = games.size(); // Get the number of records in the 'games' queue

			// Check if there are records in the 'games' queue
			if (count > 0)
			{
				cout << "\t\t-------------------------------------\n";
				cout << "\t\tname\tlevel\texperience\tstate\n";
				cout << "\t\t-------------------------------------\n";

				// Dequeue and print each game history entry
				while (!games.isEmpty())
				{
					his = games.dequeue();
					cout << "\t\t" << his.name << "\t" << his.level << "\t" << his.experience
						<< "\t\t" << (his.pass ? "pass" : "fail") << "\n";
				}

				cout << "\t\t-------------------------------------\n";
				cout << "\t\t" << count << " record" << (count > 1 ? "s" : "") << endl;
			}
			else
				cout << no_game_history; // Display a message if the game history is empty
		}
		else
			cout << no_game_history; // Display a message if the file couldn't be opened
	}


public:
	void game_start()
	{
		string command;
		game_intro();
		while (true)
		{
			game_menu();

			cout << game_command;
			getline(cin, command);
			if (command == menu_keys[0])
				game_intro();
			else if (command == menu_keys[1])
				new_game();
			else if (command == menu_keys[2])
				load_game();
			else if (command == menu_keys[3])
				show_all_save_game();
			else if (command == menu_keys[4])
				game_history();
			else if (command == menu_keys[5])
				break;
			else
				cout << error_command;
		}
	}
};

