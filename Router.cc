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
    event = nullptr;
}

Router::~Router()
{
    cancelAndDelete(event);
}

void Router::initialize()
{
    IPAddress a(0,0,0,1);
    IPAddress b(0,0,1,1);
    IPAddress c(0,1,1,1);

    avlTree.AddNodeElement(a);
    avlTree.AddNodeElement(b);
    avlTree.AddNodeElement(c);

    node* o = avlTree.FindProperNode(b);

    int g = avlTree.GetGate(o);
    IPAddress u = avlTree.GetDstAddress(o);

    // Generate and send initial message.
    EV << "I'm a Router and I'm alive\n";

    event = new cMessage("event");
}

void Router::handleMessage(cMessage *msg)
{
    if (msg==event)
    {
        ExtMessage *message = (ExtMessage*)queue.pop();
        send(message, "port$o");
        message = nullptr;  //is that necessary
    }
    else
    {
        ExtMessage *ttmsg = check_and_cast<ExtMessage *>(msg);
        queue.insert((cObject *)ttmsg);
        //handle message in routing table but....
        //temporary - just sent id to another router

        // Acknowledgment received!
        EV << "Received: " << msg->getName() << "\n";
        send(ttmsg, "port$o", 0 );

        scheduleAt(simTime()+intrand(5), event);
    }
}
