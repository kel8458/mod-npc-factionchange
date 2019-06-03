-- DOWN
-- Restore to his default gossip text
UPDATE `gossip_menu` SET `TextID` = 14017 WHERE `MenuID` = 10096;
DELETE FROM `npc_text` WHERE `ID` = 60000;

-- Remove Timear's sub name and script
UPDATE `creature_template` SET `subname` = '', `script` = '' WHERE `entry` = 31439;

-- Remove Timear Page 2
DELETE FROM `npc_text` WHERE `ID` = 60001;
DELETE FROM `gossip_menu` WHERE `MenuID` = 60001;

-- Remove Timear Page 3
DELETE FROM `npc_text` WHERE `ID` = 60002;
DELETE FROM `gossip_menu` WHERE `MenuID` = 60002;
