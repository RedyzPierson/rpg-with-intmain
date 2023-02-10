#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>

using namespace std;


int main()
{
	//friendlies
	int fhp, fexp, fmana, fdmg, flvl, fturn, fuse, farmor;
	string faby;

	//enemies
	int ehp, texp, emana, edmg, elvl, eturn, euse, earmor;
	string eaby;

	// Knight Data
	string f1 = "Knight";
	flvl = 1;
	fhp = 650;
	farmor = 50;
	fexp = 0;
	fmana = 250;
	fdmg = 15;
	fturn = 3;
	fuse = 0;

	// Witch Data
	string e1 = "Witch";
	elvl = 1;
	ehp = 800;
	earmor = 15;
	texp = 0;
	emana = 400;
	edmg = 15;
	eturn = 3;
	euse = 0;

	// Battle Data
	int bround = 0;
	int side;
	int bspescon = 0;
	bool losslvl = false;
	string s_name;
	string bname;
	string br_name;
	string aby_name;

	// Menu Data
	string input;

	// Item Data;
	int itemshop = 0;
	int rand_dmg;
	int rand_heal;
	string healitem;
	string dmgitem;

	while (fhp != 0 || ehp != 0)
	{
		// Random System
		srand((unsigned)time(NULL));
		int bresult = 1 + rand() % 4;
		side = 1 + rand() % 2;
		rand_dmg = 1 + rand() % 3;
		rand_heal = 1 + rand() % 3;

		// Damage Item Naming
		if (rand_dmg == 1)
		{
			dmgitem = "FIRE";
		}
		if (rand_dmg == 2)
		{
			dmgitem = "ICE";
		}
		if (rand_dmg == 3)
		{
			dmgitem = "WIND";
		}

		// Heal / Utility Item Naming
		if (rand_heal == 1)
		{
			healitem = "POTION";
		}
		if (rand_heal == 2)
		{
			healitem = "BOOSTER SRINGE";
		}
		if (rand_heal == 3)
		{
			healitem = "POWER PILL";
		}

		//------ Screen Cyle of the Battle ------ //

		cout << "\n\n";
		cout << " | ------ BLUE TEAM ------ " << endl;

		cout << " | Level : " << flvl << endl;
		cout << " | Name  : " << f1 << endl;
		cout << " | HP    : " << fhp << endl;
		cout << " | ATK   : " << fdmg << endl;
		cout << " | ARMOR : " << farmor << endl;
		cout << " | EXP   : " << fexp << endl;
		cout << " | MANA  : " << fmana << endl;
		cout << " | Turn  : " << fturn << endl;
		cout << " | Item  : " << faby << "\n\n";

		cout << " | ------ RED TEAM ------ " << endl;

		cout << " | Level : " << elvl << endl;
		cout << " | Name  : " << e1 << endl;
		cout << " | HP    : " << ehp << endl;
		cout << " | ATK   : " << edmg << endl;
		cout << " | ARMOR : " << earmor << endl;
		cout << " | EXP   : " << texp << endl;
		cout << " | MANA  : " << emana << endl;
		cout << " | Turn  : " << eturn << endl;
		cout << " | Item  : " << eaby << "\n\n" << endl;

		//------ Screen Cyle of the Battle ------ //

		// Condition
		if (fhp <= 0 || ehp <= 0)
		{
			if (fhp <= 0)
			{
				cout << " | Knight Has Been Defeated! |" << endl;
				cout << " | Witch Won the Fight       |" << endl;
				cout << " | Total Round Battle : " << bround << "\n\n";
			}

			else if (ehp <= 0)
			{
				cout << " | Witch Has Been Defeated! |" << endl;
				cout << " | Knight Won the Fight     |" << endl;
				cout << " | Total Round Battle : " << bround << "\n\n";
			}

			cout << "| >>>>! Game Over !<<<< |" << "\n\n";

			cout << " | Restart | Exit | " << endl;
			cout << "> ";
			cin >> input;

			if (input == "res.game")
			{
				main();
			}
			else if (input == "quit")
			{
				return 0;
			}
			else {
				return 0;
			}
		}

		// Damage Item Logic
		if (faby == "FIRE" && fuse == 1 || eaby == "FIRE" && euse == 1)
		{
			if (faby == "FIRE" && fuse == 1)
			{
				fdmg = fdmg + 25;

				cout << "This Player : " << f1 << " Get's HOT!" << endl;
				cout << f1 << " : Watch out for fire . . . ! \n\n";

				fuse = fuse - 1;
			}

			if (eaby == "FIRE" && euse == 1)
			{
				edmg = edmg + 20;

				cout << "This Player : " << e1 << " Get's HOT!" << endl;
				cout << e1 << " : Hehehe Fire will BURNNN . . . ! \n\n";

				euse = euse - 1;
			}
			Sleep(1000);
		}
		if (faby == "ICE" && fuse == 1 || eaby == "ICE" && euse == 1)
		{
			if (faby == "ICE" && fuse == 1)
			{
				if (earmor >= 0)
				{
					fdmg = fdmg + 5;
					fhp = fhp - 25;

					earmor = earmor - 25;
					ehp = ehp - 25;
					edmg = edmg - 25;
					texp = texp + 7;
				}

				if (earmor <= 0)
				{
					fdmg = fdmg + 5;
					fhp = fhp - 25;

					ehp = ehp - 75;
					fdmg = fdmg - 25;
					texp = texp + 7;
				}

				cout << "This Player : " << f1 << " Get's COLD!" << endl;
				cout << f1 << " : Ah Sh*t it's COLD but good . . . ! \n\n";

				fuse = fuse - 1;
			}

			if (eaby == "ICE" && euse == 1)
			{
				if (farmor >= 0)
				{
					edmg = edmg + 5;
					ehp = ehp - 25;

					farmor = farmor - 25;
					fhp = fhp - 25;
					fdmg = fdmg - 10;
					fexp = fexp + 7;
				}

				if (farmor <= 0)
				{
					fdmg = fdmg + 5;
					fhp = fhp - 25;

					fhp = fhp - 75;
					fdmg = fdmg - 25;
					texp = texp + 7;
				}

				cout << "This Player : " << e1 << " Get's COLD!" << endl;
				cout << e1 << " : Ice, i hate ice . . . ! \n\n";

				euse = euse - 1;
			}
			Sleep(1000);
		}
		if (faby == "WIND" && fuse == 1 || eaby == "WIND" && euse == 1)
		{
			if (faby == "WIND" && fuse == 1)
			{
				fhp = fhp - 5;
				fexp = fexp + texp;

				earmor = earmor - 5;
				ehp = ehp - 35;

				texp = texp - 50;

				cout << "This Player : " << f1 << " Get Tornado" << endl;
				cout << f1 << " : TORNADOOOO . . . ! \n\n";

				fuse = fuse - 1;

				side = 2;
				fturn = fturn - 1;
			}

			if (eaby == "WIND" && euse == 1)
			{
				ehp = ehp - 5;
				texp = texp + fexp;

				farmor = farmor - 5;
				fhp = fhp - 35;
				fexp = fexp - 50;

				cout << "This Player : " << e1 << " Get Tornado" << endl;
				cout << e1 << " : Hehehe there it is The Tornado . . . ! \n\n";

				euse = euse - 1;

				side = 1;
				eturn = eturn - 1;
			}
			Sleep(1000);
		}

		// Heal Item Logic
		if (faby == "POTION" && fuse == 1 || eaby == "POTION" && euse == 1)
		{
			if (faby == "POTION" && fuse == 1)
			{
				fhp = fhp + 500;
				farmor = farmor + 15;

				cout << "This Player : " << f1 << " Healing Potion" << endl;
				cout << f1 << " : Ahhhh feels great . . . \n\n";

				fuse = fuse - 1;
			}

			if (eaby == "POTION" && euse == 1)
			{
				ehp = ehp + 500;
				earmor = earmor + 15;

				cout << "This Player : " << e1 << " Healing Potion" << endl;
				cout << e1 << " : Healing? Good . . . \n\n";

				euse = euse - 1;
			}
			Sleep(1000);
		}
		if (faby == "BOOSTER SRINGE" && fuse == 1 || eaby == "BOOSTER SRINGE" && euse == 1)
		{
			if (faby == "BOOSTER SRINGE" && fuse == 1)
			{
				fdmg = fdmg - 10;
				fhp = fhp + 225;
				fexp = fexp + 90;
				fturn = 3;

				cout << "This Player : " << f1 << " Boosted!" << endl;
				cout << f1 << " : Alright here we goooo. . . \n\n";

				fuse = fuse - 1;
			}

			if (eaby == "BOOSTER SRINGE" && euse == 1)
			{
				edmg = edmg - 10;
				ehp = ehp + 225;
				texp = texp + 90;
				eturn = 3;

				cout << "This Player : " << e1 << " Boosted!" << endl;
				cout << e1 << " : Hihi Haha I'm Gonna Win this hehehe . . . \n\n";

				euse = euse - 1;
			}
			Sleep(1000);
		}
		if (faby == "POWER PILL" && fuse == 1 || eaby == "POWER PILL" && euse == 1)
		{
			if (faby == "POWER PILL" && fuse == 1)
			{
				fhp = fhp + 1200;
				fdmg = fdmg - 20;
				fexp = fexp + 30;

				cout << "This Player : " << f1 << " The Power Pill" << endl;
				cout << f1 << " : YEAAA POWAAA!!! . . . \n\n";

				fuse = fuse - 1;
			}

			if (eaby == "POWER PILL" && euse == 1)
			{
				ehp = ehp + 1200;
				edmg = edmg - 20;
				texp = texp + 30;

				cout << "This Player : " << e1 << " Power Pill" << endl;
				cout << e1 << " : Mmmmm Powerrrr . . . \n\n";

				euse = euse - 1;
			}
			Sleep(1000);
		}

		// Leveling Logic
		if (fexp >= 100)
		{
			system("cls");
			bname = "Knight";
			flvl = flvl + 1;

			fhp = fhp + 550;
			fdmg = fdmg + 20;
			fmana = fmana + 105;
			farmor = farmor + 20;

			fexp = 0;


			cout << " | ------------------------------ " << endl;
			cout << " | Level Up >>> " << flvl << " : " << bname << endl;
			cout << " | ------------------------------ " << endl;
			cout << " | DMG +20 | HP +350 | MANA +105 | \n\n";

			cout << " |   ================================    | " << endl;

			cout << " | ------ KNIGHT REACH NEXT LEVEL ------ |" << endl;
			cout << " | -------       ITEM SHOP       ------- |" << endl;
			cout << " | --------------------------------------|" << endl;
			cout << " | DMG Item : " << dmgitem << endl;
			cout << " | HEAL Item : " << healitem << "\n" << endl;
			cout << " > ";
			cin >> input;

			if (input == "dmg")
			{
				faby = dmgitem;
			}
			if (input == "heal")
			{
				faby = healitem;
			}

			cout << "\n\n";

			fuse = fuse + 1;
			fexp = fexp + 5;

			if (flvl == 5)
			{
				f1 = "Super Knight";
				fhp = fhp + 2200;
				fdmg = fdmg + 35;
				farmor = farmor + 150;

				fexp = fexp + 7;
			}

			Sleep(1000);
		}
		if (texp >= 100)
		{
			system("cls");
			bname = "Witch";
			elvl = elvl + 1;

			ehp = ehp + 550;
			edmg = edmg + 20;
			emana = emana + 105;
			earmor = earmor + 20;

			texp = 0;

			cout << " | ------------------------------ " << endl;
			cout << " | Level Up >>> " << elvl << " : " << bname << endl;
			cout << " | ------------------------------ " << endl;
			cout << " | DMG +20 | HP +350 | MANA +105 | \n\n";

			cout << " |   ================================    | " << endl;

			cout << " | ------ WITCH REACH NEXT LEVEL ------- |" << endl;
			cout << " | -------       ITEM SHOP       ------- |" << endl;
			cout << " | --------------------------------------|" << endl;
			cout << " | DMG Item : " << dmgitem << endl;
			cout << " | HEAL Item : " << healitem << "\n" << endl;
			cout << " > ";
			cin >> input;

			if (input == "dmg")
			{
				eaby = dmgitem;
			}
			if (input == "heal")
			{
				eaby = healitem;
			}

			cout << "\n\n";

			euse = euse + 1;
			texp = texp + 5;

			if (elvl == 5)
			{
				e1 = "Wizard";
				ehp = ehp + 1100;
				edmg = edmg + 55;
				emana = emana + 1000;
				earmor = earmor + 25;

				texp = texp + 7;
			}

			Sleep(1000);
		}
		if (fexp < 0 || texp < 0)
		{
			losslvl = true;
		}
		if (fexp < 0 || losslvl == true)
		{
			flvl = flvl - 1;
			fexp = fexp + 50;

			losslvl = false;
		}
		if (texp < 0 || losslvl == true)
		{
			elvl = elvl - 1;
			texp = texp + 50;

			losslvl = false;
		}
		if (flvl < 0)
		{
			losslvl = false;
		}

		// Special Condition Logic
		if (fmana == 0 || emana == 0)
		{
			bspescon = 1;
		}
		if (fmana == 0 && bspescon == 1 || emana == 0 && bspescon == 1)
		{
			if (fmana == 0 && bspescon == 1)
			{
				fdmg = fdmg - 3;
				fmana = fmana + 100;
				
				bspescon = 0;
			}
			if (emana == 0 && bspescon == 1)
			{
				edmg = edmg - 3;
				emana = emana + 100;

				bspescon = 0;
			}
		}
		if (farmor <= 0)
		{
			farmor = 0;
		}
		if (earmor <= 0)
		{
			earmor = 0;
		}

		// Random Battle Result
		if (bresult == 1)
		{
			br_name = "Hit";
		}
		if (bresult == 2)
		{
			br_name = "Crit";
		}
		if (bresult == 3)
		{
			br_name = "Miss";
		}
		if (bresult == 4)
		{
			br_name = "Block";
		}

		// Side Cycle
		if (side == 1)
		{
			s_name = "Witch";
		}
		if (side == 2)
		{
			s_name = "Knight";
		}

		cout << " | Battle Round  : " << bround << endl;
		cout << " | Battle Turn   : " << s_name << endl;
		cout << " | Battle Result : " << br_name << endl;

		// Turn System
		if (fturn <= 0)
		{
			fturn = 3;
			side = 1;
		}
		if (eturn <= 0)
		{
			eturn = 3;
			side = 2;
		}
		
		// Battleside 1 = Witch
		if (bresult == 1 && side == 1)
		{
			if (farmor > 0)
			{
				fhp = fhp - (edmg - (farmor % 2));
			}
			else if (farmor <= 0)
			{
				fhp = fhp - edmg;
			}

			fexp = fexp + 1;
			texp = texp + 5;
			eturn = eturn - 1;
		}
		else if (bresult == 2 && side == 1)
		{
			if (farmor > 0)
			{
				fhp = fhp - edmg;
			}
			else if (farmor <= 0)
			{
				fhp = fhp - edmg * 2;
			}

			fexp = fexp + 1;
			texp = texp + 5;

			eturn = eturn - 1;
		}
		else if (bresult == 3 && side == 1)
		{
			emana = emana - 20;

			fexp = fexp + 1;
			texp = texp + 1;

			eturn = eturn - 1;
		}
		else if (bresult == 4 && side == 1)
		{
			fhp = fhp - 5;
			farmor = farmor - 5;

			fexp = fexp + 5;
			texp = texp + 1;

			eturn = eturn - 1;
		}

		// Battleside 2 = Knight
		if (bresult == 1 && side == 2)
		{
			if (earmor > 0)
			{
				ehp = ehp - (fdmg - (earmor % 2));
			}
			else if (earmor <= 0)
			{
				ehp = ehp - fdmg;
			}

			fexp = fexp + 5;
			texp = texp + 1;

			fturn = fturn - 1;
		}
		else if (bresult == 2 && side == 2)
		{
			if (farmor > 0)
			{
				ehp = ehp - fdmg;
			}
			else if (farmor <= 0)
			{
				ehp = ehp - fdmg * 2;
			}

			fexp = fexp + 5;
			texp = texp + 1;

			fturn = fturn - 1;
		}
		else if (bresult == 3 && side == 2)
		{
			fmana = fmana - 20;

			fexp = fexp + 1;
			texp = texp + 1;

			fturn = fturn - 1;
		}
		else if (bresult == 4 && side == 2)
		{
			ehp = ehp - 5;
			earmor = earmor - 5;

			fexp = fexp + 1;
			texp = texp + 5;

			fturn = fturn - 1;
		}

		bround = bround + 1;

		Sleep(500);
		system("cls");
	}
}