// yufeng.c //���
// By Lgg,1998.9

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW "���" NOR, ({"yufeng","feng","bee"}) );
        set("race", "Ұ��");
        set("age", 8);
        set("long", "����һֻ��ɫ���۷䣬��ͷ����ͨ�۷��ö࣬\n"
                    "����ϱ����ü�������֡�\n");

        set("str", 40);
        set("dex", 50);

        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
        set("verbs", ({ "bite", "poke" }) );

        set_temp("apply/attack", 35);
        set_temp("apply/armor", 25);

        set("chat_chance", 2);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
        "�������ͷ��ת��һȦ���ƺ������ⲻ�ǿɲ��۵ĵط����������˵ط����ˡ�\n",
        "���Χ�����ʻ��ɷ�ͣͣ���ƺ�Ҳ�������ڲ����ϡ�\n",
         }) );

        setup();
}
