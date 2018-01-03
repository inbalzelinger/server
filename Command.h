//
// Created by hadar on 26/12/17.
//

#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H

#include <string>
#include <vector>

using  namespace std;
class Command {
public:

	/**
* finction name: execute
* execute the command.
*/
	virtual void execute(vector<string> args)=0;

	/**
* finction name: ~Command
* dstructor
*/
    virtual ~Command() {}
};


#endif //SERVER_COMMAND_H
