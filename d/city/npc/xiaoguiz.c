// xiaoguiz.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIC"С����"NOR, ({ "xiao guizi", "xiao", "guizi" }) );
        set("gender", "����" );
        set("age", 13);
        set("long",
                "��λС̫����һ��С���̺��ţ���������һ��ҩ��\n");
        set("combat_exp", 1000);
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 5);

        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
HIC"С����"NOR"˵�����������ٷ�һ��ҩ���ò��ã�\n",
HIC"С����"NOR"��: �ٷ��������벻�����\n",
        }) );
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/d/city2/obj/yaofen");
        add_money("silver",10);
}




