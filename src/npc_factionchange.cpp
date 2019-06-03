#include "Config.h"
#include "ScriptMgr.h"

class npc_factionchange : public CreatureScript
{
    npc_factionchange() : CreatureScript("npc_factionchange") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(1, "How bad can it be?  I am interested.", GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(1, "Ahh, I think I am in the wrong place. I have to go.", GOSSIP_SENDER_MAIN, 2);
        player->PlayerTalkClass->SendGossipMenu(60000, creature->GetGUID());
        
        return true;
    }

    bool OnGossipSelect(Player *player, Creature *creature, uint32 /*uiSender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        
        switch (action)
        {
        case 1:
            player->ADD_GOSSIP_ITEM(1, "|TInterface/ICONS/vas_factionchange:24:24:-18|t[I have fought worse and come away with but a scratch. Do it!]", GOSSIP_SENDER_MAIN, 101);
            player->ADD_GOSSIP_ITEM(1, "I think perhaps I will go sort out my life insurance and come back another day.", GOSSIP_SENDER_MAIN, 102);
            player->PlayerTalkClass->SendGossipMenu(60001, creature->GetGUID());
            return true;
            break;
            
        case 101:
            // Add faction change flag
            player->ADD_GOSSIP_ITEM(1, "I understand, thank you!", GOSSIP_SENDER_MAIN, 202);
            player->PlayerTalkClass->SendGossipMenu(60002, creature->GetGUID());
            return true;
            break;
         
        default:
            player->PlayerTalkClass->SendCloseGossip();
            return true;
            break;
        }
    }
};

void AddNPCFactionChangeScripts()
{
    new npc_factionchange();
}

