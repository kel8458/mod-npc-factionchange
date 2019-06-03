-- UP

-- Overwrite gossip text with faction change text
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (60000, 'BEHOLD!\n\nI ... am an Enchanter. There are some who call me Tim...e...ar.\n\nYOU SEEK A FACTION CHANGE?\n\nDo you wish to proceed with turning yourself inside out with the possibility of coming across a creature so foul, so cruel that no man yet has fought with it and lived?!');
UPDATE `gossip_menu` SET `TextID` = 60000 WHERE `MenuID` = 10096;

-- Update Timear to have a sub name and the new script
UPDATE `creature_template` SET `subname` = 'Faction Changes', `script` = 'npc_factionchange' WHERE `entry` = 31439;

-- Add Timear Page 2
INSERT INTO `npc_text`  (`ID`, `text0_0`) VALUES (60001, 'Are you really sure you wish to continue and face possible multiple deaths by sharp pointy teeth?\n\nChanging your faction is no simple task. The desire to change your name may come your way but heed my warning... it will not end well for you if you try!');
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES (60001, 60001);

-- Add Timear Page 3
INSERT INTO `npc_text`  (`ID`, `text0_0`) VALUES (60002, 'It is done! Now simply log yourself out and you will see my magic in play when you try to enter this realm again. You will have the option of choosing your faction.\n\nWARNING! Do not try to change your name or you may get lost in transit. And all that you have fought for will be undone.\n\nPerhaps locate a Holy Hand Grenade to defeat any cave dwelling guardians you come across.\n\nGood Luck!');
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES (60002, 60002);
