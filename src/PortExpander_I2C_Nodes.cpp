#include <PortExpander_I2C_Nodes.hpp> 
 
ExpanderRelayNode::ExpanderRelayNode(const char* node, const int relayPin, PortExpander_I2C * expander) 
   : RelayNode(node, relayPin)
{
    _expander = expander;
};

void ExpanderRelayNode::setRelayState(bool on) 
{
   _expander->digitalWrite(getRelayPin(), on ? LOW : HIGH);
};

bool ExpanderRelayNode::readRelayState() 
{
   return _expander->digitalRead(getRelayPin()) == LOW;
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



