//********************************************************************************************
//*
//*    This file is part of Egoboo.
//*
//*    Egoboo is free software: you can redistribute it and/or modify it
//*    under the terms of the GNU General Public License as published by
//*    the Free Software Foundation, either version 3 of the License, or
//*    (at your option) any later version.
//*
//*    Egoboo is distributed in the hope that it will be useful, but
//*    WITHOUT ANY WARRANTY; without even the implied warranty of
//*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*    General Public License for more details.
//*
//*    You should have received a copy of the GNU General Public License
//*    along with Egoboo.  If not, see <http://www.gnu.org/licenses/>.
//*
//********************************************************************************************

#include "EgoTest/EgoTest.hpp"
#include "IdLib/IdLib.hpp"

EgoTest_TestCase(Signal) {

// Connection, invocation, and explicit disconnection.
EgoTest_Test(signal0) {
    Id::Signal<void(const std::string&)> signal;
    // (1) Invoke with no subscriber.
    signal("Hello, World!");
    // (2) Invoke with one subscriber.
    bool invoked = false;
    auto function = [&invoked](const std::string& s) { invoked = true; };
    auto connection = signal.subscribe(function);
    signal("Hello, World!");
    connection.disconnect();
    EgoTest_Assert(true == invoked);
}

// Implicit disconnection (upon destruction of a signal).
EgoTest_Test(signal1) {
    Id::Connection connection;
    {
        Id::Signal<void(const std::string&)> signal;
        bool invoked = false;
        auto function = [&invoked](const std::string& s) { invoked = true; };
        connection = signal.subscribe(function);
        EgoTest_Assert(true == connection.isConnected());
    }
    EgoTest_Assert(false == connection.isConnected());
}

// Scoped disconnection (upon destruction of a scoped connection).
EgoTest_Test(signal2) {
    bool invoked = false;
    Id::Signal<void(const std::string&)> signal;
    {
        auto function = [&invoked](const std::string& s) { invoked = true; };
        Id::ScopedConnection scopedConnection(signal.subscribe(function));
        EgoTest_Assert(true == scopedConnection.isConnected());
    }
    signal("Hello, World!");
    EgoTest_Assert(false == invoked);
}

EgoTest_Test(signal3) {
    bool invoked = false;
    Id::Signal<void(const std::string&, const std::string&)> signal;
    {
        auto function = [&invoked](const std::string& s0, const std::string& s1) { invoked = true; };
        Id::ScopedConnection scopedConnection(signal.subscribe(function));
        EgoTest_Assert(true == scopedConnection.isConnected());
    }
    signal("Hello, ", "World!");
    EgoTest_Assert(false == invoked);
}

EgoTest_Test(signal4)
{
    bool invoked = false;
    Id::Signal<void(float, float)> signal;
    {
        auto function = [&invoked](float s0, float s1) { invoked = true; };
        Id::ScopedConnection scopedConnection(signal.subscribe(function));
        EgoTest_Assert(true == scopedConnection.isConnected());
    }
    signal(1.0f, 2.0f);
    EgoTest_Assert(false == invoked);
}


};
