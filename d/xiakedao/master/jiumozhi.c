// /kungfu/class/xueshan/jiumozhi.c �Ħ��
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�Ħ��", ({ "jiumo-zhi", "zhi" ,"ming wang"}));
        set("nickname", HIG "��������" NOR);
        set("long",@LONG
������ѩɽ�µ����ţ��˳ƴ����������Ħ�ǡ����Է��о�����о���
��һ��������ģ�ͷ��ɮñ��
LONG
        );
        set("title","ѩɽ������");
        set("gender", "����");
        set("age", 60);
        set("no_beg", 1);
        set("no_beg_from", 1);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("combat_exp", 2000000);
        set("score", 500000);

        set_skill("force", 200);
        set_skill("xiaowuxiang", 200);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 150);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("mingwang-jian", 200);
        set_skill("mizong-xinfa", 200);
        set_skill("literate", 100);
        set_skill("staff", 100);
        set_skill("xiangmo-chu", 100 );
        set_skill("strike", 200 );
        set_skill("huoyan-dao", 200);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");
        map_skill("staff", "xiangmo-chu");
        map_skill("strike","huoyan-dao");

        prepare_skill("strike","huoyan-dao");

        create_family("ѩɽ��", 1, "����");
        set("class", "bonze");

        setup();

        carry_object("/d/xueshan/obj/r-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
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
        command("say �Կ��Ϻ�ӧ����ӧ������Ӧ���������ģ����Ƿ�ָ����֮�ƣ�\n");
        command("consider");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="xuedao-laozu")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        return;
}

