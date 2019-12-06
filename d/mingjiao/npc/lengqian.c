// LengQian.c
// pal 1997.05.11

inherit NPC;
inherit F_UNIQUE;
#include <ansi.h>

void create()
{
        set_name("��ǫ", ({ "leng qian", "leng", "qian", }));
	set("long",
        "����һλ��������ߣ���һ���ײ����ۡ�\n"
        "��˵����Ϊ��ݣ�����ɱ������ͷҲ���϶�˵���ϻ���\n"
	);

        set("title", HIG "����" NOR "��ɢ��");
        set("nickname", "��������");
	set("gender", "����");
	set("attitude", "friendly");
        set("class", "fighter");

        set("age", 54);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 85);
	set_skill("hunyuan-yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin-shenfa", 85);
	set_skill("cuff", 95);
	set_skill("jingang-quan", 95);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");

	prepare_skill("cuff", "jingang-quan");
        create_family("����", 3, "��ɢ��");

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
}
