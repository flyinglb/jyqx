// geshiha.c
inherit NPC;

void create()
{
	set_name("��ʲ��", ({ "geshiha"}));
	set("gender", "����");
	set("age", 25);

	set("long", "һ���ߴ����͵ĺ��ӣ��Ǿ�����ʩ�Ŵ��˵��ױ���ʲ����\n");
	set("combat_exp", 17500);
	set("shen_type", 1);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
	
