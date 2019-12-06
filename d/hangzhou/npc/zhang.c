// zhang.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������", ({ "zhang zhaozhong", "zhang", "zhaozhong"}) );
	set("title", "���־�����Ӫ����");
	set("nickname", HIR"�����й�"NOR);
	set("gender", "����");
	set("age", 43);
	set("long",
"�������˳ơ������й١�����Ŀ��࣬��һ�Զ̺��ӡ�����ʢ
�ԡ�����һǹ��Ī��һ�š�����ָ���ˡ������Թ�����»��Ͷ
��͢�����˰�����������Щ������������ֱ�ϡ�\n");
	set("combat_exp", 750000);
        set("shen_type", -1);
	set("attitude", "heroism");
        set("max_neili", 2000);
        set("neili", 2000);
        set("max_jing", 1000);
        set("jing", 1000);
        set("max_qi", 2000);
        set("qi", 2000);
        set("per", 20);
        set("int", 30);
        set("con", 30);
        set("str", 30);
        set("dex", 30);

	set_skill("unarmed", 100);
	set_skill("sword", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("taiji-shengong", 100);
	set_skill("taiji-jian", 100);
	set_skill("taiji-quan", 100);
	set_skill("tiyunzong", 100);
	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji-shengong");
	map_skill("sword", "taiji-jian");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");

        create_family("�䵱��", 13, "����");
	setup();

        carry_object(__DIR__"obj/green_sword")->wield();
        carry_object("/d/city/obj/tiejia")->wear();

	add_money("silver", 30);
}
