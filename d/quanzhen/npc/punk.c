// punk.c

inherit NPC;

void create()
{
        set_name("С��å", ({"punk"}) );
        set("gender", "����" );
        set("age", 18);
        set("long", "����һ�����ֺ��е�С��å��\n");

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("combat_exp", 500);
//      set("shen", -100);
        set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"��å�������ֵ�˵�������������а������������һ�����ƣ���\n"
"С�������־�Ȼ������һ����������\n",
"��å����ǽ�Ǵ����˯���ˣ�˯����Ҳ��֪�뵽��ʲ�ᣬ�����\n"
"�ߵ����ҿ�������ѩ�׵Ĵ��ȣ��Ҿ����ˡ������ġ�ඡ�\n",
"��å�������Լ��Ŀڴ���̾�˿���˵��������Ǯ������С��ƭȥ\n"
"�ˣ�����ȥ�Ҵ仨�ˡ�\n",
"��å���¶��һ˿аЦ��˵�����仨��������湻������������\n"
"�̵Ĺ���������!\n",
        }) );
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("silver", 5);
}

