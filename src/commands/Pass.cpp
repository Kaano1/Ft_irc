#include <Commands.hpp>


int cmd::pass(const vector<string> &input, User& from)
{
	if (input.size() != 2)
	{
		Response::withCode(ERR_NEEDMOREPARAMS).to(from).content(PASS_USE).send();
		return (-1);
	}
	if (!isEqual(input[1], start.getPassword(), 1))
	{
		cout << "incorrect" << endl;
		Response::withCode(ERR_PASSWDMISMATCH).to(from).content(INCORRECT_PASS).send();
		return (-1);
	}
	else if (isEqual(input[1], start.getPassword(), 1))
	{
		from.setActive(HALF);
		Response::withCode(RPL_INFO).to(from).content(CORRECT_PASS).send();
		cout << "correct" << endl;
		return 1;
	}
	if (from.getActive() != FALSE)
	{
		Response::withCode(ERR_ALREADYREGISTRED).to(from).content(A_REGIST).send();
	}
	return (0);
}

