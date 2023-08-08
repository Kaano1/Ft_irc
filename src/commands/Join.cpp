#include <Commands.hpp>

int cmd::join(const vector<string> &input, User& from)
{
	if (input.size() != 2)
	{
		Response::withCode(ERR_NEEDMOREPARAMS).to(from).content(JOIN_USE).send();
		return (-1);
	}
	if (from.getActive() < HALF)
	{
		Response::create().to(from).content(ND_ACTIVE).send();
		return (-1);
	}

	cout << "join input[0] : " << input[0] << endl;
	cout << "join input[1] : " << input[1] << endl;

	start.addUserTo(input[1], from);
	return (0);
}
