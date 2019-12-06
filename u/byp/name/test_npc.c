// test_npc.c 随机姓名NPC范例

#define NAME_D    "/u/byp/name/random_name"//可对应到你放random_name.c的具体路径

inherit NPC;

void create()
{
        mapping name;
        int i;
        i = random(3);
        if(i>0)
                name = NAME_D->man_name();
        else
                name = NAME_D->woman_name();

        set_name(name["name"],name["id"]);
	
	if(i>0)
	        set("gender", "男性" );
	else
	        set("gender", "女性" );
   	
   	set("age",14+random(36));
   	set("attitude", "peaceful");
        set("quest_npc",1);

        set("str", 25);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

        set("combat_exp",1000);	
        setup();
}