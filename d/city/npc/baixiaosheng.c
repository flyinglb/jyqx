// baixiaosheng.c
inherit NPC;
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
	set_name(HIW"������"NOR, ({ "bai xiaosheng", "bai", "xiaosheng" }));
	set("title", HIR"ʲô����֪��"NOR);
	set("gender", "����");
	set("age", 50);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("per", 30);
	set("long","����ǽ������˳ơ�������֪���İ�������������ֻ�ж�ʮ���꣬��ʵ���Ѿ���ʮ�����ˡ���\n");
	set("combat_exp", 800000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 50);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("hand", 200);
	set_skill("dodge", 200);
	set_skill("shenxing-baibian", 200);
	set_skill("yunlong-shengong", 200);
	set_skill("qianye-shou", 200);
	map_skill("force", "yunlong-shengong");
	map_skill("parry", "qianye-shou");
	map_skill("dodge", "shenxing-baibian");
	map_skill("hand", "qianye-shou");
	prepare_skill("hand", "qianye-shou");

	set("inquiry", ([
		"ɱ��"    : "��˵�������⺢��MUD��Ĳ���ô����ϲ��ѧϰ����������Ǹ���ɵ�ֳ���ĺ��ӡ�\n",
		"СС��"  : "СС�㣿�ǲ��������϶�����������ô�·����ˣ�\n",
                "������"  : "���ԭӦ�����У������������˼䣬����ָ����\n",
                "��Ӱ����"  : "��ԭ����а���еĸ��֣��󾭸���ָ�㣬����������ƣ���Ϊһ����ʦ��\n",
		"ˮ�ᾧ"  : "�������������������Ů���ˣ�˭Ȣ������֪���ж��Ҹ�����������ϲ�����ɱɱ��\n",
		"��֮��"  : "��֮�룬24���ѻ顣\n",
		"����"    : "���أ�����˵���Ǹ��������壬��ϲ���������ֵ�COC�˰ɣ���ֻ��һ�仰�����ݣ���ֱ��̫���ˣ�\n",
		"������"  : "�����ң���ʲô����֪����\n",
		"ССǿ"  : "ССǿ���书�����Ҳ���࣬ûʲô�õģ���pk������\n",
		"����"    : "ֻҪ����...ֻ������.....��Ϊ�������Ƕ�����ʹ��...����'.'��\n",
		])
	);
	setup();
	carry_object("/clone/cloth/male2-cloth")->wear();
}
