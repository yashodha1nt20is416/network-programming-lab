#include <fstream>
#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/applications-module.h"
#include "ns3/internet-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

int 
main (int argc, char *argv[])
{
  //Address serverAddress;
  NodeContainer nodes;
  nodes.Create (4);


  CsmaHelper csma;
  csma.SetChannelAttribute ("DataRate", StringValue("5Mbps"));
  csma.SetChannelAttribute ("Delay", StringValue("2ms"));
  csma.SetDeviceAttribute ("Mtu", UintegerValue (1400));

  NetDeviceContainer devices;
  devices = csma.Install (nodes);

  InternetStackHelper stack;
  stack.Install (nodes);

  Ipv4AddressHelper address;
  address.SetBase ("10.1.1.0", "255.255.255.0");
  
  Ipv4InterfaceContainer interfaces = address.Assign (devices);


      //serverAddress = Address(i.GetAddress (1));
   

UdpEchoServerHelper echoServer (9);
  
  ApplicationContainer apps = echoServer.Install (nodes.Get (1));

   apps.Start (Seconds (1.0));
  apps.Stop (Seconds (10.0));



 UdpEchoClientHelper echoClient (interfaces.GetAddress (1), 9);
  echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient.SetAttribute ("PacketSize", UintegerValue (1024));

  apps = echoClient.Install (nodes.Get (0));
  apps.Start (Seconds (2.0));
  apps.Stop (Seconds (10.0));


AnimationInterface anim ("asmasecond.xml");
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}