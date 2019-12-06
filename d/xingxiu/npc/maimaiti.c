// npc: /d/xingxiu/npc/maimaiti.c
// Jay 3/17/96

inherit NPC;
inherit F_VENDOR;


void create()
{
        set_name("������", ({ "maimaiti", "seller" }) );
        set("title", "�ӻ����ϰ�");
        set("shen_type", 1);

        set("gender", "����" );
        set("age", 43);
        set("long", 
"�������Ǹ�����ά��������ˣ�ȥ��������ԭ���ܽ�һ���������\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("rank_info/respect", "����");

 
        set("vendor_goods", ({
                __DIR__"obj/hu",
                __DIR__"obj/nang",
                __DIR__"obj/fire",
                __DIR__"obj/hamigua",
                __DIR__"obj/dongbula",
        }) );

        set("inquiry", ([
                "��" : "Ҫ˵������������������",
                "������" : "�ˣ�����������ǰ����С������ˡ�",
        ]) );

        setup();
        carry_object(__DIR__"obj/wcloth")->wear();
        add_money("coin", 100);
}
void init()
{
        object ob;
        ::init();
        add_action("do_buy", "buy");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "������Ц������˵����ɫ��ķ�����\n");
                        break;
                case 1:
                        say( "���������ַ�����ǰ��ǳ��һ��˵���������ɫ��ķ\n");
                        break;
        }
}

