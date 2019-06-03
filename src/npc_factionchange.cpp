#include "Config.h"
#include "Chat.h"
#include "ScriptMgr.h"
#include "GossipDef.h"
#include "Implementation/CharacterDatabase.h"

class npc_factionchange : public CreatureScript
{
    public:

    npc_factionchange() : CreatureScript("npc_factionchange") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "How bad can it be?  I am interested.", GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Ahh, I think I am in the wrong place. I have to go.", GOSSIP_SENDER_MAIN, 2);
        player->PlayerTalkClass->SendGossipMenu(60000, creature->GetGUID());
        
        return true;
    }

    bool OnGossipSelect(Player *player, Creature *creature, uint32 /*uiSender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        
        switch (action)
        {
        case 1: {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "I have fought worse and come away with but a scratch. Do it!", GOSSIP_SENDER_MAIN, 101);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I think perhaps I will go sort out my life insurance and come back another day.", GOSSIP_SENDER_MAIN, 102);
            player->PlayerTalkClass->SendGossipMenu(60001, creature->GetGUID());
            return true;
            break;
        }
        case 101: {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
            stmt->setUInt16(0, uint16(AT_LOGIN_CHANGE_FACTION));
            player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
            stmt->setUInt32(1, player->GetGUIDLow());
            CharacterDatabase.Execute(stmt);
            
            // Inform the player
            std::ostringstream ssp;
            ssp << "|cffFF0000[Venture Bay]:|cffFF8000 Your character has been marked for a faction change.";
            ChatHandler(player->GetSession()).SendSysMessage(ssp.str().c_str());
        
            // Log to server            
            std::ostringstream sss;
            sss << player->GetName() << " has requested a faction change.";
            sLog->outString(sss.str().c_str());
        
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I understand, thank you!", GOSSIP_SENDER_MAIN, 202);
            player->PlayerTalkClass->SendGossipMenu(60002, creature->GetGUID());
            
            return true;
            break;
        }
        default: {
            player->PlayerTalkClass->SendCloseGossip();
            return true;
            break;
        }}
    }
};

void AddNPCFactionChangeScripts()
{
    new npc_factionchange();
}

