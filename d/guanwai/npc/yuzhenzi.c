// yuzhenzi.c

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name("������", ({ "yuzhen zi", "yuzhen" }));
	set("gender", "����");
	set("title", "������������");
	set("nickname", HIC"��������"NOR);
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "����һλ�����ɷ���ǵ�����ȫ�棬���ճ�����Ŀ��ǰ����\n"+
	"������ľɣ���˵�ʦ�ܣ�������Ѱ�ñ�����������Ϊ�������ţ�������ˣ�\n"+
	"������ֹȷʮ�ֲ��ˡ�\n");
	set("combat_exp", 900000);
	set("score", 10000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("jing", 1000);
	set("max_jing", 1000);
	set("qi", 3000);
	set("max_qi", 3000);

	set_skill("sword", 150);
	set_skill("force", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("huashan-jianfa", 150);
	set_skill("shenxing-baibian", 150);
	map_skill("whip",  "huashan-jianfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("dodge", "shenxing-baibian");

	set("neili", 1500); 
	set("max_neili", 1500);
	set("jiali", 100);
	setup();
        carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 2);
}

