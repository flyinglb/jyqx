// /u/beyond/mr/npc/tang.c �ƹ���
// this is made by beyond
// update 1997.6.23
#include <ansi.h>
inherit NPC;
string ask_1();
void create()
{
        set_name("�ƹ���", ({ "tang guangxiong", "tang" }));
        set("gender", "����");
        set("age", 20);      
	set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("attitude", "peaceful");
	set("max_qi",2000);
        set("max_jing",2000);
        set("neili",2000);
        set("max_neili",2000);
	set("jiali",0);
	set("score", 8000);

        set_skill("cuff", 60);
	set_skill("parry",60);
	set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan-gong",70);

	map_skill("force","shenyuan-gong");
	        
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        set("inquiry", 
                ([
                "����" : (: ask_1 :)
                ]));
        set("chat_chance",20);
        set("chat_msg",({
                "�ƹ��۵���������ҳ�ȥ���Ҹ�����һ�����ܣ�����\n",
                
        }) );        
	carry_object("/clone/misc/cloth")->wear();
}                          
string ask_1()
{
        mapping fam; 
// object ob;
        if (!(fam = this_player()->query("family")) 
           || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
		return "��԰�����������йŹ֣�\n";
         }

