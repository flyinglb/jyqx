// jiaoxi.c

inherit NPC;
inherit F_DEALER;
#include <ansi.h>

void create()
{
        set_name("�Ϸ���", ({ "lao fuzi", "lao", "fuzi" }));
        set("long",
"һ��Ψ����ͼ�������Ͻ�ϰ����������īˮ�����㻹Ҫ��Ǯ��\n");
        set("gender", "����");
        set("age", 65);
        set_skill("literate", 200);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 20);

        set("combat_exp", 40000);
        set("shen_type", 1);
        set("inquiry", ([
            "��"   : "��!�鵽��ʱ�����١�",
            "����" : "�裿�㲻���ҵ��������㣿��!",
        ]));
        setup();

}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/��2"))
                return 0;
        ob->add_temp("mark/��2", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/��2")) who->set_temp("mark/��2", 0);
        if (ob->query("money_id") && ob->value() >= 500)
        {
                message_vision("�Ϸ���ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
                who->add_temp("mark/��2", ob->value() / 50);
                return 1;
        }
}

