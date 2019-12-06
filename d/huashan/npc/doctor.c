// shiao.c
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��������", ({ "immortal doctor", "doctor" }) );

        set("nickname", "����");
        set("gender", "����");
        set("age", 30);
        set("long",
                "��ҽ���θ���������֢,�˵����ֵ�����.\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 30);
        set("int", 24);
        set("dex", 30);

        set("inquiry", ([
                "�Թ�": "Ŷ....��Ҫ�Թ�?û����,������ʹ!(accept zigong)?\n",
        ]) );
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_accept", "accept");
}

int  do_accept(string arg)
{
        object me = this_player();

        if (arg!="zigong") return 0;

        if (me->query("gender") != "����") {
                CHANNEL_D->do_channel(this_object(), "chat", 
                        sprintf( "%s ���Թ���ϧ�첻��, ����..\n",me));
        } else {
                CHANNEL_D->do_channel(this_object(), "chat", 
                        sprintf( "%s �Թ�����а������! \n",me));
                me->name(1);
                me->set("marks/�Թ�",1);
                me->set("gender","����");
        }
        return 1;
}

int accept_fight(object me)
{
        return notify_fail("����ô�����Ķ��֣�");
}

