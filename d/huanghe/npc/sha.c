// sha.c

inherit NPC;

void create()
{
	set_name("ɳͨ��", ({ "sha tongtian", "sha", "tongtian" }));
	set("gender", "����");
	set("title", HIY"�ƺӰ����"NOR);
	set("nickname", HIC"��������"NOR);
	set("age", 43);
	set("str", 25);
	set("dex", 16);
	set("per", 12);
	set("long", "ɳͨ���Ǹ�ͺ�ӣ�ͷ���͹���û���ͷ����˫Ŀ������˿����
��ͻ��������һ�����ࡣ���ӱ��꣬�书ȴ�ǳ���ظߣ�������
���˲�����\n");
	set("combat_exp", 200000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("club", 60);
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
	carry_object("/d/hangzhou/honghua/obj/tiejiang")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
}

