#include <iostream>
#include <string>
#include "colors.cpp"


int main()
{
	using namespace std;
	using namespace clr;

    cout << Color("Hello! My name is Bot. Enter your name please:", blue) << endl;
	string name;
	std::getline(std::cin, name);
	cout << Color("Nice to meet you, ", cyan);
	cout << Color(name, cyan) << endl;
	cout << Color("Please answer some questions for me using only one word in each answer.\nWhen you get bored and want to finish, please write 'Goodbye'", green) << endl;
	string question[15] = { "Where are you from", "How old are you?", "What is your gender?", "What is your job?", "What is your favourite food?", "Which music genre do you enjoy most?", 
		"What kind of sport do you enjoy doing most?","Do you have some hobbies?", "Do you have enough free time?", "What is your hometown?", "Do you learn some foriegn languages?",
		"What is your favourite season of the year?"};
	string answers[10] = {"Very nice man!", "So intresting", "Wow!That's awesome", "Well, glad for you", "Oh...", "Well", "Glad to hear it!", "That was my favourite question and now favourite answer for it!"
	};
	string answer;
	int randquest, randanswer;
	const string bye = "Goodbye";
	const string yes = "yes";
	const string no = "no";
	const string rus = "Russia";
	const string rock = "rock";
	const string pizza = "pizza";
	const string sum = "summer";
	const string foot = "football";
	while (true) {
		randquest = std::rand() % 12;
		randanswer = std::rand() % 8;
		std::cout << Color(name, cyan) << Color(", ", cyan);
		std::cout << Color(question[randquest], cyan) << endl;

		std::getline(std::cin, answer);

		if (answer == bye) {
			break;
		}
		else {
			if ((answer == rock && randquest == 5) || (answer == pizza && randquest == 4)) {
				std::cout << Color("Wow, me too! I'm a big fan of it.", blue) << '\n' << endl;
			}
			else {
				if (answer == yes && randquest == 8) {
					std::cout << Color("You're lucky", blue) << '\n' << endl;
				}
				else {
					if (answer == no && (randquest == 10 || randquest == 7)) {
						std::cout << Color("You're weird man...", blue) << '\n' << endl;
					}
					else {
						if (answer == sum && randquest == 11) {
							std::cout << Color("Mine too!", blue) << '\n' << endl;
						}
						else {
							if (answer == rus) {
								std::cout << Color("Wow, great country!", blue) << '\n' << endl;
							}
							else {
								if (answer == foot && randquest == 11) {
									std::cout << Color("Wow, me too", blue) << '\n' << endl;
								}
								else {
									std::cout << Color(answers[randanswer], blue) << '\n' << endl;
								}
							}
						}
					}
				}
			}
		}
	}
	std::cout << Color("Goodbye, ", orange);
	std::cout << Color(name, orange) << endl;
	return 0;
}