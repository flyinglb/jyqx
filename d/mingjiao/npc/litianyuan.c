// LiTianYuan.c
// pal 1997.05.11

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
#include <ansi.h>

void create()
{
    set_name("����ԫ", ({ "li tianyuan", "li", "tianyuan", }));
	set("long",
        "����һλ�������ܴ�������ߣ���һ���ײ����ۡ�\n"
        "���ǰ�üӥ����������ʦ�ܡ�һ˫�۾�����Ц���еģ�����֪Ϊʲô����������\n"
        "����η����Ы��\n"
    );

        set("title", HIG "����" CYN "������" NOR "����" );
        set("nickname", "��ü��Ŀ");
	set("gender", "����");
	set("attitude", "friendly");
        set("class", "fighter");

        set("age", 55);
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
        create_family("����", 3, "����������");

	setup();

    carry_object("/d/mingjiao/obj/baipao")->wear();
}

#include "tangzhu.h"
