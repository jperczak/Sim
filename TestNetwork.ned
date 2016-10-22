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
        string address0 = default("");
        string address1 = default("");
        string address2 = default("");
    gates:
        inout port[];
}

simple PC
{
    parameters:
        @display("i=device/laptop;is=n");
        string address = default("");
    gates:
        inout port;
}

network TestNetwork
{
 submodules:
        Router0: Router {
            @display("p=266,205");
            address0 = "10.0.0.6";
        	address1 = "10.1.0.1";
        	address2 = "0.0.0.0";
            gates:
                port[2];		
        }
        Router1: Router {
            @display("p=147,205");
            address0 = "10.1.0.2";
        	address1 = "10.2.0.1";
        	address2 = "10.3.0.1";
            gates:
                port[3];		
        }
        Router2: Router {
            @display("p=340,150");
            address0 = "10.0.2.254";
        	address1 = "10.2.0.2";
        	address2 = "0.0.0.0";
            gates:
                port[2];       		
        }
        Router3: Router {
            @display("p=303,303");
            address0 = "10.0.2.62";
        	address1 = "10.3.0.2";
        	address2 = "0.0.0.0";
            gates:
                port[2];
        }
        PC0: PC {
            parameters:
        		address = "10.0.0.1";
        }
        PC1: PC {
            parameters:
        		address = "10.0.2.1";
        }
        PC2: PC {
            parameters:
        		address = "10.0.3.1";
        }
        
 connections:
        Router1.port[0] <--> {  delay = 0ms; } <--> Router0.port[1];
        Router1.port[1] <--> {  delay = 0ms; } <--> Router2.port[1];
        Router1.port[2] <--> {  delay = 0ms; } <--> Router3.port[1];
        
        PC0.port <--> {  delay = 0ms; } <--> Router0.port[0];
        PC1.port <--> {  delay = 0ms; } <--> Router2.port[0];
        PC2.port <--> {  delay = 0ms; } <--> Router3.port[0];
}
