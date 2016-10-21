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

Router::Router()
{
    ipAddress.set(0,0,0,1);
}

Router::~Router()
{

}

void Router::initialize()
{
    //double x = par("address");
    //ipAddress = par("address"); WATCH(ipAddress);

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
