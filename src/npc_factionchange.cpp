#include "Config.h"
#include "ScriptMgr.h"

class npc_factionchange : public CreatureScript
{
    npc_factionchange() : CreatureScript("npc_factionchange") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        
        return true;
    }

    bool OnGossipSelect(Player *player, Creature *creature, uint32 /*uiSender*/, uint32 uiAction)
    {
    }
};

void AddNPCFactionChangeScripts()
{
    new npc_factionchange();
}

