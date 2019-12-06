// frog.c
#include <ansi.h>
inherit NPC;

void create()
{
    set_name(GRN"������"NOR,({ "big frog","qing wa","frog"}) );
    set("age", 7);
    set("long", "����һֻ��˿�����ܣ���������յ�ˮ̶�ȫ������\n
�ʷ�׳׳��һ��Ѫ����۾���ʮ�ֶ��ģ�������ɱ������\n");
    set("limbs", ({ "��ǰצ", "�ܺ�ץ", "����" }) );
    set("verbs", ({ "bite", "claw" }) );

    set("combat_exp", 50);
    set("shen_type", -1);
    set("str", 11);
    set("dex", 11);
    set("con", 11);
    set("int", 11);
    set("attitude", "peaceful");
    set("chat_msg", ({
        "���������ɽ���������һ�������ֻ��ĵ���ģ����\n",
        "�����ܱ������ģ�������Ľűߣ�����ģ�\n",
    }));
    setup();
}

void init()
{
    object ob;

    ::init();
    if( interactive(ob = this_player()) && !is_fighting() ) {
         remove_call_out("greeting");
         call_out("greeting", 1, ob);
    }
    add_action("do_dajia","hit");
    add_action("do_dajia","kill");
    add_action("do_dajia","fight");
    add_action("do_drop","drop");
    add_action("do_save","save");
}

void greeting(object ob)
{
    if( !ob || environment(ob) != environment() ) return;
    say( "���������ɽ���������һ�������ֻ��ĵ���ģ����\n");
}

int do_dajia(string arg)
{
    command("say ���ﶼ��ˮ��վ��վ���ȣ�����ʲô��ʡ�������գ�\n");
    return 0;
}
int do_save()
{
    command("say ����̣�ʡ�������գ�\n");
    return 0;
}
int do_drop(object arg)
{
    command("say �Ҷ��������ȼ�������\n");
    return 0;
}
