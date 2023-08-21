#include <Commands.hpp>

static string join_input(const vector<string> &input) {
	string str = "";
	for (int i = 0; i < int(input.size()); i++){
		str += input[i] + " ";
	}
	return str;
}

int cmd::privmsg(const vector<string> &input, Person & from) // kanallmı ve var mı && kullanıcı mı var mı
{
	if (input.size() < 3)
	{
		Response::create().to(from).code(ERR_NEEDMOREPARAMS).content(PRIVMSG_USE).send();
		return (-1);
	}
	cout << start.getUsers().size() << endl;
	if (start.getUserNick(input[1]) == 0 && !find_channel(input[1], from))
	{
		Response::create().to(from).code(ERR_NOSUCHNICK).content(NO_SUCH).send();
		return (-1);
	}
	string	who = input[1];

	if (who[0] == '#')
		sendGroup(from, who, join_input(input));
	else
	{
		Person *to = start.getUserNick(input[1]);

		sendUser(&from, *to, input[0] + " " + input[1] + " " + input[2]);
	}
	return (0);
}
