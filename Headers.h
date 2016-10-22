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

#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>

#define PC0 "10.0.0.1"
#define PC1 "10.0.1.1"
#define PC2 "10.0.2.1"

#define PC0R "10.0.0.6"
#define PC1R "10.0.1.254"
#define PC2R "10.0.2.62"

#define R01 "10.1.0.1"
#define R10 "10.1.0.2"
#define R12 "10.2.0.1"
#define R21 "10.2.0.2"
#define R13 "10.3.0.1"
#define R31 "10.3.0.2"

#include <AVLTree.h>
#include <ExtMessage_m.h>
#include <PC.h>
#include <cqueue.h>
#include <Router.h>

#endif /*HEADERS_H*/
