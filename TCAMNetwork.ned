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

network TCAMNetwork
{
    submodules:
        Router0: Router {
            @display("p=266,205");
            gates:
                port[3];
        }
        Router1: Router {
            @display("p=147,205");
            gates:
                port[4];
        }
        Router2: Router {
            @display("p=340,150");
            gates:
                port[4];
        }
        Router3: Router {
            @display("p=303,303");
            gates:
                port[2];
        }
        PC0: PC {
        }
        Router4: Router {
            @display("p=176,150");
            gates:
                port[2];
        }
        PC1: PC {
        }
        Router5: Router {
            @display("p=83,150");
            gates:
                port[2];
        }
        PC2: PC {
        }
        Router6: Router {
            @display("p=83,237");
            gates:
                port[2];
        }
        PC3: PC {
        }
        Router7: Router {
            @display("p=423,205");
            gates:
                port[2];
        }
        PC4: PC {
        }
        Router8: Router {
            @display("p=408,85");
            gates:
                port[2];
        }
        PC5: PC {
        }
        Router9: Router {
            @display("p=281,85");
            gates:
                port[2];
        }
        PC6: PC {
        }
    connections:
        Router0.port[0] <--> {  delay = 0ms; } <--> Router1.port[0];
        Router0.port[1] <--> {  delay = 0ms; } <--> Router2.port[0];
        Router0.port[2] <--> {  delay = 0ms; } <--> Router3.port[0];
        
        Router1.port[1] <--> {  delay = 0ms; } <--> Router4.port[0];
        Router1.port[2] <--> {  delay = 0ms; } <--> Router5.port[0];
        Router1.port[3] <--> {  delay = 0ms; } <--> Router6.port[0];
        
        Router2.port[1] <--> {  delay = 0ms; } <--> Router7.port[0];
        Router2.port[2] <--> {  delay = 0ms; } <--> Router8.port[0];
        Router2.port[3] <--> {  delay = 0ms; } <--> Router9.port[0];
        
        PC0.port <--> {  delay = 0ms; } <--> Router3.port[1];
        PC1.port <--> {  delay = 0ms; } <--> Router4.port[1];
        PC2.port <--> {  delay = 0ms; } <--> Router5.port[1];
        PC3.port <--> {  delay = 0ms; } <--> Router6.port[1];
        PC4.port <--> {  delay = 0ms; } <--> Router7.port[1];
        PC5.port <--> {  delay = 0ms; } <--> Router8.port[1];
        PC6.port <--> {  delay = 0ms; } <--> Router9.port[1];
}
