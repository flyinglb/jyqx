// liuchengfeng.c

inherit NPC;
#include <ansi.h>;
void create()
{
       set_name("���з�", ({ "liu chengfeng", "liu" }));
       set("long", 
       "�����������桰�仨��ˮ���е�������\n"
       "��������н��ϣ��������壬���з�һ��̫����������������ϱ���\n");
       set("gender", "����");
       set("nickname", HIY"���ƽ�"NOR);
       set("age", 41);
       set("attitude", "peaceful");
       set("shen_type", 0);
       set("str", 35);
       set("int", 38);
       set("con", 35);
       set("dex", 35);

       set("max_qi", 2000);
       set("max_jing", 500);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 30);
       set("combat_exp", 800000);
       set("shen_type", 1);

       set_skill("force", 100);
       set_skill("taiji-shengong", 100);
       set_skill("dodge", 100);
       set_skill("tiyunzong", 100);
       set_skill("unarmed", 100);
       set_skill("taiji-quan", 100);
       set_skill("parry", 100);
       set_skill("sword", 100);
       set_skill("taiji-jian", 100);
       set_skill("literate", 70);

       map_skill("force", "taiji-shengong");
       map_skill("dodge", "tiyunzong");
       map_skill("unarmed", "taiji-quan");
       map_skill("parry", "taiji-jian");
       map_skill("sword", "taiji-jian");
       set("chat_chance", 20);
       set("chat_msg", ({
              "���˷��Ȼ������Х�����仨������ˮ�������������棬ԶԶ���˳�ȥ��\n",
	}));

       setup();
       carry_object("/clone/weapon/changjian")->wield();
}

