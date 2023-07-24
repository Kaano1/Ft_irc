#include "../../inc/Server.hpp"

int cmd::user(const vector<string> &input, User &user) // boşluk olunca farklı sonuç
{
	if (user.getActive() <= HALF || input.size() != 5)
		return (-1);
	user.setUserName(input[1]);
	user.setHostName(input[2]);
	user.setServName(input[3]);
	user.setRealName(input[4]);
	return (0);

}
