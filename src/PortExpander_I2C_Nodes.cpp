#include <PortExpander_I2C_Nodes.hpp> 
 
ExpanderRelayNode::ExpanderRelayNode(const char* node, const int relayPin, PortExpander_I2C * expander) 
   : RelayNode(node, relayPin, -1, true)
{
    _expander = expander;
};

void ExpanderRelayNode::setRelayState(bool on) 
{
   _expander->digitalWrite(getRelayPin(), on ? _relayOnValue : _relayOffValue);
};

bool ExpanderRelayNode::getRelayState() 
{
   return _expander->digitalRead(getRelayPin()) == _relayOnValue;
};

void ExpanderRelayNode::setupRelay() 
{
    _expander->pinMode(getRelayPin(), OUTPUT);
};


ExpanderContactNode::ExpanderContactNode(const char* node, const int contactPin, PortExpander_I2C * expander) 
   : ContactNode(node, contactPin)
{
    _expander = expander;
};

byte ExpanderContactNode::readPin() 
{
   return _expander->digitalRead(getContactPin());
};

void ExpanderContactNode::setupPin() 
{
    _expander->pinMode(getContactPin(), INPUT_PULLUP);
};



