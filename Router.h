//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 


#include <Headers.h>
#include <cpacketqueue.h>

class Router : public cSimpleModule
{
public:
    Router();
    virtual ~Router();

    static std::string routTab0[3][4];
    static std::string routTab1[3][4];
    static std::string routTab2[3][4];
    static std::string routTab3[3][4];

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

private:
    IPAddress ipAddress0;
    IPAddress ipAddress1;
    IPAddress ipAddress2;
    AVLTree avlTree;
    cQueue queue;
    cMessage *selfmsg; // pointer to the event object which we'll use for timing
    ExtMessage *ttmsg; // actual msg to send after selfmsg event
};
