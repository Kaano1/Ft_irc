#include "../../inc/Server.hpp"

int cmd::nick(const vector<string> &input, User &user)
{
	if (user.getActive() <= HALF)
		return (-1);
	user.setActive(ACTIVE);
	user.setNickName(input[1]);
	cout << "nick" << endl;
	return (0);

}
