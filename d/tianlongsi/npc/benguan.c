// benguan.c
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "ben guan","guan"}) );
	set("gender", "����" );
	set("long", "һ���ݻƾ��ݵ�ɮ�ˣ����Ǳ����ɵ�ʦ�֡�\n");
	set("title", "�����µ�ʮ�ߴ�ɮ��");
	set("class", "bonze");
	set("age", 47);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 800000);
	set("score", 1000000);

	set_skill("force", 120);
	set_skill("dodge", 180);
	set_skill("parry", 120);
	set_skill("finger", 185);
	set_skill("sword", 120);
	set_skill("tiannan-step", 180);
	set_skill("kurong-changong", 120);
	set_skill("duanjia-sword", 120);
	set_skill("six-finger", 180);
	set_skill("buddhism", 100);
	set_skill("literate", 80);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","six-finger");
	create_family("����μ�",17,"��ɮ");
	setup();
	carry_object("/d/xueshan/obj/b-jiasha")->wear();
}
#include "ben.h"
