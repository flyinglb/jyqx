// liang.c

inherit NPC;

void create()
{
	set_name("������", ({ "liang ziwen", "liang", "ziwen" }));
	set("gender", "����");
	set("nickname", HIR"����"HIW"�Ϲ�"NOR);
	set("age", 43);
	set("str", 25);
	set("per", 20);
	set("dex", 16);
	set("long", "����������еȣ���ͷ�׷�����������ɫ����������ģ���һ
���𲼳��ۣ����ǵ����ס����ǳ���ɽ��ѧ��һ����ʦ��\n");
	set("combat_exp", 200000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	set("neili", 800); 
	set("max_neili", 800);
	set("jiali", 50);

	setup();
	carry_object(__DIR__"obj/changpao")->wear();
}

