/*
  FileName:     hw05.cpp
  Name:           Kostaq Papa
  Semester:      Spring 2011
  Course:         CS 1124
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

//This class creates a wizart, an archer and a swordsman.
class Protector
{
	public:
		Protector( const string& name, int strength ) : name( name ), strength( strength ){}

		virtual void enterBattle( const string& name ) = 0; 

		string getName() const						{	return name;		}
		int getStrength() const						{	return strength;	}   

		void setStrength( int newStrength )
		{
			strength = newStrength;
		}
	private:
		string name; 
		int strength; 
};

class Archer : public Protector
{
	public:
		Archer( const string& name, int strength ) : Protector( name, strength ){}

		void enterBattle( const string& name )
		{
			if( getStrength() > 0 )
				cout << "TWANG! " << getName() << " says: Take that in the name of my lord! " << name << endl;
		}
	private:
		string name;
};
class Swordsman : public Protector
{
	public:
		Swordsman( const string& name, int strength ) : Protector( name, strength ){}

		void enterBattle( const string& name )
		{
			if( getStrength() > 0 )
				cout << "CLANG! " << getName() << " says: Take that in the name of my lord! " << name << endl;
		}
	private:
		string name;
};

class Wizard : public Protector
{
	public:
		Wizard( const string& name, int strength ) : Protector( name, strength ){}

		void enterBattle( const string& name )
		{
			if( getStrength() > 0 )
				cout << "POOF! " << endl;
		}
	private:
		string name;
};


// Noble class can hire or fire Protectors.
class Noble
{
	public:
		Noble( const string& name ) : name( name ){}
		
		virtual void engageBattle( const string& name ){}
		virtual int  getTotalStr() const		= 0;
		virtual void winBattle( float ratio )	= 0;
		virtual void loseBattle()				= 0;
		virtual bool winOrLose( bool winLoss )	= 0;

		string getName() const							   {	return name;	}
		
		void setTotalStr( int newStr )
		{	
			for( size_t i = 0; i < vecProtector.size(); ++i )
				vecProtector[i]->setStrength( newStr );
		}

		void battle( Noble& noble )
		{			
			float ratio = 0;
			win         = true;
			lose        = false;

			cout << name << " battles " << noble.getName() << endl;

			if( getTotalStr() == 0 && noble.getTotalStr() == 0 )
			{
				cout << "Oh NO! They're both dead! Yuck!"
					 << endl;
			}
			
			
			else if( vecProtector.size() == 0 && noble.getTotalStr() > 0 )
			{
				engageBattle( name );
				noble.engageBattle( noble.getName() );
				if( winOrLose( lose ) )
				{
					cout << "He's dead, "
					 << noble.getName()
					 << endl;
				}
				else
				{	
						noble.loseBattle();
						cout << noble.getName()
						 << " defeats "
						 << getName()
						 << endl;

					setTotalStr( newStrength );
					noble.setTotalStr( 0 );
					winOrLose( lose );					
				}
			}

			else if( getTotalStr() == 0 && vecProtector.size() != 0 )
			{
				cout << "He's dead "
					 << noble.getName()
					 << endl;
			}
			else if( noble.getTotalStr() == 0 && noble.vecProtector.size() != 0 )
			{
				cout << "He's dead "
					 << getName()
					 << endl;
			}
			else if( getTotalStr() == noble.getTotalStr() )
			{
				engageBattle( name );
				noble.engageBattle( noble.getName() );
				loseBattle();
				noble.loseBattle();
				cout << "Mutual Annihalation: " 
					 << getName() 
					 << " and " 
					 << noble.getName() 
					 << " die at each others hands." 
					 << endl;

				setTotalStr( 0 );
				noble.setTotalStr( 0 );
			}

			else if( getTotalStr() != 0 && noble.getTotalStr() != 0 && getTotalStr() > noble.getTotalStr() )
			{
				engageBattle( name );
				noble.engageBattle( noble.getName() );

				ratio = float( noble.getTotalStr() ) / float( getTotalStr() );

				winBattle( ratio );
				noble.loseBattle();
				cout << getName()
					 << " defeats "
					 << noble.getName()
					 << endl;

				setTotalStr( newStrength );
				noble.setTotalStr( 0 );
			}
			else if( getTotalStr() != 0 && noble.getTotalStr() != 0 && getTotalStr() < noble.getTotalStr() )
			{
				engageBattle( name );
				noble.engageBattle( noble.getName() );

				ratio = getTotalStr() / float( noble.getTotalStr() );
				
				noble.winBattle( ratio );
				loseBattle();

				cout << noble.getName()
					 << " defeats "
					 << getName()
					 << endl;

				newStrength = noble.getTotalStr() - noble.getTotalStr()*( getTotalStr() / noble.getTotalStr() );
				noble.setTotalStr( newStrength );
				setTotalStr( 0 );
			}			
		}

	private:
		vector<Protector*> vecProtector;
		string name;
		int totalStr, newStrength;
		bool win, lose;
};

class Lord : public Noble
{
	public:
		Lord( const string& name ) : Noble( name ){}
		//Total strength is equal to the sum of strengths in the vector of Protectors
		int getTotalStr() const			
		{	
			int totalStr = 0;

			for( size_t i = 0; i < vecProtector.size(); i++)
				totalStr += vecProtector[i]->getStrength();

			return totalStr;
		}

		void hires( Protector& protector )
		{
			if( protector.getStrength() > 0 )
				vecProtector.push_back( &protector );
			else if( protector.getStrength() <= 0 )
				cout << protector.getName() << " is dead." << endl;
			else
				cout << getName() << " cannot hire protectors." << endl;
		}

		void fire( Protector& protector )
		{
			cout << "You are fired, " << protector.getName() << "! says: " << getName() << endl;
			for( size_t i = 0; i < vecProtector.size(); i++ )
			{
				if( protector.getName() == vecProtector[i]->getName() )
				{
					for( size_t j = i; i < ( vecProtector.size() - 1 ); j++ )
					{
						vecProtector[j] = vecProtector[j+1];
					}
					vecProtector.pop_back();
				}
			}
		}

		void loseBattle()
		{
			for( size_t i = 0; i < vecProtector.size(); ++i )
				vecProtector[i]->setStrength( 0 );
		}

		void winBattle( float ratio )
		{
			for( size_t i = 0; i < vecProtector.size(); ++i )
				vecProtector[i]->setStrength( vecProtector[i]->getStrength() - int( vecProtector[i]->getStrength() * ratio ) );
		}

		void engageBattle( const string& name )
		{
			for( size_t i = 0; i < vecProtector.size(); ++i )
				vecProtector[i]->enterBattle( name );
		}
		
		bool winOrLose( bool winLoss )
		{
			return winLoss;
		}
	private:
		vector<Protector*> vecProtector;
};

class PersonWithStrengthToFight : public Noble
{
	public:
		PersonWithStrengthToFight( const string& name, int strength ) : Noble( name ), str( strength ){}
		
		int getTotalStr() const					{	return str;		}
		
		void winBattle( float ratio )
		{
			str -= ( int( str ) * int( ratio ) );
		}
		void loseBattle()
		{
			str = 0;
		}
		bool winOrLose( bool winLoss)
		{
			return winLoss;
		}
	private:
		int str;
};

int main()
{
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250); 	
    joe.battle(randy);	
    joe.battle(sam);	
    Lord janet("Janet");	
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);	
    janet.hires(stout);	
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);	
    janet.battle(barclay);	
    janet.hires(samantha);	
    Archer pethora("Pethora", 50);	
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);	
    sam.battle(barclay);	
    joe.battle(barclay);

	system("PAUSE");
} 
