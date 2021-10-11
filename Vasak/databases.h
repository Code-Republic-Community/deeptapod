#ifndef DATABASE_H_
#define DATABASE_H_

#include <vector>
#include <string>
#include <map>

std::vector<std::string> wordsDB = {"let","bring","help","when","first","eve","drop","please","learn","lesson","crazy","crasy""favorite","touch","there","discuss","review","code","song","book","read","flower","gather","here","and","good","sing","king","dance","can","have","be","boy","girl","chair","admire","include","car","care", "wrap" };

std::map<std::string, std::string> pronounsDB = {
	{"i", "i"},
	{"you", "you"},
	{"he", "he"},
	{"she", "she"},
	{"it", "it"},
	{"we", "we"},
	{"they", "they"},
	{"me", "i"},
	{"him", "he"},
	{"us", "we"},
	{"them", "they"},
	{"my", "i"},
	{"your", "you"},
	{"his", "he"},
	{"its", "it"},
	{"our", "we"},
	{"their", "they"},
	{"mine", "i"},
	{"yours", "you"},
	{"hers", "she"},
	{"ours", "we"},
	{"theirs", "they"},
};

std::map<std::string, std::string> irregularVerbsDB = {
	{"awoke", "awake"},
	{"was", "be"},
	{"were", "be"},
	{"been", "be"},
	{"am", "be"},  //"am, is, are" are not irregular form but it's useful to keep here
	{"is", "be"},
	{"are", "be"},
	{"beaten", "beat"},
	{"became", "become"},
	{"began", "begin"},
	{"begun", "begin"},
	{"bent", "bend"},
	{"bit", "bite"},
	{"bitten", "bite"},
	{"blew", "blow"},
	{"blown", "blow"},
	{"broke", "break"},
	{"broken", "break"},
	{"brought", "bring"},
	{"built", "build"},
	{"burnt", "burn"},
	{"bought", "buy"},
	{"could", "can"},
	{"caught", "catch"},
	{"chose", "choose"},
	{"chosen", "choose"},
	{"came", "come"},
	{"dug", "dig"},
	{"did", "do"},
	{"done", "do"},
	{"drew", "drow"},
	{"drawn", "drow"},
	{"dreamt", "dream"},
	{"drove", "drive"},
	{"driven", "drive"},
	{"drank", "drink"},
	{"drunk", "drink"},
	{"ate", "eat"},
	{"eaten", "eat"},
	{"fell", "fall"},
	{"fallen", "fall"},
	{"felt", "feel"},
	{"fought", "fight"},
	{"found", "find"},
	{"flew", "fly"},
	{"flown", "fly"},
	{"forgot", "forget"},
	{"forgotten", "forget"},
	{"forgave", "forgive"},
	{"forgiven", "forgive"},
	{"froze", "freeze"},
	{"frozen", "freeze"},
	{"got", "get"},
	{"gotten", "get"},
	{"gave", "give"},
	{"given", "give"},
	{"went", "go"},
	{"gone", "go"},
	{"grew", "grow"},
	{"grown", "grow"},
	{"hung", "hang"},
	{"had", "have"},
	{"heard", "hear"},
	{"hid", "hide"},
	{"hidden", "hide"},
	{"held", "hold"},
	{"kept", "keep"},
	{"knew", "know"},
	{"known", "know"},
	{"laid", "lay"},
	{"led", "lead"},
	{"learnt", "learn"},
	{"left", "leave"},
	{"lent", "lend"},
	{"lay", "lie"},
	{"lain", "lie"},
	{"lost", "lose"},
	{"made", "make"},
	{"meant", "mean"},
	{"met", "meet"},
	{"paid", "pay"},
	{"rode", "ride"},
	{"ridden", "ride"},
	{"rang", "ring"},
	{"rung", "ring"},
	{"rose", "rise"},
	{"risen", "rise"},
	{"ran", "run"},
	{"said", "say"},
	{"saw", "see"},
	{"seen", "see"},
	{"sold", "sell"},
	{"sent", "send"},
	{"shown", "show"},
	{"sang", "sing"},
	{"sank", "sink"},
	{"sunk", "sink"},
	{"sat", "sit"},
	{"slept", "sleep"},
	{"spoke", "speak"},
	{"spoken", "speak"},
	{"spent", "spend"},
	{"stood", "stand"},
	{"stank", "stink"},
	{"stunk", "stink"},
	{"swam", "swim"},
	{"swum", "swim"},
	{"took", "take"},
	{"taken", "take"},
	{"taught", "teach"},
	{"tore", "tear"},
	{"torn", "tear"},
	{"told", "tell"},
	{"thought", "think"},
	{"threw", "throw"},
	{"thrown", "throw"},
	{"understood", "understand"},
	{"woke", "wake"},
	{"woken", "wake"},
	{"wore", "wear"},
	{"worn", "wear"},
	{"would", "win"},
	{"won", "win"},
	{"wrote", "write"},
	{"written", "write"}
};
#endif
