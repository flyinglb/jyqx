// oldman.c

inherit NPC;

void create()
{
	set_name("��������",({ "oldman" }) );
        set("gender", "����" );
        set("age", 72);
        set("long", 
"һ���������Ŵ�����ֵ�������������ſڣ�˦�����ĸ����ƴ��������Ҷ�����ŵ�
���������������ǣ���Ҳ������ڡ�\n");
        set_temp("apply/defense", 5);
	set("combat_exp", 700);
	set("shen_type", 1);
        set("per", 13);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

