#pragma once

#include <PortExpander_I2C.h>
#include <RelayNode.hpp>
#include <ContactNode.hpp>

class ExpanderRelayNode : public RelayNode
{
private:
   PortExpander_I2C * _expander;

protected:
  void setRelayState(bool on) override;
  bool readRelayState() override;
  void setupRelay() override;

public:
  ExpanderRelayNode(const char* node, const int relayPin, PortExpander_I2C * expander) ;
};


class ExpanderContactNode : public ContactNode
{
private:
   PortExpander_I2C * _expander;

protected:
   void setupPin() override;
   byte readPin() override;

public:
    ExpanderContactNode(const char* node, const int contactPin, PortExpander_I2C * expander);
};


