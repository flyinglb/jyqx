// xiaoyuanshan.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��Զɽ", ({"xiao yuanshan", "xiao", "yuanshan"}));
	set("gender", "����");
	set("nickname",HIB"����ɮ"NOR);
	set("age", 28);
	set("long", 
		"������ؤ��ǰ�ΰ�������ĸ��ף�Ǳ��������ʮ���ˡ�\n"
		"����һ����ͨ�ĺ�ɮ�ۣ�������һ���������һϵ��\n"
		"������������࣬���ʮ�ֿ��࣬����һ�������ֿ���ʮ\n"
		"�����Ի������ӣ�˫Ŀ��磬��������\n");
	set("attitude", "peaceful");
	
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	
	set("combat_exp", 180000);
	set("score", 20000);
	 
	set_skill("force", 120);             // �����ڹ�
	set_skill("hunyuan-yiqi", 120);      // ��������
	set_skill("unarmed", 120);           // ����ȭ��
	set_skill("jingang-quan", 120);      // ����ʮ����
	set_skill("dodge", 120);      	     // ��������
	set_skill("shaolin-shenfa", 120);    // ��ң��
	set_skill("parry", 120);             // �����м�
	
	map_skill("force", "hunyuan-yiqi");
	map_skill("unarmed", "jingang-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "jingang-quan");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}

