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

class PC  : public cSimpleModule
{
public:
    PC();
    virtual ~PC();

    static std::string listAdr[3];

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

private:
    ExtMessage* generateNewPacket();
    std::string generateDstAdr();

    IPAddress ipAddress;
    ExtMessage* message;
    cMessage *event; // pointer to the event object which we'll use for timing
};
