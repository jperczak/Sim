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

std::string PC::listAdr[]= {
        {PC0},
        {PC1},
        {PC2},
};

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

    scheduleAt(simTime()+poisson(10), event);
    //sprawdziæ ile TCAM jest w stanie wykonaæ operacji na sekunde i stad pozyskac przyblizony czas 1 operacji.
    //zliczac selfmsg - d³ugoœæ kolejki pakietów do obs³ugi

}

ExtMessage *PC::generateNewPacket()
{
    char msgname[20];
    std::string dst = generateDstAdr();
    IPAddress ipDst(dst.c_str());
    sprintf(msgname, "ipDst: %d.%d.%d.%d", ipDst.getDByte(0), ipDst.getDByte(1), ipDst.getDByte(2), ipDst.getDByte(3));
    ExtMessage *msg = new ExtMessage(msgname);

    msg->setSrcAddress(ipAddress);
    msg->setDstAddress(ipDst);
    msg->setMask(28);

    return msg;
}

std::string PC::generateDstAdr()
{
    int i = intrand(3);
    std::string strDst = listAdr[i];
    IPAddress ipDst(strDst.c_str());
    if( ipDst == ipAddress )
    {
        return generateDstAdr();
    }
    else
    {
        return strDst;
    }
}

void PC::handleMessage(cMessage *msg)
{
    if (msg==event)
    {
        message = generateNewPacket();

        EV << "Sending: " << message->getName() << "\n";

        send(message, "port$o");
        message = nullptr;

        scheduleAt(simTime()+poisson(10), event);
    }
    else
    {
        ExtMessage *ttmsg = check_and_cast<ExtMessage *>(msg);

        EV << "Received: " << ttmsg->getName() << "\n";

        cancelAndDelete(ttmsg);
        ttmsg=nullptr;
    }
}
