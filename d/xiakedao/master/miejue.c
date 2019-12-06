// miejue.c ���ʦ̫
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
        set_name("���ʦ̫", ({ "miejue-shitai","miejue","shitai"}));
        set("long",
                "���Ƕ����ɵĵ��������ӣ����ζ����������ˡ�\n");
        set("gender", "Ů��");
        set("age", 62);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 100000);
        set("class", "bonze");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
        }) );

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);
        set("per", 20);

        set("max_qi", 4000);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 2000000);
        set("score", 1000);
        set_skill("persuading", 150);
        set_skill("throwing", 180);
        set_skill("force", 180);
        set_skill("dodge", 180);
        set_skill("finger", 180);
        set_skill("parry", 180);
        set_skill("strike", 180);
        set_skill("sword", 180);
        set_skill("blade", 180);
        set_skill("literate", 100);
        set_skill("mahayana", 180);
        set_skill("buddhism", 180);
        set_skill("jinding-zhang", 180);
        set_skill("tiangang-zhi", 180);
        set_skill("huifeng-jian", 180);
        set_skill("yanxing-dao", 180);
        set_skill("zhutian-bu", 180);
        set_skill("linji-zhuang", 180);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
        create_family("������", 3, "������");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	object *obj, me=this_object();
	int i;

	obj = all_inventory(environment(me));
        command("say ���������������㣬��ħ������Ҫ�˾���");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="zhou-zhiruo")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        return;
}

