// huahegen.c ������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "hua hegen", "hua" }));
	set("title",  "����˾ͽ" );
	set("long", "���Ǵ��������֮һ��
��˾ͽ��������������ƶ�����ֽ��ڴ����λ��������δ����ʱ����
����ȴ�ǵ�Ĺ��صĹ�����  ���ó��ı�����͵�������޼ֵķ�Ĺ����Щ��������
���󣬱������챦��ѳ�ᣬ�������Ӽ�Զ���ھ�ص���ͨ���Ĺ��Ȼ���ȡ���
������һ����ޣ�ȴ�ɴ˶���δΪ�˷�������һ��������һ�أ��ڹ�ľ�еõ���һ
��ѳ����书�ؾ���������ϰ��������һ��׿�������Ź��򣬱����������¼���Ӫ
�������������ۣ������湦����������˾ͽְ֮��\n");
	set("gender", "����");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	
	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 750000);
	set("score", 200000);

        set_skill("force", 80);
        set_skill("dodge", 90);
        set_skill("parry", 80);
        set_skill("cuff", 95);
        set_skill("sword", 80);
        set_skill("staff", 80);
	set_skill("kurong-changong", 80);
        set_skill("tiannan-step", 90);
        set_skill("jinyu-quan", 95);
        set_skill("duanjia-sword", 80);
	set_skill("literate", 60);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 20);

	create_family("����μ�",19,"�佫");
}

