// zu.c

inherit NPC;
inherit F_UNIQUE;

void create()
{
        set_name("��ǧ��", ({ "zu qianqiu", "zu", "qianqiu" }) );
        set("nickname", "�ƺ�����");
        set("gender", "����" );
        set("age", 52);
        set("long", "һ���������͵�����������������Ƥ��һ������ǣ����������
�������ӣ���������������һƬ�͹⣬��������һ�������ȡ�\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");

	set("max_jing",500);
	set("max_qi",500);
        set("per", 17);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 30);

        set_skill("literate", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        setup();
        add_money("gold", 1);
	carry_object("d/city/obj/cloth")->wear();
}
