// duanzc.c ������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "duan zhengchun", "duan" }));
	set("title",  "����������" );
	set("long", "�����Ǵ�������������������̫�ܣ��������İ���ʥ�֡�\n");
	set("gender", "����");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	
	set("max_qi", 2200);
	set("max_jing", 600);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 1000000);
	set("score", 300000);

        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("cuff", 140);
        set_skill("strike", 150);
        set_skill("sword", 150);
        set_skill("staff", 150);
        set_skill("finger", 120);
	set_skill("kurong-changong", 150);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 130);
        set_skill("wuluo-zhang", 150);
        set_skill("duanjia-sword", 150);
        set_skill("sun-finger", 100);
	set_skill("literate", 100);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "sun-finger");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "sun-finger");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);

	create_family("����μ�",18,"������");
}

void attempt_apprentice(object ob)
{
        string sta = ob->query("dali_family_status") ;
	if( !stringp(sta) ) {
	        command("say ���Ǻ��ˣ���˴󵨣���ð�Ҹ������ͣ�");
	        return ;
	}
	if ((int)ob->query_skill("kurong-changong",1) < 100 )
	{
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɡ�");
		return;
	}
	if ((int)ob->query("shen") < 10000  ) {
		command("say �Ҵ�����������������壬����ذɣ�");
		return;
	}
        command("say �ܺã���Ȼ���������͵�����Ϊū������ʹ��");
	command("recruit " + ob->query("id"));
}
