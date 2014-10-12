/*

rec07.cpp
Name:         Kostaq Papa
ID:           0412768
Semester:     Spring 2011
Course:       CS 1124
Lab Section:  CS 1124LAB - B2

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Instrument {
public:
	virtual void makeSound() const {
		cout << "To make a sound..."; 
	}
	virtual void play() const = 0;

private:
};

class Musician {
public:
	Musician() : instr( NULL ) {}
	void acceptInstr( Instrument & i ) { instr = &i; }
	Instrument* giveBackInstr( ) { 
		Instrument* tmp(instr); 
		instr = NULL;
		return tmp;
	}
	void testPlay() const {
		if( instr )
			instr->makeSound(); 
		else
			cerr << "have no instr\n";
	}
private:
	Instrument* instr;
};

class Brass : public Instrument {
private:
	unsigned size;
public:
	Brass(unsigned size) : size(size) {}
	virtual void makeSound() const {
		cout << "to make a sound...blow on a mouthpiece of size " << size << endl;
	}
};

class Trombone : public Brass {
private:
public:
	Trombone(unsigned size) : Brass(size) {}
	void makeSound() const {
		cout <<"Trombone: ";
		Brass::makeSound();
	}
	void play() const {
		cout << "Blat";
	}
};

class Trumpet : public Brass {
private:
public:
	Trumpet(unsigned size) : Brass(size) {}
	void makeSound() const {
		cout << "Trumpet: ";
		Brass::makeSound();
	}
	void play() const {
		cout << "Toot";
	}

};

class String : public Instrument {
private:
	unsigned pitch;
public:
	String(unsigned pitch) : pitch(pitch) {}
	virtual void makeSound() const {
		cout << "To make a sound...bow a string with pitch " << pitch << endl;
	}
};

class Violin : public String {
private:
public:
	Violin(unsigned pitch) : String(pitch) {}
	void makeSound() const {
		cout << "Violin: ";
		String::makeSound();
	}
	void play() const {
		cout << "Screech";
	}
};

class Cello : public String {
private:
public:
	Cello(unsigned pitch) : String(pitch) {}
	void makeSound() const {
		cout << "Cello: ";
		String::makeSound();
	}
	void play() const {
		cout << "Squawk";
	}
};

class Percussion : public Instrument {
public:
	virtual void makeSound() const {
		cout << "To make a sound..hit me!" << endl;
	}
private:
};

class Drum : public Percussion {
public:
	void makeSound() const {
		cout << "Drum: ";
		Percussion::makeSound();
	}
	void play() const {
		cout <<"Boom";
	}
private:
};
class Cymbal : public Percussion {
public:
	void makeSound() const {
		cout <<"Cymbal: ";
		Percussion::makeSound();
	}
	void play() const {
		cout << "crash";
	}
private:
};

class MILL {
private:
	vector<Instrument*>InstrList;
public:
	void receiveInstr(Instrument* instr) {
		instr->makeSound();
		if (InstrList.size()==0) {
			InstrList.push_back(instr);
		}
		for (size_t i = 0; i < InstrList.size();++i) {
			if(InstrList[i]==NULL) {
				InstrList[i]=instr;
				return;
			}
		}
		InstrList.push_back(instr);
	}
	Instrument* loanOut() {
		if(InstrList.size() == 0) {
			return NULL;
		}
		for (size_t i = 0; i < InstrList.size(); ++i) {
			if(InstrList[i]!=NULL) {
				Instrument* temp = InstrList[i];
				InstrList[i]=NULL;
				return temp;
			}
		}
		return NULL;
	}
	void dailyTestPlay() {
		for(size_t i = 0; i < InstrList.size(); ++i) {
			if(InstrList[i]!=NULL) {
				InstrList[i]->makeSound();
			}
		}
	}
};

class Orch {
private:
	vector<Musician*> musicList;
public:
	void addPlayer(Musician& player) {
		if(musicList.size()>25) {
			cerr << "Cant add Musicians.\n";
		}
		musicList.push_back(&player);
	}
	void play() const{
	
		for(size_t i=0; i<musicList.size(); i++){

			if(musicList[i]!=NULL){
			musicList[i]->testPlay();
			}
		}
		cout << endl;
	}
};
		


int main() {
		Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone( 4 );
	Trumpet trpt( 12 ) ;
	Violin violin( 567 ) ;

	MILL mill;
	mill.receiveInstr( &trpt );
	mill.receiveInstr( &violin );
	mill.receiveInstr( &tbone );
	mill.receiveInstr( &drum );
	mill.receiveInstr( &cello );
	mill.receiveInstr( &cymbal );

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;



	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr( *mill.loanOut() );
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr( *mill.loanOut() );

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr( *mill.loanOut() );
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr( ralph.giveBackInstr() );

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr( *mill.loanOut() );
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr( *mill.loanOut() );

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();
	
	// bob gets an instrument from the MIL2
	bob.acceptInstr( *mill.loanOut() );

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr( *mill.loanOut() );

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();
	
	system("pause");
}


	

