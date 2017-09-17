/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Net/UDPConnection.h"
#include "Rendering/TeamHighlight.h"
#include "System/Config/ConfigHandler.h"
#include "System/GlobalConfig.h"
#include "Lua/LuaConfig.h"

CONFIG(int, NetworkLossFactor)
.defaultValue(netcode::UDPConnection::MIN_LOSS_FACTOR)
	.minimumValue(netcode::UDPConnection::MIN_LOSS_FACTOR)
	.maximumValue(netcode::UDPConnection::MAX_LOSS_FACTOR);

CONFIG(int, InitialNetworkTimeout)
	.defaultValue(30)
	.minimumValue(10);

CONFIG(int, NetworkTimeout)
	.defaultValue(120)
	.minimumValue(0);

CONFIG(int, ReconnectTimeout)
	.defaultValue(15)
	.minimumValue(0);

CONFIG(int, MaximumTransmissionUnit)
	.defaultValue(1400)
	.minimumValue(400);

CONFIG(int, LinkOutgoingBandwidth)
	.defaultValue(64 * 1024)
	.minimumValue(0);

CONFIG(int, LinkIncomingSustainedBandwidth)
	.defaultValue(2 * 1024)
	.minimumValue(0);

CONFIG(int, LinkIncomingPeakBandwidth)
	.defaultValue(32 * 1024)
	.minimumValue(0);

CONFIG(int, LinkIncomingMaxPacketRate)
	.defaultValue(64)
	.minimumValue(0);

// maximum lag induced by command spam is:
// LinkIncomingMaxWaitingPackets / LinkIncomingMaxPacketRate = 8 seconds
CONFIG(int, LinkIncomingMaxWaitingPackets)
	.defaultValue(512)
	.minimumValue(0);

CONFIG(int, TeamHighlight)
	.defaultValue(CTeamHighlight::HIGHLIGHT_PLAYERS)
	.minimumValue(CTeamHighlight::HIGHLIGHT_FIRST)
	.maximumValue(CTeamHighlight::HIGHLIGHT_LAST);

CONFIG(bool, UseNetMessageSmoothingBuffer).defaultValue(true);

CONFIG(bool, LuaWritableConfigFile).defaultValue(true);

CONFIG(bool, EnableDrawCallIns).defaultValue(true);

GlobalConfig* globalConfig = NULL;

GlobalConfig::GlobalConfig()
{
    //stub method
}

void GlobalConfig::Instantiate()
{
    //stub method
}

void GlobalConfig::Deallocate()
{
    //stub method
}
