// zhang.c �½�

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�½�", ({ "zhang jin", "zhang","jin" }));
	set("title", HIR "�컨��"HIG"ʮ����" NOR);
	set("nickname", HIM "ʯ�ҵ�" NOR);
	set("long", 
"���Ǹ����ӣ�����ֱ���ӡ��������м��������������ˣ���
����һ����ҵ�Ӳ����������ȱ�ݣ����ձ���ȡЦ������
����������˵��ʱ�Գơ������ӡ������Ǻö˶˵أ�Ȼ����
������������ǰ�ᵽ�����ա��֣��������������ձ�һЦ��
�������������˻�����Ц��֮�����ǳ���Ҳ�����ˣ������
�գ������ͱ������ʵʵ�Ĵ���һ�١����ں컨����������
���Ļ�������Ƣ���Ź֣����˶��������֣����ȴ�����зϣ�
������ʳ��ʱ��ϸ�����ϣ�������С�ֵ�һ�㡣�·���Ϊ��
�ʡ���òȴ��Ϊ��ª��\n");
	set("gender", "����");
	set("class", "fighter");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 12);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1200);
	set("max_jing", 700);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 120000);

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("staff", 70);
	set_skill("hand", 70);
	set_skill("claw", 70);
	set_skill("yunlong-shengong", 70);
	set_skill("wuchang-zhang", 70);
	set_skill("yunlong-shenfa", 70);
	set_skill("yunlong-shou", 70);
	set_skill("yunlong-zhua", 70);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("staff", "wuchang-zhang");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "wuchang-zhang");
	map_skill("claw", "yunlong-zhua");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("env/wimpy", 20);

 	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
}


