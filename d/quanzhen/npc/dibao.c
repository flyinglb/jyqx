// dibao.c

inherit NPC;

void create()
{
        set_name("�ر�", ({ "dibao" }) );
        set("gender", "����" );
        set("age", 43);
        set("long",
"����������������������ˣ������ʱ������ȥ������һ��\n"
"���ھֵ��������֣����˵�Ǯ��������Ȣ�˷����ţ���ũΪ����\n"
"��������������������棬�ֻ�Щ�书�����������˵ر���\n");

        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);

        set_skill("unarmed", 30);
        set_skill("dodge", 20);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set("combat_exp", 2500);

        set("attitude", "peaceful");
        setup();
        add_money("coin", 150);
        carry_object(__DIR__"obj/cloth")->wear();
}

