// lu.c ½����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("½����", ({ "lu feiqing", "lu","feiqing" }));
	set("long", 
"½���࣬���䵱�ɴ�����׳��ʱ�ڴ��ϱ��������壬�˵���
�𽭺���ԭ����������һλ�쵱��������������Ƿ������
�Ӻ���������ʮ�ֺƴ󣬺���Ӻ����Ǭ¡����������ѹ��
��Ǭ¡�߰���ʱ����������������߽������½����Զ�߽߱���
��ʱ��͢����������׷�ã�����Ϊ�˻�������֮�书��ǿ����
�Ѵ��ѣ�����͢�����ϼӲ鼩��½�����뵽���������ڳ�����
�������С�С������Ұ��֮���쵽����㸮�����ʽ̶���\n");
	set("nickname", HIC"������"NOR);
	set("gender", "����");
	set("class", "scholar");
	set("age", 62);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 23);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 3000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 1000000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("taiji-quan", 150);
	set_skill("taiji-shengong", 200);
	set_skill("taiji-dao", 200);
	set_skill("taiji-jian", 200);
	set_skill("liangyi-jian", 150);
	set_skill("tiyunzong", 200);

	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji-shengong");
	map_skill("unarmed", "taiji-quan");
	map_skill("blade", "taiji-dao");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "liangyi-jian");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ren" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
	set("env/wimpy", 60);
	create_family("�䵱��", 17, "����");

 	setup();
	carry_object("/d/wudang/obj/greyrobe")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

