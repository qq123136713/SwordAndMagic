#ifndef UnDragonBreath_CPP
#define UnDragonBreath_CPP


#include <typeinfo>
class Magic;
#include "..\Magic.h"
class Character;
#include "..\Character.h"
class Hero;
#include "..\Hero.h"
class Dragon;
#include "..\Dragon.h"

class UnDragonBreath : public Magic {

	public:
		UnDragonBreath() {
		}
		~UnDragonBreath() {
		}
		bool CanUse(Character *user, int turn = 3) {
			if (turn == 3)
				return true;
			return false;
		}
		bool Passive() {
			return false;
		}
		bool Use(Character *user, Character *receiver, Magic *magic) {
			user_ = user;
			receiver_ = receiver;
			Hero *p1 = dynamic_cast<Hero*>(user);
			if (receiver -> GetType() == 1) {
				Hero *p2 = dynamic_cast<Hero*>(receiver);
				p2 -> SetHit(magic);
				p2 -> SetHitFrom(user);
				p2 -> AskAnswer(user, magic);
			} else {
				float dam = 6.0;
				dam = p1 -> CalDam(dam, 1);
				user -> GetHurt(user, dam, 1);
			}
			return true;
		}
		void Effect(bool cho = true) {
			Character *user = user_;
			Character *receiver = receiver_;
			Hero *p1 = dynamic_cast<Hero*>(user);
			Hero *p2 = dynamic_cast<Hero*>(receiver);
			float dam = 6.0;
			dam = p1 -> CalDam(dam, 1);
			p2 -> GetHurt(user, dam, 1);
		}
		string Display() {
			return "UnDragonBreath";//未精通的龙息术
		}

};



#endif
