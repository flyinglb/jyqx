// lutianshu.c

inherit NPC;
#include <ansi.h>;
void create()
{
       set_name("½����", ({ "Lu tianshu", "lu" }));
       set("long", 
       "�����������桰�仨��ˮ���е��ϴ�\n"
       "��������н��ϣ��������壬½�������������ƣ�����������\n");
       set("gender", "����");
       set("nickname", HIG"����½��"NOR);
       set("age", 51);
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
       set_skill("hunyuan-yiqi", 100);
       set_skill("dodge", 100);
       set_skill("shaolin-shenfa", 100);
       set_skill("unarmed", 100);
       set_skill("jingang-quan", 100);
       set_skill("parry", 100);
       set_skill("blade", 100);
       set_skill("wuhu-duanmendao", 100);
       set_skill("literate", 20);

       map_skill("force", "hunyuan-yiqi");
       map_skill("dodge", "shaolin-shenfa");
       map_skill("unarmed", "jingang-quan");
       map_skill("parry", "wuhu-duanmendao");
       map_skill("blade", "wuhu-duanmendao");
       set("chat_chance", 20);
       set("chat_msg", ({
              "½��������������������Х�����䡫������ˮ������Х���ۻ룬ԶԶȺɽ��Ӧ������\n",
	}));

       setup();
       carry_object("/clone/weapon/gangdao")->wield();
}

