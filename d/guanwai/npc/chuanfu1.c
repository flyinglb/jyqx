// chuanfu.c ����

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "chuan fu", "fu" }));
        set("gender", "����");
        set("age", 36);
        set("long",
        "����һ���ɻ����ϵĴ��򡣱�����˪������͸�������˵ĺ�ˬ��\n"
        );

        set("combat_exp", 10000);
        set("shen_type", 1);

	set("eff_qi",800);
	set("qi",800);
        set("max_neili", 100);
        set("neili", 100);
        set("jiali", 10);

        setup();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
    if (ob->query("money_id") && ob->value() >= 10000)
    {
        message_vision("�����$N˵���ã���Ȼ��λ" + RANK_D->query_respect(who) +
        "Ҫ������\n���Ҿ��������������ɣ�\n" , who);
        message_vision("�����$N���˴���һ������ê�������ŷ��밶��......\n", who);
        who->move ("/d/guanwai/songhuajiang");
        tell_object(who, BLU "���ڽ���һ·Ư��.......\n" NOR ) ;
        call_out("goto_songhua",10,who) ;
 //       destruct(this_object());
       	return 1;
    }
    else  
    {
	message_vision("������ü��$N˵������㣿�����Ҹ����ɣ�˵���ͷ�����ˡ�\n", who);
        destruct(this_object());
	return 0;
    }
}

void goto_songhua(object ob)
{
   tell_object(ob , "\n���ܿ�ͣ���˰�����̧�ſ��������\n\n" ) ;
   ob->move ("/d/guanwai/chuanchang") ;
}
