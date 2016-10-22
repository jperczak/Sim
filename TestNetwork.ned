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


simple Router
{
    parameters:
        @display("i=abstract/router_vs;is=n");
    gates:
        inout port[];
}

simple PC
{
    parameters:
        @display("i=device/laptop;is=n");
    gates:
        inout port;
}

network TestNetwork
{
 submodules:
        Router0: Router {
            @display("p=266,205");
            gates:
                port[2];
        }
        Router1: Router {
            @display("p=147,205");
            gates:
                port[3];
        }
        Router2: Router {
            @display("p=340,150");
            gates:
                port[2];
        }
        Router3: Router {
            @display("p=303,303");
            gates:
                port[2];
        }
        PC0: PC {
        }
        PC1: PC {
        }
        PC2: PC {
        }
        
 connections:
        Router1.port[0] <--> {  delay = 0ms; } <--> Router0.port[1];
        Router1.port[1] <--> {  delay = 0ms; } <--> Router2.port[1];
        Router1.port[2] <--> {  delay = 0ms; } <--> Router3.port[1];
        
        PC0.port <--> {  delay = 0ms; } <--> Router0.port[0];
        PC1.port <--> {  delay = 0ms; } <--> Router2.port[0];
        PC2.port <--> {  delay = 0ms; } <--> Router3.port[0];
}
