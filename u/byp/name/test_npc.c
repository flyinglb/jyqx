// test_npc.c �������NPC����

#define NAME_D    "/u/byp/name/random_name"//�ɶ�Ӧ�����random_name.c�ľ���·��

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
	        set("gender", "����" );
	else
	        set("gender", "Ů��" );
   	
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