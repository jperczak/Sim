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


#include <AVLTree.h>
#include <Headers.h>

Define_Module(Router);

std::string Router::routTab0[][3]= {
        {PC0,PC0,"0"},
        {PC1,R10,"1"},
        {PC2,R10,"1"},
};
std::string Router::routTab1[][3]= {
        {PC0,R01,"0"},
        {PC1,R21,"1"},
        {PC2,R31,"2"},
};
std::string Router::routTab2[][3]= {
        {PC0,R12,"1"},
        {PC1,PC1,"0"},
        {PC2,R12,"1"},
};
std::string Router::routTab3[][3]= {
        {PC0,R13,"1"},
        {PC1,R13,"1"},
        {PC2,PC2,"0"},
};

Router::Router()
{
}

Router::~Router()
{
}

void Router::initialize()
{
    std::string a = par("address0");
    const char * a1 = a.c_str();
    ipAddress0.set(a1); WATCH(ipAddress0);
    std::string b = par("address1");
    const char * a2 = a.c_str();
    ipAddress1.set(a2); WATCH(ipAddress1);
    std::string c = par("address2");
    const char * a3 = a.c_str();
    ipAddress2.set(a3); WATCH(ipAddress2);

    // Generate and send initial message.
    EV << "I'm a Router and I'm alive\n";
}

void Router::handleMessage(cMessage *msg)
{

    if ( (strcmp(msg->getName(),"event") == 0))
    {
        ExtMessage *message = check_and_cast<ExtMessage *>(queue.pop());
        send(message, "port$o", 0 );
        message = nullptr;

        cancelAndDelete(msg);
    }
    else
    {
        ExtMessage *ttmsg = check_and_cast<ExtMessage *>(msg);
        queue.insert(ttmsg);
        ttmsg = nullptr;

        EV << "Received: " << msg->getName() << "\n";

        cMessage * event = new cMessage("event");
        scheduleAt(simTime()+intrand(5)+1, event);
        event = nullptr;
     }
}
