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

Define_Module(PC);

PC::PC()
{
    ipAddress.set(0,0,0,1);
    event = nullptr;
    message = nullptr;
}

PC::~PC()
{
    cancelAndDelete(event);
}

void PC::initialize()
{
    std::string a = par("address");
    const char * c = a.c_str();
	ipAddress.set(c); WATCH(ipAddress);
	
    event = new cMessage("event");

    // Generate and send initial message.
    EV << "I'm a PC and I'm alive\n";

    scheduleAt(simTime()+poisson(10), event);
}

ExtMessage *PC::generateNewPacket()
{
    // Generate a message with a different name every time.
    char msgname[20];
    sprintf(msgname, "ipSrc-%d", ipAddress.getInt());
    ExtMessage *msg = new ExtMessage(msgname);

    msg->setSrcAddress(ipAddress);
    msg->setDstAddress(ipAddress);

    return msg;
}


void PC::handleMessage(cMessage *msg)
{
    if (msg==event)
    {
        EV << "Wait period is over, sending back message\n";
        message = generateNewPacket();
        send(message, "port$o");
        message = nullptr;

        scheduleAt(simTime()+poisson(10), event);
    }
    else
    {
        ExtMessage *ttmsg = check_and_cast<ExtMessage *>(msg);

        EV << "Received: " << ttmsg->getName() << "\n";
        delete ttmsg;
    }
}
